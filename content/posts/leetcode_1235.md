
+++
authors = ["Crafted by Me"]
title = "Leetcode 1235: Maximum Profit in Job Scheduling"
date = "2021-06-16"
description = "In-depth solution and explanation for Leetcode 1235: Maximum Profit in Job Scheduling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<int>> item;
    vector<int> mem;
    
    int bs(int end, int idx) {
        int ans = item.size();
        int l = idx, r = item.size() - 1;
        while(l <= r) {
            int mid = l + (r - l + 1) /2 ;
            if(item[mid][0] >= end) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
    
    int dp(int idx) {
        if(idx == item.size()) return 0;

        if(mem[idx] != -1) return mem[idx];

        int ans = dp(idx + 1);

        int nxt = bs(item[idx][1], idx + 1);
        ans = max(ans, dp(nxt) + item[idx][2]);

        return mem[idx] = ans;
    }
    
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {

        n = st.size();
        item.resize(n);
        mem.resize(n, -1);
        for(int i = 0; i < n; i++)
            item[i] = vector<int>{st[i], et[i], profit[i]};
        // cout << n << item.size();
        sort(item.begin(), item.end());
        
        return dp(0);        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1235.md" >}}
---

| Next : [LeetCode #1236: Web Crawler](https://grid47.xyz/posts/leetcode_1236) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

