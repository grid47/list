
+++
authors = ["Yasir"]
title = "Leetcode 781: Rabbits in Forest"
date = "2022-09-08"
description = "Solution to Leetcode 781"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rabbits-in-forest/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for(int i: answers)
        c[i]++;
        int res = 0;
        for(auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
};
{{< /highlight >}}

