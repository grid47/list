
+++
authors = ["grid47"]
title = "Leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2058.md" >}}
---
{{< youtube UddDgt52h9g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2059: Minimum Operations to Convert Number](https://grid47.xyz/posts/leetcode-2059-minimum-operations-to-convert-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}