
+++
authors = ["grid47"]
title = "Leetcode 2816: Double a Number Represented as a Linked List"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2816: Double a Number Represented as a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "UmqNCKUeIy4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/)

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
    int pin(ListNode* head) {
        if(head == NULL) return 0;
        int val = pin(head->next);
        int num = head->val;
        num = num * 2 + val;
        head->val = num % 10;
        return num/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int num = pin(head);
        while(num > 0) {
            int c = num % 10;
            num /= 10;
            ListNode* node = new ListNode(c);
            node->next = head;
            head = node;
        }
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2816.md" >}}
---
{{< youtube UmqNCKUeIy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2817: Minimum Absolute Difference Between Elements With Constraint](https://grid47.xyz/leetcode/solution-2817-minimum-absolute-difference-between-elements-with-constraint/) |
| --- |
