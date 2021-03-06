# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
# ** Copyright UCAR (c) 1990 - 2016                                         
# ** University Corporation for Atmospheric Research (UCAR)                 
# ** National Center for Atmospheric Research (NCAR)                        
# ** Boulder, Colorado, USA                                                 
# ** BSD licence applies - redistribution and use in source and binary      
# ** forms, with or without modification, are permitted provided that       
# ** the following conditions are met:                                      
# ** 1) If the software is modified to produce derivative works,            
# ** such modified software should be clearly marked, so as not             
# ** to confuse it with the version available from UCAR.                    
# ** 2) Redistributions of source code must retain the above copyright      
# ** notice, this list of conditions and the following disclaimer.          
# ** 3) Redistributions in binary form must reproduce the above copyright   
# ** notice, this list of conditions and the following disclaimer in the    
# ** documentation and/or other materials provided with the distribution.   
# ** 4) Neither the name of UCAR nor the names of its contributors,         
# ** if any, may be used to endorse or promote products derived from        
# ** this software without specific prior written permission.               
# ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
# ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
# ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
# *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
###########################################################################
#
# Makefile for Sigwx2Symprod
#
###########################################################################

include $(RAP_MAKE_INC_DIR)/rap_make_macros

TARGET_FILE = Sigwx2Symprod

LOC_INCLUDES = $(NETCDF4_INCS)

LOC_LIBS = -lSpdb -ldsserver -ldidss -lxmlformats \
	-leuclid -ltoolsa -ldataport -ltdrp \
	-ltinyxml $(NETCDF4_LIBS) -lbz2 -lz \
	-lpthread -lm

LOC_LDFLAGS = $(NETCDF4_LDFLAGS)

LOC_CFLAGS =

HDRS = \
	$(PARAMS_HH) \
	Args.hh \
	BoundingBox.hh \
	CloudHandler.hh \
	CycloneDisplayItem.hh \
	DisplayItem.hh \
	Driver.hh \
	IconDef.hh \
	JetStreamHandler.hh \
	ProductHandler.hh \
	RadiationDisplayItem.hh \
	SandstormDisplayItem.hh \
	Server.hh \
	TurbulenceHandler.hh \
	VolcanoDisplayItem.hh\
	VolcanoHandler.hh

CPPC_SRCS = \
	$(PARAMS_CC) \
	Args.cc \
	BoundingBox.cc \
	CloudHandler.cc \
	CycloneDisplayItem.cc \
	DisplayItem.cc \
	Driver.cc \
	IconDef.cc \
	JetStreamHandler.cc \
	Main.cc \
	ProductHandler.cc \
	RadiationDisplayItem.cc \
	SandstormDisplayItem.cc \
	Server.cc \
	TurbulenceHandler.cc \
	VolcanoDisplayItem.cc \
	VolcanoHandler.cc

#
# tdrp macros
#

include $(RAP_MAKE_INC_DIR)/rap_make_tdrp_macros

#
# standard C++ targets
#

include $(RAP_MAKE_INC_DIR)/rap_make_c++_targets

#
# tdrp targets
#

include $(RAP_MAKE_INC_DIR)/rap_make_tdrp_c++_targets

#
# local targets
#

testJetstream: Sigwx2Symprod
	./Sigwx2Symprod -verbose \
		-testType jetstream \
		-testFile temp.jetstream.xml \
		-testLevel 10

# DO NOT DELETE THIS LINE -- make depend depends on it.

