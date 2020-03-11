/* Include files */

#include "modified_motor_sfun.h"
#include "c1_modified_motor.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "modified_motor_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[18] = { "MAX_ANGLES_TO_VISIT",
  "MODE_SCAN", "MODE_SEEK_COLOR", "MODE_SEEK_POSITION", "SHAPE_COL", "COLOR_COL",
  "X_COL", "Y_COL", "img_regions", "rect_coords", "angles_to_visit", "nargin",
  "nargout", "mode", "color", "position", "img_data", "angles_vector" };

static const char * c1_b_debug_family_names[10] = { "IMG_LENGTH", "IMG_HEIGHT",
  "IMG_CENTER", "x_from_center", "y_from_center", "cartesian_angles", "nargin",
  "nargout", "rect_coords", "angles" };

static emlrtRTEInfo c1_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_b_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_c_emlrtRTEI = { 46,/* lineNo */
  31,                                  /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_d_emlrtRTEI = { 53,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_e_emlrtRTEI = { 50,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_f_emlrtRTEI = { 43,/* lineNo */
  37,                                  /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_g_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_h_emlrtRTEI = { 57,/* lineNo */
  15,                                  /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_i_emlrtRTEI = { 46,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_j_emlrtRTEI = { 47,/* lineNo */
  37,                                  /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_k_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "Logic Block/Generate Angles List",  /* fName */
  "#modified_motor:144"                /* pName */
};

static emlrtRTEInfo c1_l_emlrtRTEI = { 26,/* lineNo */
  1,                                   /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

static emlrtRTEInfo c1_m_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

static emlrtRTEInfo c1_n_emlrtRTEI = { 30,/* lineNo */
  25,                                  /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

static emlrtRTEInfo c1_o_emlrtRTEI = { 30,/* lineNo */
  42,                                  /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

static emlrtRTEInfo c1_p_emlrtRTEI = { 26,/* lineNo */
  1,                                   /* colNo */
  "rdivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"/* pName */
};

static emlrtRTEInfo c1_q_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

static emlrtRTEInfo c1_r_emlrtRTEI = { 10,/* lineNo */
  85,                                  /* colNo */
  "atan",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\atan.m"/* pName */
};

static emlrtRTEInfo c1_s_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "rect_to_polar",                     /* fName */
  "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"/* pName */
};

/* Function Declarations */
static void initialize_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void initialize_params_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance);
static void enable_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void disable_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance);
static void set_sim_state_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void sf_gateway_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void mdl_start_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void initSimStructsc1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void c1_rect_to_polar(SFc1_modified_motorInstanceStruct *chartInstance,
  real_T c1_rect_coords_data[], int32_T c1_rect_coords_size[2], real_T
  c1_angles_data[], int32_T c1_angles_size[1]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_modified_motorInstanceStruct *chartInstance,
  const mxArray *c1_b_angles_vector, const char_T *c1_identifier, real_T c1_y
  [100]);
static void c1_b_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[1]);
static void c1_d_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[1]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[1]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_e_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2]);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2]);
static void c1_f_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2]);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_modified_motor, const char_T *
  c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_modified_motorInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_modified_motorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_modified_motor(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_modified_motor = 0U;
}

static void initialize_params_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_modified_motor
  (SFc1_modified_motorInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(2, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_angles_vector, 0,
    0U, 1U, 0U, 1, 100), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_modified_motor;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[100];
  int32_T c1_i0;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("angles_vector",
    c1_u, 0)), "angles_vector", c1_dv0);
  for (c1_i0 = 0; c1_i0 < 100; c1_i0++) {
    (*chartInstance->c1_angles_vector)[c1_i0] = c1_dv0[c1_i0];
  }

  chartInstance->c1_is_active_c1_modified_motor = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c1_modified_motor",
       c1_u, 1)), "is_active_c1_modified_motor");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_modified_motor(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  int32_T c1_i1;
  int32_T c1_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 400; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_img_data)[c1_i1], 3U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_position, 2U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_color, 1U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_mode, 0U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_modified_motor(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_modified_motorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i2 = 0; c1_i2 < 100; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_angles_vector)[c1_i2], 4U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }
}

static void mdl_start_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_b_mode;
  real_T c1_b_color;
  real_T c1_b_position;
  int32_T c1_i3;
  uint32_T c1_debug_family_var_map[18];
  real_T c1_b_img_data[400];
  real_T c1_MAX_ANGLES_TO_VISIT;
  real_T c1_MODE_SCAN;
  real_T c1_MODE_SEEK_COLOR;
  real_T c1_MODE_SEEK_POSITION;
  real_T c1_SHAPE_COL;
  real_T c1_COLOR_COL;
  real_T c1_X_COL;
  real_T c1_Y_COL;
  real_T c1_img_regions_data[400];
  int32_T c1_img_regions_size[2];
  real_T c1_rect_coords_data[200];
  int32_T c1_rect_coords_size[2];
  real_T c1_angles_to_visit_data[100];
  int32_T c1_angles_to_visit_size[1];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 1.0;
  real_T c1_b_angles_vector[100];
  int32_T c1_i4;
  int32_T c1_trueCount;
  boolean_T c1_bv0[100];
  int32_T c1_i;
  int32_T c1_tmp_size[1];
  int32_T c1_partialTrueCount;
  int32_T c1_b_i;
  int32_T c1_tmp_data[100];
  int32_T c1_i5;
  int32_T c1_loop_ub;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_b_tmp_size[1];
  int32_T c1_i10;
  int32_T c1_b_loop_ub;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_c_loop_ub;
  int32_T c1_b_rect_coords_size[2];
  int32_T c1_i13;
  static real_T c1_dv1[4] = { 3.1415926535897931, -3.1415926535897931,
    1.5707963267948966, -1.5707963267948966 };

  int32_T c1_end;
  boolean_T c1_b_tmp_data[100];
  int32_T c1_b_trueCount;
  int32_T c1_rect_coords;
  real_T c1_d0;
  int32_T c1_c_i;
  int32_T c1_b_rect_coords;
  boolean_T c1_b0;
  int32_T c1_d_loop_ub;
  boolean_T c1_b1;
  int32_T c1_i14;
  boolean_T c1_b2;
  int32_T c1_c_tmp_size[1];
  int32_T c1_b_partialTrueCount;
  int32_T c1_i15;
  int32_T c1_d_i;
  real_T c1_b_rect_coords_data[200];
  real_T c1_c_tmp_data[100];
  int32_T c1_d_tmp_size[1];
  int32_T c1_e_loop_ub;
  int32_T c1_f_loop_ub;
  int32_T c1_img_regions;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_d_tmp_data[100];
  int32_T c1_i18;
  int32_T c1_iv0[1];
  int32_T c1_g_loop_ub;
  int32_T c1_h_loop_ub;
  int32_T c1_i19;
  int32_T c1_c_rect_coords_size[2];
  int32_T c1_i20;
  int32_T c1_c_rect_coords;
  int32_T c1_d_rect_coords;
  int32_T c1_i_loop_ub;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_c_rect_coords_data[200];
  real_T c1_e_tmp_data[100];
  int32_T c1_e_tmp_size[1];
  int32_T c1_j_loop_ub;
  int32_T c1_i23;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_mode;
  c1_b_hoistedGlobal = *chartInstance->c1_color;
  c1_c_hoistedGlobal = *chartInstance->c1_position;
  c1_b_mode = c1_hoistedGlobal;
  c1_b_color = c1_b_hoistedGlobal;
  c1_b_position = c1_c_hoistedGlobal;
  for (c1_i3 = 0; c1_i3 < 400; c1_i3++) {
    c1_b_img_data[c1_i3] = (*chartInstance->c1_img_data)[c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_MAX_ANGLES_TO_VISIT, 0U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_MODE_SCAN, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_MODE_SEEK_COLOR, 2U,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_MODE_SEEK_POSITION, 3U,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_SHAPE_COL, 4U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_COLOR_COL, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_X_COL, 6U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Y_COL, 7U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_img_regions_data, (
    const int32_T *)&c1_img_regions_size, NULL, 0, 8, (void *)
    c1_f_sf_marshallOut, (void *)c1_e_sf_marshallIn, (void *)
    &c1_img_regions_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_rect_coords_data, (
    const int32_T *)&c1_rect_coords_size, NULL, 0, 9, (void *)
    c1_e_sf_marshallOut, (void *)c1_d_sf_marshallIn, (void *)
    &c1_rect_coords_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_angles_to_visit_data,
    (const int32_T *)&c1_angles_to_visit_size, NULL, 0, 10, (void *)
    c1_d_sf_marshallOut, (void *)c1_c_sf_marshallIn, (void *)
    &c1_angles_to_visit_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 11U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 12U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_mode, 13U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_color, 14U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_position, 15U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_img_data, 16U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_angles_vector, 17U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_MAX_ANGLES_TO_VISIT = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_MODE_SCAN = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_MODE_SEEK_COLOR = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_MODE_SEEK_POSITION = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_SHAPE_COL = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_COLOR_COL = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_X_COL = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
  c1_Y_COL = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  for (c1_i4 = 0; c1_i4 < 100; c1_i4++) {
    c1_bv0[c1_i4] = (c1_b_img_data[c1_i4] != 0.0);
  }

  c1_trueCount = 0;
  c1_i = 0;
  while (c1_i <= 99) {
    if (c1_bv0[c1_i]) {
      c1_trueCount++;
    }

    c1_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c1_tmp_size[0] = c1_trueCount;
  c1_partialTrueCount = 0;
  c1_b_i = 0;
  while (c1_b_i <= 99) {
    if (c1_bv0[c1_b_i]) {
      c1_tmp_data[c1_partialTrueCount] = c1_b_i + 1;
      c1_partialTrueCount++;
    }

    c1_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c1_img_regions_size[0] = c1_tmp_size[0];
  c1_img_regions_size[1] = 4;
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_loop_ub = c1_tmp_size[0] - 1;
    for (c1_i7 = 0; c1_i7 <= c1_loop_ub; c1_i7++) {
      c1_img_regions_data[c1_i7 + c1_img_regions_size[0] * c1_i5] =
        c1_b_img_data[(c1_tmp_data[c1_i7] + 100 * c1_i5) - 1];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  for (c1_i6 = 0; c1_i6 < 100; c1_i6++) {
    c1_b_angles_vector[c1_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c1_b_mode, 1.0, -1, 0U,
        c1_b_mode == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
    c1_i8 = c1_img_regions_size[0];
    c1_rect_coords_size[0] = c1_i8;
    c1_rect_coords_size[1] = 2;
    for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
      c1_c_loop_ub = c1_i8 - 1;
      for (c1_i13 = 0; c1_i13 <= c1_c_loop_ub; c1_i13++) {
        c1_rect_coords_data[c1_i13 + c1_rect_coords_size[0] * c1_i10] =
          c1_img_regions_data[c1_i13 + c1_img_regions_size[0] * (2 + c1_i10)];
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
    c1_b_rect_coords_size[0] = c1_rect_coords_size[0];
    c1_b_rect_coords_size[1] = 2;
    c1_rect_coords = c1_b_rect_coords_size[0];
    c1_b_rect_coords = c1_b_rect_coords_size[1];
    c1_d_loop_ub = c1_rect_coords_size[0] * c1_rect_coords_size[1] - 1;
    for (c1_i14 = 0; c1_i14 <= c1_d_loop_ub; c1_i14++) {
      c1_b_rect_coords_data[c1_i14] = c1_rect_coords_data[c1_i14];
    }

    c1_rect_to_polar(chartInstance, c1_b_rect_coords_data, c1_b_rect_coords_size,
                     c1_c_tmp_data, c1_d_tmp_size);
    c1_angles_to_visit_size[0] = c1_d_tmp_size[0];
    c1_e_loop_ub = c1_d_tmp_size[0] - 1;
    for (c1_i16 = 0; c1_i16 <= c1_e_loop_ub; c1_i16++) {
      c1_angles_to_visit_data[c1_i16] = c1_c_tmp_data[c1_i16];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c1_b_mode, 2.0, -1, 0U,
          c1_b_mode == 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
      c1_i9 = c1_img_regions_size[0];
      c1_b_tmp_size[0] = c1_i9;
      c1_b_loop_ub = c1_i9 - 1;
      for (c1_i12 = 0; c1_i12 <= c1_b_loop_ub; c1_i12++) {
        c1_b_tmp_data[c1_i12] = (c1_img_regions_data[c1_i12 +
          c1_img_regions_size[0]] == c1_b_color);
      }

      c1_end = c1_b_tmp_size[0] - 1;
      c1_b_trueCount = 0;
      c1_c_i = 0;
      while (c1_c_i <= c1_end) {
        if (c1_b_tmp_data[c1_c_i]) {
          c1_b_trueCount++;
        }

        c1_c_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c1_c_tmp_size[0] = c1_b_trueCount;
      c1_b_partialTrueCount = 0;
      c1_d_i = 0;
      while (c1_d_i <= c1_end) {
        if (c1_b_tmp_data[c1_d_i]) {
          c1_d_tmp_data[c1_b_partialTrueCount] = c1_d_i + 1;
          c1_b_partialTrueCount++;
        }

        c1_d_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      c1_img_regions = c1_img_regions_size[0];
      c1_rect_coords_size[0] = c1_c_tmp_size[0];
      c1_rect_coords_size[1] = 2;
      for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
        c1_h_loop_ub = c1_c_tmp_size[0] - 1;
        for (c1_i20 = 0; c1_i20 <= c1_h_loop_ub; c1_i20++) {
          c1_rect_coords_data[c1_i20 + c1_rect_coords_size[0] * c1_i18] =
            c1_img_regions_data[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 1465, 60,
             MAX_uint32_T, c1_d_tmp_data[c1_i20], 1, c1_img_regions) +
            c1_img_regions_size[0] * (2 + c1_i18)) - 1];
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
      c1_c_rect_coords_size[0] = c1_rect_coords_size[0];
      c1_c_rect_coords_size[1] = 2;
      c1_c_rect_coords = c1_c_rect_coords_size[0];
      c1_d_rect_coords = c1_c_rect_coords_size[1];
      c1_i_loop_ub = c1_rect_coords_size[0] * c1_rect_coords_size[1] - 1;
      for (c1_i22 = 0; c1_i22 <= c1_i_loop_ub; c1_i22++) {
        c1_c_rect_coords_data[c1_i22] = c1_rect_coords_data[c1_i22];
      }

      c1_rect_to_polar(chartInstance, c1_c_rect_coords_data,
                       c1_c_rect_coords_size, c1_e_tmp_data, c1_e_tmp_size);
      c1_angles_to_visit_size[0] = c1_e_tmp_size[0];
      c1_j_loop_ub = c1_e_tmp_size[0] - 1;
      for (c1_i23 = 0; c1_i23 <= c1_j_loop_ub; c1_i23++) {
        c1_angles_to_visit_data[c1_i23] = c1_e_tmp_data[c1_i23];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c1_b_mode, 3.0, -1,
            0U, c1_b_mode == 3.0))) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
        c1_angles_to_visit_size[0] = 1;
        c1_angles_to_visit_data[0] = c1_b_position;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
        c1_angles_to_visit_size[0] = 4;
        for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
          c1_angles_to_visit_data[c1_i11] = c1_dv1[c1_i11];
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
  c1_d0 = (real_T)c1_angles_to_visit_size[0];
  c1_b0 = (1.0 > c1_d0);
  c1_b1 = c1_b0;
  c1_b2 = c1_b1;
  if (c1_b2) {
    c1_i15 = 0;
  } else {
    c1_i15 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 1775, 23, MAX_uint32_T, (int32_T)c1_d0, 1, 100);
  }

  c1_tmp_size[0] = c1_i15;
  c1_f_loop_ub = c1_i15 - 1;
  for (c1_i17 = 0; c1_i17 <= c1_f_loop_ub; c1_i17++) {
    c1_tmp_data[c1_i17] = c1_i17;
  }

  c1_iv0[0] = c1_tmp_size[0];
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c1_iv0, 1, c1_angles_to_visit_size, 1);
  c1_g_loop_ub = c1_angles_to_visit_size[0] - 1;
  for (c1_i19 = 0; c1_i19 <= c1_g_loop_ub; c1_i19++) {
    c1_b_angles_vector[c1_tmp_data[c1_i19]] = c1_angles_to_visit_data[c1_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -57);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i21 = 0; c1_i21 < 100; c1_i21++) {
    (*chartInstance->c1_angles_vector)[c1_i21] = c1_b_angles_vector[c1_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_modified_motor(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_rect_to_polar(SFc1_modified_motorInstanceStruct *chartInstance,
  real_T c1_rect_coords_data[], int32_T c1_rect_coords_size[2], real_T
  c1_angles_data[], int32_T c1_angles_size[1])
{
  uint32_T c1_debug_family_var_map[10];
  real_T c1_IMG_LENGTH;
  real_T c1_IMG_HEIGHT;
  real_T c1_IMG_CENTER[2];
  real_T c1_x_from_center_data[100];
  int32_T c1_x_from_center_size[1];
  real_T c1_y_from_center_data[100];
  int32_T c1_y_from_center_size[1];
  real_T c1_cartesian_angles_data[100];
  int32_T c1_cartesian_angles_size[1];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_loop_ub;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_b_loop_ub;
  int32_T c1_i28;
  int32_T c1_x_size[1];
  int32_T c1_c_loop_ub;
  int32_T c1_i29;
  int32_T c1_y_size[1];
  real_T c1_x_data[100];
  int32_T c1_d_loop_ub;
  int32_T c1_i30;
  real_T c1_a[2];
  real_T c1_y_data[100];
  real_T c1_b[2];
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_varargin_1[2];
  boolean_T c1_p;
  real_T c1_varargin_2[2];
  boolean_T c1_b_p;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_x1;
  real_T c1_x2;
  boolean_T c1_c_p;
  boolean_T c1_d_p;
  boolean_T c1_e_p;
  const mxArray *c1_y = NULL;
  static char_T c1_cv0[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'd', 'i', 'm',
    'a', 'g', 'r', 'e', 'e' };

  int32_T c1_e_loop_ub;
  int32_T c1_i33;
  int32_T c1_f_loop_ub;
  int32_T c1_i34;
  int32_T c1_g_loop_ub;
  int32_T c1_i35;
  int32_T c1_h_loop_ub;
  int32_T c1_i36;
  int32_T c1_nx;
  int32_T c1_c_k;
  real_T c1_x;
  real_T c1_b_x;
  int32_T c1_i_loop_ub;
  int32_T c1_i37;
  boolean_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_IMG_LENGTH, 0U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_IMG_HEIGHT, 1U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_IMG_CENTER, 2U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_x_from_center_data, (
    const int32_T *)&c1_x_from_center_size, NULL, 0, 3, (void *)
    c1_d_sf_marshallOut, (void *)c1_c_sf_marshallIn, (void *)
    &c1_x_from_center_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_y_from_center_data, (
    const int32_T *)&c1_y_from_center_size, NULL, 0, 4, (void *)
    c1_d_sf_marshallOut, (void *)c1_c_sf_marshallIn, (void *)
    &c1_y_from_center_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c1_cartesian_angles_data,
    (const int32_T *)&c1_cartesian_angles_size, NULL, 0, 5, (void *)
    c1_d_sf_marshallOut, (void *)c1_c_sf_marshallIn, (void *)
    &c1_cartesian_angles_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)c1_rect_coords_data, (
    const int32_T *)c1_rect_coords_size, NULL, 1, 8, (void *)c1_e_sf_marshallOut,
    (void *)c1_d_sf_marshallIn, (void *)c1_rect_coords_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)c1_angles_data, (const
    int32_T *)c1_angles_size, NULL, 0, 9, (void *)c1_d_sf_marshallOut, (void *)
    c1_c_sf_marshallIn, (void *)c1_angles_data, false);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_IMG_LENGTH = 400.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_IMG_HEIGHT = 400.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 23);
  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_IMG_CENTER[c1_i24] = 200.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_i25 = c1_rect_coords_size[0];
  c1_x_from_center_size[0] = c1_i25;
  c1_loop_ub = c1_i25 - 1;
  for (c1_i26 = 0; c1_i26 <= c1_loop_ub; c1_i26++) {
    c1_x_from_center_data[c1_i26] = 200.0 - c1_rect_coords_data[c1_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_i27 = c1_rect_coords_size[0];
  c1_y_from_center_size[0] = c1_i27;
  c1_b_loop_ub = c1_i27 - 1;
  for (c1_i28 = 0; c1_i28 <= c1_b_loop_ub; c1_i28++) {
    c1_y_from_center_data[c1_i28] = 200.0 - c1_rect_coords_data[c1_i28 +
      c1_rect_coords_size[0]];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_x_size[0] = c1_y_from_center_size[0];
  c1_c_loop_ub = c1_y_from_center_size[0] - 1;
  for (c1_i29 = 0; c1_i29 <= c1_c_loop_ub; c1_i29++) {
    c1_x_data[c1_i29] = c1_y_from_center_data[c1_i29];
  }

  c1_y_size[0] = c1_x_from_center_size[0];
  c1_d_loop_ub = c1_x_from_center_size[0] - 1;
  for (c1_i30 = 0; c1_i30 <= c1_d_loop_ub; c1_i30++) {
    c1_y_data[c1_i30] = c1_x_from_center_data[c1_i30];
  }

  c1_a[0] = (real_T)c1_x_size[0];
  c1_a[1] = 1.0;
  c1_b[0] = (real_T)c1_y_size[0];
  c1_b[1] = 1.0;
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    c1_varargin_1[c1_i31] = c1_a[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
    c1_varargin_2[c1_i32] = c1_b[c1_i32];
  }

  c1_p = false;
  c1_b_p = true;
  c1_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c1_k < 2)) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_x1 = c1_varargin_1[(int32_T)c1_b_k - 1];
    c1_x2 = c1_varargin_2[(int32_T)c1_b_k - 1];
    c1_d_p = (c1_x1 == c1_x2);
    if (!c1_d_p) {
      c1_b_p = false;
      exitg1 = true;
    } else {
      c1_k++;
    }
  }

  if (!c1_b_p) {
  } else {
    c1_p = true;
  }

  c1_c_p = c1_p;
  c1_e_p = c1_c_p;
  if (c1_e_p) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  c1_x_size[0];
  c1_e_loop_ub = c1_x_size[0] - 1;
  for (c1_i33 = 0; c1_i33 <= c1_e_loop_ub; c1_i33++) {
    c1_x_data[c1_i33] /= c1_y_data[c1_i33];
  }

  c1_cartesian_angles_size[0] = c1_x_size[0];
  c1_f_loop_ub = c1_x_size[0] - 1;
  for (c1_i34 = 0; c1_i34 <= c1_f_loop_ub; c1_i34++) {
    c1_cartesian_angles_data[c1_i34] = c1_x_data[c1_i34];
  }

  c1_x_size[0] = c1_cartesian_angles_size[0];
  c1_g_loop_ub = c1_cartesian_angles_size[0] - 1;
  for (c1_i35 = 0; c1_i35 <= c1_g_loop_ub; c1_i35++) {
    c1_x_data[c1_i35] = c1_cartesian_angles_data[c1_i35];
  }

  c1_cartesian_angles_size[0] = c1_x_size[0];
  c1_h_loop_ub = c1_x_size[0] - 1;
  for (c1_i36 = 0; c1_i36 <= c1_h_loop_ub; c1_i36++) {
    c1_cartesian_angles_data[c1_i36] = c1_x_data[c1_i36];
  }

  c1_nx = c1_cartesian_angles_size[0];
  for (c1_c_k = 0; c1_c_k + 1 <= c1_nx; c1_c_k++) {
    c1_x = c1_cartesian_angles_data[c1_c_k];
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarAtan(c1_b_x);
    c1_cartesian_angles_data[c1_c_k] = c1_b_x;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_angles_size[0] = c1_cartesian_angles_size[0];
  c1_i_loop_ub = c1_cartesian_angles_size[0] - 1;
  for (c1_i37 = 0; c1_i37 <= c1_i_loop_ub; c1_i37++) {
    c1_angles_data[c1_i37] = c1_cartesian_angles_data[c1_i37];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\tbirdso\\Documents\\GitHub\\ECE4950Group4\\Project3\\rect_to_polar.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i38;
  const mxArray *c1_y = NULL;
  real_T c1_u[100];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i38 = 0; c1_i38 < 100; c1_i38++) {
    c1_u[c1_i38] = (*(real_T (*)[100])c1_inData)[c1_i38];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 100), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_modified_motorInstanceStruct *chartInstance,
  const mxArray *c1_b_angles_vector, const char_T *c1_identifier, real_T c1_y
  [100])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_angles_vector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_angles_vector);
}

static void c1_b_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100])
{
  real_T c1_dv2[100];
  int32_T c1_i39;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 100);
  for (c1_i39 = 0; c1_i39 < 100; c1_i39++) {
    c1_y[c1_i39] = c1_dv2[c1_i39];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_angles_vector;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[100];
  int32_T c1_i40;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_b_angles_vector = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_angles_vector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_angles_vector);
  for (c1_i40 = 0; c1_i40 < 100; c1_i40++) {
    (*(real_T (*)[100])c1_outData)[c1_i40] = c1_y[c1_i40];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i41;
  int32_T c1_i42;
  const mxArray *c1_y = NULL;
  int32_T c1_i43;
  real_T c1_u[400];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i41 = 0;
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    for (c1_i43 = 0; c1_i43 < 100; c1_i43++) {
      c1_u[c1_i43 + c1_i41] = (*(real_T (*)[400])c1_inData)[c1_i43 + c1_i41];
    }

    c1_i41 += 100;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 100, 4), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[1])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[1];
  int32_T c1_loop_ub;
  int32_T c1_i44;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[100];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_loop_ub = c1_inData_size[0] - 1;
  for (c1_i44 = 0; c1_i44 <= c1_loop_ub; c1_i44++) {
    c1_u_data[c1_i44] = c1_inData_data[c1_i44];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_size[0]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[1])
{
  uint32_T c1_uv0[1];
  int32_T c1_tmp_size[1];
  boolean_T c1_bv1[1];
  real_T c1_tmp_data[100];
  int32_T c1_loop_ub;
  int32_T c1_i45;
  (void)chartInstance;
  c1_uv0[0] = 100U;
  c1_tmp_size[0] = sf_mex_get_dimension(c1_u, 0);
  c1_bv1[0] = true;
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), (void *)&c1_tmp_data, 1, 0, 0U,
                   1, 0U, 1, c1_bv1, c1_uv0, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_loop_ub = c1_tmp_size[0] - 1;
  for (c1_i45 = 0; c1_i45 <= c1_loop_ub; c1_i45++) {
    c1_y_data[c1_i45] = c1_tmp_data[c1_i45];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[1])
{
  const mxArray *c1_angles_to_visit;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[100];
  int32_T c1_y_size[1];
  int32_T c1_loop_ub;
  int32_T c1_i46;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_angles_to_visit = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_angles_to_visit),
                        &c1_thisId, c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_angles_to_visit);
  c1_outData_size[0] = c1_y_size[0];
  c1_loop_ub = c1_y_size[0] - 1;
  for (c1_i46 = 0; c1_i46 <= c1_loop_ub; c1_i46++) {
    c1_outData_data[c1_i46] = c1_y_data[c1_i46];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_u;
  int32_T c1_b_u;
  int32_T c1_loop_ub;
  int32_T c1_i47;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[200];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = 2;
  c1_u = c1_u_size[0];
  c1_b_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i47 = 0; c1_i47 <= c1_loop_ub; c1_i47++) {
    c1_u_data[c1_i47] = c1_inData_data[c1_i47];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i48;
  int32_T c1_tmp_size[2];
  uint32_T c1_uv1[2];
  int32_T c1_i49;
  real_T c1_tmp_data[200];
  boolean_T c1_bv2[2];
  static boolean_T c1_bv3[2] = { true, false };

  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i50;
  (void)chartInstance;
  for (c1_i48 = 0; c1_i48 < 2; c1_i48++) {
    c1_uv1[c1_i48] = 100U + (uint32_T)(-98 * c1_i48);
  }

  c1_tmp_size[0] = sf_mex_get_dimension(c1_u, 0);
  c1_tmp_size[1] = sf_mex_get_dimension(c1_u, 1);
  for (c1_i49 = 0; c1_i49 < 2; c1_i49++) {
    c1_bv2[c1_i49] = c1_bv3[c1_i49];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), (void *)&c1_tmp_data, 1, 0, 0U,
                   1, 0U, 2, c1_bv2, c1_uv1, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_y_size[1] = 2;
  c1_y = c1_y_size[0];
  c1_b_y = c1_y_size[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i50 = 0; c1_i50 <= c1_loop_ub; c1_i50++) {
    c1_y_data[c1_i50] = c1_tmp_data[c1_i50];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2])
{
  const mxArray *c1_rect_coords;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[200];
  int32_T c1_y_size[2];
  int32_T c1_i51;
  int32_T c1_loop_ub;
  int32_T c1_i52;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_rect_coords = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_rect_coords), &c1_thisId,
                        c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_rect_coords);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = 2;
  for (c1_i51 = 0; c1_i51 < 2; c1_i51++) {
    c1_loop_ub = c1_y_size[0] - 1;
    for (c1_i52 = 0; c1_i52 <= c1_loop_ub; c1_i52++) {
      c1_outData_data[c1_i52 + c1_outData_size[0] * c1_i51] = c1_y_data[c1_i52 +
        c1_y_size[0] * c1_i51];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[], int32_T c1_inData_size[2])
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u_size[2];
  int32_T c1_u;
  int32_T c1_b_u;
  int32_T c1_loop_ub;
  int32_T c1_i53;
  const mxArray *c1_y = NULL;
  real_T c1_u_data[400];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u_size[0] = c1_inData_size[0];
  c1_u_size[1] = 4;
  c1_u = c1_u_size[0];
  c1_b_u = c1_u_size[1];
  c1_loop_ub = c1_inData_size[0] * c1_inData_size[1] - 1;
  for (c1_i53 = 0; c1_i53 <= c1_loop_ub; c1_i53++) {
    c1_u_data[c1_i53] = c1_inData_data[c1_i53];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", (void *)&c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_size[0], c1_u_size[1]), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[], int32_T c1_y_size[2])
{
  int32_T c1_i54;
  int32_T c1_tmp_size[2];
  uint32_T c1_uv2[2];
  int32_T c1_i55;
  real_T c1_tmp_data[400];
  boolean_T c1_bv4[2];
  static boolean_T c1_bv5[2] = { true, false };

  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i56;
  (void)chartInstance;
  for (c1_i54 = 0; c1_i54 < 2; c1_i54++) {
    c1_uv2[c1_i54] = 100U + (uint32_T)(-96 * c1_i54);
  }

  c1_tmp_size[0] = sf_mex_get_dimension(c1_u, 0);
  c1_tmp_size[1] = sf_mex_get_dimension(c1_u, 1);
  for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
    c1_bv4[c1_i55] = c1_bv5[c1_i55];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), (void *)&c1_tmp_data, 1, 0, 0U,
                   1, 0U, 2, c1_bv4, c1_uv2, c1_tmp_size);
  c1_y_size[0] = c1_tmp_size[0];
  c1_y_size[1] = 4;
  c1_y = c1_y_size[0];
  c1_b_y = c1_y_size[1];
  c1_loop_ub = c1_tmp_size[0] * c1_tmp_size[1] - 1;
  for (c1_i56 = 0; c1_i56 <= c1_loop_ub; c1_i56++) {
    c1_y_data[c1_i56] = c1_tmp_data[c1_i56];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[], int32_T
  c1_outData_size[2])
{
  const mxArray *c1_img_regions;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y_data[400];
  int32_T c1_y_size[2];
  int32_T c1_i57;
  int32_T c1_loop_ub;
  int32_T c1_i58;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_img_regions = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_img_regions), &c1_thisId,
                        c1_y_data, c1_y_size);
  sf_mex_destroy(&c1_img_regions);
  c1_outData_size[0] = c1_y_size[0];
  c1_outData_size[1] = 4;
  for (c1_i57 = 0; c1_i57 < 4; c1_i57++) {
    c1_loop_ub = c1_y_size[0] - 1;
    for (c1_i58 = 0; c1_i58 <= c1_loop_ub; c1_i58++) {
      c1_outData_data[c1_i58 + c1_outData_size[0] * c1_i57] = c1_y_data[c1_i58 +
        c1_y_size[0] * c1_i57];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i59;
  const mxArray *c1_y = NULL;
  real_T c1_u[2];
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i59 = 0; c1_i59 < 2; c1_i59++) {
    c1_u[c1_i59] = (*(real_T (*)[2])c1_inData)[c1_i59];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i60;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c1_i60 = 0; c1_i60 < 2; c1_i60++) {
    c1_y[c1_i60] = c1_dv3[c1_i60];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_IMG_CENTER;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i61;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_IMG_CENTER = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_IMG_CENTER), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_IMG_CENTER);
  for (c1_i61 = 0; c1_i61 < 2; c1_i61++) {
    (*(real_T (*)[2])c1_outData)[c1_i61] = c1_y[c1_i61];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_modified_motor_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  const char * c1_data[4] = {
    "789ce553cb4ec240149d1224b2d0b032f127ac09a0d1158815f0151270a331d8c7158a9d4e339d21b8f33b8c1fe1d2a57fe1efd8524adb89939210dd7892e6ce"
    "e969efb9733a454af74a41086d0757583f4a688eada8a0caa2165016a2ae486a8c0d54ccbc17eb6f8b6a1297c18c45c4b15db8e6d8001a1057c7b06c63116cbb",
    "bacb06cf1e200a3e71a660cd9547db81818de192a448c70e083e4b494b124ae1ba3506f3a9cf31a2633f19d7491394cae741b2ff624e3e22c47cc4e7623f4fd2"
    "af94e317f72f083c46f927df17ad11d57623cf3f6fbf8a705fb6df58a760b22123438f387af8d5d7cd3bf62b093cf18f148b70c381c4ef7d4dbf0ba95f56bfd3",
    "ee5bc7ea8d0fd457996153cb27ea2931390697f96adb661d6ea85a4bab1dd5f7db9470afa6f62899042955d54c567b78de2f2faf55cf8becff2da3cdc5ea73b0"
    "fbfad5fc3bbf08ffc56f26e9b7eaf9db91f855045d1b55a1dfec9d1f8c26b7a3e9a1a17367563f49e6e8e5f8e4cd8124fcb7fb7f03dcca63fe",
    "" };

  c1_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c1_data, 1744U, &c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i62;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i62, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i62;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_modified_motor, const char_T *
  c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_modified_motor), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_modified_motor);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_modified_motorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_modified_motorInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_mode = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_angles_vector = (real_T (*)[100])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_color = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_position = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_img_data = (real_T (*)[400])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_modified_motor_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2721098331U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3481872065U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3794867109U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3997758915U);
}

mxArray* sf_c1_modified_motor_get_post_codegen_info(void);
mxArray *sf_c1_modified_motor_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("buq7N7DWGeO74pFDTy9y2E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(4);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_modified_motor_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_modified_motor_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_modified_motor_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_modified_motor_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_modified_motor_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_modified_motor(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"angles_vector\",},{M[8],M[0],T\"is_active_c1_modified_motor\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_modified_motor_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_modified_motorInstanceStruct *chartInstance =
      (SFc1_modified_motorInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _modified_motorMachineNumber_,
           1,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           1,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_modified_motorMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_modified_motorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _modified_motorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"mode");
          _SFD_SET_DATA_PROPS(1,1,1,0,"color");
          _SFD_SET_DATA_PROPS(2,1,1,0,"position");
          _SFD_SET_DATA_PROPS(3,1,1,0,"img_data");
          _SFD_SET_DATA_PROPS(4,2,0,1,"angles_vector");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",899,-1,1822);
        _SFD_CV_INIT_EML_IF(0,1,0,1297,1317,1416,1699);
        _SFD_CV_INIT_EML_IF(0,1,1,1416,1446,1578,1699);
        _SFD_CV_INIT_EML_IF(0,1,2,1578,1611,1645,1699);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,1300,1317,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,1423,1446,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1585,1611,-1,0);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"rect_to_polar",377,-1,972);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _modified_motorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_modified_motorInstanceStruct *chartInstance =
      (SFc1_modified_motorInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_mode);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c1_angles_vector);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_color);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_position);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_img_data);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "szjlHv2GPA5JJ5GVFjmEd7";
}

static void sf_opaque_initialize_c1_modified_motor(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar);
  initialize_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_modified_motor(void *chartInstanceVar)
{
  enable_c1_modified_motor((SFc1_modified_motorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_modified_motor(void *chartInstanceVar)
{
  disable_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_modified_motor(void *chartInstanceVar)
{
  sf_gateway_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_modified_motor(SimStruct* S)
{
  return get_sim_state_c1_modified_motor((SFc1_modified_motorInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_modified_motor(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_modified_motor(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_modified_motorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_modified_motor_optimization_info();
    }

    finalize_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_modified_motor((SFc1_modified_motorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_modified_motor(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_modified_motor((SFc1_modified_motorInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_modified_motor(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_modified_motor_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1601072276U));
  ssSetChecksum1(S,(776539462U));
  ssSetChecksum2(S,(4155111740U));
  ssSetChecksum3(S,(2596336098U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_modified_motor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_modified_motor(SimStruct *S)
{
  SFc1_modified_motorInstanceStruct *chartInstance;
  chartInstance = (SFc1_modified_motorInstanceStruct *)utMalloc(sizeof
    (SFc1_modified_motorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_modified_motorInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_modified_motor;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_modified_motor;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_modified_motor;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_modified_motor;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_modified_motor;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_modified_motor;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_modified_motor;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_modified_motor;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_modified_motor;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_modified_motor;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_modified_motor;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_modified_motor(chartInstance);
}

void c1_modified_motor_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_modified_motor(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_modified_motor(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_modified_motor(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_modified_motor_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
