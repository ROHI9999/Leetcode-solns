class Solution {
    public:
    
    bool isbalanced = true;
    int height(TreeNode* root){
        //base case
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);


    // if isbalanced is true and diff > 1 then is balanced is false....
        if(isbalanced && abs(left - right)>1){ 
            isbalanced=false;
        }
        //max depth
        return max(left,right) +1;

    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }    
        height(root);
        return isbalanced;      
    }
};