#include <iostream>
using namespace std;

template <class X=int>
class Stack
{
    int max;
    X* data;
    int top;

public:
    Stack(int m)
    {
        max = m;
        data = new X[max];
        top = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(X n)
    {
        if (top != max - 1)
            data[++top] = n;
        else
            cout << "Stack Overflow.\n";
    }

    void pop()
    {
        if (top != -1)
            top--;
        else
            cout << "Stack Underflow.\n";
    }
};

int main()
{
    int maxSize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxSize;

    Stack<> intStack(maxSize);  // Assuming the stack will hold integers

    int choice;
    int value;

    do
    {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            intStack.push(value);
            break;

        case 2:
            intStack.pop();
            break;

        case 3:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
