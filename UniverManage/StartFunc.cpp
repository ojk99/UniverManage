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
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "1. �л� �߰�" << endl;
		cout << "2. �л� ��ü ����" << endl;
		cout << "3. �л� �˻�" << endl;
		cout << "4. �л� ���� ����" << endl;
		cout << "5. �л� ����" << endl;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "�޴�����(q Ȥ�� Q�� ������ ���� �޴�) : ";
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
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "1. ���� �߰�" << endl;
		cout << "2. ���� ��ü ����" << endl;
		cout << "3. ���� �˻�" << endl;
		cout << "4. ���� ���� ����" << endl;
		cout << "5. ���� ����" << endl;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "�޴�����(q Ȥ�� Q�� ������ ���� �޴�) : ";
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
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "1. ������ �߰�" << endl;
		cout << "2. ������ ��ü ����" << endl;
		cout << "3. ������ �˻�" << endl;
		cout << "4. ������ ���� ����" << endl;
		cout << "5. ������ ����" << endl;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "�޴�����(q Ȥ�� Q�� ������ ���� �޴�) : ";
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
		cout << "���б� �������� �ý���" << endl;
		cout << "1. �л�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ������" << endl;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "�޴�����(q Ȥ�� Q�� ������ ����) : ";
		cin >> m_choice;

		if (m_choice == 'q' || m_choice == 'Q')
		{
			cout << "���� �մϴ�." << endl;
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