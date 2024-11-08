
+++
authors = ["grid47"]
title = "Leetcode 1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1547: Minimum Cost to Cut a Stick](https://grid47.xyz/posts/leetcode_1547) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
