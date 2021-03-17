#ifndef BST_H
#define BST_H


#include<stdlib.h>
#include <utility> 
#include <vector>
using namespace std;

typedef struct node{
    int data;
    struct node *left,*right;
}bstNode;

bstNode *constructBST(int inputArray[],int n);
int countLeaves(bstNode *root);
int countParentsWithTwoChildren(bstNode *root);
int height(bstNode *root);
void invertBST(bstNode *root);
void printBSTPreOrder(bstNode *root, vector<int>& output);
pair<int, int> twoSum(bstNode* root, int sum);

#endif