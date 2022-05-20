#include "Company.h"



//public:
Company::Department::Department(std::string department_name) :
	department_id(),
	is_copy(false)
{
	set_department_head(NULL);
	set_department_name(department_name);
}
Company::Department::Department(size_t department_id, std::string department_name) :
	department_id(department_id),
	is_copy(false)
{
	set_department_head(NULL);
	set_department_name(department_name);
}

Company::Department::Department(const Department& department) :
	employees(department.employees),
	department_head(department.department_head),
	is_copy(true)
{}

Company::Department::~Department()
{
	if (!is_copy)
	{
		set_department_head(NULL);
		for (Employee* em : employees)
		{
			delete em;
		}
		employees.clear();

	}
	else
	{
		employees.clear();
	}
	
}


std::string Company::Department::get_department_name() const
{
	return department_name;
}
size_t Company::Department::get_department_head_id() const
{
	if (department_head != nullptr)
		return department_head->get_employee_id();
	else
		return NULL;
}
size_t Company::Department::get_department_n_employees() const
{
	return employees.size();
}
size_t Company::Department::get_department_id() const
{
	return department_id.get_department_id();
}

std::string Company::Department::get_employee_name(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
		return em->get_employee_name();
	else
		throw std::runtime_error("This employee was not found");
}
size_t Company::Department::get_employee_age(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
		return em->get_employee_age();
	else
		throw std::runtime_error("This employee was not found");
}
std::string Company::Department::get_employee_work_position(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
		return em->get_employee_work_position();
	else
		throw std::runtime_error("This employee was not found");
}
size_t Company::Department::get_employee_salary(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
		return em->get_employee_salary();
	else
		throw std::runtime_error("This employee was not found");
}
size_t Company::Department::get_employee_work_experience(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
		return em->get_employee_work_experience();
	else
		throw std::runtime_error("This employee was not found");
}


bool Company::Department::is_employee_work_here(size_t employee_id) const
{
	if (find_employee(employee_id) != nullptr)
		return true;
	else
		return false;
}


void Company::Department::create_employee_with_id(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience)
{
	employees.push_back(new Employee(employee_id, employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience));
}
size_t Company::Department::create_employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience)
{
	Employee* new_employee = new Employee(employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience);
	employees.push_back(new_employee);
	return new_employee->get_employee_id();
}


void Company::Department::edit_employee(size_t employee_id, std::string name, size_t age, std::string work_position, size_t salary, size_t work_experience)
{
	Employee* em = find_employee(employee_id);
	if (em != nullptr)
	{
		em->edit_employee(name, age, work_position, salary, work_experience);
	}
	else
		throw std::runtime_error("This employee was not found");
}
void Company::Department::edit_department(std::string name, size_t department_head_id)
{
	set_department_name(name);
	set_department_head(department_head_id);
}

void Company::Department::delete_employee(size_t employee_id)
{
	Employee* em = find_employee(employee_id);
	if (em != nullptr)
	{
		employees.remove(em);
		if (get_department_head_id() == em->get_employee_id())
			set_department_head(NULL);
		delete em;
	}
	else
		throw std::runtime_error("This employee was not found");
}


void Company::Department::print_employee(size_t employee_id) const
{
	const Employee* em = find_employee(employee_id);
	if (em != nullptr)
	{
		em->print_employee();
	}
	else
		throw std::runtime_error("This employee was not found");
}
void Company::Department::print_all_employees_from_department() const
{
	for(Employee* em : employees)
	{
		em->print_employee();
	}
}

void Company::Department::print_employee_with_name(std::string employee_name) const
{
	for (Employee* em : employees)
	{
		if (em->get_employee_name() == employee_name)
			em->print_employee();
	}
}
void Company::Department::print_employee_with_age(size_t under_age, size_t over_age) const
{
	for (Employee* em : employees)
	{
		size_t em_age = em->get_employee_age();
		if(em_age >= under_age && em_age <= over_age)
			em->print_employee();
	}
}
void Company::Department::print_employee_with_work_position(std::string employee_work_position) const
{
	for (Employee* em : employees)
	{
		if (em->get_employee_work_position() == employee_work_position)
			em->print_employee();
	}
}
void Company::Department::print_employee_with_salary(size_t from_salary, size_t to_salary) const
{
	for (Employee* em : employees)
	{
		size_t em_salary = em->get_employee_salary();
		if (em_salary >= from_salary && em_salary <= to_salary)
			em->print_employee();
	}
}
void Company::Department::print_employee_with_work_experience(size_t	from_work_experience, size_t to_work_experience) const
{
	for (Employee* em : employees)
	{
		size_t em_ex = em->get_employee_work_experience();
		if (em_ex >= from_work_experience && em_ex <= to_work_experience)
			em->print_employee();
	}
}

void Company::Department::print_department() const
{
	if (get_department_id() == NULL)
	{
		std::cout << get_department_name() << std::endl;
	}
	else
	{
		std::cout << "Department " << get_department_name() << ", (ID " << std::setw(2) << std::setfill('0') << get_department_id() << "), " << get_department_n_employees() << " employees working";
		if (department_head != nullptr)
		{
			std::cout << ", department head : " << department_head->get_employee_name() << ", (ID " << department_head->get_employee_id() << ")" << std::endl;
		}
		else
			std::cout << ", department head : none" << std::endl;
	}
	
}


void Company::Department::sort_employees_from_department_by_id()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_id() < em_2->get_employee_id();
		}
	);
}
void Company::Department::sort_employees_from_department_by_name()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_name() < em_2->get_employee_name();
		}
	);
}
void Company::Department::sort_employees_from_department_by_age()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_age() < em_2->get_employee_age();
		}
	);
}
void Company::Department::sort_employees_from_department_by_work_position()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_work_position() < em_2->get_employee_work_position();
		}
	);
}
void Company::Department::sort_employees_from_department_by_salary()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_salary() < em_2->get_employee_salary();
		}
	);
}
void Company::Department::sort_employees_from_department_by_work_experience()
{
	employees.sort([](const Employee* em_1, const Employee* em_2)
		{
			return em_1->get_employee_work_experience() < em_2->get_employee_work_experience();
		}
	);
}


//private:
void Company::Department::set_department_name(std::string department_name)
{
	if (department_name == "")
		throw std::runtime_error("Incorrect input!!!");

	this->department_name = department_name;
}
void Company::Department::set_department_head(size_t department_head_id)
{
	if (department_head_id == NULL)
		department_head = nullptr;
	else
	{
		Employee* dep_head = find_employee(department_head_id);
		if (dep_head != nullptr)
		{
			department_head = dep_head;
		}
		else
			throw std::runtime_error("This employee was not found");
	}
}


Company::Department::Employee* Company::Department::find_employee(size_t employee_id)
{
	std::list<Employee*>::iterator em = std::find_if(employees.begin(), employees.end(), 
		[employee_id](Employee* em)
		{
			return em->get_employee_id() == employee_id;
		}
	);

	if (em != employees.end())
		return *em;
	else
		return nullptr;
}
const Company::Department::Employee* Company::Department::find_employee(size_t employee_id) const
{
	std::list<Employee*>::const_iterator em = std::find_if(employees.begin(), employees.end(), 
		[employee_id](Employee* em)
		{
			return em->get_employee_id() == employee_id;
		}
	);

	if (em != employees.end())
		return *em;
	else
		return nullptr;
}