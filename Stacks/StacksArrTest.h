#pragma once
#include "StackArr.h"

class StacksArrTest
{
    public:
    static void RunAllTests() {
        TestPush();
        TestPop();
        TestPeek();
        TestIsEmpty();
        TestIsFull();
        TestReSize();
    }

private:
    static void TestPush() {
        StackArr stack(3);
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);

        std::cout << "TestPush: ";
        if (stack.Peek() == 30)
            std::cout << "Passed\n";
        else
            std::cout << "Failed\n";
    }

    static void TestPop() {
        StackArr stack(3);
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);

        int poppedItem = stack.Pop();

        std::cout << "TestPop: ";
        if (poppedItem != 30 )
            std::cout << "Failed\n";
        else
            std::cout << "Passed\n";
    }

    static void TestPeek() {
        StackArr stack(3);
        stack.Push(10);
        stack.Push(20);

        int topItem = stack.Peek();

        std::cout << "TestPeek: ";
        if (topItem == 20)
            std::cout << "Passed\n";
        else
            std::cout << "Failed\n";
    }

    static void TestIsEmpty() {
        StackArr stack(3);
        std::cout << "TestIsEmpty: ";
        if (stack.IsEmpty())
            std::cout << "Passed\n";
        else
            std::cout << "Failed\n";

        stack.Push(10);
        if (!stack.IsEmpty())
            std::cout << "Passed\n";
        else
            std::cout << "Failed\n";
    }

    static void TestIsFull() {
        StackArr stack(3);
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);

        std::cout << "TestIsFull: ";
        if (stack.IsFull())
            std::cout << "Passed\n";
        else
            std::cout << "Failed\n";
    }

    static void TestReSize() {
        StackArr stack(3);
        stack.Push(10);
        stack.Push(20);
        stack.Push(30);
        stack.Push(40); // This should trigger resizing

        std::cout << "TestReSize: ";
        if (stack.Peek() == 40 && !stack.IsFull()) // Resized stack should not be full
            std::cout << "Passed\n";

        else
            std::cout << "Failed\n";

        stack.Display();
    }
};
