
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K"
date = "2020-12-16"
description = "Solution to Leetcode 1414"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arr = {1, 1};
        while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        }

        set<int> cnt;
        int i = arr.size() -1;
        while(k > 0) {
            while(i >= 0 && arr[i] > k) i--;
            if(i == -1) break;
            k -= arr[i];
            cnt.insert(arr[i]);
        }
        return cnt.size();
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
