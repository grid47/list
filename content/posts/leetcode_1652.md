
+++
authors = ["Yasir"]
title = "Leetcode 1652: Defuse the Bomb"
date = "2020-04-20"
description = "Solution to Leetcode 1652"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/defuse-the-bomb/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k == 0) return ans;
        
        int sum = 0;
        if(k > 0) {
            for(int i = 1; i < k + 1; i++)
                sum += code[i];
            ans[0] = sum;
            for(int i = 1; i < n; i++) {
                sum += code[(i + k) % n];
                sum -= code[i];
                ans[i] = sum;
            }
            return ans;
        }

        for(int i = 0; i < abs(k); i++)
            sum += code[n - 1 - i];
        ans[0] = sum;
        for(int i = 1; i < n; i++) {
            sum += code[i - 1];
            sum -= code[(i - 1 - abs(k) + n) % n];
            ans[i] = sum;
        }
        return ans;        
        
    }
};
{{< /highlight >}}

