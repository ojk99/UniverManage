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
		cout << "파일 없음" << endl;
	}

	writeFile.close();
}

void Function_Staff::AddStaff()
{
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "교직원 추가 기능을 사용합니다." << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

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

	cout << "직원 정보를 입력해야 합니다" << endl;
	cout << "이름 : ";
	cin >> name;
	cout << "주소 : ";
	cin >> address;
	cout << "전화번호 : ";
	cin >> num;
	cout << "메일 : ";
	cin >> mail;
	cout << "성별(f,m) : ";
	cin >> *gender;
	cout << "나이 : ";
	cin >> age;
	cout << "부서 : ";
	cin >> part;
	cout << "직급 : ";
	cin >> rank;
	cout << "업무 : ";
	cin >> task;
	cout << "사번 : ";
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	if (vc_staff.size() == 0)
	{
		cout << "확인할 정보가 없습니다." << endl;
		return;
	}
	cout << "교직원 전체 보기 기능을 사용합니다." << endl;

	for (int i = 0; i < vc_staff.size(); i++)
	{
		vc_staff.at(i).StaffInfo();
	}
}

void Function_Staff::searchStaff()
{
	int count = 0;
	string name;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "교직원 검색 기능을 사용합니다." << endl;
	cout << "교직원 이름 입력 : ";
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
		cout << "검색 결과가 없습니다." << endl;
}

void Function_Staff::fixStaff()
{
	int count = 0;
	int select;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_staff.size() == 0)
	{
		cout << "수정할 정보가 없습니다." << endl;
		return;
	}
	for (int i = 0; i < vc_staff.size(); i++)
	{
		cout << i + 1 << " ";
		vc_staff.at(i).StaffInfo();
		count++;
	}

	cout << "정보수정할 번호를 입력해 주세요 : ";
	cin >> select;

	if (vc_staff.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "수정할 정보" << endl;
		cout << "1. 이름" << endl;
		cout << "2. 주소" << endl;
		cout << "3. 전화번호" << endl;
		cout << "4. 메일" << endl;
		cout << "5. 직급" << endl;
		cout << "번호 입력 : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "이름 입력 : ";
			cin >> str;
			vc_staff.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "주소 입력 : ";
			cin >> str;
			vc_staff.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "전화번호 입력 : ";
			cin >> str;
			vc_staff.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "메일 입력 : ";
			cin >> str;
			vc_staff.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "직급 : ";
			cin >> str;
			vc_staff.at(select - 1).Setrank(str.c_str());
		}
		else
		{
			cout << "잘못된 번호를 입력하였습니다" << endl;
		}
	}
	else
	{
		cout << "잘못된 번호를 입력하였습니다" << endl;
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_staff.size() == 0)
	{
		cout << "삭제할 정보가 없습니다." << endl;
		return;
	}

	cout << "삭제할 행 번호를 입력하세요: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_staff.size())
	{
		vc_staff.erase(vc_staff.begin() + Num - 1);
		cout << "삭제되었습니다.." << endl;
	}
	else
	{
		cout << "잘못된 번호입니다." << endl;
	}
}