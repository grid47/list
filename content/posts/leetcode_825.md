
+++
authors = ["Yasir"]
title = "Leetcode 825: Friends Of Appropriate Ages"
date = "2022-07-27"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

