
+++
authors = ["Yasir"]
title = "Leetcode 480: Sliding Window Median"
date = "2023-07-05"
description = "Solution to Leetcode 480"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-window-median/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win(nums.begin(), nums.begin() + k);
        
        auto mid = next(win.begin(), k/2);
        vector<double> ans;


        for(int i = k; ; i++) {
            
            double med =  ((double)*mid + (double)*prev(mid, 1 - k%2)) / 2;
            ans.push_back(med);
            
            if(i == nums.size()) return ans;
            
            win.insert(nums[i]);
            if(nums[i] < *mid) // mutiset insertion happens from upper end
                mid--;

            if(nums[i - k] <= *mid)
                mid++;
            win.erase(win.lower_bound(nums[i - k]));

        }
        return ans;
    }
};
{{< /highlight >}}

