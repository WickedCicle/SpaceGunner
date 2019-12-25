#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>

#ifndef CONSOLE_H
#define CONSOLE_H

void HideCursor(); // ������ ������
void SetCurPos(int x, int y); // ���������� ������ �� ������� x,y
void FullScreen(); // �������� ���� �� ������ �����
void RemoveScrollBox(); // �������� ������ ��������� � ����
void LucidaConnect(); // ����������� ������ Lucida Console
void UnicodeConnect(); // ����������� Unicode

#endif // !CONSOLE_H
