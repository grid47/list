
+++
authors = ["Yasir"]
title = "Leetcode 2530: Maximal Score After Applying K Operations"
date = "2017-11-24"
description = "Solution to Leetcode 2530"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--) {
            int tmp = pq.top();
            cout << tmp << " ";
            ans += tmp;
            pq.pop();
            pq.push(ceil(tmp/3.0));
            
        }
        return ans;
    }
};
{{< /highlight >}}

