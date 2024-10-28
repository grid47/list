
+++
authors = ["Yasir"]
title = "Leetcode 1387: Sort Integers by The Power Value"
date = "2021-01-11"
description = "Solution to Leetcode 1387"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-power-value/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    map<int, int> memo;
    
    int dig(int num) {
        if(num == 1) return 0;
        if(memo.count(num)) return memo[num];
        if(num % 2 == 0)
            return memo[num] = dig(num / 2) + 1;
        return memo[num] = dig(3 * num + 1) + 1;        
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        for(int i = lo; i <= hi; i++) {
            int tmp = dig(i);
            ans.push_back({tmp, i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1].second;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

