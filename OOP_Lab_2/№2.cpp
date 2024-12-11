#include <iostream> 
#include <string> 
#include <windows.h> 
using namespace std;

// Ѕазовый класс Publication дл€ хранени€ общей информации о публикации 
class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "¬ведите название: ";
        getline(cin, title);
        cout << "¬ведите цену: ";
        cin >> price;
        cin.ignore();  // очистка буфера 
    }

    void putdata() const {
        cout << "Ќазвание: " << title << endl;
        cout << "÷ена: " << price << " руб." << endl;
    }
};

// Ѕазовый класс Sales дл€ хранени€ данных о продажах за последние 3 мес€ца 
class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        cout << "¬ведите продажи за последние 3 мес€ца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "ћес€ц " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();  // очистка буфера 
    }

    void putdata() const {
        cout << "ѕродажи за последние 3 мес€ца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "ћес€ц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

//  ласс Book, наследуемый от Publication и Sales, добавл€ет количество страниц 
class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    void getdata() {
        Publication::getdata();
        cout << "¬ведите количество страниц: ";
        cin >> pageCount;
        Sales::getdata();
        cin.ignore();  // очистка буфера 
    }

    void putdata() const {
        Publication::putdata();
        cout << " оличество страниц: " << pageCount << endl;
        Sales::putdata();
    }
};

//  ласс Tape, наследуемый от Publication и Sales, добавл€ет врем€ записи 
class Tape : public Publication, public Sales {
private:
    float playTime;

public:
    void getdata() {
        Publication::getdata();
        cout << "¬ведите врем€ записи (в минутах): ";
        cin >> playTime;
        Sales::getdata();
        cin.ignore();  // очистка буфера 
    }

    void putdata() const {
        Publication::putdata();
        cout << "¬рем€ записи: " << playTime << " минут" << endl;
        Sales::putdata();
    }
};

int main() {
    SetConsoleCP(1251); // ”станавливаем ввод в кодировке Windows-1251 
    SetConsoleOutputCP(1251); // ”станавливаем вывод в кодировке Windows-1251 

    Book book;
    Tape tape;

    cout << "¬ведите данные дл€ книги:\n";
    book.getdata();

    cout << "\n¬ведите данные дл€ аудиозаписи:\n";
    tape.getdata();

    cout << "\n»нформаци€ о книге:\n";
    book.putdata();

    cout << "\n»нформаци€ об аудиозаписи:\n";
    tape.putdata();

    return 0;
}