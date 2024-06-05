#include "SalariedEmployee.h"

double SalariedEmployee::getWeeklySalary() const { return _WeeklySalary; }
void SalariedEmployee::setWeeklySalary(double weeklySalary) { _WeeklySalary = weeklySalary; }

SalariedEmployee::SalariedEmployee(std::optional<int> id, std::optional<int> reportsTo, std::optional<std::string> name, std::optional<std::string> email, std::optional<std::string> mobile, std::optional<int> departmentId, double weeklySalary)
    : Employee(id, reportsTo, name, email, mobile, departmentId), _WeeklySalary(weeklySalary)
{
}

double SalariedEmployee::getPayment() const
{
    return _WeeklySalary;
}

std::string SalariedEmployee::getEmployeeDetails() const
{
    return Employee::getEmployeeDetails() + ", Weekly Salary: " + std::to_string(_WeeklySalary);
}