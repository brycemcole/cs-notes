#include <iostream>
#include <String>

class Person {

private:
    int age;
    std::string name;

public:
    void set_Name(std::string input_name) {
        name = input_name;
    }

    void set_Age(int input_age) {
        age = input_age;
    }

    std::string get_Name() {
        return name;
    }

    int get_Age() {
        return age;
    }
};

int main() {
    Person user;
    std::string name;
    int age;

    std::cout << "what is your name? ";
    std::cin >> name;
    user.set_Name(name);
    
    std::cout << "what is your age? ";
    std::cin >> age;
    user.set_Age(age);

    std::cout << "Hello, " << user.get_Name() << "\n";

    return 0;
}