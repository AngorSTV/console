#include<windows.h>
#include <iostream>
#include "main.h"
#include "Console.h"

using namespace std;

int main() {
	Console con(GetStdHandle(STD_OUTPUT_HANDLE), GetConsoleWindow());
	con.init(80, 40);
	con.clear();

	int k = 0;
	char u;

	for (int i = 0; i < 40; i++) {
		con.setColor(0, i);
		con.setCursor(0, i);
		cout << "                            ";
		k++;
	}
	cin >> u;
}