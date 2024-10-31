
+++
authors = ["Crafted by Me"]
title = "Leetcode 1404: Number of Steps to Reduce a Number in Binary Representation to One"
date = "2020-12-28"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

