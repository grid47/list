
+++
authors = ["Crafted by Me"]
title = "Leetcode 1436: Destination City"
date = "2019-11-27"
description = "Solution to Leetcode 1436"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

