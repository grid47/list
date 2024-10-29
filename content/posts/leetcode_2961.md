
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2961: Double Modular Exponentiation"
date = "2016-09-21"
description = "Solution to Leetcode 2961"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/double-modular-exponentiation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int power(long long b, long long p, int m){
    if(p <= 0) return 1;
    long long t = power(b, p/2, m);
    t = ((t * t)%m);
    return (p%2)?(t * b)%m : t;
}

vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
    vector<int> ans;
    for(int i = 0; i < v.size(); ++i){
        long long a = v[i][0]%10, b = v[i][1], c = v[i][2], m = v[i][3], t = 1;
        t = power(a, b, 10);
        t = power(t, c, m);
        if(t == target) ans.push_back(i);
    }
    return ans;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

