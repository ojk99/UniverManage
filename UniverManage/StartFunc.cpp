#include <iostream>
#include"University.h" 
#include"Function.h"
using namespace std;

Function_Student stu;
Function_Professor pro;
Function_Staff sta;

void func_student()
{
	char s_choice;

	while (true)
	{
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "1. 학생 추가" << endl;
		cout << "2. 학생 전체 보기" << endl;
		cout << "3. 학생 검색" << endl;
		cout << "4. 학생 정보 수정" << endl;
		cout << "5. 학생 삭제" << endl;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "메뉴선택(q 혹은 Q를 누르면 이전 메뉴) : ";
		cin >> s_choice;

		if (s_choice == 'q' || s_choice == 'Q')
			break;

		switch (s_choice)
		{
		case '1':
			stu.AddStudent();
			stu.writeToCSV_Student();
			break;
		case '2':
			stu.printStudent();
			break;
		case '3':
			stu.searchStudent();
			break;
		case '4':
			stu.fixStudent();
			stu.writeToCSV_Student();
			break;
		case '5':
			stu.deleteStudent();
			stu.writeToCSV_Student();
			break;
		default:
			cout << endl;
			break;
		}
	}
}

void func_professor()
{
	char s_choice;

	while (true)
	{
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "1. 교수 추가" << endl;
		cout << "2. 교수 전체 보기" << endl;
		cout << "3. 교수 검색" << endl;
		cout << "4. 교수 정보 수정" << endl;
		cout << "5. 교수 삭제" << endl;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "메뉴선택(q 혹은 Q를 누르면 이전 메뉴) : ";
		cin >> s_choice;

		if (s_choice == 'q' || s_choice == 'Q')
			break;

		switch (s_choice)
		{
		case '1':
			pro.AddProfessor();
			pro.writeToCSV_Professor();
			break;
		case '2':
			pro.printProfessor();
			break;
		case '3':
			pro.searchProfessor();
			break;
		case '4':
			pro.fixProfessor();
			pro.writeToCSV_Professor();
			break;
		case '5':
			pro.deleteProfessor();
			pro.writeToCSV_Professor();
			break;
		default:
			cout << endl;
			break;
		}
	}
}

void func_Staff()
{
	char s_choice;

	while (true)
	{
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "1. 교직원 추가" << endl;
		cout << "2. 교직원 전체 보기" << endl;
		cout << "3. 교직원 검색" << endl;
		cout << "4. 교직원 정보 수정" << endl;
		cout << "5. 교직원 삭제" << endl;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "메뉴선택(q 혹은 Q를 누르면 이전 메뉴) : ";
		cin >> s_choice;

		if (s_choice == 'q' || s_choice == 'Q')
			break;

		switch (s_choice)
		{
		case '1':
			sta.AddStaff();
			sta.writeToCSV_Staff();
			break;
		case '2':
			sta.printStaff();
			break;
		case '3':
			sta.searchStaff();
			break;
		case '4':
			sta.fixStaff();
			sta.writeToCSV_Staff();
			break;
		case '5':
			sta.deleteStaff();
			sta.writeToCSV_Staff();
			break;
		default:
			cout << endl;
			break;
		}
	}
}

void func_start()
{
	char m_choice;

	while (true)
	{
		cout << "대학교 인적관리 시스템" << endl;
		cout << "1. 학생" << endl;
		cout << "2. 교수" << endl;
		cout << "3. 교직원" << endl;
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "메뉴선택(q 혹은 Q를 누르면 종료) : ";
		cin >> m_choice;

		if (m_choice == 'q' || m_choice == 'Q')
		{
			cout << "종료 합니다." << endl;
			break;
		}

		switch (m_choice)
		{
		case '1':
			func_student();
			break;
		case '2':
			func_professor();
			break;
		case '3':
			func_Staff();
			break;
		default:
			break;
		}
	}
}