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
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* node=st.top();
        st.pop();
        if(node->right!=NULL)st.push(node->right);
        if(node->left!=NULL)st.push(node->left);
        while(!st.empty()){
            int size=st.size();
            for(int i=0;i<size;i++){
                root->left=NULL;
                root->right=st.top();
                root=root->right;
                TreeNode* node=st.top();
                st.pop();
                if(node->right!=NULL)st.push(node->right);
                if(node->left!=NULL)st.push(node->left);
            }
        }
    }
};