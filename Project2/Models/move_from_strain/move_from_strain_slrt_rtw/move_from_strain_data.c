/*
 * move_from_strain_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "move_from_strain".
 *
 * Model version              : 1.55
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Feb 16 16:29:48 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "move_from_strain.h"
#include "move_from_strain_private.h"

/* Block parameters (auto storage) */
P_move_from_strain_T move_from_strain_P = {
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Amplitude'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/PD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Phase Delay Switch'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<Root>/Period'
                                        */

  /*  Computed Parameter: Q4AD_P1_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P2_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P3_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: index03
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P4_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: Q4AD_P5_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.0002,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P6_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 AD'
                                        */

  /*  Computed Parameter: Q4AD_P7_Size
   * Referenced by: '<Root>/Q4 AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 AD'
                                        */
  0.01,                                /* Expression: 1/100
                                        * Referenced by: '<S3>/Constant'
                                        */

  /*  Computed Parameter: Q4DO_P1_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P2_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P3_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P4_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P5_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P6_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0002,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P7_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Q4 DO '
                                        */

  /*  Computed Parameter: Q4DO_P8_Size
   * Referenced by: '<Root>/Q4 DO '
   */
  { 1.0, 1.0 },
  -1.0                                 /* Expression: pciSlot
                                        * Referenced by: '<Root>/Q4 DO '
                                        */
};
