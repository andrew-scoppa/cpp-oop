<!--
This file documents the design and implementation of the PayrollLibrary project.
The project is a library that provides functionality for managing employee payroll data.
This document includes usage and license information.
Details:
The program is written in C++ and contains the following files:
- Employee.h
- Employee.cpp
- HourlyEmployee.h
- HourlyEmployee.cpp
- SalariedEmployee.h
- SalariedEmployee.cpp
- Department.h
- Department.cpp
- PayrollManager.cpp
 -->

# Payroll Library

The Payroll Library project is a library that provides functionality for managing employee payroll data. The library is written in C++ and contains classes for different types of employees, departments, and a payroll manager.

## Files

The project contains the following files:

- `Employee.h`: Header file for the `Employee` class.
- `Employee.cpp`: Implementation file for the `Employee` class.
- `HourlyEmployee.h`: Header file for the `HourlyEmployee` class.
- `HourlyEmployee.cpp`: Implementation file for the `HourlyEmployee` class.
- `SalariedEmployee.h`: Header file for the `SalariedEmployee` class.
- `SalariedEmployee.cpp`: Implementation file for the `SalariedEmployee` class.
- `Department.h`: Header file for the `Department` class.
- `Department.cpp`: Implementation file for the `Department` class.
- `PayrollManager.cpp`: Implementation file for the `PayrollManager` class.
- `PayrollManager.h`: Header file for the PayrollManager class.
## Usage

To use the Payroll Library, you can include the necessary header files in your project and link against the compiled library. You can create instances of employees, departments, and the payroll manager to manage payroll data.

Here is an example of how to use the library:

```cpp
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Department.h"
#include "PayrollManager.h"

int main() {
    // Create some employees
    HourlyEmployee hourlyEmployee("Alice", 25.0, 40);
    SalariedEmployee salariedEmployee("Bob", 50000.0);
    
    // Create a department
    Department department("Engineering");
    
    // Add employees to the department
    department.addEmployee(hourlyEmployee);
    department.addEmployee(salariedEmployee);
    
    // Create a payroll manager
    PayrollManager payrollManager;
    
    // Calculate and print the total payroll for the department
    double totalPayroll = payrollManager.calculateTotalPayroll(department);
    std::cout << "Total payroll for department: $" << totalPayroll << std::endl;
    
    return 0;
}
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```

