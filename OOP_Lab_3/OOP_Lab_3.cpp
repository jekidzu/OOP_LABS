//#include <iostream> 
//#include <vector> 
//#include <memory> 
//#include <windows.h> 
//class Detail {
//protected:
//	Detail() {}
//public:
//	virtual ~Detail() = default;
//	virtual void display() const = 0;
//};
//class Assembly : public Detail {
//protected:
//	Assembly() {}
//public:
//	static std::shared_ptr<Assembly> create() {
//		return std::shared_ptr<Assembly>(new Assembly());
//	}
//	void display() const override {
//		std::cout << "Это объект типа Assembly (Сборка)." << std::endl;
//	}
//};
//template <typename T>
//void addToStorage(std::vector<std::shared_ptr<Detail>>& storage, std::shared_ptr<T> obj) {
//	storage.push_back(obj);
//}
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	std::vector<std::shared_ptr<Detail>> storage;
//	auto assembly1 = Assembly::create();
//	auto assembly2 = Assembly::create();
//	addToStorage(storage, assembly1);
//	addToStorage(storage, assembly2);
//	for (const auto& item : storage) {
//		item->display();
//	}
//	return 0;
//}