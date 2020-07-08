#pragma once

namespace  TIME{


	struct Time{


		Time()=default;
		~Time()=default;
		void get_time(std::string);
		void time_sleep(uint32_t time_tmp){};
	private:
			uint32_t hours;
			uint32_t minutes;
			uint32_t seconds;
			uint32_t ms;
	};
    
}