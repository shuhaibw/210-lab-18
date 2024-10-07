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

    // loop until valid input is received
    while (true)
    {
        cout << "Choice: ";
        cin >> mode

        // check if user entered an int
        if (cin.fail())
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
            cin.clear();
            // ignore the rest of the line 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // restart the while loop
            continue;
        }

        if (mode == 1 || mode == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
        }
    }

    // var for checking if user wants to do another review 
    char anotherReview; 

    do
    {
        float rating;
        // collect rating from user
        cout << "Enter review rating 0-5: "
        cin >> rating;

        // loop to validate rating
        while (cin.fail() || rating < 0 || rating > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 0 and 5."
            cin >> rating;
        }

        // clear input before collecting comments
        cin.ignore();
        string comments;
        cout << "Enter review comments: "
        getline(cin, comments);

        // add the rating and comments to the list
        if (mode == 1)
        {
            addHead(head, rating, comments);
        }
        else
        {
            addTail(tail, rating, comments);
        }

        // get and validate user input for another review
        do
        {
            cout << "Enter another review? Y/N: ";
            cin >> anotherReview;
            // make input lowercase
            anotherReview = tolower(anotherReview);

            // validate user input
            if (anotherReview != 'y' || anotherReview != 'n')
            {
                cout << "Invalid input. Please enter Y or N." << endl;
            }

        } while (anotherReview != 'y' || anotherReview != 'n')

        // clear input
        cin.ignore();

    } while (anotherReview == 'y') // loop until the user says no more reviews

    cout << "Outputting all reviews:" << endl;
    // pass in null head to the display function
    displayList(head)

    return 0;
}