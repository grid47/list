
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1536: Minimum Swaps to Arrange a Binary Grid"
date = "2020-08-16"
description = "Solution to Leetcode 1536"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
