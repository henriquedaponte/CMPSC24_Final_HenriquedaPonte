#include<iostream>
#include <set>
#include <list>
#include "bst.h"
using namespace std;


// ConstructBST Helper
node* insertBST(node* root, int val){
    if(!root){
        root = new node;
        root->data = val;
        root->right = NULL;
        root->left = NULL;
        return root;
    }else{
        if(val < root->data){
            root->left = insertBST(root->left, val);
        }else{
            root->right = insertBST(root->right, val);
        }
    }
    return root;
}

bstNode *constructBST(int inputArray[],int n){

   node* root = new node;
   root->data = inputArray[0];
   root->right = NULL;
   root->left = NULL;
   
   for(int i = 1; i < n; i++){
       insertBST(root, inputArray[i]);
   }

    return root;
}

int countLeaves(bstNode *root){
    int count = 0;

    if(root){
        if(!root->left && !root->right){
            count ++;
            return count;
        }else{
            return countLeaves(root->left) + countLeaves(root->right);
        }
    }else{return 0;}

    return count;
}

int countParentsWithTwoChildren(bstNode *root){
    int count = 0;
    if(root){
        if(root->left && root->right){
            count ++;
            count += countParentsWithTwoChildren(root->left) + countParentsWithTwoChildren(root->right);
            return count;
        }else{
            return 0;
        }
    }else{return 0;}

    return count;
}

int height(bstNode *root){
    if(root){
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if(lHeight > rHeight){
            return lHeight + 1;
        }else{
            return rHeight + 1;
        }

    }else{
        return -1;
    }

}

void invertBST(bstNode *root){
    if(root){
        invertBST(root->left);
        invertBST(root->right);
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }else return;
} 

void printBSTPreOrder(bstNode *root, vector<int>& output){
    if(!root){
            return;
        }

        cout << root->data << endl;
        printBSTPreOrder(root->left, output);
        printBSTPreOrder(root->right, output);
} 

int countNodes(node* r){
    int c = 0;
    if(r){
        c++;
        c += (countNodes(r->left) + countNodes(r->right));
        return c;
    }
    return 0; 
    
}

void bstToArr(node* root, int array[]){

    static int index = 0;

    if(root){

        array[index++] = root->data;
        bstToArr(root->left, array);
        bstToArr(root->right, array);

    }else{
        return;
    }
}

pair<int, int> twoSum(bstNode* root, int sum) {

    // Size of Array
    int const size = countNodes(root);

    // Create Array
    int* arr;
    arr = new int[size];

    // Store BST with root "root" into our newly created Array "arr"
    bstToArr(root, arr);

    //  Iterate through and compare every element in array to find  the combination that the sum is equal to "sum"
    // return both elements
    if(root){
        for(int i = 0; i < size; i++){
            for(int j = size-1; j >= 0; j--){
                if( (sum - arr[i] == arr[j]) && (arr[j] != 0) ){
                    int a = arr[i];
                    int b = arr[j];
                    return {a,b};
                }
            }
        }
    }else{
        return {-1,-1};
    }

}
