
+++
authors = ["Yasir"]
title = "Leetcode 382: Linked List Random Node"
date = "2023-10-11"
description = "Solution to Leetcode 382"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-random-node/description/)

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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = 0, i = 1;
        ListNode* p = this->head;
        while(p) {
            if(rand() % i == 0) ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
{{< /highlight >}}

