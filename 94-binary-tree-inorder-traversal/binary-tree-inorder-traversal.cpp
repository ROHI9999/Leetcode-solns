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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       TreeNode* curr = root;
       while(curr){
           //left node is null then print and move to right node
           if(curr->left == nullptr){
            ans.push_back(curr->val);
            curr = curr->right;
           }

           //left node is not null
           else{
               //find predecessor
               TreeNode* pred = curr->left;
               while(pred->right != curr && pred->right){
                   pred= pred->right;
               }
               //if pred right is null then link pred and curr node
               if(pred->right == nullptr){
                   pred->right = curr;
                   curr = curr->left;
               }

               else{
                   //remove the connection between pred node and curr node,otherwise time limit exceed
                   pred->right = nullptr;
                   ans.push_back(curr->val); // print curr node and move right
                   curr = curr->right;
               }
           }
       }
       return ans;
    }
};