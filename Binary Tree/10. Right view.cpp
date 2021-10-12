/*
    Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 1, 3, 6, 8                                                  1
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

/* The right view contains all nodes that are last nodes in their levels, so idea is to do reverse level order traversal and print the first node in every level.*/
vector<int> rightView(Node *root)
{
    if (!root)
        return {};
    vector<int> right;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
                right.push_back(temp->data);
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    return right;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    vector<int> right = rightView(root);
    for(int i = 0; i < right.size(); i++)
        cout << right[i] << " ";
    cout << endl;
    return 0;
}
