#include <ncurses/ncurses.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
using namespace std;
int main(){
		initscr();
			char nama[50], pass[50], pilihan;
		
				mvprintw (14, 55, "Login");
				mvprintw (15, 55, "Username :");
				mvprintw (16, 55, "Password :");
			refresh();
	
	move(15, 65);
	echo();
	getstr (nama);
	
	move(16, 65);
	echo();
	getstr (pass);
		refresh();
		clear();
	
	mvprintw (15, 55, "Loading...");
	mvprintw (16, 55, "      ");
	mvprintw (16, 54, "|          |");
		refresh();
