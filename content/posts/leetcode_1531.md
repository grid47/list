
+++
authors = ["Crafted by Me"]
title = "Leetcode 1531: String Compression II"
date = "2020-08-23"
description = "Solution to Leetcode 1531"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-compression-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> mem;
    string s;
    int n;

    int len(int num) {
        return num == 1? 0: num < 10? 1: num < 100? 2: 3;
    }

    int dp(int idx, int k) {

        if(k < 0) return 256;
        if(idx >= n || n - idx <= k) return 0;

        if(mem[idx][k] != -1) return mem[idx][k];

        vector<int> frq(26, 0);
        int ans = 256, most = 0;

        for(int i = idx; i < n; i++) {
            most = max(most, ++frq[s[i]- 'a']);
            ans = min(ans, 1 + len(most) + dp(i + 1, k - (i - idx + 1-most)));
        }

        return mem[idx][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        this->s = s;
        mem.resize(n, vector<int>(k + 1, -1));
        return dp(0, k);
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

