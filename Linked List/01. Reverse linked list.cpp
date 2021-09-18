<<<<<<< HEAD
/*
    Reverse a linked list by both iterative and recursive methods.
    Example:    Input: head of 1->2->3->4->NULL 
                Output: head of 4->3->2->1->NULL

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// Node class to represent a node of the linked list.
class Node {
public:
	int val;
	Node* next;
	Node() {
		val = 0;
		next = NULL;
	}
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

// Linked list class to implement a linked list.
class Linkedlist {
	Node* head;
public:
	Linkedlist() { head = NULL; }
	void insert(int) {                // To insert a node at the end of the linked list. 
        Node *newNode = new Node(data);   // Create the new Node.
        if (head == NULL) {               // Assign to head if it is first node
            head = newNode;
            return;
        }
        Node *temp = head;        
        while (temp->next != NULL)    // Traverse till end of list
            temp = temp->next;

        temp->next = newNode;   // Insert at the last.
    }

	void print() {
        if (head == NULL) {        // Check for empty list.
            cout << "List is empty \n";
            return;
        }

        Node* temp = head;        // Traverse the list.
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void iterativeReverse()
    {
        // Initialize current, previous and next pointers
        Node *prev = NULL;
        Node *current = head;
        Node *nextptr = NULL;
 
        while (current != NULL) {
            nextptr = current->next;     // Store next
            current->next = prev;       // Reverse current node's pointer
            prev = current;           // Move pointers one position ahead.
            current = nextptr;
        }
        head = prev;
    }

    Node* recursiveReverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;     // fix the head pointer 
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
 
    cout << "Given linked list: \n";
    list.print();

    list.iterativeReverse();
    cout << "Iteratively reversed Linked list: \n";
    list.print();
    cout << endl;
 
    list.head = list.recursiveReverse(list.head);
    cout << "Recursively reversed Linked list: \n";
    list.print();
    cout << endl;
    return 0;
=======
/*
    Reverse a linked list by both iterative and recursive methods.
    Example:    Input: head of 1->2->3->4->NULL 
                Output: head of 4->3->2->1->NULL

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// Node class to represent a node of the linked list.
class Node {
public:
	int val;
	Node* next;
	Node() {
		val = 0;
		next = NULL;
	}
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

// Linked list class to implement a linked list.
class Linkedlist {
	Node* head;
public:
	Linkedlist() { head = NULL; }
	void insert(int) {                // To insert a node at the end of the linked list. 
        Node *newNode = new Node(data);   // Create the new Node.
        if (head == NULL) {               // Assign to head if it is first node
            head = newNode;
            return;
        }
        Node *temp = head;        
        while (temp->next != NULL)    // Traverse till end of list
            temp = temp->next;

        temp->next = newNode;   // Insert at the last.
    }

	void print() {
        if (head == NULL) {        // Check for empty list.
            cout << "List is empty \n";
            return;
        }

        Node* temp = head;        // Traverse the list.
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void iterativeReverse()
    {
        // Initialize current, previous and next pointers
        Node *prev = NULL;
        Node *current = head;
        Node *nextptr = NULL;
 
        while (current != NULL) {
            nextptr = current->next;     // Store next
            current->next = prev;       // Reverse current node's pointer
            prev = current;           // Move pointers one position ahead.
            current = nextptr;
        }
        head = prev;
    }

    Node* recursiveReverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;     // fix the head pointer 
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
 
    cout << "Given linked list: \n";
    list.print();

    list.iterativeReverse();
    cout << "Iteratively reversed Linked list: \n";
    list.print();
    cout << endl;
 
    list.head = list.recursiveReverse(list.head);
    cout << "Recursively reversed Linked list: \n";
    list.print();
    cout << endl;
    return 0;
>>>>>>> bed65492fd13025ee099de5c0a490d788ec0f083
}