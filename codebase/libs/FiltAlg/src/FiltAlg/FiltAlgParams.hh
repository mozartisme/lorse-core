// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2016
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// FiltAlgParams.hh
//
// TDRP header file for 'FiltAlgParams' class.
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

#ifndef FiltAlgParams_hh
#define FiltAlgParams_hh

using namespace std;

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

// Class definition

class FiltAlgParams {

public:

  // enum typedefs

  typedef enum {
    NONE = 0,
    DEBUG = 1,
    DEBUG_VERBOSE = 2
  } debug_e;

  typedef enum {
    CLUMP = 0,
    ELLIP = 1,
    DILATE = 2,
    MEDIAN = 3,
    SDEV = 4,
    MEDIAN_NO_OVERLAP = 5,
    SDEV_NO_OVERLAP = 6,
    TEXTURE_X = 7,
    TEXTURE_Y = 8,
    REMAP = 9,
    REPLACE = 10,
    MAX_TRUE = 11,
    MAX = 12,
    AVERAGE = 13,
    AVERAGE_ORIENTATION = 14,
    PRODUCT = 15,
    FULL_MEAN = 16,
    FULL_SDEV = 17,
    FULL_MEDIAN = 18,
    VERT_AVERAGE = 19,
    VERT_MAX = 20,
    VERT_PRODUCT = 21,
    WEIGHTED_SUM = 22,
    WEIGHTED_ORIENTATION_SUM = 23,
    NORM_WEIGHTED_SUM = 24,
    NORM_WEIGHTED_ORIENTATION_SUM = 25,
    MASK = 26,
    RESCALE = 27,
    DB2LINEAR = 28,
    LINEAR2DB = 29,
    TRAPEZOID_REMAP = 30,
    S_REMAP = 31,
    PASSTHROUGH = 32,
    APPFILTER = 33
  } filter_t;

  // struct typedefs

  typedef struct {
    char* field;
    tdrp_bool_t is_input_field;
    tdrp_bool_t write_output_field;
    char* output_field;
    filter_t filter;
    int filter_index;
    char* app_filter_name;
  } data_filter_t;

  typedef struct {
    char* name;
    char* url;
    char* field;
  } input_t;

  typedef struct {
    int nr;
    int ntheta;
  } filter_2d_t;

  typedef struct {
    int nr;
    int ntheta;
    double bin_min;
    double bin_max;
    double bin_delta;
  } filter_2d_median_t;

  typedef struct {
    int rLwr;
    int rUpr;
    int thetaLwr;
    int thetaUpr;
  } filter_Scalar_t;

  typedef struct {
    double input_weight;
    int combine_index;
  } filter_comb_t;

  typedef struct {
    double threshold;
  } filter_clump_t;

  typedef struct {
    tdrp_bool_t set_initial_value;
    double initial_value;
    double replacement_value;
    char* logical_command;
    int combine_index;
  } filter_replace_t;

  typedef struct {
    int strings_index;
    int combine_index;
  } filter_max_true_t;

  typedef struct {
    double scale;
    double offset;
  } filter_rescale_t;

  typedef struct {
    double a;
    double b;
    double c;
    double d;
  } filter_trap_remap_t;

  typedef struct {
    double a;
    double b;
  } filter_s_remap_t;

  typedef struct {
    int dummy;
  } dummy_t;

  typedef struct {
    char* mask_name;
    tdrp_bool_t mask_is_input;
    int mask_list_index;
  } mask_t;

  typedef struct {
    double x;
    double y;
  } fuzzy_t;

  typedef struct {
    char* name;
    tdrp_bool_t is_input;
    double weight;
  } combine_t;

  typedef struct {
    double mask_min;
    double mask_max;
  } mask_range_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  FiltAlgParams ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  FiltAlgParams (const FiltAlgParams&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~FiltAlgParams ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const FiltAlgParams&);

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

  char* instance;

  debug_e debug_mode;

  tdrp_bool_t debug_triggering;

  tdrp_bool_t realtime;

  double max_wait_minutes;

  int read_tolerance_seconds;

  char* trigger_url;

  int min_gate_index;

  char* output_url;

  char* output_spdb;

  data_filter_t *_filter;
  int filter_n;

  input_t *_input;
  int input_n;

  input_t *_feedback_input;
  int feedback_input_n;

  tdrp_bool_t feedback_immediately;

  int max_feedback_seconds_back;

  char* input_info_url;

  double *_vlevel;
  int vlevel_n;

  double vlevel_tolerance;

  int num_threads;

  tdrp_bool_t thread_debug;

  filter_2d_t *_parm_2d;
  int parm_2d_n;

  filter_2d_median_t *_parm_2d_median;
  int parm_2d_median_n;

  filter_comb_t *_parm_combine;
  int parm_combine_n;

  filter_clump_t *_parm_clump;
  int parm_clump_n;

  filter_replace_t *_parm_replace;
  int parm_replace_n;

  filter_max_true_t *_parm_max_true;
  int parm_max_true_n;

  filter_rescale_t *_parm_rescale;
  int parm_rescale_n;

  filter_trap_remap_t *_parm_trap_remap;
  int parm_trap_remap_n;

  filter_s_remap_t *_parm_s_remap;
  int parm_s_remap_n;

  filter_Scalar_t *_parm_Scalar;
  int parm_Scalar_n;

  dummy_t *_parm_dummy;
  int parm_dummy_n;

  mask_t *_parm_mask;
  int parm_mask_n;

  fuzzy_t *_fuzzy0;
  int fuzzy0_n;

  fuzzy_t *_fuzzy1;
  int fuzzy1_n;

  fuzzy_t *_fuzzy2;
  int fuzzy2_n;

  fuzzy_t *_fuzzy3;
  int fuzzy3_n;

  fuzzy_t *_fuzzy4;
  int fuzzy4_n;

  fuzzy_t *_fuzzy5;
  int fuzzy5_n;

  fuzzy_t *_fuzzy6;
  int fuzzy6_n;

  fuzzy_t *_fuzzy7;
  int fuzzy7_n;

  fuzzy_t *_fuzzy8;
  int fuzzy8_n;

  fuzzy_t *_fuzzy9;
  int fuzzy9_n;

  fuzzy_t *_fuzzy10;
  int fuzzy10_n;

  fuzzy_t *_fuzzy11;
  int fuzzy11_n;

  fuzzy_t *_fuzzy12;
  int fuzzy12_n;

  fuzzy_t *_fuzzy13;
  int fuzzy13_n;

  fuzzy_t *_fuzzy14;
  int fuzzy14_n;

  combine_t *_combine0;
  int combine0_n;

  combine_t *_combine1;
  int combine1_n;

  combine_t *_combine2;
  int combine2_n;

  combine_t *_combine3;
  int combine3_n;

  combine_t *_combine4;
  int combine4_n;

  combine_t *_combine5;
  int combine5_n;

  combine_t *_combine6;
  int combine6_n;

  combine_t *_combine7;
  int combine7_n;

  combine_t *_combine8;
  int combine8_n;

  combine_t *_combine9;
  int combine9_n;

  mask_range_t *_mask_range0;
  int mask_range0_n;

  mask_range_t *_mask_range1;
  int mask_range1_n;

  mask_range_t *_mask_range2;
  int mask_range2_n;

  char* *_strings0;
  int strings0_n;

  char* *_strings1;
  int strings1_n;

  char* *_strings2;
  int strings2_n;

  char* *_strings3;
  int strings3_n;

  char* *_strings4;
  int strings4_n;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[69];

  const char *_className;

  bool _exitDeferred;

};

#endif

