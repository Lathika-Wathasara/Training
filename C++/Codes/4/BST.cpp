#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//new node
struct node* NewNode(int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right =NULL;
    return temp; 
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root!=NULL){
    if (root-> left == NULL && root-> right == NULL){
        cout<< root->key<<" ";
    }
    else  {
        
        if(root->left != NULL){traverseInOrder(root->left);}

        cout<< root->key<<" ";

        if(root->right != NULL){traverseInOrder(root->right);}

    }
    }
    else{
        cout<<"";
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {

    if (node== NULL){
        
        return NewNode(key);
    }
    else{
    if (node -> key == key){
        return node;
    }
    else if (node-> key > key){
        if (node ->left == NULL){
            node->left = NewNode(key);
            return node;
        }
        else{
            node-> left = insertNode(node->left, key);
            return node;
        }
    }
    else{
        if (node ->right == NULL){
            node->right = NewNode(key);
            return node;
        }
        else{
            node-> right = insertNode(node->right, key);
            return node;
        }
    }
    }

}



// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    
    if (root== NULL){
        return NULL;
    }
    if (root->key == key){
        if (  root->left ==NULL && root-> right ==NULL){
            root = NULL;
            return root;
        }
        else if ( root->right != NULL){
            struct node*successor = root->right;
            while (successor->left !=NULL){
                successor = successor->left;
            }
            root ->key = successor->key;
            root->right = deleteNode(root->right, successor->key);
        }
        else {
            struct node*predecessor = root->left;
            while (predecessor->right !=NULL){
                predecessor = predecessor->right;
            }
            root-> key = predecessor->key;
            root->left = deleteNode(root->left, predecessor->key);
        }
    }
    else if (root-> key >key){
        root->left = deleteNode(root->left, key);
    }
    else{
        root->right= deleteNode(root->right, key);
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}