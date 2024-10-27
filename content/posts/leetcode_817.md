
+++
authors = ["Yasir"]
title = "Leetcode 817: Linked List Components"
date = "2022-08-03"
description = "Solution to Leetcode 817"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-components/description/)

---

**Code:**

{{< highlight html >}}
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> setG(nums.begin(), nums.end());
        int res =0;
        while(head != NULL) {
            if(setG.count(head->val) && 
            (head->next == NULL || !setG.count(head->next->val)))
            res++;
            head = head->next;
        }
        return res;
    }
};
{{< /highlight >}}

