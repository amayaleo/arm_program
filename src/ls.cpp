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
//	                    Time.h
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>
#include <string>
#include <filesystem>

#include "ls.h"
#include "debug.h"
#include "defines.h"


namespace fs = std::filesystem;

namespace  RUN{
void Ls::get_ls() const
{
    DEBUG::debugger("command ls -asl");
    std::string path = "../bmp_files"; //FILES_BMP
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << "\t\t" << entry.path() << std::endl;
    }
}