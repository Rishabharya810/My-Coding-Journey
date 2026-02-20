class Employee:
    def __init__(self, name, emp_id, salary):
        self.name = name
        self.emp_id = emp_id
        self.salary = salary

    def get_details(self):
        return f"Name: {self.name}, Employee ID: {self.emp_id}, Salary: ${self.salary}"

    def calculate_salary(self):
        return self.salary


class FullTimeEmployee(Employee):
    def __init__(self, name, emp_id, salary, benefits):
        super().__init__(name, emp_id, salary)
        self.benefits = benefits

    def calculate_salary(self):
        return self.salary + self.benefits


class PartTimeEmployee(Employee):
    def __init__(self, name, emp_id, hourly_rate, hours_worked):
        super().__init__(name, emp_id, 0)
        self.hourly_rate = hourly_rate
        self.hours_worked = hours_worked

    def calculate_salary(self):
        return self.hourly_rate * self.hours_worked


class ContractEmployee(Employee):
    def __init__(self, name, emp_id, contract_rate):
        super().__init__(name, emp_id, 0)
        self.contract_rate = contract_rate

    def calculate_salary(self):
        return self.contract_rate


class Manager(FullTimeEmployee, ContractEmployee):
    def __init__(self, name, emp_id, salary, benefits, contract_rate, bonus):
        FullTimeEmployee.__init__(self, name, emp_id, salary, benefits)
        ContractEmployee.__init__(self, name, emp_id, contract_rate)
        self.bonus = bonus

    def calculate_salary(self):
        full_time_salary = FullTimeEmployee.calculate_salary(self)
        contract_salary = ContractEmployee.calculate_salary(self)
        return full_time_salary + contract_salary + self.bonus


def test_employee_system():
    emp1 = Employee("Majid", 1, 50000)
    print(emp1.get_details())
    print(f"Salary: ${emp1.calculate_salary()}\n")

    ft_emp = FullTimeEmployee("Anchal", 2, 60000, 15000)
    print(ft_emp.get_details())
    print(f"Salary: ${ft_emp.calculate_salary()}\n")

    pt_emp = PartTimeEmployee("Aryan", 3, 25, 100)
    print(pt_emp.get_details())
    print(f"Salary: ${pt_emp.calculate_salary()}\n")

    contract_emp = ContractEmployee("Meera", 4, 20000)
    print(contract_emp.get_details())
    print(f"Salary: ${contract_emp.calculate_salary()}\n")

    manager = Manager("Ishita", 5, 90000, 25000, 30000, 20000)
    print(manager.get_details())
    print(f"Salary: ${manager.calculate_salary()}\n")


# Run the test function
test_employee_system()
