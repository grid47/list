
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2526: Find Consecutive Integers from a Data Stream"
date = "2017-12-01"
description = "Solution to Leetcode 2526"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class DataStream {
public:
    int val, k, cnt = 0;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(val == num) cnt = min(k, cnt+1);
        else {
            cnt = 0;
        }
        return k == cnt;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

