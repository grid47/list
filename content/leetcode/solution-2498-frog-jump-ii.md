
+++
authors = ["grid47"]
title = "Leetcode 2498: Frog Jump II"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2498: Frog Jump II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7zFq991SKgQ"
youtube_upload_date="2022-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/7zFq991SKgQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxJump(vector<int>& A) {
        int res = A[1] - A[0];
        int n = A.size();
        for(int i = 2; i < n; i++)
            res = max(res, A[i] - A[i - 2]);
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the maximum jump distance in a given list `A` of integers, where each integer represents a position on a line. The goal is to compute the maximum jump that can be made between any two positions, where the jump is defined as the absolute difference between two positions that are either directly adjacent or separated by one intermediate position.

The task is to return the maximum distance that can be jumped in such a manner, where you are allowed to skip one position between two jumps.

### Approach

To solve the problem, the approach is based on identifying the maximum jump that can be made between valid pairs of positions in the array. The key points are:
1. **Initial Jump**: The first jump is between the first and second positions, i.e., `A[1] - A[0]`.
2. **Subsequent Jumps**: For each subsequent position `i` (starting from index 2), we can calculate the distance between `A[i]` and `A[i-2]` (since skipping one position is allowed). This represents the largest possible jump to that position.
3. **Maximization**: The goal is to find the maximum value of all these jumps and return it.

### Code Breakdown (Step by Step)

#### Step 1: Initializing the Result Variable

```cpp
int res = A[1] - A[0];
```

The first step in the code initializes the result variable `res` to the difference between the first two positions, i.e., `A[1] - A[0]`. This is the first valid jump between the first and second positions in the list.

#### Step 2: Iterating Through the Array

```cpp
int n = A.size();
for(int i = 2; i < n; i++)
```

The loop begins at index 2 (the third element) and iterates over the array until the end. The loop aims to calculate the distance for every valid jump that skips one position and updates the `res` variable with the maximum distance found.

#### Step 3: Computing the Maximum Jump

```cpp
res = max(res, A[i] - A[i - 2]);
```

For each index `i`, the code computes the jump between the current position `A[i]` and the position two steps back, i.e., `A[i - 2]`. This ensures that only jumps that skip exactly one position are considered. The result `res` is updated with the maximum of the current value of `res` and the new calculated jump distance.

#### Step 4: Return the Maximum Jump

```cpp
return res;
```

After iterating over all possible valid jumps, the function returns the value of `res`, which holds the maximum jump found.

### Complexity Analysis

#### Time Complexity:
1. **Loop Over the Array**: The function iterates through the array starting from index 2, performing constant-time operations within each iteration. This results in a linear time complexity of **O(n)**, where `n` is the size of the array `A`.
2. The only operations performed inside the loop are the calculation of the difference and a comparison to update the maximum jump, both of which take constant time **O(1)**.

Thus, the total time complexity of the algorithm is **O(n)**, where `n` is the number of elements in the array.

#### Space Complexity:
1. **Space Usage**: The function uses a constant amount of extra space for variables like `res` and `n`. There are no additional data structures used that depend on the size of the input array.
   
Thus, the space complexity is **O(1)**, as only a fixed amount of space is used.

### Conclusion

This solution efficiently computes the maximum jump that can be made between any two positions in the array, where the jump can skip one intermediate position. The approach uses a greedy strategy to maximize the jump at each step by calculating the distance between every pair of valid positions. The time complexity is **O(n)**, which makes this solution optimal for large inputs.

- **Time Complexity**: **O(n)**, where `n` is the number of elements in the input array `A`.
- **Space Complexity**: **O(1)**, as the solution uses only a constant amount of space.

This makes the solution both time-efficient and space-efficient, ideal for solving the problem within constraints typically found in competitive programming scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/frog-jump-ii/description/)

---
{{< youtube 7zFq991SKgQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
