#ifndef __LOG__H__
#define __LOG__H__

//System Header Files (A-Z)
#include <fstream>

//Common Header Files (A-Z)
#include "MACROS.h"

static string FLASH_MESSAGE_FILE = "flash_message.txt";
static string SIM_LOG_FILE = "sim_msg_log.txt";

#define MODEL_NAME		"Model: "
#define MSG_TYPE		"Type: "
#define RECEIVED_FROM	"Received From: "
#define MSG_TIME		"Time: "
#define CONTENT_PORT	"Port: "
#define CONTENT_VALUE	"Value: "

#define SIM_MSG_LOG_NAME( func ) \
	msg_log << ( func ) << endl; \

#define MSG_LOG( txt ) \
	msg_log << txt << endl;

#define SIM_CLOCK_BASE_LOG( clock_base ) \
	msg_log << "SEQ: " << log_seq << endl; \
	msg_log << "[ " << __LINE__ << " ]: " << __FUNCTION__ << endl; \
	msg_log << #clock_base << ": " << clock_base << endl << endl; \

#define COORDINATOR_MSG_LOG( devs_comp, tN, tL, star_child, wait_list ) \
	msg_log.open( SIM_LOG_FILE, ios::app ); \
	msg_log << "[ " << __LINE__ << " ]: " << __FUNCTION__ << endl; \
	msg_log << #devs_comp << ": " << ( devs_comp->getName() ) << endl; \
	msg_log << #tN << ": " << ( tN ) << endl; \
	msg_log << #tL << ": " << ( tL ) << endl; \
	msg_log << #star_child << ": " << ( getProcessor( star_child ) ) << endl; \
	msg_log << #wait_list << ": " << ( getProcessor( wait_list ) ) << endl << endl; \
	msg_log.close();

#define SIMULATOR_MSG_LOG( devs_comp, tN, tL ) \
	msg_log.open( SIM_LOG_FILE, ios::app ); \
	msg_log << "[ " << __LINE__ << " ]: " << __FUNCTION__ << endl; \
	msg_log << MODEL_NAME << ": " << ( devs_comp->getName() ) << endl; \
	msg_log << #tN << ": " << ( tN ) << endl; \
	msg_log << #tL << ": " << ( tL ) << endl << endl; \
	msg_log.close();

#define FLASE_MESSAGE_LOG( txt ) \
	msg_log << txt << endl;

#endif
