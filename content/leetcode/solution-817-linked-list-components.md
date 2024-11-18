
+++
authors = ["grid47"]
title = "Leetcode 817: Linked List Components"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 817: Linked List Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-components/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/817.webp" 
    alt="A linked list where the components are highlighted, each component softly glowing as it is connected."
    caption="Solution to LeetCode 817: Linked List Components Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/817.md" >}}
---
{{< youtube Vxbd1u86p9c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #820: Short Encoding of Words](https://grid47.xyz/leetcode/solution-820-short-encoding-of-words/) |
| --- |
