
+++
authors = ["Yasir"]
title = "Leetcode 1964: Find the Longest Valid Obstacle Course at Each Position"
date = "2019-06-13"
description = "Solution to Leetcode 1964"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        int n = obs.size();
        vector<int> ans(n, 1), tmp;
        for(int i = 0; i < n; i++) {
            if(tmp.empty() || tmp.back() <= obs[i]) {
                tmp.push_back(obs[i]);
                ans[i] = tmp.size();
            } else {
                int idx = upper_bound(tmp.begin(), tmp.end(), obs[i]) - tmp.begin();
                tmp[idx] = obs[i];
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

