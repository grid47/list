
+++
authors = ["Crafted by Me"]
title = "Leetcode 2121: Intervals Between Identical Elements"
date = "2019-01-12"
description = "Solution to Leetcode 2121"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

