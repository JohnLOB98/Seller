//#include "Button.h"
//
//
//bool GetsKeyUp(int VK, bool* Key) {
//	if (GetKeyState(VK) < 0) *Key = true;
//	else if (*Key) {
//		*Key = false;
//		return true;
//	}
//	return false;
//}
//
//// BUTTONS
//int Button::EventsControllerMenu(std::vector<Button> Buttons, Account* account, bool* Key) {
//	
//	int value = -1;
//	if (GetsKeyUp(FROM_LEFT_1ST_BUTTON_PRESSED, Key)) {
//
//		CONSOLE_SELECTION_INFO PCSI = {};
//		COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };
//
//		for (Button btn : Buttons) {
//			if (Events::OnClickRectangle(btn, cor.X, cor.Y) && btn.GetTag() == btn.GetMenuTag()) {
//				value = btn.ExecuteAction(account, btn, btn.GetActionFunction());
//			}
//		}
//	}
//
//	return value;
//}
//
//void Button::SpecialEvents(std::vector<Button> Buttons, Account* account, bool* Key) {
//	
//	if (GetsKeyUp(FROM_LEFT_1ST_BUTTON_PRESSED, Key)) {
//
//		CONSOLE_SELECTION_INFO PCSI = {};
//		COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };
//
//		for (Button btn : Buttons) {
//			if (Events::OnClickRectangle(btn, cor.X, cor.Y) && btn.GetTag() == btn.GetSpecialTag()) {
//				btn.ExecuteAction(account, btn, btn.GetActionFunction());
//			}
//		}
//	}
//}
//
//
//
//void Button::DrawButton(CHAR_INFO* buffer, uchar FColor) const {
//
//	int x = rect.GetX();
//	int y = rect.GetY();
//	int Width = rect.GetWidth();
//	
//	WString s1 = L"│ " + text.GetLabel();
//	int l = s1.length();
//	for (int i = 0; i <= Width - 2 - l; ++i) s1 += L" ";
//	s1 += L"│";
//	
//	WString s0 = L"┌";
//	for (int i = 0; i < Width - 2; ++i) s0 += L'─';
//	s0 += L"┐";
//
//	WString s2 = L"└";
//	for (int i = 0; i < Width - 2; ++i) s2 += L'─';
//	s2 += L"┘";
//
//	ConsoleApplication* CA = (ConsoleApplication*)malloc(sizeof(ConsoleApplication));
//	CA->DrawStringW(x, y,	  s0, FColor, buffer);
//	CA->DrawStringW(x, y - 1, s1, FColor, buffer);
//	CA->DrawStringW(x, y - 2, s2, FColor, buffer);
//
//	free(CA);
//}
//
//void Button::DrawUnlockCPUButton(CHAR_INFO* buffer, int i) const {
//
//	int x = rect.GetX();
//	int y = rect.GetY();
//	WString s = L"│ ₿ " + std::to_wstring(1000 + i * 5000) + L" to buy";
//
//	int l = s.length();
//	for (int i = 0; i <= 25 - l; ++i) s += L" ";
//	s += L"│";
//
//	WString noComputer = std::to_wstring(i + 1);
//	ConsoleApplication* CA = (ConsoleApplication*)malloc(sizeof(ConsoleApplication));
//	CA->DrawStringW(x, y,     L"┌─CPU " + noComputer + L"───────────────────┐", Green, buffer);
//	CA->DrawStringW(x, y - 1, L"│                         │", Green, buffer);
//	CA->DrawStringW(x, y - 2, s, Green, buffer);
//	CA->DrawStringW(x, y - 3, L"│                         │", Green, buffer);
//	CA->DrawStringW(x, y - 4, L"└─────────────────────────┘", Green, buffer);
//
//	free(CA);
//}
//
//void Button::DrawButtonCPU(CHAR_INFO* buffer, Account& account) const {
//
//	int CountComputers = account.GetComputers().size();
//	int x = 20;
//	int y = 20 - CountComputers * 5;
//	
//	int count = 0;
//	for (int i = 0; i < 3 || i < account.GetComputers().size(); i++) {
//		Computer c = account.GetComputers()[i];
//	}
//
//	WString noComputer = std::to_wstring(CountComputers + 1);
//	ConsoleApplication* CA = (ConsoleApplication*)malloc(sizeof(ConsoleApplication));
//	CA->DrawStringW(x, y, L"┌─CPU " + noComputer + L"───────────────────┐", Green, buffer);
//	CA->DrawStringW(x, y - 1, L"│                         │", Green, buffer);
//	CA->DrawStringW(x, y - 2, L"│                         │", Green, buffer);
//	CA->DrawStringW(x, y - 3, L"│                         │", Green, buffer);
//	CA->DrawStringW(x, y - 4, L"└─────────────────────────┘", Green, buffer);
//
//	free(CA);
//}
//
//
//
//
//
//// EVENTS
//bool Events::OnClickRectangle(Button& btn, short Mx, short My) {
//
//	RECTANGLE rect = btn.GetRectangle();
//	return Mx >= rect.GetX() && Mx < rect.GetX() + rect.GetWidth() && My >= 22 - rect.GetY() && My < 22 - rect.GetY() + rect.GetHeight();
//}
//
//int Events::OnClickBuyCPU(Account* account, Button btn) {
//	return Components::GetCostCPU(btn.GetText().GetLabel());
//}
//
////int Events::OnClickBuyCPU(Account* account, Button btn) {
////
////	int Cost = Components::GetCostCPU(btn.GetText().GetLabel());
////
////	//if(Account)
////	return Cost;
////
////	//account
////}
