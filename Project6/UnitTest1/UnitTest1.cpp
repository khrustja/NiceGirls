#include "pch.h"
#include "CppUnitTest.h" 
#include "../Project6/Set.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 
{
    TEST_CLASS(UnitTest1) 
    {
    public:

        TEST_METHOD(DefaultConstructorTest) // ���� ������������ �� �������������
        {
            Set<int> set; // ��������� �������� �������
            Assert::AreEqual((size_t)0, set.size()); // ��������, �� ����� ������� 0
        }

        TEST_METHOD(InitializerListConstructorTest) // ���� ������������ � ������� �����������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            Assert::AreEqual((size_t)3, set.size()); // ��������, �� ����� ������� 3
        }

        TEST_METHOD(CopyConstructorTest) // ���� ������������ ������������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            Set<int> copySet(set); // ��������� ��ﳿ �������
            Assert::AreEqual(set.size(), copySet.size()); // ��������, �� ������ �������
        }

        TEST_METHOD(AssignmentOperatorTest) // ���� ��������� ������������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            Set<int> assignedSet = set; // ��������� ���� ������� �����
            Assert::AreEqual(set.size(), assignedSet.size()); // ��������, �� ������ �������
        }

        TEST_METHOD(AddTest) // ���� ��������� ��������
        {
            Set<int> set; // ��������� �������� �������
            set.add(1); // ��������� ������ ��������
            set.add({ 2, 3, 4 }); // ��������� �������� �������� �� ��������� ������ �����������
            Assert::AreEqual((size_t)4, set.size()); // ��������, �� ����� ������� 4
            Assert::IsTrue(set.contains(1)); // ��������, �� 1 �������� � ������
            Assert::IsTrue(set.contains(2)); // ��������, �� 2 �������� � ������
            Assert::IsTrue(set.contains(3)); // ��������, �� 3 �������� � ������
            Assert::IsTrue(set.contains(4)); // ��������, �� 4 �������� � ������
        }

        TEST_METHOD(RemoveTest) // ���� ��������� ��������
        {
            Set<int> set{ 1, 2, 3, 4 }; // ��������� ������� � ����������� ����������
            set.remove(3); // ��������� ��������
            Assert::AreEqual((size_t)3, set.size()); // ��������, �� ����� ������� 3
            Assert::IsFalse(set.contains(3)); // ��������, �� 3 ������� � ������
        }

        TEST_METHOD(ClearTest) // ���� �������� �������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            set.clear(); // �������� �������
            Assert::AreEqual((size_t)0, set.size()); // ��������, �� ����� ������� 0
        }

        TEST_METHOD(ContainsTest) // ���� �������� ���������� ��������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            Assert::IsTrue(set.contains(2)); // ��������, �� 2 �������� � ������
            Assert::IsFalse(set.contains(4)); // ��������, �� 4 ������� � ������
        }

        TEST_METHOD(SizeTest) // ���� ��������� ������ �������
        {
            Set<int> set{ 1, 2, 3 }; // ��������� ������� � ����������� ����������
            Assert::AreEqual((size_t)3, set.size()); // ��������, �� ����� ������� 3
        }

        TEST_METHOD(UnionTest) // ���� ��'������� ������
        {
            Set<int> set1{ 1, 2, 3 }; // ��������� ����� �������
            Set<int> set2{ 3, 4, 5 }; // ��������� ����� �������
            Set<int> result = set1.union_with(set2); // ��'������� ������
            Assert::AreEqual((size_t)5, result.size()); // ��������, �� ����� ��'������ ������� ������� 5
            Assert::IsTrue(result.contains(1)); // ��������, �� 1 �������� � ��'������ ������
            Assert::IsTrue(result.contains(2)); // ��������, �� 2 �������� � ��'������ ������
            Assert::IsTrue(result.contains(3)); // ��������, �� 3 �������� � ��'������ ������
            Assert::IsTrue(result.contains(4)); // ��������, �� 4 �������� � ��'������ ������
            Assert::IsTrue(result.contains(5)); // ��������, �� 5 �������� � ��'������ ������
        }

        TEST_METHOD(IntersectionTest) // ���� �������� ������
        {
            Set<int> set1{ 1, 2, 3 }; // ��������� ����� �������
            Set<int> set2{ 3, 4, 5 }; // ��������� ����� �������
            Set<int> result = set1.intersection_with(set2); // ������� ������
            Assert::AreEqual((size_t)1, result.size()); // ��������, �� ����� ���������� ������� 1
            Assert::IsTrue(result.contains(3)); // ��������, �� 3 �������� � ���������
        }

        TEST_METHOD(DifferenceTest) // ���� ������ ������
        {
            Set<int> set1{ 1, 2, 3 }; // ��������� ����� �������
            Set<int> set2{ 3, 4, 5 }; // ��������� ����� �������
            Set<int> result = set1.difference_with(set2); // г����� ������
            Assert::AreEqual((size_t)2, result.size()); // ��������, �� ����� ���������� ������� 2
            Assert::IsTrue(result.contains(1)); // ��������, �� 1 �������� � ���������
            Assert::IsTrue(result.contains(2)); // ��������, �� 2 �������� � ���������
        }
    };
}