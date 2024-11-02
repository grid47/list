
+++
authors = ["Crafted by Me"]
title = "Leetcode 1535: Find the Winner of an Array Game"
date = "2020-08-20"
description = "Solution to Leetcode 1535"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-winner-of-an-array-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;
        int j = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[j]) {
                cnt++;
            } else {
                cnt = 1;
                j = i;
            }
            if(cnt == k) return arr[j];            
        }
        return arr[j];
    }
};
{{< /highlight >}}


---
{{< youtube v6On1TQfMTU >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

