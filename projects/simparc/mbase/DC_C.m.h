#ifndef __DC_C_M_H__
#define __DC_C_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define DC_C_NAME	"DC_C"

class DC_C : public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS job_id;
	STATE_VARS p_cnt;
	STATE_VARS out_port;
	
public:
	PORT*	in;
	PORT*	out;
	PORT* 	px; 
	PORT* 	py;
	PORT* 	cx;
	PORT* 	cy;
	PORT* 	x1;
	PORT* 	y1;
	PORT* 	x2;
	PORT* 	y2;
	PORT* 	x3;
	PORT* 	y3;
	
	DC_C(string name);
	~DC_C();

	void		externalTransitionFunc(timetype e, CONTENT x);
	void		internalTransitionFunc();
	CONTENT		outputFunc();
};
#endif
