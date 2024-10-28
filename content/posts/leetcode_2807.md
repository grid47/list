
+++
authors = ["Yasir"]
title = "Leetcode 2807: Insert Greatest Common Divisors in Linked List"
date = "2017-02-21"
description = "Solution to Leetcode 2807"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/)

---

**Code:**

{{< highlight html >}}
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* res = head;
        
        while(head && head->next) {
            ListNode* node = new ListNode(__gcd(head->val, head->next->val));
            ListNode* tmp = head->next;
            head->next = node;
            node->next = tmp;
            head = tmp;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

