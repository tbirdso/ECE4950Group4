/*
 * modified_motor_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.50
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Mar 09 23:28:12 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modified_motor.h"
#include "modified_motor_private.h"

/* Block parameters (auto storage) */
P_modified_motor_T modified_motor_P = {
  3.2284E-6,                           /* Variable: J
                                        * Referenced by: '<S10>/Inertia '
                                        */
  0.0274,                              /* Variable: Ke
                                        * Referenced by: '<S10>/Ke'
                                        */
  0.0274,                              /* Variable: Kt
                                        * Referenced by: '<S10>/Kt'
                                        */
  0.01,                                /* Variable: L
                                        * Referenced by: '<S10>/Inductance'
                                        */
  4.0,                                 /* Variable: R
                                        * Referenced by: '<S10>/Resistance'
                                        */
  3.5077E-6,                           /* Variable: b
                                        * Referenced by: '<S10>/Damping'
                                        */
  -0.040956521739,                     /* Expression: -0.040956521739
                                        * Referenced by: '<S1>/FIXME_const_pos_out'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */

  /*  Computed Parameter: Q4Enc_P1_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P2_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P3_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P4_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P5_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P6_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P7_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P8_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P9_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P10_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P11_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P12_Size
   * Referenced by: '<S7>/Q4 Enc '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S7>/Q4 Enc '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Switch1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S3>/Kp'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S3>/Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/KI'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gate1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Gate2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S7>/Saturation'
                                        */

  /*  Computed Parameter: Q4DA_P1_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P2_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P3_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  -5.0,                                /* Expression: range
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P4_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P5_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P6_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P7_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P8_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S7>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P9_Size
   * Referenced by: '<S7>/Q4 DA '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S7>/Q4 DA '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/TODO_Color_Input'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/TODO_ID_Input1'
                                        */
  0                                    /* Computed Parameter: TODO_Mode_input_Value
                                        * Referenced by: '<S2>/TODO_Mode_input'
                                        */
};
