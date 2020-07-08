#pragma once

namespace MAIN_MENU{

	enum number_id_display
	{
		DISPLAY_PRESENT,
		DISPLAY_FILES,
		SETTINGS,
		REBOOT,
		EXIT,
		BACK

	};

	struct Menu
	{
		Menu();
		~Menu();

		void function(void);
		int menu_display(int);
		void print_menu_all();

	};

}