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

    ListNode* getkthNode(ListNode*temp , int k){
        k--;
        while(temp!=nullptr && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *groupPrev = &dummy;
        while(true){
            ListNode* kth = getkthNode(groupPrev->next,k);
            if(kth==nullptr){
                break;
            }
            ListNode*groupNext = kth->next;
            kth->next = nullptr;

            ListNode* groupStart = groupPrev->next;
            ListNode* newHead = reverse(groupStart);
            groupPrev->next =newHead;
            groupStart->next = groupNext;
            groupPrev = groupStart;
        }
        
        return dummy.next;
    }
};