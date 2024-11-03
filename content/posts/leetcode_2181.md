
+++
authors = ["Crafted by Me"]
title = "Leetcode 2181: Merge Nodes in Between Zeros"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2181: Merge Nodes in Between Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---
{{< youtube jrSav7fulJY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2182: Construct String With Repeat Limit](https://grid47.xyz/posts/leetcode_2182) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

