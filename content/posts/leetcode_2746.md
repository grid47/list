
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2746: Decremental String Concatenation"
date = "2017-04-25"
description = "Solution to Leetcode 2746"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

