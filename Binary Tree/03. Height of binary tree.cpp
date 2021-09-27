/*
    Find height of binary tree i.e, number of levels.
    Example:    Input: 1, 2, 3, -1, 5, 4, 6, 5, -1, -1, -1, -1, -1, 7            // -1 means no node
                Output: 4                                                             1
                                                                                   /     \
                Time Complexity: O(n)                                             2       3
                Space Complexity: O(n)                                             \     / \
                                                                                     5  4   6
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
//Iterative
int height(Node *root)
{
    if (!root)
        return 0;
    int height = 0;
    queue<Node *> q;
    q.push(root);
    Node *node;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        height++;
    }
    return height;
}
//Recursive
int height(Node* root)
{
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    cout << height(root) << "\n";
    return 0;
}