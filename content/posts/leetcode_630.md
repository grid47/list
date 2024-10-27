
+++
authors = ["Yasir"]
title = "Leetcode 630: Course Schedule III"
date = "2023-02-06"
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

{{< highlight html >}}
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

