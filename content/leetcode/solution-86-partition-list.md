
+++
authors = ["grid47"]
title = "Leetcode 86: Partition List"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 86: Partition List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/86.webp"
youtube = "KT1iUciJr4g"
youtube_upload_date="2021-02-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KT1iUciJr4g/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/partition-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/86.webp" 
    alt="A glowing line dividing a list into two perfect sections."
    caption="Solution to LeetCode 86: Partition List Problem"
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);        
        
        ListNode* ans = p1, *r = p2;
        
        while(head) {
            if(head->val < x) {
                p1->next = new ListNode(head->val);
                p1 = p1->next;
            } else {
                p2->next = new ListNode(head->val);
                p2 = p2->next;                
            }
            head = head->next;
        }

        p1->next = r->next;
        return ans->next;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/86.md" >}}
---
{{< youtube KT1iUciJr4g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #89: Gray Code](https://grid47.xyz/leetcode/solution-89-gray-code/) |
| --- |