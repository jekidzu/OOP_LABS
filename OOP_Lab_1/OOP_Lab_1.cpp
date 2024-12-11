//#include <windows.h>
//#include <iostream>
//
//int main() {
//    SetConsoleCP(1251); // Устанавливаем ввод в кодировке Windows-1251
//    SetConsoleOutputCP(1251); // Устанавливаем вывод в кодировке Windows-1251
//
//    int n;
//    std::cout << "Введите размер массива: ";
//    std::cin >> n;
//
//    int* arr = new int[n];
//
//    std::cout << "Введите " << n << " целых чисел:\n";
//    for (int i = 0; i < n; i++) {
//        std::cin >> arr[i];
//    }
//
//    std::cout << "Массив: ";
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "Адрес начала массива: " << arr << std::endl;
//
//    for (int i = 0; i < n; i++) {
//        std::cout << "Элемент " << i << ": " << arr[i]
//            << " на расстоянии " << (arr + i) - arr << " ячеек памяти от начала\n";
//    }
//
//    delete[] arr;
//
//    return 0;
//}
