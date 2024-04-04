#include <iostream>
#include "Set.h" 

using namespace std;

int main() {
    // Створення двох множин
    Set<int> set1{ 1, 2, 3, 4 };
    Set<int> set2{ 3, 4, 5, 6 };

    // Виведення множин на екран
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;

    // Додавання елементів до першої множини
    for (int i = 1; i < 10; ++i) set1.add(i);
    cout << "Addition: " << set1 << endl;

    // Об'єднання множин
    Set<int> unionSet = set1.union_with(set2);
    cout << "Union: " << unionSet << endl;

    // Перетин множин
    Set<int> intersectionSet = set1.intersection_with(set2);
    cout << "Intersection: " << intersectionSet << endl;

    // Різниця множин
    Set<int> differenceSet = set1.difference_with(set2);
    cout << "Difference: " << differenceSet << endl;

    // Видалення елемента з першої множини
    set1.remove(3);
    cout << "Remove: " << set1 << endl;

    // Перевірка, чи міститься елемент у першій множині
    int elementToCheck = 3;
    if (set1.contains(elementToCheck)) {
        cout << "Set contains element " << elementToCheck << endl;
    }
    else {
        cout << "Set does not contain element " << elementToCheck << endl;
    }

    // Очищення другої множини
    set2.clear();
    cout << "Set2: " << set2;

    return 0;
}