#include <iostream>
#include <vector>

class Check {                               // You can NOT edit this
 public:                                    // You can NOT edit this
    int is_user_happy(int idx) {            // You can NOT edit this
        counter++;                          // You can NOT edit this
        if (idx % 3 == 0)                   // You can NOT edit this
            return 1;                       // You can NOT edit this
        return 0;                           // You can NOT edit this
    }                                       // You can NOT edit this
                                            // You can NOT edit this
    int get_counter() {                     // You can NOT edit this
        counter++;                          // You can NOT edit this
        return counter;                     // You can NOT edit this
    }                                       // You can NOT edit this
 private:                                   // You can NOT edit this
    int counter = 0;                        // You can NOT edit this
} check;                                    // You can NOT edit this

struct Car {
    int id;
    Car() {}
    Car(int id) : id(id) {}
    virtual ~Car() {}
};

struct Sedan : public Car {
    Sedan(int id) : Car(id) {}
};

struct Hatchback : public Car {
    Hatchback(int id) : Car(id) {}
};

class Dealership {
 public:
    Dealership(int parkingLot) {
        numCars = parkingLot;
        cars = std::vector<Car *>();
    }

    void receiveCar(Car *car) {
        cars.push_back(car);
    }

    Car *sellCar(int i) {
        Car *car = cars[i];
        cars.erase(cars.begin() + i);

        return car;
    }

    int testDrive(int idx) {
        // if user is happy -> he will buy the car
        return check.is_user_happy(idx);
    }

    void printLot() {
        std::cout << check.get_counter() << "\n";
        for (Car *c : cars)
            std::cout << c->id << " ";

        std::cout << "\n";
    }

    std::vector<Car *> viewLot() {
        return cars;
    }

private:
    int numCars;
    std::vector<Car *> cars;
};

int main(void)
{
    unsigned int numCars;
    std::cin >> numCars;

    Dealership dealership(numCars);
    for (unsigned int i = 0; i < numCars; ++i) {
        Car car;
        int index;
        std::cin >> index;
        if (i % 2 == 0) {
            car = Sedan(index);
        } else {
            car = Hatchback(index);
        }
        dealership.receiveCar(&car);
    }

    size_t i = 0;
    auto dealerLot = dealership.viewLot();
    for (auto it = dealerLot.begin(); it != dealerLot.end(); it++) {
        if (dealership.testDrive(i))
            dealership.sellCar(i);
        i++;
    }

    dealership.printLot();
    return 0;
}
