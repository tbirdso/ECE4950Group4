/*
 * modified_motor_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.145
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 11 23:07:30 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modified_motor_private_h_
#define RTW_HEADER_modified_motor_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "modified_motor.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void encquanserq8(SimStruct *rts);
extern void daquanserq8(SimStruct *rts);
void modified_motor_output0(void);
void modified_motor_update0(void);
void modified_motor_output2(void);
void modified_motor_update2(void);     /* private model entry point functions */
extern void modified_motor_derivatives(void);

#endif                                 /* RTW_HEADER_modified_motor_private_h_ */
