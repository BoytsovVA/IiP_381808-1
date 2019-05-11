#include <string>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <clocale>
#include "Depozit.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int sum, time;
	Depozit B1;
	int answer_log;
	string answer_pas;
	char UserChoice = 1;
	cout << "Авторизация. Введите номер зарплатного счета и пароль" << endl;
	cin >> answer_log >> answer_pas;
	if (B1.Authorization(answer_log, answer_pas))
	{
		cout << "Автозизация прошла успешно" << endl;
		while (UserChoice != '0')
		{
			cout << endl;
			cout << "Список доступных действий: " << endl;
			cout << "1 - Доступные депозиты, исходя из суммы на вашем банковском счету" << endl;
			cout << "2 - Проверить наличие открытого депозита" << endl;
			cout << "3 - Открыть депозит" << endl;
			cout << "4- показать состояние депозита" << endl;
			cout << "5- снять проценты" << endl;
			cout << "6 - закрыть депозит" << endl;
			cin >> UserChoice;
			switch (UserChoice)
			{
				//case '0':
				//	break;
			case '1':
				B1.RecomendDepozit();
				break;
			case '2':
				B1.CheckOpenDepozit();
				break;
			case '3':
			{
				cout << "Введите сумму, которую хотите положить на депозит и срок" << endl;
				cin >> sum >> time;
				B1.OpenDepozit(sum, time);
				break;
			}
			case '4':
			{
				B1.LookDepozit();
				break;
			}
			case '5':
			{
				B1.WithdrawPercent();
				break;
			}
			case '6':
				B1.CloseDepozit();
				break;
			case 's':
				return 1;
			}
		}
	}
	else
	{
		cout << "Введены неверные данные" << endl;
		return 0;
	}
	system("pause");
}