#include <gtest/gtest.h>
#include <iostream>
#include "bst.h"
using namespace std;

const int n = 5;
int count = 0;

int a[n] = {3,1,2,5,4};

bstNode *root = constructBST(a,n);
bstNode *node;

TEST(testP1,case1){

    EXPECT_EQ(root->data, 3);
    node = root->left;
    EXPECT_EQ(node->data,1);
    node = node->right;
    EXPECT_EQ(node->data,2);
    node = root->right;
    EXPECT_EQ(node->data,5);
    node = node->left;
    EXPECT_EQ(node->data,4);
}

TEST(testP1,case2){
    EXPECT_EQ(countLeaves(root), 2);
}

TEST(testP1,case3){
    EXPECT_EQ(countParentsWithTwoChildren(root),1);
}

TEST(testP1,case4){
    EXPECT_EQ(height(root), 2);
}

TEST(testP1,case5){
    bool compareResult = false;
    pair<int, int> twoSumPair = twoSum(root, 3);
    if ((twoSumPair.first==1 && twoSumPair.second==2) \
        || (twoSumPair.first==2 && twoSumPair.second==1)){
        compareResult = true;
    }
    EXPECT_TRUE(compareResult);
}

TEST(testP1,case6){
    vector<int> output;
    int correctOutput[5] = {3, 1, 2, 5, 4};
    printBSTPreOrder(root, output);
    for(size_t i=0; i < output.size(); i++){
        cout << output[i] << " ";
        EXPECT_EQ(output[i], correctOutput[i]);
    }
}

TEST(testP1,case7){
    invertBST(root);
    vector<int> output;
    int correctOutput[5] = {3, 5, 4, 1, 2};
    printBSTPreOrder(root, output);
    for(size_t i=0; i < output.size(); i++){
        // cout << output[i] << " ";
        EXPECT_EQ(output[i], correctOutput[i]);
    }
}


int const s = 8;
int b[s] = {5,3,2,1,4,7,6,8};

bstNode* r = constructBST(b, s);

TEST(testP1,case8){
    EXPECT_EQ(countParentsWithTwoChildren(r),3);
}