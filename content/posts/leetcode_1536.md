
+++
authors = ["Crafted by Me"]
title = "Leetcode 1536: Minimum Swaps to Arrange a Binary Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1536: Minimum Swaps to Arrange a Binary Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        set<int> found;
        
        vector<int> arr(n, 0);
        
        for(int i = 0; i < n; i++) {
            
            int j = n - 1, cnt = 0;
            while(j > -1 && grid[i][j] == 0) {
                j--;
                cnt++;
            }
            
            for(int k = n - 1; k >= 0; k--) {
                if(cnt >= k && !found.count(k)) {
                    found.insert(k);
                    arr[i] = n - 1 - k;
                    break;
                }
            }
        }
        
        if(found.size() != n) return -1;
        
        return bubble(arr);
    }
    
    int bubble(vector<int> &arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        for(int j = 1; j < arr.size(); j++)
            if(arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                cnt++;
            }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1536.md" >}}
---
{{< youtube OLA5Qwt4NKw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1540: Can Convert String in K Moves](https://grid47.xyz/posts/leetcode_1540) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
