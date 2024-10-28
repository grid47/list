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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* res = head;
        
        while(head && head->next) {
            ListNode* node = new ListNode(__gcd(head->val, head->next->val));
            ListNode* tmp = head->next;
            head->next = node;
            node->next = tmp;
            head = tmp;
        }
        return res;
    }
};