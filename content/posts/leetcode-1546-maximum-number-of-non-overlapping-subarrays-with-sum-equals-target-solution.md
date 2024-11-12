
+++
authors = ["grid47"]
title = "Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Prefix Sum"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1546.md" >}}
---
{{< youtube wcDDdRZH1Q0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1551: Minimum Operations to Make Array Equal](https://grid47.xyz/posts/leetcode-1551-minimum-operations-to-make-array-equal-solution/) |
| --- |
