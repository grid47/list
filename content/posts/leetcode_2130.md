
+++
authors = ["Crafted by Me"]
title = "Leetcode 2130: Maximum Twin Sum of a Linked List"
date = "2019-01-02"
description = "Solution to Leetcode 2130"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/)

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
    int pairSum(ListNode* head) {
        
        ListNode* slow = head, *fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        /*
        
        if its a even chain fast pointer will go out of index
        slow will reach at second of middle elements or first of second half of the chain
        
        */
        
        ListNode *cur = slow, *prv = NULL, *nxt;
        
        while(cur) {
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        
        int res = 0;
        while(prv) {
            res = max(res, head->val + prv->val);
            head = head->next;
            prv = prv->next;
        }
        return res;
    }
};
{{< /highlight >}}



---

{{< youtube FnKG0uH2PVc >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

