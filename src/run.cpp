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
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>
#include "ls.h"
#include "run.h"

namespace RUN 
{

    RunApp::RunApp(){
    #ifdef USE_DEBUG
        DEBUG::Debug  obj_debug;
        obj_debug.debug("Inicializando Aplicacion ... ");
        obj_debug.get_pid();        
    #endif // DEBUG
       // Ls ls;
        //ls.get_ls();
#ifdef USE_BMP_INFO
        INFO_BMP::BmpInfo  bmp_info;
        bmp_info.bmp();
#endif // DEBUG        

    }


    void App(void)
    {
        try
        {
            RunApp run;
        }
        catch(...)
        {
            std::cout << " Program error  ... "<< std::endl;   
        }
    }

}