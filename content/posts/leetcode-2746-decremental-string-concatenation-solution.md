
+++
authors = ["grid47"]
title = "Leetcode 2746: Decremental String Concatenation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2746: Decremental String Concatenation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decremental-string-concatenation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public: 
    int n ; 
    int dp[1010][26][26] ;  
    int rec(int level , int first , int last , vector <string>& arr){
        if(level == n){
            return 0 ; 
        }
        if(dp[level][first][last] != -1){
            return dp[level][first][last] ; 
        }
        int ans = 1e9 ;
        int t = (int)arr[level].size() ; 
        if(arr[level][t-1] - 'a' == first){
            ans = min(ans , t-1 + rec(level+1 , arr[level][0] - 'a' , last , arr) ) ; 
        }
        ans = min(ans , t + rec(level+1 , arr[level][0] - 'a' , last , arr)) ; 
        if(arr[level][0] - 'a' == last){
            ans = min(ans , t-1 + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
        }
        ans = min(ans , t + rec(level+1 , first , arr[level][t-1] - 'a' , arr)) ; 
        return dp[level][first][last] = ans ; 
    }
    
    
    int minimizeConcatenatedLength(vector<string>& words) {
        n = (int)words.size() ; 
        memset(dp , -1 , sizeof(dp)) ; 
        int t = (int)words[0].size() ; 
        int ans = t + rec(1 , words[0][0] -'a' , words[0][t-1]-'a' , words) ; 
        return ans ; 
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2746.md" >}}
---
{{< youtube RxvXIWCooRE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2747: Count Zero Request Servers](https://grid47.xyz/posts/leetcode-2746-decremental-string-concatenation-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
