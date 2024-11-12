
+++
authors = ["grid47"]
title = "Leetcode 2: Add Two Numbers"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2: Add Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Math","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/2.webp" 
    alt="Two radiant number paths merging into one continuous light beam, symbolizing addition."
    caption="Solution to LeetCode 2: Add Two Numbers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int rm = 0;

        while (l1 != NULL || l2 != NULL || rm != 0) {
            int no1 = (l1 != NULL) ? l1->val : 0;
            int no2 = (l2 != NULL) ? l2->val : 0;

            int sum = no1 + no2 + rm;
            int digit = sum % 10;
            rm = sum / 10;

            ListNode* nxt = new ListNode(digit);
            tail->next = nxt;
            tail = tail->next;

            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }

        ListNode* res = head->next;
        delete head;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2.md" >}}
---
{{< youtube wgFPrzTjm7s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3: Longest Substring Without Repeating Characters](https://grid47.xyz/posts/leetcode-3-longest-substring-without-repeating-characters-solution/) |
| --- |
