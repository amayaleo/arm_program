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
//#include <unistd.h>
//#include <errno.h>
#include "menu.h"
#include "debug.h"
#include "time.h"

namespace MAIN_MENU
{
    int Menu::menu_display(int number_id){
    bool debug =1;
    TIME::Time tyme ;

        switch(number_id){
            case DISPLAY_PRESENT:
                    system("clear");
                        tyme.time_sleep(1);
                        DEBUG::debugger("Develepment lio pixel wide");
                        tyme.time_sleep(3);
                    //system("clear");
                        DEBUG::debugger("Seleccione la opcion");
                        tyme.time_sleep(3);
                break;
                case DISPLAY_FILES:
                        DEBUG::debugger("\tfile1.jpg");
                        DEBUG::debugger("\tfile2.jpg");
                        DEBUG::debugger("\tfile3.jpg");
                        DEBUG::debugger("\tfile4.jpg");
                        DEBUG::debugger("\tfile5.jpg");
                        system("clear");
                        tyme.time_sleep(3);
                    break;
            case EXIT:
                DEBUG::debugger("\t\t\tEXIT- Press ok ");
                DEBUG::debugger("\t\t\t\t\t\tsystem(poweroff)");
                break;
            case REBOOT:
                DEBUG::debugger("\t\t\tREBOOT Press ok ");
                DEBUG::debugger("\t\t\t\t\t\tsystem(reboot)");
                break;

            case BACK:
                if(debug)DEBUG::debugger("\t\t\tBack menu ");
                break;
            case SETTINGS:
            if(debug)DEBUG::debugger("\t\t\tSettings");
                break;

            default:
            if(debug)DEBUG::debugger("\t\t\tDefault");
                break;
            }
        return number_id;
    }



    void Menu::print_menu_all(){
    DEBUG::debugger("*****************************************************");
        for(int x=0;x<5;x++){
        menu_display(x);
        }

        DEBUG::debugger("*****************************************************");
    }

    Menu::Menu(){DEBUG::debugger("constructor menu");};

    Menu::~Menu(){DEBUG::debugger("destructor menu");}

    
}