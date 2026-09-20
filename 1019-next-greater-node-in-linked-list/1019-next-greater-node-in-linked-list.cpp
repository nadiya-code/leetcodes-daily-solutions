/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reversed(ListNode* head){
        ListNode* reversed=NULL;
        while(head){
            ListNode* Node=head->next;
            head->next=reversed;
            reversed=head;
            head=Node;
        }
        return reversed;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nodes;
        stack<ListNode*>st;
        ListNode* dummy=reversed(head);
        while(dummy){
            while(!st.empty()&&st.top()->val<=dummy->val){
                st.pop();
            }
            if(!st.empty()){
                nodes.push_back(st.top()->val);
            }
            else{
                nodes.push_back(0);
            }
            st.push(dummy);
            dummy=dummy->next;
        }
        reverse(nodes.begin(),nodes.end());
        return nodes;
    }
};