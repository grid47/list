
+++
authors = ["Crafted by Me"]
title = "Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
date = "2020-08-08"
description = "Solution to Leetcode 1546"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int hit) {
        map<int, int> mp;
        
        int n = nums.size(), sum = 0, right = -1, cnt = 0;
        
        //partial_sum(nums.begin(), nums.end(), nums.begin());
        
        
        mp[0] = -1;
        
        
        for(int i = 0; i < n;i++){
            //cout<< nums[i] << " ";
            sum += nums[i];
            if(mp.count(sum - hit)) {
                int left = mp[sum - hit];
            //    cout << right << " " << left;
                if (right <= left) {
                    cnt++;
                    right = i;
                  }
                }


            mp[sum] = i;
            // cout<< mp[sum] << endl;
          }
            
            

        
        return cnt;
            
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

