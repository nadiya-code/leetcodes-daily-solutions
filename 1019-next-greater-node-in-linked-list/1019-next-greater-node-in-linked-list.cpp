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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nodes;
        stack<ListNode*>st;
        while(head){
            ListNode*curr=head->next;
            while(curr && head->val>=curr->val){
                curr=curr->next;
            }
            if(curr){
                nodes.push_back(curr->val);
            }
            else{
                nodes.push_back(0);
            }
            head=head->next;
        }
        return nodes;
    }
};