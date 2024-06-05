#include <string>
#include <optional>

class Employee
{
protected:
    std::optional<int> _Id;
    std::optional<int> _ReportsTo;
    std::optional<std::string> _Name;
    std::optional<std::string> _Email;
    std::optional<std::string> _Mobile;
    std::optional<int> _DepartmentId;

public:
    std::optional<int> getId() const;
    void setId(std::optional<int> id);

    std::optional<int> getReportsTo() const;
    void setReportsTo(std::optional<int> reportsTo);

    std::optional<std::string> getName() const;
    void setName(std::optional<std::string> name);

    std::optional<std::string> getEmail() const;
    void setEmail(std::optional<std::string> email);

    std::optional<std::string> getMobile() const;
    void setMobile(std::optional<std::string> mobile);

    std::optional<int> getDepartmentId() const;
    void setDepartmentId(std::optional<int> departmentId);

    Employee(std::optional<int> id = std::nullopt, std::optional<int> reportsTo = std::nullopt, std::optional<std::string> name = std::nullopt, std::optional<std::string> email = std::nullopt, std::optional<std::string> mobile = std::nullopt, std::optional<int> departmentId = std::nullopt);

    virtual double getPayment() const = 0;

    virtual std::string getEmployeeDetails() const;
};