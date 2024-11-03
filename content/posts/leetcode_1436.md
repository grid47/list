
+++
authors = ["Crafted by Me"]
title = "Leetcode 1436: Destination City"
date = "2020-11-27"
description = "In-depth solution and explanation for Leetcode 1436: Destination City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destination-city/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        for(auto s: paths)
            mp[s[0]] = s[1];
        
        string ans = paths[0][0];
        while(mp.count(ans)) {
            ans = mp[ans];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1436.md" >}}
---

| Next : [LeetCode #1437: Check If All 1's Are at Least Length K Places Away](https://grid47.xyz/posts/leetcode_1437) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

