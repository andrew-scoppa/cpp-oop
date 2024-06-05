#include <string>
#include <optional>

class Department
{
private:
    std::optional<int> _Id;
    std::optional<std::string> _Name;

public:
    std::optional<int> getId() const;
    void setId(std::optional<int> id);

    std::optional<std::string> getName() const;
    void setName(std::optional<std::string> name);

    Department(std::optional<int> id = std::nullopt, std::optional<std::string> name = std::nullopt);
};