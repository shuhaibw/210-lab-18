// COMSC-210 | Lab 18 | Shuhaib Walahi

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// struct for moview review nodes
struct Node
{
    float rating;
    string comments;
    Node* next;
}

// function prototypes
void displayList(Node* head);
void deleteList(Node*& head);
void addHead(Node*& head, float rating, const string& comments);
void addTail(Node*& head, float rating, const string& comments);

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
    // pass in head to the display function
    displayList(head);

    // delete the list
    deleteList(head);

    return 0;
}

void displayList(Node* head) 
{
    Node* temp = head;
    int count = 1;
    float total = 0;
    int reviewAmount = 0;

    // loop while current is not nullptr
    while (current)
    {
      
    }
}

void deleteList(Node*& head) 
{
    // assign current to point to head
    Node* current = head;

    while (current)
    {
        // make head point to second node
        head = current->next;
        // delete first node current is pointing to
        delete current;
        // assign current to point to second one which is now first
        current = head;
    }

    // assign head point to nullptr when all nodes delete
    head = nullptr;
}

void addHead(Node*& head, float rating, const string& comments) 
{

}

void addTail(Node*& head, float rating, const string& comments) 
{

}