#include "slrtappmapping.h"
#include "./maps/new_analog_loopback_q4_p4.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <new_analog_loopback_q4_p4> */
		{ /* SignalMapInfo */
			new_analog_loopback_q4_p4_BIOMAP,
			new_analog_loopback_q4_p4_LBLMAP,
			new_analog_loopback_q4_p4_SIDMAP,
			new_analog_loopback_q4_p4_SBIO,
			new_analog_loopback_q4_p4_SLBL,
			{0,0},
			1,
		},
		{ /* ParamMapInfo */
			new_analog_loopback_q4_p4_PTIDSMAP,
			new_analog_loopback_q4_p4_PTNAMESMAP,
			new_analog_loopback_q4_p4_SPTMAP,
			{0,11},
			12,
		},
		"new_analog_loopback_q4_p4",
		"",
		"new_analog_loopback_q4_p4",
		1,
		new_analog_loopback_q4_p4_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}