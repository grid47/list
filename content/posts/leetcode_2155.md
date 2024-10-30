
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2155: All Divisions With the Highest Score of a Binary Array"
date = "2018-12-07"
description = "Solution to Leetcode 2155"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++)
        if (nums[i] == 1) ones++;
        
        int mx = ones;
        vector<int> mxx;
        mxx.push_back(0);

        int zeros = 0;
        
        int prv, cur = mx;
        for(int i = 1; i < n + 1; i++) {
            zeros += ((nums[i - 1] == 0)? 1 : 0);
            ones  -= ((nums[i - 1] == 1)? 1 : 0);

            prv = mx;
            cur = zeros + ones;
            mx  = max(mx, cur);

                 if (mx == cur && cur == prv) mxx.push_back(i);
            else if (mx >  prv) {
                mxx.clear();
                mxx.push_back(i);
            }
        }
        
        return mxx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

