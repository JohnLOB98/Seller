#pragma once
//#include <sqlite3.h>

class Element {
public:

	static WString ActiveWindow;

	static bool GetKeyUp(int VK, bool* Key) {
		if (GetKeyState(VK) < 0) *Key = true;
		else if (*Key) {
			*Key = false;
			return true;
		}
		return false;
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class Button {
		public:

			// CONSTRUCTOR
			//Button(): Text(L""), Name(L""), Tag(L""), CoordX(0), CoordY(0), Width(0), Height(0), FontColor(Black) {};
			Button(WString vText, WString vName, WString vTag, uchar vCoordX, uchar vCoordY, uchar vWidth, uchar vHeight, uchar vFontColor):
				Text(vText), Name(vName), Tag(vTag), CoordX(vCoordX), CoordY(vCoordY), Width(vWidth), Height(vHeight), FontColor(vFontColor) {};

			//Button(WString vText, WString vName, WString vTag, uchar vCoordX, uchar vCoordY, uchar vWidth, uchar vHeight, uchar vFontColor)> vFunction) :
			//	Text(vText), Name(vName), Tag(vTag), CoordX(vCoordX), CoordY(vCoordY), Width(vWidth), Height(vHeight), FontColor(vFontColor), OnClick(vFunction)  {};

			
			// GET
			uchar GetFontColor() { return this->FontColor; }

			// SET 

			// DEFAULT TRIGGERS


			// DRAW BUTTON
			void DrawButton(CHAR_INFO* buffer) {

				int x = this->CoordX;
				int y = this->CoordY;
				int Width = this->Width;
				uchar FontColor = this->FontColor;

				WString s1 = L"│ " + this->Text;
				int l = s1.length();
				for (int i = 0; i <= Width - 2 - l; ++i) s1 += L" ";
				s1 += L"│";

				WString s0 = L"┌";
				for (int i = 0; i < Width - 2; ++i) s0 += L'─';
				s0 += L"┐";

				WString s2 = L"└";
				for (int i = 0; i < Width - 2; ++i) s2 += L'─';
				s2 += L"┘";

				//this->CA
				ConsoleApplication* CA = (ConsoleApplication*)malloc(sizeof(ConsoleApplication));
				CA->DrawStringW(x, y, s0, FontColor, buffer);
				CA->DrawStringW(x, y - 1, s1, FontColor, buffer);
				CA->DrawStringW(x, y - 2, s2, FontColor, buffer);

				free(CA);
			}

			// CUSTOM FUNTIONS

			template<typename F>
			void OnClick(bool* key, F function) {

				CONSOLE_SELECTION_INFO PCSI = {};
				COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };

				int x = cor.X;
				int y = cor.Y;

				int mx = this->CoordX;
				int my = this->CoordY;
				int mW = this->Width;
				int mH = this->Height;

				if (x >= mx && x < mx + mW && y >= 22 - my && y < 22 - my + mH && GetKeyUp(FROM_LEFT_1ST_BUTTON_PRESSED, key)) {
					function();
				}
			}

			
			
		private:
			WString Text, Name, Tag;
			uchar CoordX, CoordY, Width, Height, FontColor;
			//std::function<void(void)> OnClick;
	};


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class Label {

	};


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class CheckBox {
	public:

		CheckBox() : CheckBox(false, L"", L"", L"", 0, 0, 0, 0, Green, GreenInverted) {};
		CheckBox(bool vFlag, WString vText, WString vName, WString vTag, uchar vCoordX, uchar vCoordY, uchar vWidth, uchar vHeight, uchar vFontColor, uchar vFlagTrueColor):
			Flag(vFlag), Text(vText), Name(vName), Tag(vTag), CoordX(vCoordX), CoordY(vCoordY), Width(vWidth), Height(vHeight), FontColor(vFontColor), FlagTrueColor(vFlagTrueColor) {};

		bool GetKeyUp(int VK, bool* Key) {
				if (GetKeyState(VK) < 0) *Key = true;
				else if (*Key) {
					*Key = false;
					return true;
				}
				return false;
		}

		void DrawCheckBox(CHAR_INFO* buffer) {
			int x = this->CoordX;
			int y = this->CoordY;
			int Width = this->Width;
			uchar color = this->Flag ? this->FlagTrueColor : this->FontColor;

			WString s1 = L"│ " + this->Text;
			int l = s1.length();
			for (int i = 0; i <= Width - 2 - l; ++i) s1 += L" ";
			s1 += L"│";

			WString s0 = L"┌";
			for (int i = 0; i < Width - 2; ++i) s0 += L'─';
			s0 += L"┐";

			WString s2 = L"└";
			for (int i = 0; i < Width - 2; ++i) s2 += L'─';
			s2 += L"┘";

			ConsoleApplication* CA = (ConsoleApplication*)malloc(sizeof(ConsoleApplication));
			CA->DrawStringW(x, y, s0, color, buffer);
			CA->DrawStringW(x, y - 1, s1, color, buffer);
			CA->DrawStringW(x, y - 2, s2, color, buffer);

			free(CA);
		}


		// SET/GET
		void SetFlag(bool vFlag) {
			this->Flag = vFlag;
		}
		bool GetFlag() { return Flag; }

		uchar GetCoordX() { return CoordX; }
		uchar GetCoordY() { return CoordY; }
		uchar GetWidth() { return Width; }
		uchar GetHeight() { return Height; }

		WString GetText() { return Text; }

		//CheckBox OnClick(bool* key) {

		//		CONSOLE_SELECTION_INFO PCSI = {};
		//		COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };

		//		int x = cor.X;
		//		int y = cor.Y;

		//		int mx = this->CoordX;
		//		int my = this->CoordY;
		//		int mW = this->Width;
		//		int mH = this->Height;

		//		if (x >= mx && x < mx + mW && y >= 22 - my && y < 22 - my + mH) {
		//			this->Flag = !this->Flag;
		//		}

		//	return *this;
		//}

		template<typename F>
		void OnClick(bool* vKey, F function) {
			CONSOLE_SELECTION_INFO PCSI = {};
			COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };

			int x = cor.X;
			int y = cor.Y;

			int mx = this->CoordX;
			int my = this->CoordY;
			int mW = this->Width;
			int mH = this->Height;

			if (x >= mx && x < mx + mW && y >= 22 - my && y < 22 - my + mH) {
				this->Flag = !this->Flag;
				function();
			}
		}

		template<typename F>
		void OnClickInPanel(F funciton) {
			
		}

	private:
		bool Flag;
		WString Text, Name, Tag;
		uchar CoordX, CoordY, Width, Height;
		uchar FontColor, FlagTrueColor;
		//std::function<CheckBox()> Event;

	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class PanelCheckBox {
	public:

		// CONSTRUCTOR
		PanelCheckBox(): Element::PanelCheckBox(L"", L"", L"", 0, 0, 0, 0, std::vector<CheckBox>()) {};
		PanelCheckBox(WString vText, WString vName, WString vTag, uchar vCoordX, uchar vCoordY, uchar vWidth, uchar vHeight, std::vector<CheckBox> vListCheckBox):
			Text(vText), Name(vName), Tag(vTag), CoordX(vCoordX), CoordY(vCoordY), Width(vWidth), Height(vHeight), ListCheckBox(vListCheckBox) {};

		// GET
		std::vector<CheckBox> GetListCheckBox() { return this->ListCheckBox; }
		bool GetKeyUp(int VK, bool* Key) {
			if (GetKeyState(VK) < 0) *Key = true;
			else if (*Key) {
				*Key = false;
				return true;
			}
			return false;
		}

		// DRAW
		void DrawPanelChechBox(CHAR_INFO* buffer) {
			for (CheckBox cb : this->ListCheckBox) {
				cb.DrawCheckBox(buffer);
			}
		}

		// EVENTS 
		//void OnClick()
		//template<typename F>
		void OnClick(bool* key) {

			//bool flag = false;
			//if (GetKeyUp(FROM_LEFT_1ST_BUTTON_PRESSED, key)) {
				CONSOLE_SELECTION_INFO PCSI = {};
				COORD cor = GetConsoleSelectionInfo(&PCSI) ? COORD{ PCSI.dwSelectionAnchor.X, PCSI.dwSelectionAnchor.Y } : COORD{ 0, 0 };
				int x = cor.X;
				int y = cor.Y;

				for (int i = 0; i < ListCheckBox.size(); ++i) {

					int mx = ListCheckBox[i].GetCoordX();
					int my = ListCheckBox[i].GetCoordY();
					int mw = ListCheckBox[i].GetWidth();
					int mH = ListCheckBox[i].GetHeight();
					if (x >= mx && x < mx + mw && y >= 22 - my && y < 22 - my + mH && GetKeyUp(FROM_LEFT_1ST_BUTTON_PRESSED, key)) {

						for (int ii = 0; ii < ListCheckBox.size(); ++ii) {
							ListCheckBox[ii].SetFlag(false);
						}

						ListCheckBox[i].SetFlag(true);
					}
				}
			//}
		}

		// UTILITY
		CheckBox GetActiveCheckBox() {
			for (CheckBox ch : ListCheckBox) {
				if (ch.GetFlag()) return ch;
			}
		}

	private:
		WString Text, Name, Tag;
		uchar CoordX, CoordY, Width, Height;
		std::vector<CheckBox> ListCheckBox;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class Panel {
		
	};

};

class Menu {
public:

	// CONSTRUCTOR

	// SET
	void SetActiveMenu(uchar vActiveMenu) { this->ActiveMenu = vActiveMenu; }

	// GET
	uchar GetActiveMenu() { return this->ActiveMenu; }

	// TRIGGERS

private:
	uchar ActiveMenu;
};



class MenuPrincipal : public Menu {
public:
	
	// CONSTRUCTOR
	//MenuPrincipal() {};
	MenuPrincipal(ConsoleApplication* vCA, bool* vKey) :
		CA(vCA),
		KeyLeftMouse(vKey),
		btnStore(Element::Button(L"Store", L"", L"", 1, 21, 13, 3, Green)),
		btnRegister(Element::Button(L"Register", L"", L"", 1, 18, 13, 3, Green)),
		btnOptions(Element::Button(L"Options", L"", L"", 1, 15, 13, 3, Green)),
		btnSaveData(Element::Button(L"Save Data", L"", L"", 1, 12, 13, 3, Green)),
		btnClose(Element::Button(L"Close", L"", L"", 1, 3, 13, 3, Green))
		//PanelCheckBox1(Element::PanelCheckBox())

	{

		//std::vector<Element::CheckBox> ListCheckBox;
		//ListCheckBox.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 20, 10, 13, 3, Green, GreenInverted));
		//ListCheckBox.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 33, 10, 13, 3, Green, GreenInverted));
		//ListCheckBox.push_back(Element::CheckBox(false, L"Prueba", L"", L"", 46, 10, 13, 3, Green, GreenInverted));
		//PanelCheckBox1 = Element::PanelCheckBox(L"", L"", L"", 20, 10, 39, 3, ListCheckBox);
	};

	void Inputs() {

		OnClick_btnClose();
		OnClick_btnStore();

		//PanelCheckBox1[0]

		//PanelCheckBox1.OnClick(KeyLeftMouse);
	}

	void Update() {

		CA->ClearBuffer(CA->Buffer);
		DrawStaticMaterial();

		btnStore.DrawButton(this->CA->Buffer);
		btnRegister.DrawButton(this->CA->Buffer);
		btnOptions.DrawButton(this->CA->Buffer);
		btnSaveData.DrawButton(this->CA->Buffer);
		btnClose.DrawButton(this->CA->Buffer);



		//PanelCheckBox1.DrawPanelChechBox(this->CA->Buffer);
	}

	void Render() {
		WriteConsoleOutput(CA->hout, CA->Buffer, CA->dwBufferSize, CA->dwBufferCoord, &CA->lpWriteRegion);
		Sleep(1);
	}

	// CUSTOM TRIGGERS
	void OnClick_btnClose() {
		this->btnClose.OnClick(KeyLeftMouse, [this]() { this->SetActiveMenu(ControllerCloseGame); });
	}
	void OnClick_btnStore() {
		this->btnStore.OnClick(KeyLeftMouse, [this]() {this->SetActiveMenu(ControllerMenuStoreCPU); });
	}


	// CONSTANT MATERIAL TO DRAW
	void DrawStaticMaterial() {

		uchar bufferHeight = this->CA->bufferHeight - 1;
		uchar bufferWidth = this->CA->bufferWidth - 1;
		uchar height = bufferHeight - 1;
		uchar width = bufferWidth - 1;


		CA->DrawStringW(2, 20, L"C:\\Start>", Green, CA->Buffer);

		CA->DrawStringVerticalyW(0, 1, height, L'║', Green, CA->Buffer);
		CA->DrawStringVerticalyW(bufferWidth, 1, height, L'║', Green, CA->Buffer);
		CA->DrawStringVerticalyW(14, 1, height, L'║', Green, CA->Buffer);

		CA->DrawStringHorizontallyW(1, 0, width, L'═', Green, CA->Buffer);
		CA->DrawStringHorizontallyW(1, bufferHeight, width, L'═', Green, CA->Buffer);

		CA->DrawCharW(14, 0, L'╩', Green, CA->Buffer);
		CA->DrawCharW(14, bufferHeight, L'╦', Green, CA->Buffer);

		CA->DrawCharW(0, 0, L'╚', Green, CA->Buffer);
		CA->DrawCharW(bufferWidth, 0, L'╝', Green, CA->Buffer);
		CA->DrawCharW(0, bufferHeight, L'╔', Green, CA->Buffer);
		CA->DrawCharW(bufferWidth, bufferHeight, L'╗', Green, CA->Buffer);
	}

private:

	// SCREEN
	ConsoleApplication* CA;

	// ELEMENTS
	//Element::PanelCheckBox PanelCheckBox1;
	Element::Button btnStore;
	Element::Button btnRegister;
	Element::Button btnOptions;
	Element::Button btnSaveData;
	Element::Button btnClose;
	
	// KEYS
	bool* KeyLeftMouse;
	
};

class MenuStore : public Menu {
public:

	// DEFAULT CONSTRUCTOR
	MenuStore(ConsoleApplication* vCA, bool* vKey) :
		CA(vCA),
		KeyLeftMouse(vKey),
		Page(1),
		PanelCheckBox1(Element::PanelCheckBox()), 
		PanelCheckBox2(Element::PanelCheckBox()), 
		btnReturn(Element::Button(L"Return", L"", L"", 1, 3, 13, 3, Green)),
		btnBuy(Element::Button(L"Buy", L"", L"", 73, 3, 7, 3, Green))
	{

		std::vector<Element::CheckBox> ListCheckBox;
		ListCheckBox.push_back(Element::CheckBox(true, L"CPU", L"", L"", 1, 21, 13, 3, Green, GreenInverted));
		ListCheckBox.push_back(Element::CheckBox(false, L"GPU", L"", L"", 1, 18, 13, 3, Green, GreenInverted));
		ListCheckBox.push_back(Element::CheckBox(false, L"Memory", L"", L"", 1, 15, 13, 3, Green, GreenInverted));
		ListCheckBox.push_back(Element::CheckBox(false, L"Storage", L"", L"", 1, 12, 13, 3, Green, GreenInverted));
		ListCheckBox.push_back(Element::CheckBox(false, L"Network", L"", L"", 1, 9, 13, 3, Green, GreenInverted));
		PanelCheckBox1 = Element::PanelCheckBox(L"", L"", L"", 1, 21, 13, 15, ListCheckBox); // CAMBIAR DIMENSIONES

		std::vector<Element::CheckBox> ListCheckBox2;
		for (int i = Page; i < Page + 4; ++i)
			ListCheckBox2.push_back(Element::CheckBox(i == Page ? true : false, Components::GetItem(L"CPU", i), L"", L"", 15, 24 - i * 3, 65, 3, Green, GreenInverted));

		PanelCheckBox2 = Element::PanelCheckBox(L"", L"", L"", 15, 21, 65, 12, ListCheckBox2); // CAMBIAR DIMENSIONES
	};

	void Inputs() {

		OnClick_ReturnPrincipalMenu();
		OnClick_Buy();

		PanelCheckBox1.OnClick(KeyLeftMouse);
		PanelCheckBox2.OnClick(KeyLeftMouse);

		//PanelCheckBox1.OnClick(KeyLeftMouse);
		//PanelCheckBox2.OnClick(KeyLeftMouse);
	}

	void Update() {

		CA->ClearBuffer(CA->Buffer);

		DrawStaticMaterial();

		btnReturn.DrawButton(CA->Buffer);
		btnBuy.DrawButton(CA->Buffer);
		PanelCheckBox1.DrawPanelChechBox(this->CA->Buffer);
		PanelCheckBox2.DrawPanelChechBox(this->CA->Buffer);

		WString txt = PanelCheckBox2.GetActiveCheckBox().GetText();
		CA->DrawStringW(16, 3, txt, Green, CA->Buffer);
	}

	void Render() {
		WriteConsoleOutput(CA->hout, CA->Buffer, CA->dwBufferSize, CA->dwBufferCoord, &CA->lpWriteRegion);
		Sleep(1);
	}


	// CUSTOM TRIGGERS	
	void OnClick_ReturnPrincipalMenu() {
		this->btnReturn.OnClick(KeyLeftMouse, [this]() { this->SetActiveMenu(ControllerMenuPrincipal); });
	}

	void OnClick_Buy() {

		this->btnBuy.OnClick(KeyLeftMouse, [this]() {

			if (ValidateSelectAnItem()) {
				WString item = GetNameSelectItem();
			}
		});
	}

	// CONSTANT MATERIAL TO DRAW
	void DrawStaticMaterial() {
		CA->DrawWndStore(CA);
	}

	//UTILITY
	bool ValidateSelectAnItem() {
		for (Element::CheckBox ch : PanelCheckBox2.GetListCheckBox()) {
			if (ch.GetFlag()) return true;
		}

		return false;
	}

	WString GetNameSelectItem() {
		for (Element::CheckBox ch : PanelCheckBox2.GetListCheckBox()) {
			if (ch.GetFlag()) return ch.GetText();
		}
	}


private:

	// SCREEN
	ConsoleApplication* CA;

	// ELEMENTS
	Element::PanelCheckBox PanelCheckBox1;
	Element::PanelCheckBox PanelCheckBox2;
	Element::Button btnReturn;
	Element::Button btnBuy;

	// KEYS
	bool* KeyLeftMouse;

	// PAGE
	int Page; // To controll the display of the items  
};
