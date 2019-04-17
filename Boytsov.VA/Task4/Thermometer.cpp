#include "Thermometer.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <iomanip>
using namespace std;

DateThermometr::DateThermometr()
{
	day = month = year = hour = 0;
	temperature = 0.0;
}

DateThermometr::DateThermometr(int _day, int _month, int _year, int _hour, double _temperature)
{
	day = _day;
	month = _month;
	year = _year;
	hour = _hour;
	temperature = _temperature;
}

DateThermometr::~DateThermometr()
{
	day = NULL;
	month = NULL;
	year = NULL;
	hour = NULL;
	temperature = NULL;
}

string DateThermometr::Get_DateThermometr()
{
	string str = "";
	str += to_string(year);
	str += '.';
	if (month <= 9) {
		str += '0';
	}
	str += to_string(month);
	str += '.';
	if (day <= 9) {
		str += '0';
	}
	str += to_string(day);
	str += ' ';
	str += to_string(hour);
	str += ":00";
	return str;
}

double DateThermometr::get_temperature()
{
	return temperature;
}

int DateThermometr::get_hour()
{
	return hour;
}
bool DateThermometr::check_DateAndHour(DateThermometr v)
{
	if (day == v.day && month == v.month && year == v.year && hour == v.hour)
		return true;
	return false;
}

bool DateThermometr::check_Date(DateThermometr v)
{
	if (day == v.day && month == v.month && year == v.year)
		return true;
	return false;
}

bool DateThermometr::check_Year(int _year)
{
	if (year == _year)
		return true;
	return false;
}

bool DateThermometr::check_Month(int _month)
{
	if (month == _month)
		return true;
	return false;
}

ostream & operator<<(ostream & stream, const DateThermometr & v)
{
	stream << v.day << ' ' << v.month << ' ' << v.year << ' ' << v.hour << ' ' << v.temperature;
	return stream;
}

istream & operator>>(istream & stream, DateThermometr & v)
{
	stream >> v.day >> v.month >> v.year >> v.hour >> v.temperature;
	return stream;
}

Thermometr::Thermometr()
{
	size = 0;
	buf = 0;
	ArrayOfObservations = NULL;
}

Thermometr::Thermometr(int _size)
{
	size = _size;
	buf = _size + buf_Delta;
	ArrayOfObservations = new DateThermometr[buf];
}

Thermometr::~Thermometr()
{
	size = 0;
	buf = 0;
	delete[] ArrayOfObservations;
	ArrayOfObservations = NULL;
}

DateThermometr Thermometr::FindStartDateAndTime()
{
	return ArrayOfObservations[0];
}

void Thermometr::Add_Value(DateThermometr Value)
{
	if (size < buf) {
		ArrayOfObservations[size] = Value;
		size++;
	}
	else 
	{ //Используем вспомогательный массив для хранения данных
		int i;
		DateThermometr* ArrayOfObservations_Reserve;
		buf = buf + buf_Delta;
		ArrayOfObservations_Reserve = new DateThermometr[buf];
		for (i = 0; i < size; i++)
		{
			ArrayOfObservations_Reserve[i] = ArrayOfObservations[i];
		}
		ArrayOfObservations[size] = Value;
		delete[] ArrayOfObservations;
		ArrayOfObservations = NULL;
		size++;
		ArrayOfObservations = new DateThermometr[buf];
		for  (i = 0; i < size; i++)
		{
			ArrayOfObservations[i] = ArrayOfObservations_Reserve[i];
		}
		delete[] ArrayOfObservations_Reserve;
		ArrayOfObservations_Reserve = NULL;
	}
}

double Thermometr::Get_Temperature(DateThermometr v)
{
	bool flag = false;
	int j;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_DateAndHour(v))
		{
			flag = true;
			j = i;
		}

	}
	if (flag == true)
		return ArrayOfObservations[j].get_temperature();
	cout << "Такого наблюдения нет" << endl;
}

void Thermometr::Get_TemperaturePerDay(DateThermometr v)
{
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_Date(v))
		{
			flag = true;
			cout << ArrayOfObservations[i].Get_DateThermometr() << " Температура = " << ArrayOfObservations[i].get_temperature() << endl;
		}

	}
	if (flag == false)
	cout << "Такого наблюдения нет" << endl;
}

double Thermometr::Get_AverageTemperaturePerDay(DateThermometr v)
{
	bool flag = false;
	double result = 0.0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_Date(v))
		{
			flag = true;
			result += ArrayOfObservations[i].get_temperature();
			k++;
		}

	}
	if (flag == true)
		return result / k;
	return 0.0;
}

double Thermometr::Get_AverageTemperaturePerMonth(int Month)
{
	bool flag = false;
	double result = 0.0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_Month(Month))
		{
			flag = true;
			result += ArrayOfObservations[i].get_temperature();
			k++;
		}

	}
	if (flag == true)
		return result / k;
	return 0.0;
}

double Thermometr::Get_AverageTemperatureAll(void)
{
	bool flag = false;
	double result = 0.0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
			flag = true;
			result += ArrayOfObservations[i].get_temperature();
			k++;

	}
	if (flag == true)
		return result / k;
	return 0.0;
}

double Thermometr::Get_AverageTemperaturePerMonth_Day(int Month)
{
	bool flag = false;
	double result = 0.0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_Month(Month) && ArrayOfObservations[i].get_hour() >= 6 && ArrayOfObservations[i].get_hour() <= 18)
		{
			flag = true;
			result += ArrayOfObservations[i].get_temperature();
			k++;
		}

	}
	if (flag == true)
		return result / k;
	return 0.0;
}

double Thermometr::Get_AverageTemperaturePerMonth_Night(int Month)
{
	bool flag = false;
	double result = 0.0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (ArrayOfObservations[i].check_Month(Month) && (ArrayOfObservations[i].get_hour() < 6 || ArrayOfObservations[i].get_hour() > 18))
		{
			flag = true;
			result += ArrayOfObservations[i].get_temperature();
			k++;
		}

	}
	if (flag == true)
		return result / k;
	return 0.0;
}

ostream & operator<<(ostream & stream, Thermometr const & v)
{
	stream << v.size << endl;
	for (int i = 0; i < v.size; i++) {
		stream << v.ArrayOfObservations[i] << " " << endl;
	}
	return stream;
}

istream & operator>>(istream & stream, Thermometr & v)
{
	stream >> v.size;
	if (v.size >= v.buf)
	{
		delete[] v.ArrayOfObservations;
		v.ArrayOfObservations = NULL;
		v.buf = v.buf + v.buf_Delta;
		v.ArrayOfObservations = new DateThermometr[v.size];
	}
	for (int i = 0; i < v.size; i++)
	{
		stream >> v.ArrayOfObservations[i];
	}
	return stream;
}
