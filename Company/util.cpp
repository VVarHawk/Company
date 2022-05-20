#include "util.h"



MENU_MODE main_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "-----------------*ГЛАВНОЕ МЕНЮ*-----------------\n";
			std::cout << "1. Add new employee\n";
			std::cout << "2. Add new department\n";
			std::cout << "3. Print all employees\n";
			std::cout << "4. Print all employees from department\n";
			std::cout << "5. Print all departments\n";
			std::cout << "6. Найти сотрудника\n";
			std::cout << "7. Найти департамент\n";
			std::cout << "8. Редактировать профиль сотрудника\n";
			std::cout << "9. Редактировать профиль департамента\n";
			std::cout << "10. Сортировать профили сотрудников\n";
			std::cout << "11. Сортировать профили департаментов\n";
			std::cout << "12. Сохранить\n";
			std::cout << "13. Загрузить базу данных\n";
			std::cout << "14. Выход\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Выберите режим: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
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
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}

}

EMPLOYEE_PROFILE_MODE employee_profile_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "-------*Редактирование профиля сотрудника*------\n";
			std::cout << "1. Редактировать все\n";
			std::cout << "2. Изменить имя\n";
			std::cout << "3. Изменить возраст\n";
			std::cout << "4. Изменить должность\n";
			std::cout << "5. Изменить зарплату\n";
			std::cout << "6. Изменить опыт работы\n";
			std::cout << "7. Изменить департамент работы\n";
			std::cout << "8. Удалить профиль\n";
			std::cout << "9. Назад\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Введите режим редактирования профиля : ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
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
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}
}
DEPARTMENT_PROFILE_MODE department_profile_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "------*Редактирование профиля департамента*-----\n";
			std::cout << "1. Редактировать все\n";
			std::cout << "2. Изменить имя\n";
			std::cout << "3. Изменить главу департамента\n";
			std::cout << "4. Убрать главу департамента\n";
			std::cout << "5. Удалить департамент\n";
			std::cout << "6. Назад\n";
			std::cout << "------------------------------------------------\n";

			std::cout << "Введите режим редактирования профиля : ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
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
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}
}

EMPLOYEE_FIND_MODE employee_find_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "---------------*Поиск сотрудника*---------------\n";
			std::cout << "1. По ID\n";
			std::cout << "2. По имени\n";
			std::cout << "3. По возрасту\n";
			std::cout << "4. По должности\n";
			std::cout << "5. По зарплате\n";
			std::cout << "6. Назад\n";
			std::cout << "------------------------------------------------\n";
			

			std::cout << "Введите параметр поиска сотрудника: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
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
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}
}
DEPARTMENT_FIND_MODE department_find_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "--------------*Поиск департамента*--------------\n";
			std::cout << "1. По ID\n";
			std::cout << "2. По названию\n";
			std::cout << "3. По кол-ву сотрудников\n";//?
			std::cout << "4. Назад\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Введите параметр поиска департамента: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
			case 1:
				return DEPARTMENT_FIND_MODE::ID;
			case 2:
				return DEPARTMENT_FIND_MODE::NAME;
			case 3:
				return DEPARTMENT_FIND_MODE::N_EMPLOYEES;
			case 4:
				return DEPARTMENT_FIND_MODE::BACK;
			default:
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}
}

EMPLOYEE_SORT_MODE employee_sort_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "------------*Сортировка сотрудников*------------\n";
			std::cout << "1. По ID\n";
			std::cout << "2. По имени\n";
			std::cout << "3. По возрасту\n";
			std::cout << "4. По должности\n";
			std::cout << "5. По зарплате\n";
			std::cout << "6. По опыту работы\n";
			std::cout << "7. Назад\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Введите параметр поиска департамента: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
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
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
		}
	}
}
DEPARTMENT_SORT_MODE department_sort_menu()
{
	for (;;)
	{
		try
		{
			std::cout << "-----------*Сортировка департаментов*-----------\n";
			std::cout << "1. По ID\n";
			std::cout << "2. По названию\n";
			std::cout << "3. По кол-ву сотрудников\n";
			std::cout << "4. Назад\n";
			std::cout << "------------------------------------------------\n";


			std::cout << "Введите параметр поиска департамента: ";
			size_t mode = input_size_t(); std::cout << std::endl;

			switch (mode)
			{
			case 0:
				throw std::exception("Некорректный ввод");
			case 1:
				return DEPARTMENT_SORT_MODE::ID;
			case 2:
				return DEPARTMENT_SORT_MODE::NAME;
			case 3:
				return DEPARTMENT_SORT_MODE::N_EMPLOYEES;
			case 4:
				return DEPARTMENT_SORT_MODE::BACK;
			default:
				throw std::exception("Данной функции нет в меню");
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод\n\n\n\n";
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
				throw std::exception("Некорректный ввод строки");
			return str;
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод : ";
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
				throw std::exception("Некорректный ввод числа");
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << ". Повторите ввод : ";
		}
	}
	
}