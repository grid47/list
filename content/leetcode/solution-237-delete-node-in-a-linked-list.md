
+++
authors = ["grid47"]
title = "Leetcode 237: Delete Node in a Linked List"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 237: Delete Node in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "sW8ZaOTtvgI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp"
+++



[`Problem Link`](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/237.webp" 
    alt="A linked list where a node gently fades away, leaving a cleaner structure behind."
    caption="Solution to LeetCode 237: Delete Node in a Linked List Problem"
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        auto nxt = node->next;
        *node = *nxt;
        delete nxt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/237.md" >}}
---
{{< youtube sW8ZaOTtvgI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #238: Product of Array Except Self](https://grid47.xyz/leetcode/solution-238-product-of-array-except-self/) |
| --- |
