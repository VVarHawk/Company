/*
========================================================util.h========================================================

Содержит вспомогательные enum class и функции для выбора опции:
	* MENU_MODE					&	main_menu				- главное меню
	* EMPLOYEE_PROFILE_MODE		&	employee_profile_menu	- меню редактирования профиля сотрудника
	* DEPARTMENT_PROFILE_MODE	&	department_profile_menu	- меню редактирования профиля департамента
	* EMPLOYEE_FIND_MODE		&	employee_find_menu		- меню поиска сотрудника
	* DEPARTMENT_FIND_MODE		&	department_find_menu	- мюню поиска департамента
	* EMPLOYEE_SORT_MODE		&	employee_sort_menu		- меню сортировки сотрудников
	* DEPARTMENT_SORT_MODE		&	department_sort_menu	- менюю сортировки департаментов

Содержит вспомогательные функции ввода данных:
	* input_string - ввод строки типа std::string
	* input_size_t - ввод числа типа size_t

Все функции ввода данных могут выбрасывать исключения, но они же и обрабатывают их, 
не давая пользователю продолжить пока он не введет корректные значения

======================================================================================================================
*/




#pragma once

#include <iostream>
#include <string>
#include <limits>


enum class MENU_MODE					// режимы работы меню
{
	ADD_EMPLOYEE = 1,			// добавить сотрудника
	ADD_DEPARTMENT,				// создать департамент

	PRINT_ALL_EMPLOYEES,
	PRINT_EMPLOYEES_FROM_DEPARTMENT,
	PRINT_ALL_DEPARTMENTS,
	

	FIND_EMPLOYEE,						// найти сотрудника
	FIND_DEPARTMENT,

	EDIT_EMPLOYEE_PROFILE,
	EDIT_DEPARTMENT_RROFILE,

	SORT_EMPLOYEES,						// сортировать профили сотрудников
	SORT_DEPARTMENTS,

	SAVE,						// сохранить данные в файле
	DOWNLOAD,					// загрузить данные из файла

	EXIT						// выйти из приложния
};

enum class EMPLOYEE_PROFILE_MODE				// режимы редактивание профиля
{
	EDIT_ALL = 1,				// редактировать все
	EDIT_NAME,					// редактировать имя
	EDIT_AGE,					// редактировать возраст
	EDIT_WORK_POSITION,				// редактировать должность
	EDIT_SALARY,				// редактировать зарплату
	EDIT_WORK_EXPERIENCE,			// редактировать суммарный опыт работы
	EDIT_WORK_DEPARTMENT,			// редактировать департамент работы

	DELETE_EMPLOYEE,						// удалить профиль

	BACK						// выйти из режима редактирования профиля
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

enum class EMPLOYEE_FIND_MODE					// режимы поиска сотрудника
{
	ID = 1,							// по id
	NAME,					// по имени
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