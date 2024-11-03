
+++
authors = ["Crafted by Me"]
title = "Leetcode 725: Split Linked List in Parts"
date = "2022-11-08"
description = "In-depth solution and explanation for Leetcode 725: Split Linked List in Parts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-linked-list-in-parts/description/)

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }

        int numNodes = len/k;
        int ext = len % k;
        int i = 0;
        vector<ListNode*> res;
        temp = head;
        while(temp) {
            res.push_back(temp);
            int curLen = 1;
            while(curLen < numNodes) {
                temp =  temp->next;
                curLen++;
            }
            if(ext > 0 && len > k) {
                temp = temp->next;
                ext--;
            }
            ListNode* x = temp->next;
            temp->next = NULL;
            temp = x;
        }

        while(len < k) {
            res.push_back(NULL);
            len++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/725.md" >}}
---
{{< youtube ZITsHLE5mbE >}}

"| 726: Number of Atoms |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

