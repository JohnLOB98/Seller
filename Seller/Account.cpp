#include "Account.h"


void Account::DrawMoney(ConsoleApplication* CA, const Account& account) {
	
	std::wstring s = L"₿ " + std::to_wstring(account.GetMoney());
	CA->DrawStringW(68, 20, s, Green, CA->Buffer);
}

//void Account::DrawCPUs(ConsoleApplication* CA, const Account& account) {
//
//
//}
