/*
 * modified_motor.c
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

#include "rt_logging_mmi.h"
#include "modified_motor_capi.h"
#include "modified_motor.h"
#include "modified_motor_private.h"

/* Block signals (auto storage) */
B_modified_motor_T modified_motor_B;

/* Continuous states */
X_modified_motor_T modified_motor_X;

/* Block states (auto storage) */
DW_modified_motor_T modified_motor_DW;

/* Real-time model */
RT_MODEL_modified_motor_T modified_motor_M_;
RT_MODEL_modified_motor_T *const modified_motor_M = &modified_motor_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  modified_motor_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  modified_motor_output();
  modified_motor_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  modified_motor_output();
  modified_motor_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void modified_motor_output(void)
{
  real_T *lastU;
  real_T lastTime;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* set solver stop time */
    if (!(modified_motor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&modified_motor_M->solverInfo,
                            ((modified_motor_M->Timing.clockTickH0 + 1) *
        modified_motor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&modified_motor_M->solverInfo,
                            ((modified_motor_M->Timing.clockTick0 + 1) *
        modified_motor_M->Timing.stepSize0 +
        modified_motor_M->Timing.clockTickH0 *
        modified_motor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modified_motor_M)) {
    modified_motor_M->Timing.t[0] = rtsiGetT(&modified_motor_M->solverInfo);
  }

  /* Integrator: '<S10>/Integrator2' */
  modified_motor_B.theta = modified_motor_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* Constant: '<S1>/FIXME_const_pos_out' */
    modified_motor_B.FIXME_const_pos_out =
      modified_motor_P.FIXME_const_pos_out_Value;

    /* Gain: '<S3>/Gain' */
    modified_motor_B.Gain = modified_motor_P.Gain_Gain *
      modified_motor_B.FIXME_const_pos_out;

    /* S-Function (encquanserq8): '<S7>/Q4 Enc ' */

    /* Level2 S-Function Block: '<S7>/Q4 Enc ' (encquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* MATLAB Function: '<S7>/Convert to Rad' */
    /* MATLAB Function 'motor_subsystem/Real motor/Convert to Rad': '<S12>:1' */
    /*  Observed experimentally */
    /* '<S12>:1:6' */
    /* '<S12>:1:8' */
    modified_motor_B.y = modified_motor_B.Positionsteps * 2.0 *
      3.1415926535897931 / 400.0 - 3.1415926535897931;

    /* Fcn: '<S7>/Invert Sign' */
    modified_motor_B.Positionrad = -modified_motor_B.y;
  }

  /* Switch: '<S11>/Switch1' incorporates:
   *  Constant: '<S3>/Switch'
   */
  if (modified_motor_P.Switch_Value > modified_motor_P.Switch1_Threshold) {
    modified_motor_B.Switch1 = modified_motor_B.theta;
  } else {
    modified_motor_B.Switch1 = modified_motor_B.Positionrad;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Sum: '<S3>/Sum' */
  modified_motor_B.Sig1 = modified_motor_B.Gain - modified_motor_B.Switch1;

  /* Gain: '<S3>/Kp' */
  modified_motor_B.Kp = modified_motor_P.Kp_Gain * modified_motor_B.Sig1;

  /* Derivative: '<S3>/Derivative' */
  if ((modified_motor_DW.TimeStampA >= modified_motor_M->Timing.t[0]) &&
      (modified_motor_DW.TimeStampB >= modified_motor_M->Timing.t[0])) {
    modified_motor_B.Derivative = 0.0;
  } else {
    lastTime = modified_motor_DW.TimeStampA;
    lastU = &modified_motor_DW.LastUAtTimeA;
    if (modified_motor_DW.TimeStampA < modified_motor_DW.TimeStampB) {
      if (modified_motor_DW.TimeStampB < modified_motor_M->Timing.t[0]) {
        lastTime = modified_motor_DW.TimeStampB;
        lastU = &modified_motor_DW.LastUAtTimeB;
      }
    } else {
      if (modified_motor_DW.TimeStampA >= modified_motor_M->Timing.t[0]) {
        lastTime = modified_motor_DW.TimeStampB;
        lastU = &modified_motor_DW.LastUAtTimeB;
      }
    }

    lastTime = modified_motor_M->Timing.t[0] - lastTime;
    modified_motor_B.Derivative = (modified_motor_B.Sig1 - *lastU) / lastTime;
  }

  /* End of Derivative: '<S3>/Derivative' */

  /* Gain: '<S3>/Kd' */
  modified_motor_B.Kd = modified_motor_P.Kd_Gain * modified_motor_B.Derivative;

  /* Integrator: '<S3>/Integrator' */
  modified_motor_B.Integrator = modified_motor_X.Integrator_CSTATE;

  /* Gain: '<S3>/KI' */
  modified_motor_B.KI = modified_motor_P.KI_Gain * modified_motor_B.Integrator;

  /* Sum: '<S3>/Sum1' */
  modified_motor_B.Pos_Input = (modified_motor_B.Kp + modified_motor_B.Kd) +
    modified_motor_B.KI;

  /* Saturate: '<S3>/Saturation' */
  lastTime = modified_motor_B.Pos_Input;
  u1 = modified_motor_P.Saturation_LowerSat;
  u2 = modified_motor_P.Saturation_UpperSat;
  if (lastTime > u2) {
    modified_motor_B.Voltage_Input = u2;
  } else if (lastTime < u1) {
    modified_motor_B.Voltage_Input = u1;
  } else {
    modified_motor_B.Voltage_Input = lastTime;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
  }

  /* S-Function (scblock): '<S8>/S-Function' */
  /* ok to acquire for <S8>/S-Function */
  modified_motor_DW.SFunction_IWORK.AcquireOK = 1;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (scblock): '<S9>/S-Function' */
    /* ok to acquire for <S9>/S-Function */
    modified_motor_DW.SFunction_IWORK_m.AcquireOK = 1;

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S3>/Switch'
     *  Constant: '<S6>/Constant'
     */
    modified_motor_B.SwitchPosition = modified_motor_P.Constant_Value -
      modified_motor_P.Switch_Value;
  }

  /* Switch: '<S6>/Gate1' incorporates:
   *  Constant: '<S3>/Switch'
   */
  if (modified_motor_P.Switch_Value > modified_motor_P.Gate1_Threshold) {
    modified_motor_B.SimulatedMotor = modified_motor_B.Voltage_Input;
  } else {
    modified_motor_B.SimulatedMotor = 0.0;
  }

  /* End of Switch: '<S6>/Gate1' */

  /* Switch: '<S6>/Gate2' */
  if (modified_motor_B.SwitchPosition > modified_motor_P.Gate2_Threshold) {
    modified_motor_B.RealMotor = modified_motor_B.Voltage_Input;
  } else {
    modified_motor_B.RealMotor = 0.0;
  }

  /* End of Switch: '<S6>/Gate2' */

  /* Saturate: '<S7>/Saturation' */
  lastTime = modified_motor_B.RealMotor;
  u1 = modified_motor_P.Saturation_LowerSat_d;
  u2 = modified_motor_P.Saturation_UpperSat_a;
  if (lastTime > u2) {
    modified_motor_B.Saturation = u2;
  } else if (lastTime < u1) {
    modified_motor_B.Saturation = u1;
  } else {
    modified_motor_B.Saturation = lastTime;
  }

  /* End of Saturate: '<S7>/Saturation' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (daquanserq8): '<S7>/Q4 DA ' */

    /* Level2 S-Function Block: '<S7>/Q4 DA ' (daquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }
  }

  /* Integrator: '<S10>/Integrator' */
  modified_motor_B.i = modified_motor_X.Integrator_CSTATE_g;

  /* Gain: '<S10>/Resistance' */
  modified_motor_B.Resistance = modified_motor_P.R * modified_motor_B.i;

  /* Integrator: '<S10>/Integrator1' */
  modified_motor_B.ddttheta = modified_motor_X.Integrator1_CSTATE;

  /* Gain: '<S10>/Ke' */
  modified_motor_B.Ke = modified_motor_P.Ke * modified_motor_B.ddttheta;

  /* Sum: '<S10>/Add' */
  modified_motor_B.Add = (modified_motor_B.SimulatedMotor -
    modified_motor_B.Resistance) - modified_motor_B.Ke;

  /* Gain: '<S10>/Kt' */
  modified_motor_B.Kt = modified_motor_P.Kt * modified_motor_B.i;

  /* Gain: '<S10>/Damping' */
  modified_motor_B.Damping = modified_motor_P.b * modified_motor_B.ddttheta;

  /* Sum: '<S10>/Add1' */
  modified_motor_B.Add1 = modified_motor_B.Kt - modified_motor_B.Damping;

  /* Gain: '<S10>/Inductance' */
  lastTime = modified_motor_P.L;
  lastTime = 1.0 / lastTime;
  modified_motor_B.ddti = lastTime * modified_motor_B.Add;

  /* Gain: '<S10>/Inertia ' */
  lastTime = modified_motor_P.J;
  lastTime = 1.0 / lastTime;
  modified_motor_B.d2dt2theta = lastTime * modified_motor_B.Add1;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (scblock): '<S5>/S-Function' */
    /* ok to acquire for <S5>/S-Function */
    modified_motor_DW.SFunction_IWORK_f.AcquireOK = 1;

    /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
     *  Constant: '<S2>/TODO_Mode_input'
     */
    modified_motor_B.DataTypeConversion2 =
      modified_motor_P.TODO_Mode_input_Value;

    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Constant: '<S2>/TODO_Color_Input'
     */
    modified_motor_B.DataTypeConversion1 =
      modified_motor_P.TODO_Color_Input_Value;

    /* MATLAB Function: '<S1>/Image Processing' */
    /* MATLAB Function 'Image Processing/Image Processing': '<S4>:1' */
    /*  PURPOSE - process user GUI selections and generate positions accordingly */
    /*  INPUTS */
    /*    - Mode: What should the system do in response to the user selection */
    /*        - scan: Visit every well with a sticker */
    /*        - seek color: Visit every well with a sticker of the given color */
    /*        - seek position: Visit only the well with the given sticker ID */
    /*  OUTPUTS */
    /*    - target_pos: The fixed destination position to which the motor */
    /*        arm should point on the range (-pi, pi] */
    /*  NOTES */
    /*    - If mode = 2 then the function ignores ID. */
    /*    - If mode = 3 then the function ignores color. */
    /*    - The motor must always return to its original position at the end of */
    /*    the action. */
    /*    - The function will always need to iterate through more than one */
    /*    position in order to visit at least one well and return to its original */
    /*    position. We probably need to introduce a clock/counter/some form of */
    /*    memory or delay for this purpose. */
    /*    TODO process params + computer vision */
    /* '<S4>:1:27' */
    modified_motor_B.y_c = 3.1415926535897931;

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Constant: '<S2>/TODO_ID_Input1'
     */
    modified_motor_B.id_val = modified_motor_P.TODO_ID_Input1_Value;
  }
}

/* Model update function */
void modified_motor_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S3>/Derivative' */
  if (modified_motor_DW.TimeStampA == (rtInf)) {
    modified_motor_DW.TimeStampA = modified_motor_M->Timing.t[0];
    lastU = &modified_motor_DW.LastUAtTimeA;
  } else if (modified_motor_DW.TimeStampB == (rtInf)) {
    modified_motor_DW.TimeStampB = modified_motor_M->Timing.t[0];
    lastU = &modified_motor_DW.LastUAtTimeB;
  } else if (modified_motor_DW.TimeStampA < modified_motor_DW.TimeStampB) {
    modified_motor_DW.TimeStampA = modified_motor_M->Timing.t[0];
    lastU = &modified_motor_DW.LastUAtTimeA;
  } else {
    modified_motor_DW.TimeStampB = modified_motor_M->Timing.t[0];
    lastU = &modified_motor_DW.LastUAtTimeB;
  }

  *lastU = modified_motor_B.Sig1;

  /* End of Update for Derivative: '<S3>/Derivative' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    rt_ertODEUpdateContinuousStates(&modified_motor_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++modified_motor_M->Timing.clockTick0)) {
    ++modified_motor_M->Timing.clockTickH0;
  }

  modified_motor_M->Timing.t[0] = rtsiGetSolverStopTime
    (&modified_motor_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++modified_motor_M->Timing.clockTick1)) {
      ++modified_motor_M->Timing.clockTickH1;
    }

    modified_motor_M->Timing.t[1] = modified_motor_M->Timing.clockTick1 *
      modified_motor_M->Timing.stepSize1 + modified_motor_M->Timing.clockTickH1 *
      modified_motor_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void modified_motor_derivatives(void)
{
  XDot_modified_motor_T *_rtXdot;
  _rtXdot = ((XDot_modified_motor_T *) modified_motor_M->derivs);

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = modified_motor_B.ddttheta;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = modified_motor_B.Sig1;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = modified_motor_B.ddti;

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = modified_motor_B.d2dt2theta;
}

/* Model initialize function */
void modified_motor_initialize(void)
{
  /* Start for S-Function (encquanserq8): '<S7>/Q4 Enc ' */
  /* Level2 S-Function Block: '<S7>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S8>/S-Function' */

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("motor_subsystem/Sum"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("motor_subsystem/Sum"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 2.0);
        xpceScopeAcqOK(2, &modified_motor_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S9>/S-Function' */

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("motor_subsystem/Real motor/Q4 Enc "));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "motor_subsystem/Real motor/Q4 Enc "),"%15.6f");
        rl32eSetScope(4, 4, 250);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo(
          "motor_subsystem/Real motor/Q4 Enc "));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 2.0);
        xpceScopeAcqOK(4, &modified_motor_DW.SFunction_IWORK_m.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Start for S-Function (daquanserq8): '<S7>/Q4 DA ' */
  /* Level2 S-Function Block: '<S7>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S5>/S-Function' */

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Image Processing/Image Processing"));
        rl32eSetScope(1, 4, 250);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Image Processing/Image Processing"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &modified_motor_DW.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* InitializeConditions for Integrator: '<S10>/Integrator2' */
  modified_motor_X.Integrator2_CSTATE = modified_motor_P.Integrator2_IC;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  modified_motor_DW.TimeStampA = (rtInf);
  modified_motor_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  modified_motor_X.Integrator_CSTATE = modified_motor_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  modified_motor_X.Integrator_CSTATE_g = modified_motor_P.Integrator_IC_a;

  /* InitializeConditions for Integrator: '<S10>/Integrator1' */
  modified_motor_X.Integrator1_CSTATE = modified_motor_P.Integrator1_IC;
}

/* Model terminate function */
void modified_motor_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<S7>/Q4 Enc ' */
  /* Level2 S-Function Block: '<S7>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<S7>/Q4 DA ' */
  /* Level2 S-Function Block: '<S7>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  modified_motor_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  modified_motor_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  modified_motor_initialize();
}

void MdlTerminate(void)
{
  modified_motor_terminate();
}

/* Registration function */
RT_MODEL_modified_motor_T *modified_motor(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)modified_motor_M, 0,
                sizeof(RT_MODEL_modified_motor_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&modified_motor_M->solverInfo,
                          &modified_motor_M->Timing.simTimeStep);
    rtsiSetTPtr(&modified_motor_M->solverInfo, &rtmGetTPtr(modified_motor_M));
    rtsiSetStepSizePtr(&modified_motor_M->solverInfo,
                       &modified_motor_M->Timing.stepSize0);
    rtsiSetdXPtr(&modified_motor_M->solverInfo, &modified_motor_M->derivs);
    rtsiSetContStatesPtr(&modified_motor_M->solverInfo, (real_T **)
                         &modified_motor_M->contStates);
    rtsiSetNumContStatesPtr(&modified_motor_M->solverInfo,
      &modified_motor_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&modified_motor_M->solverInfo,
      &modified_motor_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&modified_motor_M->solverInfo,
      &modified_motor_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&modified_motor_M->solverInfo,
      &modified_motor_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&modified_motor_M->solverInfo, (&rtmGetErrorStatus
      (modified_motor_M)));
    rtsiSetRTModelPtr(&modified_motor_M->solverInfo, modified_motor_M);
  }

  rtsiSetSimTimeStep(&modified_motor_M->solverInfo, MAJOR_TIME_STEP);
  modified_motor_M->intgData.y = modified_motor_M->odeY;
  modified_motor_M->intgData.f[0] = modified_motor_M->odeF[0];
  modified_motor_M->intgData.f[1] = modified_motor_M->odeF[1];
  modified_motor_M->intgData.f[2] = modified_motor_M->odeF[2];
  modified_motor_M->contStates = ((real_T *) &modified_motor_X);
  rtsiSetSolverData(&modified_motor_M->solverInfo, (void *)
                    &modified_motor_M->intgData);
  rtsiSetSolverName(&modified_motor_M->solverInfo,"ode3");
  modified_motor_M->solverInfoPtr = (&modified_motor_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = modified_motor_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    modified_motor_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    modified_motor_M->Timing.sampleTimes =
      (&modified_motor_M->Timing.sampleTimesArray[0]);
    modified_motor_M->Timing.offsetTimes =
      (&modified_motor_M->Timing.offsetTimesArray[0]);

    /* task periods */
    modified_motor_M->Timing.sampleTimes[0] = (0.0);
    modified_motor_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    modified_motor_M->Timing.offsetTimes[0] = (0.0);
    modified_motor_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(modified_motor_M, &modified_motor_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = modified_motor_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    modified_motor_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(modified_motor_M, -1);
  modified_motor_M->Timing.stepSize0 = 0.001;
  modified_motor_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    modified_motor_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(modified_motor_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(modified_motor_M->rtwLogInfo, (NULL));
    rtliSetLogT(modified_motor_M->rtwLogInfo, "tout");
    rtliSetLogX(modified_motor_M->rtwLogInfo, "");
    rtliSetLogXFinal(modified_motor_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(modified_motor_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(modified_motor_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(modified_motor_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(modified_motor_M->rtwLogInfo, 1);
    rtliSetLogY(modified_motor_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(modified_motor_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(modified_motor_M->rtwLogInfo, (NULL));
  }

  modified_motor_M->solverInfoPtr = (&modified_motor_M->solverInfo);
  modified_motor_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&modified_motor_M->solverInfo, 0.001);
  rtsiSetSolverMode(&modified_motor_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  modified_motor_M->blockIO = ((void *) &modified_motor_B);
  (void) memset(((void *) &modified_motor_B), 0,
                sizeof(B_modified_motor_T));

  /* parameters */
  modified_motor_M->defaultParam = ((real_T *)&modified_motor_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &modified_motor_X;
    modified_motor_M->contStates = (x);
    (void) memset((void *)&modified_motor_X, 0,
                  sizeof(X_modified_motor_T));
  }

  /* states (dwork) */
  modified_motor_M->dwork = ((void *) &modified_motor_DW);
  (void) memset((void *)&modified_motor_DW, 0,
                sizeof(DW_modified_motor_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  modified_motor_InitializeDataMapInfo(modified_motor_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &modified_motor_M->NonInlinedSFcns.sfcnInfo;
    modified_motor_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(modified_motor_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &modified_motor_M->Sizes.numSampTimes);
    modified_motor_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (modified_motor_M)[0]);
    modified_motor_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (modified_motor_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,modified_motor_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(modified_motor_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(modified_motor_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (modified_motor_M));
    rtssSetStepSizePtr(sfcnInfo, &modified_motor_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(modified_motor_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &modified_motor_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &modified_motor_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &modified_motor_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &modified_motor_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &modified_motor_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &modified_motor_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &modified_motor_M->solverInfoPtr);
  }

  modified_motor_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&modified_motor_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    modified_motor_M->childSfunctions =
      (&modified_motor_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    modified_motor_M->childSfunctions[0] =
      (&modified_motor_M->NonInlinedSFcns.childSFunctions[0]);
    modified_motor_M->childSfunctions[1] =
      (&modified_motor_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: modified_motor/<S7>/Q4 Enc  (encquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = modified_motor_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = modified_motor_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = modified_motor_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &modified_motor_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, modified_motor_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &modified_motor_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &modified_motor_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &modified_motor_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &modified_motor_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &modified_motor_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &modified_motor_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &modified_motor_B.Positionsteps));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 Enc ");
      ssSetPath(rts, "modified_motor/motor_subsystem/Real motor/Q4 Enc ");
      ssSetRTModel(rts,modified_motor_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modified_motor_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)modified_motor_P.Q4Enc_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)modified_motor_P.Q4Enc_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)modified_motor_P.Q4Enc_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)modified_motor_P.Q4Enc_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)modified_motor_P.Q4Enc_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)modified_motor_P.Q4Enc_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)modified_motor_P.Q4Enc_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)modified_motor_P.Q4Enc_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)modified_motor_P.Q4Enc_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)modified_motor_P.Q4Enc_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)modified_motor_P.Q4Enc_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)modified_motor_P.Q4Enc_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &modified_motor_DW.Q4Enc_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modified_motor_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modified_motor_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modified_motor_DW.Q4Enc_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: modified_motor/<S7>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = modified_motor_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = modified_motor_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = modified_motor_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &modified_motor_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, modified_motor_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &modified_motor_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &modified_motor_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &modified_motor_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &modified_motor_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &modified_motor_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &modified_motor_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &modified_motor_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &modified_motor_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "modified_motor/motor_subsystem/Real motor/Q4 DA ");
      ssSetRTModel(rts,modified_motor_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &modified_motor_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)modified_motor_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)modified_motor_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)modified_motor_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)modified_motor_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)modified_motor_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)modified_motor_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)modified_motor_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)modified_motor_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)modified_motor_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &modified_motor_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &modified_motor_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &modified_motor_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &modified_motor_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &modified_motor_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &modified_motor_DW.Q4DA_IWORK);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  modified_motor_M->Sizes.numContStates = (4);/* Number of continuous states */
  modified_motor_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  modified_motor_M->Sizes.numY = (0);  /* Number of model outputs */
  modified_motor_M->Sizes.numU = (0);  /* Number of model inputs */
  modified_motor_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  modified_motor_M->Sizes.numSampTimes = (2);/* Number of sample times */
  modified_motor_M->Sizes.numBlocks = (48);/* Number of blocks */
  modified_motor_M->Sizes.numBlockIO = (33);/* Number of block outputs */
  modified_motor_M->Sizes.numBlockPrms = (90);/* Sum of parameter "widths" */
  return modified_motor_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
