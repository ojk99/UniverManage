#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "University.h"
#include "Function.h"
using namespace std;

Function_Student::Function_Student()
{
	ifstream readFile_std;
	readFile_std.open("Student.csv");
	string std;

	if (readFile_std.is_open())
	{
		while (getline(readFile_std, std))
		{
			vector<string> result = split(std, ',');
			vc_student.push_back(Student(result[0].c_str(), result[1].c_str(), result[2].c_str(), result[3].c_str(), *result[4].c_str(), stoi(result[5]), result[6].c_str(), stoi(result[7]), stod(result[8]), result[9] == "true" ? true : false));
		}
	}
	readFile_std.close();
	
	
}

void Function_Student::writeToCSV_Student()
{
	ofstream writeFile;
	writeFile.open("Student.csv");
	string s;

	if (writeFile.is_open())
	{
		for (int i = 0; i < vc_student.size(); i++)
		{
			s += vc_student.at(i).GetName();
			s += ',';
			s += vc_student.at(i).GetAddress();
			s += ',';
			s += vc_student.at(i).GetNum();
			s += ',';
			s += vc_student.at(i).GetMail();
			s += ',';
			s += vc_student.at(i).Getgender();
			s += ',';
			s += to_string(vc_student.at(i).GetAge());
			s += ',';
			s += vc_student.at(i).GetMajor();
			s += ',';
			s += to_string(vc_student.at(i).GetStdnum());
			s += ',';
			s += to_string(vc_student.at(i).GetGrade());
			s += ',';
			s += vc_student.at(i).GetDorm() == true ? "true" : "false";
			if (i < vc_student.size() - 1)
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

void Function_Student::AddStudent()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "�л� �߰� ����� ����մϴ�." << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	string name;
	string address;
	string num;
	string mail;
	char* gender = new char;
	int age;
	string major;
	int stdnum;
	double grade;
	char* dorm = new char;

	cout << "�л� ������ �Է��ؾ� �մϴ�" << endl;
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
	cout << "�а� : ";
	cin >> major;
	cout << "�й� : ";
	cin >> stdnum;
	cout << "���� : ";
	cin >> grade;
	cout << "�����(t,f) : ";
	cin >> *dorm;

	vc_student.push_back(Student(name.c_str(), address.c_str(), num.c_str(), mail.c_str(),
		*gender, age, major.c_str(), stdnum, grade, *dorm));
	delete gender;
	delete dorm;
}

vector<string> Function_Student::split(string input, char delimiter)
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

void Function_Student::printStudent()
{
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_student.size() == 0)
	{
		cout << "Ȯ���� ������ �����ϴ�." << endl;
		return;
	}
	cout << "�л� ��ü ���� ����� ����մϴ�." << endl;

	for (int i = 0; i < vc_student.size(); i++)
	{
		vc_student.at(i).StudentInfo();
	}
}

void Function_Student::searchStudent()
{
	int count = 0;
	string name;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "�л� �˻� ����� ����մϴ�." << endl;
	cout << "�л� �̸� �Է� : ";
	cin >> name;

	for (int i = 0; i < vc_student.size(); i++)
	{
		if (strcmp(vc_student.at(i).GetName(), name.c_str()) == 0)
		{
			vc_student.at(i).StudentInfo();
			count++;
		}
	}
	if (count == 0)
		cout << "�˻� ����� �����ϴ�." << endl;
}

void Function_Student::fixStudent()
{
	int count = 0;
	int select;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_student.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}

	for (int i = 0; i < vc_student.size(); i++)
	{
		cout << i + 1 << " ";
		vc_student.at(i).StudentInfo();
		count++;
	}

	cout << "���������� ��ȣ�� �Է��� �ּ��� : ";
	cin >> select;

	if (vc_student.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "������ ����" << endl;
		cout << "1. �̸�" << endl;
		cout << "2. �ּ�" << endl;
		cout << "3. ��ȭ��ȣ" << endl;
		cout << "4. ����" << endl;
		cout << "5. ����� ����" << endl;
		cout << "��ȣ �Է� : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "�̸� �Է� : ";
			cin >> str;
			vc_student.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "�ּ� �Է� : ";
			cin >> str;
			vc_student.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "��ȭ��ȣ �Է� : ";
			cin >> str;
			vc_student.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "���� �Է� : ";
			cin >> str;
			vc_student.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "����� ����(t,f) : ";
			cin >> c;
			vc_student.at(select - 1).SetDorm(c == 't' ? true : false);
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

void Function_Student::deleteStudent()
{
	int count = 1;
	string ch;

	for (int i = 0; i < vc_student.size(); i++)
	{
		cout << count << ".";
		vc_student.at(i).StudentInfo();

		count++;
	}

	int Num;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	if (vc_student.size() == 0)
	{
		cout << "������ ������ �����ϴ�." << endl;
		return;
	}

	cout << "������ �� ��ȣ�� �Է��ϼ���: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_student.size())
	{
		vc_student.erase(vc_student.begin() + Num - 1);
		cout << "�����Ǿ����ϴ�.." << endl;
	}
	else
	{
		cout << "�߸��� ��ȣ�Դϴ�." << endl;
	}
}

