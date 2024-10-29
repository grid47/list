
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 920: Number of Music Playlists"
date = "2022-04-24"
description = "Solution to Leetcode 920"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-music-playlists/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numMusicPlaylists(int N, int L, int K) {
        int mod = (int)pow(10, 9) + 7;
        vector<vector<long>> dp(L+1, vector<long>(N+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= L; i++){
            for (int j = 1; j <= N; j++){
                dp[i][j] = (dp[i-1][j-1] * (N - (j-1)))%mod; 
                if (j > K){
                    dp[i][j] = (dp[i][j] + (dp[i-1][j] * (j-K))%mod)%mod;
                }
            }
        }
        return (int)dp[L][N];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

