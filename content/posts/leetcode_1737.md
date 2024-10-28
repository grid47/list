
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1737: Change Minimum Characters to Satisfy One of Three Conditions"
date = "2020-01-27"
description = "Solution to Leetcode 1737"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    int minCharacters(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> ca(26, 0), cb(26, 0);
        for(int i = 0; i < m; i++) {
            ca[a[i] - 'a']++; }
        for(int j = 0; j < n; j++) {
            cb[b[j] - 'a']++; }
        
        int res = m + n;
        for(int i = 0; i < 26; i++) {
            res = min(res, m + n - ca[i] - cb[i]);
            if(i > 0) {

         ca[i] += ca[i - 1];
         cb[i] += cb[i - 1];
                }
            if(i < 25) {
res = min(res, m - ca[i] + cb[i]);
res = min(res, n - cb[i] + ca[i]);

            }
            
            }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

