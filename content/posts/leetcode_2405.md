
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2018-04-01"
description = "Solution to Leetcode 2405"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/optimal-partition-of-string/description/)

---
{{< youtube 1Zx7gEznzfI >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkBit(int &flag, int &n) {
        return flag & (1<< n);
    }

    void setBit(int &flag, int & n) {
        flag |= (1<<n);
    }

    int partitionString(string s) {
        int flag = 0, ans = 1;
        for(auto c: s) {
            int n = c - 'a';
            if(checkBit(flag, n)) {
                flag = 0;
                ans++;
            }
            setBit(flag, n);
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

