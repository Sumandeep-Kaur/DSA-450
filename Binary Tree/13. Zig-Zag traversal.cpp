/*
    Given a Binary Tree, Find the Zig-Zag Level Order Traversal of the Binary Tree.
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 1, 3, 2, 4, 5, 6, 8, 7                                      1
                                                                                 /     \
    Time Complexity: O(n)                                                       2        3
    Space Complexity: O(n)                                                     /       /   \
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

/* Output as vector of vectors
vector<vector<int>> zigzag(Node *root)
{
    if (!root)
        return {};
    queue<Node *> q;
    vector<vector<int>> v;
    q.push(root);
    Node *node;
    while (!q.empty()) {
        int len = q.size();
        vector<int> temp;
        for (int i = 0; i < len; i++) {
            node = q.front();
            q.pop();
            temp.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (v.size() % 2 != 0)
            reverse(temp.begin(), temp.end());
        v.push_back(temp);
    }
    return v;
}
*/

// Using stack (single vector output)
vector<int> zizagtraversal(Node* root)
{
    if (!root)
        return {};

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    vector<int> v;

    currentLevel.push(root);
    bool leftToRight = true;
    while (!currentLevel.empty()) {
        Node* temp = currentLevel.top();
        currentLevel.pop();
        v.push_back(temp->data);
        if (leftToRight) {
            if (temp->left)
                nextLevel.push(temp->left);
            if (temp->right)
                nextLevel.push(temp->right);
        }
        else {
            if (temp->right)
                nextLevel.push(temp->right);
            if (temp->left)
                nextLevel.push(temp->left);
        }
        if (currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    vector<int> res = zigZag(root);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
