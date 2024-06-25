#pragma once

class University
{
protected:
	char name[10];		//이름
	char address[20];	//주소
	char num[20];		//폰번호
	char mail[20];		//이메일
	char gender;		//성별
	int age;			//나이

public:
	University(const char* name, const char* address, const char* num, const char* mail, const char gender, int age);

	virtual void PrintInfo();

	char* GetName();
	void SetName(const char* name);
	char* GetAddress();
	void SetAddress(const char* address);
	char* GetNum();
	void SetNum(const char* num);
	char* GetMail();
	void SetMail(const char* mail);
	char Getgender();
	void SetGender(const char gender);
	int GetAge();
	void SetAge(int age);
};

class Staff : public University
{
private:
	char part[20];  //담당부서
	char rank[20];  //직급
	char task[20];  //업무
	int snum;       //사번

public:
	Staff(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* part, const char* rank, const char* task, int snum);

	virtual void StaffInfo();

	char* Getpart();
	void Setpart(const char* part);
	char* Getrank();
	void Setrank(const char* rank);
	char* Gettask();
	void Settask(const char* task);
	int Getsnum();
	void Setsnum(int snum);
};

class Professor : public University 
{
protected:
	char pmajor[20];
	char subject[10];
	char pro;
	char lab[10];

public:
	Professor(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* subject, const char* pmajor, const char pro, const char* lab);
	virtual void ProfessorInfo();
	char* Getsubject();
	void Setsubject(const char* subject);
	char* Getpmajor();
	void Setpmajor(const char* pmajor);
	char Getpro();
	void Setpro(const char pro);
	char* Getlab();
	void Setlab(const char* lab);
	void SearchPro(const char* what);
};

class Student : public University
{
private:

	char major[20];	 //학과
	int stdnum;      //학번
	double grade;    //성적
	bool dorm;		 //기숙사여부

public:
	Student(const char* name, const char* address, const char* num, const char* mail, const char gender, int age, const char* major, int stdnum, double grade, const char dorm);

	virtual void StudentInfo();

	char* GetMajor();
	void SetMajor(const char* major);
	int GetStdnum();
	void SetStdnum(int stdnum);
	double GetGrade();
	void SetGrade(double grade);
	bool GetDorm();
	void SetDorm(bool dorm);
};

