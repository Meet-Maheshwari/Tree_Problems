#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

bool validateBST(Node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->val < min) {
        return false;
    }
    if(max != NULL && root->val > max){
        return false;
    }

    bool left = validateBST(root->left, min, root->val);
    bool right = validateBST(root->right, root->val, max);

    return left && right;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        return new Node(data);   
    }

    if(data < root->val) {
        root->left = insert(root->left, data);
    }

    if(data > root->val) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* buildBST(vector<int> arr, int n) {
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root; // Non Void function doees not return anything
}

static int idx = -1;
Node* buildBinaryTree(vector<int> arr) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildBinaryTree(arr);
    root->right = buildBinaryTree(arr);

    return root;
}

void inorderTravel(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTravel(root->left);
    cout << root->val << " ";
    inorderTravel(root->right);
}

int main() {
    vector<int> arr1 = {10, 6, 12, 5, 8, 14};
    int n = arr1.size();

    Node* root1 = buildBST(arr1, n);
    cout << root1->val << endl;

    vector<int> arr2 = {10, 6, 9, -1, -1, 8, -1, -1, 12, -1, 14, -1, -1};
    Node* root2 = buildBinaryTree(arr2);
    inorderTravel(root2);
    cout << endl;
    cout << validateBST(root1, NULL, NULL) << endl;
    cout << validateBST(root2, NULL, NULL) << endl;
}