
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2: Add Two Numbers"
date = "2024-10-28"
description = "Solution to Leetcode 2"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers/description/)

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
