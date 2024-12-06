#pragma once
#include <iostream>

#include "LinkedList.h"

class LinkedList_Test
{
public:
    static void RunAllTests() {
        TestInsertAtBeginning();
        TestInsertAtEnd();
        TestInsertAtPosition();
        // TestDeleteFromBeginning();
        //TestDeleteFromEnd();
        //TestDeleteFromPosition();
        //TestDisplay();
    }

private:
    static void TestInsertAtBeginning() {
        LinkedList list;
        list.InsertAtBeginning(10);
        list.InsertAtBeginning(20);
        list.InsertAtBeginning(30);

        std::cout << "TestInsertAtBeginning: ";
        list.Display(); // Expected: 30 -> 20 -> 10
    }

    static void TestInsertAtEnd() {
        LinkedList list;
        list.InsertAtEnd(10);
        list.InsertAtEnd(20);
        list.InsertAtEnd(30);

        std::cout << "TestInsertAtEnd: ";
        list.Display(); // Expected: 10 -> 20 -> 30
    }

    static void TestInsertAtPosition() {
        LinkedList list;
        list.InsertAtBeginning(10);
        list.InsertAtBeginning(20);
        list.InsertAtPosition(15, 2);

        std::cout << "TestInsertAtPosition: ";
        list.Display(); // Expected: 20 -> 15 -> 10
    }

    static void TestDeleteFromBeginning() {
        LinkedList list;
        list.InsertAtBeginning(10);
        list.InsertAtBeginning(20);
        list.DeleteFromBeginning();

        std::cout << "TestDeleteFromBeginning: ";
        list.Display(); // Expected: 10
    }

    static void TestDeleteFromEnd() {
        LinkedList list;
        list.InsertAtEnd(10);
        list.InsertAtEnd(20);
        list.DeleteFromEnd();

        std::cout << "TestDeleteFromEnd: ";
        list.Display(); // Expected: 10
    }

    static void TestDeleteFromPosition() {
        LinkedList list;
        list.InsertAtEnd(10);
        list.InsertAtEnd(20);
        list.InsertAtEnd(30);
        list.DeleteFromPosition(2);

        std::cout << "TestDeleteFromPosition: ";
        list.Display(); // Expected: 10 -> 30
    }

    static void TestDisplay() {
        LinkedList list;
        list.InsertAtEnd(10);
        list.InsertAtEnd(20);
        list.InsertAtEnd(30);

        std::cout << "TestDisplay: ";
        list.Display(); // Expected: 10 -> 20 -> 30
    }
};
