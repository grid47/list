
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1019: Next Greater Node In Linked List"
date = "2022-01-14"
description = "Solution to Leetcode 1019"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-node-in-linked-list/description/)

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> stk, res;
        
        for(ListNode* node = head; node != NULL; node = node->next) {
            
            while(!stk.empty() && res[stk.back()] < node->val) {
                res[stk.back()] = node->val;
                stk.pop_back();
            }

            
            stk.push_back(res.size());
            res.push_back(node->val);
        }
        
        for(int i : stk) res[i] = 0;
        
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

