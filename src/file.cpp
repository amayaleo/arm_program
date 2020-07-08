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
//#include <fstream>
#include "defines.h"
#include "file.h"
#include "debug.h"

#ifdef USE_DEBUG
    #define FILENAME FILENAME_BACKUP
#else 
    #define FILENAME "file.omg"
#endif // DEBUG



namespace RUN
{
    File::File()
    :namefile {FILENAME}
    {
        dbg("File()  : " + namefile );

        create();
        write();
    }

     File::~File(){
         dbg("~File()");
        close();
      }

    inline void File::read()
    {
        dbg("read file");

    }

    inline void File::write()
    {
        dbg("init write line");
        for(int i=14;i<69;i++)
        {
            wsfile << "line : " << i << "\n";
        }
        dbg("end write line");
    }

    inline bool File::open()
    {   
        wsfile.open(namefile);
        if(wsfile.is_open())  
        {
            dbg("create file : " + namefile);
            return true;
        }
        dbg("open");
        return false;
    }

    inline void File::close()
    {
        if(wsfile.is_open())
        {
            wsfile.close();
        } 
        dbg("no file in ");    
    }

    inline void File::dbg(std::string dbg){

#ifdef USE_DEBUG
    DEBUG::debugger(dbg);
#else   
    std::cout << " DEBUGGER DISABLE msj : "<< dbg<<std::endl;
#endif

    }

    inline void File::create()
    {
        if(open()){
            dbg("Create()");      
        }
            dbg("no create()");  
          
    }

} // namespace FILE


