#include "Depozit.h"

Depozit::Depozit()
{
	ifstream is;
	is.open(file->Getfilename());
	is >> *file;
	is.close();
}


bool Depozit::Authorization(int _SalaryAccount, string _ClientPassword)
{
	for (int i = 0; i < file->Getsize(); i++)
	{
		if (file->Getbase()[i].GetSalaryAccountClient() == _SalaryAccount)
			if (file->Getbase()[i].GetClientPassword() == _ClientPassword)
			{
				ClientNow = file->SearchClient(_SalaryAccount);
				ClientDepozit = file->SearchDepozitBase(_SalaryAccount);
				return true;
			}
	}
	return false;
}

void Depozit::RecomendDepozit()
{
	if (ClientNow->GetClientCash() < 100000)
	{
		cout << "На вашем счету " << ClientNow->GetClientCash() << ", поэтому вам доступны следующие варианты: " << endl;
		cout << "На срок 3 месяца: " << DepozitCoefficient[0] << "%" << endl;
		cout << "На срок 6 месяцев: " << DepozitCoefficient[0] + (6 * 0.05) << "%" << endl;
		cout << "На срок 12 месяцев: " << DepozitCoefficient[0] + (12 * 0.05) << "%" << endl;
		cout << "На срок 24 месяца: " << DepozitCoefficient[0] + (24 * 0.05) << "%" << endl;
		cout << "На срок 36 месяцев: " << DepozitCoefficient[0] + (36 * 0.05) << "%" << endl;
	}
	if ((ClientNow->GetClientCash() >= 100000) && (ClientNow->GetClientCash() < 500000))
	{
		cout << "На вашем счету " << ClientNow->GetClientCash() << ", поэтому вам доступны следующие варианты: " << endl;
		cout << "На срок 3 месяца: " << DepozitCoefficient[1] << "%" << endl;
		cout << "На срок 6 месяцев: " << DepozitCoefficient[1] + (6 * 0.05) << "%" << endl;
		cout << "На срок 12 месяцев: " << DepozitCoefficient[1] + (12 * 0.05) << "%" << endl;
		cout << "На срок 24 месяца: " << DepozitCoefficient[1] + (24 * 0.05) << "%" << endl;
		cout << "На срок 36 месяцев: " << DepozitCoefficient[1] + (36 * 0.05) << "%" << endl;
	}
	if ((ClientNow->GetClientCash() >= 500000) && (ClientNow->GetClientCash() < 1000000))
	{
		cout << "На вашем счету " << ClientNow->GetClientCash() << ", поэтому вам доступны следующие варианты: " << endl;
		cout << "На срок 3 месяца: " << DepozitCoefficient[2] << "%" << endl;
		cout << "На срок 6 месяцев: " << DepozitCoefficient[2] + (6 * 0.05) << "%" << endl;
		cout << "На срок 12 месяцев: " << DepozitCoefficient[2] + (12 * 0.05) << "%" << endl;
		cout << "На срок 24 месяца: " << DepozitCoefficient[2] + (24 * 0.05) << "%" << endl;
		cout << "На срок 36 месяцев: " << DepozitCoefficient[2] + (36 * 0.05) << "%" << endl;
	}
	if (ClientNow->GetClientCash() >= 1000000)
	{
		cout << "На вашем счету " << ClientNow->GetClientCash() << ", поэтому вам доступны следующие варианты: " << endl;
		cout << "На срок 3 месяца: " << DepozitCoefficient[3] << "%" << endl;
		cout << "На срок 6 месяцев: " << DepozitCoefficient[3] + (6 * 0.05) << "%" << endl;
		cout << "На срок 12 месяцев: " << DepozitCoefficient[3] + (12 * 0.05) << "%" << endl;
		cout << "На срок 24 месяца: " << DepozitCoefficient[3] + (24 * 0.05) << "%" << endl;
		cout << "На срок 36 месяцев: " << DepozitCoefficient[3] + (36 * 0.05) << "%" << endl;
	}
}

bool Depozit::CheckOpenDepozit()
{
	if (ClientDepozit->GetCheckDepozit() == 1)
	{
		cout << "Депозит открыт" << endl;
		return true;
	}
	else 
	{
		cout << "Депозит ещё не открыт" << endl;
		return false;
	}
}

bool Depozit::OpenDepozit(int Summ, int Time)
{
	int value, month;
	double koeff_year;//годовой коэффициент
	double koeff_month;//Месячный коэффициент
	double sum_percent = 0.0;
	if (ClientNow->GetDepozitOpen() || Summ > ClientNow->GetClientCash()) //Проверяется открыт ли уже депозит, достаточно ли денег на счету
	{
		cout << "Ошибка" << endl;
		return 0;
	}
	cout << "Депозит открыт" << endl;
	ClientDepozit->SetCheckDepozit(true);//Открывает депозит
	ClientDepozit->SetInitial_Summ(Summ);//Указываем начальную сумму депозита
	ClientNow->SetClientCash(ClientNow->GetClientCash() - Summ);//Вычитаем сумму, положенную на депозит из зп.
	ClientDepozit->SetTerm_of_Depozit(Time);//Указываем срок депозита
	ClientDepozit->SetFirst_month(file->GetСurrent_month());//Указываем месяц, с которого начался депозит
	if (Summ < 100000)
		value = 0;
	else if (Summ > 100000 && (Summ < 500000))
		value = 1;
	else if (Summ> 500000 && (Summ < 1000000))
		value = 2;
	else if (Summ > 1000000)
		value = 3;
	koeff_year = (DepozitCoefficient[value] + 0.05*Time) / 100;//Вычисляем годовой коэффициент
	koeff_month = koeff_year / Time;//Вычисляем месячный коэффициент
	cout << koeff_year << koeff_month << endl;
	Time += file->GetСurrent_month();//Прибавляем к сроку депозиту начальный месяц, чтобы не было ошибки
	month = ClientDepozit->GetFirst_month();//Присваиваем переменной month месяц, с которого начался депозит
	while (month  < Time)  //Запускаем цикл, который каждый месяц начисляет проценты
	{
		sum_percent = sum_percent + Summ * koeff_month; //В переменной sum_percent складываем проценты за каждый месяц
		ClientDepozit->SetPercent_Summ(sum_percent); //Фиксируем проценты в классе
		month++;
	}
	file->SetCurrent_month(month); //Сдвигаем месяц, с учётом пройденного времени
	return true;
	SaveFile();//Сохраняем в файл
}

void Depozit::LookDepozit()
{
	cout << "Сумма = " << ClientDepozit->GetInitial_Summ() << "была положена на " << ClientDepozit->GetTerm_of_Depozit() << " месяцев" << endl;
	cout << "За это время начислено " << ClientDepozit->GetPercent_Summ() << endl;
}

void Depozit::WithdrawPercent()
{
	double s;
	s = ClientNow->GetClientCash();//Сохраняем в переменную S остаток на зп. счету клиента
	s += ClientDepozit->GetPercent_Summ();//Добавляем проценты
	ClientNow->SetClientCash(s);//Записываем в класс
	ClientDepozit->SetPercent_Summ(0.0);//Обнуляем проценты на депозите
	SaveFile();//Сохраняем в файл
}

void Depozit::CloseDepozit()
{
	double s;
	s = ClientNow->GetClientCash();//Сохраняем в переменную S остаток на зп. счету клиента
	s += ClientDepozit->GetPercent_Summ();//Добавляем проценты
	s += ClientDepozit->GetInitial_Summ();//Добавляем положенную сумму
	ClientNow->SetClientCash(s);//Записываем в класс
	ClientDepozit->SetPercent_Summ(0.0);//Обнуляем проценты на депозите
	ClientDepozit->SetInitial_Summ(0); //Обнуляем положенную на депозит сумму
	ClientDepozit->SetCheckDepozit(false); //Закрываем депозит
	ClientDepozit->SetTerm_of_Depozit(0); //Обнуляем срок депозита
	ClientDepozit->SetFirst_month(0);//Обнуляем начальный месяц
	SaveFile();//Сохраняем в файл
}

void Depozit::SaveFile()
{
	ofstream os;
	os.open(file->Getfilename());
	os << *file;
	os.close();
}










