#pragma once
#include <chrono>
namespace DEBUG
{

struct  Debugger
{
	virtual 	~Debugger()	= default;
	virtual 	uint32_t state() 	=0;
	virtual 	void start_dbg() 	=0;
	virtual 	void end_dbg()  	=0;
};


	struct Debug : public Debugger
	{
		Debug()=default;
		~Debug()=default;
		void debug(std::string);
		void get_pid(void);


		uint32_t state()override;
		void start_dbg()override;
		void end_dbg()override;

	private:
		inline static uint32_t counter {0};
		std::chrono::time_point<std::chrono::system_clock> start, end;

	};

	void debugger(std::string);
}