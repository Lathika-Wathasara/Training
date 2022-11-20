/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:*/
#include <iostream>
using namespace std;

	struct Node {
		int data;
		Node* left;
		Node* right;
	};
// was a cmnt before

    bool checkLeaf(Node* nd){
        if (nd->left ==NULL && nd->right==NULL){
            return true;
        }
        else{return false;}
    } 

    bool check_two_Leaf_branch(Node* nd){
        if (nd->left !=NULL && nd->right!=NULL){
            return true;
        }
        else{return false;}
    }

    

    bool checkBST(Node* root) {

        /*if (root->left ==NULL && root-> right==NULL){
            return true;
        }
        else*/ if (root->left != NULL && root-> right==NULL){
            if (checkLeaf(root->left)){
                if(root->left->data <= root->data){
                    return true;
                }
                else{return false;}
            }
            else if (checkBST(root->left)){
                if (root->left->data <= root->data){ return true;}
                else{return false;}
            }
            else {return false;}
            }
        else if (root->left == NULL && root-> right!=NULL){
            if (checkLeaf(root->right)){
                if(root->right->data >= root->data){
                    return true;
                }
                else{return false;}
            }
            else if (checkBST(root->right)){
                if (root->right->data >= root->data){ return true;}
                else{return false;}
            }
            else {return false;}
            }
        else{
            if (checkBST(root->left) && checkBST(root->right)){
                if (root->left->data <= root->data && root->data <= root->right->data ){
                    if (check_two_Leaf_branch(root->left)){
                        if(root->left->right->data < root->data){
                            return true;
                        }
                        else {return false;}
                    }
                    else{return true;}
                    if (check_two_Leaf_branch(root->right)){
                        if(root->right->left->data > root->data){
                            return true;
                        }
                        else {return false;}
                    }
                    else{return true;}

                }
                else{return false;}
            }
            else {return false;}
        }
                     }