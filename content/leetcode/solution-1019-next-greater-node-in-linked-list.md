
+++
authors = ["grid47"]
title = "Leetcode 1019: Next Greater Node In Linked List"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1019: Next Greater Node In Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1019.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1020: Number of Enclaves](https://grid47.xyz/leetcode/solution-1020-number-of-enclaves/) |
| --- |