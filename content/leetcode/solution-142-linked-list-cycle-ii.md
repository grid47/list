
+++
authors = ["grid47"]
title = "Leetcode 142: Linked List Cycle II"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 142: Linked List Cycle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/142.webp"
youtube = "Yn5xqbK95Uw"
youtube_upload_date="2020-10-27"
youtube_thumbnail="https://i.ytimg.com/vi/Yn5xqbK95Uw/sddefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-cycle-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/142.webp" 
    alt="A cycle in the linked list gently glowing, with the starting node illuminated to indicate the cycle's start."
    caption="Solution to LeetCode 142: Linked List Cycle II Problem"
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *fast = head, *slow= head;
        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!(fast && fast->next)) return NULL;
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/142.md" >}}
---
{{< youtube Yn5xqbK95Uw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #143: Reorder List](https://grid47.xyz/leetcode/solution-143-reorder-list/) |
| --- |
