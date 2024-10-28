
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1861: Rotating the Box"
date = "2019-09-25"
description = "Solution to Leetcode 1861"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotating-the-box/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        reverse(box.begin(), box.end());
        
        int m = box.size(), n = box[0].size();
        vector<vector<char>> tmp(n, vector<char>(m));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            tmp[j][i] = box[i][j];
        
        for(int i = 0; i < m; i++) {
            int k = n - 1;
            for(int j = n - 1; j >= 0; j--) {
                if(tmp[j][i] == '#') {
                    tmp[j][i] = '.'; // o
                    tmp[k][i] = '#'; // order is important
                    k--;
                } else if(tmp[j][i] == '*') {
                    k = j - 1;
                }else if(tmp[j][i] == '.') {
                    
                }
            }
        }
        return tmp; 
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

