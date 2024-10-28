
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2578: Split With Minimum Sum"
date = "2017-10-08"
description = "Solution to Leetcode 2578"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-with-minimum-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0, x = 1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(),v.end());
        num = 0;
        for(auto &i: v){
            num *= 10;
            num += i;
        }
        while(num){
            num1 += x*(num%10);
            num /= 10;
            num2 += x*(num%10);
            num /= 10;
            x *= 10;
        }
        return num1+num2;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

