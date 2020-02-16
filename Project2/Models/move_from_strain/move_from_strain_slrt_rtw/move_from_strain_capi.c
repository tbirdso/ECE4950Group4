/*
 * move_from_strain_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "move_from_strain".
 *
 * Model version              : 1.55
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Feb 16 16:29:48 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "move_from_strain_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "move_from_strain.h"
#include "move_from_strain_capi.h"
#include "move_from_strain_private.h"
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
  { 0, 1, TARGET_STRING("PW Mapping"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Q4 AD"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("Programmable Pulse Generator/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 3, 0, TARGET_STRING("Programmable Pulse Generator/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 4, 0, TARGET_STRING("Programmable Pulse Generator/mod"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("Programmable Pulse Generator/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("Programmable Pulse Generator/Product1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("Programmable Pulse Generator/Relational Operator"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 8, 0, TARGET_STRING("Programmable Pulse Generator/Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("Programmable Pulse Generator/Phase Delay Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 10, TARGET_STRING("Amplitude"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 11, TARGET_STRING("PD"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 12, TARGET_STRING("Period"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 13, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 14, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 15, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 16, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 17, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 18, TARGET_STRING("Q4 AD"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 19, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 20, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 21, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 22, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 23, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 24, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 25, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 26, TARGET_STRING("Q4 DO "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 27, TARGET_STRING("Programmable Pulse Generator/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 28, TARGET_STRING("Programmable Pulse Generator/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 29, TARGET_STRING("Programmable Pulse Generator/Phase Delay Switch"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

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
  &move_from_strain_B.y,               /* 0: Signal */
  &move_from_strain_B.Q4AD,            /* 1: Signal */
  &move_from_strain_B.Clock,           /* 2: Signal */
  &move_from_strain_B.DataTypeConversion,/* 3: Signal */
  &move_from_strain_B.mod,             /* 4: Signal */
  &move_from_strain_B.Product,         /* 5: Signal */
  &move_from_strain_B.Product1,        /* 6: Signal */
  &move_from_strain_B.RelationalOperator,/* 7: Signal */
  &move_from_strain_B.Sum2,            /* 8: Signal */
  &move_from_strain_B.PhaseDelaySwitch,/* 9: Signal */
  &move_from_strain_P.Amplitude_Value, /* 10: Block Parameter */
  &move_from_strain_P.PD_Value,        /* 11: Block Parameter */
  &move_from_strain_P.Period_Value,    /* 12: Block Parameter */
  &move_from_strain_P.Q4AD_P1,         /* 13: Block Parameter */
  &move_from_strain_P.Q4AD_P2,         /* 14: Block Parameter */
  &move_from_strain_P.Q4AD_P3,         /* 15: Block Parameter */
  &move_from_strain_P.Q4AD_P5,         /* 16: Block Parameter */
  &move_from_strain_P.Q4AD_P6,         /* 17: Block Parameter */
  &move_from_strain_P.Q4AD_P7,         /* 18: Block Parameter */
  &move_from_strain_P.Q4DO_P1,         /* 19: Block Parameter */
  &move_from_strain_P.Q4DO_P2,         /* 20: Block Parameter */
  &move_from_strain_P.Q4DO_P3,         /* 21: Block Parameter */
  &move_from_strain_P.Q4DO_P4,         /* 22: Block Parameter */
  &move_from_strain_P.Q4DO_P5,         /* 23: Block Parameter */
  &move_from_strain_P.Q4DO_P6,         /* 24: Block Parameter */
  &move_from_strain_P.Q4DO_P7,         /* 25: Block Parameter */
  &move_from_strain_P.Q4DO_P8,         /* 26: Block Parameter */
  &move_from_strain_P.Constant_Value,  /* 27: Block Parameter */
  &move_from_strain_P.Constant1_Value, /* 28: Block Parameter */
  &move_from_strain_P.PhaseDelaySwitch_Threshold,/* 29: Block Parameter */
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
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
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
  0.0002, 0.0
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
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
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
  { rtBlockSignals, 10,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 20,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3017202078U,
    128167539U,
    2034224790U,
    3422675696U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  move_from_strain_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void move_from_strain_InitializeDataMapInfo(RT_MODEL_move_from_strain_T *const
  move_from_strain_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(move_from_strain_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(move_from_strain_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(move_from_strain_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(move_from_strain_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(move_from_strain_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  move_from_strain_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(move_from_strain_M);
  move_from_strain_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_move_from_strain_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(move_from_strain_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(move_from_strain_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(move_from_strain_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void move_from_strain_host_InitializeDataMapInfo
    (move_from_strain_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: move_from_strain_capi.c */
