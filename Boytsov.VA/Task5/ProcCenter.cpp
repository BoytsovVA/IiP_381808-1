#include "ProcCenter.h"

ProcCenter::ProcCenter()
{
	size = 0;
	delete[] base;
	base = nullptr;
	filename = "";
}

ProcCenter::~ProcCenter()
{
	size = 0;
	delete[] base;
	base = nullptr;
	filename = "";
}

ProcCenter::ProcCenter(string _filename)
{
	filename = _filename;
}

int ProcCenter::Getsize()
{
	return size;
}

int ProcCenter::GetСurrent_month()
{
	return Сurrent_month;
}

int ProcCenter::SetCurrent_month(int _Current_month)
{
	return _Current_month;
}

Client * ProcCenter::Getbase()
{
	return base;
}

DepozitBase * ProcCenter::GetDepozitBase()
{
	return DepozitBase;
}

Client * ProcCenter::SearchClient(int _SalaryAccount)
{
	for (int i = 0; i < size; i++)
	{
		if (_SalaryAccount == base[i].GetSalaryAccountClient())
		{
			return &base[i];
		}
	}
	return nullptr;
}

DepozitBase * ProcCenter::SearchDepozitBase(int  _log)
{
	for (int i = 0; i < size; i++)
	{
		if (_log == DepozitBase[i].Getlog())
		{
			return &DepozitBase[i];
		}
	}
	return nullptr;
}


string ProcCenter::Getfilename()
{
	return filename;
}

ostream & operator<<(ostream & filename, const ProcCenter & v)
{
	filename.clear();
	filename << v.size << endl;
	filename << v.Сurrent_month << endl;
	filename << v.Current_year << endl;
	for (int i = 0; i < (v.size); i++)
	{
		filename << v.base[i] << " ";
	}
	for (int i = (v.size); i < v.size; i++)
	{
		filename << v.DepozitBase[i] << " ";
	}
	return  filename;
}

istream & operator>>(istream & filename, ProcCenter & v)
{
	filename >> v.size;
	if (v.base != nullptr)
	{
		delete[] v.base;
	}
	v.base = new Client[v.size];
	if (v.DepozitBase != nullptr)
	{
		delete[] v.DepozitBase;
	}
	v.DepozitBase = new DepozitBase[v.size];
	filename >> v.Сurrent_month;
	filename >> v.Current_year;
	for (int i = 0; i < v.size; i++)
	{
		filename >> v.base[i];
	}
	for (int i = 0; i < v.size; i++)
	{
		filename >> v.DepozitBase[i];
	}
	return filename;
}



