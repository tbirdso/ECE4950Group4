#ifndef __modified_motor_XPCOPTIONS_H___
#define __modified_motor_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "modified_motor.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_modified_motor_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            2048
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void modified_motor_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_modified_motor_T *const modified_motor_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  modified_motor_M->Timing.stepSize0 = modified_motor_M->Timing.stepSize0 *
    ratio;
  modified_motor_M->Timing.stepSize1 = modified_motor_M->Timing.stepSize1 *
    ratio;
  modified_motor_M->Timing.stepSize2 = modified_motor_M->Timing.stepSize2 *
    ratio;
  modified_motor_M->Timing.stepSize = modified_motor_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  modified_motor_ChangeStepSize(stepSize, modified_motor_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(modified_motor_M, errMsg);
}

#endif                                 /* __modified_motor_XPCOPTIONS_H___ */
