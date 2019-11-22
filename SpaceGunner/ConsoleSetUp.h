#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>

#ifndef CONSOLE_H
#define CONSOLE_H

void HideCursor();
void SetCurPos(int x, int y);
void UnicodeConnect();

#endif // !CONSOLE_H
