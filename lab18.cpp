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
};

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

    cout << "Which linked list method should we use?\n"
    << "    [1] New nodes are added at the head of the linked list\n"
    << "    [2] New nodes are added at the tail of the linked list" << endl;

    // loop until valid input is received
    while (true)
    {
        cout << "Choice: ";
        cin >> mode;

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
        cout << "Enter review rating 0-5: ";
        cin >> rating;

        // loop to validate rating
        while (cin.fail() || rating < 0 || rating > 5)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 0 and 5." << endl;
            // ask again
            cout << "Enter review rating 0-5: ";
            cin >> rating;
        }

        // clear input before collecting the comments
        cin.ignore();
        string comments;
        cout << "Enter review comments: ";
        getline(cin, comments);

        // add the rating and comments to the list
        if (mode == 1)
        {
            addHead(head, rating, comments);
        }
        else
        {
            addTail(head, rating, comments);
        }

        // get and validate user input for another review
        do
        {
            cout << "Enter another review? Y/N: ";
            cin >> anotherReview;
            // make input lowercase
            anotherReview = tolower(anotherReview);

            // validate user input
            if (anotherReview != 'y' && anotherReview != 'n')
            {
                cout << "Invalid input. Please enter Y or N." << endl;
            }

        } while (anotherReview != 'y' && anotherReview != 'n');

        // clear input
        cin.ignore();

    } while (anotherReview == 'y'); // loop until the user says no more reviews

    cout << "Outputting all reviews:" << endl;
    // pass in head to the display function
    displayList(head);

    // delete the list
    deleteList(head);

    return 0;
}

/*
    displayList() outputs all reviews in the linked list.
    Arguments: 
    Node* head: Pointer to the head of the linked list.
    Returns: 
    void
*/
void displayList(Node* head) 
{
    // check if list is empty
    if (!head) 
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node* temp = head;
    int count = 1;
    float total = 0;
    int reviewCount = 0;

    // loop to traverse and output reviews
    while (temp)
    {
      cout << "    > Review #" << count << ": " << fixed 
      << setprecision(2) << temp->rating << ": " 
      << temp->comments << endl;
      // add the rating to total
      total += temp->rating;
      // increment review count
      reviewCount++;
      // go to next review
      temp = temp->next;
      count++;
    }

    // calculate and display average rating
    if (reviewCount > 0)
    {
        cout << "    > Average: " << fixed << setprecision(5) 
        << (total / reviewCount) << endl;
    }
}

/*
    deleteList() frees all nodes in the linked list.
    Arguments: 
    Node*& head: Reference to the head pointer of the linked list.
    Returns: 
    void
*/
void deleteList(Node*& head) 
{
    // check if list is empty
    if (!head) 
    {
        cout << "There is nothing to delete." << endl;
        return;
    }

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

/*
    addHead() inserts a new node at the beginning of the linked list.
    Arguments: 
    Node*& head: Reference to the list's head pointer.
    float rating: Review rating to be added.
    const string& comments: Review comments to be added.
    Returns: 
    void
*/
void addHead(Node*& head, float rating, const string& comments) 
{
    // create a new node
    Node* newNode = new Node();
    // assign rating and comments to the node
    newNode->rating = rating;
    newNode->comments = comments;
    // make new node point to current head
    newNode->next = head;
    // assign head to point to new node
    head = newNode;
}

/*
    addTail() appends a new node at the end of the linked list.
    Arguments: 
    Node*& head: Reference to the list's head pointer.
    float rating: Review rating to be added.
    const string& comments: Review comments to be added.
    Returns: 
    void
*/
void addTail(Node*& head, float rating, const string& comments) 
{
    Node* newNode = new Node();
    // assign values to node
    newNode->rating = rating;
    newNode->comments = comments;
    // make the node point to nullptr
    newNode->next = nullptr;

    if (!head) 
    {
        // if list is empty, assign new node as head
        head = newNode; 
    } 
    else 
    {
        // temp pointer to traverse the list
        Node* temp = head;
        while (temp->next)
        {
            // go to the end
            temp = temp->next;
        }

        // link new node at the end
        temp->next = newNode;
    }
}