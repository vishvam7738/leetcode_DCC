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
class FindElements {
public:
    TreeNode* curr;
    FindElements(TreeNode* root) {
        curr=root;
    }
    bool findVal(TreeNode*root,int val,int x){
        if(!root)return false;
        if(val==0)return true;
        root->val=x;
        if(root->val==val)return true;       
        return findVal(root->left,val,(2*root->val)+1)||  findVal(root->right,val,(2*root->val)+2);
    }
    
    bool find(int target) {
        return findVal(curr,target,0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
