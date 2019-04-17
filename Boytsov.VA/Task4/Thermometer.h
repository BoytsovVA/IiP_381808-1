#pragma once
#include <iostream>
#include <string>

using namespace std;

#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class DateThermometr
{
public:
	DateThermometr(); //Конструктор по умолчанию
	DateThermometr(int _day, int _month, int _year, int _hour, double _temperature); //Конструктор инициализатор
	~DateThermometr(); //Деструктор
	//Ввод/Вывод в поток
	friend ostream& operator<<(ostream& stream, const DateThermometr& v);
	friend istream& operator>>(istream& stream, DateThermometr& v);
	string DateThermometr::Get_DateThermometr(); //Функция возвращения даты в формате строки
	double get_temperature(); //Функция возвращает температуру
	int get_hour(); //Функция возвращает час
	bool check_DateAndHour(DateThermometr); //Функция сравнивает дату и время с поступившей от пользователя
	bool check_Date(DateThermometr); //Функция сравнивает дату с поступившей от пользователя
	bool check_Year(int _year); //Функция сравнивает год с поступившем от пользователя
	bool check_Month(int _month); //Функция сравнивает месяц с поступившем от пользователя

private:
	unsigned int day; //День наблюдения
	unsigned int month; //Месяц наблюдения 
	unsigned int year; //Год наблюдения 
	unsigned int hour; //Час наблюдения
	double temperature; //Показания термометра
};

class Thermometr
{
public:
	Thermometr(); //Конструтор по умолчанию
	Thermometr(int _size); //Конструктор инициализации
	~Thermometr(); //Деструктор
	DateThermometr FindStartDateAndTime(); //Фукция выводит на экран начальную дату и время наблюдений(1)
	void Add_Value(DateThermometr); //Функция добавляет наблюдение в историю наблюдений(2)
	double Get_Temperature(DateThermometr); //Функция возвращает температуру для выбранным дате и времени(3)
	void Get_TemperaturePerDay(DateThermometr); //Функция возвращает температуру по выбранной дате(4)
	double Get_AverageTemperaturePerDay(DateThermometr); //Функция возвращает среднюю температуру для выбранной даты(5)
	double Get_AverageTemperaturePerMonth(int Month); //Функция возвращает среднюю температуру для выбранного месяца(5)
	double Get_AverageTemperatureAll(void); //Функция возвращает среднюю температуру всего списка наблюдения(5)
	double Get_AverageTemperaturePerMonth_Day(int Month); //Функция возвращает среднюю дневную температуру для выбранного месяца(6)
	double Get_AverageTemperaturePerMonth_Night(int Month); //Функция возвращает среднюю ночьную температуру для выбранного месяца(6)
	friend ostream& operator << (ostream& stream, Thermometr const& v);
	friend istream& operator >> (istream& stream, Thermometr& v);

private:
	int size; //Реальное кол-во наблюдений
	int buf; //Максимальное кол-во наблюдений
	const int buf_Delta = 10; //Запас памяти, если size>buf
	DateThermometr* ArrayOfObservations; //Массив наблюдений
};

