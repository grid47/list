
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1338: Reduce Array Size to The Half"
date = "2021-03-02"
description = "Solution to Leetcode 1338"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reduce-array-size-to-the-half/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int c: arr) ++mp[c];

        vector<int> frq;
        for(auto [_, fq] : mp) frq.push_back(fq);

        sort(frq.begin(), frq.end());

        int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
        while(rm < half) {
            rm += frq[i--];
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

