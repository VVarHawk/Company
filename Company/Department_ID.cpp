#include "Company.h"


//public:
Company::Department::Department_ID::Department_ID()
{
	if (available_department_id.size())
	{
		department_id = *available_department_id.begin();
		available_department_id.erase(available_department_id.begin());
	}
	else
		department_id = next_department_id++;
}
Company::Department::Department_ID::Department_ID(size_t department_id)
{
	if (department_id == next_department_id)
	{
		this->department_id = next_department_id++;
	}
	else if (department_id > next_department_id)
	{
		for (size_t id = next_department_id; id < department_id; ++id)
		{
			available_department_id.push_back(department_id);
		}
		this->department_id = department_id;
		next_department_id = department_id + 1;
	}
	else
	{
		if (std::find(available_department_id.begin(), available_department_id.end(), department_id) != available_department_id.end())
		{
			available_department_id.remove(department_id);
			this->department_id = department_id;
		}
		else
			throw std::exception("Ошибка создания департамента (этот id уже занят)");
	}
}

Company::Department::Department_ID::Department_ID(const Department_ID& department_id)
{
	throw std::exception("Для данного объекта не может быть конструктора копирования, ведь иначе будут 2 объекта с одинаковым id");
}

Company::Department::Department_ID::~Department_ID()
{
	available_department_id.push_back(department_id);
}

size_t Company::Department::Department_ID::get_department_id() const
{
	return department_id;
}

//private:
size_t Company::Department::Department_ID::next_department_id = 0;
std::list<size_t> Company::Department::Department_ID::available_department_id {};