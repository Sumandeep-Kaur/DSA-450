/*
    Find reverse level order traversal of binary tree i.e, the traversal must begin from the last level.
    Example:    Input: 1, 2, 3, -1, 5, 4, 6, 5, -1, -1, -1, -1, -1, 7            // -1 means no node
                Output: 7 5 4 6 2 3 1                                                 1
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

vector<int> reverseLevelOrder(Node *root)
{
    if(!root)
        return {};
    vector<int> v;
    queue<Node*> q;
    Node* node;
    q.push(root);
    while(!q.empty()){
        node = q.front();
        q.pop();
        v.push_back(node->val);
        if(node->right)
            q.push(node->right);
        if(node->left)
            q.push(node->left);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    vector<int> v = reverseLevelOrder(root);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}