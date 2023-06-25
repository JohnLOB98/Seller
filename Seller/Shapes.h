#pragma once

class RECTANGLE {

public:
	RECTANGLE() : RECTANGLE(0, 0, 0, 0) {};
	RECTANGLE(int Vx, int Vy, int VW, int VH): x(Vx), y(Vy), W(VW), H(VH) {};
	//~Rectangle();
	void SetX(int v) { x = v; }
	void SetY(int v) { y = v; }
	void SetWidth(int v) { W = v; }
	void SetHeight(int v) { H = v; }
	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	inline int GetWidth() const { return W; }
	inline int GetHeight() const { return H; }

private:
	int x, y, W, H;
};
