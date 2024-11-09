
+++
authors = ["grid47"]
title = "Leetcode 24: Swap Nodes in Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 24: Swap Nodes in Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swap-nodes-in-pairs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.jpeg" 
    alt="Two floating nodes gently exchanging places, glowing with subtle motion."
    caption="Solution to LeetCode 24: Swap Nodes in Pairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        
        ListNode* cur = head, *nxt = head->next, *ret = nxt, *prv = NULL;
        
        while(cur != NULL && nxt != NULL) {
            if(prv != NULL) prv->next = nxt;
            prv = cur;            
            cur->next = nxt->next;
            nxt->next = cur;
            cur = cur->next;
            if(cur != NULL) nxt = cur->next;
        }
        return ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/24.md" >}}
---
{{< youtube o811TZLAWOo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #27: Remove Element](https://grid47.xyz/posts/leetcode_27) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
