
+++
authors = ["grid47"]
title = "Leetcode 698: Partition to K Equal Sum Subsets"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 698: Partition to K Equal Sum Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Memoization","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp"
youtube = "mBk4I0X46oI"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi/mBk4I0X46oI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp" 
    alt="A set of numbers where they are partitioned into equal sum subsets, with each valid partition softly glowing."
    caption="Solution to LeetCode 698: Partition to K Equal Sum Subsets Problem"
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
        bool canPartitionKSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;
        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2) return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement:
In this problem, we are given a collection of integers, and our goal is to determine if we can partition the array into `K` subsets, where each subset has the same sum. This is a classical "Partition Problem" often referred to as **K-Partition Problem** or **K-Subset Partition Problem**. Specifically, the problem asks if it is possible to divide the array such that the sum of the elements in each of the `K` subsets is equal.

### Approach:
To solve this problem, we can use a **backtracking** approach, which is a depth-first search (DFS) approach that explores all possibilities of partitioning the array into subsets. The key steps involved in the solution are:

1. **Initial Check**:
   - If `K` equals `1`, then the array can always be partitioned into one subset (the entire array), so we return `true`.
   - If the size of the array `N` is less than `K`, then it's impossible to partition the array into `K` subsets, so we return `false`.
   - If the sum of all the elements in the array isn't divisible by `K`, then it's impossible to partition them equally into `K` subsets. In this case, we return `false`.

2. **Subset Sum Calculation**:
   - Calculate the total sum of all the elements in the array and check if it's divisible by `K`.
   - If it is, each subset must have a sum equal to `total_sum / K`.
   - If not, it's impossible to partition the array into `K` equal-sum subsets.

3. **Backtracking**:
   - Use a backtracking approach to try forming the subsets.
   - Start placing elements into the subsets, ensuring that no subset exceeds the required sum.
   - Each time we fill a subset up to the required sum, move on to the next subset.
   - If we successfully place all elements into `K` subsets, return `true`.
   - If no valid partitioning is found, return `false`.

4. **Tracking Subset Construction**:
   - Use an array `subsetSum[]` to store the current sum of each subset.
   - Use a `taken[]` boolean array to track which elements have already been used in the subsets.

### Code Breakdown (Step by Step):

#### 1. **Main Function (`canPartitionKSubsets`)**:
```cpp
bool canPartitionKSubsets(vector<int>& nums, int K) {
    int N = nums.size();
    if (K == 1) return true;
    if (N < K) return false;
    int sum = 0;
    for (int i = 0; i < N; i++) sum += nums[i];
    if (sum % K != 0) return false;

    int subset = sum / K;
    int subsetSum[K];
    bool taken[N];

    for (int i = 0; i < K; i++) subsetSum[i] = 0;
    for (int i = 0; i < N; i++) taken[i] = false;

    subsetSum[0] = nums[N - 1];
    taken[N - 1] = true;

    return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
}
```

- **Initial checks**: The function first handles the base cases:
  - If `K == 1`, we can always partition the array into one subset.
  - If `N < K`, it is impossible to partition the array into `K` subsets.
  - If the sum of all elements in the array isn't divisible by `K`, return `false`.

- **Partition Setup**: 
  - We calculate the target sum for each subset as `sum / K`.
  - The `subsetSum[]` array keeps track of the sum of the current elements placed in each subset.
  - The `taken[]` array keeps track of which elements are already used.

- **Initial Setup**:
  - The last element of the array is placed in the first subset initially to kickstart the backtracking process.

- **Recursive Backtracking Call**:
  - The function calls the helper function `canPartitionKSubsets()` to start the process of partitioning the elements into subsets.

#### 2. **Recursive Helper Function (`canPartitionKSubsets`)**:
```cpp
bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
    if (subsetSum[curIdx] == subset) {
        if (curIdx == K - 2) return true;
        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
    }

    for (int i = limitIdx; i >= 0; i--) {
        if (taken[i]) continue;
        int tmp = subsetSum[curIdx] + nums[i];

        if (tmp <= subset) {
            taken[i] = true;
            subsetSum[curIdx] += nums[i];
            bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= nums[i];
            if (nxt) return true;
        }
    }
    return false;
}
```

- **Recursive Base Case**: If a subset is filled (`subsetSum[curIdx] == subset`), we check if we are at the last subset. If we are, we have successfully partitioned the array into `K` subsets and return `true`. Otherwise, we move to the next subset and attempt to fill it.

- **Exploring All Possible Elements**: 
  - The function iterates over the remaining elements and tries to place each element in the current subset if it doesn't exceed the target subset sum.
  - For each element placed in a subset, the recursive function is called to attempt filling the next subset.
  - If placing an element leads to a valid configuration, it returns `true`. Otherwise, it backtracks by removing the element and trying the next possibility.

### Complexity:

#### Time Complexity:
- The time complexity of this solution is difficult to express precisely because it involves backtracking, which tries many combinations of subsets. The worst-case time complexity can be **O(2^N)** in the case where we try all combinations of elements for the `K` subsets. However, the solution benefits from pruning unnecessary branches through the use of the `taken[]` array and subset sum checks.

#### Space Complexity:
- The space complexity is **O(N + K)**:
  - `O(N)` space is used to store the `taken[]` array, which tracks whether each element has been used in the partition.
  - `O(K)` space is used to store the current sums of the `K` subsets in the `subsetSum[]` array.

### Conclusion:

This solution uses a **backtracking** approach to explore all possible ways of partitioning the array into `K` subsets with equal sums. By leveraging recursion and a greedy strategy to try placing elements in subsets, the algorithm attempts to fill the subsets while respecting the constraints. Although the problem can be computationally expensive for larger inputs due to the backtracking nature of the algorithm, it is a straightforward and effective approach for solving the **K-Subset Partition Problem**.

[`Link to LeetCode Lab`](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/)

---
{{< youtube mBk4I0X46oI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
