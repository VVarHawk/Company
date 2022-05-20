#include "Company.h"


//public:
Company::Department::Employee::Employee_ID::Employee_ID()
{
	if (available_employee_id.size())
	{
		employee_id = *available_employee_id.begin();
		available_employee_id.erase(available_employee_id.begin());
	}
	else
		employee_id = next_employee_id++;
}
Company::Department::Employee::Employee_ID::Employee_ID(size_t employee_id)
{
	if (employee_id == next_employee_id)
	{
		this->employee_id = next_employee_id++;
	}
	else if(employee_id > next_employee_id)
	{
		for (size_t id = next_employee_id; id < employee_id; ++id)
		{
			available_employee_id.push_back(id);
		}
		this->employee_id = employee_id;
		next_employee_id = employee_id + 1;
	}
	else
	{
		if(std::find(available_employee_id.begin(), available_employee_id.end(), employee_id) != available_employee_id.end())
		{
			available_employee_id.remove(employee_id);
			this->employee_id = employee_id;
		}
		else
			throw std::runtime_error("Error creating employee (this id is already taken)");
	}
}
Company::Department::Employee::Employee_ID::Employee_ID(const Employee::Employee_ID& employee_id)
{
	throw std::runtime_error("Error creating employee");
	// There cannot be a copy constructor for this object, because otherwise there will be 2 objects with the same id
}

Company::Department::Employee::Employee_ID::~Employee_ID()
{
	available_employee_id.push_back(employee_id);
}

size_t Company::Department::Employee::Employee_ID::get_employee_id() const
{
	return employee_id;
}

//private:
size_t Company::Department::Employee::Employee_ID::next_employee_id = 1;
std::list<size_t> Company::Department::Employee::Employee_ID::available_employee_id = {};