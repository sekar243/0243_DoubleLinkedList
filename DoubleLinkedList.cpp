#include <iostream>
using namespace std;

// membuat struktur untuk object double LinkedList
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemberian nilai
Node *START = NULL;

// deklarasi prosedur addNode
void addNode()
{

    // pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node(); //step 1 buat Node baru
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; // Assign value to the data field of the new Node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name; // Assign values to the data field of th

    // Insert the new node in the list
    // kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        // kondisi jika star tidak kosong dan noMhs node baru sama dengan noMhs
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        // jika list kosong, maka node next nya adalah START
        newNode->next = START; // step 3: make the new node point to the frst node
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
            START->prev = newNode; // step 4: make the first node point to the node
        }
        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make the new node point to NULL
        START = newNode; // step 6: make the new node the the first node
    }
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {

        // insert the new nide in the middle or at the end
        // set nilai current = start dan nilai previous = nill
        Node *current = START; // step 1.a : start from the first node
        Node *previous = NULL; // step 1.b : previous node is Null initially

        // looping selama current != null dan noMhs dari current lebih kecil
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                        // step 1.c: traverse the list to find the 
            previous = current; // step 1.d: move the prrevious to the current
            current = current->next; // step 1.e: move the current to the next
        }

        //set nilai next node baru = current dan prev node baru = previous
        newNode->next = current; // step4: make the next field of the new node
        newNode->prev = previous; // step 5: make the previous field of the new node

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the 
        }

        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next field of the previous
        }
        // kondisi jika if previous sama dengan null
        else
        {
            // if previous is still NULL, it means newNode is now the first node
            START = newNode;
        }
        
    }

}

// pembuatan function search untuk mencari data
bool seacrh(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);

}

// pembuatan prosedur delete untuk menghapus data
void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be delete: ";
    cin >> rollNo; // step 3: get the roll number number to be delete

    if (START == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    current = START; // step 1: start from the first node
    previous = NULL;

    // locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number]"
        << rollNo << " not found\033[0m" << endl;
        return;
    }
    
    
}