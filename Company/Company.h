#pragma once


#include <string>
#include <algorithm>
#include <list>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <thread>
#include <future>


class Company
{
	class Department;
public:
	Company();

	Company(const Company& company);

	~Company();
	

	std::string		get_employee_name(size_t employee_id)				const;
	size_t			get_employee_age(size_t employee_id)				const;
	std::string		get_employee_work_position(size_t employee_id)		const;
	size_t			get_employee_salary(size_t employee_id)				const;
	size_t			get_employee_work_experience(size_t employee_id)	const;

	size_t			get_employee_department_id(size_t employee_id)		const;

	std::string		get_department_name(size_t department_id)			const;
	size_t			get_department_head_id(size_t department_id)		const;
	size_t			get_department_n_employees(size_t department_id)	const;
	size_t			get_department_id(size_t department_id)				const;

	size_t get_n_employees()											const;
	size_t get_n_departments()											const;

	
	void create_employee_with_id(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience, size_t employee_department_id);
	size_t create_employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience, size_t employee_department_id);

	void create_department_with_id(size_t department_id, std::string department_name);
	size_t create_department(std::string department_name);


	void		transfer_employee(size_t employee_id, size_t new_department_id);

	void		edit_employee(size_t employee_id, std::string new_employee_name, size_t new_employee_age, std::string new_employee_work_position, size_t new_employee_salary, size_t new_employee_work_experience);
	void		edit_department(size_t department_id, std::string new_department_name, size_t new_department_head_id);

	void		delete_employee						(size_t employee_id);
	void		delete_department					(size_t department_id);
	

	void		print_employee						(size_t employee_id)										const;
	void		print_department					(size_t department_id)										const;

	void		print_all_employees()																			const;
	void		print_all_employees_from_department	(size_t department_id)										const;
	void		print_all_departments()																			const;

	void		print_employee_with_name			(std::string employee_name			)						const;
	void		print_employee_with_age				(size_t	under_age, size_t over_age	)						const;
	void		print_employee_with_work_position	(std::string employee_work_position	)						const;
	void		print_employee_with_salary			(size_t	from_salary, size_t to_salary	)					const;
	void		print_employee_with_work_experience	(size_t	from_work_experience, size_t to_work_experience)	const;
	
	void		print_department_with_name			(std::string name			)								const;
	void		print_department_with_n_employees	(size_t under, size_t over	)								const;


	void		sort_employees_by_id();
	void		sort_employees_by_name();
	void		sort_employees_by_age();
	void		sort_employees_by_work_position();
	void		sort_employees_by_salary();
	void		sort_employees_by_work_experience();

	void		sort_departments_by_id();
	void		sort_departments_by_name();
	void		sort_departments_by_n_employees();


	void		download	(std::string file_name = "D:\\Company\\Company\\files\\file.txt");
	void		save		(std::string file_name = "D:\\Company\\Company\\files\\file.txt") const;

private:
	Department*			find_department	(size_t department_id);	
	const Department*	find_department	(size_t department_id) const;


	std::list<Department*> departments;
	bool is_copy;

	class Department
	{
		class Employee;
	public:

		Department(std::string department_name);
		Department(size_t department_id, std::string department_name);

		Department(const Department& department);

		~Department();


		std::string		get_department_name()								const;
		size_t			get_department_head_id()							const;
		size_t			get_department_n_employees()						const;
		size_t			get_department_id()									const;

		std::string		get_employee_name(size_t employee_id)				const;
		size_t			get_employee_age(size_t employee_id)				const;
		std::string		get_employee_work_position(size_t employee_id)		const;
		size_t			get_employee_salary(size_t employee_id)				const;
		size_t			get_employee_work_experience(size_t employee_id)	const;


		bool			is_employee_work_here(size_t employee_id)			const;


		void			create_employee_with_id(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience);
		size_t			create_employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience);


		void			edit_employee(size_t employee_id, std::string name, size_t age, std::string work_position, size_t salary, size_t work_experience);
		void			edit_department(std::string name, size_t department_head_id);

		void			delete_employee(size_t employee_id);


		void			print_employee(size_t employee_id)																const;
		void			print_all_employees_from_department()															const;

		void			print_employee_with_name(std::string	employee_name)											const;
		void			print_employee_with_age(size_t	under_age, size_t over_age)										const;
		void			print_employee_with_work_position(std::string	employee_work_position)							const;
		void			print_employee_with_salary(size_t	from_salary, size_t to_salary)								const;
		void			print_employee_with_work_experience(size_t	from_work_experience, size_t to_work_experience)	const;

		void			print_department()																				const;


		void			sort_employees_from_department_by_id();
		void			sort_employees_from_department_by_name();
		void			sort_employees_from_department_by_age();
		void			sort_employees_from_department_by_work_position();
		void			sort_employees_from_department_by_salary();
		void			sort_employees_from_department_by_work_experience();
		

		friend bool operator !=(const Department& department_1, const Department& department_2)
		{
			return (department_1.get_department_id() != department_2.get_department_id());
		}

		friend std::ostream& operator <<(std::ostream& out, const Department& department)
		{
			out << department.get_department_id() << std::endl
				<< department.get_department_name() << std::endl
				<< department.get_department_n_employees() << std::endl
				<< department.get_department_head_id() << std::endl;

			for (Department::Employee* em : department.employees)
				out << *em;

			return out;
		}

	private:
		void			set_department_name(std::string name);
		void			set_department_head(size_t department_head_id);


		Employee* find_employee(size_t employee_id);
		const Employee* find_employee(size_t employee_id) const;


		std::string				department_name;
		Employee* department_head;

		std::list<Employee*>	employees;

		bool is_copy;

		class Department_ID
		{
		public:
			Department_ID();
			Department_ID(size_t department_id);
			Department_ID(const Department_ID& department_id);

			~Department_ID();

			size_t get_department_id() const;
		private:
			size_t						department_id;				// id департамента

			static size_t				next_department_id;	// id следующего департамента
			static std::list<size_t>	available_department_id;
		} department_id;
		class Employee
		{
		public:
			Employee(std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience);																			// конструктор полныq
			Employee(size_t employee_id, std::string employee_name, size_t employee_age, std::string employee_work_position, size_t employee_salary, size_t employee_work_experience);

			Employee(const Employee& employee);

			~Employee();


			std::string get_employee_name()				const;
			size_t		get_employee_age()				const;
			std::string get_employee_work_position()	const;
			size_t		get_employee_salary()			const;
			size_t		get_employee_work_experience()	const;

			size_t		get_employee_id()				const;


			void		edit_employee(std::string new_employee_name, size_t new_employee_age, std::string new_employee_work_positionsize_t, size_t new_employee_salary, size_t new_employee_work_experience);


			void		print_employee()				const;


			friend bool operator!=(const Employee& employee_1, const Employee& employee_2)
			{
				return (employee_1.get_employee_id() != employee_2.get_employee_id());
			}
			friend bool operator==(const Employee& employee_1, const Employee& employee_2)
			{
				return (employee_1.get_employee_id() == employee_2.get_employee_id());
			}


			friend std::ostream& operator<<(std::ostream& out, const Department::Employee& employee)
			{
				out << employee.get_employee_id() << std::endl
					<< employee.get_employee_name() << std::endl
					<< employee.get_employee_age() << std::endl
					<< employee.get_employee_work_position() << std::endl
					<< employee.get_employee_salary() << std::endl
					<< employee.get_employee_work_experience() << std::endl;

				return out;
			}
		private:
			void		set_employee_name(std::string	employee_name);
			void		set_employee_age(size_t			employee_age);
			void		set_employee_work_position(std::string	employee_work_position);
			void		set_employee_salary(size_t			employee_salary);
			void		set_employee_work_experience(size_t			employee_work_experience);


			std::string employee_name;															
			size_t		employee_age;																	
			std::string employee_work_position;															
			size_t		employee_salary;																
			size_t		employee_work_experience;														


			class Employee_ID
				/*
				Данный класс отвечает за присвоение сотруднику его ID и привязку сотрудника к контретному департаменту
				*/

			{
			public:
				Employee_ID();
				Employee_ID(size_t employee_id);

				Employee_ID(const Employee_ID& full_id);

				~Employee_ID();

				size_t get_employee_id() const;
			private:
				size_t				employee_id;													// id сотрудника

				static	size_t				next_employee_id;										// id следующего сотрудника
				static	std::list<size_t>	available_employee_id;									// свободные id сотруднинов (если кого-то уволили)
			} employee_id;
		};
	};
};