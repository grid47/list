
+++
authors = ["Crafted by Me"]
title = "Leetcode 143: Reorder List"
date = "2024-06-11"
description = "Solution to Leetcode 143"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reorder-list/description/)

---

{{< youtube i3HU4Ur3-uM >}}

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
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* next, *prev = NULL;
        while(mid) {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode* l1 = head, *l2 = prev;
        while(l1 && l2) {
            ListNode* tmp1 = l1->next;
            l1->next = l2;
            ListNode* tmp2 = l2->next;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/143.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

