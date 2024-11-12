
+++
authors = ["grid47"]
title = "Leetcode 2326: Spiral Matrix IV"
date = "2024-03-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2326: Spiral Matrix IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-iv/description/)

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int i = 0, j = 0, cur_dir = 0, d[5] = {0, 1, 0, -1, 0};
        for(;head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int ni = i + d[cur_dir], nj = j + d[cur_dir + 1];
            if(min(ni, nj) < 0 || ni >= m || nj >= n || res[ni][nj] != -1)
                cur_dir = (cur_dir + 1) % 4;
            i += d[cur_dir];
            j += d[cur_dir + 1];
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2326.md" >}}
---
{{< youtube sOV1nRhmsMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2327: Number of People Aware of a Secret](https://grid47.xyz/posts/leetcode-2327-number-of-people-aware-of-a-secret-solution/) |
| --- |
