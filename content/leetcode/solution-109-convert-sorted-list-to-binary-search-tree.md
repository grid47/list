
+++
authors = ["grid47"]
title = "Leetcode 109: Convert Sorted List to Binary Search Tree"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 109: Convert Sorted List to Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Divide and Conquer","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "0E8Xxu6LV9o"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/109.webp"
+++



[`Problem Link`](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/109.webp" 
    alt="A flowing list of sorted numbers seamlessly transforming into a calm, glowing binary search tree."
    caption="Solution to LeetCode 109: Convert Sorted List to Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    TreeNode* toBST(ListNode* start, ListNode* end) {

        if(start == end) return NULL;

        ListNode* slw = start;
        ListNode* fst = start;

        while(fst != end && fst->next != end) {
            slw = slw->next;
            fst = fst->next->next;
        }

        TreeNode* node = new TreeNode(slw->val);
        node->left = toBST(start, slw);
        node->right = toBST(slw->next, end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        return toBST(head, NULL);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/109.md" >}}
---
{{< youtube 0E8Xxu6LV9o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #110: Balanced Binary Tree](https://grid47.xyz/leetcode/solution-110-balanced-binary-tree/) |
| --- |
