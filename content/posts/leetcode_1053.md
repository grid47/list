
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1053: Previous Permutation With One Swap"
date = "2021-12-12"
description = "Solution to Leetcode 1053"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/previous-permutation-with-one-swap/description/)

---

**Code:**

{{< highlight cpp >}}

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1, n = arr.size();
        for(int i = n - 1; i > 0; i--) {
            // cout<< arr[i] << " " << arr[i - 1] << '\n';
            if(arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        // cout << idx;
        if(idx == -1) return arr;

        for(int i = n - 1; i > idx; i--) {
            if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
