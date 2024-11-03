
+++
authors = ["Crafted by Me"]
title = "Leetcode 1669: Merge In Between Linked Lists"
date = "2020-04-08"
description = "In-depth solution and explanation for Leetcode 1669: Merge In Between Linked Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-in-between-linked-lists/description/)

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* f = list1, *s = list1;
        for(int i = 0; i < a-1; i++) f = f->next;
        for(int i = 0; i < b; i++) s = s->next;
        f->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = s->next;
        return list1;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1670: Design Front Middle Back Queue](https://grid47.xyz/posts/leetcode_1670) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

