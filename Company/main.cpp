/*
=================================================TODO=================================================

Â ôóíêöèè main äîëæåí áûòü ãëàâíûé ïîòîê, êîòîðûé ñîçäàåò êîíñîëüíîå ìåíþ äëÿ âûáîðà ðåæèìà, ðåæèìû,
òðåáóþùèå âçàèìîäåéñòâèÿ ñ ïîëüçîâàòåëåì (ââîä íîâîãî îáúåêòà, ðåäàêòèðîâàíèå îáúåêòà, ïîèñê è ïå÷àòüþ,
ïå÷àòü ñïèñêà îáúåêòîâ è ò.ï.) âûïîëíÿþòñÿ â ýòîì ãëàâíîì ïîòîêå. Ðåæèìû, íå òðåáóþùèå âçàèìîäåéñòâèÿ ñ
ïîëüçîâàòåëåì (óäàëåíèå, ñîõðàíåíèå â ôàéëå è ÷òåíèå èç ôàéëà), âûïîëíÿþòñÿ â îòäåëüíîì ïîòîêå,
ñîçäàííîì â ãëàâíîì, ïðè ýòîì îáåñïå÷èòü ñèíõðîíèçàöèþ ïðè äîñòóïå ê äàííûì îáúåêòîâ.

  1. Ââîä íîâîãî îáúåêòà (ñîòðóäíèêà) è äîáàâëåíèå åãî â êîíòåéíåð
  2. Ïîèñê îáúåêòà â êîíòåéíåðå ïî çíà÷åíèÿì ïîëåé ñ ïå÷àòüþ äàííûõ î íàéäåííûõ îáúåêòàõ
  3. Ðåäàêòèðîâàíèå îáúåêòà
  4. Óäàëåíèå îáúåêòà èç êîíòåéíåðà
  5. Ñîõðàíåíèå äàííûõ âñåõ îáúåêòîâ â ôàéëå
  6. ×òåíèå äàííûõ îáúåêòîâ èç ôàéëà
  7. Ñîðòèðîâêà îáúåêòîâ êîíòåéíåðà ïî âûáðàííîìó ïîëþ äëÿ list
  8. Ïå÷àòü ñïèñêà îáúåêòîâ
  9. Ïðåäóñìîòðåòü îáðàáîòêó èñêëþ÷åíèé, âîçìîæíûå èñêëþ÷åíèÿ îïðåäåëèòü ñàìîñòîÿòåëüíî

  10. Äëÿ êëàññîâ îáúåêòîâ ÿâíî îïðåäåëÿþòñÿ è ðàçðàáàòûâàþòñÿ:
		1) êîíñòðóêòîðû è äåñòðóêòîðû (íå ìåíåå 2),
		2) íå ìåíåå 4 ìåòîäîâ (ôóíêöèé ÷ëåíîâ êëàññà) è íå ìåíåå 4 ñâîéñòâ (äàííûõ êëàññà);
		3) ïî âûáîðó, â çàâèñèìîñòè îò âàðèàíòà, îïðåäåëÿåòñÿ êàê ìèíèìóì îäíà ïåðåãðóæàåìàÿ îïåðàöèÿ
			(îáÿçàòåëüíàÿ îïåðàöèÿ, îáîçíà÷åííàÿ çíàêîì "+" )
		4) Îïèñàíèÿ êëàññîâ äîëæíû áûòü âûíåñåíû â îòäåëüíûå ôàéëû (*.h).
			Ïðè ýòîì íåîáõîäèìî èñêëþ÷èòü ïîâòîðíîå âêëþ÷åíèå îïèñàíèé â èñõîäíûé òåêñò.
		5) Îáÿçàòåëüíûì ÿâëÿåòñÿ ïåðåãðóçêà îïåðàöèè âûâîäà (<<) â ñòàíäàðòíûé ïîòîê cout
			äëÿ ïðåäìåòíîãî êëàññà.

======================================================================================================
*/

#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <thread>

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
					std::cout << "Ñîòðóäíèê óñïåøíî äîáàâëåí!\n";
					company.print_employee(new_employee_id);
					std::cout << "\n\n\n\n";
				}
				else
					std::cout << "Îøèáêà äîáàâëåíèÿ ñîòðóäíèêà!\n\n\n\n";
				/*std::thread th(&Company::create_employee, std::ref(company), employee_name, employee_age, employee_work_position, employee_salary, employee_work_experience, employee_department_id);
				th.join();*/
				break;
			}
			case MENU_MODE::ADD_DEPARTMENT:
			{
				std::cout << "Ââåäèòå íàçâàíèå íîâîãî äåïàðòàìåíòà (÷åðåç Enter): ";
				std::string department_name = input_string(); std::cout << std::endl;

				if (size_t new_department_id = company.create_department(department_name))
					std::cout << "Äåïàðòàìåíò óñïåøíî ñîçäàí!\n\n\n\n";
				else
					std::cout << "Îøèáêà ñîçäàíèÿ äåïàðòàìåíòà\n\n\n\n";

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
				std::cout << "Ââåäèòå id äåïàðòàìåíòà: "; size_t department_id = input_size_t(); std::cout << std::endl;
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
					std::cout << "Ââåäèòå id ñîòðóäíèêà: "; size_t employee_id = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee(employee_id);
					break;
				}
				case EMPLOYEE_FIND_MODE::NAME:
				{
					std::cout << "Ââåäèòå èìÿ ñîòðóäíèêà: "; std::string employee_name = input_string(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee_with_name(employee_name);
					break;
				}
				case EMPLOYEE_FIND_MODE::AGE:
				{
					std::cout << "Ñîòðóäíèê íå ìëàäøå : "; size_t under_age = input_size_t();
					std::cout << "è íå ñòàðøå : "; size_t over_age = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee_with_age(under_age, over_age);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_POSITION:
				{
					std::cout << "Ââåäèòå èìÿ ñîòðóäíèêà: "; std::string work_position = input_string(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee_with_work_position(work_position);
					break;
				}
				case EMPLOYEE_FIND_MODE::SALARY:
				{
					std::cout << "Ñîòðóäíèê ïîëó÷àåò íå ìåíüøå : "; size_t under = input_size_t();
					std::cout << "è íå áîëüøå : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee_with_salary(under, over);
					break;
				}
				case EMPLOYEE_FIND_MODE::WORK_EXPERIENCE:
				{
					std::cout << "Ñîòðóäíèê ïîëó÷àåò íå ìåíüøå : "; size_t under = input_size_t();
					std::cout << "è íå áîëüøå : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee_with_salary(under, over);
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
					std::cout << "Ââåäèòå id äåïàðòàìåíòà: "; size_t department_id = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_department(department_id);
					break;
				}
				case DEPARTMENT_FIND_MODE::NAME:
				{
					std::cout << "Ââåäèòå íàçâàíèå äåïàðòàìåíòà : "; std::string department_name = input_string(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_department_with_name(department_name);
					break;
				}
				case DEPARTMENT_FIND_MODE::N_EMPLOYEES:
				{
					std::cout << "Â äåïàðòàìåíòå ðàáîòàåò íå ìåíüøå : "; size_t under = input_size_t();
					std::cout << ", è íå áîëüøå : "; size_t over = input_size_t(); std::cout << std::endl;
					std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_department_with_n_employees(under, over);
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
				std::cout << "Ââåäèòå id ñîòðóäíèêà: "; size_t employee_id = input_size_t(); std::cout << std::endl;
				std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_employee(employee_id);

				switch (employee_profile_menu())
				{
				case EMPLOYEE_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Ââåäèòå èìÿ íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
					std::string  employee_name = input_string(); std::cout << std::endl;
					std::cout << "Ââåäèòå âîçðàñò íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
					size_t age = input_size_t(); std::cout << std::endl;
					std::cout << "Ââåäèòå äîëæíîñòü íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
					std::string  work_position = input_string(); std::cout << std::endl;
					std::cout << "Ââåäèòå çàðïëàòó íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
					size_t salary = input_size_t(); std::cout << std::endl;
					std::cout << "Ââåäèòå îïûò ðàáîòû íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
					size_t work_experience = input_size_t(); std::cout << std::endl;
					std::cout << "Ââåäèòå id äåïàðòàìåíò íîâîãî ñîòðóäíèêà (÷åðåç Enter): ";
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
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Ââåäèòå íîâîå èìÿ: ";  std::string  employee_name = input_string(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						employee_name,
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_AGE:
				{
					std::cout << "Ââåäèòå íîâûé âîçðàñò: "; size_t age = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						age,
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_POSITION:
				{
					std::cout << "Ââåäèòå íîâóþ äîëæíîñòü: "; std::string  work_position = input_string(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						work_position,
						company.get_employee_salary(employee_id),
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_SALARY:
				{
					std::cout << "Ââåäèòå íîâóþ çàðïëàòó: "; size_t salary = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						salary,
						company.get_employee_work_experience(employee_id)
					);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_EXPERIENCE:
				{
					std::cout << "Ââåäèòå íîâûé îïûò ðàáîòû: "; size_t work_experience = input_size_t(); std::cout << std::endl;
					company.edit_employee
					(
						employee_id,
						company.get_employee_name(employee_id),
						company.get_employee_age(employee_id),
						company.get_employee_work_position(employee_id),
						company.get_employee_salary(employee_id),
						work_experience
					);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::EDIT_WORK_DEPARTMENT:
				{
					std::cout << "Ââåäèòå id íîâîãî äåïàðòàìåíòà: "; size_t new_department_id = input_size_t(); std::cout << std::endl;
					company.transfer_employee(employee_id, new_department_id);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî èçìåíåí!\n";
					break;
				}
				case EMPLOYEE_PROFILE_MODE::DELETE_EMPLOYEE:
				{
					company.delete_employee(employee_id);
					std::cout << "Ïðîôèëü ñîòðóäíèêà óñïåøíî óäàëåí!\n";
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
				std::cout << "Ââåäèòå id äåïàðòàìåíòà: "; size_t department_id = input_size_t(); std::cout << std::endl;
				std::cout << "Ðåçóëüòàòû ïîèñêà:\n"; company.print_department(department_id);

				switch (department_profile_menu())
				{
				case DEPARTMENT_PROFILE_MODE::EDIT_ALL:
				{
					std::cout << "Ââåäèòå íàçâàíèå íîâîãî äåïàðòàìåíòà (÷åðåç Enter): ";
					std::string  department_name = input_string(); std::cout << std::endl;
					std::cout << "Ââåäèòå id íîâîãî ãëàâû äåïàðòàìåíòà (÷åðåç Enter): ";
					size_t department_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, department_name, department_head_id);
					std::cout << "Ïðîôèëü óñïåøíî èçìåíåí!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_NAME:
				{
					std::cout << "Ââåäèòå íàçâàíèå íîâîãî äåïàðòàìåíòà (÷åðåç Enter): ";
					std::string  dep_name = input_string(); std::cout << std::endl;

					company.edit_department(department_id, dep_name, company.get_department_head_id(department_id));
					std::cout << "Ïðîôèëü óñïåøíî èçìåíåí!\n";
					break;
				}
				case DEPARTMENT_PROFILE_MODE::EDIT_DEPARTMENT_HEAD:
				{
					std::cout << "Ââåäèòå id íîâîãî ãëàâû äåïàðòàìåíòà (÷åðåç Enter): ";
					size_t new_dep_head_id = input_size_t(); std::cout << std::endl;

					company.edit_department(department_id, company.get_department_name(department_id), new_dep_head_id);/////////////////////////////////////
					std::cout << "Ïðîôèëü óñïåøíî èçìåíåí!\n";
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
					std::cout << "Ïðîôèëü äåïàðòàìåíòà óñïåøíî óäàëåí!\n";
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
				std::cout << "Ñîðòèðîâêà ñîòðóäíèêîâ çàâåðøåíà!\n\n\n\n";
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
				std::cout << "Ñîðòèðîâêà äåïàðòàìåíòîâ çàâåðøåíà!\n\n\n\n";
				break;
			}
			case MENU_MODE::SAVE:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				const Company c(company);
				th = new std::thread(&Company::save, c, file_path);
				/*company.save(file_path);
				std::cout << "Ôàéë óñïåøíî ñîõðàíåí!\n\n\n\n";*/
				std::cout << "\n\n\n\n";
				break;
			}
			case MENU_MODE::DOWNLOAD:
			{
				std::string file_path = "D:\\Company\\Company\\files\\file.txt";
				company.download(file_path);
				std::cout << "Ôàéë óñïåøíî çàãðóæåí\n\n\n\n";
				break;
			}
			case MENU_MODE::EXIT:
			{
				for (;;)
				{
					std::cout << "Ñîõðàíèòü äàííûå ïåðåä âûõîäîì? ((y)es/(n)o\n";
					wchar_t ans; std::wcin >> ans;
					switch (ans)
					{
					case 'y':
						if(th != nullptr)
							th->join();
						company.save("D:\\Company\\Company\\files\\file.txt");
						std::cout << "Ôàéë óñïåøíî ñîõðàíåí!\n\n\n\n";
						return 0;
					case 'n':
						if (th != nullptr)
							th->join();
						return 0;
					default:
						std::cout << "Íåêîððåêòíûé ââîä\n";
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
