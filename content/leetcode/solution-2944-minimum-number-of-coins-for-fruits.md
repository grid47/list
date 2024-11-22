
+++
authors = ["grid47"]
title = "Leetcode 2944: Minimum Number of Coins for Fruits"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2944: Minimum Number of Coins for Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Queue","Heap (Priority Queue)","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_Zt6ADHF8nE"
youtube_upload_date="2023-11-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_Zt6ADHF8nE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCoins(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.front() + 1) * 2 < i + 1)
                q.pop_front();
            while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
                q.pop_back();
            q.push_back(i);
            dp[i + 1] = dp[q.front()] + A[q.front()];
        }
        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem is to determine the minimum number of coins needed to reach a particular amount. Given a list `A`, where each element represents a coin's value, the task is to find the minimum number of coins needed to achieve a sum represented by the elements of the list. The list may have values that can be reused multiple times to form combinations.

### Approach:
To solve this problem efficiently, we will use **dynamic programming** combined with a **sliding window approach** leveraging a deque (double-ended queue) for optimization. Here's the breakdown of the solution:

1. **Dynamic Programming (DP)**: We use an array `dp` where `dp[i]` represents the minimum sum of coins needed to form a sum of `i`. The value of `dp[i]` is computed based on previously computed values, ensuring that the minimum number of coins is used.

2. **Sliding Window**: To optimize the transition from one state to another, a sliding window is used. The deque helps in maintaining the valid window of states efficiently, ensuring that we are always considering the optimal solution.

3. **Transition**: The state transitions from `dp[i]` to `dp[i+1]` by considering the element `A[i]` and ensuring that the minimum number of coins is maintained through each iteration.

### Code Breakdown (Step by Step):

#### 1. **Initialize DP Array**:
The DP array `dp` is initialized to store the minimum number of coins required to achieve each value from 0 to `n`, where `n` is the size of the input list `A`. The deque `q` is used to keep track of the most promising candidates for the minimum coin calculations.

```cpp
int n = A.size();
vector<int> dp(n + 1, 0);
deque<int> q;
```

Here, `dp[i]` will eventually hold the minimum number of coins needed for `i`. We initialize `dp[0] = 0`, as zero coins are needed to achieve a sum of 0.

#### 2. **Iterate Over the List**:
We start iterating through the array `A`. For each index `i`, we adjust the sliding window by popping out elements from the deque that no longer form valid combinations (based on the condition `(q.front() + 1) * 2 < i + 1`).

```cpp
for (int i = 0; i < n; i++) {
    while (!q.empty() && (q.front() + 1) * 2 < i + 1)
        q.pop_front();
```
This ensures that the deque always contains the most recent valid indices that can contribute to the computation.

#### 3. **Maintaining the Deque**:
Next, we perform another while loop to maintain the deque such that the element in `dp[q.back()] + A[q.back()]` is greater than or equal to `dp[i] + A[i]`. This ensures that the deque holds the indices of the smallest values that can help form the current result.

```cpp
while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
    q.pop_back();
q.push_back(i);
```

We then push the current index `i` into the deque, ensuring that it is always in the correct order for future calculations.

#### 4. **Updating DP Array**:
Now, we update the `dp[i+1]` value by adding the coin at `q.front()` to the current result. This ensures that we are calculating the minimum number of coins required at each state.

```cpp
dp[i + 1] = dp[q.front()] + A[q.front()];
```

#### 5. **Return the Result**:
Finally, the answer to the problem is stored in `dp[n]`, which will contain the minimum number of coins needed for the sum represented by the list `A`.

```cpp
return dp[n];
```

### Complexity:

#### Time Complexity:
- **Main Iteration**: The outer loop iterates over the list `A`, which has a size of `n`. 
- **Deque Operations**: The operations on the deque (pop_front, pop_back, and push_back) are each \(O(1)\). In the worst case, each index of `A` is added and removed from the deque only once, meaning the total operations on the deque are linear with respect to `n`.

Thus, the overall time complexity is:
\[
O(n)
\]

#### Space Complexity:
- **DP Array**: The `dp` array has a size of \(n + 1\), which requires \(O(n)\) space.
- **Deque**: The deque stores indices of the elements of `A`, so it requires \(O(n)\) space in the worst case.

Therefore, the space complexity is:
\[
O(n)
\]

### Conclusion:
The solution efficiently computes the minimum number of coins needed to form a sum using a dynamic programming approach enhanced by a sliding window technique implemented with a deque. This reduces the time complexity from a naive \(O(n^2)\) solution to a more efficient \(O(n)\), making it suitable for larger inputs.

#### Key Insights:
- **Sliding Window**: The sliding window ensures that we only consider the most promising candidates for each state, reducing unnecessary calculations.
- **Deque for Efficiency**: The deque helps to maintain the optimal subproblem solutions and avoid redundant recalculations.
- **Dynamic Programming**: The DP approach ensures that we solve the problem optimally by building upon smaller subproblems.

This combination of dynamic programming with an efficient sliding window using a deque provides an elegant solution to this problem, improving both the time and space complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/)

---
{{< youtube _Zt6ADHF8nE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
