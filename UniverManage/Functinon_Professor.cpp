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
		cout << "파일 없음" << endl;
	}

	writeFile.close();
}

void Function_Professor::AddProfessor()
{
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "교수 추가 기능을 사용합니다." << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

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

	cout << "교수 정보를 입력해야 합니다" << endl;
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
	cout << "담당과목 : ";
	cin >> subject;
	cout << "학과 :	";
	cin >> pmajor;
	cout << "교수(F,A) : ";
	cin >> *pro;
	cout << "연구실소속 : ";
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	if (vc_professor.size() == 0)
	{
		cout << "확인할 정보가 없습니다." << endl;
		return;
	}
	cout << "교수 전체 보기 기능을 사용합니다." << endl;

	for (int i = 0; i < vc_professor.size(); i++)
	{
		vc_professor.at(i).ProfessorInfo();
	}
}

void Function_Professor::searchProfessor()
{
	int count = 0;
	string name;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "교수 검색 기능을 사용합니다." << endl;
	cout << "교수 이름 입력 : ";
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
		cout << "검색 결과가 없습니다." << endl;
}

void Function_Professor::fixProfessor()
{
	int count = 0;
	int select;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_professor.size() == 0)
	{
		cout << "수정할 정보가 없습니다." << endl;
		return;
	}

	for (int i = 0; i < vc_professor.size(); i++)
	{
		cout << i + 1 << " ";
		vc_professor.at(i).ProfessorInfo();
		count++;
	}

	cout << "정보수정할 번호를 입력해 주세요 : ";
	cin >> select;

	if (vc_professor.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "수정할 정보" << endl;
		cout << "1. 이름" << endl;
		cout << "2. 주소" << endl;
		cout << "3. 전화번호" << endl;
		cout << "4. 메일" << endl;
		cout << "5. 정임 교수 여부(F,A)" << endl;
		cout << "번호 입력 : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "이름 입력 : ";
			cin >> str;
			vc_professor.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "주소 입력 : ";
			cin >> str;
			vc_professor.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "전화번호 입력 : ";
			cin >> str;
			vc_professor.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "메일 입력 : ";
			cin >> str;
			vc_professor.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "정임 교수 여부(F,A) : ";
			cin >> c;
			vc_professor.at(select - 1).Setpro(c == 'F' || c == 'f' ? 'F' : 'A');
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	if (vc_professor.size() == 0)
	{
		cout << "삭제할 정보가 없습니다." << endl;
		return;
	}

	cout << "삭제할 행 번호를 입력하세요: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_professor.size())
	{
		vc_professor.erase(vc_professor.begin() + Num - 1);
		cout << "삭제되었습니다.." << endl;
	}
	else
	{
		cout << "잘못된 번호입니다." << endl;
	}
}
