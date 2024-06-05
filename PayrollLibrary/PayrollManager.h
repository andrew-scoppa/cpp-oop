// PayrollManager.h
#include "Employee.h"
#include <vector>
#include <memory>

class PayrollManager {
public:
    void addEmployee(std::shared_ptr<Employee> employee);
    double calculateTotalPayroll() const;

private:
    std::vector<std::shared_ptr<Employee>> employees;
};