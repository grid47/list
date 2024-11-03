
+++
authors = ["Crafted by Me"]
title = "Leetcode 2526: Find Consecutive Integers from a Data Stream"
date = "2017-12-03"
description = "In-depth solution and explanation for Leetcode 2526: Find Consecutive Integers from a Data Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

---

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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

