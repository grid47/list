
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1675: Minimize Deviation in Array"
date = "2020-03-30"
description = "Solution to Leetcode 1675"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
