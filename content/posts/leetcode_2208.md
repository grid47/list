
+++
authors = ["Crafted by Me"]
title = "Leetcode 2208: Minimum Operations to Halve Array Sum"
date = "2018-10-17"
description = "Solution to Leetcode 2208"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        priority_queue<double, vector<double>, less<double>> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        
        sum = sum / 2;
        
        double tmp = 0;
        int cnt = 0;
        while(tmp < sum && !pq.empty()) {

            double x = (pq.top() / 2);
            tmp += x;

            pq.pop();
            pq.push(x);

            cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

