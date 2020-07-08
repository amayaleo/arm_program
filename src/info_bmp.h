#pragma once 
#include <fstream>

namespace INFO_BMP{
 
  struct bmpFileHeader
  {
    /* 2 bytes de identificación */
    uint32_t size;        /* Tamaño del archivo */
    uint16_t resv1;       /* Reservado */
    uint16_t resv2;       /* Reservado */
    uint32_t offset;      /* Offset hasta hasta los datos de imagen */
  };

  struct bmpInfoHeader
  {
    uint32_t headersize;      /* Tamaño de la cabecera */
    uint32_t width;               /* Ancho */
    uint32_t height;          /* Alto */
    uint16_t planes;                  /* Planos de color (Siempre 1) */
    uint16_t bpp;             /* bits por pixel */
    uint32_t compress;        /* compresión */
    uint32_t imgsize;     /* tamaño de los datos de imagen */
    uint32_t bpmx;                /* Resolución X en bits por metro */
    uint32_t bpmy;                /* Resolución Y en bits por metro */
    uint32_t colors;              /* colors used en la paleta */
    uint32_t imxtcolors;      /* Colores importantes. 0 si son todos */
  };

  struct BmpInfo : public  bmpInfoHeader , bmpFileHeader
  {
    explicit BmpInfo()=default;
    void DisplayInfo();
    void LoadBMP( const std::string);
    void bmp();

  template <typename TYPE>
  void read_byte(TYPE &);

  private:
    char buffer[54];
    inline static uint16_t i{0};
    bmpInfoHeader info_header;
    std::ifstream pFile;
    bmpFileHeader img;
  };


   }