#include <iostream>
#include <windows.h>
using namespace std;
int getx() { //gets current console pos x
CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(h,&csbi);
return csbi.dwCursorPosition.X;
}

int gety() { //gets current console pos y
CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
       GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.Y;
}


void gotoxy(int x, int y) //goes to x,y console
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main() {
    int x,y;
int time = 10;

cout << "Time left ";
x = getx();
y = gety();

while(time>0) {
Sleep(1000);
gotoxy(x,y);
cout << time << "      \n";
time--;

}
}
