/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*curr = head;
        ListNode*temp = head;
        
        while(temp!=nullptr && temp->next!=nullptr){
            curr = curr->next;
            temp = temp->next->next;

            if(curr == temp){
                curr = head;
                while(curr!=temp){
                    curr = curr ->next;
                    temp = temp->next;
                }
                if(curr == temp){
                    return curr;
                }    

            }
        }
        return nullptr;
    }
};