/*
 * new_analog_loopback_q4_p4_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "new_analog_loopback_q4_p4_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "new_analog_loopback_q4_p4.h"
#include "new_analog_loopback_q4_p4_capi.h"
#include "new_analog_loopback_q4_p4_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Q4 Enc "),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 1, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 2, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 3, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 4, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 5, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 6, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 7, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 8, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 9, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 10, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 11, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 12, TARGET_STRING("Q4 Enc "),
    TARGET_STRING("P12"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &new_analog_loopback_q4_p4_B.Q4Enc,  /* 0: Signal */
  &new_analog_loopback_q4_p4_P.Q4Enc_P1,/* 1: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P2,/* 2: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P3,/* 3: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P4,/* 4: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P5,/* 5: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P6,/* 6: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P7,/* 7: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P8,/* 8: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P9,/* 9: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P10,/* 10: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P11,/* 11: Block Parameter */
  &new_analog_loopback_q4_p4_P.Q4Enc_P12,/* 12: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 1,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 12,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 416287855U,
    4037666066U,
    2740329339U,
    507448839U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  new_analog_loopback_q4_p4_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void new_analog_loopback_q4_p4_InitializeDataMapInfo
  (RT_MODEL_new_analog_loopback_q4_p4_T *const new_analog_loopback_q4_p4_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(new_analog_loopback_q4_p4_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(new_analog_loopback_q4_p4_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(new_analog_loopback_q4_p4_M->DataMapInfo.mmi,
    (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(new_analog_loopback_q4_p4_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(new_analog_loopback_q4_p4_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  new_analog_loopback_q4_p4_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(new_analog_loopback_q4_p4_M);
  new_analog_loopback_q4_p4_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_new_analog_loopback_q4_p4_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(new_analog_loopback_q4_p4_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(new_analog_loopback_q4_p4_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(new_analog_loopback_q4_p4_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void new_analog_loopback_q4_p4_host_InitializeDataMapInfo
    (new_analog_loopback_q4_p4_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: new_analog_loopback_q4_p4_capi.c */
