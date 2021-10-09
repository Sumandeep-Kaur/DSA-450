/*
    Find postorder traversal of binary tree (left-right-right)
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 4,2,7,8,5,6,3,1                                             1
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

//  ** Recursive Approach ** //
void postorder(TreeNode* root)
{
    if (root) {
        inorder(root->left);
        inorder(root->right);
        cout << root->val << " ";
    }
}

//  ** Iterative Approach ** //
void postorder(Node* root)
{
    stack<Node*> stack;
    stack.push(root);
    stack<int> ans;   // create another stack to store postorder traversal
 
    while (!stack.empty()) {
        // pop a node from the stack and push the data into the output stack
        Node* curr = stack.top();
        stack.pop();
 
        ans.push(curr->val);
 
        if (curr->left) 
            s.push(curr->left);
 
        if (curr->right) 
            s.push(curr->right);
    }
 
    // print postorder traversal
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    postorder(root);
    cout << endl;
    return 0;
}
