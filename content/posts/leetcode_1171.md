
+++
authors = ["Yasir"]
title = "Leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List"
date = "2021-08-14"
description = "Solution to Leetcode 1171"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/)

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next= head;
        int prefix = 0;
        map<int, ListNode*> mp;
        while(cur) {
            prefix += cur->val;
            if(mp.count(prefix)) {
                cur = mp[prefix]->next;
                int p = prefix + cur->val;
                while(p != prefix) {
                    mp.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                mp[prefix]->next = cur->next;
            } else mp[prefix]  = cur;

            cur = cur->next;
        }
        return dummy->next;
    }
};
{{< /highlight >}}

