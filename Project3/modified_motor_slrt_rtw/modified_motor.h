/*
 * modified_motor.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.171
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Mar 12 01:55:07 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modified_motor_h_
#define RTW_HEADER_modified_motor_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef modified_motor_COMMON_INCLUDES_
# define modified_motor_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "xpcimports.h"
#endif                                 /* modified_motor_COMMON_INCLUDES_ */

#include "modified_motor_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_modified_motor         RT_MODEL_modified_motor_T

/* Definition for use in the target main file */
#define modified_motor_rtModel         RT_MODEL_modified_motor_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  real_T target_pos;                   /* '<S2>/Rate Transition' */
  real_T Run;                          /* '<Root>/Run' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T theta;                        /* '<S14>/Integrator2' */
  real_T Positionsteps;                /* '<S11>/Q4 Enc ' */
  real_T Positionrad;                  /* '<S11>/Invert Sign' */
  real_T Switch1;                      /* '<S15>/Switch1' */
  real_T Sig1;                         /* '<S4>/Sum' */
  real_T Kp;                           /* '<S4>/Kp' */
  real_T Derivative;                   /* '<S4>/Derivative' */
  real_T Kd;                           /* '<S4>/Kd' */
  real_T Integrator;                   /* '<S4>/Integrator' */
  real_T KI;                           /* '<S4>/KI' */
  real_T Pos_Input;                    /* '<S4>/Sum1' */
  real_T Voltage_Input;                /* '<S4>/Saturation' */
  real_T SwitchPosition;               /* '<S10>/Add' */
  real_T SimulatedMotor;               /* '<S10>/Gate1' */
  real_T RealMotor;                    /* '<S10>/Gate2' */
  real_T Saturation;                   /* '<S11>/Saturation' */
  real_T i;                            /* '<S14>/Integrator' */
  real_T Resistance;                   /* '<S14>/Resistance' */
  real_T ddttheta;                     /* '<S14>/Integrator1' */
  real_T Ke;                           /* '<S14>/Ke' */
  real_T Add;                          /* '<S14>/Add' */
  real_T Kt;                           /* '<S14>/Kt' */
  real_T Damping;                      /* '<S14>/Damping' */
  real_T Add1;                         /* '<S14>/Add1' */
  real_T ddti;                         /* '<S14>/Inductance' */
  real_T d2dt2theta;                   /* '<S14>/Inertia ' */
  real_T UnitDelay;                    /* '<S6>/Unit Delay' */
  real_T Sum;                          /* '<S6>/Sum' */
  real_T DataTypeConversion2;          /* '<S3>/Data Type Conversion2' */
  real_T DataTypeConversion1;          /* '<S3>/Data Type Conversion1' */
  real_T DataTypeConversion;           /* '<S3>/Data Type Conversion' */
  real_T TmpRTBAtPositionIteratorInport2;
  real_T y;                            /* '<S11>/Convert to Rad' */
  real_T iter_cur_index;               /* '<S8>/Data Store Read' */
  real_T DataStoreRead1;               /* '<S8>/Data Store Read1' */
  real_T target_pos_o;                 /* '<S8>/Iterator' */
  real_T next_index;                   /* '<S8>/Iterator' */
  real_T next_run;                     /* '<S8>/Iterator' */
  real_T angles_vector[100];           /* '<S2>/Generate Angles List' */
  real_T image_data[400];              /* '<S1>/Process Image' */
} B_modified_motor_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S6>/Unit Delay' */
  real_T RateTransition_Buffer0;       /* '<S2>/Rate Transition' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  volatile real_T TmpRTBAtPositionIteratorInport2;/* synthesized block */
  real_T Index;                        /* '<S8>/Store_Index' */
  real_T Run_sig;                      /* '<S8>/Store_Index1' */
  real_T Q4DA_RWORK[16];               /* '<S11>/Q4 DA ' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFor_;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_l;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_e;   /* synthesized block */

  int_T Q4Enc_IWORK[3];                /* '<S11>/Q4 Enc ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S12>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_m;                 /* '<S13>/S-Function' */

  int_T Q4DA_IWORK;                    /* '<S11>/Q4 DA ' */
  volatile int8_T TmpRTBAtPositionIteratorInpor_a;/* synthesized block */
  int8_T PositionIterator_SubsysRanBC; /* '<S2>/Position Iterator' */
} DW_modified_motor_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S14>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S14>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S14>/Integrator1' */
} X_modified_motor_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S14>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S14>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S14>/Integrator1' */
} XDot_modified_motor_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S14>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S14>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S14>/Integrator1' */
} XDis_modified_motor_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState PositionIterator_Trig_ZCE;/* '<S2>/Position Iterator' */
} PrevZCX_modified_motor_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            modified_motor_B
#define BlockIO                        B_modified_motor_T
#define rtX                            modified_motor_X
#define ContinuousStates               X_modified_motor_T
#define rtXdot                         modified_motor_XDot
#define StateDerivatives               XDot_modified_motor_T
#define tXdis                          modified_motor_XDis
#define StateDisabled                  XDis_modified_motor_T
#define rtP                            modified_motor_P
#define Parameters                     P_modified_motor_T
#define rtDWork                        modified_motor_DW
#define D_Work                         DW_modified_motor_T
#define rtPrevZCSigState               modified_motor_PrevZCX
#define PrevZCSigStates                PrevZCX_modified_motor_T

/* Parameters (auto storage) */
struct P_modified_motor_T_ {
  real_T J;                            /* Variable: J
                                        * Referenced by: '<S14>/Inertia '
                                        */
  real_T Ke;                           /* Variable: Ke
                                        * Referenced by: '<S14>/Ke'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by: '<S14>/Kt'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S14>/Inductance'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by: '<S14>/Resistance'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<S14>/Damping'
                                        */
  real_T Target_Position_Y0;           /* Computed Parameter: Target_Position_Y0
                                        * Referenced by: '<S8>/Target_Position'
                                        */
  real_T Store_Index_InitialValue;     /* Expression: 0
                                        * Referenced by: '<S8>/Store_Index'
                                        */
  real_T Store_Index1_InitialValue;    /* Expression: 0
                                        * Referenced by: '<S8>/Store_Index1'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S2>/Rate Transition'
                                        */
  real_T Run_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/Run'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S14>/Integrator2'
                                        */
  real_T Switch_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Q4Enc_P1_Size[2];             /* Computed Parameter: Q4Enc_P1_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P1;                     /* Expression: boardtype
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P2_Size[2];             /* Computed Parameter: Q4Enc_P2_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P2;                     /* Expression: channel
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P3_Size[2];             /* Computed Parameter: Q4Enc_P3_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P3;                     /* Expression: initialCount
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P4_Size[2];             /* Computed Parameter: Q4Enc_P4_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P4;                     /* Expression: prescale
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P5_Size[2];             /* Computed Parameter: Q4Enc_P5_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P5;                     /* Expression: quadrature
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P6_Size[2];             /* Computed Parameter: Q4Enc_P6_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P6;                     /* Expression: mode
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P7_Size[2];             /* Computed Parameter: Q4Enc_P7_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P7;                     /* Expression: synchronousIndex
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P8_Size[2];             /* Computed Parameter: Q4Enc_P8_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P8;                     /* Expression: indexPolarity
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P9_Size[2];             /* Computed Parameter: Q4Enc_P9_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P9;                     /* Expression: preserveCounts
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P10_Size[2];            /* Computed Parameter: Q4Enc_P10_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P10;                    /* Expression: sampleTime
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P11_Size[2];            /* Computed Parameter: Q4Enc_P11_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P11;                    /* Expression: pciBus
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P12_Size[2];            /* Computed Parameter: Q4Enc_P12_Size
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Q4Enc_P12;                    /* Expression: pciSlot
                                        * Referenced by: '<S11>/Q4 Enc '
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S15>/Switch1'
                                        */
  real_T Kp_Gain;                      /* Expression: 10
                                        * Referenced by: '<S4>/Kp'
                                        */
  real_T Kd_Gain;                      /* Expression: 0.2
                                        * Referenced by: '<S4>/Kd'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T KI_Gain;                      /* Expression: 0
                                        * Referenced by: '<S4>/KI'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gate1_Threshold;              /* Expression: 0
                                        * Referenced by: '<S10>/Gate1'
                                        */
  real_T Gate2_Threshold;              /* Expression: 0
                                        * Referenced by: '<S10>/Gate2'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 5
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -5
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Q4DA_P1_Size[2];              /* Computed Parameter: Q4DA_P1_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P1;                      /* Expression: boardtype
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P2_Size[2];              /* Computed Parameter: Q4DA_P2_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P2;                      /* Expression: channel
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P3_Size[2];              /* Computed Parameter: Q4DA_P3_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P3;                      /* Expression: range
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P4_Size[2];              /* Computed Parameter: Q4DA_P4_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P4;                      /* Expression: simul
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P5_Size[2];              /* Computed Parameter: Q4DA_P5_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P5;                      /* Expression: reset
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P6_Size[2];              /* Computed Parameter: Q4DA_P6_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P6;                      /* Expression: initValue
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P7_Size[2];              /* Computed Parameter: Q4DA_P7_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P7;                      /* Expression: sampleTime
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P8_Size[2];              /* Computed Parameter: Q4DA_P8_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P8;                      /* Expression: pciBus
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P9_Size[2];              /* Computed Parameter: Q4DA_P9_Size
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Q4DA_P9;                      /* Expression: pciSlot
                                        * Referenced by: '<S11>/Q4 DA '
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S14>/Integrator1'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  real_T Color_Value;                  /* Expression: 1
                                        * Referenced by: '<S3>/Color'
                                        */
  real_T Position_Value;               /* Expression: -3.1416
                                        * Referenced by: '<S3>/Position'
                                        */
  int8_T Mode_Value;                   /* Computed Parameter: Mode_Value
                                        * Referenced by: '<S3>/Mode'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_modified_motor_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssSFcnModelMethods4 methods4[2];
    struct _ssStatesInfo2 statesInfo2[2];
    ssPeriodicStatesInfo periodicStatesInfo[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;
  } NonInlinedSFcns;

  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_modified_motor_T modified_motor_P;

/* Block signals (auto storage) */
extern B_modified_motor_T modified_motor_B;

/* Continuous states (auto storage) */
extern X_modified_motor_T modified_motor_X;

/* Block states (auto storage) */
extern DW_modified_motor_T modified_motor_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_modified_motor_T modified_motor_PrevZCX;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void modified_motor_initialize(void);
extern void modified_motor_output0(void);
extern void modified_motor_update0(void);
extern void modified_motor_output(int_T tid);
extern void modified_motor_update(int_T tid);
extern void modified_motor_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern modified_motor_rtModel *modified_motor(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  modified_motor_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_modified_motor_T *const modified_motor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'modified_motor'
 * '<S1>'   : 'modified_motor/Imager'
 * '<S2>'   : 'modified_motor/Logic Block'
 * '<S3>'   : 'modified_motor/UI'
 * '<S4>'   : 'modified_motor/motor_subsystem'
 * '<S5>'   : 'modified_motor/Imager/Process Image'
 * '<S6>'   : 'modified_motor/Logic Block/Clock'
 * '<S7>'   : 'modified_motor/Logic Block/Generate Angles List'
 * '<S8>'   : 'modified_motor/Logic Block/Position Iterator'
 * '<S9>'   : 'modified_motor/Logic Block/Position Iterator/Iterator'
 * '<S10>'  : 'modified_motor/motor_subsystem/Motor Selector'
 * '<S11>'  : 'modified_motor/motor_subsystem/Real motor'
 * '<S12>'  : 'modified_motor/motor_subsystem/Scope 1'
 * '<S13>'  : 'modified_motor/motor_subsystem/Scope 3'
 * '<S14>'  : 'modified_motor/motor_subsystem/Simulated Motor'
 * '<S15>'  : 'modified_motor/motor_subsystem/Switching Logic'
 * '<S16>'  : 'modified_motor/motor_subsystem/Real motor/Convert to Rad'
 */
#endif                                 /* RTW_HEADER_modified_motor_h_ */
