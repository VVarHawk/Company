/*
=================================================TODO=================================================

В функции main должен быть главный поток, который создает консольное меню для выбора режима, режимы,
требующие взаимодействия с пользователем (ввод нового объекта, редактирование объекта, поиск и печатью,
печать списка объектов и т.п.) выполняются в этом главном потоке. Режимы, не требующие взаимодействия с
пользователем (удаление, сохранение в файле и чтение из файла), выполняются в отдельном потоке,
созданном в главном, при этом обеспечить синхронизацию при доступе к данным объектов.

  1. Ввод нового объекта (сотрудника) и добавление его в контейнер
  2. Поиск объекта в контейнере по значениям полей с печатью данных о найденных объектах
  3. Редактирование объекта
  4. Удаление объекта из контейнера
  5. Сохранение данных всех объектов в файле
  6. Чтение данных объектов из файла
  7. Сортировка объектов контейнера по выбранному полю для list
  8. Печать списка объектов
  9. Предусмотреть обработку исключений, возможные исключения определить самостоятельно

  10. Для классов объектов явно определяются и разрабатываются:
		1) конструкторы и деструкторы (не менее 2),
		2) не менее 4 методов (функций членов класса) и не менее 4 свойств (данных класса);
		3) по выбору, в зависимости от варианта, определяется как минимум одна перегружаемая операция
			(обязательная операция, обозначенная знаком "+" )
		4) Описания классов должны быть вынесены в отдельные файлы (*.h).
			При этом необходимо исключить повторное включение описаний в исходный текст.
		5) Обязательным является перегрузка операции вывода (<<) в стандартный поток cout
			для предметного класса.

======================================================================================================
*/

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <Windows.h>
#include <thread>

#include "Company.h"
#include "util.h"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Company company;
	std::thread* th = nullptr;

	for (;;)
	{
		try
		{
			switch (main_menu())
			{
			case MENU_MODE::ADD_EMPLOYEE:
			{
				std::cout << "Введите имя нового сотрудника (через Enter): ";
				std::string  employee_name = input_string();
				std::cout << "Введите возраст нового сотрудника (через Enter): ";
				size_t employee_age = input_size_t();
				std::cout << "Введите должность нового сотрудника (через Enter): ";
				std::string  employee_work_position = input_string();
				std::cout << "Введите зарплату нового сотрудника (через Enter): ";
				size_t employee_salary = input_size_t();
				std::cout << "Введите опыт работы нового сотрудника (через Enter): ";
				size_t employee_work_experience = input_size_t();
				std::cout << "Введите id департамент нового сотрудника или 0, если нет (через Enter): ";
				size_t employee_department_id = input_size_t(); std::wcout << std::endl;


				if (size_t new_employee_id = company.create_employee(employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience, employee_department_id))
				{
					std::cout << "Сотрудник успешно добавлен!\n";
					company.print_employee(new_employee_id);
					std::cout << "\n\n\n\n";
				}
				else
					std::cout << "Ошибка добавления сотрудника!\n\n\n\n";
				/*std::thread th(&Company::create_employee, std::ref(company), employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience, employee_department_id);
				th.join();*/
				break;
			}
			case MENU_MODE::ADD_DEPARTMENT:
			{
				std::cout << "Введите название нового департамента (через Enter): ";
				std::string department_name = input_string(); std::cout << std::endl;

				if (size_t new_department_id = company.create_department(department_name))
					std::cout << "Департамент успешно создан!\n\n\n\n";
				else
					std::cout << "Ошибка создания департамента\n\n\n\n";

				/*std::thread th(&Company::create_department, std::ref(company), department_name);
				th.join();*/

				break;
			}
			case MENU_MODE::PRINT_ALL_EMPLOYEES:
			{
				company.print_all_employees();
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::PRINT_ALL_DEPARTMENTS:
			{
				company.print_all_departments();
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::PRINT_EMPLOYEES_FROM_DEPARTMENT:
			{
				std::cout << "Введите id департамента: "; size_t department_id = input_size_t(); std::cout << std::endl;
				company.print_all_employees_from_department(department_id);
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::FIND_EMPLOYEE:
			{
				switch (employee_find_menu())
				{
				case EMPLOYEE_FIND_MODE::ID:
				{
					std::cout << "Введите id сотрудника: "; size_t employee_id = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee(employee_id);
					break;
				}
				case EMPLOYEE_FIND_MODE::NAME:
				{
					std::cout << "Введите имя сотрудника: "; std::string employee_name = input_string(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee_with_name(employee_name);
					break;
				}
				case EMPLOYEE_FIND_MODE::AGE:
				{
					std::cout << "Сотрудник не младше : "; size_t under_age = input_size_t();
					std::cout << "и не старше : "; size_t over_age = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee_with_age(under_age, over_age);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_POSITION:
				{
					std::cout << "Введите имя сотрудника: "; std::string work_position = input_string(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee_with_work_position(work_position);
					break;
				}
				case EMPLOYEE_FIND_MODE::SALARY:
				{
					std::cout << "Сотрудник получает не меньше : "; size_t under = input_size_t();
					std::cout << "и не больше : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee_with_salary(under, over);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_EXPERIENCE:
				{
					std::cout << "Сотрудник получает не меньше : "; size_t under = input_size_t();
					std::cout << "и не больше : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_employee_with_salary(under, over);
					break;
				}
				case EMPLOYEE_FIND_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::FIND_DEPARTMENT:
			{
				switch (department_find_menu())
				{
				case DEPARTMENT_FIND_MODE::ID:
				{
					std::cout << "Введите id департамента: "; size_t department_id = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_department(department_id);
					break;
				}
				case DEPARTMENT_FIND_MODE::NAME:
				{
					std::cout << "Введите название департамента : "; std::string department_name = input_string(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_department_with_name(department_name);
					break;
				}
				case DEPARTMENT_FIND_MODE::N_EMPLOYEES:
				{
					std::cout << "В департаменте работает не меньше : "; size_t under = input_size_t();
					std::cout << ", и не больше : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Результаты поиска:\n"; company.print_department_with_n_employees(under, over);
					break;
				}
				case DEPARTMENT_FIND_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::EDIT_EMPLOYEE_PROFILE:
			{
				std::cout << "Введите id сотрудника: "; size_t employee_id = input_size_t(); std::cout << std::endl;
				std::cout << "Результаты поиска:\n"; company.print_employee(employee_id);

				switch (employee_profile_menu())
				{
				case EMPLOYEE_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Введите имя нового сотрудника (через Enter): ";
					std::string  employee_name = input_string(); std::cout << std::endl;
					std::cout << "Введите возраст нового сотрудника (через Enter): ";
					size_t age = input_size_t(); std::cout << std::endl;
					std::cout << "Введите должность нового сотрудника (через Enter): ";
					std::string  work_position = input_string(); std::cout << std::endl;
					std::cout << "Введите зарплату нового сотрудника (через Enter): ";
					size_t salary = input_size_t(); std::cout << std::endl;
					std::cout << "Введите опыт работы нового сотрудника (через Enter): ";
					size_t work_experience = input_size_t(); std::cout << std::endl;
					std::cout << "Введите id департамент нового сотрудника (через Enter): ";
					size_t department_id = input_size_t(); std::cout << std::endl;

					company.edit_employee
					(
						employee_id,
						employee_name,
						age,
						work_position,
						salary,
						work_experience
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Введите новое имя: ";  std::string  employee_name = input_string(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						employee_name,
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_AGE:
				{
					std::cout << "Введите новый возраст: "; size_t age = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						age,
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_POSITION:
				{
					std::cout << "Введите новую должность: "; std::string  work_position = input_string(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						work_position,
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_SALARY:
				{
					std::cout << "Введите новую зарплату: "; size_t salary = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						salary,
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_EXPERIENCE:
				{
					std::cout << "Введите новый опыт работы: "; size_t work_experience = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						work_experience
					);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_DEPARTMENT:
				{
					std::cout << "Введите id нового департамента: "; size_t new_department_id = input_size_t(); std::cout << std::endl;
					company.transfer_employee(employee_id, new_department_id);
					std::cout << "Профиль сотрудника успешно изменен!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::DELETE_EMPLOYEE:
				{
					company.delete_employee(employee_id);
					std::cout << "Профиль сотрудника успешно удален!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::EDIT_DEPARTMENT_RROFILE:
			{
				std::cout << "Введите id департамента: "; size_t department_id = input_size_t(); std::cout << std::endl;
				std::cout << "Результаты поиска:\n"; company.print_department(department_id);

				switch (department_profile_menu())
				{
				case DEPARTMENT_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Введите название нового департамента (через Enter): ";
					std::string  department_name = input_string(); std::cout << std::endl;
					std::cout << "Введите id нового главы департамента (через Enter): ";
					size_t department_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, department_name, department_head_id);
					std::cout << "Профиль успешно изменен!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Введите название нового департамента (через Enter): ";
					std::string  dep_name = input_string(); std::cout << std::endl;

					company.edit_department(department_id, dep_name, company.get_department_head_id(department_id));
					std::cout << "Профиль успешно изменен!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_DEPARTMENT_HEAD:
				{
					std::cout << "Введите id нового главы департамента (через Enter): ";
					size_t new_dep_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, company.get_department_name(department_id), new_dep_head_id);/////////////////////////////////////
					std::cout << "Профиль успешно изменен!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT_HEAD:
				{
					company.edit_department(department_id, company.get_department_name(department_id), NULL);
					break;
				}
				case DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT://////////////////////////////////
				{
					company.delete_department(department_id);
					std::cout << "Профиль департамента успешно удален!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::SORT_EMPLOYEES:
			{
				switch (employee_sort_menu())
				{
				case EMPLOYEE_SORT_MODE::ID:
				{
					company.sort_employees_by_id();
					break;
				}
				case EMPLOYEE_SORT_MODE::NAME:
				{
					company.sort_employees_by_name();
					break;
				}
				case EMPLOYEE_SORT_MODE::AGE:
				{
					company.sort_employees_by_age();
					break;
				}
				case EMPLOYEE_SORT_MODE::WORK_POSITION:
				{
					company.sort_employees_by_work_position();
					break;
				}
				case EMPLOYEE_SORT_MODE::SALARY:
				{
					company.sort_employees_by_salary();
					break;
				}
				case EMPLOYEE_SORT_MODE::WORK_EXPERIENCE:
				{
					company.sort_employees_by_work_experience();
					break;
				}
				case EMPLOYEE_SORT_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "Сортировка сотрудников завершена!\n\n\n\n";
				break;
			}
			case MENU_MODE::SORT_DEPARTMENTS:
			{
				switch (department_sort_menu())
				{
				case DEPARTMENT_SORT_MODE::ID:
				{
					company.sort_departments_by_id();
					break;
				}
				case DEPARTMENT_SORT_MODE::NAME:
				{
					company.sort_departments_by_name();
					break;
				}
				case DEPARTMENT_SORT_MODE::N_EMPLOYEES:
				{
					company.sort_departments_by_n_employees();
					break;
				}
				case DEPARTMENT_SORT_MODE::BACK:
				{
					break;
				}
				}
				std::cout << "Сортировка департаментов завершена!\n\n\n\n";
				break;
			}
			case MENU_MODE::SAVE:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				const Company c(company);
				th = new std::thread(&Company::save, c, file_path);
				/*company.save(file_path);
				std::cout << "Файл успешно сохранен!\n\n\n\n";*/
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::DOWNLOAD:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				company.download(file_path);
				std::cout << "Файл успешно загружен\n\n\n\n";
				break;
			}
			case MENU_MODE::EXIT:
			{
				for (;;)
				{
					std::cout << "Сохранить данные перед выходом? ((y)es/(n)o\n";
					wchar_t ans; std::wcin >> ans;
					switch (ans)
					{
					case 'y':
						if(th != nullptr)
							th->join();
						company.save("D:\\Company\\Company\\files\\file.txt");
						std::cout << "Файл успешно сохранен!\n\n\n\n";
						return 0;
					case 'n':
						if (th != nullptr)
							th->join();
						return 0;
					default:
						std::cout << "Некорректный ввод\n";
						break;
					}
				}
			}
			}
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << "\n\n\n\n";
		}
	}


	return 0;
}