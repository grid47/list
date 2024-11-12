
+++
authors = ["grid47"]
title = "Leetcode 2121: Intervals Between Identical Elements"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2121: Intervals Between Identical Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/intervals-between-identical-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        typedef long long ll;

        
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
        mp[arr[i]].push_back(i);
        
        vector<ll> pre(n, 0), suf(n, 0);
        for(auto& val : mp){
            vector<int> vec = val.second;
            for(int i = 1; i < vec.size(); i++)
    pre[vec[i]] = pre[vec[i - 1]] + i* (ll) (vec[i] - vec[i - 1]);            
        }
        for(auto& val : mp){
            vector<int> vec = val.second;
            for(int i = vec.size() - 2; i >= 0; i--)
    suf[vec[i]] = suf[vec[i + 1]] + ll(vec.size() - 1 - i) *(ll) (vec[i + 1] - vec[i]);     
        }            

        vector<ll> ans(n, 0);
        for(int i = 0; i < n; i++)
        ans[i] = (pre[i] + suf[i]);
   
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2121.md" >}}
---
{{< youtube m1yH7eaMjMc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2124: Check if All A's Appears Before All B's](https://grid47.xyz/posts/leetcode-2124-check-if-all-as-appears-before-all-bs-solution/) |
| --- |
