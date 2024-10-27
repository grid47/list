
+++
authors = ["Yasir"]
title = "Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One"
date = "2020-12-24"
description = "Solution to Leetcode 1404"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSteps(string s) {
        
        int idx = s.size() - 1, cnt = 0;
        
        while(idx > 0) {
            if(s[idx] == '0') {
                cnt++;
                idx--;
            } else {
                int tmp = idx;
                while(idx >= 0 && s[idx] == '1') idx--;
                cnt++; // add one
                if(idx >= 0) {
                    s[idx] = '1';
                    cnt += (tmp-idx); // divide by 2
                } else {
                    cnt += (tmp-idx);
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

