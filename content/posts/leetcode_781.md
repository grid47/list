
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 781: Rabbits in Forest"
date = "2022-09-11"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/781.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

