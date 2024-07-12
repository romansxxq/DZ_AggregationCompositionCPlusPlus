#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
    void start() const {
        cout << "Engine started." << endl;
    }
};

class Body {
public:
    void type() const {
        cout << "Sedan body." << endl;
    }
};

class Wheel {
public:
    void rotate() const {
        cout << "Wheel rotating." << endl;
    }
};

class Door {
public:
    void open() const {
        cout << "Door opened." << endl;
    }
};

class Headlight {
public:
    void on() const {
        cout << "Headlight is on." << endl;
    }
};

class Driver {
private:
    string name;
    string surname;
    int age;
    int experience;

public:
    Driver(const string& name, const string& surname, int age, int experience)
        : name(name), surname(surname), age(age), experience(experience) {}

    void showInfo() const {
        cout << "Driver: " << name << " " << surname << ", Age: " << age << ", Experience: " << experience << " years." << endl;
    }
};

class Car {
private:
    Engine engine;
    Body body;
    Wheel wheels[4];
    Door doors[4];
    Headlight lights[2];
    Driver* driver;

public:
    Car() : driver(nullptr) {}

    Car(Driver* drv) : driver(drv) {}

    void addDriver(Driver* drv) {
        driver = drv;
    }

    bool removeDriver() {
        if (driver != nullptr) {
            driver = nullptr;
            return true;
        }
        return false;
    }

    void print() const {
        cout << "Car details:" << endl;
        engine.start();
        body.type();
        for (const auto& wheel : wheels) {
            wheel.rotate();
        }
        for (const auto& door : doors) {
            door.open();
        }
        for (const auto& light : lights) {
            light.on();
        }

        if (driver != nullptr) {
            driver->showInfo();
        }
        else {
            cout << "No driver assigned." << endl;
        }
    }
};

int main() {
    Driver driver("John", "Doe", 30, 5);

    Car carWithDriver(&driver);
    carWithDriver.print();

    cout << endl;

    Car carWithoutDriver;
    carWithoutDriver.print();

    cout << endl;

    carWithoutDriver.addDriver(&driver);
    carWithoutDriver.print();

    cout << endl;

    carWithoutDriver.removeDriver();
    carWithoutDriver.print();

    return 0;
}
