
+++
authors = ["grid47"]
title = "Leetcode 377: Combination Sum IV"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 377: Combination Sum IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/377.webp"
youtube = "hg_U5GVEM-k"
youtube_upload_date="2023-07-06"
youtube_thumbnail="https://i.ytimg.com/vi/hg_U5GVEM-k/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/377.webp" 
    alt="A glowing set of numbers forming different combinations to meet the target sum, each combination softly glowing."
    caption="Solution to LeetCode 377: Combination Sum IV Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> mem;
public:
    int combinationSum4(vector<int>& nums, int target) {
        mem.resize(target + 1, -1);
        return dp(nums, target);
    }
    
    int dp(vector<int>& nums, int left) {
        
        if(left == 0) return 1;
        if(left < 0) return 0;

        if(mem[left] != -1) return mem[left];

        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += dp(nums, left - nums[i]);

        return mem[left] = res;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The **Combination Sum IV** problem asks us to find how many ways we can combine numbers from a given array `nums` to sum up to a target number `target`. The twist? We can use each number in `nums` multiple times, and the order of the numbers in each combination matters.

For example, with `nums = [1, 2, 3]` and `target = 4`, the valid combinations are:
- `[1, 1, 1, 1]`
- `[1, 1, 2]`
- `[2, 2]`
- `[1, 3]`

So, there are **7** ways to make `4`!

---

### 🧠 Approach

To tackle this efficiently, we'll use **Dynamic Programming (DP)**, where we break the problem down into smaller subproblems. This approach allows us to reuse the results of previously solved subproblems, saving time and computational effort.

#### Key Idea:
We create a DP array that tells us how many ways we can form each target sum from `0` to the given `target`.

- **Base case**: There's exactly **1** way to make a target of `0`—by not choosing any numbers.
- For any other target, we consider each number in `nums` and recursively subtract it from the target, accumulating the number of ways we can form the remaining sum.

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initializing Memoization
```cpp
vector<int> mem;
mem.resize(target + 1, -1);
```
- We declare a memoization vector `mem` that will store the results for all subproblems. It’s initialized with `-1`, meaning no subproblem has been solved yet.

#### Step 2: The `combinationSum4` Function
```cpp
return dp(nums, target);
```
- The main function calls the helper function `dp` to calculate the number of ways to reach the target sum.

#### Step 3: The `dp` Function
```cpp
int dp(vector<int>& nums, int left) {
    if(left == 0) return 1;
    if(left < 0) return 0;
    if(mem[left] != -1) return mem[left];
```
- **Base cases**:
  - If `left == 0`, we've found a valid combination, so return `1`.
  - If `left < 0`, we've overshot the target, so return `0`.
- If we've already solved for this sum (i.e., `mem[left] != -1`), return the stored value to avoid redundant calculations.

```cpp
int res = 0;
for(int i = 0; i < nums.size(); i++)
    res += dp(nums, left - nums[i]);
```
- For each number in `nums`, subtract it from the target `left`, and recursively calculate the number of ways to reach the new target. We accumulate this count into `res`.

```cpp
return mem[left] = res;
```
- Once we've calculated the number of ways to form the target, store it in `mem[left]` to reuse it later.

#### Step 4: Returning the Result
Finally, the result is returned from `mem[target]`, which contains the number of ways to form the target sum using elements from `nums`.

---

### 📈 Complexity Analysis

#### Time Complexity
The time complexity is **O(target * n)**, where `n` is the size of the `nums` array and `target` is the target sum.

- For each target sum from `0` to `target`, we recursively check all the elements in `nums`, leading to a complexity of **O(n)** per target sum.
- Therefore, the total time complexity is **O(target * n)**.

#### Space Complexity
The space complexity is **O(target)**, as we only need to store the results for all subproblems from `0` to `target` in the memoization array `mem`.

- Additionally, the recursion call stack might use some space, but since we're using memoization, the total space complexity is **O(target)**.

---

### 🏁 Conclusion

By using **Dynamic Programming (DP)** with **Memoization**, we solve the **Combination Sum IV** problem efficiently! This approach ensures we don't repeatedly calculate the same subproblems, making it fast and optimal for larger inputs.

#### Quick Recap:
- **Time Complexity**: O(target * n)
- **Space Complexity**: O(target)
- **Efficient solution using DP and memoization**
- **Great for overlapping subproblems!**

With this method, we can confidently solve this problem and handle even bigger test cases with ease! Keep going—you've got this! 💪🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/combination-sum-iv/description/)

---
{{< youtube hg_U5GVEM-k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
