
#ifndef CONSOLEUTIL_H
#define CONSOLEUTIL_H

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25

void dump_key_buffer()
{
	int c = getchar();

	while (c != '\n' && c != EOF)
		c = getchar();
}

//Tested: Windows 7 + VS 2012
#if defined(WIN32) || defined(_WIN32)

#include <conio.h>
#include <windows.h>

void console_activate()
{
	fflush(stdout);

}

void console_deactivate()
{
	fflush(stdout);
}

void print_char(int x, int y, char c)
{
	COORD pos = {x , y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%c", c);
}

void print_string(int x, int y, const char* str)
{
	COORD pos = {x , y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	printf("%s", str);
}

int get_input()
{
	return _getch();
}

void get_string(char* str)
{
	scanf_s("%s", str);
	dump_key_buffer();
}



#endif


#endif