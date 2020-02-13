/*
 * custom_pwm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "custom_pwm".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Feb 13 12:59:47 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "custom_pwm.h"
#include "custom_pwm_private.h"

/* Block parameters (auto storage) */
P_custom_pwm_T custom_pwm_P = {
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Amplitude'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/PD'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/PW'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<Root>/Period'
                                        */
  0.01,                                /* Expression: 1/100
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<S1>/Phase Delay Switch'
                                        */
};
