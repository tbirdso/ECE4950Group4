/*
 * modified_motor_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.141
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 11 21:18:23 2020
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
                                        * Referenced by: '<S17>/Inertia '
                                        */
  0.0274,                              /* Variable: Ke
                                        * Referenced by: '<S17>/Ke'
                                        */
  0.0274,                              /* Variable: Kt
                                        * Referenced by: '<S17>/Kt'
                                        */
  0.01,                                /* Variable: L
                                        * Referenced by: '<S17>/Inductance'
                                        */
  4.0,                                 /* Variable: R
                                        * Referenced by: '<S17>/Resistance'
                                        */
  3.5077E-6,                           /* Variable: b
                                        * Referenced by: '<S17>/Damping'
                                        */
  0.0,                                 /* Computed Parameter: Target_Position_Y0
                                        * Referenced by: '<S10>/Target_Position'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Store_Index'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Store Image Data'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Rate Transition'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */

  /*  Computed Parameter: Q4Enc_P1_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P2_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P3_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P4_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P5_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P6_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P7_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P8_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P9_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P10_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P11_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */

  /*  Computed Parameter: Q4Enc_P12_Size
   * Referenced by: '<S14>/Q4 Enc '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S14>/Q4 Enc '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/Kp'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S4>/Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/KI'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Gate1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Gate2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S14>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S14>/Saturation'
                                        */

  /*  Computed Parameter: Q4DA_P1_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P2_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P3_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  -5.0,                                /* Expression: range
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P4_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P5_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P6_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P7_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P8_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S14>/Q4 DA '
                                        */

  /*  Computed Parameter: Q4DA_P9_Size
   * Referenced by: '<S14>/Q4 DA '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S14>/Q4 DA '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Run'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Color'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/ID'
                                        */
  1                                    /* Computed Parameter: Mode_Value
                                        * Referenced by: '<S3>/Mode '
                                        */
};
