/*
======================================================Employee.cpp======================================================
class Employee - ��������� ����������:

public:
	1) ����� ������� �������������� ����� edit_employee
	2) ����� ������� ������ ����� print_employee
	3) ����� ������������� �������� ��������� !=, == �  ������

	exceptions:
		a) ��� ������������ ��������� ����� ����� ������ ������� set, ������������ Employee � ������� edit_employee
			�������� ���������� std::exception("�������� ����!!!")

private:
	4) �������� ��������� ����� Employee_ID - ������ ����� �������� �� id ����������:

		a) ��� �������� ���������� id ������������� ��� ������������� ��������� �� ������� ������� � 1 (next_employee_id)
		b) ��� �������� ���������� ��� id ������������� � ����������� � ������ ��������� (available_employee_id)
		c) ���� ������ ��������� id �� ������, �� ���������� ���������� ��������� id �� ������ ����� ������
		d) ������� ����������� ��������� ���������� ������������ id, �� � ����� ������ ����� ���� ������� ���������� (���� ������ id ��� ������������).
	���� id ��������, �� ��������� �������� ���, � ����������� �� ���������� id ����� ��������� ��������� �� ������� id/������ ��������� id,
	���, ����� ��� ���������� �������� id ��� "��������"
		e) ������� ����������� �������� id ���������� ����� get_employee_id()

		exceptions:
			I) ��� ��� ������� id ���������� ����������� Employee_ID(size_t employee_id)
				�������� ���������� std::exception("������ �������� ���������� (���� id ��� �����)")

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
	throw std::exception("��� ������� ������� �� ����� ���� ������������ �����������, ���� ����� ����� 2 ������� � ���������� id");
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
		throw std::exception("�������� ����!!!");

	this->employee_name = new_employee_name;
}
void Company::Department::Employee::set_employee_age(size_t new_employee_age)
{
	if (this->employee_age == new_employee_age)
		return;

	if (!new_employee_age)
		throw std::exception("�������� ����!!!");

	this->employee_age = new_employee_age;
}
void Company::Department::Employee::set_employee_work_position(std::string new_employee_work_position)
{
	if (this->employee_work_position == new_employee_work_position)
		return;

	if (new_employee_work_position == "")
		throw std::exception("�������� ����!!!");

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