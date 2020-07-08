#pragma once

#include "file.h"
#include "defines.h"
#include "ls.h"
#ifdef USE_BMP_INFO
	#include "info_bmp.h"
#endif // DEBUG

#ifdef USE_DEBUG  
	#include "debug.h"
#endif

namespace RUN 
{
	struct RunApp : public  File  , Ls
	#ifdef USE_DEBUG  
	, DEBUG::Debug 
	#endif // DEBUG

	{

		RunApp();
		~RunApp()=default;

	private:
		uint32_t counter=0;
	};


void App(void);

}
