#include "Thermometer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Thermometr Ther1;
	DateThermometr value;
	int day, month, year, hour;
	double temp;
	cout << "Введите общее количество наблюдений и заполните историю наблюдений" << endl;
	cin >> Ther1;
	char UserChoice = 1;
	while (UserChoice != '0')
	{
		cout << "Выберите действие:" << endl;
		cout << "1 - Узнать начальные дату и время наблюдений" << endl;
		cout << "2 - Добавить наблюдение" << endl;
		cout << "3 - Узнать температуру в наблюдении, выбранном по дате и времени" << endl;
		cout << "4 - Выдать серию наблюдений для выбранной даты" << endl;
		cout << "5 - Найти среднюю температуру для выбранной даты" << endl;
		cout << "6 - Найти среднюю температуру для выбранного месяца" << endl;
		cout << "7 - Найти среднюю температуру за всю историю наблюдений" << endl;
		cout << "8 - Найти среднюю дневную температуру для выбранного месяца" << endl;
		cout << "9 - Найти среднюю ночную температуру для выбранного месяца" << endl;
		cout << "s - Сохранить данные в файл" << endl;
		cout << "0 - Выход из программы" << endl;
		cin >> UserChoice;
		switch (UserChoice)
		{
		//case '0':
		//	break;
		case '1':
			cout << "Начальная дата наблюдений: " << Ther1.FindStartDateAndTime() <<  endl;
			break;
		case '2':
			cout << "Введите новое наблюдение: " << endl;
			cin >> value;
			Ther1.Add_Value(value);
			break;
		case '3' :
		{
			cout << "Введите дату и время: " << endl;
			cin >> day >> month >> year >> hour;
			DateThermometr Test1(day, month, year, hour, 0.0);
			cout << "Температура в выбранную дату = " << Ther1.Get_Temperature(Test1) << endl;
			break;
		}
		case '4' :
		{
			cout << "Введите дату: " << endl;
			cin >> day >> month >> year;
			DateThermometr Test2(day, month, year, 0, 0.0);
			Ther1.Get_TemperaturePerDay(Test2);
			break;
		}
		case '5':
		{
			cout << "Введите дату: " << endl;
			cin >> day >> month >> year;
			DateThermometr Test3(day, month, year, 0, 0.0);
			cout << "Средняя температура для выбранной даты = " << Ther1.Get_AverageTemperaturePerDay(Test3) << endl;
			break;
		}
		case '6':
			cout << "Введите месяц: " << endl;
			cin >> month;
			cout << "Средняя температура для выбранного месяца = " << Ther1.Get_AverageTemperaturePerMonth(month) << endl;
			break;
		case '7':
			cout << "Средняя температура всего списка наблюдений = " << Ther1.Get_AverageTemperatureAll() << endl;
			break;
		case '8':
			cout << "Введите месяц: " << endl;
			cin >> month;
			cout << "Средняя дневная температура для выбранного месяца = " << Ther1.Get_AverageTemperaturePerMonth_Day(month) << endl;
			break;
		case '9':
			cout << "Введите месяц: " << endl;
			cin >> month;
			cout << "Средняя ночная температура для выбранного месяца = " << Ther1.Get_AverageTemperaturePerMonth_Night(month) << endl;
			break;
		case 's'://Сохранение данных в файл
		{
			ofstream os;
			os.open("file1.txt");
			os << Ther1;
			os.close();
			break;
		}
		default:
			break;
		}
	}
	Thermometr Test4;
	ifstream is;
	is.open("file2.txt");
	is >> Test4;
	is.close();
	cout << "Данные из файла : " << endl << Test4 << endl;
	system("pause");
}