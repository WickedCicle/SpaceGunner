#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>

#ifndef CONSOLE_H
#define CONSOLE_H

void HideCursor(); // скрыть курсор
void SetCurPos(int x, int y); // установить курсор на позицию x,y
void FullScreen(); // открытие окна на полный экран
void RemoveScrollBox(); // убирание полосы прокрутки в окне
void LucidaConnect(); // подключение шрифта Lucida Console
void UnicodeConnect(); // подключение Unicode

#endif // !CONSOLE_H
