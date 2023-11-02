#ifndef __SPK_M_H__
#define __SPK_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"

#define SPK_NAME	"SPK"

class SPK: public ATOMIC_MODELS
{
protected: // state variables
	STATE_VARS kick_type_;
	STATE_VARS processing_time;
    //STATE_VARS score;
    STATE_VARS winner;

public:
	PORT*	in_a;
    PORT*   in_b;
	PORT*	out;

    string id_inport;
    int cnt = 0;
	SPK( string name );
	~SPK();

	void		externalTransitionFunc( timetype e, CONTENT x );
	void		internalTransitionFunc();
	CONTENT		outputFunc();
    int Ascore = 0, Bscore = 0;
};
#endif