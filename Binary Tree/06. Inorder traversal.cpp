/*
    Find inorder traversal of binary tree (left-root-right)
    Example:    Input: 1, 2, 3, 4, -1, 5, 6, -1, -1, 7, 8                 // -1 means no node
                Output: 4,2,1,7,5,8,3,6                                             1
                                                                                 /     \
    Time Complexity: O(n)                                                       2       3
    Space Complexity: O(n)                                                     /      /   \
                                                                              4      5     6
                                                                                    /  \
                                                                                   7    8
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
void inorder(TreeNode* root)
{
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

//  ** Iterative Approach ** //
void inorder(Node* root)
{
    stack<Node*> stack;
    Node* curr = root;  // start from the root node (set current node to the root node)
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr) {
        // if the current node exists, push it into the stack (defer it) and move to its left child
        if (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // if the current node is null, pop an element from the stack, print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, -1, 4, 6, -1, 5, -1, -1, 7, -1};        // -1 denotes NULL node
    Node *root = buildTree(arr);
    inorder(root);
    cout << endl;
    return 0;
}
