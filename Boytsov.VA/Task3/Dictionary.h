#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "windows.h"
#include <fstream>

using namespace std;

class Dictionary
{
public:
	Dictionary();//����������� �� ���������
	Dictionary(Dictionary &v);//����������� �����������
	Dictionary(istream& filename);//���������� �������������
	~Dictionary();//���������� 
	Dictionary& operator=(const Dictionary& v);//���������� �������� ������������
	Dictionary& operator+=(const Dictionary& v);//���������� �������� ������������ ���� ��������
	void AddWords(string s1, string s2);//������ ���������� ���� � �������
	void EditTranslation(string s1, string s2);//������� ��������� �������� ���������� �����
	void LearnTranslation(string s1);//������� ��������� �������� ���������� �����
	void CheckWord(string s1);//������� �������� ������� ����� � �������
	void NumberWords();//������� ������ ���������� ���� � �������
	void FilePreparation(const char* name);//������� ���������� ����� � ������
	void SaveDictionary(ostream& filename);//������� ������ � ����
	friend ostream& operator<<(ostream& stream, const Dictionary& v);//���������� �������� ������ �� �������
private:
	int length;//����� �������
	string *RusWords;//������� ����� �������
	string *EngWords;//���������� ����� �������
};
ostream& operator<<(ostream& stream, const Dictionary& v);
