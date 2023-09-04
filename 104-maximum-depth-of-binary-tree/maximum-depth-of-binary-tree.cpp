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
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0;
        }

        //left part max no. of nodes
        int leftHeight = maxDepth(root->left);

        //right part max no. of nodes
        int rightHeight = maxDepth(root->right);

        //return max no. of nodes
        int ans = max(leftHeight,rightHeight) + 1;   // +1 for considering root node to find max.
        return ans;
    }
};