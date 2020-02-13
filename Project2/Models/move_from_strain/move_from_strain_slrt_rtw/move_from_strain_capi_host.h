#ifndef RTW_HEADER_move_from_strain_cap_host_h_
#define RTW_HEADER_move_from_strain_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} move_from_strain_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void move_from_strain_host_InitializeDataMapInfo
    (move_from_strain_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_move_from_strain_cap_host_h_ */

/* EOF: move_from_strain_capi_host.h */
