/*
 * modified_motor_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.222
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Mar 12 19:59:54 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modified_motor_types_h_
#define RTW_HEADER_modified_motor_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef struct_emxArray_int32_T_100
#define struct_emxArray_int32_T_100

struct emxArray_int32_T_100
{
  int32_T data[100];
  int32_T size;
};

#endif                                 /*struct_emxArray_int32_T_100*/

#ifndef typedef_emxArray_int32_T_100_modified_T
#define typedef_emxArray_int32_T_100_modified_T

typedef struct emxArray_int32_T_100 emxArray_int32_T_100_modified_T;

#endif                                 /*typedef_emxArray_int32_T_100_modified_T*/

/* Parameters (auto storage) */
typedef struct P_modified_motor_T_ P_modified_motor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_modified_motor_T RT_MODEL_modified_motor_T;

#endif                                 /* RTW_HEADER_modified_motor_types_h_ */
