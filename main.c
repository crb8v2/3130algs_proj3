
#include "header.h"

struct node initTree(struct node*);
void inorder(struct node*);
void postorder(struct node*);
void preorder(struct node*);

// Driver Program to test above functions
int main()
{
    int array[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
//    int userChoice, exitFlag = 0;
//    int value;


    // init the tree
    struct node *root = NULL;
    root = insert(root, array[0]);
    for(int ii = 1; ii < 10; ii++){
        insert(root, array[ii]);
    }

    while(1) {
        initTree(root);
    }
}

struct node initTree(struct node *root){

    int userChoice;
    int value;
    int exitFlag = 0;

    printf("\n###############################\n");
    printf("##### BINARY SEARCH TREES #####\n");
    printf("###############################\n\n");
    printf("##### Menu #####\n");
    printf("*enter a digit*\n\n");
    printf("1. Insert a value into the tree.\n");
    printf("2. Search for a value into the tree.\n");
    printf("3. Delete a value from the tree.\n");
    printf("4. Display inorder\n");
    printf("5. Display postorder\n");
    printf("6. Display preorder\n");
    printf("0. Exit program\n\n");
    printf("==>\n");

    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1:
            printf("\nValue to insert:\n");
            scanf("%d", &value);
            insert(root, value);
            break;

        case 2:
            printf("\nValue to search for:\n");
            scanf("%d", &value);
            search(root, value);
            break;

        case 3:
            printf("\ndelete\n");
            printf("\nValue to delete:\n");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;

        case 4:
            printf("\n\n INORDER:  ");
            inorder(root);
            printf("\n\n");
            break;

        case 5:
            printf("\n\n POSTORDER:  ");
            postorder(root);
            printf("\n\n");
            break;

        case 6:
            printf("\n\n PREORDER:  ");
            preorder(root);
            printf("\n\n");
            break;

        case 0:
            printf("\nTerminated\n");
            exit(0);
    }


}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// A utility function to do inorder traversal of BST
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// A utility function to do inorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


