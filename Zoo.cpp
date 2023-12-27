#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    int age;
    string habitat;

    Animal() {}

    Animal(string name, int age, string habitat) : name(name), age(age), habitat(habitat) {}

    virtual void makeSound() = 0;

    virtual void move() { cout << name << " is moving." << endl; }
    virtual void sleep() { cout << name << " is sleeping." << endl; }
    virtual void eat() { cout << name << " is eating." << endl; }

    virtual void info() {
        cout << "Name: " << name << ", Age: " << age << ", Habitat: " << habitat << endl;
    }
};

class Lion : public Animal {
public:
    float maneSize;
    bool isAlpha;
    int roarVolume;

    Lion(string name, int age, string habitat, float maneSize, bool isAlpha, int roarVolume)
        : Animal(name, age, habitat), maneSize(maneSize), isAlpha(isAlpha), roarVolume(roarVolume) {}

    void makeSound() override { cout << "Lion roars!" << endl; }

    void displayDominance() { cout << name << " displays dominance." << endl; }
    void leadPride() { cout << name << " leads the pride." << endl; }
    void hunt() { cout << name << " goes hunting." << endl; }

    void info() override {
        Animal::info();
        cout << "Mane Size: " << maneSize << ", Alpha: " << (isAlpha ? "Yes" : "No")
            << ", Roar Volume: " << roarVolume << endl;
    }
};

class Tiger : public Animal {
public:
    string stripePattern;
    float territorySize;
    bool swimmingAbility;

    Tiger(string name, int age, string habitat, string stripePattern, float territorySize, bool swimmingAbility)
        : Animal(name, age, habitat), stripePattern(stripePattern), territorySize(territorySize), swimmingAbility(swimmingAbility) {}

    void makeSound() override { cout << "Tiger growls!" << endl; }

    void stalkPrey() { cout << name << " stalks its prey." << endl; }
    void markTerritory() { cout << name << " marks its territory." << endl; }
    void swim() { cout << name << " swims skillfully." << endl; }

    void info() override {
        Animal::info();
        cout << "Stripe Pattern: " << stripePattern << ", Territory Size: " << territorySize
            << " sq km, Swimming Ability: " << (swimmingAbility ? "Good" : "Poor") << endl;
    }
};

class Bear : public Animal {
public:
    string dietType;
    bool hibernates;
    float clawLength;

    Bear(string name, int age, string habitat, string dietType, bool hibernates, float clawLength)
        : Animal(name, age, habitat), dietType(dietType), hibernates(hibernates), clawLength(clawLength) {}

    void makeSound() override { cout << "Bear growls!" << endl; }

    void forage() { cout << name << " forages for food." << endl; }
    void hibernate() { cout << name << " goes into hibernation." << endl; }
    void fish() { cout << name << " fishes in the river." << endl; }

    void info() override {
        Animal::info();
        cout << "Diet: " << dietType << ", Hibernates: " << (hibernates ? "Yes" : "No")
            << ", Claw Length: " << clawLength << " inches" << endl;
    }
};

int main() {
    const int zooSize = 3;
    Animal* zoo[zooSize];

    zoo[0] = new Lion("Leo", 5, "Savannah", 12.5, true, 80);
    zoo[1] = new Tiger("Tigra", 4, "Rainforest", "Bold Stripes", 20.0, true);
    zoo[2] = new Bear("Baloo", 7, "Forest", "Omnivore", true, 15.0);

    cout << "=============================\n";
    cout << "\nZoo animals:\n";
    for (int i = 0; i < zooSize; ++i) {
        zoo[i]->info();
        zoo[i]->makeSound();
        zoo[i]->sleep();
        cout << "=============================\n\n";

    }

    // Cleaning up to avoid memory leaks
    for (int i = 0; i < zooSize; ++i) {
        delete zoo[i];
    }


    return 0;
}
