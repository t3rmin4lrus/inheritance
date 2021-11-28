#include <iostream>
#include <string>

//Задание 1: класс Персоны:

class Person
{
private:
    static int count;
    std::string m_name;
    int m_age;
    std::string m_gender;
    int m_weight;


public:
    static int GetCount() { return count; }

    Person(const std::string& name, const int& age, const std::string& gender, const int& weight)
        : m_name(name), m_age(age), m_weight(weight), m_gender(gender)
    {
        count++;
    }

    std::string GetName() { return m_name; }
    int GetAge() { return m_age; }
    int GetWeight() { return m_weight; }
    virtual void Print()  
    {
        std::cout << m_name << ' ' << m_age << ' ' << m_gender << ' ' << m_weight <<std::endl;
    }
};

class Student : public Person
{
private:
    int m_year;

public:
    Student(int year, const std::string& name, const int age, const std::string& gender, const int weight)
        :Person(name, age, gender, weight), m_year(year)
    {}
    int GetYear() { return m_year; }
    void AddYear(int addValue)
    {
        m_year += addValue;
    }
    void AddYear()
    {
        m_year++;
    }

    void Print()
    {
        std::cout << m_year << ' ';
        Person::Print();
    }
};

int Person::count = 0;

int main()
{
    const int N = 2;
    Person* persona[N];
    for (int i = 0; i < N; i++)
    {
        int year, weight, age;
        std::string name, gender;
        std::cout << "Enter name, age, gender, weight:" << std::endl;
        std::cin >> name >> age >> gender >> weight >> year;
        persona[i] = new Student(year, name, age, gender, weight);
        std::cout << "Count=" << persona[i]->GetCount() << std::endl;
    }
    for (int i = 0; i < N; i++)
        persona[i]->Print();
    Student* s1 = static_cast<Student*>(persona[0]);
    s1->AddYear(2);
    std::cout << "New age of " << s1->GetName() << " = "
        << s1->GetAge() << std::endl;
    for (int i = 0; i < N; i++)
        delete persona[i];
    return 0;
}