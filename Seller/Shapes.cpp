#pragma once
#include "Shapes.h"

CHAR_INFO* Computer::DrawBar(const Computer& bar, CHAR_INFO* buffer, int CoordX, int CoordY) {

	ConsoleApplication CA;
	CA.DrawCharW(CoordX, bar.CoordY, L'[', Green, buffer);
	CA.DrawCharW(CoordX + 11, bar.CoordY, L']', Green, buffer);

	WString percentage = std::to_wstring(bar.x) + L" of " + std::to_wstring(bar.xt);
	CA.DrawStringW(bar.CoordX + 13, bar.CoordY, percentage, Green, buffer);

	int l = (float)bar.x / (float)bar.xt * Width;
	for (int i = 0; i < Computer::Width; ++i) {
		CA.DrawCharW(bar.CoordX + i + 1, bar.CoordY, i <= l ? L'▬' : L'—', i <= l ? Green : GreenSoft, buffer);
	}

	return buffer;
}