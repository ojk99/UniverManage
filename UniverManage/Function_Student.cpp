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
		cout << "파일 없음" << endl;
	}

	writeFile.close();
}

void Function_Student::AddStudent()
{
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "학생 추가 기능을 사용합니다." << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

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

	cout << "학생 정보를 입력해야 합니다" << endl;
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
	cout << "학과 : ";
	cin >> major;
	cout << "학번 : ";
	cin >> stdnum;
	cout << "성적 : ";
	cin >> grade;
	cout << "기숙사(t,f) : ";
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_student.size() == 0)
	{
		cout << "확인할 정보가 없습니다." << endl;
		return;
	}
	cout << "학생 전체 보기 기능을 사용합니다." << endl;

	for (int i = 0; i < vc_student.size(); i++)
	{
		vc_student.at(i).StudentInfo();
	}
}

void Function_Student::searchStudent()
{
	int count = 0;
	string name;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "학생 검색 기능을 사용합니다." << endl;
	cout << "학생 이름 입력 : ";
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
		cout << "검색 결과가 없습니다." << endl;
}

void Function_Student::fixStudent()
{
	int count = 0;
	int select;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_student.size() == 0)
	{
		cout << "수정할 정보가 없습니다." << endl;
		return;
	}

	for (int i = 0; i < vc_student.size(); i++)
	{
		cout << i + 1 << " ";
		vc_student.at(i).StudentInfo();
		count++;
	}

	cout << "정보수정할 번호를 입력해 주세요 : ";
	cin >> select;

	if (vc_student.size() >= select && select - 1 >= 0)
	{
		int si;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "수정할 정보" << endl;
		cout << "1. 이름" << endl;
		cout << "2. 주소" << endl;
		cout << "3. 전화번호" << endl;
		cout << "4. 메일" << endl;
		cout << "5. 기숙사 여부" << endl;
		cout << "번호 입력 : ";
		cin >> si;

		string str;
		char c;

		if (si == 1)
		{
			cout << "이름 입력 : ";
			cin >> str;
			vc_student.at(select - 1).SetName(str.c_str());
		}
		else if (si == 2)
		{
			cout << "주소 입력 : ";
			cin >> str;
			vc_student.at(select - 1).SetAddress(str.c_str());
		}
		else if (si == 3)
		{
			cout << "전화번호 입력 : ";
			cin >> str;
			vc_student.at(select - 1).SetNum(str.c_str());
		}
		else if (si == 4)
		{
			cout << "메일 입력 : ";
			cin >> str;
			vc_student.at(select - 1).SetMail(str.c_str());
		}
		else if (si == 5)
		{
			cout << "기숙사 여부(t,f) : ";
			cin >> c;
			vc_student.at(select - 1).SetDorm(c == 't' ? true : false);
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
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	if (vc_student.size() == 0)
	{
		cout << "삭제할 정보가 없습니다." << endl;
		return;
	}

	cout << "삭제할 행 번호를 입력하세요: ";
	cin >> Num;

	if (Num >= 1 && Num <= vc_student.size())
	{
		vc_student.erase(vc_student.begin() + Num - 1);
		cout << "삭제되었습니다.." << endl;
	}
	else
	{
		cout << "잘못된 번호입니다." << endl;
	}
}

