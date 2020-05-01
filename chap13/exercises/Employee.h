#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>

class Employee {
   private:
    static unsigned long id_num;
    std::string name;
    std::string id;

   public:
    Employee() : name(std::string("wuming")), id(std::to_string(id_num)) { ++id_num; }
    Employee(const std::string &name) : name(name), id(std::to_string(id_num)) { ++id_num; }
    ~Employee() = default;
    Employee(const Employee &rhs) : name(rhs.name), id(std::to_string(id_num)) { ++id_num; }
    Employee &operator=(const Employee &rhs) {
        name = rhs.name;
        id = std::to_string(id_num);
        ++id_num;
        return *this;
    }

    std::string getName() const { return name; }
    std::string getId() const { return id; }
};
unsigned long Employee::id_num = 0;

#endif