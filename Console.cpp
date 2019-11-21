#include <windows.h>
#include <iostream>
#include "Console.h"

	Console::Console(HANDLE hOut, HWND hWnd) : hOut(hOut), hWnd(hWnd)
	{
		//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		//HWND hWnd = GetConsoleWindow();
		hMenu = GetSystemMenu(hWnd, false);
	}

	void Console::init(SHORT x, SHORT y) {
		COORD size = { x, y };
		SMALL_RECT src = { 0, 0, size.X - 1, size.Y - 1 };
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		SetConsoleWindowInfo(hOut, true, &src);
		SetConsoleScreenBufferSize(hOut, size);
		RemoveMenu(hMenu, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
		RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
		DrawMenuBar(hWnd);
	}

	void Console::clear() {
		COORD topLeft = { 0, 0 };
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;
		GetConsoleScreenBufferInfo(hOut, &screen);
		FillConsoleOutputCharacterA(hOut, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		FillConsoleOutputAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		SetConsoleCursorPosition(hOut, topLeft);
	}

	void Console::setColor(UCHAR fontColor, UCHAR backColor) {
		fontColor &= 0x0f;
		backColor &= 0x0f;
		backColor *= 0x10;
		int color = fontColor + backColor;
		SetConsoleTextAttribute(hOut, color);
	}

	void Console::setCursor(SHORT x, SHORT y) {
		COORD position;
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hOut, position);
	}