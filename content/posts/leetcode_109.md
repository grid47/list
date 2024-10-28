
+++
authors = ["Yasir"]
title = "Leetcode 109: Convert Sorted List to Binary Search Tree"
date = "2024-07-12"
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

**Code:**

{{< highlight html >}}

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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

