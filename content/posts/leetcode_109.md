
+++
authors = ["Crafted by Me"]
title = "Leetcode 109: Convert Sorted List to Binary Search Tree"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 109: Convert Sorted List to Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Divide and Conquer","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #110: Balanced Binary Tree](https://grid47.xyz/posts/leetcode_110) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
