#include <iostream>
#include <string>

//Задание 2: класс Фрукты:

class Fruit
{
private:
    std::string n_name;
    std::string n_color;

public:
    Fruit(std::string name, std::string color) : n_name(name), n_color(color) {}
    std::string getName() { return n_name; }
    std::string getColor() { return n_color; }
};

class Apple:public Fruit
{
protected:
    Apple(std::string name, std::string color) : Fruit(name, color) {}

public:
    Apple(std::string color = "Red") : Fruit("apple", color) {}
};

class GrannySmith:public Apple
{
public:
    GrannySmith():Apple("Granny Smith apple", "green") {}
};

class Banana:public Fruit
{
public:
    Banana(std::string name = "Banana", std::string color = "Yellow") : Fruit(name, color) {}
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}