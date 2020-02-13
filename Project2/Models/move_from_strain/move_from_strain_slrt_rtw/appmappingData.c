#include "slrtappmapping.h"
#include "./maps/move_from_strain.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <move_from_strain> */
		{ /* SignalMapInfo */
			move_from_strain_BIOMAP,
			move_from_strain_LBLMAP,
			move_from_strain_SIDMAP,
			move_from_strain_SBIO,
			move_from_strain_SLBL,
			{0,9},
			10,
		},
		{ /* ParamMapInfo */
			move_from_strain_PTIDSMAP,
			move_from_strain_PTNAMESMAP,
			move_from_strain_SPTMAP,
			{0,19},
			20,
		},
		"move_from_strain",
		"",
		"move_from_strain",
		2,
		move_from_strain_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}