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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = nullptr, *n2 = nullptr;
        for(ListNode *p = head; p != nullptr; p = p->next) {
            n2 = n2 == nullptr? nullptr: n2->next;
            if(--k == 0) {
                n1 = p;
                n2 = head;
            }
        }
        swap(n2->val, n1->val);
        return head;
    }
};