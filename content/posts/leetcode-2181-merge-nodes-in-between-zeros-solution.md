
+++
authors = ["grid47"]
title = "Leetcode 2181: Merge Nodes in Between Zeros"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2181: Merge Nodes in Between Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-nodes-in-between-zeros/description/)

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
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next) return nullptr;

        ListNode* ptr = head->next;
        int sum = 0;
        while(ptr->val!=0) sum += ptr->val, ptr = ptr->next;
        head->next->val = sum;
        head->next->next= mergeNodes(ptr);
        return head->next;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2181.md" >}}
---
{{< youtube jrSav7fulJY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2182: Construct String With Repeat Limit](https://grid47.xyz/posts/leetcode-2182-construct-string-with-repeat-limit-solution/) |
| --- |
