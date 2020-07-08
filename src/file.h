#pragma once
#include <iostream>
#include <fstream>

namespace RUN
{
	
	struct File
	{
		File();
		~File();
	 	void read();
	 	void write();
		bool open();
		void close();
		void dbg(std::string);
		void create();
		
	private:
	 	std::string namefile;
		std::ofstream wsfile;
	};

} // namespace FILE


