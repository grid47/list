
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2181: Merge Nodes in Between Zeros"
date = "2018-11-11"
description = "Solution to Leetcode 2181"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

