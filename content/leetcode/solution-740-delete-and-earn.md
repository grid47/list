
+++
authors = ["grid47"]
title = "Leetcode 740: Delete and Earn"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 740: Delete and Earn in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp"
youtube = "MnbTKT4-KLc"
youtube_upload_date="2023-07-05"
youtube_thumbnail="https://i.ytimg.com/vi/MnbTKT4-KLc/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/740.webp" 
    alt="A series of numbers where the optimal strategy to delete and earn is highlighted, glowing softly as the calculation is made"
    caption="Solution to LeetCode 740: Delete and Earn Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> val(n + 1, 0);
        vector<int> dp (n + 1, 0);
        
        for(int num : nums)
          val[num] += num;
        
        dp[0] = 0;
        dp[1] = val[0];
        for(int i = 1; i < n; i++)
        dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
        
        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the maximum points we can earn from a list of integers by performing the following operations:
- If we select an integer `num`, we earn `num * frequency of num` points and must delete all instances of `num` and `num+1` from the list.
- We need to maximize the total points we can earn by performing this operation.

For example, if `nums = [3, 4, 2]`, we can select `3`, earn `3 * 1 = 3` points, then delete all instances of `3` and `4`. The remaining number is `2`, so the total points we would earn would be `3 + 2 = 5`.

### Approach

To solve this problem efficiently, we can use a dynamic programming approach. The solution can be broken down into these key steps:

1. **Frequency Calculation**: First, calculate the total value we can earn by selecting each number from the input array. This can be done by creating an array `val` where `val[i]` represents the total value (sum of all `i`'s) for the number `i`.

2. **Dynamic Programming Array (dp)**: After calculating the values, we define a dynamic programming (DP) array `dp` where `dp[i]` represents the maximum points we can earn from the subarray of numbers from `0` to `i`. The idea is to either:
   - **Skip** the current number `i`, in which case the maximum points would be the same as `dp[i-1]`.
   - **Select** the current number `i`, in which case we add `val[i]` (points earned from `i`) to the maximum points from `dp[i-2]` (because selecting `i` means we must skip `i-1`).

3. **Recursive Transition**: The recurrence relation to fill the DP array is:
   - `dp[i] = max(dp[i-1], dp[i-2] + val[i])`
   This means for each number `i`, we either skip it or select it.

4. **Final Result**: After filling the DP array, the last element `dp[n]` will contain the maximum points that can be earned.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Arrays
We initialize two arrays:
- `val`: to store the total value for each number in the range `[0, 10000]`. The index `i` in this array will store the sum of all occurrences of the number `i` in the input list.
- `dp`: to store the maximum points that can be earned up to the number `i`. The size of `dp` is `10001`, corresponding to all possible values from `0` to `10000`.

```cpp
int n = 10001;
vector<int> val(n + 1, 0);  // To store total value for each number
vector<int> dp(n + 1, 0);   // To store maximum points up to each number
```

#### Step 2: Populate `val` Array
We loop through the input array `nums` and add the values to the `val` array. This way, `val[i]` will hold the total sum of points we can earn by selecting the number `i` (i.e., `i * frequency of i`).

```cpp
for(int num : nums)
  val[num] += num;
```

#### Step 3: Base Cases for DP
We set up the base cases for the dynamic programming array `dp`:
- `dp[0] = 0`: No points can be earned from number `0`.
- `dp[1] = val[1]`: The only option is to pick number `1` if it exists in the input.

```cpp
dp[0] = 0;
dp[1] = val[0];
```

#### Step 4: Fill DP Array
Next, we use a loop to fill the DP array using the recurrence relation. For each number `i` from `2` to `10000`, we either skip it or select it. We update `dp[i]` to the maximum of skipping `i` (i.e., `dp[i-1]`) or selecting `i` (i.e., `dp[i-2] + val[i]`).

```cpp
for(int i = 1; i < n; i++)
  dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
```

#### Step 5: Return the Final Result
Finally, we return `dp[n]`, which contains the maximum points we can earn.

```cpp
return dp[n];
```

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the size of the input array `nums`. We traverse through the `nums` array to calculate the values and then compute the DP array in a single pass.

#### Space Complexity:
- **O(n)**, where `n` is the size of the range of numbers. We use two arrays, `val` and `dp`, both of size `10001` (due to the range of possible values). Therefore, the space complexity is linear with respect to the range of numbers in the input.

### Conclusion

The problem of maximizing the points in the "delete and earn" scenario can be efficiently solved using a dynamic programming approach. By calculating the total value for each number and using a DP array to track the maximum points that can be earned, we can ensure that we maximize the score while adhering to the deletion constraints. The approach leverages recurrence relations to decide whether to skip or select a number, ultimately providing an optimal solution with a time complexity of **O(n)**.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-and-earn/description/)

---
{{< youtube MnbTKT4-KLc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
