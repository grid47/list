
+++
authors = ["grid47"]
title = "Leetcode 24: Swap Nodes in Pairs"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 24: Swap Nodes in Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp"
youtube = "o811TZLAWOo"
youtube_upload_date="2020-12-31"
youtube_thumbnail="https://i.ytimg.com/vi/o811TZLAWOo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/swap-nodes-in-pairs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp" 
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #27: Remove Element](https://grid47.xyz/leetcode/solution-27-remove-element/) |
| --- |
