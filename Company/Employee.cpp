/*
======================================================Employee.cpp======================================================
class Employee - описывает сотрудника:

public:
	1) имеет функцию РЕДАКТИРОВАНИЯ полей edit_employee
	2) имеет функцию ПЕЧАТИ полей print_employee
	3) имеет перегруженные операции сравнения !=, == и  вывода

	exceptions:
		a) при некорректных значениях ввода полей класса функции set, конструкторы Employee и функция edit_employee
			вызывают исключение std::exception("Неверный ввод!!!")

private:
	4) содержит вложенный класс Employee_ID - данный класс отвечает за id сотрудника:

		a) при создании сотрудника id присваивается ему автоматически следующее по очереди начиная с 1 (next_employee_id)
		b) при удалении сотрудника его id освобождается и добавляется в список свободных (available_employee_id)
		c) если список свободных id не пустой, то следующему сотруднику достается id из начала этого списка
		d) имеется возможность присвоить сотруднику произвольное id, но в таком случае может быть вызвано исключение (если данное id уже используется).
	Если id свободно, то сотрудник получает его, в зависимости от выбранного id могут изменится следующее по очереди id/список свободных id,
	так, чтобы все сотрудники получали id без "пробелов"
		e) имеется возможность получить id сотрудника через get_employee_id()

		exceptions:
			I) при уже занятом id сотрудника конструктор Employee_ID(size_t employee_id)
				вызывает исключение std::exception("Ошибка создания сотрудника (этот id уже занят)")

======================================================================================================================
*/

#include "Company.h"


//public:
Company::Department::Employee::Employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience) :
	employee_id()
{
	set_employee_name(employee_name);
	set_employee_age(employee_age);
	set_employee_work_position(employee_work_position);
	set_employee_salary(employee_salary);
	set_employee_work_experience(employee_work_experience);
}

Company::Department::Employee::Employee(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience) :
	employee_id(employee_id)
{
	set_employee_age(employee_age);
	set_employee_salary(employee_salary);
	set_employee_work_experience(employee_work_experience);
	set_employee_work_position(employee_work_position);
	set_employee_name(employee_name);
}
Company::Department::Employee::Employee(const Employee& employee)
{
	throw std::exception("Для данного объекта не может быть конструктора копирования, ведь иначе будут 2 объекта с одинаковым id");
}

Company::Department::Employee::~Employee()
{}


std::string Company::Department::Employee::get_employee_name() const
{
	return employee_name;
}
size_t Company::Department::Employee::get_employee_age() const
{
	return employee_age;
}
std::string Company::Department::Employee::get_employee_work_position() const
{
	return employee_work_position;
}
size_t Company::Department::Employee::get_employee_salary() const
{
	return employee_salary;
}
size_t Company::Department::Employee::get_employee_work_experience() const
{
	return employee_work_experience;
}

size_t Company::Department::Employee::get_employee_id() const
{
	return employee_id.get_employee_id();
}


void Company::Department::Employee::edit_employee(std::string new_employee_name, size_t new_employee_age, std::string new_employee_work_position, size_t new_employee_salary, size_t new_employee_work_experience)
{
	set_employee_name(new_employee_name);
	set_employee_age(new_employee_age);
	set_employee_work_position(new_employee_work_position);
	set_employee_salary(new_employee_salary);
	set_employee_work_experience(new_employee_work_experience);
}


void Company::Department::Employee::print_employee() const
{
	std::cout << get_employee_name() << ", " << get_employee_age() << " y.o. (ID " << std::setw(6) << std::setfill('0') << get_employee_id() << ")\n";
	std::cout << "\t\twork position : " << get_employee_work_position() << std::endl;
	std::cout << "\t\tsalary : " << get_employee_salary() << std::endl;
	std::cout << "\t\twork experience : " << get_employee_work_experience() << std::endl;
}


//private:
void Company::Department::Employee::set_employee_name(std::string new_employee_name)
{
	if (this->employee_name == new_employee_name)
		return;

	if (new_employee_name == "")
		throw std::exception("Неверный ввод!!!");

	this->employee_name = new_employee_name;
}
void Company::Department::Employee::set_employee_age(size_t new_employee_age)
{
	if (this->employee_age == new_employee_age)
		return;

	if (!new_employee_age)
		throw std::exception("Неверный ввод!!!");

	this->employee_age = new_employee_age;
}
void Company::Department::Employee::set_employee_work_position(std::string new_employee_work_position)
{
	if (this->employee_work_position == new_employee_work_position)
		return;

	if (new_employee_work_position == "")
		throw std::exception("Неверный ввод!!!");

	this->employee_work_position = new_employee_work_position;
}
void Company::Department::Employee::set_employee_salary(size_t new_employee_salary)
{
	if (this->employee_salary == new_employee_salary)
		return;

	this->employee_salary = new_employee_salary;
}
void Company::Department::Employee::set_employee_work_experience(size_t new_employee_work_experience)
{
	if (this->employee_work_experience == new_employee_work_experience)
		return;

	this->employee_work_experience = new_employee_work_experience;
}