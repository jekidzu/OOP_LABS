#include <iostream> 
#include <vector> 
#include <memory> 
#include <stdexcept> 
#include <windows.h> 
// Базовый класс "Средство передвижения" 
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void show() const = 0; // Полиморфный метод 
};
// Класс "Велосипед" 
class Bicycle : public Vehicle {
public:
    void show() const override {
        std::cout << "Это велосипед." << std::endl;
    }
};
// Класс "Автомобиль" 
class Car : public Vehicle {
public:
        void show() const override {
        std::cout << "Это автомобиль." << std::endl;
    }
};

// Класс "Грузовик" 
class Truck : public Vehicle {
public:
    void show() const override {
        std::cout << "Это грузовик." << std::endl;
    }
};

// Шаблонный класс для хранения массива указателей на объекты 
template <typename T>
class ObjectArray {
private:
    std::vector<std::shared_ptr<T>> storage;

public:
    void add(std::shared_ptr<T> obj) {
        storage.push_back(obj);
    }

    std::shared_ptr<T> operator[](size_t index) {
        if (index >= storage.size()) {
            throw std::range_error("Индекс превышает допустимый диапазон.");
        }
        return storage[index];
    }

    void showAll() const {
        for (const auto& obj : storage) {
            obj->show();
        }
    }

    void validateIndex(size_t index) const {
        if (index >= storage.size()) {
            throw std::range_error("Индекс превышает допустимый диапазон.");
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        // Создание массива для объектов Vehicle 
        ObjectArray<Vehicle> vehicles;

        vehicles.add(std::make_shared<Bicycle>());
        vehicles.add(std::make_shared<Car>());
        vehicles.add(std::make_shared<Truck>());

        std::cout << "Список всех транспортных средств:" << std::endl;
        vehicles.showAll();

        std::cout << "\nДоступ к объекту с индексом 1:" << std::endl;
        vehicles[1]->show();
        std::cout << "\nПопытка доступа к несуществующему индексу:" << std::endl;
        vehicles.validateIndex(5);
        vehicles[5]->show();
    }
    catch (const std::range_error& e) {
        std::cerr << "Ошибка (range_error): " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Другое исключение: " << e.what() << std::endl;
    }
    return 0;
}