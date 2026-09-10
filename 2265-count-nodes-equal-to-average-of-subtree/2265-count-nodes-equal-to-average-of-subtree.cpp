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
    int count=0;
    bool averageOfSub(TreeNode*root){
        int val=root->val;
        int l=0;
        stack<TreeNode*>st;
        st.push(root);
        int sum=0;
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            if(node->right!=NULL)st.push(node->right);
            if(node->left!=NULL)st.push(node->left);
            sum+=node->val;
            l++;
        }
        if(sum/l==val){
            return true;
        }
        return false;
    }
    int averageOfSubtree(TreeNode* root) {
        if(averageOfSub(root)){
            count++;
        }
        if(root->left!=NULL)averageOfSubtree(root->left);
        if(root->right!=NULL)averageOfSubtree(root->right);
        return count;
    }
};
