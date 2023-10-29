/*
#ifndef __PS_M_H__
#define __PS_M_H__

#include "ATOMIC_MODELS.h"
#include "MACROS.h"
#define PS_NAME "PS"

class __stack
{
    private:
        STATE_VARS queue1, queue2;
        
    public:
        void push(string value){
            queue2.push(value);
            while(!queue1.empty()){
                queue2.push(queue1.front());
                queue1.pop();
            }
            std::swap(queue1, queue2);
        }
        void pop(){
            if(queue1.empty()){
                return;
            }
            queue1.pop();
        }
        
}

class PS: public ATOMIC_MODELS
{
    protected:
        STATE_VARS job_id;
        __stack _stack;
        STATE_VARS processing_time;
    
    public:
        PORT* in;
        PORT* out;

        PS(string name);
        ~PS();

        void externalTransitionFunc( timetype e, CONTENT x);
        void internalTransitionFunc();
        CONTENT outputFunc();
};
#endif
*/