#include <iostream> 
#include <string> 
#include <windows.h> 
using namespace std;

// ������� ����� Publication ��� �������� ����� ���������� � ���������� 
class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "������� ��������: ";
        getline(cin, title);
        cout << "������� ����: ";
        cin >> price;
        cin.ignore();  // ������� ������ 
    }

    void putdata() const {
        cout << "��������: " << title << endl;
        cout << "����: " << price << " ���." << endl;
    }
};

// ������� ����� Sales ��� �������� ������ � �������� �� ��������� 3 ������ 
class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        cout << "������� ������� �� ��������� 3 ������:\n";
        for (int i = 0; i < 3; i++) {
            cout << "����� " << i + 1 << ": ";
            cin >> sales[i];
        }
        cin.ignore();  // ������� ������ 
    }

    void putdata() const {
        cout << "������� �� ��������� 3 ������:\n";
        for (int i = 0; i < 3; i++) {
            cout << "����� " << i + 1 << ": " << sales[i] << " ���." << endl;
        }
    }
};

// ����� Book, ����������� �� Publication � Sales, ��������� ���������� ������� 
class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    void getdata() {
        Publication::getdata();
        cout << "������� ���������� �������: ";
        cin >> pageCount;
        Sales::getdata();
        cin.ignore();  // ������� ������ 
    }

    void putdata() const {
        Publication::putdata();
        cout << "���������� �������: " << pageCount << endl;
        Sales::putdata();
    }
};

// ����� Tape, ����������� �� Publication � Sales, ��������� ����� ������ 
class Tape : public Publication, public Sales {
private:
    float playTime;

public:
    void getdata() {
        Publication::getdata();
        cout << "������� ����� ������ (� �������): ";
        cin >> playTime;
        Sales::getdata();
        cin.ignore();  // ������� ������ 
    }

    void putdata() const {
        Publication::putdata();
        cout << "����� ������: " << playTime << " �����" << endl;
        Sales::putdata();
    }
};

int main() {
    SetConsoleCP(1251); // ������������� ���� � ��������� Windows-1251 
    SetConsoleOutputCP(1251); // ������������� ����� � ��������� Windows-1251 

    Book book;
    Tape tape;

    cout << "������� ������ ��� �����:\n";
    book.getdata();

    cout << "\n������� ������ ��� �����������:\n";
    tape.getdata();

    cout << "\n���������� � �����:\n";
    book.putdata();

    cout << "\n���������� �� �����������:\n";
    tape.putdata();

    return 0;
}