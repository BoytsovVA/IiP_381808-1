#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class DepozitBase
{
public:
	//Конструкторы и деструктор
	DepozitBase();
	DepozitBase(int, int, bool, int, double, int);
	~DepozitBase();
	//Геттеры
	int Getlog();
	int GetFirst_month();
	bool GetCheckDepozit();
	int GetInitial_Summ();
	double GetPercent_Summ();
	double GetTerm_of_Depozit();
	//Сеттеры
	void Setlog(int);
	void SetFirst_month(int);
	void SetCheckDepozit(bool);
	void SetInitial_Summ(int);
	void SetPercent_Summ(double);
	void SetTerm_of_Depozit(int);
	friend ostream &operator << (ostream & stream, const DepozitBase & v);
	friend istream &operator >> (istream & stream, DepozitBase & v);

private:
	int log;//Номер счёта клиента
	int First_month;//Первый месяц депозита
	bool CheckDepozit;//1 - депозит открыт, 0 - депозит не открыт
	int Initial_Summ;//Сумма, внесенная на депозит
	double Percent_Summ;//Ежемесячные проценты
	int Term_of_Depozit;//Срок депозита
};

