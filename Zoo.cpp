#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    int age;

    Animal() {} // Default constructor

    Animal(string name, int age) : name(name), age(age) {}

    virtual void makeSound() = 0;

    virtual void info() {
        cout << "Name : " << name << ", Age: " << age << endl;
    }
};

class Lion : public Animal {
public:
    Lion(string name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "Lion roars!" << endl;
    }
};

class Tiger : public Animal {
public:
    Tiger(string name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "Tiger growls!" << endl;
    }
};

class Bear : public Animal {
public:
    Bear(string name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "Bear growls!" << endl;
    }
};

int main() {

    const int zooSize = 3;
    Animal* zoo[zooSize];

    for (int i = 0; i < zooSize; ++i) {
        string name;
        int age;



        if (i == 0) {
            cout << "Enter the name of Lion " << ": ";
            cin >> name;
            cout << "Enter the age of " << name << ": ";
            cin >> age;
            zoo[i] = new Lion(name, age);
        }
        else if (i == 1) {
            cout << "Enter the name of Tiger " << ": ";
            cin >> name;
            cout << "Enter the age of " << name << ": ";
            cin >> age;
            zoo[i] = new Tiger(name, age);
        }
        else {
            cout << "Enter the name of Bear " << ": ";
            cin >> name;
            cout << "Enter the age of " << name << ": ";
            cin >> age;
            zoo[i] = new Bear(name, age);
        }
    }
    cout << "=============================\n";
    cout << "\n Zoo animals:\n";
    for (int i = 0; i < zooSize; ++i) {
        zoo[i]->info();
        zoo[i]->makeSound();
    }



    return 0;
}
