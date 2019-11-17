#include<windows.h>
#include <iostream>
#include "main.h"

using namespace std;

int main() {
	int a = initCon(80, 35);
}

int initCon(SHORT x, SHORT y) {
	COORD size = { x, y };
	SMALL_RECT src = { 0, 0, size.X - 1, size.Y - 1 };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	SetConsoleCP(1251);
	SetConsoleWindowInfo(hout, true, &src);
	SetConsoleScreenBufferSize(hout, size);
	RemoveMenu(hMenu, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);
	return 0;
}