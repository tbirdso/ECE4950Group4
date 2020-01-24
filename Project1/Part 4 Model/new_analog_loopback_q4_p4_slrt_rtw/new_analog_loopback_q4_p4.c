/*
 * new_analog_loopback_q4_p4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "new_analog_loopback_q4_p4".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Fri Jan 24 00:04:14 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "new_analog_loopback_q4_p4_capi.h"
#include "new_analog_loopback_q4_p4.h"
#include "new_analog_loopback_q4_p4_private.h"

/* Block signals (auto storage) */
B_new_analog_loopback_q4_p4_T new_analog_loopback_q4_p4_B;

/* Block states (auto storage) */
DW_new_analog_loopback_q4_p4_T new_analog_loopback_q4_p4_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_new_analog_loopback_q4_p4_T new_analog_loopback_q4_p4_Y;

/* Real-time model */
RT_MODEL_new_analog_loopback_q4_p4_T new_analog_loopback_q4_p4_M_;
RT_MODEL_new_analog_loopback_q4_p4_T *const new_analog_loopback_q4_p4_M =
  &new_analog_loopback_q4_p4_M_;

/* Model output function */
static void new_analog_loopback_q4_p4_output(void)
{
  /* S-Function (encquanserq8): '<Root>/Q4 Enc ' */

  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_p4_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Outport: '<Root>/Out2' */
  new_analog_loopback_q4_p4_Y.Out2 = new_analog_loopback_q4_p4_B.Q4Enc;

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  new_analog_loopback_q4_p4_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  new_analog_loopback_q4_p4_DW.SFunction_IWORK_e.AcquireOK = 1;
}

/* Model update function */
static void new_analog_loopback_q4_p4_update(void)
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
  if (!(++new_analog_loopback_q4_p4_M->Timing.clockTick0)) {
    ++new_analog_loopback_q4_p4_M->Timing.clockTickH0;
  }

  new_analog_loopback_q4_p4_M->Timing.t[0] =
    new_analog_loopback_q4_p4_M->Timing.clockTick0 *
    new_analog_loopback_q4_p4_M->Timing.stepSize0 +
    new_analog_loopback_q4_p4_M->Timing.clockTickH0 *
    new_analog_loopback_q4_p4_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void new_analog_loopback_q4_p4_initialize(void)
{
  /* Start for S-Function (encquanserq8): '<Root>/Q4 Enc ' */
  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_p4_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Q4 Enc "),"%15.6f");
        rl32eSetScope(2, 4, 100);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -1.0);
        rl32eSetTargetScope(2, 10, 1.0);
        xpceScopeAcqOK(2,
                       &new_analog_loopback_q4_p4_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetScope(1, 4, 100);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Q4 Enc "));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, -1.0);
        rl32eSetTargetScope(1, 10, 1.0);
        xpceScopeAcqOK(1,
                       &new_analog_loopback_q4_p4_DW.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }
}

/* Model terminate function */
static void new_analog_loopback_q4_p4_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<Root>/Q4 Enc ' */
  /* Level2 S-Function Block: '<Root>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = new_analog_loopback_q4_p4_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  new_analog_loopback_q4_p4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  new_analog_loopback_q4_p4_update();
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
  new_analog_loopback_q4_p4_initialize();
}

void MdlTerminate(void)
{
  new_analog_loopback_q4_p4_terminate();
}

/* Registration function */
RT_MODEL_new_analog_loopback_q4_p4_T *new_analog_loopback_q4_p4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)new_analog_loopback_q4_p4_M, 0,
                sizeof(RT_MODEL_new_analog_loopback_q4_p4_T));
  rtsiSetSolverName(&new_analog_loopback_q4_p4_M->solverInfo,"FixedStepDiscrete");
  new_analog_loopback_q4_p4_M->solverInfoPtr =
    (&new_analog_loopback_q4_p4_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = new_analog_loopback_q4_p4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    new_analog_loopback_q4_p4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    new_analog_loopback_q4_p4_M->Timing.sampleTimes =
      (&new_analog_loopback_q4_p4_M->Timing.sampleTimesArray[0]);
    new_analog_loopback_q4_p4_M->Timing.offsetTimes =
      (&new_analog_loopback_q4_p4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    new_analog_loopback_q4_p4_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    new_analog_loopback_q4_p4_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(new_analog_loopback_q4_p4_M,
             &new_analog_loopback_q4_p4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = new_analog_loopback_q4_p4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    new_analog_loopback_q4_p4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(new_analog_loopback_q4_p4_M, -1);
  new_analog_loopback_q4_p4_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    new_analog_loopback_q4_p4_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(new_analog_loopback_q4_p4_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(new_analog_loopback_q4_p4_M->rtwLogInfo, (NULL));
    rtliSetLogT(new_analog_loopback_q4_p4_M->rtwLogInfo, "tout");
    rtliSetLogX(new_analog_loopback_q4_p4_M->rtwLogInfo, "");
    rtliSetLogXFinal(new_analog_loopback_q4_p4_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(new_analog_loopback_q4_p4_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(new_analog_loopback_q4_p4_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(new_analog_loopback_q4_p4_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(new_analog_loopback_q4_p4_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &new_analog_loopback_q4_p4_Y.Out2
      };

      rtliSetLogYSignalPtrs(new_analog_loopback_q4_p4_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "new_analog_loopback_q4_p4/Out2" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(new_analog_loopback_q4_p4_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(new_analog_loopback_q4_p4_M->rtwLogInfo, "yout");
  }

  new_analog_loopback_q4_p4_M->solverInfoPtr =
    (&new_analog_loopback_q4_p4_M->solverInfo);
  new_analog_loopback_q4_p4_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&new_analog_loopback_q4_p4_M->solverInfo, 0.001);
  rtsiSetSolverMode(&new_analog_loopback_q4_p4_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  new_analog_loopback_q4_p4_M->blockIO = ((void *) &new_analog_loopback_q4_p4_B);
  (void) memset(((void *) &new_analog_loopback_q4_p4_B), 0,
                sizeof(B_new_analog_loopback_q4_p4_T));

  /* parameters */
  new_analog_loopback_q4_p4_M->defaultParam = ((real_T *)
    &new_analog_loopback_q4_p4_P);

  /* states (dwork) */
  new_analog_loopback_q4_p4_M->dwork = ((void *) &new_analog_loopback_q4_p4_DW);
  (void) memset((void *)&new_analog_loopback_q4_p4_DW, 0,
                sizeof(DW_new_analog_loopback_q4_p4_T));

  /* external outputs */
  new_analog_loopback_q4_p4_M->outputs = (&new_analog_loopback_q4_p4_Y);
  new_analog_loopback_q4_p4_Y.Out2 = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  new_analog_loopback_q4_p4_InitializeDataMapInfo(new_analog_loopback_q4_p4_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &new_analog_loopback_q4_p4_M->NonInlinedSFcns.sfcnInfo;
    new_analog_loopback_q4_p4_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (new_analog_loopback_q4_p4_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &new_analog_loopback_q4_p4_M->Sizes.numSampTimes);
    new_analog_loopback_q4_p4_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (new_analog_loopback_q4_p4_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,
                   new_analog_loopback_q4_p4_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(new_analog_loopback_q4_p4_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(new_analog_loopback_q4_p4_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (new_analog_loopback_q4_p4_M));
    rtssSetStepSizePtr(sfcnInfo, &new_analog_loopback_q4_p4_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (new_analog_loopback_q4_p4_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &new_analog_loopback_q4_p4_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &new_analog_loopback_q4_p4_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &new_analog_loopback_q4_p4_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &new_analog_loopback_q4_p4_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &new_analog_loopback_q4_p4_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &new_analog_loopback_q4_p4_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &new_analog_loopback_q4_p4_M->solverInfoPtr);
  }

  new_analog_loopback_q4_p4_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &new_analog_loopback_q4_p4_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    new_analog_loopback_q4_p4_M->childSfunctions =
      (&new_analog_loopback_q4_p4_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    new_analog_loopback_q4_p4_M->childSfunctions[0] =
      (&new_analog_loopback_q4_p4_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: new_analog_loopback_q4_p4/<Root>/Q4 Enc  (encquanserq8) */
    {
      SimStruct *rts = new_analog_loopback_q4_p4_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &new_analog_loopback_q4_p4_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, new_analog_loopback_q4_p4_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &new_analog_loopback_q4_p4_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &new_analog_loopback_q4_p4_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &new_analog_loopback_q4_p4_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &new_analog_loopback_q4_p4_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &new_analog_loopback_q4_p4_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &new_analog_loopback_q4_p4_B.Q4Enc));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 Enc ");
      ssSetPath(rts, "new_analog_loopback_q4_p4/Q4 Enc ");
      ssSetRTModel(rts,new_analog_loopback_q4_p4_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       new_analog_loopback_q4_p4_P.Q4Enc_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &new_analog_loopback_q4_p4_DW.Q4Enc_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &new_analog_loopback_q4_p4_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &new_analog_loopback_q4_p4_DW.Q4Enc_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  new_analog_loopback_q4_p4_M->Sizes.numContStates = (0);/* Number of continuous states */
  new_analog_loopback_q4_p4_M->Sizes.numY = (1);/* Number of model outputs */
  new_analog_loopback_q4_p4_M->Sizes.numU = (0);/* Number of model inputs */
  new_analog_loopback_q4_p4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  new_analog_loopback_q4_p4_M->Sizes.numSampTimes = (1);/* Number of sample times */
  new_analog_loopback_q4_p4_M->Sizes.numBlocks = (4);/* Number of blocks */
  new_analog_loopback_q4_p4_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  new_analog_loopback_q4_p4_M->Sizes.numBlockPrms = (36);/* Sum of parameter "widths" */
  return new_analog_loopback_q4_p4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
