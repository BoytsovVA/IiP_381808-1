#include "Client.h"

Client::Client()
{
	Name = "<Неизвестно>";
	Surname = "<Неизвестно>";
	Patronymic = "<Неизвестно>";
	ClientPassword = "<Неизвестно>";
	SalaryAccount  = ClientCash = DepozitOpen = 0;
	ClientDepozit = 0.0;
}

Client::Client(string _Name, string _Surname, string _Patronymic, int _SalaryAccount, double _ClientDepozit, string _ClientPassword, int _ClientCash, bool _DepozitOpen)
{
	Name = _Name;
	Surname = _Surname;
	Patronymic = _Patronymic;
	SalaryAccount = _SalaryAccount;
	ClientPassword = _ClientPassword;
	ClientDepozit = _ClientDepozit;
	DepozitOpen = _DepozitOpen;
}

Client::~Client()
{
	Name = "<Неизвестно>";
	Surname = "<Неизвестно>";
	Patronymic = "<Неизвестно>";
	ClientPassword = "<Неизвестно>";
	SalaryAccount =  ClientCash = DepozitOpen = 0;
	ClientDepozit = 0.0;
}

string Client::GetNameClient()
{
	string NameClient = Name + " " + Surname + " " + Patronymic;
	return NameClient;
}

int Client::GetSalaryAccountClient()
{
	return SalaryAccount;
}

string Client::GetClientPassword()
{
	return ClientPassword;
}

int Client::GetClientCash()
{
	return ClientCash;
}

bool Client::GetDepozitOpen()
{
	return DepozitOpen;
}

void Client::SetSalaryAccountClient(int _Account)
{
	SalaryAccount = _Account;
}

void Client::SetClientPassword(string _Password)
{
	ClientPassword = _Password;
}

void Client::SetClientCash(int _Cash)
{
	ClientCash = _Cash;
}

void Client::SetDepozitOpen(bool _Open)
{
	DepozitOpen = _Open;
}

ostream & operator<<(ostream & stream, const Client & v)
{
	stream << v.Name << ' ' << v.Surname << ' ' << v.Patronymic << ' ' << v.SalaryAccount << ' ' << v.ClientPassword << ' ' << v.ClientCash << ' ' << v.DepozitOpen << ' ' << v.ClientDepozit << ' ' << endl;
	return stream;
}

istream & operator>>(istream & stream, Client & v)
{
	stream >> v.Name >> v.Surname >> v.Patronymic >> v.SalaryAccount >> v.ClientPassword >> v.ClientCash >> v.DepozitOpen >> v.ClientDepozit;
	return stream;
}
