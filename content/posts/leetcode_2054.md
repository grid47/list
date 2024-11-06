
+++
authors = ["Crafted by Me"]
title = "Leetcode 2054: Two Best Non-Overlapping Events"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2054: Two Best Non-Overlapping Events in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sorting","Heap (Priority Queue)"]
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
{{< youtube eC62DF5PW6E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2055: Plates Between Candles](https://grid47.xyz/posts/leetcode_2055) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
