#pragma once

namespace DISPLAY
{
    struct Display{

        Display()=default;
        ~Display()=default;

        void view ();
        void line(uint16_t);
    private:
        uint16_t wide;
        uint16_t height;
        uint16_t line_tmp;
    };
}