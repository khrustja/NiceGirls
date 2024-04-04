#include "pch.h"
#include "CppUnitTest.h" 
#include "../Project6/Set.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 
{
    TEST_CLASS(UnitTest1) 
    {
    public:

        TEST_METHOD(DefaultConstructorTest) // Тест конструктора за замовчуванням
        {
            Set<int> set; // Створення порожньої множини
            Assert::AreEqual((size_t)0, set.size()); // Перевірка, що розмір дорівнює 0
        }

        TEST_METHOD(InitializerListConstructorTest) // Тест конструктора зі списком ініціалізації
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            Assert::AreEqual((size_t)3, set.size()); // Перевірка, що розмір дорівнює 3
        }

        TEST_METHOD(CopyConstructorTest) // Тест копіювального конструктора
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            Set<int> copySet(set); // Створення копії множини
            Assert::AreEqual(set.size(), copySet.size()); // Перевірка, що розміри однакові
        }

        TEST_METHOD(AssignmentOperatorTest) // Тест оператора присвоювання
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            Set<int> assignedSet = set; // Присвоєння однієї множини іншій
            Assert::AreEqual(set.size(), assignedSet.size()); // Перевірка, що розміри однакові
        }

        TEST_METHOD(AddTest) // Тест додавання елементів
        {
            Set<int> set; // Створення порожньої множини
            set.add(1); // Додавання одного елемента
            set.add({ 2, 3, 4 }); // Додавання декількох елементів за допомогою списку ініціалізації
            Assert::AreEqual((size_t)4, set.size()); // Перевірка, що розмір дорівнює 4
            Assert::IsTrue(set.contains(1)); // Перевірка, що 1 присутній в множині
            Assert::IsTrue(set.contains(2)); // Перевірка, що 2 присутній в множині
            Assert::IsTrue(set.contains(3)); // Перевірка, що 3 присутній в множині
            Assert::IsTrue(set.contains(4)); // Перевірка, що 4 присутній в множині
        }

        TEST_METHOD(RemoveTest) // Тест видалення елементів
        {
            Set<int> set{ 1, 2, 3, 4 }; // Створення множини з початковими елементами
            set.remove(3); // Видалення елемента
            Assert::AreEqual((size_t)3, set.size()); // Перевірка, що розмір дорівнює 3
            Assert::IsFalse(set.contains(3)); // Перевірка, що 3 відсутній в множині
        }

        TEST_METHOD(ClearTest) // Тест очищення множини
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            set.clear(); // Очищення множини
            Assert::AreEqual((size_t)0, set.size()); // Перевірка, що розмір дорівнює 0
        }

        TEST_METHOD(ContainsTest) // Тест перевірки присутності елемента
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            Assert::IsTrue(set.contains(2)); // Перевірка, що 2 присутній в множині
            Assert::IsFalse(set.contains(4)); // Перевірка, що 4 відсутній в множині
        }

        TEST_METHOD(SizeTest) // Тест отримання розміру множини
        {
            Set<int> set{ 1, 2, 3 }; // Створення множини з початковими елементами
            Assert::AreEqual((size_t)3, set.size()); // Перевірка, що розмір дорівнює 3
        }

        TEST_METHOD(UnionTest) // Тест об'єднання множин
        {
            Set<int> set1{ 1, 2, 3 }; // Створення першої множини
            Set<int> set2{ 3, 4, 5 }; // Створення другої множини
            Set<int> result = set1.union_with(set2); // Об'єднання множин
            Assert::AreEqual((size_t)5, result.size()); // Перевірка, що розмір об'єднаної множини дорівнює 5
            Assert::IsTrue(result.contains(1)); // Перевірка, що 1 присутній в об'єднаній множині
            Assert::IsTrue(result.contains(2)); // Перевірка, що 2 присутній в об'єднаній множині
            Assert::IsTrue(result.contains(3)); // Перевірка, що 3 присутній в об'єднаній множині
            Assert::IsTrue(result.contains(4)); // Перевірка, що 4 присутній в об'єднаній множині
            Assert::IsTrue(result.contains(5)); // Перевірка, що 5 присутній в об'єднаній множині
        }

        TEST_METHOD(IntersectionTest) // Тест перетину множин
        {
            Set<int> set1{ 1, 2, 3 }; // Створення першої множини
            Set<int> set2{ 3, 4, 5 }; // Створення другої множини
            Set<int> result = set1.intersection_with(set2); // Перетин множин
            Assert::AreEqual((size_t)1, result.size()); // Перевірка, що розмір результату дорівнює 1
            Assert::IsTrue(result.contains(3)); // Перевірка, що 3 присутній в результаті
        }

        TEST_METHOD(DifferenceTest) // Тест різниці множин
        {
            Set<int> set1{ 1, 2, 3 }; // Створення першої множини
            Set<int> set2{ 3, 4, 5 }; // Створення другої множини
            Set<int> result = set1.difference_with(set2); // Різниця множин
            Assert::AreEqual((size_t)2, result.size()); // Перевірка, що розмір результату дорівнює 2
            Assert::IsTrue(result.contains(1)); // Перевірка, що 1 присутній в результаті
            Assert::IsTrue(result.contains(2)); // Перевірка, що 2 присутній в результаті
        }
    };
}