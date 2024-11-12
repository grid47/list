
+++
authors = ["grid47"]
title = "Leetcode 2358: Maximum Number of Groups Entering a Competition"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2358: Maximum Number of Groups Entering a Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int cur_people = 1;
        int cur_grade  = nums[0];
        int tmp_people = 0;
        int tmp_grade = 0;
        int total = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
                tmp_grade += nums[i];
                tmp_people += 1;
            } else {
                total += 1;
                cur_people = tmp_people;
                cur_grade = tmp_grade;
                tmp_people = 1;
                tmp_grade = nums[i];
            }
        }
        return (tmp_people > cur_people && tmp_grade > cur_grade)? total + 1: total;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2358.md" >}}
---
{{< youtube r_kn18dmnNo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2359: Find Closest Node to Given Two Nodes](https://grid47.xyz/posts/leetcode-2359-find-closest-node-to-given-two-nodes-solution/) |
| --- |
