
+++
authors = ["grid47"]
title = "Leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List"
date = "2024-07-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/)

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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1171.md" >}}
---
{{< youtube xZRozZEjizg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1177: Can Make Palindrome from Substring](https://grid47.xyz/posts/leetcode-1177-can-make-palindrome-from-substring-solution/) |
| --- |
