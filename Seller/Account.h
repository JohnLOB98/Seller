#pragma once
#include <vector>
#include "Shapes.h"
#include "ConsoleApplication.h"

typedef unsigned long long uint64;
typedef unsigned int uint32;

class Account {
public:

	static const int LimitComputers = 3;

	// CONSTRUCTOR
	Account(): Account(1000) {};
	Account(uint64 vMoney): Money(vMoney), Computers(std::vector<Computer>()), holdCPU(std::vector<iCPU>()) {};
	
	// SET 
	void SetMoney(uint64 vMoney) { Money = vMoney; }
	void SetComputers(Computer vComputer) { Computers.push_back(vComputer); }
	
	// GET 
	inline int GetMoney() const { return Money; }
	inline std::vector<Computer> GetComputers() const { return Computers; }
	//inline int GetNumberComputers() const { return GetComputers().size() / sizeof(Computers); }
	inline int GetCostNewComputer() const { return 1000 + GetComputers().size() * 5000; }
	
	// DRAW 
	void DrawMoney(ConsoleApplication* CA, const Account& account);
	//void DrawCPUs(ConsoleApplication* CA, const Account& account);
	
private:
	uint64 Money;
	std::vector<Computer> Computers;
	std::vector<iCPU> holdCPU;
};