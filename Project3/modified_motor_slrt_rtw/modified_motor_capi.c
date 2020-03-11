/*
 * modified_motor_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "modified_motor".
 *
 * Model version              : 1.135
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 11 01:12:51 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "modified_motor_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "modified_motor.h"
#include "modified_motor_capi.h"
#include "modified_motor_private.h"
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
  { 0, 1, TARGET_STRING("Image Deconstructor/Fire Webcam"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 2, TARGET_STRING("Image Deconstructor/Process Image"),
    TARGET_STRING("image_data_sig"), 0, 0, 1, 0, 0 },

  { 2, 0, TARGET_STRING("Image Deconstructor/Read Image"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 3, TARGET_STRING("Logic Block/Generate Angles List"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 4, 0, TARGET_STRING("Logic Block/Fcn"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("Logic Block/Rate Transition"),
    TARGET_STRING("target_pos"), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("Logic Block/Selector"),
    TARGET_STRING("x"), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("Logic Block/Selector1"),
    TARGET_STRING("y"), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("UI Input/Data Type Conversion"),
    TARGET_STRING("id_val"), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("UI Input/Data Type Conversion1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("UI Input/Data Type Conversion2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("motor_subsystem/Derivative"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 12, 0, TARGET_STRING("motor_subsystem/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING("motor_subsystem/KI"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 14, 0, TARGET_STRING("motor_subsystem/Kd"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 15, 0, TARGET_STRING("motor_subsystem/Kp"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 16, 0, TARGET_STRING("motor_subsystem/Integrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 17, 0, TARGET_STRING("motor_subsystem/Saturation"),
    TARGET_STRING("Voltage_Input"), 0, 0, 0, 0, 2 },

  { 18, 0, TARGET_STRING("motor_subsystem/Sum"),
    TARGET_STRING("Sig1"), 0, 0, 0, 0, 2 },

  { 19, 0, TARGET_STRING("motor_subsystem/Sum1"),
    TARGET_STRING("Pos_Input"), 0, 0, 0, 0, 2 },

  { 20, 0, TARGET_STRING("Image Deconstructor/Clock/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("Image Deconstructor/Clock/Unit Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("Logic Block/Clock/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("Logic Block/Clock/Unit Delay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 4, TARGET_STRING("Logic Block/Position Iterator/Iterator/p1"),
    TARGET_STRING("target_pos"), 0, 0, 0, 0, 3 },

  { 25, 4, TARGET_STRING("Logic Block/Position Iterator/Iterator/p2"),
    TARGET_STRING("iter_next_index"), 1, 0, 0, 0, 3 },

  { 26, 5, TARGET_STRING("Logic Block/Position Iterator/Data Store Read"),
    TARGET_STRING("iter_cur_index"), 0, 0, 0, 0, 3 },

  { 27, 0, TARGET_STRING("motor_subsystem/Motor Selector/Add"),
    TARGET_STRING("Switch Position"), 0, 0, 0, 0, 1 },

  { 28, 0, TARGET_STRING("motor_subsystem/Motor Selector/Gate1"),
    TARGET_STRING("Simulated Motor"), 0, 0, 0, 0, 2 },

  { 29, 0, TARGET_STRING("motor_subsystem/Motor Selector/Gate2"),
    TARGET_STRING("Real Motor"), 0, 0, 0, 0, 2 },

  { 30, 7, TARGET_STRING("motor_subsystem/Real motor/Convert to Rad"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 31, 0, TARGET_STRING("motor_subsystem/Real motor/Invert Sign"),
    TARGET_STRING("Position (rad)"), 0, 0, 0, 0, 1 },

  { 32, 0, TARGET_STRING("motor_subsystem/Real motor/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 33, 0, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("Position (steps)"), 0, 0, 0, 0, 1 },

  { 34, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Damping"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 35, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Inductance"),
    TARGET_STRING("d/dt(i)"), 0, 0, 0, 0, 2 },

  { 36, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Inertia "),
    TARGET_STRING("d2/dt2(theta)"), 0, 0, 0, 0, 2 },

  { 37, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Ke"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 38, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Kt"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 39, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Resistance"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 40, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator"),
    TARGET_STRING("i"), 0, 0, 0, 0, 2 },

  { 41, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator1"),
    TARGET_STRING("d/dt(theta)"), 0, 0, 0, 0, 2 },

  { 42, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator2"),
    TARGET_STRING("theta"), 0, 0, 0, 0, 2 },

  { 43, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Add"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 44, 0, TARGET_STRING("motor_subsystem/Simulated Motor/Add1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  { 45, 0, TARGET_STRING("motor_subsystem/Switching Logic/Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 2 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 46, TARGET_STRING("Run"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 47, TARGET_STRING("Switch"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 48, TARGET_STRING("Image Deconstructor/Store Image Data"),
    TARGET_STRING("InitialValue"), 0, 0, 0 },

  { 49, TARGET_STRING("Logic Block/Rate Transition"),
    TARGET_STRING("X0"), 0, 0, 0 },

  { 50, TARGET_STRING("UI Input/Color"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 51, TARGET_STRING("UI Input/ID"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 52, TARGET_STRING("UI Input/Mode "),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 53, TARGET_STRING("motor_subsystem/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 54, TARGET_STRING("motor_subsystem/KI"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 55, TARGET_STRING("motor_subsystem/Kd"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 56, TARGET_STRING("motor_subsystem/Kp"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 57, TARGET_STRING("motor_subsystem/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 58, TARGET_STRING("motor_subsystem/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 59, TARGET_STRING("motor_subsystem/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 60, TARGET_STRING("Image Deconstructor/Clock/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 61, TARGET_STRING("Image Deconstructor/Clock/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 62, TARGET_STRING("Logic Block/Clock/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 63, TARGET_STRING("Logic Block/Clock/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 64, TARGET_STRING("Logic Block/Position Iterator/Target_Position"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 65, TARGET_STRING("Logic Block/Position Iterator/Store_Index"),
    TARGET_STRING("InitialValue"), 0, 0, 0 },

  { 66, TARGET_STRING("motor_subsystem/Motor Selector/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 67, TARGET_STRING("motor_subsystem/Motor Selector/Gate1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 68, TARGET_STRING("motor_subsystem/Motor Selector/Gate2"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 69, TARGET_STRING("motor_subsystem/Real motor/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 70, TARGET_STRING("motor_subsystem/Real motor/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 71, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 72, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 73, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 74, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 75, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 76, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 77, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 78, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 79, TARGET_STRING("motor_subsystem/Real motor/Q4 DA "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 80, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 81, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 82, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 83, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 84, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 85, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 86, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 87, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 88, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 89, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 90, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 91, TARGET_STRING("motor_subsystem/Real motor/Q4 Enc "),
    TARGET_STRING("P12"), 0, 0, 0 },

  { 92, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 93, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 94, TARGET_STRING("motor_subsystem/Simulated Motor/Integrator2"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 95, TARGET_STRING("motor_subsystem/Switching Logic/Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 96, TARGET_STRING("J"), 0, 0, 0 },

  { 97, TARGET_STRING("Ke"), 0, 0, 0 },

  { 98, TARGET_STRING("Kt"), 0, 0, 0 },

  { 99, TARGET_STRING("L"), 0, 0, 0 },

  { 100, TARGET_STRING("R"), 0, 0, 0 },

  { 101, TARGET_STRING("b"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &modified_motor_B.image,             /* 0: Signal */
  &modified_motor_B.image_data[0],     /* 1: Signal */
  &modified_motor_B.ReadImage,         /* 2: Signal */
  &modified_motor_B.angles_vector[0],  /* 3: Signal */
  &modified_motor_B.Fcn,               /* 4: Signal */
  &modified_motor_B.target_pos,        /* 5: Signal */
  &modified_motor_B.x,                 /* 6: Signal */
  &modified_motor_B.y,                 /* 7: Signal */
  &modified_motor_B.id_val,            /* 8: Signal */
  &modified_motor_B.DataTypeConversion1,/* 9: Signal */
  &modified_motor_B.DataTypeConversion2,/* 10: Signal */
  &modified_motor_B.Derivative,        /* 11: Signal */
  &modified_motor_B.Gain,              /* 12: Signal */
  &modified_motor_B.KI,                /* 13: Signal */
  &modified_motor_B.Kd,                /* 14: Signal */
  &modified_motor_B.Kp,                /* 15: Signal */
  &modified_motor_B.Integrator,        /* 16: Signal */
  &modified_motor_B.Voltage_Input,     /* 17: Signal */
  &modified_motor_B.Sig1,              /* 18: Signal */
  &modified_motor_B.Pos_Input,         /* 19: Signal */
  &modified_motor_B.Sum,               /* 20: Signal */
  &modified_motor_B.UnitDelay,         /* 21: Signal */
  &modified_motor_B.Sum_m,             /* 22: Signal */
  &modified_motor_B.UnitDelay_i,       /* 23: Signal */
  &modified_motor_B.target_pos_o,      /* 24: Signal */
  &modified_motor_B.next_index,        /* 25: Signal */
  &modified_motor_B.iter_cur_index,    /* 26: Signal */
  &modified_motor_B.SwitchPosition,    /* 27: Signal */
  &modified_motor_B.SimulatedMotor,    /* 28: Signal */
  &modified_motor_B.RealMotor,         /* 29: Signal */
  &modified_motor_B.y_f,               /* 30: Signal */
  &modified_motor_B.Positionrad,       /* 31: Signal */
  &modified_motor_B.Saturation,        /* 32: Signal */
  &modified_motor_B.Positionsteps,     /* 33: Signal */
  &modified_motor_B.Damping,           /* 34: Signal */
  &modified_motor_B.ddti,              /* 35: Signal */
  &modified_motor_B.d2dt2theta,        /* 36: Signal */
  &modified_motor_B.Ke,                /* 37: Signal */
  &modified_motor_B.Kt,                /* 38: Signal */
  &modified_motor_B.Resistance,        /* 39: Signal */
  &modified_motor_B.i,                 /* 40: Signal */
  &modified_motor_B.ddttheta,          /* 41: Signal */
  &modified_motor_B.theta,             /* 42: Signal */
  &modified_motor_B.Add,               /* 43: Signal */
  &modified_motor_B.Add1,              /* 44: Signal */
  &modified_motor_B.Switch1,           /* 45: Signal */
  &modified_motor_P.Run_Value,         /* 46: Block Parameter */
  &modified_motor_P.Switch_Value,      /* 47: Block Parameter */
  &modified_motor_P.StoreImageData_InitialValue,/* 48: Block Parameter */
  &modified_motor_P.RateTransition_X0, /* 49: Block Parameter */
  &modified_motor_P.Color_Value,       /* 50: Block Parameter */
  &modified_motor_P.ID_Value,          /* 51: Block Parameter */
  &modified_motor_P.Mode_Value,        /* 52: Block Parameter */
  &modified_motor_P.Gain_Gain,         /* 53: Block Parameter */
  &modified_motor_P.KI_Gain,           /* 54: Block Parameter */
  &modified_motor_P.Kd_Gain,           /* 55: Block Parameter */
  &modified_motor_P.Kp_Gain,           /* 56: Block Parameter */
  &modified_motor_P.Integrator_IC,     /* 57: Block Parameter */
  &modified_motor_P.Saturation_UpperSat,/* 58: Block Parameter */
  &modified_motor_P.Saturation_LowerSat,/* 59: Block Parameter */
  &modified_motor_P.Constant_Value,    /* 60: Block Parameter */
  &modified_motor_P.UnitDelay_InitialCondition,/* 61: Block Parameter */
  &modified_motor_P.Constant_Value_b,  /* 62: Block Parameter */
  &modified_motor_P.UnitDelay_InitialCondition_b,/* 63: Block Parameter */
  &modified_motor_P.Target_Position_Y0,/* 64: Block Parameter */
  &modified_motor_P.Store_Index_InitialValue,/* 65: Block Parameter */
  &modified_motor_P.Constant_Value_c,  /* 66: Block Parameter */
  &modified_motor_P.Gate1_Threshold,   /* 67: Block Parameter */
  &modified_motor_P.Gate2_Threshold,   /* 68: Block Parameter */
  &modified_motor_P.Saturation_UpperSat_a,/* 69: Block Parameter */
  &modified_motor_P.Saturation_LowerSat_d,/* 70: Block Parameter */
  &modified_motor_P.Q4DA_P1,           /* 71: Block Parameter */
  &modified_motor_P.Q4DA_P2,           /* 72: Block Parameter */
  &modified_motor_P.Q4DA_P3,           /* 73: Block Parameter */
  &modified_motor_P.Q4DA_P4,           /* 74: Block Parameter */
  &modified_motor_P.Q4DA_P5,           /* 75: Block Parameter */
  &modified_motor_P.Q4DA_P6,           /* 76: Block Parameter */
  &modified_motor_P.Q4DA_P7,           /* 77: Block Parameter */
  &modified_motor_P.Q4DA_P8,           /* 78: Block Parameter */
  &modified_motor_P.Q4DA_P9,           /* 79: Block Parameter */
  &modified_motor_P.Q4Enc_P1,          /* 80: Block Parameter */
  &modified_motor_P.Q4Enc_P2,          /* 81: Block Parameter */
  &modified_motor_P.Q4Enc_P3,          /* 82: Block Parameter */
  &modified_motor_P.Q4Enc_P4,          /* 83: Block Parameter */
  &modified_motor_P.Q4Enc_P5,          /* 84: Block Parameter */
  &modified_motor_P.Q4Enc_P6,          /* 85: Block Parameter */
  &modified_motor_P.Q4Enc_P7,          /* 86: Block Parameter */
  &modified_motor_P.Q4Enc_P8,          /* 87: Block Parameter */
  &modified_motor_P.Q4Enc_P9,          /* 88: Block Parameter */
  &modified_motor_P.Q4Enc_P10,         /* 89: Block Parameter */
  &modified_motor_P.Q4Enc_P11,         /* 90: Block Parameter */
  &modified_motor_P.Q4Enc_P12,         /* 91: Block Parameter */
  &modified_motor_P.Integrator_IC_a,   /* 92: Block Parameter */
  &modified_motor_P.Integrator1_IC,    /* 93: Block Parameter */
  &modified_motor_P.Integrator2_IC,    /* 94: Block Parameter */
  &modified_motor_P.Switch1_Threshold, /* 95: Block Parameter */
  &modified_motor_P.J,                 /* 96: Model Parameter */
  &modified_motor_P.Ke,                /* 97: Model Parameter */
  &modified_motor_P.Kt,                /* 98: Model Parameter */
  &modified_motor_P.L,                 /* 99: Model Parameter */
  &modified_motor_P.R,                 /* 100: Model Parameter */
  &modified_motor_P.b,                 /* 101: Model Parameter */
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

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
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
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  100,                                 /* 2 */
  4,                                   /* 3 */
  100,                                 /* 4 */
  1                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  1.0, 0.0, 0.001
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
    2, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (NULL), (NULL), -1, 0 }
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
  { rtBlockSignals, 46,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 50,
    rtModelParameters, 6 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1881450807U,
    3727993589U,
    2577957431U,
    3148472767U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  modified_motor_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void modified_motor_InitializeDataMapInfo(RT_MODEL_modified_motor_T *const
  modified_motor_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(modified_motor_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(modified_motor_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(modified_motor_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(modified_motor_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(modified_motor_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  modified_motor_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (modified_motor_M);
  modified_motor_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_modified_motor_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(modified_motor_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(modified_motor_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(modified_motor_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void modified_motor_host_InitializeDataMapInfo
    (modified_motor_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: modified_motor_capi.c */
