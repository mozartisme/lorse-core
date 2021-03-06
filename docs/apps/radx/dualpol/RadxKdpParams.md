```
/**********************************************************************
 * TDRP params for RadxKdp
 **********************************************************************/

//======================================================================
//
// RadxKdp reads moments from Radx-type files, computes KDP and 
//   optionally attenuation, and writes out the results to CfRadial files.
//
//======================================================================
 
//======================================================================
//
// DEBUGGING.
//
//======================================================================
 
///////////// debug ///////////////////////////////////
//
// Debug option.
//
// If set, debug messages will be printed appropriately.
//
//
// Type: enum
// Options:
//     DEBUG_OFF
//     DEBUG_NORM
//     DEBUG_VERBOSE
//     DEBUG_EXTRA
//

debug = DEBUG_OFF;

//======================================================================
//
// THREADING FOR SPEED.
//
// Multiple threads are used to improve performance. The computations 
//   are carried out in parallel in separate threads. The read and write 
//   stages occur in the main thread, since netCDF is not thread safe.
//
//======================================================================
 
///////////// n_compute_threads ///////////////////////
//
// The number of compute threads.
//
// The moments computations are segmented in range, with each thread 
//   computing a fraction of the number of gates. For maximum performance, 
//   n_threads should be set to the number of processors multiplied by 4. 
//   For further tuning, use top to maximize CPU usage while varying the 
//   number of threads. For single-threaded operation set this to 1.
//
// Minimum val: 1
//
// Type: int
//

n_compute_threads = 4;

//======================================================================
//
// DATA INPUT.
//
//======================================================================
 
///////////// mode ////////////////////////////////////
//
// Operating mode.
//

//
// In REALTIME mode, the program waits for a new input file.\nIn ARCHIVE 
//   mode, it moves through the data between the start and end times set 
//   on the command line. 
//
// In FILELIST mode, it moves through the list of file names specified 
//   on the command line.
//
//
// Type: enum
// Options:
//     REALTIME
//     ARCHIVE
//     FILELIST
//

mode = FILELIST;

///////////// input_dir ///////////////////////////////
//
// Input directory for searching for files.
//
// Files will be searched for in this directory.
//
//
// Type: string
//

input_dir = "/tmp/cfradial/moments";

///////////// input_file_search_ext ///////////////////
//
// File name extension.
//
// If set, only files with this extension will be processed.
//
//
// Type: string
//

input_file_search_ext = "nc";

///////////// input_file_search_substr ////////////////
//
// File name sub-string.
//
// If set, only files with names containing this sub-string will be 
//   processed.
//
//
// Type: string
//

input_file_search_substr = "cfrad";

///////////// start_time //////////////////////////////
//
// Set the start time for ARCHIVE mode analysis.
//
// Format is 'yyyy mm dd hh mm ss'.
//
//
// Type: string
//

start_time = "2015 06 26 00 00 00";

///////////// end_time ////////////////////////////////
//
// Set the end time for ARCHIVE mode analysis.
//
// Format is 'yyyy mm dd hh mm ss'.
//
//
// Type: string
//

end_time = "2015 06 26 12 00 00";

//======================================================================
//
// INPUT FIELD INFORMATION.
//
// Names of fields in the input file. The following fields are required: 
//   SNR, DBZ, ZDR, PHIDP and RHOHV. If SNR is not available, it is 
//   computed from DBZ.
//
//======================================================================
 
///////////// SNR_available ///////////////////////////
//
// Is SNR data available?.
//
// If not, SNR will be computed from the DBZ field. See 
//   'noise_dbz_at_100km'.
//
//
// Type: boolean
//

SNR_available = FALSE;

///////////// SNR_field_name //////////////////////////
//
// Field name for SNR.
//
// Signal-to-noise ratio (dB).
//
//
// Type: string
//

SNR_field_name = "SNR";

///////////// noise_dbz_at_100km //////////////////////
//
// The noise value, represented as dBZ at a range of 100km.
//
// This is used for computing the SNR from the DBZ field. It is only 
//   used if SNR_available is FALSE. The SNR will be computed by 
//   range-correcting this value and using it as the noise value.
//
//
// Type: double
//

noise_dbz_at_100km = 0;

///////////// DBZ_field_name //////////////////////////
//
// Field name for DBZ.
//
// Horizontally-polarized reflectivity factor.
//
//
// Type: string
//

DBZ_field_name = "DBZ";

///////////// ZDR_field_name //////////////////////////
//
// Field name for ZDR.
//
//
// Type: string
//

ZDR_field_name = "ZDR";

///////////// PHIDP_field_name ////////////////////////
//
// Field name for PHIDP.
//
//
// Type: string
//

PHIDP_field_name = "PHIDP";

///////////// RHOHV_field_name ////////////////////////
//
// Field name for RHOHV.
//
//
// Type: string
//

RHOHV_field_name = "RHOHV";

//======================================================================
//
// COMPUTING KDP.
//
// The parameters for KDP computations are contained in a separate file. 
//   An example default file can be generated using the -print_params_kdp 
//   command line argument.
//
//======================================================================
 
///////////// KDP_params_file_path ////////////////////
//
// Path for parameters for KDP computations.
//
// If set to use-defaults, no parameter file will be read in, and the 
//   default parameters will be used.
//
//
// Type: string
//

KDP_params_file_path = "./KdpParams.test";

//======================================================================
//
// SPECIFYING OUTPUT FIELDS.
//
//======================================================================
 
///////////// output_fields ///////////////////////////
//
// Indicate which fields should be written to the output file.
//
// Choose the ID from the list.
//
// The name and units can be set however the user prefers.
//
// The output_encoding apply to CfRadial output only. 
//
// 	KDP: KDP from filtering PHIDP and computing slope (deg/km)
// 	KDP_SC: KDP conditioned using ZZDR self-consistency (deg/km)
// 	DBZ_ATTEN_CORRECTION: DBZ attenuation correction (dB)
// 	ZDR_ATTEN_CORRECTION: ZDR attenuation correction (dB)
// 	DBZ_ATTEN_CORRECTED: DBZ corrected for attenuation (dBZ)
// 	ZDR_ATTEN_CORRECTED: ZDR corrected for attenuation (dB).
//
//
// Type: struct
//   typedef struct {
//      output_field_id_t id;
//        Options:
//          KDP
//          KDP_SC
//          DBZ_ATTEN_CORRECTION
//          ZDR_ATTEN_CORRECTION
//          DBZ_ATTEN_CORRECTED
//          ZDR_ATTEN_CORRECTED
//      string name;
//      string long_name;
//      string standard_name;
//      string units;
//      boolean do_write;
//   }
//
// 1D array - variable length.
//

output_fields = {
  {
    id = KDP,
    name = "KDP",
    long_name = "specific_differential_phase",
    standard_name = "specific_differential_phase_hv",
    units = "deg/km",
    do_write = TRUE
  }
  ,
  {
    id = KDP_SC,
    name = "KDP_SC",
    long_name = "kdp_from_self_consistency_with_ZZDR",
    standard_name = "specific_differential_phase_hv",
    units = "deg/km",
    do_write = FALSE
  }
  ,
  {
    id = DBZ_ATTEN_CORRECTION,
    name = "DBZ_ATTEN_CORRECTION",
    long_name = "correction_to_dbz_for_attenuation",
    standard_name = "dbz_attenuation_correction",
    units = "dB",
    do_write = FALSE
  }
  ,
  {
    id = ZDR_ATTEN_CORRECTION,
    name = "ZDR_ATTEN_CORRECTION",
    long_name = "correction_to_zdr_for_attenuation",
    standard_name = "zdr_attenuation_correction",
    units = "dB",
    do_write = FALSE
  }
  ,
  {
    id = DBZ_ATTEN_CORRECTED,
    name = "DBZ_ATTEN_CORRECTED",
    long_name = "dbz_corrected_for_attenuation",
    standard_name = "dbz_corrected_for_attenuation",
    units = "dBZ",
    do_write = FALSE
  }
  ,
  {
    id = ZDR_ATTEN_CORRECTED,
    name = "ZDR_ATTEN_CORRECTED",
    long_name = "zdr_corrected_for_attenuation",
    standard_name = "zdr_corrected_for_attenuation",
    units = "dB",
    do_write = FALSE
  }
};

///////////// output_encoding /////////////////////////
//
// Set the encoding for fields in the output files.
//
// INT16 provides better compression. FL32 writes 32-bit floats.
//
//
// Type: enum
// Options:
//     OUTPUT_ENCODING_FL32
//     OUTPUT_ENCODING_INT16
//

output_encoding = OUTPUT_ENCODING_INT16;

//======================================================================
//
// SPECIFY COPY-THROUGH FIELDS.
//
// These fields are copied unchanged from the input file to the output 
//   file. This allows the user to consolidate the input and output data 
//   set in a single file.
//
//======================================================================
 
///////////// copy_selected_input_fields_to_output ////
//
// Option to copy input fields unchanged to the output file.
//
//
// Type: boolean
//

copy_selected_input_fields_to_output = TRUE;

///////////// copy_fields /////////////////////////////
//
// These fields are copied through unchanged to the output file.
//
// You can change the name of the field on output.
//
//
// Type: struct
//   typedef struct {
//      string input_name;
//      string output_name;
//   }
//
// 1D array - variable length.
//

copy_fields = {
  {
    input_name = "DBZ",
    output_name = "DBZ"
  }
  ,
  {
    input_name = "VEL",
    output_name = "VEL"
  }
  ,
  {
    input_name = "WIDTH",
    output_name = "WIDTH"
  }
  ,
  {
    input_name = "ZDR",
    output_name = "ZDR"
  }
  ,
  {
    input_name = "PHIDP",
    output_name = "PHIDP"
  }
  ,
  {
    input_name = "RHOHV",
    output_name = "RHOHV"
  }
};

//======================================================================
//
// WRITING DEBUG FIELDS.
//
//======================================================================
 
///////////// KDP_write_debug_fields //////////////////
//
// Write extra fields to assist with debugging.
//
// These are the intermediate fields used in computing KDP and 
//   attenuation.
//
//
// Type: boolean
//

KDP_write_debug_fields = TRUE;

//======================================================================
//
// WRITING THE OUTPUT FILES.
//
//======================================================================
 
///////////// output_dir //////////////////////////////
//
// Output directory path.
//
// Files will be written to this directory.
//
//
// Type: string
//

output_dir = "/tmp/cfradial/kdp/test";

///////////// output_filename_mode ////////////////////
//
// Mode for computing output file name.
//
// START_AND_END_TIMES: include both start and end times in file name. 
//   START_TIME_ONLY: include only start time in file name. END_TIME_ONLY: 
//   include only end time in file name.
//
//
// Type: enum
// Options:
//     START_AND_END_TIMES
//     START_TIME_ONLY
//     END_TIME_ONLY
//

output_filename_mode = START_AND_END_TIMES;

///////////// append_day_dir_to_output_dir ////////////
//
// Add the day directory to the output directory.
//
// Path will be output_dir/yyyymmdd/filename.
//
//
// Type: boolean
//

append_day_dir_to_output_dir = TRUE;

///////////// append_year_dir_to_output_dir ///////////
//
// Add the year directory to the output directory.
//
// Path will be output_dir/yyyy/yyyymmdd/filename.
//
//
// Type: boolean
//

append_year_dir_to_output_dir = FALSE;

///////////// output_format ///////////////////////////
//
// Format for the output files.
//
//
// Type: enum
// Options:
//     OUTPUT_FORMAT_CFRADIAL
//     OUTPUT_FORMAT_DORADE
//     OUTPUT_FORMAT_UF
//

output_format = OUTPUT_FORMAT_CFRADIAL;

//======================================================================
//
// REALTIME OPERATIONS.
//
//======================================================================
 
///////////// instance ////////////////////////////////
//
// Program instance for process registration.
//
// This application registers with procmap. This is the instance used 
//   for registration.
//
//
// Type: string
//

instance = "nexrad";

///////////// procmap_register_interval ///////////////
//
// Interval for registering with procmap (secs).
//
// REALTIME mode only. The app will register with procmap at this 
//   interval, to update its status. If it does not register within twice 
//   this interval, the auto_restart script will restart the app.
//
//
// Type: int
//

procmap_register_interval = 60;

///////////// max_realtime_data_age_secs //////////////
//
// Maximum age of realtime data (secs).
//
// Only data less old than this will be used.
//
//
// Type: int
//

max_realtime_data_age_secs = 300;

```

