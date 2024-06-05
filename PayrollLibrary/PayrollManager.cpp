// PayrollManager.cpp
#include "PayrollManager.h"

void PayrollManager::addEmployee(std::shared_ptr<Employee> employee) {
    employees.push_back(employee);
}

double PayrollManager::calculateTotalPayroll() const {
    double total = 0.0;
    for (const auto& employee : employees) {
        total += employee->getPayment();
    }
    return total;
}