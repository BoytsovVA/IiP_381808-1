#include "Dictionary.h"
#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	// ������ �� ������
	ifstream is; // ����� ��� ������
	is.open("Words1.txt"); // ���� ��� ������
	Dictionary Dict1(is);
	is.close();
	is.open("Words2.txt"); // ���� ��� ������
	Dictionary Dict2(is);
	is.close();
	is.open("output.txt"); // ���� ��� ������
	Dictionary DictTogether(is);
	is.close();
	DictTogether = Dict2;
	cout << "���������� ������� DictTogether, ����� ������������ ��� Dict2: " << endl;
	cout << DictTogether << endl;
	Dict1 +=  Dict2;
	cout << "���������� ������� Dict1, ����� ������� � Dict2: " << endl;
	cout << Dict1 << endl;
	int Answer;
	string Word, Translation;
	do
	{
		cout << "������� ����� ��������, ������� ������ ���������: " << endl;
		cout << "1 - �������� � ������� ����� � ��� �������" << endl;
		cout << "2 - �������� ������� ���������� �����" << endl;
		cout << "3 - ������ ������� ���������� �����" << endl;
		cout << "4 - ��������� ������� ����� � �������" << endl;
		cout << "5 - ������ ����� ���� � �������" << endl;
		cout << "6 - ������� �������" << endl;
		cout << "0 - ����� �� ���������" << endl;
		cin >> Answer;

		switch (Answer)
		{
		case 1:
			cout << "������� ����� �� ���������� �����" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			cout << "������� ������� ����� �����" << endl;
			getline(cin, Translation);
			Dict1.AddWords(Word, Translation);
			break;
		case 2:
			cout << "������� �����, ������� �������� ������ ��������" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			cout << "������� ������� ������� �����" << endl;
			getline(cin, Translation);
			Dict1.EditTranslation(Word, Translation);
			break;
		case 3:
			cout << "������� �����, ������� �������� �� ������ ������" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			Dict1.LearnTranslation(Word);
			break;
		case 4:
			cout << "������� �����, ������� �������� ������ ���������" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			Dict1.CheckWord(Word);
			break;
		case 5:
			Dict1.NumberWords();
			break;
		case 6:
			Dict1.FilePreparation("Words1.txt");
			break;
		case 0:
			return;
		default:
			break;
		}
	} while (Answer >=0 && Answer <=6);
}