#include <iostream>
#include"University.h" 
using namespace std;

Staff::Staff(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* part, const char* rank, const char* task, int snum) : University(name, address, num, mail, gender, age)
{
	strcpy(this->part, part);
	strcpy(this->rank, rank);
	strcpy(this->task, task);
	this->snum = snum;
}

void Staff::StaffInfo()
{
	University::PrintInfo();

	cout << "\n  부서 : " << part;
	cout << ", 직급 : " << rank;
	cout << ", 업무 : " << task;
	cout << ", 사번 : " << snum << endl;
}

char* Staff::Getpart()
{
	return part;
}

void Staff::Setpart(const char* part)
{
	strcpy(this->part, part);
}

char* Staff::Getrank()
{
	return rank;
}

void Staff::Setrank(const char* rank)
{
	strcpy(this->rank, rank);
}

char* Staff::Gettask()
{
	return task;
}

void Staff::Settask(const char* task)
{
	strcpy(this->task, task);
}

int Staff::Getsnum()
{
	return snum;
}

void Staff::Setsnum(int snum)
{
	this->snum = snum;
}
