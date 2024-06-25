#include <iostream>
#include"University.h" 
using namespace std;

University::University(const char* name, const char* address, const char* num, const char* mail, const char gender, int age) : age(age)
{
	if (gender == 'f' || gender == 'F')
		this->gender = 'f';
	else
		this->gender = 'm';

	strcpy(this->name, name);
	strcpy(this->address, address);
	strcpy(this->num, num);
	strcpy(this->mail, mail);
}

void University::PrintInfo()
{
	cout << "이름 : " << name << ", 주소 : " << address << ", 전화번호 : " << num << ", 성별 : " << gender << ", 나이 : " << age;
}

char* University::GetName()
{
	return name;
}

void University::SetName(const char* name)
{
	strcpy(this->name, name);
}

char* University::GetAddress()
{
	return address;
}

void University::SetAddress(const char* address)
{
	strcpy(this->address, address);
}

char* University::GetNum()
{
	return num;
}

void University::SetNum(const char* num)
{
	strcpy(this->num, num);
}

char* University::GetMail()
{
	return mail;
}

void University::SetMail(const char* mail)
{
	strcpy(this->mail, mail);
}

char University::Getgender()
{
	return gender;
}

void University::SetGender(const char gender)
{
	if (gender == 'f' || gender == 'F')
		this->gender = 'f';
	else
		this->gender = 'm';
}

int University::GetAge()
{
	return age;
}

void University::SetAge(int age)
{
	this->age = age;
}
