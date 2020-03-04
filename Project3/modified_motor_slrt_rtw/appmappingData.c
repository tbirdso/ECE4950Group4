#include "slrtappmapping.h"
#include "./maps/modified_motor.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <modified_motor> */
		{ /* SignalMapInfo */
			modified_motor_BIOMAP,
			modified_motor_LBLMAP,
			modified_motor_SIDMAP,
			modified_motor_SBIO,
			modified_motor_SLBL,
			{0,28},
			29,
		},
		{ /* ParamMapInfo */
			modified_motor_PTIDSMAP,
			modified_motor_PTNAMESMAP,
			modified_motor_SPTMAP,
			{0,44},
			45,
		},
		"modified_motor",
		"",
		"modified_motor",
		1,
		modified_motor_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}