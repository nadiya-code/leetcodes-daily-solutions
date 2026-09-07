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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            int size=st.size();
            for(int i=0;i<size;i++){
                TreeNode* node=st.top();
                st.pop();
                pq.push(node->val);
                if(node->right!=NULL)st.push(node->right);
                if(node->left!=NULL)st.push(node->left);
            }
        }
        TreeNode* order=new TreeNode(pq.top());
        TreeNode* ans=order;
        pq.pop();
        while(!pq.empty()){
            order->right=new TreeNode(pq.top());
            pq.pop();
            order=order->right;
        }
        return ans;
    }
};