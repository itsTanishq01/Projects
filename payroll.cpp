#include <iostream>
#include <iomanip> // Include the header to set precision and fixed notation
#include <string>

class Employee {
public:
    std::string name;
    int age;
    double basicSalary;

    Employee() {}

    Employee(const std::string& name, int age, double basicSalary)
        : name(name), age(age), basicSalary(basicSalary) {}

    double calculateTax()  {
        double tax = 0.0;
        double taxableIncome = basicSalary;

        if (taxableIncome <= 300000.0)
        {
            return tax; // No tax for income up to ₹3,00,000
        }
        else if (taxableIncome <= 600000.0 && taxableIncome >= 300000.0)
        {
            tax = taxableIncome * 0.05;
        }
        else if (taxableIncome <= 900000.0 && taxableIncome >= 600000.0)
        {
            tax = taxableIncome * 0.10;
        }
        else if (taxableIncome <= 1200000.0 && taxableIncome >= 900000.0)
        {
            tax = taxableIncome * 0.15;
        }
        else if (taxableIncome <= 1500000.0 && taxableIncome >= 1200000.0)
        {
            tax = taxableIncome * 0.20;
        }
        else if (taxableIncome >= 1500000.0)
        {
            tax = taxableIncome * 0.30;
        }

        return tax;
    }

    double calculateSalaryAfterTax()  {
        return basicSalary - calculateTax();
    }

    void readEmployeeInfo() {
        std::cout << "Enter employee name: ";
        std::cin >> name;

        std::cout << "Enter employee age: ";
        std::cin >> age;

        std::cout << "Enter employee basic salary: ";
        std::cin >> basicSalary;
    }

    void printPaySlip()  {
        double tax = calculateTax();
        double salaryAfterTax = calculateSalaryAfterTax();

        // Set the precision and fixed notation for displaying double values
        std::cout << std::fixed << std::setprecision(2);

        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Basic Salary: " << basicSalary << std::endl;
        std::cout << "Tax Deduction: " << tax << std::endl;
        std::cout << "Salary After Tax: " << salaryAfterTax << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    Employee e;

    e.readEmployeeInfo();
    e.printPaySlip();

    return 0;
}
