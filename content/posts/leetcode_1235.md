
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1235: Maximum Profit in Job Scheduling"
date = "2021-06-13"
description = "Solution to Leetcode 1235"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
