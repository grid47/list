
+++
authors = ["Crafted by Me"]
title = "Leetcode 2054: Two Best Non-Overlapping Events"
date = "2019-03-19"
description = "Solution to Leetcode 2054"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/two-best-non-overlapping-events/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> eve;
    vector<vector<unordered_map<int, int>>> memo;
    int n;
    
    int dp(int idx, int end, int k) {
        if(idx >= n || k == 0) return 0;
        
        if(memo[idx][k].count(end)) return memo[idx][k][end];
        
        int ans = dp(idx + 1, end, k);
        
        int l = idx + 1, r = n - 1, res = n;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            if(eve[mid][0] > eve[idx][1]) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
            
        }
        
        ans = max(ans, eve[idx][2] + dp(res, eve[idx][1], k - 1));
        
        return memo[idx][k][end] = ans;
    }
    
    int ma(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        eve = events;
        n = eve.size();
        memo.resize(n, vector<unordered_map<int, int>>(3));
        return dp(0, 0, 2);        
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int ans = 0, mx = 0;
        map<int, int> mp;
        
        int size = events.size();
        
        while(size--) {
            auto it = mp.upper_bound(events[size][1]);
            mx = max(mx, events[size][2]);
            mp[events[size][0]] = mx;
            if(it == mp.end()) {
                ans = max(ans, mx);
            } else {
                ans = max(ans, events[size][2] + it->second);
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

