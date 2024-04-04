#include <iostream>
#include <set>
using namespace std;

// Шаблонний клас для реалізації множини
template<typename T>
class Set {
private:
    set<T> data; // Внутрішня структура даних - STL set

public:
    // Конструктор за замовчуванням
    Set() {}

    // Конструктор зі списком ініціалізації
    Set(initializer_list<T> elements) : data(elements) {}

    // Деструктор
    ~Set() {}

    // Перегрузка оператора присвоєння
    Set<T>& operator=(const Set<T>& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Додає елемент до множини
    void add(const T& element) {
        data.insert(element);
    }

    // Додає кілька елементів зі списку ініціалізації
    void add(const initializer_list<T>& elements) {
        for (const auto& element : elements) {
            data.insert(element);
        }
    }

    // Видаляє елемент з множини
    void remove(const T& element) {
        data.erase(element);
    }

    // Очищує множину
    void clear() {
        data.clear();
    }

    // Перевіряє, чи міститься елемент у множині
    bool contains(const T& element) const {
        return data.count(element) > 0;
    }

    // Повертає розмір множини
    size_t size() const {
        return data.size();
    }

    // Об'єднання множин
    Set<T> union_with(const Set<T>& other) const {
        Set<T> result(*this);
        for (const auto& element : other.data) {
            result.add(element);
        }
        return result;
    }

    // Перетин множин
    Set<T> intersection_with(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : data) {
            if (other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Різниця множин
    Set<T> difference_with(const Set<T>& other) const {
        Set<T> result;
        for (const auto& element : data) {
            if (!other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Дружня функція для потокового виводу
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);
};

// Перегрузка оператора виводу для множини
template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
    os << "{ ";
    for (const auto& element : set.data) {
        os << element << " ";
    }
    os << "}";
    return os;
}
