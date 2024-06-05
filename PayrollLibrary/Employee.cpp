#include "Employee.h"

std::optional<int> Employee::getId() const { return _Id; }
void Employee::setId(std::optional<int> id) { _Id = id; }

std::optional<int> Employee::getReportsTo() const { return _ReportsTo; }
void Employee::setReportsTo(std::optional<int> reportsTo) { _ReportsTo = reportsTo; }

std::optional<std::string> Employee::getName() const { return _Name; }
void Employee::setName(std::optional<std::string> name) { _Name = name; }

std::optional<std::string> Employee::getEmail() const { return _Email; }
void Employee::setEmail(std::optional<std::string> email) { _Email = email; }

std::optional<std::string> Employee::getMobile() const { return _Mobile; }
void Employee::setMobile(std::optional<std::string> mobile) { _Mobile = mobile; }

std::optional<int> Employee::getDepartmentId() const { return _DepartmentId; }
void Employee::setDepartmentId(std::optional<int> departmentId) { _DepartmentId = departmentId; }

Employee::Employee(std::optional<int> id, std::optional<int> reportsTo, std::optional<std::string> name, std::optional<std::string> email, std::optional<std::string> mobile, std::optional<int> departmentId)
    : _Id(id), _ReportsTo(reportsTo), _Name(name), _Email(email), _Mobile(mobile), _DepartmentId(departmentId)
{
}

std::string Employee::getEmployeeDetails() const
{
    return "Id: " + std::to_string(_Id.value_or(0)) + ", Name: " + _Name.value_or("") + ", Email: " + _Email.value_or("") + ", Mobile: " + _Mobile.value_or("") + ", DepartmentId: " + std::to_string(_DepartmentId.value_or(0));
}