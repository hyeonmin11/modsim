#ifndef __MESSAGES_H__
#define __MESSAGES_H__

//Common Header Files (A-Z)
#include "DEVS-ObjectC.h"

//DEVS system Header Files (A-Z)
#include "CONTENT.h"
#include "PORT.h"

#include "base_type.h"

class DLL_EXPORT MODELS;

DLL_EXPORT enum type
{
	STAR, X, Y, DONE, EXT
};

class DLL_EXPORT MESSAGES
{
private:
	int type;
	MODELS* source;
	timetype time;
	CONTENT content;

public:
	// 持失切, 社瑚切
	MESSAGES();
	MESSAGES( int type, timetype time );
	MESSAGES( int type, MODELS* source, timetype time );
	~MESSAGES();

	int getType();
	MODELS* getSource();
	timetype getTime();
	CONTENT getContent();
	void addContent( CONTENT content );
	//void		SetMessage( MODELS* source, timetype time, CONTENT* content);
};
#endif
