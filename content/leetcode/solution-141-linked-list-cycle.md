
+++
authors = ["grid47"]
title = "Leetcode 141: Linked List Cycle"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 141: Linked List Cycle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/141.webp"
youtube = "6OrZ4wAy4uE"
youtube_upload_date="2019-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6OrZ4wAy4uE/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-cycle/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/141.webp" 
    alt="A circular linked list glowing in a cycle, with the loop softly visible."
    caption="Solution to LeetCode 141: Linked List Cycle Problem"
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/141.md" >}}
---
{{< youtube 6OrZ4wAy4uE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #142: Linked List Cycle II](https://grid47.xyz/leetcode/solution-142-linked-list-cycle-ii/) |
| --- |