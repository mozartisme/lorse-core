/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program RadxApRemoval
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    REALTIME = 0,
    ARCHIVE = 1,
    FILELIST = 2
  } mode_t;

  typedef enum {
    TDBZ = 0,
    GDZ = 1,
    MVE = 2,
    MSW = 3,
    SDVE = 4,
    SDSW = 5,
    SPIN = 6,
    SIGN = 7,
    RGDZ = 8,
    SRDZ = 9,
    RSINZ = 10
  } interest_field_t;

  typedef enum {
    LAND = 0,
    WATER = 1,
    ALL = 2
  } terrain_t;

  typedef enum {
    APDA = 0,
    SCDA = 1,
    PDA = 2
  } filter_type_t;

  typedef enum {
    AND_FILTER = 0,
    OR_FILTER = 1
  } filter_comb_type_t;

  typedef enum {
    OUTPUT_ENCODING_ASIS = 0,
    OUTPUT_ENCODING_FLOAT32 = 1,
    OUTPUT_ENCODING_INT32 = 2,
    OUTPUT_ENCODING_INT16 = 3,
    OUTPUT_ENCODING_INT08 = 4
  } output_encoding_t;

  typedef enum {
    SCALING_DYNAMIC = 0,
    SCALING_SPECIFIED = 1
  } output_scaling_t;

  typedef enum {
    OUTPUT_FORMAT_CFRADIAL = 0,
    OUTPUT_FORMAT_DORADE = 1,
    OUTPUT_FORMAT_FORAY = 2,
    OUTPUT_FORMAT_NEXRAD = 3,
    OUTPUT_FORMAT_UF = 4,
    OUTPUT_FORMAT_MDV_RADIAL = 5
  } output_format_t;

  typedef enum {
    CLASSIC = 0,
    NC64BIT = 1,
    NETCDF4 = 2,
    NETCDF4_CLASSIC = 3
  } netcdf_style_t;

  typedef enum {
    START_AND_END_TIMES = 0,
    START_TIME_ONLY = 1,
    END_TIME_ONLY = 2
  } filename_mode_t;

  // struct typedefs

  typedef struct {
    double min_elev;
    double max_elev;
  } filter_range_t;

  typedef struct {
    double latitude;
    double longitude;
  } radar_loc_t;

  typedef struct {
    int azimuth_radius;
    int gate_radius;
  } radius_info_t;

  typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    double x5;
    double y5;
    double x6;
    double y6;
  } range_weight_func_t;

  typedef struct {
    interest_field_t interest_field;
    double weight;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
    double x5;
    double y5;
    double x6;
    double y6;
  } interest_func_t;

  typedef struct {
    filter_type_t filter_type;
    filter_comb_type_t comb_type;
  } filter_comb_t;

  typedef struct {
    char* input_field_name;
    char* output_field_name;
    char* long_name;
    char* standard_name;
    char* output_units;
    output_encoding_t encoding;
    output_scaling_t output_scaling;
    double output_scale;
    double output_offset;
  } output_field_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int arrayRealloc(const char *param_name,
                   int new_array_n);

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  char* instance;

  char* input_dir;

  mode_t mode;

  int max_realtime_data_age_secs;

  tdrp_bool_t latest_data_info_avail;

  tdrp_bool_t search_recursively;

  int max_recursion_depth;

  int wait_between_checks;

  int file_quiescence;

  char* search_ext;

  tdrp_bool_t set_fixed_angle_limits;

  double lower_fixed_angle_limit;

  double upper_fixed_angle_limit;

  tdrp_bool_t set_sweep_num_limits;

  int lower_sweep_num;

  int upper_sweep_num;

  tdrp_bool_t read_set_radar_num;

  int read_radar_num;

  tdrp_bool_t aggregate_sweep_files_on_read;

  tdrp_bool_t ignore_idle_scan_mode_on_read;

  tdrp_bool_t remove_rays_with_all_data_missing;

  tdrp_bool_t remove_rays_with_antenna_transitions;

  int transition_nrays_margin;

  tdrp_bool_t trim_surveillance_sweeps_to_360deg;

  tdrp_bool_t set_max_range;

  double max_range_km;

  tdrp_bool_t set_ngates_constant;

  tdrp_bool_t override_instrument_name;

  char* instrument_name;

  tdrp_bool_t override_radar_location;

  double radar_latitude_deg;

  double radar_longitude_deg;

  double radar_altitude_meters;

  tdrp_bool_t change_radar_latitude_sign;

  char* input_fmq_url;

  char* vel_field_name;

  char* refl_field_name;

  char* sw_field_name;

  tdrp_bool_t use_terrain;

  char* terrain_url;

  char* terrain_field_name;

  char* *_filter_field_names;
  int filter_field_names_n;

  filter_range_t filter_range;

  double gate_spacing;

  long max_num_gates;

  double delta_azimuth;

  radar_loc_t radar_location;

  radius_info_t dbz_radius_info;

  radius_info_t vel_radius_info;

  range_weight_func_t range_weight_func;

  interest_func_t *_ap_interest_func;
  int ap_interest_func_n;

  interest_func_t *_ap_confidence_func;
  int ap_confidence_func_n;

  interest_func_t *_sc_interest_func;
  int sc_interest_func_n;

  interest_func_t *_sc_confidence_func;
  int sc_confidence_func_n;

  interest_func_t *_p_interest_func;
  int p_interest_func_n;

  interest_func_t *_p_confidence_func;
  int p_confidence_func_n;

  tdrp_bool_t p_filter_low_dbz;

  double p_low_dbz_threshold;

  double slant_range_dist;

  terrain_t ap_terrain_use_type;

  terrain_t sc_terrain_use_type;

  terrain_t p_terrain_use_type;

  double sc_spin_threshold;

  double ap_spin_threshold;

  double p_spin_threshold;

  double ap_interest_threshold;

  double sc_interest_threshold;

  double p_interest_threshold;

  tdrp_bool_t eov_trigger;

  filter_comb_t *_filter_combination;
  int filter_combination_n;

  tdrp_bool_t set_output_fields;

  output_field_t *_output_fields;
  int output_fields_n;

  tdrp_bool_t write_other_fields_unchanged;

  tdrp_bool_t set_output_encoding_for_all_fields;

  output_encoding_t output_encoding;

  output_format_t output_format;

  netcdf_style_t netcdf_style;

  tdrp_bool_t output_native_byte_order;

  tdrp_bool_t output_compressed;

  tdrp_bool_t output_force_ngates_vary;

  int compression_level;

  char* output_dir;

  filename_mode_t output_filename_mode;

  tdrp_bool_t append_day_dir_to_output_dir;

  tdrp_bool_t append_year_dir_to_output_dir;

  tdrp_bool_t write_individual_sweeps;

  tdrp_bool_t write_latest_data_info;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[104];

  const char *_className;

  bool _exitDeferred;

};

#endif

