
+++
authors = ["grid47"]
title = "Leetcode 2008: Maximum Earnings From Taxi"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2008: Maximum Earnings From Taxi in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QoAuE1v2vxA"
youtube_upload_date="2021-09-18"
youtube_thumbnail="https://i.ytimg.com/vi/QoAuE1v2vxA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-earnings-from-taxi/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rides;
    vector<long long> memo;
    int n;

    long long dp(int idx) {
        
        if(idx == rides.size()) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        long long ans = dp(idx + 1);
                
        
        int end = rides[idx][1];
        
        int l = idx + 1, r = rides.size() - 1;
        int pos = rides.size();
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(rides[mid][0] >= end) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
            
        ans = max(ans, dp(pos) + rides[idx][2]);        
        return memo[idx] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
        this->n = n;
        rides = ride;
        sort(rides.begin(), rides.end());
        
        for(int i = 0; i < rides.size(); i++)
            rides[i][2] += rides[i][1] - rides[i][0];
        
        memo.resize(rides.size() + 1, -1);
        return dp(0);

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2008.md" >}}
---
{{< youtube QoAuE1v2vxA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2011: Final Value of Variable After Performing Operations](https://grid47.xyz/leetcode/solution-2011-final-value-of-variable-after-performing-operations/) |
| --- |