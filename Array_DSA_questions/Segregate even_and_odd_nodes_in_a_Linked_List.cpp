

// 
// this code is not a optimal solution of the code 
//
#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* divide(Node* head) {
        // Create dummy nodes to start the even and odd lists
        Node* evenHead = new Node(-1);
        Node* oddHead = new Node(-1);
        Node* even = evenHead;  // Pointer to traverse even list
        Node* odd = oddHead;    // Pointer to traverse odd list
        Node* temp = head;      // Pointer to traverse the original list
        
        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                even->next = temp;  // Add current node to even list
                even = even->next;   // Move even pointer
            } else {
                odd->next = temp;   // Add current node to odd list
                odd = odd->next;    // Move odd pointer
            }
            temp = temp->next;  // Move to the next node in the original list
        }
        
        // Terminate both even and odd lists
        odd->next = nullptr;  // End odd list
        even->next = oddHead->next;  // Link even list to odd list
        
        return evenHead->next;  // Return the start of the even list
    }

    // Helper function to print the linked list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Helper function to create a linked list from user input
    Node* createList(int n) {
        int data;
        Node* head = nullptr;
        Node* temp = nullptr;

        cout << "Enter the elements of the list: ";
        for (int i = 0; i < n; i++) {
            cin >> data;
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    Solution sol;
    
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    Node* head = sol.createList(n);  // Create the linked list from user input

    cout << "Original list: ";
    sol.printList(head);  // Print the original linked list

    Node* result = sol.divide(head);  // Divide the list into even and odd lists
    cout << "List after dividing into even and odd: ";
    sol.printList(result);  // Print the resulting list

    return 0;
}
