
+++
authors = ["grid47"]
title = "Leetcode 1262: Greatest Sum Divisible by Three"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1262: Greatest Sum Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(3, 0);

        for(int a : nums)
        for(int i : vector<int>(dp))
        dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);

        return dp[0];
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem at hand is to find the maximum sum of elements from an integer array `nums` that is divisible by `3`. The challenge lies in optimizing the selection of array elements to achieve the highest possible sum while ensuring the result meets the divisibility condition.

### Approach
To tackle this problem, we will employ a dynamic programming technique. The main idea is to maintain a dynamic programming array that keeps track of the maximum sums that yield specific remainders when divided by `3`. The remainders can only be `0`, `1`, or `2`, and the state transitions will allow us to build upon previously computed values to find the maximum sum.

1. **Dynamic Programming Array**: We create a `dp` array of size `3`, where `dp[i]` represents the maximum sum of elements that gives a remainder of `i` when divided by `3`.
2. **Iterate Through Elements**: For each number in the input array, we calculate its contribution to potential new sums and update our `dp` array accordingly.
3. **State Transition**: For each current sum stored in `dp`, we consider adding the current number and calculate the new remainder. We update the `dp` array based on the maximum sums we can achieve.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
```
- **Line 1-3**: The `Solution` class is defined with a public member function `maxSumDivThree`, which accepts a vector of integers, `nums`, as an argument.

```cpp
        int n = nums.size();
        vector<int> dp(3, 0);
```
- **Line 4-5**: The size of the input array `nums` is stored in `n`. We then initialize a dynamic programming vector `dp` of size `3`, with all values set to `0`. This vector will store the maximum sums for remainders `0`, `1`, and `2`.

```cpp
        for(int a : nums)
```
- **Line 6**: We start a loop that iterates over each element `a` in the `nums` array.

```cpp
        for(int i : vector<int>(dp))
```
- **Line 7**: A nested loop begins, where we create a copy of the current state of `dp` to avoid modifying it while iterating. This is crucial because we want to ensure that each number is processed based on the previous state of `dp`.

```cpp
        dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
```
- **Line 8**: For each value `i` from the copied `dp` array, we calculate the new remainder when adding the current element `a`. We update `dp` for that remainder with the maximum of the current value or the new sum `i + a`.

```cpp
        return dp[0];
    }
};
```
- **Line 9**: After processing all numbers in `nums`, we return `dp[0]`, which contains the maximum sum of the selected elements that is divisible by `3`.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this solution is \(O(n)\), where \(n\) is the number of elements in the `nums` array. This is because we iterate through the elements of `nums` once and update the `dp` array in constant time for each element.

2. **Space Complexity**:
   - The space complexity is \(O(1)\), as we only use a fixed-size array `dp` of length `3` to keep track of the maximum sums for each remainder.

### Conclusion
The `maxSumDivThree` function provides an efficient solution to the problem of finding the maximum sum of elements in an array that is divisible by `3`. By employing a dynamic programming approach, we can efficiently compute the necessary values while minimizing space usage. This method not only ensures optimal performance but also demonstrates the versatility of dynamic programming techniques in solving problems related to combinatorial selection and constraints.

In summary, this solution effectively leverages mathematical properties of remainders and dynamic programming principles, showcasing how to transform a seemingly complex problem into a manageable computation through clever use of state representation. The approach can be generalized to similar problems where sums need to meet specific divisibility or modularity conditions, making it a valuable technique in the algorithmic toolkit.

[`Link to LeetCode Lab`](https://leetcode.com/problems/greatest-sum-divisible-by-three/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
