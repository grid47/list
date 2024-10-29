
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points"
date = "2019-03-13"
description = "Solution to Leetcode 2058"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/)

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn = INT_MAX, mx = 0;
        if(head == NULL || head->next == NULL) return {-1, -1};
        auto nxt = head->next;
        int state = head->val > nxt->val? -1: head->val == nxt->val? 0:1;
        int prv, cnt = -1, cnt2 = -1;
        while(nxt->next) {
            head = nxt;
            nxt = nxt->next;
            prv = state;
            state = head->val > nxt->val? -1: (head->val == nxt->val? 0:1);
            // cout << prv << ":" << state << " ";
            if(cnt != -1) {
                cnt++;
                cnt2++;
            }
            if((prv == -1 && state == 1) || (prv == 1 && state == -1)) {
                if(cnt2 == -1) cnt2 = 0;
                else {
                    mx = max(mx, cnt2);                    
                }
                if(cnt != -1)
                mn = min(mn, cnt);                                
                cnt = 0;
            }
        }
        // cout << mn << " " << mx;
        if(mn == INT_MAX || mx == 0) return {-1, -1};
        
        return {mn, mx};
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

