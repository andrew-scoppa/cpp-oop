#include "HourlyEmployee.h"

double HourlyEmployee::getHourlyRate() const { return _HourlyRate; }
double HourlyEmployee::getHoursWorked() const { return _HoursWorked; }

HourlyEmployee::HourlyEmployee(std::optional<int> id, std::optional<int> reportsTo, std::optional<std::string> name, std::optional<std::string> email, std::optional<std::string> mobile, std::optional<int> departmentId, double hourlyRate, double hoursWorked)
    : Employee(id, reportsTo, name, email, mobile, departmentId), _HourlyRate(hourlyRate), _HoursWorked(hoursWorked)
{
}

double HourlyEmployee::getPayment() const
{
    return _HourlyRate * _HoursWorked;
}

std::string HourlyEmployee::getEmployeeDetails() const
{
    return Employee::getEmployeeDetails() + ", Hourly Rate: " + std::to_string(_HourlyRate) + ", Hours Worked: " + std::to_string(_HoursWorked);
}