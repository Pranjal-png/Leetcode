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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next== nullptr ||k==0){
            return head;
        }
        int n = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            n++;
            temp = temp->next;
        }
        k = k%n;
        ListNode*curr = head;
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = head;
        ListNode*tempp = head;
        for(int i=0 ; i<n-k-1 ; i++){
            tempp = tempp->next;
        }
        ListNode* newhead = tempp->next;
        tempp->next = nullptr;
        return newhead;
    }
};