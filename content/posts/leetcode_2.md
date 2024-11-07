
+++
authors = ["Crafted by Me"]
title = "Leetcode 2: Add Two Numbers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2: Add Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int rm = 0;

        while (l1 != NULL || l2 != NULL || rm != 0) {
            int no1 = (l1 != NULL) ? l1->val : 0;
            int no2 = (l2 != NULL) ? l2->val : 0;

            int sum = no1 + no2 + rm;
            int digit = sum % 10;
            rm = sum / 10;

            ListNode* nxt = new ListNode(digit);
            tail->next = nxt;
            tail = tail->next;

            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }

        ListNode* res = head->next;
        delete head;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2.md" >}}
---
{{< youtube wgFPrzTjm7s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3: Longest Substring Without Repeating Characters](https://grid47.xyz/posts/leetcode_3) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
