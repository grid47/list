
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 630: Course Schedule III"
date = "2023-02-08"
description = "Solution to Leetcode 630"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/course-schedule-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& nums) {
        
        priority_queue<int> pq;
        
        sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        
        int sum = 0;
        for(auto it: nums) {
            sum += it[0];
            pq.push(it[0]);
            if(sum > it[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/630.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

