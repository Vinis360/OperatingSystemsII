// EPOS Semaphore Abstraction Implementation

//#include "../../include/semaphore.h"
#include <semaphore.h>
__BEGIN_SYS

Semaphore::Semaphore(int v): _value(v)
{
    db<Synchronizer>(TRC) << "Semaphore(value=" << _value << ") => " << this << endl;
}


Semaphore::~Semaphore()
{
    db<Synchronizer>(TRC) << "~Semaphore(this=" << this << ")" << endl;
}


void Semaphore::p()
{
    db<Synchronizer>(TRC) << "Semaphore::p(this=" << this << ",value=" << _value << ")" << endl;
    begin_atomic();
    if(_value > 0) {
    	fdec(_value);
    } else {
	sleep();
    }
    end_atomic();
        
    
    
}


void Semaphore::v()
{
    db<Synchronizer>(TRC) << "Semaphore::v(this=" << this << ",value=" << _value << ")" << endl;
    begin_atomic();
    if(!on_hold.empty()){
	wakeup();
    } else {	
    	finc(_value);
    } 
    end_atomic();
}

__END_SYS
