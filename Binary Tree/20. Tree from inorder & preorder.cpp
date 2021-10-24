/*
    Construct a binary tree from inorder and preorder traversal and print the Postorder traversal.
    Example:    Input: inorder[] = {3 1 4 0 5 2}    preorder[] = {0 1 3 4 2 5}
                Output: 3, 4, 1, 5, 2, 0                                              0
                                                                                   /     \
                Time Complexity: O(n*n)                                           1       2
                Space Complexity: O(n)                                           / \     / 
                                                                                3   4   5   
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

Node *build(vector<int> in, vector<int> pre, int inStart, int inEnd, int preIdx)
{
    if (preIndex >= pre.size() || inStart > inEnd)
        return NULL;
    Node *root = new Node(pre[preIdx]);
    int inIdx = inStart;
    for (; inIdx <= inEnd; inIdx++) {
        if (in[inIdx] == pre[preIdx])
            break;
    }

    root->left = build(in, pre, inStart, inIdx - 1, preIdx + 1);
    root->right = build(in, pre, inIdx + 1, inEnd, preIdx + 1 + inIdx - inStart);

    return root;
}

Node *buildTree(vector<int> in, vector<int> pre)
{
    return build(in, pre, 0, in.size() - 1, 0);
}

int main()
{
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    vector<int> postorder = buildTree(inorder, preorder);
    for(int val : postorder)
        cout << val << " ";
    cout << endl;
    return 0;
}