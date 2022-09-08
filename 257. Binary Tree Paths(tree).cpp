/******************************************************************************
257. Binary Tree Paths

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
*******************************************************************************/
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
     void func(TreeNode*&root,vector<string>&ans,string s){
        if(!root) return;
        s+=to_string(root->val);
        s+="->";
        
        if(!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
        }
        func(root->left,ans,s);
        func(root->right,ans,s);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string>ans;
        string s;
        func(root,ans,s);
        return ans;
    }
};