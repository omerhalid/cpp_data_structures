
//COME BACK TO THIS PROBLEM LATER

//Problem statement link: https://leetcode.com/problems/binary-tree-inorder-traversal/

//Tree is not a linear data structure, so we can't traverse it in a linear way.
//we can have more than one possible directions to traverse the tree.

//Tree traversal: visiting each node in the tree exactly once.

//BFS: breadth first search: level order traversal
//DFS: depth first search: preorder, inorder, postorder traversal

//Preorder traversal: root, left, right
//Inorder traversal: left, root, right (gives sorted order for BST)
//Postorder traversal: left, right, root

//Level-order implementation using queue:
//Time complexity: O(n)
//Space complexity: O(n)

//Space complexity means the extra space used by the algorithm, not including the space taken up by the inputs.
//Time complexity means the number of operations the algorithm performs on the inputs.

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val; 
    TreeNode *left;
    TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        queue<TreeNode*> Q;
        vector<vector<int>> result;

        Q.push(root);

        while(!Q.empty())
        {
            int levelSize = Q.size();
            vector<int> currentLevel;

            for(int i=0; i<levelSize; i++){
                TreeNode* current = Q.front();
                Q.pop();

                if(current -> left != nullptr){ // <-- Corrected this line
                    Q.push(current->left);
                }
                
                if(current -> right != nullptr){
                    Q.push(current->right);
                }
                
                currentLevel.push_back(current->val);
            }
            result.push_back(currentLevel); // <-- Added this line
        }
        return result;
    }
};