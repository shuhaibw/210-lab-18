// COMSC-210 | Lab 18 | Shuhaib Walahi

#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node
{
    float rating;
    string comments;
    Node* next;
}

int main()
{
    // make a head of linked list
    Node* head = nullptr;
    //make var for the mode choice
    int mode;

    cout << "Which linked list method should we use?
    [1] New nodes are added at the head of the linked list
    [2] New nodes are added at the tail of the linked list" << endl;

    while(true)
    {
        cout << "Choice: ";
        cin >> mode

        // check if user entered an int
        if(cin.fail())
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
            cin.clear();
            // ignore the rest of the line 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // restart the while loop
            continue;
        }

        if(mode == 1)
        {
            break;
        }
        else if (mode == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
        }
    }

    return 0;
}