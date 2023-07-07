#pragma once
#include <windows.h>
#include <string>

typedef unsigned int uint;
typedef unsigned char uchar;
typedef std::wstring WString;

enum Colors {
	Black = 0x00,
	White = 0x0F,
	Yellow = 0x0E,
	Green = 0x0A,
	GreenSoft = 0x02,
	GreenInverted = 0xA0,
};

enum MenuController {
	ControllerCloseGame = 0x00,
	ControllerMenuPrincipal = 0x01,
	//ControllerMenuStore = 0x02,
	ControllerMenuStoreCPU = 0x03,
	ControllerMenuStoreGPU = 0x04,
	ControllerMenuStoreMemory = 0x05,
	ControllerMenuStoreStorage = 0x06,
	ControllerMenuStoreNetwork = 0x07,
};

class ConsoleApplication {
public:


	static const uint bufferWidth = 81;
	static const uint bufferHeight = 23;

	CHAR_INFO* Buffer;
	HWND hwnd;
	HANDLE hout;
	COORD dwBufferSize = { bufferWidth, bufferHeight };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT lpWriteRegion = { 0, 0, bufferWidth - 1, bufferHeight - 1 };

	ConsoleApplication() {
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		int length = bufferWidth * bufferHeight;
		Buffer = (CHAR_INFO*)malloc(length * sizeof(*Buffer));
		hwnd = { GetConsoleWindow() };

		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
		static CONSOLE_FONT_INFOEX fontex; // Comienza a ajustar el tamaño de los carcteres de la consola
		GetCurrentConsoleFontEx(hout, 0, &fontex);
		fontex.cbSize = sizeof(fontex);
		fontex.nFont = 0;
		fontex.dwFontSize.X = 17;
		fontex.dwFontSize.Y = 33;
		fontex.FontWeight = FW_NORMAL;
		fontex.FontFamily = FF_DONTCARE;
		lstrcpyW(fontex.FaceName, L"Terminal");
		//fontex.FaceName = L"Lucida Console";
		SetCurrentConsoleFontEx(hout, false, &fontex); // Termina de ajustar el tamaño de los caracteres
		// Poner la consola en el centro de la pantalla y ajusta su tamaño
		SetWindowPos(GetConsoleWindow(), NULL, GetSystemMetrics(SM_CXSCREEN) / 2 - 1492 / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - 800 / 2, 1492, 800, SWP_SHOWWINDOW);

		CONSOLE_CURSOR_INFO info; 
		GetConsoleCursorInfo(hout, &info); // dwSize, bVisible
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(hout, &info); // Termina de esconder el cursor
		ShowScrollBar(hwnd, SB_VERT, 0); // Remove the scrollbar
		SetConsoleTitle(L"Game");


		ClearBuffer(this->Buffer);

		DWORD cNumRead, fdwMode = { NULL }, i;

	}

	void ClearBuffer(CHAR_INFO* buffer) {
		for (int i = 0; i < bufferWidth * bufferHeight; ++i) {
			buffer[i].Char.UnicodeChar = L' ';
			buffer[i].Attributes = Black;
		}
	}

	void DrawCharW(int CoordX, int CoordY, wchar_t c, uchar Color, CHAR_INFO* buffer) {

		uint y = bufferHeight - CoordY - 1;
		uint i = y * bufferWidth + CoordX;

		buffer[i].Char.UnicodeChar = c;
		buffer[i].Attributes = Color;
	}

	void DrawStringW(int CoordX, int CoordY, WString s, uchar Color, CHAR_INFO* buffer) {

		for (int i = 0; i < s.length(); i++) {
			DrawCharW(CoordX + i, CoordY, s[i], Color, buffer);
		}
	}

	void DrawStringVerticalyW(int CoordX, int CoordY, int Length, wchar_t c, uchar Color, CHAR_INFO* buffer) {

		for (int i = 0; i < Length; i++) {
			DrawCharW(CoordX, CoordY + i, c, Color, buffer);
		}
	}

	void DrawStringHorizontallyW(int CoordX, int CoordY, int Length, wchar_t c, uchar Color, CHAR_INFO* buffer) {

		for (int i = 0; i < Length; i++) {
			DrawCharW(CoordX + i, CoordY, c, Color, buffer);
		}
	}

	static void DrawWndBegin(ConsoleApplication* CA) {

		uchar height = bufferHeight - 2;

		CA->DrawStringW(2, 20, L"C:\\Start>", Green, CA->Buffer);

		CA->DrawStringVerticalyW(0, 1, height, L'║', Green, CA->Buffer);
		CA->DrawStringVerticalyW(bufferWidth - 1, 1, height, L'║', Green, CA->Buffer);
		CA->DrawStringVerticalyW(14, 1, height, L'║', Green, CA->Buffer);

		CA->DrawStringHorizontallyW(1, 0, bufferWidth - 2, L'═', Green, CA->Buffer);
		CA->DrawStringHorizontallyW(1, bufferHeight - 1, bufferWidth - 2, L'═', Green, CA->Buffer);

		CA->DrawCharW(14, 0, L'╩', Green, CA->Buffer);
		CA->DrawCharW(14, bufferHeight - 1, L'╦', Green, CA->Buffer);

		CA->DrawCharW(0, 0, L'╚', Green, CA->Buffer);
		CA->DrawCharW(bufferWidth - 1, 0, L'╝', Green, CA->Buffer);
		CA->DrawCharW(0, bufferHeight - 1, L'╔', Green, CA->Buffer);
		CA->DrawCharW(bufferWidth - 1, bufferHeight - 1, L'╗', Green, CA->Buffer);
	}
	
	static void DrawWndStore(ConsoleApplication* CA) {

		DrawWndBegin(CA);

		CA->DrawStringHorizontallyW(15, 8, bufferWidth - 16, L'═', Green, CA->Buffer);
		CA->DrawCharW(14, 8, L'╠', Green, CA->Buffer);
		CA->DrawCharW(bufferWidth - 1, 8, L'╣', Green, CA->Buffer);
	}
};
