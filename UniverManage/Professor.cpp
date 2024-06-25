#include <iostream>
#include"University.h" 
using namespace std;

Professor::Professor(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* subject, const char* pmajor, const char pro, const char* lab) : University(name, address, num, mail, gender, age)
{
	if (pro == 'F' || pro == 'f')
	{
		this->pro = 'F';
	}
	else
	{
		this->pro = 'A';
	}

	strcpy(this->pmajor, pmajor);
	strcpy(this->subject, subject);
	strcpy(this->lab, lab);
}

void Professor::ProfessorInfo()
{
	University::PrintInfo();
	cout << "\n  학과 : " << pmajor << ", 담당 과목 : " << subject << ", 교수 직급 : " << pro << ", 연구실 소속 : " << lab << endl;
}

char* Professor::Getpmajor()
{
	return pmajor;
}

void Professor::Setpmajor(const char* pmajor)
{
	strcpy(this->pmajor, pmajor);
}

char Professor::Getpro()
{
	return pro;
}

void Professor::Setpro(const char pro)
{
	this->pro = pro;
}

char* Professor::Getsubject()
{
	return subject;
}

void Professor::Setsubject(const char* subject)
{
	strcpy(this->subject, subject);
}

char* Professor::Getlab()
{
	return lab;
}

void Professor::Setlab(const char* lab)
{
	strcpy(this->lab, lab);
}