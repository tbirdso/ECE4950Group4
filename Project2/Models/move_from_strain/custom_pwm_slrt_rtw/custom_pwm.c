/*
 * custom_pwm.c
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

#include "rt_logging_mmi.h"
#include "custom_pwm_capi.h"
#include "custom_pwm.h"
#include "custom_pwm_private.h"

/* Block signals (auto storage) */
B_custom_pwm_T custom_pwm_B;

/* Block states (auto storage) */
DW_custom_pwm_T custom_pwm_DW;

/* Real-time model */
RT_MODEL_custom_pwm_T custom_pwm_M_;
RT_MODEL_custom_pwm_T *const custom_pwm_M = &custom_pwm_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T q;
  boolean_T y_0;
  boolean_T y_1;
  y = u0;
  y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
  y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
  if (!(y_0 && y_1)) {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      y_0 = (y == 0.0);
      if ((!y_0) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        y_0 = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (y_0) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Model output function */
static void custom_pwm_output(void)
{
  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  custom_pwm_DW.SFunction_IWORK.AcquireOK = 1;

  /* Clock: '<S1>/Clock' */
  custom_pwm_B.Clock = custom_pwm_M->Timing.t[0];

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<Root>/PD'
   */
  custom_pwm_B.Sum2 = custom_pwm_B.Clock - custom_pwm_P.PD_Value;

  /* Math: '<S1>/mod' incorporates:
   *  Constant: '<Root>/Period'
   */
  custom_pwm_B.mod = rt_modd_snf(custom_pwm_B.Sum2, custom_pwm_P.Period_Value);

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<Root>/PW'
   *  Constant: '<Root>/Period'
   *  Constant: '<S1>/Constant'
   */
  custom_pwm_B.Product = custom_pwm_P.Period_Value * custom_pwm_P.PW_Value *
    custom_pwm_P.Constant_Value;

  /* RelationalOperator: '<S1>/Relational Operator' */
  custom_pwm_B.RelationalOperator = (custom_pwm_B.mod <= custom_pwm_B.Product);

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  custom_pwm_B.DataTypeConversion = custom_pwm_B.RelationalOperator;

  /* Switch: '<S1>/Phase Delay Switch' incorporates:
   *  Constant: '<Root>/Amplitude'
   *  Constant: '<S1>/Constant1'
   */
  if (custom_pwm_B.Sum2 >= custom_pwm_P.PhaseDelaySwitch_Threshold) {
    custom_pwm_B.PhaseDelaySwitch = custom_pwm_P.Amplitude_Value;
  } else {
    custom_pwm_B.PhaseDelaySwitch = custom_pwm_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Phase Delay Switch' */

  /* Product: '<S1>/Product1' */
  custom_pwm_B.Product1 = custom_pwm_B.PhaseDelaySwitch *
    custom_pwm_B.DataTypeConversion;
}

/* Model update function */
static void custom_pwm_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++custom_pwm_M->Timing.clockTick0)) {
    ++custom_pwm_M->Timing.clockTickH0;
  }

  custom_pwm_M->Timing.t[0] = custom_pwm_M->Timing.clockTick0 *
    custom_pwm_M->Timing.stepSize0 + custom_pwm_M->Timing.clockTickH0 *
    custom_pwm_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++custom_pwm_M->Timing.clockTick1)) {
      ++custom_pwm_M->Timing.clockTickH1;
    }

    custom_pwm_M->Timing.t[1] = custom_pwm_M->Timing.clockTick1 *
      custom_pwm_M->Timing.stepSize1 + custom_pwm_M->Timing.clockTickH1 *
      custom_pwm_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void custom_pwm_initialize(void)
{
  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo(
          "Programmable Pulse Generator/Product1"));
        rl32eSetScope(1, 4, 250);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo(
          "Programmable Pulse Generator/Product1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 5.0);
        xpceScopeAcqOK(1, &custom_pwm_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }
}

/* Model terminate function */
static void custom_pwm_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  custom_pwm_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  custom_pwm_update();
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
  custom_pwm_initialize();
}

void MdlTerminate(void)
{
  custom_pwm_terminate();
}

/* Registration function */
RT_MODEL_custom_pwm_T *custom_pwm(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)custom_pwm_M, 0,
                sizeof(RT_MODEL_custom_pwm_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&custom_pwm_M->solverInfo,
                          &custom_pwm_M->Timing.simTimeStep);
    rtsiSetTPtr(&custom_pwm_M->solverInfo, &rtmGetTPtr(custom_pwm_M));
    rtsiSetStepSizePtr(&custom_pwm_M->solverInfo,
                       &custom_pwm_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&custom_pwm_M->solverInfo, (&rtmGetErrorStatus
      (custom_pwm_M)));
    rtsiSetRTModelPtr(&custom_pwm_M->solverInfo, custom_pwm_M);
  }

  rtsiSetSimTimeStep(&custom_pwm_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&custom_pwm_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = custom_pwm_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    custom_pwm_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    custom_pwm_M->Timing.sampleTimes = (&custom_pwm_M->Timing.sampleTimesArray[0]);
    custom_pwm_M->Timing.offsetTimes = (&custom_pwm_M->Timing.offsetTimesArray[0]);

    /* task periods */
    custom_pwm_M->Timing.sampleTimes[0] = (0.0);
    custom_pwm_M->Timing.sampleTimes[1] = (0.0002);

    /* task offsets */
    custom_pwm_M->Timing.offsetTimes[0] = (0.0);
    custom_pwm_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(custom_pwm_M, &custom_pwm_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = custom_pwm_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    custom_pwm_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(custom_pwm_M, -1);
  custom_pwm_M->Timing.stepSize0 = 0.0002;
  custom_pwm_M->Timing.stepSize1 = 0.0002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    custom_pwm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(custom_pwm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(custom_pwm_M->rtwLogInfo, (NULL));
    rtliSetLogT(custom_pwm_M->rtwLogInfo, "tout");
    rtliSetLogX(custom_pwm_M->rtwLogInfo, "");
    rtliSetLogXFinal(custom_pwm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(custom_pwm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(custom_pwm_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(custom_pwm_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(custom_pwm_M->rtwLogInfo, 1);
    rtliSetLogY(custom_pwm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(custom_pwm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(custom_pwm_M->rtwLogInfo, (NULL));
  }

  custom_pwm_M->solverInfoPtr = (&custom_pwm_M->solverInfo);
  custom_pwm_M->Timing.stepSize = (0.0002);
  rtsiSetFixedStepSize(&custom_pwm_M->solverInfo, 0.0002);
  rtsiSetSolverMode(&custom_pwm_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  custom_pwm_M->blockIO = ((void *) &custom_pwm_B);
  (void) memset(((void *) &custom_pwm_B), 0,
                sizeof(B_custom_pwm_T));

  /* parameters */
  custom_pwm_M->defaultParam = ((real_T *)&custom_pwm_P);

  /* states (dwork) */
  custom_pwm_M->dwork = ((void *) &custom_pwm_DW);
  (void) memset((void *)&custom_pwm_DW, 0,
                sizeof(DW_custom_pwm_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  custom_pwm_InitializeDataMapInfo(custom_pwm_M);

  /* Initialize Sizes */
  custom_pwm_M->Sizes.numContStates = (0);/* Number of continuous states */
  custom_pwm_M->Sizes.numY = (0);      /* Number of model outputs */
  custom_pwm_M->Sizes.numU = (0);      /* Number of model inputs */
  custom_pwm_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  custom_pwm_M->Sizes.numSampTimes = (2);/* Number of sample times */
  custom_pwm_M->Sizes.numBlocks = (15);/* Number of blocks */
  custom_pwm_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  custom_pwm_M->Sizes.numBlockPrms = (7);/* Sum of parameter "widths" */
  return custom_pwm_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
