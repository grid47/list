
+++
authors = ["grid47"]
title = "Leetcode 328: Odd Even Linked List"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 328: Odd Even Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp"
youtube = "HaoudL9xEHA"
youtube_upload_date="2020-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/HaoudL9xEHA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/odd-even-linked-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/328.webp" 
    alt="A linked list where odd and even numbered nodes alternate, glowing softly as they form the correct pattern."
    caption="Solution to LeetCode 328: Odd Even Linked List Problem"
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *odd = head, *ehead = head->next, *even = head->next;

        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = ehead;
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/328.md" >}}
---
{{< youtube HaoudL9xEHA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #338: Counting Bits](https://grid47.xyz/leetcode/solution-338-counting-bits/) |
| --- |