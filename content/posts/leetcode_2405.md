
+++
authors = ["Yasir"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2018-03-29"
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

**Code:**

{{< highlight html >}}
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

