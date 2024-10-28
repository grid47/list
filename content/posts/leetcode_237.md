
+++
authors = ["Yasir"]
title = "Leetcode 237: Delete Node in a Linked List"
date = "2024-03-06"
description = "Solution to Leetcode 237"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

