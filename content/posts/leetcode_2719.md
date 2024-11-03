
+++
authors = ["Crafted by Me"]
title = "Leetcode 2719: Count of Integers"
date = "2017-05-24"
description = "In-depth solution and explanation for Leetcode 2719: Count of Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-of-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int dp[24][2][2][401];
    string n1, n2;
    int mod = (int) 1e9 + 7;
    
    int sum(int idx, bool t1, bool t2, int net) {
        if(net < 0) return 0;
        if(idx == n1.size()) return 1;
        
        if(dp[idx][t1][t2][net] != -1) return dp[idx][t1][t2][net];
        
        int st = t1? n1[idx] - '0': 0;
        int ed = t2? n2[idx] - '0': 9;
        int cnt = 0;
        for(int i = st; i <= ed; i++) {
            cnt = (long) (cnt + sum(idx + 1, t1 && (i == st), t2 && (i == ed), net - i)) % mod;
        }
        return dp[idx][t1][t2][net] = cnt;
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        num1 = string(num2.size() - num1.size(), '0') + num1;
        
        n1 = num1;
        n2 = num2;
        
        memset(dp, -1, sizeof(dp));
        
        int res = sum(0, 1, 1, max_sum);
        res -= sum(0, 1, 1, min_sum - 1);
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

