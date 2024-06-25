#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "University.h"
#include "Function.h"
using namespace std;

Function_Staff::Function_Staff()
{
	ifstream readFile;
	readFile.open("Staff.csv");
	string s;

	if (readFile.is_open())
	{
		while (getline(readFile, s))
		{
			vector<string> result = split(s, ',');
			vc_staff.push_back(Staff(result[0].c_str(), result[1].c_str(), result[2].c_str(), result[3].c_str(), *result[4].c_str(), stoi(result[5]), result[6].c_str(), result[7].c_str(), result[8].c_str(), stoi(result[9])));
		}
	}

	readFile.close();
}

void Function_Staff::writeToCSV_Staff()
{
	ofstream writeFile;
	writeFile.open("Staff.csv");
	string s;

	if (writeFile.is_open())
	{
		for (int i = 0; i < vc_staff.size(); i++)
		{
			s += vc_staff.at(i).GetName();
			s += ',';
			s += vc_staff.at(i).GetAddress();
			s += ',';
			s += vc_staff.at(i).GetNum();
			s += ',';
			s += vc_staff.at(i).GetMail();
			s += ',';
			s += vc_staff.at(i).Getgender();
			s += ',';
			s += to_string(vc_staff.at(i).GetAge());
			s += ',';
			s += vc_staff.at(i).Getpart();
			s += ',';
			s += vc_staff.at(i).Getrank();
			s += ',';
			s += vc_staff.at(i).Gettask();
			s += ',';
			s += to_string(vc_staff.at(i).Getsnum());
			if (i < vc_staff.size() - 1)
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

void Function_Staff::AddStaff()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "������ �߰� ����� ����մϴ�." << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	string name;
	string address;
	string num;
	string mail;
	char* gender = new char;
	int age;
	string part;
	string rank;
	string task;
	int snum;

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
	cout << "�μ� : ";
	cin >> part;
	cout << "���� : ";
	cin >> rank;
	cout << "���� : ";
	cin >> task;
	cout << "��� : ";
	cin >> snum;

	vc_staff.push_back(Staff(name.c_str(), address.c_str(), num.c_str(), mail.c_str(),
		*gender, age, part.c_str(), rank.c_str(), task.c_str(), snum));
	delete gender;
}

vector<string> Function_Staff::split(string input, char delimiter)
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

void Function_Staff::printStaff()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	if (vc_staff.size() == 0)
	{
		cout << "Ȯ���� ������ �����ϴ�." << endl;
		return;
	}
	cout << "������ ��ü ���� ����� ����մϴ�." << endl;

	for (int i = 0; i < vc_staff.size(); i++)
	{
		vc_staff.at(i).StaffInfo();
	}
}

void Function_Staff::searchStaff()
{
	int count = 0;
	string name;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "������ �˻� ����� ����մϴ�." << endl;
	cout << "������ �̸� �Է� : ";
	cin >> name;

	for (int i = 0; i < vc_staff.size(); i++)
	{
		if (strcmp(vc_staff.at(i).GetName(), name.c_str()) == 0)
		{
			vc_staff.at(i).StaffInfo();
			count++;
		}
	}
	if (count == 0)
		cout << "�˻� ����� �����ϴ�." << endl;
}

void Function_Staff::fixStaff()
{
	int count = 0;
	int select;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_staff.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < vc_staff.size(); i++)
	{
		cout << i + 1 << " ";
		vc_staff.at(i).StaffInfo();
		count++;
	}

	cout << "���������� ��ȣ�� �Է��� �ּ��� : ";
	cin >> select;

	if (vc_staff.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "������ ����" << endl;
		cout << "1. �̸�" << endl;
		cout << "2. �ּ�" << endl;
		cout << "3. ��ȭ��ȣ" << endl;
		cout << "4. ����" << endl;
		cout << "5. ����" << endl;
		cout << "��ȣ �Է� : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "�̸� �Է� : ";
			cin >> str;
			vc_staff.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "�ּ� �Է� : ";
			cin >> str;
			vc_staff.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "��ȭ��ȣ �Է� : ";
			cin >> str;
			vc_staff.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "���� �Է� : ";
			cin >> str;
			vc_staff.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "���� : ";
			cin >> str;
			vc_staff.at(select - 1).Setrank(str.c_str());
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

void Function_Staff::deleteStaff()
{
	int count = 1;
	string ch;

	for (int i = 0; i < vc_staff.size(); i++)
	{
		cout << count << ".";
		vc_staff.at(i).StaffInfo();

		count++;
	}

	int Num;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_staff.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}

	cout << "������ �� ��ȣ�� �Է��ϼ���: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_staff.size())
	{
		vc_staff.erase(vc_staff.begin() + Num - 1);
		cout << "�����Ǿ����ϴ�.." << endl;
	}
	else
	{
		cout << "�߸��� ��ȣ�Դϴ�." << endl;
	}
}