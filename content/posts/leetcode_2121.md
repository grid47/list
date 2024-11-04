
+++
authors = ["Crafted by Me"]
title = "Leetcode 2121: Intervals Between Identical Elements"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2121: Intervals Between Identical Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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
{{< youtube m1yH7eaMjMc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2122: Recover the Original Array](https://grid47.xyz/posts/leetcode_2122) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

