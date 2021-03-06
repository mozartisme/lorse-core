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
/*********************************************************************
 * ArcMsgFactory : Class representing a message from an HiQ radar
 *                 processor using the new ARC messages.
 *
 * RAP, NCAR, Boulder CO
 *
 * October 2008
 *
 * Nancy Rehak
 *
 *********************************************************************/

#ifndef ArcMsgFactory_hh
#define ArcMsgFactory_hh


#include "ArcBeamMsg.hh"
#include "MsgFactory.hh"

using namespace std;


class ArcMsgFactory : public MsgFactory
{

public:

  /*********************************************************************
   * Constructors.
   */

  ArcMsgFactory();

  /*********************************************************************
   * Destructor
   */

  virtual ~ArcMsgFactory();

  /*********************************************************************
   * createMessage() - Create a ArcMsgFactory object using the given buffer
   *                   of data.
   */

  HiqMsg *createMessage(const char *buffer,
			const int buffer_len);


private:

};

#endif
