
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 109: Convert Sorted List to Binary Search Tree"
date = "2024-07-14"
description = "Solution to Leetcode 109"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

---
{{< youtube 0E8Xxu6LV9o >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

