#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <thread>
#include <exception>

#include "Company.h"
#include "util.h"



int main()
{
	setlocale(LC_ALL, "RU");

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
				std::cout << "Enter employee name: ";
				std::string  employee_name = input_string();
				std::cout << "Enter employee age: ";
				size_t employee_age = input_size_t();
				std::cout << "Enter employee work position: ";
				std::string  employee_work_position = input_string();
				std::cout << "Enter employee salary: ";
				size_t employee_salary = input_size_t();
				std::cout << "Enter employee work experience: ";
				size_t employee_work_experience = input_size_t();
				std::cout << "Enter employee department: ";
				size_t employee_department_id = input_size_t(); std::wcout << std::endl;


				if (size_t new_employee_id = company.create_employee(employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience, employee_department_id))
				{
					std::cout << "Employee added successfully!\n";
					company.print_employee(new_employee_id);
					std::cout << "\n\n\n\n";
				}
				else
					std::cout << "Error adding employee!\n\n\n\n";

				break;
			}
			case MENU_MODE::ADD_DEPARTMENT:
			{
				std::cout << "Enter department name: ";
				std::string department_name = input_string(); std::cout << std::endl;

				if (size_t new_department_id = company.create_department(department_name))
					std::cout << "Department added successfully!\n\n\n\n";
				else
					std::cout << "Error adding department\n\n\n\n";

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
				std::cout << "Enter department id: "; size_t department_id = input_size_t(); std::cout << std::endl;
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
					std::cout << "Enter employee id: "; size_t employee_id = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee(employee_id);
					break;
				}
				case EMPLOYEE_FIND_MODE::NAME:
				{
					std::cout << "Enter employee name: "; std::string employee_name = input_string(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee_with_name(employee_name);
					break;
				}
				case EMPLOYEE_FIND_MODE::AGE:
				{
					std::cout << "Search employee under age: "; size_t under_age = input_size_t();
					std::cout << "and over age: "; size_t over_age = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee_with_age(under_age, over_age);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_POSITION:
				{
					std::cout << "Enter employee work wosition: "; std::string work_position = input_string(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee_with_work_position(work_position);
					break;
				}
				case EMPLOYEE_FIND_MODE::SALARY:
				{
					std::cout << "Searching employee under salary: "; size_t under_salary = input_size_t();
					std::cout << "and over salary: "; size_t over_salary = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee_with_salary(under_salary, over_salary);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_EXPERIENCE:
				{
					std::cout << "Searching employee under work experience: "; size_t under = input_size_t();
					std::cout << "and over work experience: "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_employee_with_salary(under, over);
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
					std::cout << "Enter department id: "; size_t department_id = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_department(department_id);
					break;
				}
				case DEPARTMENT_FIND_MODE::NAME:
				{
					std::cout << "Enter department name: "; std::string department_name = input_string(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_department_with_name(department_name);
					break;
				}
				case DEPARTMENT_FIND_MODE::N_EMPLOYEES:
				{
					std::cout << "Searching department under employees: "; size_t under = input_size_t();
					std::cout << "and over employees: "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Searching results:\n"; company.print_department_with_n_employees(under, over);
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
				std::cout << "Enter employee id: "; size_t employee_id = input_size_t(); std::cout << std::endl;
				std::cout << "Searching results:\n"; company.print_employee(employee_id);

				switch (employee_profile_menu())
				{
				case EMPLOYEE_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Enter employee name: ";
					std::string  employee_name = input_string();
					std::cout << "Enter employee age: ";
					size_t employee_age = input_size_t();
					std::cout << "Enter employee work position: ";
					std::string  employee_work_position = input_string();
					std::cout << "Enter employee salary: ";
					size_t employee_salary = input_size_t();
					std::cout << "Enter employee work experience: ";
					size_t employee_work_experience = input_size_t();
					std::cout << "Enter employee department: ";
					size_t employee_department_id = input_size_t(); std::wcout << std::endl;

					company.edit_employee
					(
						employee_id,
						employee_name,
						employee_age,
						employee_work_position,
						employee_salary,
						employee_work_experience
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Enter employee name: ";
					std::string  employee_name = input_string();

					company.edit_employee
					(
						employee_id,
						employee_name,
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_AGE:
				{
					std::cout << "Enter employee age: ";
					size_t employee_age = input_size_t();

					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						employee_age,
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_POSITION:
				{
					std::string  employee_work_position = input_string();
					std::cout << "Enter employee salary: ";

					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						employee_work_position,
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_SALARY:
				{
					std::cout << "Enter employee salary: ";
					size_t employee_salary = input_size_t();

					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						employee_salary,
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_EXPERIENCE:
				{
					std::cout << "Enter employee work experience: ";
					size_t employee_work_experience = input_size_t();

					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						employee_work_experience
					);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_DEPARTMENT:
				{
					std::cout << "Enter employee department: ";
					size_t employee_department_id = input_size_t(); std::wcout << std::endl;

					company.transfer_employee(employee_id, employee_department_id);
					std::cout << "Employee profile edited successfully!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::DELETE_EMPLOYEE:
				{
					company.delete_employee(employee_id);
					std::cout << "Employee profile deleted successfully!\n";
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
				std::cout << "Enter department id: "; size_t department_id = input_size_t(); std::cout << std::endl;
				std::cout << "Searching results:\n"; company.print_department(department_id);

				switch (department_profile_menu())
				{
				case DEPARTMENT_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Enter department name: ";
					std::string department_name = input_string(); std::cout << std::endl;
					std::cout << "Enter department head id: ";
					size_t department_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, department_name, department_head_id);
					std::cout << "Department profile edited successfully!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Enter department name: ";
					std::string department_name = input_string(); std::cout << std::endl;

					company.edit_department(department_id, department_name, company.get_department_head_id(department_id));
					std::cout << "Department profile edited successfully!!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_DEPARTMENT_HEAD:
				{
					std::cout << "Enter department head id: ";
					size_t department_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, company.get_department_name(department_id), department_head_id);
					std::cout << "Department profile edited successfully!!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT_HEAD:
				{
					company.edit_department(department_id, company.get_department_name(department_id), NULL);
					break;
				}
				case DEPARTMENT_PROFILE_MODE::DELETE_DEPARTMENT:
				{
					company.delete_department(department_id);
					std::cout << "Department profile edited successfully!!\n";
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
				std::cout << "Sorting completed!\n\n\n\n";
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
				std::cout << "Sorting completed!\n\n\n\n";
				break;
			}
			case MENU_MODE::SAVE:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				const Company c(company);
				th = new std::thread(&Company::save, c, file_path);
				/*company.save(file_path);
				std::cout << "File saved successfully";*/
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::DOWNLOAD:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				company.download(file_path);
				std::cout << "downloading is complete\n\n\n\n";
				break;
			}
			case MENU_MODE::EXIT:
			{
				for (;;)
				{
					std::cout << "Save before exit? ((y)es/(n)o\n";
					wchar_t ans; std::wcin >> ans;
					switch (ans)
					{
					case 'y':
						if(th != nullptr)
							th->join();
						company.save("D:\\Company\\Company\\files\\file.txt");
						std::cout << "File saved successfully!\n\n\n\n";
						return 0;
					case 'n':
						if (th != nullptr)
							th->join();
						return 0;
					default:
						std::cout << "Save before exit? ((y)es/(n)o\n";
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
