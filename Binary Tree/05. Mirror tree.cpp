/*
    Given the root of a binary tree, invert the tree i.e., find mirror image of the binary tree.
    Example:    Input: 1, 2, 3, 4, 5             
                Output: 1, 3, 2, -1, -1, 5, 4                                         1                   1
                                                                                    /   \               /   \
                Time Complexity: O(n)                                              2     3      =>     3     2
                Space Complexity: O(n)                                           /   \                      /  \
                                                                                4     5                    5    4
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

/*The inverse of an empty tree is the empty tree. 
The inverse of a tree with root r and subtrees right and left is a tree with root r, whose right subtree is the inverse of left, and left subtree is the inverse of right.*/
Node* mirrorTree(Node* root)
{
    if (root == null)
        return null;
    Node* right = mirrorTree(root->right);
    Node* left = mirrorTree(root->left);
    root->left = right;
    root->right = left;
    return root;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1}; // -1 denotes NULL node
    Node *root = buildTree(arr);
    return 0;
}
