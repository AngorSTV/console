#include <windows.h>

class Console {
	
private:
	HANDLE hOut;
	HWND hWnd;
	HMENU hMenu;

public:
	//Конструктор
	Console(HANDLE hOut, HWND hWnd);

	//Устанавливает размер в знакоместах
	void init(SHORT x, SHORT y);

	//Очищает
	void clear();

	//Задаёт текущий цвет шрифта и фона
	void setColor(UCHAR fontColor, UCHAR backColor);

	//Устанавливает курсор в позицию
	void setCursor(SHORT x, SHORT y);
};