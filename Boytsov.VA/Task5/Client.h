#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Client
{
public:
	//Конструкторы и деструктор
	Client();
	Client(string, string, string, int, double, string, int, bool);
	~Client();
	friend ostream &operator << (ostream & stream, const Client & v);
	friend istream &operator >> (istream & stream, Client & v);
	//Геттеры
	string GetNameClient();
	int GetSalaryAccountClient();
	string GetClientPassword();
	int GetClientCash();
	bool GetDepozitOpen();
	//Сеттеры
	void SetSalaryAccountClient(int);
	void SetClientPassword(string);
	void SetClientCash(int);
	void SetDepozitOpen(bool);
private:
	//ФИО
	string Name;
	string Surname;
	string Patronymic;

	int SalaryAccount; //Номер зарплатного счёта клиента
	string ClientPassword; //Пароль клиента
	int ClientCash; //Сумма на зарплатном счету клиента
	double ClientDepozit;//Сумма на депозите
	bool DepozitOpen; //1 - депозит открыт, 0 - депозит закрыт

};
