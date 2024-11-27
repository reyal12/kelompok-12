#include <ncurses/ncurses.h>
#include <unistd.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
	struct User{
		string nama, pass;
	};
		vector<User> users;
	void signUp(), signIn(), mainMenu(), loadingScreen();
		
int main(){
	initscr();
	curs_set(0);
		while(true){
			clear();
				mvprintw (10, 55, "=== LOGIN ===");
				mvprintw (12, 55, "1. Sign Up");
				mvprintw (13, 55, "2. Sign In");
				mvprintw (14, 55, "3. Keluar");
			refresh();
	
				noecho();
				char pilihan = getch();
				
			if (pilihan == '1'){
				signUp();
			} else if (pilihan == '2'){
				signIn();
			} else if (pilihan == '3'){
				break;
			} else {
			clear();
				mvprintw (15, 55, "Failed!");
			refresh();
			}
		}
		endwin();
		return 0;
}
//-----------------------------------------------------------------------
	
