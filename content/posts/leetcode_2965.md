
+++
authors = ["Crafted by Me"]
title = "Leetcode 2965: Find Missing and Repeated Values"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2965: Find Missing and Repeated Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-missing-and-repeated-values/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int first = 0;
        int sec = 0;
        
        int n = grid.size();
        
        //xor from 1 to n^2
        for(int i=1;i<=n*n;i++){
            first = first ^ i;
        }

        //xor all element from array
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sec = sec ^ grid[i][j];
            }
        }


        int xorboth = first ^ sec;

        int diff_bit_pos = 0;
        //find differentiating bit postion from back
        for(int i=0;i<32;i++){
            if((xorboth & (1<<i))) {
                diff_bit_pos = i;
                break;
            }
        }

        int ans0 = 0;
        int ans1 = 0;

        //differentiate the both according to the diff_bit_pos
        for(int i=1;i<=n*n;i++){
            if(i & (1<<diff_bit_pos)){
                ans0 ^= i;
            }
            else{
                ans1 ^= i;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] & (1<<diff_bit_pos)){
                    ans0 ^= grid[i][j];
                }
                else{
                    ans1 ^= grid[i][j];
                }
            }
        }

        //finding the order of answer
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == ans0)
                    //if ans0 is found then its repeating number
                    return {ans0 , ans1};
            }
        }

        //if ans0 is found then its not a repeating number
        return {ans1 , ans0};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2965.md" >}}
---
{{< youtube 6r-PQyoHHoQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2966: Divide Array Into Arrays With Max Difference](https://grid47.xyz/posts/leetcode_2966) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
