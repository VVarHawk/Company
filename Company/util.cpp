#include "util.h"



MENU_MODE main_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "------------------*MAIN MENU*------------------\n";
			std::cout << "1.  Add new employee\n";
			std::cout << "2.  Add new department\n";
			std::cout << "3.  Print all employees\n";
			std::cout << "4.  Print all employees from department\n";
			std::cout << "5.  Print all departments\n";
			std::cout << "6.  Find employee\n";
			std::cout << "7.  Find department\n";
			std::cout << "8.  Edit employee profile\n";
			std::cout << "9.  Edit department profile\n";
			std::cout << "10. Sort employee profiles\n";
			std::cout << "11. Sort department profiles\n";
			std::cout << "12. Save\n";
			std::cout << "13. Download\n";
			std::cout << "14. Exit\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return MENU_MODE::ADD_EMPLOYEE;
			case 2:
				return MENU_MODE::ADD_DEPARTMENT;
			case 3:
				return MENU_MODE::PRINT_ALL_EMPLOYEES;
			case 4:
				return MENU_MODE::PRINT_EMPLOYEES_FROM_DEPARTMENT;
			case 5:
				return MENU_MODE::PRINT_ALL_DEPARTMENTS;
			case 6:
				return MENU_MODE::FIND_EMPLOYEE;
			case 7:
				return MENU_MODE::FIND_DEPARTMENT;
			case 8:
				return MENU_MODE::EDIT_EMPLOYEE_PROFILE;
			case 9:
				return MENU_MODE::EDIT_DEPARTMENT_RROFILE;
			case 10:
				return MENU_MODE::SORT_EMPLOYEES;
			case 11:
				return MENU_MODE::SORT_DEPARTMENTS;
			case 12:
				return MENU_MODE::SAVE;
			case 13:
				return MENU_MODE::DOWNLOAD;
			case 14:
				return MENU_MODE::EXIT;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}

}

EMPLOYEE_PROFILE_MODE employee_profile_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "-------------*EDIT EMPLOYEE PROFILE*------------\n";
			std::cout << "1. Edit all\n";
			std::cout << "2. Edit name\n";
			std::cout << "3. Edit age\n";
			std::cout << "4. Edit work position\n";
			std::cout << "5. Edit salary\n";
			std::cout << "6. Edit work experience\n";
			std::cout << "7. Edit department\n";
			std::cout << "8. Delete profile\n";
			std::cout << "9. Back\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return EMPLOYEE_PROFILE_MODE::EDIT_ALL;
			case 2:
				return EMPLOYEE_PROFILE_MODE::EDIT_NAME;
			case 3:
				return EMPLOYEE_PROFILE_MODE::EDIT_AGE;
			case 4:
				return EMPLOYEE_PROFILE_MODE::EDIT_WORK_POSITION;
			case 5:
				return EMPLOYEE_PROFILE_MODE::EDIT_SALARY;
			case 6:
				return EMPLOYEE_PROFILE_MODE::EDIT_WORK_EXPERIENCE;
			case 7:
				return EMPLOYEE_PROFILE_MODE::EDIT_WORK_DEPARTMENT;
			case 8:
				return EMPLOYEE_PROFILE_MODE::DELETE_EMPLOYEE;
			case 9:
				return EMPLOYEE_PROFILE_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}
DEPARTMENT_PROFILE_MODE department_profile_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "------------*EDIT DEPARTMENT PROFILE*-----------\n";
			std::cout << "1. Edit all\n";
			std::cout << "2. Edit name\n";
			std::cout << "3. Change department head\n";
			std::cout << "4. Delete department head\n";
			std::cout << "5. Delete department profile\n";
			std::cout << "6. Back\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return DEPARTMENT_PROFILE_MODE::EDIT_ALL;
			case 2:
				return DEPARTMENT_PROFILE_MODE::EDIT_NAME;
			case 3:
				return DEPARTMENT_PROFILE_MODE::EDIT_DEPARTMENT_HEAD;
			case 4:
				return DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT_HEAD;
			case 5:
				return DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT;
			case 6:
				return DEPARTMENT_PROFILE_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}

EMPLOYEE_FIND_MODE employee_find_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "----------------*FIND EMPLOYEE*-----------------\n";
			std::cout << "1. By id\n";
			std::cout << "2. By name\n";
			std::cout << "3. By age\n";
			std::cout << "4. By work position\n";
			std::cout << "5. By salary\n";
			std::cout << "6. Back\n";
			std::cout << "------------------------------------------------\n";
			

			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return EMPLOYEE_FIND_MODE::ID;
			case 2:
				return EMPLOYEE_FIND_MODE::NAME;
			case 3:
				return EMPLOYEE_FIND_MODE::AGE;
			case 4:
				return EMPLOYEE_FIND_MODE::WORK_POSITION;
			case 5:
				return EMPLOYEE_FIND_MODE::SALARY;
			case 6:
				return EMPLOYEE_FIND_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}
DEPARTMENT_FIND_MODE department_find_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "---------------*FIND DEPARMTENT*----------------\n";
			std::cout << "1. By id\n";
			std::cout << "2. By name\n";
			std::cout << "3. By number of employees\n";//?
			std::cout << "4. Back\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return DEPARTMENT_FIND_MODE::ID;
			case 2:
				return DEPARTMENT_FIND_MODE::NAME;
			case 3:
				return DEPARTMENT_FIND_MODE::N_EMPLOYEES;
			case 4:
				return DEPARTMENT_FIND_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}

EMPLOYEE_SORT_MODE employee_sort_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "----------------*SORT EMPLOYEES*----------------\n";
			std::cout << "1. By id\n";
			std::cout << "2. By name\n";
			std::cout << "3. By age\n";
			std::cout << "4. By work position\n";
			std::cout << "5. By salary\n";
			std::cout << "6. By work experience\n";
			std::cout << "7. Back\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return EMPLOYEE_SORT_MODE::ID;
			case 2:
				return EMPLOYEE_SORT_MODE::NAME;
			case 3:
				return EMPLOYEE_SORT_MODE::AGE;
			case 4:
				return EMPLOYEE_SORT_MODE::WORK_POSITION;
			case 5:
				return EMPLOYEE_SORT_MODE::SALARY;
			case 6:
				return EMPLOYEE_SORT_MODE::WORK_EXPERIENCE;
			case 7:
				return EMPLOYEE_SORT_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}
DEPARTMENT_SORT_MODE department_sort_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "---------------*SORT DEPARTMENT*----------------\n";
			std::cout << "1. By id\n";
			std::cout << "2. By name\n";
			std::cout << "3. By number of employees\n";
			std::cout << "4. Back\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Select mode: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::runtime_error("Incorrect input");
			case 1:
				return DEPARTMENT_SORT_MODE::ID;
			case 2:
				return DEPARTMENT_SORT_MODE::NAME;
			case 3:
				return DEPARTMENT_SORT_MODE::N_EMPLOYEES;
			case 4:
				return DEPARTMENT_SORT_MODE::BACK;
			default:
				throw std::runtime_error("This function is not in the menu");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype\n\n\n\n";
		}
	}
}


std::string input_string()
{
	for (;;)
	{
		try
		{
			std::string str;
			std::getline(std::cin, str);

			if (str == std::string())
				throw std::runtime_error("Incorrect string input");
			return str;
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype: ";
		}
	}
	
}
size_t input_size_t()
{
	for (;;)
	{
		try
		{
			long long num;
			if (std::cin >> num && num >= 0)
			{
				std::cin.ignore(std::numeric_limits<char>::max(), '\n');
				return (size_t)num;
			}
			else
				throw std::runtime_error("Incorrect number input");
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Retype: ";
		}
	}
	
}