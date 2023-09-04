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
    int D=0;
    int height(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        int currD = lh + rh; //current diameter
        
        D = max(D,currD);    // max diameter

        return max(lh,rh)+1;   // max height
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return D;    // max diameter
    }
};