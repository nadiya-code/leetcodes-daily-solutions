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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next ||!head->next->next){
            return {-1,-1};
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        int index=1;
        int first=-1;
        int last=-1;
        int minidis=INT_MAX;
        while(curr->next){
            if((prev->val<curr->val && curr->val>curr->next->val)||(prev->val>curr->val && curr->val<curr->next->val)){
                if(first==-1){
                    first=index;
                }
                else{
                    minidis=min(minidis,index-last);
                }
                last=index;
            }
            prev=prev->next;
            curr=curr->next;
            index++;
        }
        if(first==last){
            return {-1,-1};
        }
        int maxidis=last-first;
        return {minidis,maxidis};
    }
};