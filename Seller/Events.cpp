#include "Events.h"

bool Events::OnClickRectangle(const Button& btn, int Mx, int My) {

	RECTANGLE rect = btn.GetRectangle();

	return Mx >= rect.GetX() && Mx <= rect.GetX() + rect.GetWidth() && My >= rect.GetY() && My <= rect.GetY() + rect.GetHeight();
	//if (Mx >= rect.GetX() && Mx <= rect.GetX() + rect.GetWidth() && My >= rect.GetY() && My <= rect.GetY() + rect.GetHeight()) {
	//	return true;
	//} 

	//return false;
}