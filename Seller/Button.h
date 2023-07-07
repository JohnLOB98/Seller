//#pragma once
//#include <string>
//#include <functional>
//#include "Shapes.h"
//#include "Account.h"
//
//typedef std::wstring WString;
//typedef unsigned char uchar;
//
//class Text {
//public:
//	Text(): Text(0, 0, L"", White) {};
//	Text(int MTextX, int MTextY, WString MS, uchar MFontColor): x(MTextX), y(MTextY), Label(MS), FontColor(MFontColor) {};
//	
//	// SET
//	void SetFontColor(uchar vFontColor) { this->FontColor = vFontColor; }
//
//	// GET
//	inline int GetX() const { return x; }
//	inline int GetY() const { return y; }
//	inline WString GetLabel() const { return Label; }
//	inline uchar GetFontColor() const { return FontColor; }
//
//	
//private:
//	int x, y;
//	WString Label;
//	uchar FontColor;
//};
//
//
//
//
//
//class Button {
//
//public:
//
//	
//	
//
//	// CONSTRUCTOR
//	//Button() : rect(RECTANGLE()), text(Text()), tag(L"MenuButton"), ActionFunction() {};
//	Button(): Button(RECTANGLE(), Text(), Button::GetMenuTag(), ActionFunction) {};
//	Button(RECTANGLE rectangle, Text txt, uchar tg, std::function<int(Account*, Button)> func): rect(rectangle), text(txt), tag(tg), ActionFunction(func) {};
//	Button(Button* btn): rect(btn->rect), text(btn->text), tag(btn->tag), ActionFunction(btn->ActionFunction) {};
//	// GET
//	inline RECTANGLE GetRectangle() const { return rect; }
//	inline Text GetText() const { return text; }
//	inline std::function<int(Account*, Button)> GetActionFunction() const { return ActionFunction; }
//	uchar GetTag() { return tag; }
//	static const uchar GetMenuTag() { return 0; }
//	static const uchar GetSpecialTag() { return 1; }
//
//	// EXECUTE ACTIONS
//	int ExecuteAction(Account* account, Button btn, std::function<int(Account*, Button)> func) const { return func(account, btn); }
//	int EventsControllerMenu(std::vector<Button> Buttons, Account* account, bool* Key);
//	void SpecialEvents(std::vector<Button> Buttons, Account* account, bool* Key);
//
//	// DRAW
//	void DrawButton(CHAR_INFO* buffer, uchar FColor) const;
//	void DrawUnlockCPUButton(CHAR_INFO* buffer, int i) const;	
//	void DrawButtonCPU(CHAR_INFO* buffer, Account& account) const;
//
//	// SET
//	
//	void SetLabelFontColor(uchar vFontColor) { this->GetText().SetFontColor(vFontColor); }
//	
//	//void OnClick()
//	//void OnEnter()
//	//int OnSelectStoreCPU(Account* account, Button btn) {
//	//	this->
//	//}
//
//	void OnClickBuyCPU(Account* account) {
//		
//		int Cost = Components::GetCostCPU(this->text.GetLabel());
//		if (Cost <= account->GetMoney()) {
//			account->SetMoney(account->GetMoney() - Cost);
//		}
//	}
//
//private:
//	RECTANGLE rect;
//	Text text;
//	uchar tag; // MenuButton, SpecialButton, 
//	std::function<int(Account*, Button)> ActionFunction;
//};
//
//
//
//
//
//class Events {
//public:
//
//	static bool OnClickRectangle(Button& btn, short Mx, short My);
//
//	inline static int CloseGame(Account* account, Button btn) { return ControllerCloseGame; }
//	inline static int MenuBegin(Account* account, Button btn) { return ControllerMenuPrincipal; }
//	//inline static int OnClickButtonStore(Account* account, Button btn) { return ControllerMenuStore; }
//	inline static int OnClickButtonStoreCPU(Account* account, Button btn) { return ControllerMenuStoreCPU; }
//	inline static int OnClickButtonStoreGPU(Account* account, Button btn) { return ControllerMenuStoreGPU; }
//	inline static int OnClickButtonStoreMemory(Account* account, Button btn) { return ControllerMenuStoreMemory; }
//	inline static int OnClickButtonStoreStorage(Account* account, Button btn) { return ControllerMenuStoreStorage; }
//	inline static int OnClickButtonStoreNetwork(Account* account, Button btn) { return ControllerMenuStoreNetwork; }
//
//	static int OnClickBuyCPU(Account* account, Button btn);
//	static int OnSelectStoreCPU(Account* account, Button btn) {
//		btn.SetLabelFontColor(GreenInverted);
//		return -1;
//	}
//	// inline static int OnClick
//};
//
//
//
//
//
//class Menu {
//
//public:
//
//	// CONSTRUCTOR
//	Menu() : Buttons(std::vector<Button>()) {};
//	Menu(std::vector<Button> vButtons) : Buttons(vButtons) {};
//	Menu(Menu* menu) : Buttons(menu->Buttons) {};
//
//	// GET
//	inline std::vector<Button> GetButtons() { return Buttons; }
//
//	// SET
//	void SetButtons(std::vector<Button>* vButtons) { Buttons = *vButtons; }
//
//	// DEFAULTS INPUTS OF MENUS
//	void SwapButtonsMenuBegin(Menu* menu) {
//
//		uchar s = Button::GetMenuTag();
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"Store", Green), s, Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"Score", Green), s, Events::CloseGame));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Options", Green), s, Events::CloseGame));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Save Data", Green), s, Events::CloseGame));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Close", Green), s, Events::CloseGame));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//	//void SwapButtonsMenuStore(Menu* menu) {
//
//	//	uchar s = Button::GetMenuTag();
//	//	std::vector<Button>* Buttons = new std::vector<Button>();
//	//	Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", Green), s, Events::OnClickButtonStoreCPU));
//	//	Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", Green), s, Events::OnClickButtonStoreGPU));
//	//	Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", Green), s, Events::OnClickButtonStoreMemory));
//	//	Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", Green), s, Events::OnClickButtonStoreStorage));
//	//	Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", Green), s, Events::OnClickButtonStoreNetwork));
//	//	Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green), s, Events::MenuBegin));
//
//	//	menu->SetButtons(Buttons);
//	//	delete Buttons;
//	//}
//
//	void SwapButtonsMenuStoreCPU(Menu* menu) {
//
//		uchar s = Button::GetMenuTag();
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", GreenInverted), s ,  Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", Green)		, s ,  Events::OnClickButtonStoreGPU));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", Green)		, s ,  Events::OnClickButtonStoreMemory));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", Green)	, s ,  Events::OnClickButtonStoreStorage));
//		Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", Green)		, s ,  Events::OnClickButtonStoreNetwork));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green)		, s ,  Events::MenuBegin));
//		
//		int i = 0;
//		for (WString s : Components::GetCPUNames()) {
//			uchar Color = i == 0 ? GreenInverted : Green;
//			Buttons->push_back(Button(RECTANGLE(15, 21 - i * 3, 64, 3), Text(2, 2, s, Color), Button::GetSpecialTag(), Events::OnSelectStoreCPU));
//			++i;
//		}
//
//		Buttons->push_back(Button(RECTANGLE(73, 3, 7, 3), Text(2, 2, L"Buy", Green), Button::GetSpecialTag(), Events::OnClickBuyCPU));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//	void SwapButtonsMenuStoreGPU(Menu* menu) {
//
//		uchar s = Button::GetMenuTag();
//		
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", Green)		 , s, Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", GreenInverted) , s, Events::OnClickButtonStoreGPU));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", Green)		 , s, Events::OnClickButtonStoreMemory));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", Green)	 , s, Events::OnClickButtonStoreStorage));
//		Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", Green)		 , s, Events::OnClickButtonStoreNetwork));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green)		 , s, Events::MenuBegin));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//	void SwapButtonsMenuStoreMemory(Menu* menu) {
//
//		uchar s = Button::GetMenuTag();
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", Green)		   , s, Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", Green)		   , s, Events::OnClickButtonStoreGPU));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", GreenInverted), s, Events::OnClickButtonStoreMemory));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", Green)	   , s, Events::OnClickButtonStoreStorage));
//		Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", Green)		   , s, Events::OnClickButtonStoreNetwork));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green)		   , s, Events::MenuBegin));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//	void SwapButtonsMenuStoreStorage(Menu* menu) {
//		uchar s = Button::GetMenuTag();
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", Green), s, Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", Green), s, Events::OnClickButtonStoreGPU));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", Green), s, Events::OnClickButtonStoreMemory));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", GreenInverted), s, Events::OnClickButtonStoreStorage));
//		Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", Green), s, Events::OnClickButtonStoreNetwork));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green), s, Events::MenuBegin));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//	void SwapButtonsMenuStoreNetwork(Menu* menu) {
//		uchar s = Button::GetMenuTag();
//		std::vector<Button>* Buttons = new std::vector<Button>();
//		Buttons->push_back(Button(RECTANGLE(1, 21, 13, 3), Text(2, 2, L"CPU", Green), s, Events::OnClickButtonStoreCPU));
//		Buttons->push_back(Button(RECTANGLE(1, 18, 13, 3), Text(2, 2, L"GPU", Green), s, Events::OnClickButtonStoreGPU));
//		Buttons->push_back(Button(RECTANGLE(1, 15, 13, 3), Text(2, 2, L"Memory", Green), s, Events::OnClickButtonStoreMemory));
//		Buttons->push_back(Button(RECTANGLE(1, 12, 13, 3), Text(2, 2, L"Storage", Green), s, Events::OnClickButtonStoreStorage));
//		Buttons->push_back(Button(RECTANGLE(1, 9, 13, 3), Text(2, 2, L"Network", GreenInverted), s, Events::OnClickButtonStoreNetwork));
//		Buttons->push_back(Button(RECTANGLE(1, 3, 13, 3), Text(2, 2, L"Return", Green), s, Events::MenuBegin));
//
//		menu->SetButtons(Buttons);
//		delete Buttons;
//	}
//
//private:
//	std::vector<Button> Buttons;
//};
