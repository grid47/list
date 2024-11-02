
+++
authors = ["Crafted by Me"]
title = "Leetcode 825: Friends Of Appropriate Ages"
date = "2021-07-30"
description = "Solution to Leetcode 825"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/friends-of-appropriate-ages/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for(int age: ages)
            cnt[age]++;

        int res = 0;
        for(auto a: cnt)
        for(auto b: cnt)
        if(request(a.first, b.first))
            res += a.second * (b.second - (a.first == b.first? 1: 0));
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/825.md" >}}
---
{{< youtube 0_4H68f85HQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

