
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 24: Swap Nodes in Pairs"
date = "2024-10-06"
description = "Solution to Leetcode 24"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swap-nodes-in-pairs/description/)

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
