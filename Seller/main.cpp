#include <windows.h>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include "Events.h"
//#include "Shapes.h"
#include "Button.h"

//#define BufferLength 1863 // BufferWidth * BufferHeight
//#define VK_LeftMouse0x0001

typedef unsigned int uint;
typedef unsigned char uchar;
typedef std::wstring WString;

uint bufferWidth = 81;
uint bufferHeight = 23;


// SCREEN CAMERA
CHAR_INFO* Buffer;
HWND hwnd;
HANDLE hout;
COORD dwBufferSize = { bufferWidth, bufferHeight };
COORD dwBufferCoord = { 0, 0 };
SMALL_RECT lpWriteRegion = { 0, 0, bufferWidth - 1, bufferHeight - 1 };

class ConsoleApplication {
public: 
	void Initialize(int bufferWidth, int bufferHeight) {
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		int length = bufferWidth * bufferHeight;
		Buffer = (CHAR_INFO*)malloc(length * sizeof(*Buffer));
		hwnd = { GetConsoleWindow() };

		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
		static CONSOLE_FONT_INFOEX fontex; // Comienza a ajustar el tamaño de los carcteres de la consola
		GetCurrentConsoleFontEx(hout, 0, &fontex);
		fontex.cbSize = sizeof(fontex);
		fontex.nFont = 0;
		fontex.dwFontSize.X = 18;
		fontex.dwFontSize.Y = 35;
		fontex.FontWeight = FW_DONTCARE;
		fontex.FontFamily = FF_SCRIPT;
		SetCurrentConsoleFontEx(hout, false, &fontex); // Termina de ajustar el tamaño de los caracteres
		// Poner la consola en el centro de la pantalla y ajusta su tamaño
		SetWindowPos(GetConsoleWindow(), NULL, GetSystemMetrics(SM_CXSCREEN) / 2 - 1492 / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - 800 / 2, 1492, 800, SWP_SHOWWINDOW);
		CONSOLE_CURSOR_INFO info = { 100, false }; // dwSize, bVisible
		SetConsoleCursorInfo(hout, &info); // Termina de esconder el cursor
		ShowScrollBar(GetConsoleWindow(), SB_VERT, 0); // Remove the scrollbar
		SetConsoleTitle(L"Long Story");

		DWORD cNumRead, fdwMode = {NULL}, i;

		ClearBuffer();
	}

	void ClearBuffer() {
		for (int i = 0; i < bufferWidth * bufferHeight; i++) {
			Buffer[i].Char.UnicodeChar = L' ';
			Buffer[i].Attributes = 0;
		}
	}

	void DrawCharW(int CoordX, int CoordY, wchar_t c, uchar Color) {

		uint y = bufferHeight - CoordY - 1;
		uint i = y * bufferWidth + CoordX;

		Buffer[i].Char.UnicodeChar = c;
		Buffer[i].Attributes = Color;
	}

	void DrawStringW(int CoordX, int CoordY, WString s, uchar Color) {

		for (int i = 0; i < s.length(); i++) {
			DrawCharW(CoordX + i, CoordY, s[i], Color);
		}
	}

	void DrawStringVerticalyW(int CoordX, int CoordY, int Length, wchar_t c, uchar Color) {

		for (int i = 0; i < Length; i++) {
			DrawCharW(CoordX, CoordY + i, c, Color);
		}
	}

	void DrawStringHorizontallyW(int CoordX, int CoordY, int Length, wchar_t c, uchar Color) {

		for (int i = 0; i < Length; i++) {
			DrawCharW(CoordX + i, CoordY, c, Color);
		}
	}

	void DrawWndBegin() {

		ConsoleApplication CA;
		uchar height = bufferHeight - 2;

		CA.DrawStringVerticalyW(0, 1, height, L'║', Yellow);
		CA.DrawStringVerticalyW(bufferWidth - 1, 1, height, L'║', Yellow);
		CA.DrawStringHorizontallyW(1, 0, bufferWidth - 2, L'═', Yellow);
		CA.DrawStringHorizontallyW(1, bufferHeight - 1, bufferWidth - 2, L'═', Yellow);
		CA.DrawCharW(0, 0, L'╚', Yellow);
		CA.DrawCharW(bufferWidth - 1, 0, L'╝', Yellow);
		CA.DrawCharW(0, bufferHeight - 1, L'╔', Yellow);
		CA.DrawCharW(bufferWidth - 1, bufferHeight - 1, L'╗', Yellow);
	}
};

void Start(std::vector<Button>* Buttons) {

	ConsoleApplication CA;

	for (Button btn : *Buttons) {
		Text txt = btn.GetText();
		CA.DrawStringW(txt.GetX(), txt.GetY(), txt.GetLabel(), txt.GetFontColor());
	}
}

void WndBegin() {

	ConsoleApplication CA;
	CA.DrawWndBegin();

	std::vector<Button> Buttons;
	Buttons.push_back(Button(RECTANGLE(1, 4, 7, 3), Text(2, 2, L"Close", Green))); // { L"Close", 1, 1, 15, Green });
	//Buttons.push_back({ L"Close", 1, 1, 15, Green });
	//Buttons.push_back({ L"Achivements", 1, 17, 15, Green });
	//Buttons.push_back({ L"Shop", 1, 19, 15, Green });
	//Buttons.push_back({ L"Profit", 1, 21, 15, Green});
	Start(&Buttons);

	while (true) {

		// REFERENCE https://learn.microsoft.com/en-us/windows/console/mouse-event-record-str?redirectedfrom=MSDN
		if (GetAsyncKeyState(FROM_LEFT_1ST_BUTTON_PRESSED)) {

			CONSOLE_SELECTION_INFO PCSI = {};
			COORD* cor = GetConsoleSelectionInfo(&PCSI) ? new COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : new COORD{ 0, 0 };

			WString s = L"X: " + std::to_wstring(cor->X) + L", Y: " + std::to_wstring(cor->Y);
			CA.DrawStringW(10, 10, s, White);

			//for(Input)

		}
		if (GetAsyncKeyState(RIGHTMOST_BUTTON_PRESSED)) {
			CA.DrawCharW(10, 10, L'R', White);
		}

		WriteConsoleOutput(hout, Buffer, dwBufferSize, dwBufferCoord, &lpWriteRegion);
		Sleep(1);
	}
}


int main() {

	ConsoleApplication CA;
	CA.Initialize(bufferWidth, bufferHeight);

	WndBegin();

	return 0;
}