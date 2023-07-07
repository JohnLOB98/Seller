#include <iostream>
#include <chrono>
#include <vector>
//#include <bind>
#include <functional>
#include "ConsoleApplication.h"
#include "Shapes.h"
//#include "Button.h"
//#include "Account.h"
#include "Element.h"

float deltaT = 0;
long long ms = 0;
std::chrono::steady_clock::time_point begin;
std::chrono::steady_clock::time_point final;
bool* KeyLeftClick;

//Account account = Account();

//int WndBegin(ConsoleApplication* CA, std::function<void(ConsoleApplication*)> DrawFixedObjects) {
//
//	int flag = -1;
//	std::vector<Element::CheckBox> PanelCH;
//	PanelCH.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 20, 10, 13, 3, Green, GreenInverted));
//	PanelCH.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 33, 10, 13, 3, Green, GreenInverted));
//	PanelCH.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 46, 10, 13, 3, Green, GreenInverted));
//	
//	Element::PanelCheckBox panel = Element::PanelCheckBox(L"", L"", L"", 20, 10, 39, 3, PanelCH);
//
//	std::vector<Element::Button> Buttons;
//	Buttons.push_back(Element::Button(L"Store", L"", L"", 1, 21, 13, 3, Green));
//	Buttons.push_back(Element::Button(L"Score", L"", L"", 1, 18, 13, 3, Green));
//	Buttons.push_back(Element::Button(L"Options", L"", L"", 1, 15, 13, 3, Green));
//	Buttons.push_back(Element::Button(L"Save Data", L"", L"", 1, 12, 13, 3, Green));
//	Buttons.push_back(Element::Button(L"Close", L"", L"", 1, 3, 13, 3, Green));
//
//	while (flag == -1) {
//		begin = std::chrono::high_resolution_clock::now();
//		//int r = ms == 0 ? 0 : 1000 / ms ;
//		ms = 0;
//
//		// INPUTS
//		// REFERENCE https://learn.microsoft.com/en-us/windows/console/mouse-event-record-str?redirectedfrom=MSDN
//		panel = panel.OnClick(KeyLeftClick);
//
//
//		// UPDATE
//		CA->ClearBuffer(CA->Buffer);
//		DrawFixedObjects(CA);
//		for (Element::Button btn : Buttons) btn.DrawButton( CA->Buffer );
//		//for (Button btn : menu->GetButtons()) btn.DrawButton(CA->Buffer, btn.GetText().GetFontColor());
//		for (Element::CheckBox ch : panel.GetListCheckBox()) ch.DrawCheckBox(CA->Buffer);
//
//		//RENDER
//		WriteConsoleOutput(CA->hout, CA->Buffer, CA->dwBufferSize, CA->dwBufferCoord, &CA->lpWriteRegion);
//		Sleep(1);
//		final = std::chrono::high_resolution_clock::now();
//		ms += std::chrono::duration_cast<std::chrono::milliseconds>(final - begin).count();		
//	}
//
//	return flag;
//}

uchar StartMenuPrincipal(ConsoleApplication* CA, bool* vKey) {

	MenuPrincipal MP = MenuPrincipal(CA, vKey);
	MP.SetActiveMenu(ControllerMenuPrincipal);

	while (MP.GetActiveMenu() == ControllerMenuPrincipal) {

		MP.Inputs();
		MP.Update();
		MP.Render();
	}

	return MP.GetActiveMenu();
}

uchar StartMenuStore(ConsoleApplication* CA, bool* vKey, int Controller = ControllerMenuStoreCPU) {

	MenuStore MP = MenuStore(CA, vKey);
	MP.SetActiveMenu(Controller);

	while (MP.GetActiveMenu() == Controller) {

		MP.Inputs();
		MP.Update();
		MP.Render();
	}

	return MP.GetActiveMenu();
}

int main() {

	ConsoleApplication* CA = new ConsoleApplication();
	uchar x = ControllerMenuPrincipal;

	KeyLeftClick = new bool;
	*KeyLeftClick = false;

	do {
		switch (x) {
			case ControllerMenuPrincipal:
				//Sleep(500);
				x = StartMenuPrincipal(CA, KeyLeftClick);
				break;

			case ControllerMenuStoreCPU:
				//Sleep(500);
				x = StartMenuStore(CA, KeyLeftClick);
				//menu->SwapButtonsMenuStoreCPU(menu);
				//x = WndBegin(CA, ConsoleApplication::DrawWndStore);

				break;
			case ControllerMenuStoreGPU:
				//menu->SwapButtonsMenuStoreGPU(menu);
				//x = WndBegin(CA, ConsoleApplication::DrawWndStore);
				break;

			case ControllerMenuStoreMemory:
				//menu->SwapButtonsMenuStoreMemory(menu);
				//x = WndBegin(CA, ConsoleApplication::DrawWndStore);
				break;

			case ControllerMenuStoreStorage:
				//menu->SwapButtonsMenuStoreStorage(menu);
				//x = WndBegin(CA, ConsoleApplication::DrawWndStore);
				break;		
			case ControllerMenuStoreNetwork:
				//menu->SwapButtonsMenuStoreNetwork(menu);
				//x = WndBegin(CA, ConsoleApplication::DrawWndStore);
				break;

			default:
				break;
		}
	} while (x != ControllerCloseGame);

	return 1;
}