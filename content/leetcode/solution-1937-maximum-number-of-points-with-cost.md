
+++
authors = ["grid47"]
title = "Leetcode 1937: Maximum Number of Points with Cost"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1937: Maximum Number of Points with Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ik1y7fz8AOc"
youtube_upload_date="2024-08-17"
youtube_thumbnail="https://i.ytimg.com/vi/ik1y7fz8AOc/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-points-with-cost/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> pts;
    map<int, map<int, long long>> mp;
    long long dp(int idx, int prv) {
        if(idx == pts.size()) return 0;
        
        if(mp.count(idx) && mp[idx].count(prv)) return mp[idx][prv];
        
        long long ans = LLONG_MIN;
        if(prv == -1) {
            for(int i = 0; i < pts[0].size(); i++)
                ans = max(ans, pts[idx][i] + dp(idx + 1, i));
        } else {
            for(int i = 0; i < pts[0].size(); i++)
                ans = max(ans, pts[idx][i] - abs(i - prv) + dp(idx + 1, i));
        }
        return mp[idx][prv] = ans;
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        pts = points;
        int m = pts.size(), n = pts[0].size();
        
        vector<long long> prv(n);
        for(int i = 0; i < n; i++) prv[i] = pts[0][i];
        
        for(int j = 0; j < m - 1; j++) {
            vector<long long> left(n, 0), right(n, 0), cur(n, 0);
            
            left[0] = prv[0];
            right[n - 1] = prv[n - 1];
            
            for(int i = 1; i < n; i++)
                left[i] = max(left[i - 1] - 1, prv[i]);
            
            for(int i = n - 2; i >= 0; i--)
                right[i] = max(right[i + 1] - 1, prv[i]);
            
            for(int i = 0; i < n; i++)
                cur[i] = max(left[i], right[i]) + pts[j + 1][i];
            
            prv = cur;
        }
        
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++)
            ans = max(ans, prv[i]);

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1937.md" >}}
---
{{< youtube ik1y7fz8AOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1941: Check if All Characters Have Equal Number of Occurrences](https://grid47.xyz/leetcode/solution-1941-check-if-all-characters-have-equal-number-of-occurrences/) |
| --- |