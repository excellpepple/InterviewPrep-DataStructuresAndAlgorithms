#pragma once
#include <iostream>

class StackArr
{
private:
    int Capacity;
    int Count;
    int* Items;
    int CurrentIndex;

public:
    StackArr()
    {
        Capacity = 3;
        Count = 0;
        CurrentIndex=-1;
        Items = new int[Capacity];
    }
    StackArr(int newCapacity)
    {
        Capacity = newCapacity;
        Count = 0;
        CurrentIndex = -1;
        Items = new int[Capacity];
    }
    ~StackArr()
    {
        delete[] Items;
    }

    void Push(int item)
    {
        if (Count == GetSize())
        {
            ReSize();
        }
        CurrentIndex++;
        Items[CurrentIndex] = item;
        Count++;

    }

    int Pop()
    {
        if (!IsEmpty())
        {
            int result = Items[CurrentIndex];
            CurrentIndex--;
            Count--;
            return result;

        }
        throw std::underflow_error("Stack is empty, cannot pop.");

    }

    int Peek()
    {
        if (!IsEmpty())
        {
            int result = Items[CurrentIndex];
            return result;

        }
        throw std::underflow_error("Stack is empty, cannot peek.");

    }
    bool IsEmpty()
    {
        return Count == 0;

    }
    bool IsFull()
    {
        return Count == Capacity;
    }

    int GetSize()
    {
        return Capacity;
    }

    void ReSize()
    {

        int* NewItems = new int[Capacity * 2];
        for (int i = 0; i < Count; i++)
        {
            NewItems[i] = Items[i];
        }
        delete[] Items;
        Items = NewItems;
        Capacity *= 2;

    }

    void Display()
    {
        std::cout << "---- Stack Contents----\n";
        for (int i = 0; i < Count; i++)
        {
            std::cout << "\t  " << Items[i] << "\n";
        }
        std::cout << "----------End---------\n";
    }

};
