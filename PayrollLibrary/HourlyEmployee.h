#include "Employee.h"
#include <string>
#include <optional>

class HourlyEmployee : public Employee
{
private:
    double _HourlyRate;
    double _HoursWorked;

public:
    double getHourlyRate() const;
    double getHoursWorked() const;

    HourlyEmployee(std::optional<int> id = std::nullopt, std::optional<int> reportsTo = std::nullopt, std::optional<std::string> name = std::nullopt, std::optional<std::string> email = std::nullopt, std::optional<std::string> mobile = std::nullopt, std::optional<int> departmentId = std::nullopt, double hourlyRate = 0, double hoursWorked = 0);

    virtual double getPayment() const override;

    virtual std::string getEmployeeDetails() const override;
};