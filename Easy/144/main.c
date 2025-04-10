#include <stdlib.h> 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void size(struct TreeNode* root, int *length){
    if(root == NULL){
        return;
    }

    (*length)++;

    size(root->left , length);
    size(root->right , length);
}

void traverse(struct TreeNode* root, int *arr, int *idx){
    if(root == NULL){
        return;
    }

    arr[(*idx)++] = root->val;

    traverse(root->left , arr, idx);
    traverse(root->right , arr, idx);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    size(root, returnSize);
    int *arr = malloc(sizeof(int)**returnSize);

    *returnSize = 0;
    traverse(root, arr, returnSize);

    return arr;
}