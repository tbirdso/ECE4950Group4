#ifndef RTW_HEADER_custom_pwm_cap_host_h_
#define RTW_HEADER_custom_pwm_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} custom_pwm_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void custom_pwm_host_InitializeDataMapInfo(custom_pwm_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_custom_pwm_cap_host_h_ */

/* EOF: custom_pwm_capi_host.h */
