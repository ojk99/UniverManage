#include <iostream>
#include"University.h"
using namespace std;

Student::Student(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* major, int stdnum, double grade, const char dorm) : University(name, address, num, mail, gender, age)
{
	if (dorm == 't' || dorm == 'T')
		this->dorm = true;
	else
		this->dorm = false;

	strcpy(this->major, major);
	this->stdnum = stdnum;
	this->grade = grade;
}

void Student::StudentInfo()	//���� ���
{
	University::PrintInfo();

	string dorm = this->dorm == true ? "true" : "false";
	cout << "\n" << "  �а� : " << major << ", �й� : " << stdnum << ", ���� : " << grade << ", ����� ���� : " << dorm << endl;
}

char* Student::GetMajor()	//�а� Get/Set
{
	return major;
}

void Student::SetMajor(const char* major)
{
	strcpy(this->major, major);
}

int Student::GetStdnum()	//�й� Get/Set
{
	return stdnum;
}

void Student::SetStdnum(int stdnum)
{
	this->stdnum = stdnum;
}

double Student::GetGrade()	//���� Get/Set
{
	return grade;
}

void Student::SetGrade(double grade)
{
	this->grade = grade;
}

bool Student::GetDorm()		//����� ���� Get/Set
{
	return dorm;
}

void Student::SetDorm(bool dorm)
{
	this->dorm = dorm;
}

