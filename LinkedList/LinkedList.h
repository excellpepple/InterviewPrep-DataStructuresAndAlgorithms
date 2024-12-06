#pragma once
#include <iostream>

struct Node
{
    int data;
    Node* next;

};

class LinkedList
{
private:
    Node* Head;
    Node* Tail;
    Node* Prev;
    int Count;
    int CurrentIndex;




public:
    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
        Prev = nullptr;
        Count = 0;
        CurrentIndex = 0;
    }
    void InsertAtBeginning(int data)
    {
        Node* NewNode = new Node();
        NewNode->data = data;
        if(IsEmpty())
        {
            Head = NewNode;
            Tail = Head;
            Prev = nullptr;
            Count =1;
            CurrentIndex = 1;
            return;
        }
        else
        {
            NewNode->next = Head;
            Tail = NewNode;
            Head = NewNode;
        }
        Count++;

    }

    void InsertAtEnd(int data)
    {
        Node* NewNode = new Node();
        NewNode->data = data;
        NewNode->next = nullptr;

        if(IsEmpty())
        {
            Head = NewNode;
            Tail = Head;
            Prev = nullptr;

            Count = 1;
            CurrentIndex = 1;
            return;
        }
        else
        {
            Node* Temp = Tail;
            Tail->next = NewNode;
            Tail = Temp->next;
            Count++;
        }

    }

    void InsertAtPosition(int data, int position)
    {
        if (position > Count || position < 1)
        {
            std::cout << "Invalid position\n" ;
            return;
        }
        if (position == 1)
        {
            InsertAtBeginning(data);
            return;
        }
        if (position == Count)
        {
            InsertAtEnd(data);
            return;
        }

        Node* NewNode = new Node();
        NewNode->data = data;
        if(IsEmpty())
        {
            Head = NewNode;
            Count = 0;
        }
        else
        {
            Node* Item{nullptr};

            if (position < CurrentIndex)
            {
                Item = Head;
                CurrentIndex = 1;
            }else
            {
                Item = Prev;
            }

            for (; Item != Tail; Item = Item->next)
            {
                if(CurrentIndex != position)
                {
                    CurrentIndex++;
                    Prev = Item;
                }
                if (CurrentIndex == position)
                {
                     NewNode->next = Item;
                     Prev->next = NewNode;
                     Count++;
                     break;

                }
            }
        }
    }

    void DeleteFromBeginning()
    {
        if (IsEmpty()) return;
        CurrentIndex = 1;
        Prev = nullptr;
        Node* NewNode = Head;
        Head = NewNode->next;
        Count--;
        delete NewNode;

    }

    void DeleteFromEnd()
    {
        if (IsEmpty()) return;
        if(Count == 1)
        {
            delete Head;
            Head = nullptr;
            Tail = nullptr;

            Count = 0;
            return;
        }

        Node* Item = Prev;
        if ( CurrentIndex != Count)
        {
            for (; Item != Tail; Item = Item->next)
            {
                CurrentIndex++;
                Prev = Item;
            }
        }
        Prev->next = nullptr;
        Tail = Prev;
        Count--;
        delete Item;

    }

    void DeleteFromPosition(int Position)
    {
        if (IsEmpty()) return;
        if (Position > CurrentIndex)
        {
            std::cout << "Invalid Position \n";
            return;
        }
        if(Count == 1)
        {
            delete Head;
            delete Prev;
            Head = nullptr;
            Tail = nullptr;
            Prev = nullptr;

            Count = 0;
            CurrentIndex = 0;
            return;
        }
        Node* Temp = nullptr;
        if (Position < CurrentIndex )
        {
            Temp = Head;
            CurrentIndex = 1;
        }
        else
        {
            Temp = Prev;
        }
        for (; Temp != nullptr; Temp = Temp->next)
        {
            if(CurrentIndex != Position)
            {
                CurrentIndex++;
                Prev = Temp;
            }
            if (CurrentIndex == Position)
            {
                Prev->next = Temp->next;
                delete Temp;
                Count--;
                break;
            }
        }

    }

    void Display()
    {
        Node* Temp = Head;
        while (Temp!= nullptr)
        {
            std::cout << Temp->data << " -> ";
            Temp = Temp->next;
        }
        std::cout << "NULL\n";

    }
    bool IsEmpty()
    {
        bool result = Head == nullptr;
        // if (result) delete Tail;
        // Tail = nullptr;

        return result;
    }
    
};
