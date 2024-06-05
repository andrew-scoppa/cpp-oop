#include "Employee.h"
#include <string>
#include <optional>

class SalariedEmployee : public Employee
{
private:
    double _WeeklySalary;

public:
    double getWeeklySalary() const;
    void setWeeklySalary(double weeklySalary);

    SalariedEmployee(std::optional<int> id = std::nullopt, std::optional<int> reportsTo = std::nullopt, std::optional<std::string> name = std::nullopt, std::optional<std::string> email = std::nullopt, std::optional<std::string> mobile = std::nullopt, std::optional<int> departmentId = std::nullopt, double weeklySalary = 0);

    virtual double getPayment() const override;

    virtual std::string getEmployeeDetails() const override;
};