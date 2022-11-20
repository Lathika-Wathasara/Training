#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void insertNode(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
    
}

void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; 
        delete temp;            
        return;
    }
    
    else {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        
    if (temp == NULL){
        cout << key <<" is not found"<<endl;
        return;
    }
        
 
    prev->next = temp->next;
 
    delete temp;
    }
    
}

void searchNode(Node** head_ref, int key)
{
    Node* now = *head_ref;
    while (now!= NULL)
    {
        if (now-> data == key){
            cout << key << " is found" << endl;
            return;
        }
    now = now -> next;
    }
    cout<< key << " is not found" << endl;
    return;
    
}


int main()
{   
    int a, b;
    Node* head = NULL;
    
    while(true){
        
        cin >> a;
        
        if(a == -1){
            printList(head);
            break;
        }
        
        cin >> b;
        
        switch (a) {
          case 1:
            insertNode(&head, b);
            break;
          case 2:
            deleteNode(&head, b);
            break;
          case 3:
            searchNode(&head, b);
            break;
        }
        
    }

    return 0;
}