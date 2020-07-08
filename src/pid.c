/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	autor : 
//						Amaya Leo
//	Compilardor:
//						g++
//
//	Tipo de aplicacion:
//
//	Caracteristicas:
//
//	Makefile:
//
//	Library :							
//	                    pid.h
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "pid.h"
#include "defines.h"


struct  Pid
{
    /* data */
};


unsigned int  get_pid_value() {

    unsigned int  pid_tmp = 0;
    pid_tmp = getpid();
#ifdef USE_DEBUG
    printf (" pid program is : [%d] \n" ,pid_tmp);
#endif // USE_DEBUG
        
    if(pid_tmp){
        return pid_tmp;
    }
    else{
        return 0;
    }

}
