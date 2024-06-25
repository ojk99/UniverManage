#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "University.h"
#include "Function.h"
using namespace std;

Function_Professor ::Function_Professor()
{
	ifstream readFile_pro;
	readFile_pro.open("professor.csv");
	string pro;

	if (readFile_pro.is_open())
	{
		while (getline(readFile_pro, pro))
		{
			vector<string> result = split(pro, ',');
			vc_professor.push_back(Professor(result[0].c_str(), result[1].c_str(), result[2].c_str(), result[3].c_str(), *result[4].c_str(), stoi(result[5]), result[6].c_str(), result[7].c_str(), *result[8].c_str(), result[9].c_str()));
		}
	}

	readFile_pro.close();
}

void Function_Professor::writeToCSV_Professor()
{
	ofstream writeFile;
	writeFile.open("Professor.csv");
	string s;

	if (writeFile.is_open())
	{
		for (int i = 0; i < vc_professor.size(); i++)
		{
			s += vc_professor.at(i).GetName();
			s += ',';
			s += vc_professor.at(i).GetAddress();
			s += ',';
			s += vc_professor.at(i).GetNum();
			s += ',';
			s += vc_professor.at(i).GetMail();
			s += ',';
			s += vc_professor.at(i).Getgender();
			s += ',';
			s += to_string(vc_professor.at(i).GetAge());
			s += ',';
			s += vc_professor.at(i).Getsubject();
			s += ',';
			s += vc_professor.at(i).Getpmajor();
			s += ',';
			s += vc_professor.at(i).Getpro();
			s += ',';
			s += vc_professor.at(i).Getlab();
			if (i < vc_professor.size() - 1)
				s += '\n';
		}
		writeFile.write(s.c_str(), s.size());
	}
	else
	{
		cout << "���� ����" << endl;
	}

	writeFile.close();
}

void Function_Professor::AddProfessor()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "���� �߰� ����� ����մϴ�." << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	string name;
	string address;
	string num;
	string mail;
	char* gender = new char;
	int age;
	string subject;
	string pmajor;
	char* pro = new char;
	string lab;

	cout << "���� ������ �Է��ؾ� �մϴ�" << endl;
	cout << "�̸� : ";
	cin >> name;
	cout << "�ּ� : ";
	cin >> address;
	cout << "��ȭ��ȣ : ";
	cin >> num;
	cout << "���� : ";
	cin >> mail;
	cout << "����(f,m) : ";
	cin >> *gender;
	cout << "���� : ";
	cin >> age;
	cout << "������ : ";
	cin >> subject;
	cout << "�а� :	";
	cin >> pmajor;
	cout << "����(F,A) : ";
	cin >> *pro;
	cout << "�����ǼҼ� : ";
	cin >> lab;

	vc_professor.push_back(Professor(name.c_str(), address.c_str(), num.c_str(), mail.c_str(),
		*gender, age, subject.c_str(), pmajor.c_str(), *pro, lab.c_str()));
	delete gender;
	delete pro;
}

vector<string> Function_Professor::split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		answer.push_back(temp);
	}

	return answer;
}

void Function_Professor::printProfessor()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	if (vc_professor.size() == 0)
	{
		cout << "Ȯ���� ������ �����ϴ�." << endl;
		return;
	}
	cout << "���� ��ü ���� ����� ����մϴ�." << endl;

	for (int i = 0; i < vc_professor.size(); i++)
	{
		vc_professor.at(i).ProfessorInfo();
	}
}

void Function_Professor::searchProfessor()
{
	int count = 0;
	string name;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "���� �˻� ����� ����մϴ�." << endl;
	cout << "���� �̸� �Է� : ";
	cin >> name;

	for (int i = 0; i < vc_professor.size(); i++)
	{
		if (strcmp(vc_professor.at(i).GetName(), name.c_str()) == 0)
		{
			vc_professor.at(i).ProfessorInfo();
			count++;
		}
	}
	if (count == 0)
		cout << "�˻� ����� �����ϴ�." << endl;
}

void Function_Professor::fixProfessor()
{
	int count = 0;
	int select;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_professor.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}

	for (int i = 0; i < vc_professor.size(); i++)
	{
		cout << i + 1 << " ";
		vc_professor.at(i).ProfessorInfo();
		count++;
	}

	cout << "���������� ��ȣ�� �Է��� �ּ��� : ";
	cin >> select;

	if (vc_professor.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "������ ����" << endl;
		cout << "1. �̸�" << endl;
		cout << "2. �ּ�" << endl;
		cout << "3. ��ȭ��ȣ" << endl;
		cout << "4. ����" << endl;
		cout << "5. ���� ���� ����(F,A)" << endl;
		cout << "��ȣ �Է� : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "�̸� �Է� : ";
			cin >> str;
			vc_professor.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "�ּ� �Է� : ";
			cin >> str;
			vc_professor.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "��ȭ��ȣ �Է� : ";
			cin >> str;
			vc_professor.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "���� �Է� : ";
			cin >> str;
			vc_professor.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "���� ���� ����(F,A) : ";
			cin >> c;
			vc_professor.at(select - 1).Setpro(c == 'F' || c == 'f' ? 'F' : 'A');
		}
		else
		{
			cout << "�߸��� ��ȣ�� �Է��Ͽ����ϴ�" << endl;
		}
	}
	else
	{
		cout << "�߸��� ��ȣ�� �Է��Ͽ����ϴ�" << endl;
	}
}

void Function_Professor::deleteProfessor()
{
	int count = 1;
	string ch;

	for (int i = 0; i < vc_professor.size(); i++)
	{
		cout << count << ".";
		vc_professor.at(i).ProfessorInfo();

		count++;
	}

	int Num;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	if (vc_professor.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}

	cout << "������ �� ��ȣ�� �Է��ϼ���: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_professor.size())
	{
		vc_professor.erase(vc_professor.begin() + Num - 1);
		cout << "�����Ǿ����ϴ�.." << endl;
	}
	else
	{
		cout << "�߸��� ��ȣ�Դϴ�." << endl;
	}
}
