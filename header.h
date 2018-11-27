//
// Created by crbaniak on 11/24/18.
//

#ifndef BANC3_HEADER_H
#define BANC3_HEADER_H

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

//struct node* newNode(int item);

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct node* search(struct node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) {
        printf("%d\n", root->key);
        return root;
    }

    // Key is greater than root's key
    if (root->key < key) {
        printf("%d\n", root->key);
        return search(root->right, key);
    }

    // Key is smaller than root's key
    printf("%d\n", root->key);
    return search(root->left, key);
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
#endif //BANC3_HEADER_H
