
+++
authors = ["Crafted by Me"]
title = "Leetcode 1675: Minimize Deviation in Array"
date = "2020-04-02"
description = "In-depth solution and explanation for Leetcode 1675: Minimize Deviation in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-deviation-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), mn = -1;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            int tmp = nums[i]%2? nums[i] * 2: nums[i];
            if(mn == -1 || mn > tmp)
                mn = tmp;
            pq.push(tmp);
        }
        int ans = INT_MAX;
        while((pq.top() % 2) == 0) {
            ans = min(ans, pq.top() - mn);
            int tmp = pq.top() / 2;
            mn = min(mn, tmp);
            pq.pop();
            pq.push(tmp);
        }
        return min(ans, pq.top() - mn);
        
        // [4,1,5,20,3]
        //  1 1 5 5  3
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

