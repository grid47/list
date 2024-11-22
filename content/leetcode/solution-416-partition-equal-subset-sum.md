
+++
authors = ["grid47"]
title = "Leetcode 416: Partition Equal Subset Sum"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 416: Partition Equal Subset Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp"
youtube = "ZFuagJEpeEU"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/ZFuagJEpeEU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/416.webp" 
    alt="A set of numbers with glowing partitions, showing how they can be divided into equal subsets."
    caption="Solution to LeetCode 416: Partition Equal Subset Sum Problem"
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
    vector<int> nums;
    int memo[201][10001];
    
    bool dp(int idx, int sum) {
        
        if(idx == nums.size()) return sum == 0;
        
        if(memo[idx][sum] != -1) return memo[idx][sum];
        
        bool res = dp(idx + 1, sum);
        
        if(sum >= nums[idx])
            res |= dp(idx + 1, sum - nums[idx]);
        
        return memo[idx][sum] = res;
        
    }
    
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        int sum = 0;
        for(int x: nums)
            sum += x;
        
        if(sum & 1) return false;
        
        sum = sum / 2;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, sum);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine if a given array of integers can be partitioned into two subsets such that the sum of the elements in both subsets is the same. This is a classical problem known as the **Partition Problem**. 

Given a list `nums` of integers, we are required to return `true` if it is possible to partition the list into two subsets with equal sum, and `false` otherwise.

For example:
- **Input:** `nums = [1, 5, 11, 5]`
- **Output:** `true`
- **Explanation:** The array can be partitioned into two subsets: `[1, 5, 5]` and `[11]`, both having a sum of `11`.

- **Input:** `nums = [1, 2, 3, 5]`
- **Output:** `false`
- **Explanation:** The array cannot be partitioned into two subsets with equal sum.

### Approach

To solve this problem, we can utilize **dynamic programming (DP)**, which is a typical approach for subset sum problems. The key idea is to reduce the problem to determining if there is a subset of the array that sums up to half of the total sum of the array.

1. **Sum Calculation**:
   - If the sum of all elements in the array is odd, it's impossible to split the array into two equal subsets, so we can immediately return `false`.
   - If the sum is even, we aim to find a subset whose sum equals half of the total sum, i.e., `sum / 2`.

2. **Subset Sum Problem**:
   - This problem can be reduced to a **0/1 knapsack problem**, where we try to determine if we can form a subset with a specific sum (which is `sum / 2`).
   - We will use dynamic programming to check whether it's possible to achieve this sum.

3. **Memoization**:
   - To efficiently calculate the solution, we can use a recursive approach with **memoization** to store the results of overlapping subproblems. This avoids recomputing the same results multiple times.

### Code Breakdown (Step by Step)

#### Step 1: Initial Setup

```cpp
vector<int> nums;
int memo[201][10001];
```
- The array `nums` stores the input numbers.
- The 2D array `memo` is used to store the results of the subproblems. We initialize `memo` with `-1` to indicate that a result has not been computed for a particular subproblem.

#### Step 2: Recursive Function with Memoization

```cpp
bool dp(int idx, int sum) {
    if(idx == nums.size()) return sum == 0;
    if(memo[idx][sum] != -1) return memo[idx][sum];
    
    bool res = dp(idx + 1, sum);
    if(sum >= nums[idx]) res |= dp(idx + 1, sum - nums[idx]);
    
    return memo[idx][sum] = res;
}
```
- The function `dp(idx, sum)` is a recursive function that checks if a subset with the specified sum can be formed from the first `idx` elements of the array.
- **Base Case**: If we have processed all elements (`idx == nums.size()`), we return `true` if the `sum` is `0` (meaning we have found a valid subset), and `false` otherwise.
- **Memoization**: If the result for the subproblem `dp(idx, sum)` has already been computed (i.e., `memo[idx][sum] != -1`), we simply return the stored result.
- **Recursive Case**:
  - We first try to exclude the current element `nums[idx]` and check if we can achieve the target sum from the remaining elements: `dp(idx + 1, sum)`.
  - If the current element can be included (i.e., `sum >= nums[idx]`), we also try including it and check if we can achieve the remaining sum `sum - nums[idx]` from the rest of the elements.
- Finally, the result is stored in `memo[idx][sum]` to avoid redundant calculations in future calls.

#### Step 3: Checking for Partition

```cpp
bool canPartition(vector<int>& nums) {
    this->nums = nums;
    int sum = 0;
    for(int x: nums) sum += x;
    if(sum & 1) return false;
    sum = sum / 2;
    memset(memo, -1, sizeof(memo));
    return dp(0, sum);
}
```
- The `canPartition` function is the main entry point of the solution.
- First, we calculate the total sum of the elements in the array.
- If the sum is odd (`sum & 1`), we return `false` immediately because it’s not possible to split the array into two subsets with equal sum.
- We then set `sum = sum / 2`, which is the target sum for the subset we need to find.
- We initialize the `memo` array with `-1` using `memset` to reset it before starting the DP calculations.
- Finally, we call the `dp` function with the initial index `0` and the target sum.

### Complexity

#### Time Complexity:
- **Time Complexity of `dp`**: The function `dp(idx, sum)` is called with `idx` from `0` to `nums.size()` and `sum` from `0` to `sum / 2`. Hence, the number of unique subproblems is proportional to `n * (sum / 2)`, where `n` is the size of the array.
- Since each subproblem is solved at most once due to memoization, the overall time complexity is **O(n * sum)**, where `n` is the number of elements and `sum` is half of the total sum.

#### Space Complexity:
- **Space Complexity**: The space complexity is dominated by the memoization array, which is a 2D array with dimensions `[n][sum / 2]`. Thus, the space complexity is **O(n * sum)**, where `n` is the number of elements and `sum` is half of the total sum.

### Conclusion

The solution to the **Partition Problem** efficiently uses **dynamic programming** with **memoization** to determine if a subset with sum equal to half of the total sum can be found in the array. This approach ensures that we only solve each subproblem once, improving performance compared to a naive recursive approach. With a time complexity of **O(n * sum)** and a space complexity of **O(n * sum)**, this solution is both time-efficient and space-efficient, making it suitable for large inputs. The use of memoization significantly reduces redundant calculations, allowing the algorithm to solve the problem optimally.

[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-equal-subset-sum/description/)

---
{{< youtube ZFuagJEpeEU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
