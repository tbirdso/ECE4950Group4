#include "slrtappmapping.h"
#include "./maps/custom_pwm.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <custom_pwm> */
		{ /* SignalMapInfo */
			custom_pwm_BIOMAP,
			custom_pwm_LBLMAP,
			custom_pwm_SIDMAP,
			custom_pwm_SBIO,
			custom_pwm_SLBL,
			{0,7},
			8,
		},
		{ /* ParamMapInfo */
			custom_pwm_PTIDSMAP,
			custom_pwm_PTNAMESMAP,
			custom_pwm_SPTMAP,
			{0,6},
			7,
		},
		"custom_pwm",
		"",
		"custom_pwm",
		2,
		custom_pwm_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}