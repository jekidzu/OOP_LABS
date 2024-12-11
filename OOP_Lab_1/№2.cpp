#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

class Book {
private:
    std::string author;
    std::string title;
    std::string type;

public:
    // Конструктор с тремя параметрами
    Book(const std::string& author, const std::string& title, const std::string& type)
        : author(author), title(title), type(type) {}

    // Получение типа книги
    std::string getType() const {
        return type;
    }
};

// Функция для вывода количества книг по типам с использованием switch
void countBooksByType(const std::vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (const auto& book : library) {
        std::string type = book.getType();
        if (type == "Художественная") {
            fictionCount++;
        }
        else if (type == "Техническая") {
            technicalCount++;
        }
    }

    std::cout << "Количество художественной литературы: " << fictionCount << std::endl;
    std::cout << "Количество технической литературы: " << technicalCount << std::endl;
}

int main() {

    SetConsoleCP(1251); // Устанавливаем ввод в кодировке Windows-1251
    SetConsoleOutputCP(1251); // Устанавливаем вывод в кодировке Windows-1251

    // Создание библиотеки (вектор книг)
    std::vector<Book> library;

    // Наполнение библиотеки книгами
    library.push_back(Book("Лев Толстой", "Война и мир", "Художественная"));
    library.push_back(Book("Исаак Ньютон", "Математические начала натуральной философии", "Техническая"));
    library.push_back(Book("Джордж Оруэлл", "1984", "Художественная"));
    library.push_back(Book("Алессандро Волта", "Теории электричества", "Техническая"));

    // Вызов функции для вывода количества книг по типам
    countBooksByType(library);

    return 0;
}
