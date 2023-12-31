#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    Person();
    Person(const int age);
    Person(const Person& person) = default;
    ~Person();

public:
    inline const std::string &GetName() const {
        return m_name;
    }
    inline void SetName(const std::string &name) {
        m_name = name;
    }

    inline constexpr int GetAge() const {
        return m_age;
    }

    inline void SetAge(const int age) {
        m_age = age;
    }

    void ShowInfomation() const;

private:
    string m_name;
    int m_age;
    string m_address;
};

#endif /* PERSON_H */
