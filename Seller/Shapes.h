#pragma once
#include <windows.h>
#include <vector>
#include "ConsoleApplication.h"

class RECTANGLE {

public:

	// CONSTRUCTOR
	RECTANGLE() : RECTANGLE(0, 0, 0, 0) {};
	RECTANGLE(int Vx, int Vy, int VW, int VH): x(Vx), y(Vy), W(VW), H(VH) {};
	//~RECTANGLE();
	
	// SET
	void SetX(int v) { x = v; }
	void SetY(int v) { y = v; }
	void SetWidth(int v) { W = v; }
	void SetHeight(int v) { H = v; }
	
	// GET
	inline int GetX() const { return x; }
	inline int GetY() const { return y; }
	inline int GetWidth() const { return W; }
	inline int GetHeight() const { return H; }

private:
	int x, y, W, H;
};

class iCPU {
public:

	iCPU(WString vName, uchar vAmount): Name(vName), Amount(vAmount) {}
	
	void SetName(WString vName) { Name = vName; }
	void SetAmount(uchar vAmount) { Amount = vAmount; }

	WString GetName() { return Name; }
	uchar GetAmount() { return Amount; }

private:
	WString Name;
	uchar Amount;
};


class Components {
public:

	// CONSTRUCTOR
	Components(): Components(L"Corei3 Gen 10th", L"NVidia GT 730", 8, 1, 128, 60) {};
	Components(WString VCPU, WString VGPU, int VMemory, int VMemorySlots, int VStorage, int VNetwork)
		: CPU(VCPU), GPU(VGPU), Memory(VMemory), MemorySlots(VMemorySlots), Storage(VStorage), Network(VNetwork) {};

	// SET
	void SetCPU(WString VCPU) { CPU = VCPU; }
	void SetGPU(WString VGPU) { GPU = VGPU; }
	void SetMemory(int VMemory) { Memory = VMemory; }
	//void SetMemorySlots(int VMemorySlots) { MemorySlots = VMemorySlots; }
	void SetStorage(int VStorage) { Storage = VStorage; }
	void SetNetwork(int VNetwork) { Network = VNetwork; }

	// GET
	inline WString GetCPU() const { return CPU; } // Corei3, Corei5, Corei7, Corei9 (All 10th Generation)
	inline WString GetGPU() const { return GPU; } // Nvidia GT 730, Nvidia GT 1030, Nvidia GTX 1660, Nvidia RTX 3060, Nvidia RTX 4060, Nvidia RTX 4070, Nvidia RTX 4090
	inline int GetMemory() const { return Memory; } // 8GB, 16GB, 32GB, 64GB, 128GB 
	//inline int GetMemorySlots() const { return MemorySlots; } // 1
	inline int GetStorage() const { return Storage; } // 128GB, 256GB, 512GB, 1024GB(1TB), 2048GB(2TB) // https://www.kingston.com/en/blog/pc-performance/ssd-form-factors
	inline int GetNetwork() const { return Network; } // 60MB, 80MB, 100BM, 300MB, 750MB, 1024MB(1GB)

	// EXISTING ITEMS
	//static std::vector<WString> GetCPUNames() {
	//	std::vector<WString> CPUNames;
	//	CPUNames.push_back(L"Intel Corei3 10th");
	//	CPUNames.push_back(L"Intel Corei5 10th");
	//	CPUNames.push_back(L"Intel Corei7 10th");
	//	CPUNames.push_back(L"Intel Corei9 10th");

	//	return CPUNames;
	//}

	static WString GetItem(WString StoreMenu, int id) {
		
		WString x = L"Null";
		if (StoreMenu == L"CPU") x = GetCPUName(id);
		else if (StoreMenu == L"GPU") x = GetGPUName(id);
		return x;
	}

	static WString GetCPUName(int id) {
		switch (id) {
		case 1: return L"Intel Corei3 10th";
		case 2: return L"Intel Corei5 10th";
		case 3: return L"Intel Corei7 10th";
		case 4: return L"Intel Corei9 10th";
			default:
				return L"Unable";
		}
	}

	static WString GetGPUName(int id) {
		switch (id) {
		case 1: return L"Nvidia GT 730";
		case 2: return L"Nvidia GT 1030";
		case 3: return L"Nvidia GTX 1660";
		case 4: return L"Nvidia RTX 3060";
		case 5: return L"Nvidia RTX 4060";
		case 6: return L"Nvidia RTX 4070";
		case 7: return L"Nvidia RTX 4090";
		default:
			return L"Unable";
		}
	}

	static int GetCostCPU(WString vName) {
		if (vName == L"Intel Corei3 10th") return 300;
		else if (vName == L"Intel Corei5 10th") return 350;
		else if (vName == L"Intel Corei7 10th") return 350;
		else if (vName == L"Intel Corei9 10th") return 400;
		
		return 0;
	}

private:
	WString CPU, GPU;
	int MemorySlots, Memory, Storage, Network;
};

class Computer {

public:

	static const int Width = 10;

	// CONSTRUCTORS
	Computer() : Computer(Components::Components(), 10, 10, 0, 100, 1) {};
	Computer(int VCoordX, int VCoordY, int Vx, int Vxt, int vDelta): Computer(Components::Components(), VCoordX, VCoordY, Vx, Vxt, vDelta) {};
	Computer(Components VComponents, int VCoordX, int VCoordY, int Vx, int Vxt, int VDelta): Components(VComponents), CoordX(VCoordX), CoordY(VCoordY), x(Vx), xt(Vxt), Delta(VDelta) {};

	// GET
	inline int GetCoordX() { return CoordX; }
	inline int GetCoordY() { return CoordY; }
	inline int GetX() { return x; }
	inline int GetXTotal() { return xt; }
	inline int GetDelta() { return Delta; }

	// DRAW
	static CHAR_INFO* DrawBar(const Computer& computer, CHAR_INFO* buffer, int CoordX, int CoordY);

private:
	Components Components;
	int CoordX, CoordY, x, xt, Delta;
};




