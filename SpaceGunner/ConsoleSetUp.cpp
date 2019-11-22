#include "ConsoleSetUp.h"

void HideCursor() {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void SetCurPos(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void UnicodeConnect() {
	_setmode(_fileno(stdout), _O_U8TEXT);

	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.nFont = 0;
	wcscpy_s(fontInfo.FaceName, L"Unifont");
	fontInfo.dwFontSize.X = 14;
	fontInfo.dwFontSize.Y = 18;
	fontInfo.FontFamily = FW_DONTCARE;
	fontInfo.FontWeight = FW_REGULAR;
	fontInfo.cbSize = sizeof(fontInfo);

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}