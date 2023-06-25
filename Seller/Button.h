#pragma once
#include <string>
#include "Shapes.h"

typedef std::wstring WString;
typedef unsigned char uchar;

enum Colors {
	White = 0x0F,
	Yellow = 0x0E,
	Green = 0x0A
};

class Text {
public:
	Text(): Text(0, 0, L"NULL", White) {};
	Text(int MTextX, int MTextY, WString MS, uchar MFontColor): x(MTextX), y(MTextY), Label(MS), FontColor(MFontColor) {};
	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	//inline int GetWidth() const { return W; }
	inline WString GetLabel() const { return Label; }
	inline uchar GetFontColor() const { return FontColor; }
	
private:
	int x, y;
	WString Label;
	uchar FontColor;
};

class Button {
public:
	Button(RECTANGLE rectangle, Text txt) : rect(rectangle), text(txt) {};
	inline RECTANGLE GetRectangle() const { return rect; }
	inline Text GetText() const { return text; }

private:
	RECTANGLE rect;
	Text text;
};
