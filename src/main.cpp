/////////////////////////////////////////////////////////////////////////////////////////////////////
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
//						g++ main.c -o app		
//	./app
//
//      REAME.md 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "run.h"



struct B //: A
{
    virtual void f()=0;
    virtual  ~B()=default;
            
    /* data */
};

struct A : public B
{
    A(std::string txt)
    :text(txt)
    {

    }
     void f()override; 

    private:
        std::string text;
};

void A::f(){
    std::cout << "/* message */" << text << std::endl;

}



int main(int argc,char *argv[])
{
  RUN::App();

//   B * b;
//   b=new A(" funcion virtual creada \n");
//   b->f();
//   if(b)  delete b;
           
    return 0;
}
