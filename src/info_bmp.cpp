
#include <iostream>
#include <cstdint>

#include "info_bmp.h"
#include "defines.h"
#include "debug.h"

namespace INFO_BMP{

void BmpInfo::LoadBMP(const std::string filename)
{


std::cout<< "load bmp ... \n";
    pFile.open(filename ,std::ifstream::binary );
    pFile.read(buffer, 54);

    if(pFile.is_open()){
      pFile.close();
    }

read_byte(info_header.headersize);      /* Tamaño de la cabecera */
//std::cout << "s3 value" << " 0x"<<std::hex << info_header.headersize<<std::endl ;

read_byte(info_header.width);               /* Ancho */
read_byte(info_header.height);          /* Alto */
read_byte(info_header.planes);                  /* Planos de color (Siempre 1) */
read_byte(info_header.bpp);             /* bits por pixel */
read_byte(info_header.compress);        /* compresión */
read_byte(info_header.imgsize);     /* tamaño de los datos de imagen */
read_byte(info_header.bpmx);                /* Resolución X en bits por metro */
read_byte(info_header.bpmy);                /* Resolución Y en bits por metro */
read_byte(info_header.colors);              /* colors used en la paleta */
read_byte(info_header.imxtcolors); 

return ;
}




  void BmpInfo::DisplayInfo()
  {
              std::cout<< "read info display ... \n";

#ifdef USE_DEBUG

#else
    //if(info_header)
    {
      std::printf("\t\tTamaño de la cabecera: %u\n",  info_header.headersize);
      std::printf("\t\tAnchura: %d\n" , info_header.width);
      std::printf("\t\tAltura: %d\n" , info_header.height);
      std::printf("\t\tPlanos (1): %d\n" , info_header.planes);
      std::printf("\t\tBits por pixel: %d\n" , info_header.bpp);
      std::printf("\t\tCompresión: %d\n" , info_header.compress);
      std::printf("\t\tTamaño de datos de imagen: %u\n" , info_header.imgsize);
      std::printf("\t\tResolucón horizontal: %u\n" ,  info_header.bpmx);
      std::printf("\t\tResolucón vertical: %u\n" , info_header.bpmy);
      std::printf("\t\tColores en paleta: %d\n" , info_header.colors);
      std::printf("\t\tColores importantes: %d\n" , info_header.imxtcolors);
    }
    #endif // DEBUG
  }


  void BmpInfo::bmp()
  {
    BmpInfo bmp_info;
    bmp_info.LoadBMP("../bmp_files/gradient.bmp");
    bmp_info.DisplayInfo();
  }





  template <typename TYPE>
  void BmpInfo::read_byte(TYPE & tmp)
  {
    uint16_t x = sizeof(tmp);

    switch (x)
    {
      case 2 :
              tmp = this->buffer [this->i+1]<<8 | this->buffer[this->i];
              this->i += 2;
            break;

      case 4:
              tmp = this->buffer [this->i+3]<<24 | this->buffer [this->i+2]<<16 | this->buffer [this->i+1]<<8 | this->buffer[this->i];
              this->i += 4;
              std::cout << "\t value " << " 0x" << std::hex << tmp << "value i : " << this->i <<std::endl ;

            break;
    default:
          break;
    }
  }




  // void BmpInfo::TextDisplay()
  // {
  //   uint32_t x, y;
  //   /* Reducimos la resolución vertical y horizontal para que la imagen entre en pantalla */
  //   static const int reduccionX=6, reduccionY=4;
  //   /* Si la componente supera el umbral, el color se marcará como 1. */
  //   static const int umbral=90;
  //   /* Asignamos caracteres a los colores en pantalla */
  //   static unsigned char colores[9]={"bgfrRGB"};
  //   int r,g,b;

  //   /* Dibujamos la imagen */
  //   for (y=info_header.height; y>0; y-=reduccionY)
  //     {
  //       for (x=0; x<info_header.width; x+=reduccionX)
  //     {
  //       b=(img[3*(x+y*info_header.width)]>umbral);
  //       g=(img[3*(x+y*info_header.width)+1]>umbral);
  //       r=(img[3*(x+y*info_header.width)+2]>umbral);

  //       std::printf("%c", colores[b+g*2+r*4]);
  //     }
  //       std::cout<<"\n";
  //     }
  // }




}