/*
    Given a binary tree, find if it is height balanced or not. 
    A tree is balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
    Example:    Input: 1, 2, 3, -1, 5, 4, 6, 5, -1, -1, -1, -1, -1, 7            // -1 means no node
                Output: 1                                                             1
                                                                                   /     \
                Time Complexity: O(n)                                             2       3
                Space Complexity: O(n)                                             \     / \
                                                                                    5   4   6
                                                                                             \
                                                                                              7
*/

#include <bits/stdc++.h>
using namespace std;
 
struct Node 
{
    int val;
    struct Node* left;
    struct Node* right;
 
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(vector<int> &arr)
{
    if(arr.size() == 0 || arr[0] == -1)
        return NULL;
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int index = 1;
    while (!q.empty()) {
        Node *front = q.front();
        q.pop();
        if (arr[index] != -1) {
            front->left = new Node(arr[index]);
            q.push(front->left);
        }
        index++;
        if (index == arr.size())
            break;
        if (arr[index] != -1) {
            front->right = new Node(arr[index]);
            q.push(front->right);
        }
        index++;
        if (index == arr.size())
            break;
    }
    return root;
}

int height(Node* root)
{
    if(!root)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

bool isBalanced(Node* root)
{
    if(!root)
        return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    cout << isBalanced(root) << "\n";
    return 0;
}