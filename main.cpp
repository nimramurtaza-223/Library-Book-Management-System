#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList library;

    int choice, id, index, firstIndex, secondIndex;
    string title;

    library.InsertAt(CreateBook(103, "Operating Systems"), 0);
    library.InsertAt(CreateBook(101, "Data Structures"), 1);
    library.InsertAt(CreateBook(105, "Computer Networks"), 2);
    library.InsertAt(CreateBook(102, "Database Systems"), 3);
    library.InsertAt(CreateBook(104, "Software Engineering"), 4);

    do
    {
        cout << "\n===== LIBRARY BOOK COLLECTION SYSTEM =====\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Check Collection Status\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            library.Print();
            break;

        case 2:
            cout << "Enter book ID: ";
            if(!(cin>>id))
            {
                cout<<"Invalid book ID.Please enter a number.\n;
                    cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter book title: ";
            getline(cin, title);

            library.Insert(CreateBook(id, title));
            break;
            }

        case 3:
        {
            BookNode* removed = library.Remove();

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else
                cout << "Collection is empty.\n";

            break;
        }

        case 4:
            cout << "Enter book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter index: ";
            cin >> index;

            library.InsertAt(CreateBook(id, title), index);
            break;

        case 5:
        {
            cout << "Enter index: ";
            cin >> index;

            BookNode* removed = library.RemoveAt(index);

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else
                cout << "Collection is empty.\n";

            break;
        }

        case 6:
            cout << "Enter first index: ";
            cin >> firstIndex;

            cout << "Enter second index: ";
            cin >> secondIndex;

            library.Swap(firstIndex, secondIndex);
            break;

        case 7:
            library.Sort();
            cout << "Books sorted by ID.\n";
            break;

        case 8:
            library.Reverse();
            cout << "Collection reversed.\n";
            break;

        case 9:
            if (library.IsEmpty())
                cout << "Collection is empty.\n";
            else
                cout << "Collection is not empty.\n";

            break;

        case 10:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
