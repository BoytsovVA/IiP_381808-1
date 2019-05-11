
#include "ProcCenter.h"
#include "Client.h"
#include "DepozitBase.h"
class Depozit
{
public:
	Depozit();
	bool Authorization(int, string);//Авторизация клиента
	void RecomendDepozit();//Доступные клиенту депозиты, исходя из суммы на его счету
	bool CheckOpenDepozit();//Проверка наличия открытого депозита
	bool OpenDepozit(int, int);//Открытие депозита(переведя указанную сумму с зп. счёта клиента на депозит)
	void LookDepozit();//Показать состояние депозита(Сколько денег было положено, на какой срок, сколько процентов было начислено)
	void WithdrawPercent();//Снятие процентов(переведя их на зп. счёт клиента)
	void CloseDepozit();//Закрытие депозита(переведя всю сумму на зп. счёт клиента)
	void SaveFile();//Сохранение в файл

private:

	Client* ClientNow;//Данные о текущем пользователе
	ProcCenter *file = new ProcCenter("E:/Теперь точно работающий/IiP_381808-1/Boytsov.VA/Task5/Base.txt");
	DepozitBase* ClientDepozit;//Данные по депозиту о текущем пользователе
	double DepozitCoefficient[4] = { 3, 3.5, 4, 4.5 };//Начальный коэффициент для определенных сумм. Зависит от указанной суммы с зарплатного счёта клиента.
					 
};
