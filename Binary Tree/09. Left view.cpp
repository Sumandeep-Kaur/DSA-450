/*
    Given a Binary Tree, print Left view of it. Left view of a binary tree is set of nodes visible when tree is visited from left side.
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 1, 2, 4, 7                                                  1
                                                                                 /     \
    Time Complexity: O(n)                                                       2        3
    Space Complexity: O(height)                                                /       /   \
                                                                              4       5     6
                                                                                    /   \
                                                                                   7     8
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

/* The left view contains all nodes that are first nodes in their levels, so idea is to do level order traversal and print the first node in every level.*/
vector<int> leftView(Node *root)
{
    if(!root)
        return {};
    vector<int> left;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            if(i == 0)
                left.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return left;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    vector<int> left = leftView(root);
    for(int i = 0; i < left.size(); i++)
        cout << left[i] << " ";
    cout << endl;
    return 0;
}
