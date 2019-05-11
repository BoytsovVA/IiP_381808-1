#include "Client.h"
#include "DepozitBase.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ProcCenter
{
public:
	ProcCenter();
	~ProcCenter();
	ProcCenter(string);
	//Геттеры/Сеттер
	int Getsize();
	int GetСurrent_month();
	int SetCurrent_month(int);
	Client* Getbase();
	DepozitBase* GetDepozitBase();

	Client* SearchClient(int);//Ищет клиента в базе, возвращая ссылку на ячейку
	DepozitBase* SearchDepozitBase(int);//Ищет депозит клиента в базе, возвращая ссылку на ячейку
	string Getfilename();
	friend ostream & operator << (ostream & filename, const ProcCenter & v);
	friend istream & operator >> (istream & filename, ProcCenter & v);


private:
	int size;//Количество клиентов
	int Сurrent_month;//Текущий месяц
	int Current_year; //Текущий год
	Client* base;//База клиентов
	DepozitBase* DepozitBase;//База депозитов клиентов
	string filename;//Имя файла
};
