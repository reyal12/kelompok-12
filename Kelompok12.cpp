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
	
		for (int f=0; f<10; f++){
			start_color();
			init_pair(1,COLOR_WHITE,COLOR_WHITE);
			attron(COLOR_PAIR(1));
				mvprintw(16, 55 + f, ">");
			refresh();
			Sleep(600);
			attroff(COLOR_PAIR(1));
	}
	clear();
	
	mvprintw (15, 55, "Login Berhasil!");
		refresh();
		Sleep(1000);
		clear();
	
	mvprintw (12, 55, "Main Menu");
	mvprintw (13, 55, "1. Start");
	mvprintw (14, 55, "2. Option");
	mvprintw (15, 55, "3. Keluar");
	mvprintw (16, 55, "4. Pilih Menu :");
		refresh();
	
	move(16, 70);
	echo();
	pilihan = getch();
