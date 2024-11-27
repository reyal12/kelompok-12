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
	void signUp(){
		clear();
		char nama[50], pass[50];
			mvprintw (13, 55, "=== SIGN UP ===");
			mvprintw (15, 55, "Username :");
		move(15, 66);
		echo();
		getstr(nama);
			
			mvprintw (16, 55, "Password :");
		move(16, 66);
		echo();
		getstr(pass);
			
	users.push_back({nama, pass});
		
		clear();
			mvprintw (15, 55, "Success!");
		refresh();
		getch();	
	}
//------------------------------------------------------------------------
	void signIn(){
		clear();
		char nama[50], pass[50];
			mvprintw (13, 55, "=== SIGN IN ===");
			mvprintw (15, 55, "Username :");
		move(15, 66);
		echo();
		getstr(nama);
			
			mvprintw (16, 55, "Password :");
		move(16, 66);
		echo();
		getstr(pass);
			
		bool loginSuccess = false;
		for (const auto& user : users){
			if (user.nama == nama && user.pass == pass){
				loginSuccess = true;
				break;
			}
		}
		if (loginSuccess){
			loadingScreen();
			mainMenu();
			} else {
			clear();	
				mvprintw (15, 50, "Username atau Password salah King!");
			refresh();
			getch();
			clear();
			}
		}
		
void loadingScreen(){
	clear();
	mvprintw (15, 55, "loading...");
	mvprintw (16, 55, "      ");
	mvprintw (16, 54, "|            |");
		refresh();
	
		for (int f=0; f<12; f++){
			start_color();
			init_pair(1,COLOR_BLUE,COLOR_BLUE);
			attron(COLOR_PAIR(1));
				mvprintw(16, 55 + f, ">");
			refresh();
			Sleep(400);
			attroff(COLOR_PAIR(1));
		}
	clear();
		mvprintw (15, 55, "Login Berhasil King!");
		refresh();
		Sleep(800);
	}

void mainMenu(){
	clear();
	mvprintw (10, 55, "WELLCOME");
	mvprintw (12, 55, "1. Continue");
	mvprintw (13, 55, "2. New Game");
	mvprintw (14, 55, "3. Exit");
		refresh();
	
	char opsi;
	move(0, 0);
	noecho();
	opsi = getch();
	
	switch (opsi){
		case '1':
			if (mainMenu){
				} else {
			clear();
				mvprintw (15, 55, "New Game");
			refresh();
				Sleep(800);
				}
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			clear();
				mvprintw (15, 55, "Keluar dari game ");
			refresh();
			Sleep(800);
			break;
		default:
			clear();
				mvprintw (15, 55, "Coba lagi ");
			refresh();
			Sleep(800);
			break;	
		}
	}
