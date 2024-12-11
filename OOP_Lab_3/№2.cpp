#include <iostream> 
#include <vector> 
#include <memory> 
#include <random> 
#include <windows.h> 

class Base {
public:
    virtual ~Base() = default;
    virtual void behavior() const {
        std::cout << "Поведение объекта типа Base." << std::endl;
    }
};
// Производный класс 
class Derived : public Base {
public:
    void behavior() const override {
        std::cout << "Поведение объекта типа Derived." << std::endl;
    }
};

void add(std::vector<std::shared_ptr<Base>>& storage, std::shared_ptr<Base> obj) {
    storage.push_back(obj); // Добавление объекта в хранилище 
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<std::shared_ptr<Base>> storage;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    for (int i = 0; i < 10; ++i) {
        if (dist(gen) % 2 == 0) {
            add(storage, std::make_shared<Base>());
        }
        else {
            add(storage, std::make_shared<Derived>());
        }
    }

    for (const auto& obj : storage) {
        obj->behavior();
    }
    return 0;
}