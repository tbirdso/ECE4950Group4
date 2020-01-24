#ifndef RTW_HEADER_new_analog_loopback_q4_p4_cap_host_h_
#define RTW_HEADER_new_analog_loopback_q4_p4_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} new_analog_loopback_q4_p4_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void new_analog_loopback_q4_p4_host_InitializeDataMapInfo
    (new_analog_loopback_q4_p4_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_new_analog_loopback_q4_p4_cap_host_h_ */

/* EOF: new_analog_loopback_q4_p4_capi_host.h */
