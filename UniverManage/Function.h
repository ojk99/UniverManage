#pragma once
#include <vector>
#include "University.h"
using namespace std;

class Function_Student  //학생
{
private:
	vector<Student> vc_student;      

public:
	Function_Student();
	void writeToCSV_Student();
	void AddStudent();
	void printStudent();
	void searchStudent();
	void fixStudent();
	void deleteStudent();
	vector<string> split(string input, char delimiter);
};

class Function_Professor  //교수
{
private:
	vector<Professor> vc_professor;

public:
	Function_Professor();
	void writeToCSV_Professor();
	void AddProfessor();
	void printProfessor();
	void searchProfessor();
	void fixProfessor();
	void deleteProfessor();
	vector<string> split(string input, char delimiter);
};

class Function_Staff  //교직원
{
private:
	vector<Staff> vc_staff;

public:
	Function_Staff();
	void writeToCSV_Staff();
	void AddStaff();
	void printStaff();
	void searchStaff();
	void fixStaff();
	void deleteStaff();
	vector<string> split(string input, char delimiter);
};