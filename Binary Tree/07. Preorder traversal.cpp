/*
    Find preorder traversal of binary tree (root-left-right)
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 1,2,4,3,5,7,8,6                                             1
                                                                                 /     \
    Time Complexity: O(n)                                                       2       3
    Space Complexity: O(n)                                                     /      /   \
                                                                              4      5     6
                                                                                    / \
                                                                                   7   8
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

//  ********** Recursive Approach ********** //
void preorder(TreeNode* root)
{
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

//  ********** Iterative Approach *********** //
void preorder(Node* root)
{
    if (root == nullptr)
        return;

    stack<Node *> stack;      // create an empty stack and push the root node
    stack.push(root);

    // loop till stack is empty
    while (!stack.empty()) {
        Node *curr = stack.top();     // pop a node from the stack and print it
        stack.pop();
        cout << curr->val << " ";

        if (curr->right)             // push the right child of the popped node into the stack
            stack.push(curr->right);

        if (curr->left)             // push the left child of the popped node into the stack
            stack.push(curr->left);

        // the right child is pushed first so that the left child is processed first (LIFO order)
    }
}

/***** This can be optimized by pushing only the right children to the stack *****/
void preorder(Node* root)
{
    if (root == nullptr) 
        return;
 
    stack<Node*> stack;
    stack.push(root);
    Node* curr = root;     // start from the root node
 
    while (!stack.empty()) {
        // if the current node exists, print it and push its right child to the stack before moving to its left child
        if (curr != nullptr) {
            cout << curr->val << " ";
 
            if (curr->right) 
                stack.push(curr->right);
 
            curr = curr->left;
        }
        // if the current node is null, pop a node from the stack & set the current node to the popped node
        else {
            curr = stack.top();
            stack.pop();
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    preorder(root);
    cout << endl;
    return 0;
}
