/*
 * move_from_strain.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "move_from_strain".
 *
 * Model version              : 1.48
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Feb 13 16:44:14 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "move_from_strain_capi.h"
#include "move_from_strain.h"
#include "move_from_strain_private.h"

/* Block signals (auto storage) */
B_move_from_strain_T move_from_strain_B;

/* Block states (auto storage) */
DW_move_from_strain_T move_from_strain_DW;

/* Real-time model */
RT_MODEL_move_from_strain_T move_from_strain_M_;
RT_MODEL_move_from_strain_T *const move_from_strain_M = &move_from_strain_M_;
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
static void move_from_strain_output(void)
{
  /* Clock: '<S2>/Clock' */
  move_from_strain_B.Clock = move_from_strain_M->Timing.t[0];

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<Root>/PD'
   */
  move_from_strain_B.Sum2 = move_from_strain_B.Clock -
    move_from_strain_P.PD_Value;

  /* Switch: '<S2>/Phase Delay Switch' incorporates:
   *  Constant: '<Root>/Amplitude'
   *  Constant: '<S2>/Constant1'
   */
  if (move_from_strain_B.Sum2 >= move_from_strain_P.PhaseDelaySwitch_Threshold)
  {
    move_from_strain_B.PhaseDelaySwitch = move_from_strain_P.Amplitude_Value;
  } else {
    move_from_strain_B.PhaseDelaySwitch = move_from_strain_P.Constant1_Value;
  }

  /* End of Switch: '<S2>/Phase Delay Switch' */

  /* Math: '<S2>/mod' incorporates:
   *  Constant: '<Root>/Period'
   */
  move_from_strain_B.mod = rt_modd_snf(move_from_strain_B.Sum2,
    move_from_strain_P.Period_Value);

  /* S-Function (adquanserq8): '<Root>/Q4 AD' */

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* MATLAB Function: '<Root>/PW Mapping' */
  /* MATLAB Function 'PW Mapping': '<S1>:1' */
  /* '<S1>:1:3' */
  move_from_strain_B.y = floor(move_from_strain_B.Q4AD) * 10.0 + 2.2;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<Root>/Period'
   *  Constant: '<S2>/Constant'
   */
  move_from_strain_B.Product = move_from_strain_P.Period_Value *
    move_from_strain_B.y * move_from_strain_P.Constant_Value;

  /* RelationalOperator: '<S2>/Relational Operator' */
  move_from_strain_B.RelationalOperator = (move_from_strain_B.mod <=
    move_from_strain_B.Product);

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  move_from_strain_B.DataTypeConversion = move_from_strain_B.RelationalOperator;

  /* Product: '<S2>/Product1' */
  move_from_strain_B.Product1 = move_from_strain_B.PhaseDelaySwitch *
    move_from_strain_B.DataTypeConversion;

  /* S-Function (doquanserq8): '<Root>/Q4 DO ' */

  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (scblock): '<S3>/S-Function' */
  /* ok to acquire for <S3>/S-Function */
  move_from_strain_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S4>/S-Function' */
  /* ok to acquire for <S4>/S-Function */
  move_from_strain_DW.SFunction_IWORK_d.AcquireOK = 1;
}

/* Model update function */
static void move_from_strain_update(void)
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
  if (!(++move_from_strain_M->Timing.clockTick0)) {
    ++move_from_strain_M->Timing.clockTickH0;
  }

  move_from_strain_M->Timing.t[0] = move_from_strain_M->Timing.clockTick0 *
    move_from_strain_M->Timing.stepSize0 +
    move_from_strain_M->Timing.clockTickH0 *
    move_from_strain_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++move_from_strain_M->Timing.clockTick1)) {
      ++move_from_strain_M->Timing.clockTickH1;
    }

    move_from_strain_M->Timing.t[1] = move_from_strain_M->Timing.clockTick1 *
      move_from_strain_M->Timing.stepSize1 +
      move_from_strain_M->Timing.clockTickH1 *
      move_from_strain_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void move_from_strain_initialize(void)
{
  /* Start for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (doquanserq8): '<Root>/Q4 DO ' */
  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 11, 0.0);
        rl32eSetTargetScope(2, 10, 2.0);
        xpceScopeAcqOK(2, &move_from_strain_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S4>/S-Function' */

  /* S-Function Block: <S4>/S-Function (scblock) */
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
        rl32eSetTargetScope(1, 10, 6.0);
        xpceScopeAcqOK(1, &move_from_strain_DW.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }
}

/* Model terminate function */
static void move_from_strain_terminate(void)
{
  /* Terminate for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (doquanserq8): '<Root>/Q4 DO ' */
  /* Level2 S-Function Block: '<Root>/Q4 DO ' (doquanserq8) */
  {
    SimStruct *rts = move_from_strain_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  move_from_strain_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  move_from_strain_update();
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
  move_from_strain_initialize();
}

void MdlTerminate(void)
{
  move_from_strain_terminate();
}

/* Registration function */
RT_MODEL_move_from_strain_T *move_from_strain(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)move_from_strain_M, 0,
                sizeof(RT_MODEL_move_from_strain_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&move_from_strain_M->solverInfo,
                          &move_from_strain_M->Timing.simTimeStep);
    rtsiSetTPtr(&move_from_strain_M->solverInfo, &rtmGetTPtr(move_from_strain_M));
    rtsiSetStepSizePtr(&move_from_strain_M->solverInfo,
                       &move_from_strain_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&move_from_strain_M->solverInfo, (&rtmGetErrorStatus
      (move_from_strain_M)));
    rtsiSetRTModelPtr(&move_from_strain_M->solverInfo, move_from_strain_M);
  }

  rtsiSetSimTimeStep(&move_from_strain_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&move_from_strain_M->solverInfo,"FixedStepDiscrete");
  move_from_strain_M->solverInfoPtr = (&move_from_strain_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = move_from_strain_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    move_from_strain_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    move_from_strain_M->Timing.sampleTimes =
      (&move_from_strain_M->Timing.sampleTimesArray[0]);
    move_from_strain_M->Timing.offsetTimes =
      (&move_from_strain_M->Timing.offsetTimesArray[0]);

    /* task periods */
    move_from_strain_M->Timing.sampleTimes[0] = (0.0);
    move_from_strain_M->Timing.sampleTimes[1] = (0.0002);

    /* task offsets */
    move_from_strain_M->Timing.offsetTimes[0] = (0.0);
    move_from_strain_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(move_from_strain_M, &move_from_strain_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = move_from_strain_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    move_from_strain_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(move_from_strain_M, -1);
  move_from_strain_M->Timing.stepSize0 = 0.0002;
  move_from_strain_M->Timing.stepSize1 = 0.0002;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    move_from_strain_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(move_from_strain_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(move_from_strain_M->rtwLogInfo, (NULL));
    rtliSetLogT(move_from_strain_M->rtwLogInfo, "tout");
    rtliSetLogX(move_from_strain_M->rtwLogInfo, "");
    rtliSetLogXFinal(move_from_strain_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(move_from_strain_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(move_from_strain_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(move_from_strain_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(move_from_strain_M->rtwLogInfo, 1);
    rtliSetLogY(move_from_strain_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(move_from_strain_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(move_from_strain_M->rtwLogInfo, (NULL));
  }

  move_from_strain_M->solverInfoPtr = (&move_from_strain_M->solverInfo);
  move_from_strain_M->Timing.stepSize = (0.0002);
  rtsiSetFixedStepSize(&move_from_strain_M->solverInfo, 0.0002);
  rtsiSetSolverMode(&move_from_strain_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  move_from_strain_M->blockIO = ((void *) &move_from_strain_B);
  (void) memset(((void *) &move_from_strain_B), 0,
                sizeof(B_move_from_strain_T));

  /* parameters */
  move_from_strain_M->defaultParam = ((real_T *)&move_from_strain_P);

  /* states (dwork) */
  move_from_strain_M->dwork = ((void *) &move_from_strain_DW);
  (void) memset((void *)&move_from_strain_DW, 0,
                sizeof(DW_move_from_strain_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  move_from_strain_InitializeDataMapInfo(move_from_strain_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &move_from_strain_M->NonInlinedSFcns.sfcnInfo;
    move_from_strain_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(move_from_strain_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &move_from_strain_M->Sizes.numSampTimes);
    move_from_strain_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (move_from_strain_M)[0]);
    move_from_strain_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (move_from_strain_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,move_from_strain_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(move_from_strain_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(move_from_strain_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (move_from_strain_M));
    rtssSetStepSizePtr(sfcnInfo, &move_from_strain_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(move_from_strain_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &move_from_strain_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &move_from_strain_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &move_from_strain_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &move_from_strain_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &move_from_strain_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &move_from_strain_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &move_from_strain_M->solverInfoPtr);
  }

  move_from_strain_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&move_from_strain_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    move_from_strain_M->childSfunctions =
      (&move_from_strain_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    move_from_strain_M->childSfunctions[0] =
      (&move_from_strain_M->NonInlinedSFcns.childSFunctions[0]);
    move_from_strain_M->childSfunctions[1] =
      (&move_from_strain_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: move_from_strain/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = move_from_strain_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = move_from_strain_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = move_from_strain_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = move_from_strain_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &move_from_strain_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, move_from_strain_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &move_from_strain_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &move_from_strain_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &move_from_strain_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &move_from_strain_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &move_from_strain_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &move_from_strain_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &move_from_strain_B.Q4AD));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "move_from_strain/Q4 AD");
      ssSetRTModel(rts,move_from_strain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &move_from_strain_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)move_from_strain_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)move_from_strain_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)move_from_strain_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)move_from_strain_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)move_from_strain_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)move_from_strain_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)move_from_strain_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &move_from_strain_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &move_from_strain_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &move_from_strain_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &move_from_strain_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: move_from_strain/<Root>/Q4 DO  (doquanserq8) */
    {
      SimStruct *rts = move_from_strain_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = move_from_strain_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = move_from_strain_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = move_from_strain_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &move_from_strain_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, move_from_strain_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &move_from_strain_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &move_from_strain_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &move_from_strain_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &move_from_strain_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &move_from_strain_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &move_from_strain_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &move_from_strain_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &move_from_strain_B.Product1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DO ");
      ssSetPath(rts, "move_from_strain/Q4 DO ");
      ssSetRTModel(rts,move_from_strain_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &move_from_strain_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)move_from_strain_P.Q4DO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)move_from_strain_P.Q4DO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)move_from_strain_P.Q4DO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)move_from_strain_P.Q4DO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)move_from_strain_P.Q4DO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)move_from_strain_P.Q4DO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)move_from_strain_P.Q4DO_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)move_from_strain_P.Q4DO_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &move_from_strain_DW.Q4DO_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &move_from_strain_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &move_from_strain_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &move_from_strain_DW.Q4DO_IWORK);
      }

      /* registration */
      doquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0002);
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
  move_from_strain_M->Sizes.numContStates = (0);/* Number of continuous states */
  move_from_strain_M->Sizes.numY = (0);/* Number of model outputs */
  move_from_strain_M->Sizes.numU = (0);/* Number of model inputs */
  move_from_strain_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  move_from_strain_M->Sizes.numSampTimes = (2);/* Number of sample times */
  move_from_strain_M->Sizes.numBlocks = (19);/* Number of blocks */
  move_from_strain_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  move_from_strain_M->Sizes.numBlockPrms = (50);/* Sum of parameter "widths" */
  return move_from_strain_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
