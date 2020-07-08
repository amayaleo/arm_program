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
#include "display.h"
#include "debug.h"



namespace DISPLAY
{
    inline void 
    Display::view (){
        DEBUG::debugger("view");
    }

    inline void 
    Display::line(uint16_t selective_line){
        DEBUG::debugger("line");
    }

}