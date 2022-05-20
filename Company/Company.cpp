#include "Company.h"




//public:
Company::Company() :
	is_copy(false)
{
	create_department_with_id(NULL, "available employees");
}

Company::Company(const Company& company) : 
	departments(company.departments),
	is_copy(true)
{}

Company::~Company()
{
	if (!is_copy)
	{
		for (Department* dep : departments)
		{
			delete dep;
		}
		departments.clear();
	}
	else
	{
		departments.clear();
	}
}


std::string Company::get_employee_name(size_t employee_id) const
{
	return find_department(get_employee_department_id(employee_id))->get_employee_name(employee_id);
}
size_t Company::get_employee_age(size_t employee_id) const
{
	return find_department(get_employee_department_id(employee_id))->get_employee_age(employee_id);
}
std::string Company::get_employee_work_position(size_t employee_id) const
{
	return find_department(get_employee_department_id(employee_id))->get_employee_work_position(employee_id);
}
size_t Company::get_employee_salary(size_t employee_id) const
{
	return find_department(get_employee_department_id(employee_id))->get_employee_salary(employee_id);
}
size_t Company::get_employee_work_experience(size_t employee_id) const
{
	return find_department(get_employee_department_id(employee_id))->get_employee_work_experience(employee_id);
}

size_t Company::get_employee_department_id(size_t employee_id) const
{
	for (Department* dep : departments)
	{
		if (dep->is_employee_work_here(employee_id))
			return dep->get_department_id();
	}
	throw std::exception("This employee was not found");
}

std::string Company::get_department_name(size_t department_id) const
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
		return dep->get_department_name();
	else
		throw std::exception("This department was not found");
}
size_t Company::get_department_head_id(size_t department_id) const
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
		return dep->get_department_head_id();
	else
		throw std::exception("This department was not found");
}
size_t Company::get_department_n_employees(size_t department_id) const
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
		return dep->get_department_n_employees();
	else
		throw std::exception("This department was not found");
}
size_t Company::get_department_id(size_t department_id) const
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
		return dep->get_department_id();
	else
		throw std::exception("This department was not found");
}

size_t Company::get_n_employees() const
{
	size_t n_em = 0;
	for (Department* dep : departments)
	{
		n_em += dep->get_department_n_employees();
	}
	return n_em;
}
size_t Company::get_n_departments() const
{
	return departments.size() - 1;
}


void Company::create_employee_with_id(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience, size_t employee_department_id)
{
	Department* dep = find_department(employee_department_id);
	if (dep != nullptr)
		dep->create_employee_with_id(employee_id, employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience);
	else
		throw std::exception("This department was not found");
}
size_t Company::create_employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience, size_t employee_department_id)
{
	Department* dep = find_department(employee_department_id);
	if (dep != nullptr)
	{
		return dep->create_employee(employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience);
	}
	else
		throw std::exception("This department was not found");
}

void Company::create_department_with_id(size_t department_id, std::string department_name)
{
	departments.push_back(new Department(department_id, department_name));
}
size_t Company::create_department(std::string department_name)
{
	Department* dep = new Department(department_name);
	departments.push_back(dep);
	return dep->get_department_id();
}


void Company::transfer_employee(size_t employee_id, size_t new_department_id)
{
	Department* dep_to = find_department(new_department_id);
	if(dep_to != nullptr)
	{
		Department* dep_from = find_department(get_employee_department_id(employee_id));

		if (dep_from != nullptr)
		{
			if (dep_to->get_department_id() == dep_from->get_department_id())
				throw std::exception("This employee already works in this department");
			else
			{
				std::string employee_name = dep_from->get_employee_name(employee_id);
				size_t employee_age = dep_from->get_employee_age(employee_id);
				std::string employee_work_position = dep_from->get_employee_work_position(employee_id);
				size_t employee_salary = dep_from->get_employee_salary(employee_id);
				size_t employee_work_experience = dep_from->get_employee_work_experience(employee_id);

				dep_from->delete_employee(employee_id);
				dep_to->create_employee_with_id(employee_id, employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience);
			}
		}
		else
			throw std::exception("This department was not found");
	}
	else
		throw std::exception("This department was not found");
	
}

void Company::edit_employee(size_t employee_id, std::string new_employee_name, size_t new_employee_age, std::string new_employee_work_position, size_t new_employee_salary, size_t new_employee_work_experience)
{
	find_department(get_employee_department_id(employee_id))->edit_employee
	(
		employee_id,
		new_employee_name,
		new_employee_age,
		new_employee_work_position,
		new_employee_salary,
		new_employee_work_experience
	);

}
void Company::edit_department(size_t department_id, std::string new_department_name, size_t new_department_head_id)
{
	Department* dep = find_department(department_id);
	if (dep != nullptr)
	{
		dep->edit_department(new_department_name, new_department_head_id);
	}
	else
		throw std::exception("This department was not found");
}

void Company::delete_employee(size_t employee_id)
{
	find_department(get_employee_department_id(employee_id))->delete_employee(employee_id);
}
void Company::delete_department(size_t department_id)
{
	Department* dep = find_department(department_id);
	if (dep != nullptr)
	{
		departments.remove(dep);
		delete dep;
	}
	else
		throw std::exception("This department was not found");
}


void Company::print_employee(size_t employee_id) const
{
	find_department(get_employee_department_id(employee_id))->print_employee(employee_id);

}
void Company::print_department(size_t department_id) const 
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
		dep->print_department();
	else
		throw std::exception("This department was not found");
}

void Company::print_all_employees() const
{
	for (Department* dep : departments)
	{
		if (dep->get_department_id() != NULL || dep->get_department_n_employees() != NULL)
		{
			dep->print_department();
			std::cout << std::endl;
			dep->print_all_employees_from_department();
			std::cout << std::endl << std::endl;
		}
	}
	
}
void Company::print_all_employees_from_department(size_t department_id) const
{
	const Department* dep = find_department(department_id);
	if (dep != nullptr)
	{
		dep->print_department();
		dep->print_all_employees_from_department();
	}
	else
		throw std::exception("This department was not found");
}
void Company::print_all_departments() const
{
	for(Department* dep : departments)
	{
		if (dep->get_department_id() != NULL)
		{
			dep->print_department();
		}	
	}
}

void Company::print_employee_with_name(std::string employee_name) const
{
	for (Department* dep : departments)
	{
		dep->print_employee_with_name(employee_name);
	}
}
void Company::print_employee_with_age(size_t under_age, size_t over_age) const
{
	for (Department* dep : departments)
	{
		dep->print_employee_with_age(under_age, over_age);
	}
}
void Company::print_employee_with_work_position(std::string employee_work_position) const
{
	for (Department* dep : departments)
	{
		dep->print_employee_with_work_position(employee_work_position);
	}
}
void Company::print_employee_with_salary(size_t from_salary, size_t to_salary) const
{
	for (Department* dep : departments)
	{
		dep->print_employee_with_salary(from_salary, to_salary);
	}
}
void Company::print_employee_with_work_experience(size_t from_work_experience, size_t to_work_experience) const
{
	for (Department* dep : departments)
	{
		dep->print_employee_with_work_experience(from_work_experience, to_work_experience);
	}
}

void Company::print_department_with_name(std::string name) const
{
	for (Department* dep : departments)
	{
		if (dep->get_department_name() == name && dep->get_department_id() != 0)
			dep->print_department();
	}
}
void Company::print_department_with_n_employees(size_t under, size_t over) const
{
	for (Department* dep : departments)
	{
		size_t n_em = dep->get_department_n_employees();
		if (n_em >= under && n_em <= over && dep->get_department_id() != 0)
			dep->print_department();
	}
}


void Company::sort_employees_by_id()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_id, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}
void Company::sort_employees_by_name()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_name, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}
void Company::sort_employees_by_age()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_age, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}
void Company::sort_employees_by_work_position()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_work_position, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}
void Company::sort_employees_by_salary()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_salary, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}
void Company::sort_employees_by_work_experience()
{
	std::list<std::thread*> th;
	for (Department* dep : departments)
	{
		th.push_back(new std::thread(&Company::Department::sort_employees_from_department_by_work_experience, dep));
	}
	for (std::thread* t : th)
	{
		t->join();
	}
	while (th.size())
	{
		std::thread* t = th.front();
		th.remove(t);
		delete t;
	}
}

void Company::sort_departments_by_id()
{
	departments.sort([](const Department* dep_1, const Department* dep_2)
		{
			return dep_1->get_department_id() < dep_2->get_department_id();
		}
	);
}
void Company::sort_departments_by_name()
{
	departments.sort([](const Department* dep_1, const Department* dep_2)
		{
			return dep_1->get_department_name() < dep_2->get_department_name();
		}
	);
}
void Company::sort_departments_by_n_employees()
{
	departments.sort([](const Department* dep_1, const Department* dep_2)
		{
			return dep_1->get_department_n_employees() < dep_2->get_department_n_employees();
		}
	);
}

void Company::download(std::string file_name)
/*
n_departments

department : id name n_employees department_head_id(or 0 if he is not)
	employee : id name age work_position salary work_experience
	...
...
*/
{
	for (Department* dep : departments)
	{
		delete dep;
	}
	departments.clear();


	std::ifstream in(file_name);
	if (!in.is_open())
		throw std::exception("Failed to open file");

	try
	{
		size_t n_departments; in >> n_departments;

		for (size_t n_dep = 0; n_dep < n_departments; ++n_dep)
		{
			size_t department_id, department_n_employees, department_head_id;
			std::string department_name;

			in >> department_id;
			in.ignore(std::numeric_limits<char>::max(), '\n'); getline(in, department_name);
			in >> department_n_employees >> department_head_id;

			create_department_with_id(department_id, department_name);

			for (size_t n_em = 1; n_em <= department_n_employees; ++n_em)
			{
				size_t employee_id, employee_age, employee_salary, employee_work_experience;
				std::string employee_name, employee_work_position;

				in >> employee_id;
				in.ignore(std::numeric_limits<char>::max(), '\n'); getline(in, employee_name);
				in >> employee_age;
				in.ignore(std::numeric_limits<char>::max(), '\n'); getline(in, employee_work_position);
				in >> employee_salary >> employee_work_experience;

				create_employee_with_id(employee_id, employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience, department_id);
			}
			find_department(department_id)->edit_department(department_name, department_head_id);
		}

		in.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}
void Company::save(std::string file_name) const
{
	std::ofstream out(file_name);

	out << get_n_departments() + 1 << std::endl;

	for (Department* dep : departments)
		out << *dep;

	out.close();
}


//private:
Company::Department* Company::find_department(size_t department_id)
{
	std::list<Department*>::iterator dep = find_if(departments.begin(), departments.end(),
		[department_id](Department* dep)
		{
			return dep->get_department_id() == department_id;
		}
	);

	if (dep != departments.end())
		return *dep;
	else
		return nullptr;
}
const Company::Department* Company::find_department(size_t department_id) const
{
	std::list<Department*>::const_iterator dep = find_if(departments.begin(), departments.end(),
		[department_id](Department* dep)
		{
			return dep->get_department_id() == department_id;
		}
	);

	if (dep != departments.end())
		return *dep;
	else
		return nullptr;
}