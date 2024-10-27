
+++
authors = ["Yasir"]
title = "Leetcode 142: Linked List Cycle II"
date = "2024-06-08"
description = "Solution to Leetcode 142"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-cycle-ii/description/)

---

**Code:**

{{< highlight html >}}
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
        if(head == NULL) return NULL;
        ListNode *fast = head, *slow= head;
        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!(fast && fast->next)) return NULL;
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
{{< /highlight >}}

