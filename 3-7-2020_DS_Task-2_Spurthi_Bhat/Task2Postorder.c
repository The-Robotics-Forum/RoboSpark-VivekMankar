#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node *left;
struct Node *right;
int leaf;
}Node;
Node* newNode(int data)
{
     Node* node = (Node*)malloc(sizeof(Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     node->leaf=1;

     return(node);
}
Node* insert_bst(Node* root, int data) {
    // Inserts data into it's appropriate position in the BST
    if (!root) {
        root = newNode(data);
        return root;
    }
    else {
        Node* node = newNode(data);
        Node* temp = root;
        while (temp) {
            if (temp->leaf) {
                if (temp->data > data) {
                    temp->left = node;
                    temp->leaf = 0;
                    break;
                }
                else {
                    temp->right = node;
                    temp->leaf = 0;
                    break;
                }
            }
            else {
                 if (temp->data > data) {
                     if (temp->left == NULL) {
                        temp->left = node;
                        break;
                    }
                    temp = temp->left;
                }
                else {
                    if (temp->right == NULL) {
                        temp->right = node;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }
    return root;
}

int search_bst(Node* root, int target) {
    // Searches for target in the BST
    if (!root)
        return 0;
    if (root->data == target)
        return 1;
    else if (root->data > target)
        return search_bst(root->left, target);
    else
        return search_bst(root->right, target);
    return 0;
}
void print_search(Node* root, int target) {
    if (search_bst(root, target) == 1) {
        printf("\nValue: %d found in the BST!\n", target);
    }
    else {
        printf("\nValue: %d is not found in the BST.\n", target);
    }
}
void postorder(Node* node)
{
     if (node == NULL)
        return;

     postorder(node->left);

     postorder(node->right);

     printf("%d ", node->data);
}
int main()
{
     Node *root  = newNode(1);
    root = insert_bst(root, 20);
    root = insert_bst(root, 15);
    root = insert_bst(root, 60);
    root = insert_bst(root, 40);
    root = insert_bst(root, 50);
    root = insert_bst(root, 70);

     printf("\nPostorder traversal of binary tree is \n");
     postorder(root);

    print_search(root, 20);
    print_search(root, 40);
    print_search(root, 35);

     return 0;
}



