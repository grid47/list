
+++
authors = ["grid47"]
title = "Leetcode 445: Add Two Numbers II"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 445: Add Two Numbers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "ovGnWmf2sew"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp"
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/445.webp" 
    alt="Two linked lists gently adding their digits, with each addition softly illuminated as it occurs."
    caption="Solution to LeetCode 445: Add Two Numbers II Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #447: Number of Boomerangs](https://grid47.xyz/leetcode/solution-447-number-of-boomerangs/) |
| --- |
