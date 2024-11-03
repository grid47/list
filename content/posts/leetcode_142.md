
+++
authors = ["Crafted by Me"]
title = "Leetcode 142: Linked List Cycle II"
date = "2024-06-13"
description = "In-depth solution and explanation for Leetcode 142: Linked List Cycle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube Yn5xqbK95Uw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #143: Reorder List](https://grid47.xyz/posts/leetcode_143) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

