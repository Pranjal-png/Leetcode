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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Put the first node of every list into the heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(!pq.empty()) {

            // Smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Attach it to answer
            temp->next = node;
            temp = temp->next;

            // Push the next node from the same list
            if(node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return ans->next;
    }
};