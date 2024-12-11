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
    // ����������� � ����� �����������
    Book(const std::string& author, const std::string& title, const std::string& type)
        : author(author), title(title), type(type) {}

    // ��������� ���� �����
    std::string getType() const {
        return type;
    }
};

// ������� ��� ������ ���������� ���� �� ����� � �������������� switch
void countBooksByType(const std::vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (const auto& book : library) {
        std::string type = book.getType();
        if (type == "��������������") {
            fictionCount++;
        }
        else if (type == "�����������") {
            technicalCount++;
        }
    }

    std::cout << "���������� �������������� ����������: " << fictionCount << std::endl;
    std::cout << "���������� ����������� ����������: " << technicalCount << std::endl;
}

int main() {

    SetConsoleCP(1251); // ������������� ���� � ��������� Windows-1251
    SetConsoleOutputCP(1251); // ������������� ����� � ��������� Windows-1251

    // �������� ���������� (������ ����)
    std::vector<Book> library;

    // ���������� ���������� �������
    library.push_back(Book("��� �������", "����� � ���", "��������������"));
    library.push_back(Book("����� ������", "�������������� ������ ����������� ���������", "�����������"));
    library.push_back(Book("������ ������", "1984", "��������������"));
    library.push_back(Book("���������� �����", "������ �������������", "�����������"));

    // ����� ������� ��� ������ ���������� ���� �� �����
    countBooksByType(library);

    return 0;
}
