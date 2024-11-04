
+++
authors = ["Crafted by Me"]
title = "Leetcode 445: Add Two Numbers II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 445: Add Two Numbers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Linked List","Stack","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers-ii/description/)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int cry = 0;
        
        ListNode* node = NULL, *prv = NULL;
        
        while(!s1.empty() || !s2.empty()) {
            
            if(!s1.empty()) {
                cry += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                cry += s2.top();
                s2.pop();
            }
            
            node = new ListNode(cry % 10);
            node->next = prv;
            
            prv = node;
            cry /= 10;
            
        }
        
        if(cry != 0) {
            node = new ListNode(cry %10);
            node->next = prv;
            
        }
        
        return node;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/445.md" >}}
---
{{< youtube ovGnWmf2sew >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #446: Arithmetic Slices II - Subsequence](https://grid47.xyz/posts/leetcode_446) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

