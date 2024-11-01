
+++
authors = ["Crafted by Me"]
title = "Leetcode 142: Linked List Cycle II"
date = "2024-06-13"
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

{{< highlight cpp >}}
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/142.md" >}}
- by gpt
        
---
{{< youtube Yn5xqbK95Uw >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

