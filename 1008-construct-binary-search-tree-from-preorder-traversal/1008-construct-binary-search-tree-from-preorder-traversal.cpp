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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        stack<TreeNode*>st;
        TreeNode* root= new TreeNode(preorder[0]);
        st.push(root);
        TreeNode* ans=root;
        int n=preorder.size();
        for(int i=1;i<n;i++){
            TreeNode* node=new TreeNode(preorder[i]);
            if(preorder[i]<st.top()->val){
                st.top()->left=node;
                st.push(node);
            }
            else{
                TreeNode* parent=NULL;
                while(!st.empty() && preorder[i]>st.top()->val){
                    parent=st.top();
                    st.pop();
                }
                parent->right=node;
                st.push(node);
            }
        }
        return ans;
    }
};