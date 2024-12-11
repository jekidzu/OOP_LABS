//#include <iostream>
//#include <string> 
//#include <windows.h> 
//
//using namespace std;
//// Класс Publication для хранения общей информации 
//class Publication {
//protected:
//    string title;
//    float price;
//public:
//    // Метод для получения данных 
//    void getdata() {
//        cout << "Введите название: ";
//        getline(cin, title);
//        cout << "Введите цену: ";
//        cin >> price;
//        cin.ignore();  // Очистка буфера ввода 
//    }
//    // Метод для вывода данных 
//    void putdata() const {
//        cout << "Название: " << title << endl;
//        cout << "Цена: " << price << " руб." << endl;
//    }
//};
//// Класс Book, наследник Publication, добавляет количество страниц 
//class Book : public Publication {
//private:
//    int pageCount;
//
//public:
//    void getdata() {
//        Publication::getdata();
//        cout << "Введите количество страниц: ";
//        cin >> pageCount;
//        cin.ignore();  // Очистка буфера ввода 
//    }
//
//    void putdata() const {
//        Publication::putdata();
//        cout << "Количество страниц: " << pageCount << endl;
//    }
//};
//
//// Класс Tape, наследник Publication, добавляет время записи 
//class Tape : public Publication {
//private:
//    float playTime;
//
//public:
//    void getdata() {
//        Publication::getdata();
//        cout << "Введите время записи (в минутах): ";
//        cin >> playTime;
//        cin.ignore();  // Очистка буфера ввода 
//    }
//
//    void putdata() const {
//        Publication::putdata();
//        cout << "Время записи: " << playTime << " минут" << endl;
//    }
//};
//
//int main() {
//    SetConsoleCP(1251); // Устанавливаем ввод в кодировке Windows-1251 
//    SetConsoleOutputCP(1251); // Устанавливаем вывод в кодировке Windows-1251 
//
//    Book book;
//    Tape tape;
//
//    cout << "Введите данные для книги:\n";
//    book.getdata();
//
//    cout << "\nВведите данные для аудиозаписи:\n";
//    tape.getdata();
//
//    cout << "\nИнформация о книге:\n";
//    book.putdata();
//
//    cout << "\nИнформация об аудиозаписи:\n";
//    tape.putdata();
//
//    return 0;
//}