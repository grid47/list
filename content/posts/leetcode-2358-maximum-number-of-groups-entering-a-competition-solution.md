
+++
authors = ["grid47"]
title = "Leetcode 2358: Maximum Number of Groups Entering a Competition"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2359: Find Closest Node to Given Two Nodes](https://grid47.xyz/posts/leetcode-2359-find-closest-node-to-given-two-nodes-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}