#ifndef __c1_modified_motor_h__
#define __c1_modified_motor_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_modified_motorInstanceStruct
#define typedef_SFc1_modified_motorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_modified_motor;
  void *c1_fEmlrtCtx;
  real_T *c1_mode;
  real_T (*c1_angles_vector)[100];
  real_T *c1_color;
  real_T *c1_position;
  real_T (*c1_img_data)[400];
} SFc1_modified_motorInstanceStruct;

#endif                                 /*typedef_SFc1_modified_motorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_modified_motor_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_modified_motor_get_check_sum(mxArray *plhs[]);
extern void c1_modified_motor_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
