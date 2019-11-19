


void initConsole(SHORT x, SHORT y) {
	COORD size = { x, y };
	SMALL_RECT src = { 0, 0, size.X - 1, size.Y - 1 };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	SetConsoleWindowInfo(hOut, true, &src);
	SetConsoleScreenBufferSize(hOut, size);
	RemoveMenu(hMenu, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);
}

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void setColor(int color) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, color);
}