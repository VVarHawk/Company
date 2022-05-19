/*
========================================================util.h========================================================

�������� ��������������� enum class � ������� ��� ������ �����:
	* MENU_MODE					&	main_menu				- ������� ����
	* EMPLOYEE_PROFILE_MODE		&	employee_profile_menu	- ���� �������������� ������� ����������
	* DEPARTMENT_PROFILE_MODE	&	department_profile_menu	- ���� �������������� ������� ������������
	* EMPLOYEE_FIND_MODE		&	employee_find_menu		- ���� ������ ����������
	* DEPARTMENT_FIND_MODE		&	department_find_menu	- ���� ������ ������������
	* EMPLOYEE_SORT_MODE		&	employee_sort_menu		- ���� ���������� �����������
	* DEPARTMENT_SORT_MODE		&	department_sort_menu	- ����� ���������� �������������

�������� ��������������� ������� ����� ������:
	* input_string - ���� ������ ���� std::string
	* input_size_t - ���� ����� ���� size_t

��� ������� ����� ������ ����� ����������� ����������, �� ��� �� � ������������ ��, 
�� ����� ������������ ���������� ���� �� �� ������ ���������� ��������

======================================================================================================================
*/




#pragma once

#include <iostream>
#include <string>
#include <limits>


enum class MENU_MODE					// ������ ������ ����
{
	ADD_EMPLOYEE = 1,			// �������� ����������
	ADD_DEPARTMENT,				// ������� �����������

	PRINT_ALL_EMPLOYEES,
	PRINT_EMPLOYEES_FROM_DEPARTMENT,
	PRINT_ALL_DEPARTMENTS,
	

	FIND_EMPLOYEE,						// ����� ����������
	FIND_DEPARTMENT,

	EDIT_EMPLOYEE_PROFILE,
	EDIT_DEPARTMENT_RROFILE,

	SORT_EMPLOYEES,						// ����������� ������� �����������
	SORT_DEPARTMENTS,

	SAVE,						// ��������� ������ � �����
	DOWNLOAD,					// ��������� ������ �� �����

	EXIT						// ����� �� ���������
};

enum class EMPLOYEE_PROFILE_MODE				// ������ ������������ �������
{
	EDIT_ALL = 1,				// ������������� ���
	EDIT_NAME,					// ������������� ���
	EDIT_AGE,					// ������������� �������
	EDIT_WORK_POSITION,				// ������������� ���������
	EDIT_SALARY,				// ������������� ��������
	EDIT_WORK_EXPERIENCE,			// ������������� ��������� ���� ������
	EDIT_WORK_DEPARTMENT,			// ������������� ����������� ������

	DELETE_EMPLOYEE,						// ������� �������

	BACK						// ����� �� ������ �������������� �������
};
enum class DEPARTMENT_PROFILE_MODE
{
	EDIT_ALL = 1,
	EDIT_NAME,
	EDIT_DEPARTMENT_HEAD,
	DELETE_DEPARTMENT_HEAD,

	DELETE_DEPARTMENT,

	BACK
};

enum class EMPLOYEE_FIND_MODE					// ������ ������ ����������
{
	ID = 1,							// �� id
	NAME,					// �� �����
	AGE,
	WORK_POSITION,
	SALARY,
	WORK_EXPERIENCE,

	BACK
};
enum class DEPARTMENT_FIND_MODE
{
	ID = 1,
	NAME,
	N_EMPLOYEES,

	BACK
};

enum class EMPLOYEE_SORT_MODE
{
	ID = 1,
	NAME,
	AGE,
	WORK_POSITION,
	SALARY,
	WORK_EXPERIENCE,

	BACK
};
enum class DEPARTMENT_SORT_MODE
{
	ID = 1,
	NAME,
	N_EMPLOYEES,

	BACK
};


MENU_MODE main_menu();

EMPLOYEE_PROFILE_MODE employee_profile_menu();
DEPARTMENT_PROFILE_MODE department_profile_menu();

EMPLOYEE_FIND_MODE employee_find_menu();
DEPARTMENT_FIND_MODE department_find_menu();

EMPLOYEE_SORT_MODE employee_sort_menu();
DEPARTMENT_SORT_MODE department_sort_menu();


std::string input_string();
size_t input_size_t();