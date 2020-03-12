/*
 * modified_motor.c
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

/* Previous zero-crossings (trigger) states */
PrevZCX_modified_motor_T modified_motor_PrevZCX;

/* Real-time model */
RT_MODEL_modified_motor_T modified_motor_M_;
RT_MODEL_modified_motor_T *const modified_motor_M = &modified_motor_M_;

/* Forward declaration for local functions */
static void modified_motor_merge(int32_T idx_data[], real_T x_data[], int32_T
  offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
static void modified_motor_merge_block(int32_T idx_data[], real_T x_data[],
  int32_T n, int32_T iwork_data[], real_T xwork_data[]);
static void modified_motor_sortIdx(real_T x_data[], int32_T *x_size, int32_T
  idx_data[], int32_T *idx_size);
static void modified_motor_sort(real_T x_data[], int32_T *x_size);
static void modified_motor_rect_to_polar_v2(const real_T center_coords_data[],
  const int32_T center_coords_size[2], real_T Angles_sorted_data[], int32_T
  *Angles_sorted_size);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(modified_motor_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(modified_motor_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (modified_motor_M->Timing.TaskCounters.TID[1] == 0) {
    modified_motor_M->Timing.RateInteraction.TID1_2 =
      (modified_motor_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    modified_motor_M->Timing.perTaskSampleHits[5] =
      modified_motor_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (modified_motor_M->Timing.TaskCounters.TID[2])++;
  if ((modified_motor_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [1.0s, 0.0s] */
    modified_motor_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  modified_motor_output0();
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
  modified_motor_output0();
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

/* Function for MATLAB Function: '<S2>/Generate Angles List' */
static void modified_motor_merge(int32_T idx_data[], real_T x_data[], int32_T
  offset, int32_T np, int32_T nq, int32_T iwork_data[], real_T xwork_data[])
{
  int32_T n;
  int32_T q;
  int32_T qend;
  int32_T iout;
  int32_T exitg1;
  if (nq != 0) {
    n = np + nq;
    for (q = 0; q + 1 <= n; q++) {
      iwork_data[q] = idx_data[offset + q];
      xwork_data[q] = x_data[offset + q];
    }

    n = 0;
    q = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[n] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[n];
        x_data[iout] = xwork_data[n];
        if (n + 1 < np) {
          n++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < qend) {
          q++;
        } else {
          q = (iout - n) + 1;
          while (n + 1 <= np) {
            idx_data[q + n] = iwork_data[n];
            x_data[q + n] = xwork_data[n];
            n++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<S2>/Generate Angles List' */
static void modified_motor_merge_block(int32_T idx_data[], real_T x_data[],
  int32_T n, int32_T iwork_data[], real_T xwork_data[])
{
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  int32_T nPairs;
  nPairs = n >> 2;
  bLen = 4;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        modified_motor_merge(idx_data, x_data, tailOffset, bLen, nTail - bLen,
                             iwork_data, xwork_data);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      modified_motor_merge(idx_data, x_data, (nTail - 1) * tailOffset, bLen,
                           bLen, iwork_data, xwork_data);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    modified_motor_merge(idx_data, x_data, 0, bLen, n - bLen, iwork_data,
                         xwork_data);
  }
}

/* Function for MATLAB Function: '<S2>/Generate Angles List' */
static void modified_motor_sortIdx(real_T x_data[], int32_T *x_size, int32_T
  idx_data[], int32_T *idx_size)
{
  real_T b_x_data[100];
  int32_T nNaNs;
  int32_T iwork_data[100];
  real_T xwork_data[100];
  int32_T n;
  real_T x4[4];
  int8_T idx4[4];
  int32_T ib;
  int32_T wOffset;
  int32_T itmp;
  int8_T perm[4];
  int32_T i1;
  int32_T i3;
  int32_T i4;
  int32_T b_x_size;
  int32_T iwork_size;
  int32_T xwork_size;
  int8_T b_idx_0;
  b_idx_0 = (int8_T)*x_size;
  b_x_size = *x_size;
  n = *x_size;
  for (nNaNs = 0; nNaNs < n; nNaNs++) {
    b_x_data[nNaNs] = x_data[nNaNs];
  }

  *idx_size = b_idx_0;
  n = b_idx_0;
  for (nNaNs = 0; nNaNs < n; nNaNs++) {
    idx_data[nNaNs] = 0;
  }

  n = *x_size;
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  iwork_size = b_idx_0;
  ib = iwork_size;
  for (nNaNs = 0; nNaNs < ib; nNaNs++) {
    iwork_data[nNaNs] = 0;
  }

  b_idx_0 = (int8_T)*x_size;
  xwork_size = b_idx_0;
  ib = xwork_size;
  for (nNaNs = 0; nNaNs < ib; nNaNs++) {
    xwork_data[nNaNs] = 0.0;
  }

  nNaNs = 1;
  ib = 0;
  for (wOffset = 0; wOffset + 1 <= n; wOffset++) {
    if (rtIsNaN(b_x_data[wOffset])) {
      idx_data[n - nNaNs] = wOffset + 1;
      xwork_data[n - nNaNs] = b_x_data[wOffset];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (int8_T)(wOffset + 1);
      x4[ib - 1] = b_x_data[wOffset];
      if (ib == 4) {
        ib = wOffset - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          itmp = 2;
        } else {
          i1 = 2;
          itmp = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[i1 - 1] <= x4[i3 - 1]) {
          if (x4[itmp - 1] <= x4[i3 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)itmp;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (x4[itmp - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)itmp;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)itmp;
          }
        } else if (x4[i1 - 1] <= x4[i4 - 1]) {
          if (x4[itmp - 1] <= x4[i4 - 1]) {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i1;
            perm[2] = (int8_T)itmp;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i1;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)itmp;
          }
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)i1;
          perm[3] = (int8_T)itmp;
        }

        idx_data[ib - 2] = idx4[perm[0] - 1];
        idx_data[ib - 1] = idx4[perm[1] - 1];
        idx_data[ib] = idx4[perm[2] - 1];
        idx_data[ib + 1] = idx4[perm[3] - 1];
        b_x_data[ib - 2] = x4[perm[0] - 1];
        b_x_data[ib - 1] = x4[perm[1] - 1];
        b_x_data[ib] = x4[perm[2] - 1];
        b_x_data[ib + 1] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = *x_size - nNaNs;
  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (i1 = 1; i1 <= ib; i1++) {
      idx_data[(wOffset - ib) + i1] = idx4[perm[i1 - 1] - 1];
      b_x_data[(wOffset - ib) + i1] = x4[perm[i1 - 1] - 1];
    }
  }

  ib = ((nNaNs - 1) >> 1) + 1;
  for (i1 = 1; i1 < ib; i1++) {
    itmp = idx_data[wOffset + i1];
    idx_data[wOffset + i1] = idx_data[n - i1];
    idx_data[n - i1] = itmp;
    b_x_data[wOffset + i1] = xwork_data[n - i1];
    b_x_data[n - i1] = xwork_data[wOffset + i1];
  }

  if (((nNaNs - 1) & 1) != 0) {
    b_x_data[wOffset + ib] = xwork_data[wOffset + ib];
  }

  n = (*x_size - nNaNs) + 1;
  if (n > 1) {
    modified_motor_merge_block(idx_data, b_x_data, n, iwork_data, xwork_data);
  }

  *x_size = b_x_size;
  n = b_x_size;
  for (nNaNs = 0; nNaNs < n; nNaNs++) {
    x_data[nNaNs] = b_x_data[nNaNs];
  }
}

/* Function for MATLAB Function: '<S2>/Generate Angles List' */
static void modified_motor_sort(real_T x_data[], int32_T *x_size)
{
  real_T vwork_data[100];
  int32_T vstride;
  int32_T dim;
  int32_T b;
  int32_T c_k;
  int32_T vwork_size;
  emxArray_int32_T_100_modified_T vwork_data_0;
  dim = 2;
  if (*x_size != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    b = *x_size;
  } else {
    b = 1;
  }

  vwork_size = (int8_T)b;
  vstride = 1;
  c_k = 1;
  while (c_k <= dim - 1) {
    vstride *= *x_size;
    c_k = 2;
  }

  for (dim = 0; dim + 1 <= vstride; dim++) {
    for (c_k = 0; c_k + 1 <= b; c_k++) {
      vwork_data[c_k] = x_data[c_k * vstride + dim];
    }

    modified_motor_sortIdx(vwork_data, &vwork_size, vwork_data_0.data,
      &vwork_data_0.size);
    for (c_k = 0; c_k + 1 <= b; c_k++) {
      x_data[dim + c_k * vstride] = vwork_data[c_k];
    }
  }
}

/* Function for MATLAB Function: '<S2>/Generate Angles List' */
static void modified_motor_rect_to_polar_v2(const real_T center_coords_data[],
  const int32_T center_coords_size[2], real_T Angles_sorted_data[], int32_T
  *Angles_sorted_size)
{
  int32_T i;

  /*  PURPOSE - Convert rectangular object coordinates to angle for */
  /*            motor position */
  /*  INPUTS */
  /*    - X, Y coordinates == center coords of each object */
  /*  OUTPUTS */
  /*    - Vector of angles (radians) ordered ascending */
  /*  NOTES */
  /*    - Theta == 0 is at the bottom of the map */
  /*    - Positive angles are in RH plane */
  /*    - Negative angles are in LH plane */
  /*    - Camera origin (0,0) is at NW corner */
  /*    - Game board origin is at image center */
  /*  Update these to actual frame dimensions */
  /*  Get the game board center (Approx. Motor Location)  */
  /*  so we can calculate relative angles */
  *Angles_sorted_size = center_coords_size[0];
  for (i = 0; i < center_coords_size[0]; i++) {
    Angles_sorted_data[i] = atan((center_coords_data[i + center_coords_size[0]]
      - 296.5) / (center_coords_data[i] - 413.0));

    /*  Quandrant dependent angle math */
    if ((center_coords_data[i] - 413.0 > 0.0) && (center_coords_data[i +
         center_coords_size[0]] - 296.5 < 0.0)) {
      Angles_sorted_data[i] = -Angles_sorted_data[i];
    } else if ((center_coords_data[i] - 413.0 < 0.0) && (center_coords_data[i +
                center_coords_size[0]] - 296.5 < 0.0)) {
      Angles_sorted_data[i] = 3.1415926535897931 - Angles_sorted_data[i];
    } else if ((center_coords_data[i] - 413.0 < 0.0) && (center_coords_data[i +
                center_coords_size[0]] - 296.5 > 0.0)) {
      Angles_sorted_data[i] = 3.1415926535897931 + -Angles_sorted_data[i];
    } else {
      /*  may need to fix this, this is 4th quadrant */
    }
  }

  modified_motor_sort(Angles_sorted_data, Angles_sorted_size);
}

/* Model output function for TID0 */
void modified_motor_output0(void)      /* Sample time: [0.0s, 0.0s] */
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

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modified_motor_M)) {
    modified_motor_M->Timing.t[0] = rtsiGetT(&modified_motor_M->solverInfo);
  }

  /* RateTransition: '<S2>/Rate Transition' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    if (modified_motor_M->Timing.RateInteraction.TID1_2) {
      modified_motor_B.target_pos = modified_motor_DW.RateTransition_Buffer0;
    }

    /* Gain: '<S4>/Gain' */
    modified_motor_B.Gain = modified_motor_P.Gain_Gain *
      modified_motor_B.target_pos;
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* Integrator: '<S17>/Integrator2' */
  modified_motor_B.theta = modified_motor_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (encquanserq8): '<S14>/Q4 Enc ' */

    /* Level2 S-Function Block: '<S14>/Q4 Enc ' (encquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* MATLAB Function: '<S14>/Convert to Rad' */
    /* MATLAB Function 'motor_subsystem/Real motor/Convert to Rad': '<S19>:1' */
    /*  Observed experimentally */
    /* '<S19>:1:6' */
    /* '<S19>:1:8' */
    modified_motor_B.y_f = modified_motor_B.Positionsteps * 2.0 *
      3.1415926535897931 / 400.0 - 3.1415926535897931;

    /* Fcn: '<S14>/Invert Sign' */
    modified_motor_B.Positionrad = -modified_motor_B.y_f;
  }

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<Root>/Switch'
   */
  if (modified_motor_P.Switch_Value > modified_motor_P.Switch1_Threshold) {
    modified_motor_B.Switch1 = modified_motor_B.theta;
  } else {
    modified_motor_B.Switch1 = modified_motor_B.Positionrad;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* Sum: '<S4>/Sum' */
  modified_motor_B.Sig1 = modified_motor_B.Gain - modified_motor_B.Switch1;

  /* Gain: '<S4>/Kp' */
  modified_motor_B.Kp = modified_motor_P.Kp_Gain * modified_motor_B.Sig1;

  /* Derivative: '<S4>/Derivative' */
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

  /* End of Derivative: '<S4>/Derivative' */

  /* Gain: '<S4>/Kd' */
  modified_motor_B.Kd = modified_motor_P.Kd_Gain * modified_motor_B.Derivative;

  /* Integrator: '<S4>/Integrator' */
  modified_motor_B.Integrator = modified_motor_X.Integrator_CSTATE;

  /* Gain: '<S4>/KI' */
  modified_motor_B.KI = modified_motor_P.KI_Gain * modified_motor_B.Integrator;

  /* Sum: '<S4>/Sum1' */
  modified_motor_B.Pos_Input = (modified_motor_B.Kp + modified_motor_B.Kd) +
    modified_motor_B.KI;

  /* Saturate: '<S4>/Saturation' */
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

  /* End of Saturate: '<S4>/Saturation' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
  }

  /* S-Function (scblock): '<S15>/S-Function' */
  /* ok to acquire for <S15>/S-Function */
  modified_motor_DW.SFunction_IWORK.AcquireOK = 1;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (scblock): '<S16>/S-Function' */
    /* ok to acquire for <S16>/S-Function */
    modified_motor_DW.SFunction_IWORK_m.AcquireOK = 1;

    /* Sum: '<S13>/Add' incorporates:
     *  Constant: '<Root>/Switch'
     *  Constant: '<S13>/Constant'
     */
    modified_motor_B.SwitchPosition = modified_motor_P.Constant_Value_c -
      modified_motor_P.Switch_Value;
  }

  /* Switch: '<S13>/Gate1' incorporates:
   *  Constant: '<Root>/Switch'
   */
  if (modified_motor_P.Switch_Value > modified_motor_P.Gate1_Threshold) {
    modified_motor_B.SimulatedMotor = modified_motor_B.Voltage_Input;
  } else {
    modified_motor_B.SimulatedMotor = 0.0;
  }

  /* End of Switch: '<S13>/Gate1' */

  /* Switch: '<S13>/Gate2' */
  if (modified_motor_B.SwitchPosition > modified_motor_P.Gate2_Threshold) {
    modified_motor_B.RealMotor = modified_motor_B.Voltage_Input;
  } else {
    modified_motor_B.RealMotor = 0.0;
  }

  /* End of Switch: '<S13>/Gate2' */

  /* Saturate: '<S14>/Saturation' */
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

  /* End of Saturate: '<S14>/Saturation' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* S-Function (daquanserq8): '<S14>/Q4 DA ' */

    /* Level2 S-Function Block: '<S14>/Q4 DA ' (daquanserq8) */
    {
      SimStruct *rts = modified_motor_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }
  }

  /* Integrator: '<S17>/Integrator' */
  modified_motor_B.i = modified_motor_X.Integrator_CSTATE_g;

  /* Gain: '<S17>/Resistance' */
  modified_motor_B.Resistance = modified_motor_P.R * modified_motor_B.i;

  /* Integrator: '<S17>/Integrator1' */
  modified_motor_B.ddttheta = modified_motor_X.Integrator1_CSTATE;

  /* Gain: '<S17>/Ke' */
  modified_motor_B.Ke = modified_motor_P.Ke * modified_motor_B.ddttheta;

  /* Sum: '<S17>/Add' */
  modified_motor_B.Add = (modified_motor_B.SimulatedMotor -
    modified_motor_B.Resistance) - modified_motor_B.Ke;

  /* Gain: '<S17>/Kt' */
  modified_motor_B.Kt = modified_motor_P.Kt * modified_motor_B.i;

  /* Gain: '<S17>/Damping' */
  modified_motor_B.Damping = modified_motor_P.b * modified_motor_B.ddttheta;

  /* Sum: '<S17>/Add1' */
  modified_motor_B.Add1 = modified_motor_B.Kt - modified_motor_B.Damping;

  /* Gain: '<S17>/Inductance' */
  lastTime = modified_motor_P.L;
  lastTime = 1.0 / lastTime;
  modified_motor_B.ddti = lastTime * modified_motor_B.Add;

  /* Gain: '<S17>/Inertia ' */
  lastTime = modified_motor_P.J;
  lastTime = 1.0 / lastTime;
  modified_motor_B.d2dt2theta = lastTime * modified_motor_B.Add1;
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    /* Constant: '<S3>/Mode' */
    modified_motor_B.Modescanseek_colorseek_pos = modified_motor_P.Mode_Value;

    /* DataTypeConversion: '<S3>/Data Type Conversion2' */
    modified_motor_B.DataTypeConversion2 =
      modified_motor_B.Modescanseek_colorseek_pos;

    /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport1' */
    if (!(modified_motor_DW.TmpRTBAtGenerateAnglesListInp_d != 0)) {
      modified_motor_DW.TmpRTBAtGenerateAnglesListInpor =
        modified_motor_B.DataTypeConversion2;
    }

    /* End of RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport1' */

    /* Constant: '<S3>/Color' */
    modified_motor_B.color_enum = modified_motor_P.Color_Value;

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    modified_motor_B.DataTypeConversion1 = modified_motor_B.color_enum;

    /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport2' */
    if (!(modified_motor_DW.TmpRTBAtGenerateAnglesListInp_i != 0)) {
      modified_motor_DW.TmpRTBAtGenerateAnglesListInp_f =
        modified_motor_B.DataTypeConversion1;
    }

    /* End of RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport2' */

    /* Constant: '<S3>/Position' */
    modified_motor_B.pos_val = modified_motor_P.Position_Value;

    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    modified_motor_B.DataTypeConversion = modified_motor_B.pos_val;

    /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport3' */
    if (!(modified_motor_DW.TmpRTBAtGenerateAnglesListInp_c != 0)) {
      modified_motor_DW.TmpRTBAtGenerateAnglesListInp_o =
        modified_motor_B.DataTypeConversion;
    }

    /* End of RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport3' */
  }
}

/* Model update function for TID0 */
void modified_motor_update0(void)      /* Sample time: [0.0s, 0.0s] */
{
  real_T *lastU;

  /* Update for Derivative: '<S4>/Derivative' */
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

  /* End of Update for Derivative: '<S4>/Derivative' */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    rt_ertODEUpdateContinuousStates(&modified_motor_M->solverInfo);
  }

  /* Update absolute time */
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

  /* Update absolute time */
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

/* Derivatives for root system: '<Root>' */
void modified_motor_derivatives(void)
{
  XDot_modified_motor_T *_rtXdot;
  _rtXdot = ((XDot_modified_motor_T *) modified_motor_M->derivs);

  /* Derivatives for Integrator: '<S17>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = modified_motor_B.ddttheta;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = modified_motor_B.Sig1;

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = modified_motor_B.ddti;

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = modified_motor_B.d2dt2theta;
}

/* Model output function for TID2 */
void modified_motor_output2(void)      /* Sample time: [1.0s, 0.0s] */
{
  int32_T i;
  real_T angles_to_visit_data[100];
  boolean_T c[100];
  boolean_T d_data[100];
  int8_T e_data[100];
  int8_T f_data[100];
  int32_T g_data[100];
  int32_T g_i;
  ZCEventType zcEvent;
  real_T tmp_data[200];
  int32_T c_i;
  real_T tmp_data_0[400];
  int32_T angles_to_visit_size;
  int32_T tmp_size[2];
  boolean_T c_0;
  int32_T e_size_idx_0;
  int32_T f_size_idx_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(modified_motor_DW.PositionIterator_SubsysRanBC);

  /* UnitDelay: '<S5>/Unit Delay' */
  modified_motor_B.UnitDelay = modified_motor_DW.UnitDelay_DSTATE;

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/Constant'
   */
  modified_motor_B.Sum = modified_motor_P.Constant_Value -
    modified_motor_B.UnitDelay;

  /* DataStoreRead: '<S1>/Read Image' */
  modified_motor_B.ReadImage = modified_motor_DW.Image;

  /* MATLAB Function: '<S1>/Fire Webcam' */
  /* MATLAB Function 'Image Deconstructor/Fire Webcam': '<S6>:1' */
  if (modified_motor_B.Sum != 0.0) {
    /* '<S6>:1:4' */
    modified_motor_B.image = modified_motor_B.ReadImage + 1.0;
  } else {
    /* '<S6>:1:6' */
    modified_motor_B.image = modified_motor_B.ReadImage;
  }

  /* End of MATLAB Function: '<S1>/Fire Webcam' */

  /* DataStoreWrite: '<S1>/Write Image' */
  modified_motor_DW.Image = modified_motor_B.image;

  /* MATLAB Function: '<S1>/Process Image' */
  /* MATLAB Function 'Image Deconstructor/Process Image': '<S7>:1' */
  /*  Can only send fixed-length matrices so specify max 100 regions */
  /*  FIXME do processing */
  /* '<S7>:1:7' */
  memset(&modified_motor_B.image_data[0], 0, 400U * sizeof(real_T));

  /*  ex. pass back [shape; color; x_pos; y_pos] */
  /* '<S7>:1:10' */
  for (i = 0; i < 10; i++) {
    /* '<S7>:1:10' */
    /* '<S7>:1:11' */
    modified_motor_B.image_data[i] = 1.0 + (real_T)i;
    modified_motor_B.image_data[100 + i] = 1.0;
    modified_motor_B.image_data[200 + i] = modified_motor_B.image * 10.0;
    modified_motor_B.image_data[300 + i] = modified_motor_B.image * 10.0 + 20.0;
  }

  /* End of MATLAB Function: '<S1>/Process Image' */

  /* Selector: '<S2>/Selector1' */
  modified_motor_B.y = modified_motor_B.image_data[300];

  /* Selector: '<S2>/Selector' */
  modified_motor_B.x = modified_motor_B.image_data[200];

  /* UnitDelay: '<S8>/Unit Delay' */
  modified_motor_B.UnitDelay_i = modified_motor_DW.UnitDelay_DSTATE_m;

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Constant'
   */
  modified_motor_B.Sum_m = modified_motor_P.Constant_Value_b -
    modified_motor_B.UnitDelay_i;

  /* Fcn: '<S2>/Fcn' incorporates:
   *  Constant: '<Root>/Run'
   */
  modified_motor_B.Fcn = 1.0 - modified_motor_P.Run_Value;

  /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport1' */
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_d = 1;
  modified_motor_B.TmpRTBAtGenerateAnglesListInpor =
    modified_motor_DW.TmpRTBAtGenerateAnglesListInpor;
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_d = 0;

  /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport2' */
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_i = 1;
  modified_motor_B.TmpRTBAtGenerateAnglesListInp_d =
    modified_motor_DW.TmpRTBAtGenerateAnglesListInp_f;
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_i = 0;

  /* RateTransition: '<S2>/TmpRTBAtGenerate Angles ListInport3' */
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_c = 1;
  modified_motor_B.TmpRTBAtGenerateAnglesListInp_l =
    modified_motor_DW.TmpRTBAtGenerateAnglesListInp_o;
  modified_motor_DW.TmpRTBAtGenerateAnglesListInp_c = 0;

  /* MATLAB Function: '<S2>/Generate Angles List' */
  /* MATLAB Function 'Logic Block/Generate Angles List': '<S9>:1' */
  /*  PURPOSE - Parser to set  */
  /*  INPUTS */
  /*    - Mode: What should the system do in response to the user selection */
  /*        - scan: Visit every well with a sticker */
  /*        - seek color: Visit every well with a sticker of the given color */
  /*        - seek position: Visit only the well with the given sticker ID */
  /*    - Color Enum: What color the system should visit */
  /*    - Position: Angle in radians to visit */
  /*    - Image Data: 2D processed data from webcam */
  /*        - Col 1: Shape */
  /*        - Col 2: Color */
  /*        - Col 3: X Position */
  /*        - Col 4: Y Position */
  /*  OUTPUTS */
  /*    - positions_to_visit: Vector of fixed destination positions on [-pi, pi)  */
  /*        to which the motor arm should point in sequence. */
  /*  NOTES */
  /*    - If mode = 1 then the function ignores requested position and color. */
  /*    - If mode = 2 then the function ignores requested position. */
  /*    - If mode = 3 then the function ignores requested color. */
  /*  MATLAB expects a fixed-size output matrix so allow up to 100 angles */
  /*  to be propagated */
  /* '<S9>:1:39' */
  memset(&modified_motor_B.angles_vector[0], 0, 100U * sizeof(real_T));
  if (modified_motor_B.TmpRTBAtGenerateAnglesListInpor == 1.0) {
    /* '<S9>:1:41' */
    /* '<S9>:1:38' */
    c_i = 0;
    for (i = 0; i < 100; i++) {
      c_0 = (modified_motor_B.image_data[i] != 0.0);
      if (c_0) {
        c_i++;
      }

      c[i] = c_0;
    }

    e_size_idx_0 = c_i;
    i = 0;
    for (c_i = 0; c_i < 100; c_i++) {
      if (c[c_i]) {
        e_data[i] = (int8_T)(c_i + 1);
        i++;
      }
    }

    /* '<S9>:1:42' */
    /* '<S9>:1:43' */
    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i] = modified_motor_B.image_data[e_data[i] - 1];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + e_size_idx_0] = modified_motor_B.image_data[e_data[i] + 99];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + (e_size_idx_0 << 1)] = modified_motor_B.image_data[e_data[i]
        + 199];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + e_size_idx_0 * 3] = modified_motor_B.image_data[e_data[i] +
        299];
    }

    tmp_size[0] = e_size_idx_0;
    tmp_size[1] = 2;
    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data[i] = tmp_data_0[(e_size_idx_0 << 1) + i];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data[i + tmp_size[0]] = tmp_data_0[e_size_idx_0 * 3 + i];
    }

    modified_motor_rect_to_polar_v2(tmp_data, tmp_size, angles_to_visit_data,
      &angles_to_visit_size);
  } else if (modified_motor_B.TmpRTBAtGenerateAnglesListInpor == 2.0) {
    /* '<S9>:1:45' */
    /* '<S9>:1:38' */
    i = 0;
    for (c_i = 0; c_i < 100; c_i++) {
      c_0 = (modified_motor_B.image_data[c_i] != 0.0);
      if (c_0) {
        i++;
      }

      c[c_i] = c_0;
    }

    e_size_idx_0 = i;
    i = 0;
    for (c_i = 0; c_i < 100; c_i++) {
      if (c[c_i]) {
        e_data[i] = (int8_T)(c_i + 1);
        i++;
      }
    }

    /* '<S9>:1:46' */
    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i] = modified_motor_B.image_data[e_data[i] - 1];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + e_size_idx_0] = modified_motor_B.image_data[e_data[i] + 99];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + (e_size_idx_0 << 1)] = modified_motor_B.image_data[e_data[i]
        + 199];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data_0[i + e_size_idx_0 * 3] = modified_motor_B.image_data[e_data[i] +
        299];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      d_data[i] = (tmp_data_0[i + e_size_idx_0] ==
                   modified_motor_B.TmpRTBAtGenerateAnglesListInp_d);
    }

    i = 0;
    for (c_i = 0; c_i < 100; c_i++) {
      if (c[c_i]) {
        i++;
      }
    }

    f_size_idx_0 = i;
    i = 0;
    for (c_i = 0; c_i < 100; c_i++) {
      if (c[c_i]) {
        f_data[i] = (int8_T)(c_i + 1);
        i++;
      }
    }

    i = e_size_idx_0 - 1;
    c_i = 0;
    for (g_i = 0; g_i <= i; g_i++) {
      if (d_data[g_i]) {
        c_i++;
      }
    }

    e_size_idx_0 = c_i;
    c_i = 0;
    for (g_i = 0; g_i <= i; g_i++) {
      if (d_data[g_i]) {
        g_data[c_i] = g_i + 1;
        c_i++;
      }
    }

    /* '<S9>:1:46' */
    /* '<S9>:1:47' */
    for (i = 0; i < f_size_idx_0; i++) {
      tmp_data_0[i] = modified_motor_B.image_data[f_data[i] - 1];
    }

    for (i = 0; i < f_size_idx_0; i++) {
      tmp_data_0[i + f_size_idx_0] = modified_motor_B.image_data[f_data[i] + 99];
    }

    for (i = 0; i < f_size_idx_0; i++) {
      tmp_data_0[i + (f_size_idx_0 << 1)] = modified_motor_B.image_data[f_data[i]
        + 199];
    }

    for (i = 0; i < f_size_idx_0; i++) {
      tmp_data_0[i + f_size_idx_0 * 3] = modified_motor_B.image_data[f_data[i] +
        299];
    }

    tmp_size[0] = e_size_idx_0;
    tmp_size[1] = 2;
    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data[i] = tmp_data_0[((f_size_idx_0 << 1) + g_data[i]) - 1];
    }

    for (i = 0; i < e_size_idx_0; i++) {
      tmp_data[i + tmp_size[0]] = tmp_data_0[(f_size_idx_0 * 3 + g_data[i]) - 1];
    }

    modified_motor_rect_to_polar_v2(tmp_data, tmp_size, angles_to_visit_data,
      &angles_to_visit_size);
  } else if (modified_motor_B.TmpRTBAtGenerateAnglesListInpor == 3.0) {
    /* '<S9>:1:49' */
    /* '<S9>:1:50' */
    angles_to_visit_size = 1;
    angles_to_visit_data[0] = modified_motor_B.TmpRTBAtGenerateAnglesListInp_l;
  } else {
    /* '<S9>:1:53' */
    angles_to_visit_size = 4;
    angles_to_visit_data[0] = 3.1415926535897931;
    angles_to_visit_data[1] = -3.1415926535897931;
    angles_to_visit_data[2] = 1.5707963267948966;
    angles_to_visit_data[3] = -1.5707963267948966;
  }

  /*  Package variable-length vector into fixed-length vector */
  /* '<S9>:1:57' */
  f_size_idx_0 = angles_to_visit_size;
  for (i = 0; i < f_size_idx_0; i++) {
    modified_motor_B.angles_vector[i] = angles_to_visit_data[i];
  }

  /* End of MATLAB Function: '<S2>/Generate Angles List' */

  /* Outputs for Triggered SubSystem: '<S2>/Position Iterator' incorporates:
   *  TriggerPort: '<S10>/Increment'
   */
  if (rtmIsMajorTimeStep(modified_motor_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &modified_motor_PrevZCX.PositionIterator_Trig_ZCE,
                       (modified_motor_B.Sum_m));
    if (zcEvent != NO_ZCEVENT) {
      /* DataStoreRead: '<S10>/Data Store Read' */
      modified_motor_B.iter_cur_index = modified_motor_DW.Index;

      /* MATLAB Function: '<S10>/Iterator' */
      /* MATLAB Function 'Logic Block/Position Iterator/Iterator': '<S12>:1' */
      /*  PURPOSE - Iterate over list of positions to visit */
      /*  INPUTS */
      /*    - Position List: Vector of target positions for the motor to turn to */
      /*    - Current Index: Loopback to store variable state */
      /*    - Clock: Trigger to move to the next position */
      /*    - Reset: Trigger to reset to first position in list (0 == HIGH) */
      /*  OUTPUTS */
      /*    - Target Position: Motor position on range [-pi, pi)  */
      /*    - Next Index: Loopback to store variable state */
      /*  BEHAVIOR */
      /*    - If Reset is high then reset index to 0 and output first position */
      /*    - Else if Clock is low then output the position at the current index */
      /*    - Else if the index is at the end of the list then output 0 */
      /*    - Else increment the index and output the next position */
      /*  PRECONDITION: pos_list is a column vector */
      /* '<S12>:1:21' */
      /* '<S12>:1:22' */
      /*  Reset has highest priority */
      if (modified_motor_B.Fcn == 0.0) {
        /* '<S12>:1:25' */
        /* '<S12>:1:26' */
        modified_motor_B.next_index = 1.0;

        /* '<S12>:1:27' */
        modified_motor_B.target_pos_o = modified_motor_B.angles_vector[0];
      } else {
        /*  If we can increment then do that */
        if ((-1.0 < modified_motor_B.iter_cur_index) &&
            (modified_motor_B.iter_cur_index < 100.0)) {
          /* '<S12>:1:30' */
          /* '<S12>:1:31' */
          modified_motor_B.next_index = modified_motor_B.iter_cur_index + 1.0;

          /* '<S12>:1:32' */
          modified_motor_B.target_pos_o = modified_motor_B.angles_vector
            [(int32_T)(modified_motor_B.iter_cur_index + 1.0) - 1];

          /*  Otherwise maintain current state */
        } else {
          /* '<S12>:1:35' */
          modified_motor_B.next_index = modified_motor_B.iter_cur_index;

          /* '<S12>:1:36' */
          modified_motor_B.target_pos_o = 0.0;
        }
      }

      /* End of MATLAB Function: '<S10>/Iterator' */

      /* DataStoreWrite: '<S10>/Data Store Write' */
      modified_motor_DW.Index = modified_motor_B.next_index;
      modified_motor_DW.PositionIterator_SubsysRanBC = 4;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/Position Iterator' */
}

/* Model update function for TID2 */
void modified_motor_update2(void)      /* Sample time: [1.0s, 0.0s] */
{
  /* Update for UnitDelay: '<S5>/Unit Delay' */
  modified_motor_DW.UnitDelay_DSTATE = modified_motor_B.Sum;

  /* Update for RateTransition: '<S2>/Rate Transition' */
  modified_motor_DW.RateTransition_Buffer0 = modified_motor_B.target_pos_o;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  modified_motor_DW.UnitDelay_DSTATE_m = modified_motor_B.Sum_m;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++modified_motor_M->Timing.clockTick2)) {
    ++modified_motor_M->Timing.clockTickH2;
  }

  modified_motor_M->Timing.t[2] = modified_motor_M->Timing.clockTick2 *
    modified_motor_M->Timing.stepSize2 + modified_motor_M->Timing.clockTickH2 *
    modified_motor_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void modified_motor_output(int_T tid)
{
  switch (tid) {
   case 0 :
    modified_motor_output0();
    break;

   case 2 :
    modified_motor_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void modified_motor_update(int_T tid)
{
  switch (tid) {
   case 0 :
    modified_motor_update0();
    break;

   case 2 :
    modified_motor_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void modified_motor_initialize(void)
{
  /* Start for DataStoreMemory: '<S1>/Store Image Data' */
  modified_motor_DW.Image = modified_motor_P.StoreImageData_InitialValue;

  /* Start for RateTransition: '<S2>/Rate Transition' */
  modified_motor_B.target_pos = modified_motor_P.RateTransition_X0;

  /* Start for S-Function (encquanserq8): '<S14>/Q4 Enc ' */
  /* Level2 S-Function Block: '<S14>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S15>/S-Function' */

  /* S-Function Block: <S15>/S-Function (scblock) */
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

  /* Start for S-Function (scblock): '<S16>/S-Function' */

  /* S-Function Block: <S16>/S-Function (scblock) */
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

  /* Start for S-Function (daquanserq8): '<S14>/Q4 DA ' */
  /* Level2 S-Function Block: '<S14>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Triggered SubSystem: '<S2>/Position Iterator' */
  /* Start for DataStoreMemory: '<S10>/Store_Index' */
  modified_motor_DW.Index = modified_motor_P.Store_Index_InitialValue;

  /* End of Start for SubSystem: '<S2>/Position Iterator' */

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  modified_motor_DW.UnitDelay_DSTATE =
    modified_motor_P.UnitDelay_InitialCondition;

  /* InitializeConditions for RateTransition: '<S2>/Rate Transition' */
  modified_motor_DW.RateTransition_Buffer0 = modified_motor_P.RateTransition_X0;

  /* InitializeConditions for Integrator: '<S17>/Integrator2' */
  modified_motor_X.Integrator2_CSTATE = modified_motor_P.Integrator2_IC;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  modified_motor_DW.TimeStampA = (rtInf);
  modified_motor_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  modified_motor_X.Integrator_CSTATE = modified_motor_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  modified_motor_X.Integrator_CSTATE_g = modified_motor_P.Integrator_IC_a;

  /* InitializeConditions for Integrator: '<S17>/Integrator1' */
  modified_motor_X.Integrator1_CSTATE = modified_motor_P.Integrator1_IC;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  modified_motor_DW.UnitDelay_DSTATE_m =
    modified_motor_P.UnitDelay_InitialCondition_b;

  /* SystemInitialize for Triggered SubSystem: '<S2>/Position Iterator' */
  /* SystemInitialize for Outport: '<S10>/Target_Position' */
  modified_motor_B.target_pos_o = modified_motor_P.Target_Position_Y0;
  modified_motor_PrevZCX.PositionIterator_Trig_ZCE = ZERO_ZCSIG;

  /* End of SystemInitialize for SubSystem: '<S2>/Position Iterator' */
}

/* Model terminate function */
void modified_motor_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<S14>/Q4 Enc ' */
  /* Level2 S-Function Block: '<S14>/Q4 Enc ' (encquanserq8) */
  {
    SimStruct *rts = modified_motor_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<S14>/Q4 DA ' */
  /* Level2 S-Function Block: '<S14>/Q4 DA ' (daquanserq8) */
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
  if (tid == 1)
    tid = 0;
  modified_motor_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  modified_motor_update(tid);
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
    mdlTsMap[2] = 2;
    modified_motor_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    modified_motor_M->Timing.sampleTimes =
      (&modified_motor_M->Timing.sampleTimesArray[0]);
    modified_motor_M->Timing.offsetTimes =
      (&modified_motor_M->Timing.offsetTimesArray[0]);

    /* task periods */
    modified_motor_M->Timing.sampleTimes[0] = (0.0);
    modified_motor_M->Timing.sampleTimes[1] = (0.001);
    modified_motor_M->Timing.sampleTimes[2] = (1.0);

    /* task offsets */
    modified_motor_M->Timing.offsetTimes[0] = (0.0);
    modified_motor_M->Timing.offsetTimes[1] = (0.0);
    modified_motor_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(modified_motor_M, &modified_motor_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = modified_motor_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      modified_motor_M->Timing.perTaskSampleHitsArray;
    modified_motor_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    modified_motor_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(modified_motor_M, -1);
  modified_motor_M->Timing.stepSize0 = 0.001;
  modified_motor_M->Timing.stepSize1 = 0.001;
  modified_motor_M->Timing.stepSize2 = 1.0;

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
  rtsiSetSolverMode(&modified_motor_M->solverInfo, SOLVER_MODE_MULTITASKING);

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
    modified_motor_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (modified_motor_M)[2]);
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

    /* Level2 S-Function Block: modified_motor/<S14>/Q4 Enc  (encquanserq8) */
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

    /* Level2 S-Function Block: modified_motor/<S14>/Q4 DA  (daquanserq8) */
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
  modified_motor_M->Sizes.numSampTimes = (3);/* Number of sample times */
  modified_motor_M->Sizes.numBlocks = (82);/* Number of blocks */
  modified_motor_M->Sizes.numBlockIO = (55);/* Number of block outputs */
  modified_motor_M->Sizes.numBlockPrms = (98);/* Sum of parameter "widths" */
  return modified_motor_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
