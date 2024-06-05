#include "Department.h"

std::optional<int> Department::getId() const { return _Id; }
void Department::setId(std::optional<int> id) { _Id = id; }

std::optional<std::string> Department::getName() const { return _Name; }
void Department::setName(std::optional<std::string> name) { _Name = name; }

Department::Department(std::optional<int> id, std::optional<std::string> name)
    : _Id(id), _Name(name)
{
}