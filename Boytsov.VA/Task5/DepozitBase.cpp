#include "DepozitBase.h"

DepozitBase::DepozitBase()
{
	log= First_month = CheckDepozit = Initial_Summ = Term_of_Depozit = 0;
	Percent_Summ = 0.0;
}

DepozitBase::DepozitBase(int _log, int _First_month, bool _CheckDepozit, int _Initial_Summ, double _Percent_Summ, int _Term_of_Depozit)
{
	log = _log;
	First_month = _First_month;
	CheckDepozit = _CheckDepozit;
	Initial_Summ = _Initial_Summ;
	Percent_Summ = _Percent_Summ;
	Term_of_Depozit = _Term_of_Depozit;
}

DepozitBase::~DepozitBase()
{
	log = First_month = CheckDepozit = Initial_Summ = Term_of_Depozit = 0;
	Percent_Summ = 0.0;
}

int DepozitBase::Getlog()
{
	return log;
}

int DepozitBase::GetFirst_month()
{
	return First_month;
}

bool DepozitBase::GetCheckDepozit()
{
	return CheckDepozit;
}

int DepozitBase::GetInitial_Summ()
{
	return Initial_Summ;
}

double DepozitBase::GetPercent_Summ()
{
	return Percent_Summ;
}

double DepozitBase::GetTerm_of_Depozit()
{
	return Term_of_Depozit;
}

void DepozitBase::Setlog(int _log)
{
	log = _log;
}

void DepozitBase::SetFirst_month(int _First_month)
{
	First_month = _First_month;
}

void DepozitBase::SetCheckDepozit(bool _CheckDepozit)
{
	CheckDepozit = _CheckDepozit;
}

void DepozitBase::SetInitial_Summ(int _Initial_Summ)
{
	Initial_Summ = _Initial_Summ;
}

void DepozitBase::SetPercent_Summ(double _Percent_Summ)
{
	Percent_Summ = _Percent_Summ;
}

void DepozitBase::SetTerm_of_Depozit(int _Term_of_Depozit)
{
	Term_of_Depozit = _Term_of_Depozit;
}

ostream & operator<<(ostream & stream, const DepozitBase & v)
{
	stream << v.log << v.First_month << v.CheckDepozit  << v.Initial_Summ << v.Percent_Summ << v.Term_of_Depozit << endl;
	return stream;
}

istream & operator>>(istream & stream, DepozitBase & v)
{
	stream >> v.log >> v.First_month >> v.CheckDepozit >> v.Initial_Summ >> v.Percent_Summ >> v.Term_of_Depozit;
	return stream;
}
