
+++
authors = ["grid47"]
title = "Leetcode 2256: Minimum Average Difference"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2256: Minimum Average Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rh8Mnj9Bd64"
youtube_upload_date="2023-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/rh8Mnj9Bd64/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        typedef long long ll;
        
        ll sum = 0;
        for(int a : nums) sum += a;

        ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
        ll l = 0, r = sum;
        for(int i = 0; i < n; i++) {
            int prv = res;
            l += nums[i];
            r -= nums[i];      
            la = l / (i + 1);
            ra = (i+1==n)?0:r / (n-(i+1));
            res = min(res, abs(la - ra));
            if(prv != res) ret = i;
        }
        return ret;            
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the index where the absolute difference between the average of the left part and the average of the right part of a list `nums` is minimized. Specifically, the left part consists of all elements before and including the given index, and the right part contains all the remaining elements. The goal is to return the index where the absolute difference between the averages of the two parts is the smallest.

For example:
- Given an array `nums = [2, 4, 1, 3, 5]`, the goal is to split the array at every index, compute the averages of the left and right parts, and return the index where the absolute difference between these averages is minimized.

### Approach

To solve this problem, we can break it down into the following steps:

1. **Compute the Total Sum of the Array**: We need to calculate the sum of all elements in the array, as this will help us efficiently compute the sum of the right part without iterating over the array multiple times.

2. **Sliding Window of Sums**: The key idea is to iterate through the array and compute the average of the left part (`l`) and the right part (`r`) at each index. The sum of the left part (`l`) can be easily calculated incrementally by adding elements from the start of the array. The sum of the right part (`r`) is the total sum minus the sum of the left part.

3. **Average Calculation**: Once we have the sum of both parts at each index, we can compute the average for each part:
   - Left average = sum of left part / size of left part
   - Right average = sum of right part / size of right part
   - If the right part is empty, the average is considered to be 0.

4. **Track the Minimum Difference**: For each index, we compute the absolute difference between the left and right averages. We keep track of the index where this difference is the smallest.

5. **Return the Index with Minimum Difference**: After iterating through the entire array, we return the index where the minimum difference was found.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
typedef long long ll;

ll sum = 0;
for(int a : nums) sum += a;
```

- We define `ll` as a typedef for `long long` to handle potentially large sums. 
- We initialize a variable `sum` and calculate the sum of all elements in `nums`. This will be used to compute the right sum without iterating multiple times.

#### Step 2: Initialize Variables for Tracking

```cpp
ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
ll l = 0, r = sum;
```

- `n` is the size of the array `nums`.
- `res` is initialized to `INT_MAX` and will store the minimum absolute difference found during the iteration.
- `ret` is initialized to `0` and will store the index where the minimum difference occurs.
- `la` and `ra` represent the left and right averages respectively.
- `l` is the running sum for the left part, initialized to `0`.
- `r` is initialized to `sum`, representing the sum of the right part (initially the entire array).

#### Step 3: Iterate Over the Array

```cpp
for(int i = 0; i < n; i++) {
    int prv = res;
    l += nums[i];
    r -= nums[i];      
    la = l / (i + 1);
    ra = (i + 1 == n) ? 0 : r / (n - (i + 1));
    res = min(res, abs(la - ra));
    if(prv != res) ret = i;
}
```

- We iterate over the array, starting from index `0` to `n-1`.
- `prv` stores the previous value of `res` to check if `res` changes in this iteration.
- We update the left sum `l` by adding `nums[i]` and update the right sum `r` by subtracting `nums[i]`.
- `la` is the left average calculated as the sum of the left part divided by the number of elements in the left part (i.e., `i + 1`).
- `ra` is the right average. If we are at the last index, the right part is empty, and we set `ra` to 0. Otherwise, we compute the right average as the sum of the right part divided by the number of elements in the right part (i.e., `n - (i + 1)`).
- We compute the absolute difference between the left and right averages and update `res` to store the minimum difference found.
- If the current `res` is different from `prv`, we update `ret` to the current index `i`.

#### Step 4: Return the Result

```cpp
return ret;
```

- After finishing the iteration, we return the index `ret`, which represents the index with the minimum absolute difference between the left and right averages.

### Complexity

#### Time Complexity

1. **Summing the Array**: The initial sum of all elements in the array takes \( O(n) \), where `n` is the size of the array.
2. **Iterating Through the Array**: The loop iterates over the array once, and within each iteration, we perform constant-time operations (such as updating sums and averages). This gives us a time complexity of \( O(n) \).

Thus, the overall time complexity of the solution is \( O(n) \), where `n` is the size of the input array `nums`.

#### Space Complexity

The space complexity of the solution is \( O(1) \) because we are using only a constant amount of extra space (for variables like `l`, `r`, `res`, `ret`, etc.), aside from the input array.

### Conclusion

This solution efficiently solves the problem by iterating through the array once and using cumulative sums to compute the left and right averages at each index. By leveraging the total sum of the array, we can calculate the right sum without iterating over the array multiple times. This approach ensures a linear time complexity, making it optimal for large inputs.

The key insight is using the total sum to dynamically update the right sum as we iterate, and keeping track of the left and right averages to find the index where the absolute difference between them is minimized.

This solution is both time-efficient (with \( O(n) \) complexity) and space-efficient (with \( O(1) \) space complexity), making it well-suited for handling large arrays within competitive programming constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-average-difference/description/)

---
{{< youtube rh8Mnj9Bd64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
