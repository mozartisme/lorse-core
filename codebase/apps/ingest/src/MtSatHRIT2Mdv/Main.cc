// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
//

#include <cstdio>
//
// Include stuff from the RAL libraries.
//
#include <toolsa/pmu.h>
#include <didss/DsInputPath.hh>
//
// Local include files - most notably Params.hh, which
// is generated from the paramdef file using tdrp_gen.
//
#include "Params.hh"
#include "Args.hh"
#include "MtSatHRIT2Mdv.hh"
//
// Use the standard namespace. This is necessary for more
// recent versions of the compiler.
//
using namespace std;
//
// The 'tidy_and_exit' routine is called by the program if the
// system gets an interrupt signal.
//
static void tidy_and_exit (int sig);
//
// Main program starts.
// 
int main(int argc, char *argv[])
{
  //
  // Trap signals with reference to the 'tidy_and_exit' routine.
  //
  PORTsignal(SIGINT, tidy_and_exit);
  PORTsignal(SIGHUP, tidy_and_exit);
  PORTsignal(SIGTERM, tidy_and_exit);
  
  //
  // Get the Command Line Interperter arguments using the
  // Args class.
  //
  static char prog_name[14] = "MtSatHRIT2Mdv";
  Args *_args = new Args(argc, argv, prog_name);
  if (!_args->OK) {
    fprintf(stderr, "ERROR: MtSatHRIT2Mdv\n");
    fprintf(stderr, "Problem with command line args\n");
    exit(-1);
  }                 

  //
  // Get the Table Driven Runtime Parameters loaded
  // into the 'tdrp' structure.
  //
  Params *tdrp = new  Params(); 

  if (tdrp->loadFromArgs(argc, argv, _args->override.list, &_args->paramsFilePath)){
    fprintf(stderr,"Specify params file with -params option.\n");
    exit(-1);
  } 

  //
  // If -verbose or -debug specified, then set debug flag.
  //
  for (int k=0; k < argc; k++){
    if (0==strcmp(argv[k], "-debug")) {
      tdrp->debug = (tdrp_bool_t) true;
    }
    if (0==strcmp(argv[k], "-verbose")){
      tdrp->debug = (tdrp_bool_t) true;
      tdrp->verbose = (tdrp_bool_t) true;
    }
  }

  //
  // Check in to the process mapping system, using the instance string
  // we get from the tdrp parameters.
  //
  PMU_auto_init("MtSatHRIT2Mdv", tdrp->instance, PROCMAP_REGISTER_INTERVAL);
  
  //
  // Set up a DsInputPath object. At RAL, this is a reasonably standard
  // method of monitoring a directory to see if new file arrives.
  //
  DsInputPath *_input;

  //
  // The setup of this object depends on if we are running in archive
  // mode or realtime mode.
  //
  // In archive mode, the file names are specified on the command line
  // with the -f argument. This information is in the _args class.
  //
  if (tdrp->mode == Params::ARCHIVE) {

    if (_args->nFiles <= 0){
      fprintf(stderr,"For ARCHIVE mode, specify file list a argument.\n");
      exit(-1);
    }

    if (tdrp->debug){
      fprintf(stderr,"%d files :\n",_args->nFiles);
      for (int i=0;i<_args->nFiles;i++){
	fprintf(stderr,"[ %d ] %s\n",i+1,_args->filePaths[i]);
      }
    }
    _input = new DsInputPath("MtSatHRIT2Mdv",
			     tdrp->verbose,
			     _args->nFiles,
			     _args->filePaths);
                                                            
  } else {
    //
    // In realtime mode, we monitor a directory for new files.
    //
    _input = new DsInputPath("MtSatHRIT2Mdv",
                             tdrp->verbose,
                             tdrp->ir1Input.dir,
                             tdrp->max_realtime_valid_age,
                             PMU_auto_register,
			     false, false);

    _input->setSubString( tdrp->ir1Input.filenameSubString );
    _input->setSearchExt( tdrp->required_file_ext );

  }

  //
  // Now that we have the _input object set up, use it.
  // Register with the process mapping system.
  //
  PMU_auto_register("Waiting for data");

  char *FilePath;
  _input->reset();

  //
  // Instantiate an instance of the object that will
  // actually do most of the work.
  //
  MtSatHRIT2Mdv D( tdrp );
  //
  // Loop through, processing the input files.
  //
  while ((FilePath = _input->next()) != NULL) {

    D.MtSatHRIT2MdvFile( FilePath );
    PMU_auto_register("Waiting for data");

  } // while loop.

  //
  // Should only get here if we come to the end of the input
  // file list in archive mode.
  //
  return 0;
}

/////////////////////////////////////////////
//
// Small routine called in the event of an interrupt signal.
//
static void tidy_and_exit (int sig){
  PMU_auto_unregister();
  exit(sig);
}








