#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

struct BookNode
{
    int bookID;
    string title;
    BookNode* next;
};

class LinkedList
{
private:
    BookNode* head;
    int count;

    BookNode* GetNodeAt(int index);
    void CopyBookData(BookNode* a, BookNode* b);

public:
    LinkedList();
    ~LinkedList();

    void Insert(BookNode* book);
    BookNode* Remove();
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    void InsertAt(BookNode* book, int index);
    BookNode* RemoveAt(int index);
    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print();
};

BookNode* CreateBook(int id, string title);

#endif
