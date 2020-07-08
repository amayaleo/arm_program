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
//								
//	
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>
extern "C"{
    // #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include "pid.h"
}

#include <ctime>
#include "debug.h"
#include "defines.h"


namespace DEBUG{
    void Debug::debug(std::string str_tmp)
    {
    #ifdef USE_DEBUG
        std::cout << " debug : " << str_tmp << " step : " << counter <<  "\r\n" ;
    #endif
        counter++;
    }

    void Debug::get_pid(){
    std::string str ;
    if(  get_pid_value()  ){
        str = std::to_string( get_pid_value() );
    }
    else {
        str = "[no defined Program ID]";
    }


        #ifdef USE_DEBUG
            debugger( str );
        #else
            debugger(" no debugger - pid : " +   get_pid_value() );
        #endif // DEBUG
    }

    void debugger(std::string dbg){
#ifdef USE_DEBUG
        Debug obj_dbg;
        obj_dbg.debug(dbg);
        return ;
#else
        static uint32_t count=0;
        std::cout << "step : "  << count  << "msj : "<< dbg <<std::endl;
#endif
    }


	uint32_t Debug::state()
    {
        uint32_t elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "Cálculo terminado  " << std::ctime(&end_time)
        << "tiempo transcurrido: " << elapsed_seconds << "s\n";
    return elapsed_seconds;
    }

	void Debug::start_dbg(){
    start = std::chrono::system_clock::now();
    }

	void Debug::end_dbg(){
    end = std::chrono::system_clock::now();
    }


}