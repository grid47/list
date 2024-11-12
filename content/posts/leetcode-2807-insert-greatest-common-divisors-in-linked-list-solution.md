
+++
authors = ["grid47"]
title = "Leetcode 2807: Insert Greatest Common Divisors in Linked List"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2807: Insert Greatest Common Divisors in Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/)

---
**Code:**

{{< highlight cpp >}}
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
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2807.md" >}}
---
{{< youtube SVnSiD95r-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2808: Minimum Seconds to Equalize a Circular Array](https://grid47.xyz/posts/leetcode-2808-minimum-seconds-to-equalize-a-circular-array-solution/) |
| --- |
