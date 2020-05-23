//练习 15.22：对于上一题中选择的类，为其添加合适的虚函数及公有成员和受保护的成员。

#include <iostream>
#include <string>

class Shape {
   private:
    std::string name;

   protected:
    virtual double calculateArea() const = 0;

   public:
    Shape(const std::string &pName) : name(pName) {}
    virtual ~Shape() = default;

    std::string getName() const { return name; }
    virtual double getArea() const = 0;
};

class Circle : public Shape {
   private:
    double radius = 0.0;

   protected:
    double calculateArea() const override { return 3.14 * radius * radius; }

   public:
    Circle(const std::string &pName, double r) : Shape(pName), radius(r) {}
    ~Circle() = default;

    double getArea() const override { return calculateArea(); }
};
