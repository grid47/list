
+++
authors = ["grid47"]
title = "Leetcode 2221: Find Triangular Sum of an Array"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2221: Find Triangular Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "K-IoQp07D8c"
youtube_upload_date="2022-04-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K-IoQp07D8c/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);        
        for(int i = n; i > 1; i--) {
            int k = i - 1;
            for(int j = k - 1; j >= 0; j--)
                arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
            
            nums = arr;
        }
        
        return nums[0];
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem requires computing a triangular sum from an array of integers. The triangular sum is calculated by performing repeated reductions on the array. At each step, the adjacent numbers in the array are summed, and the sum is taken modulo 10. This process continues until only a single number remains in the array, and this number is returned as the result.

Given an array of integers `nums`, the goal is to find the final result after repeatedly applying the reduction process.

### Approach
The approach is based on progressively reducing the array through modulo-based operations. At each reduction step:
1. **Adjacent sums** are calculated using the current values in the array.
2. Each new value is taken modulo 10 to keep the sum within a valid digit range.
3. The reduced array is then used in the next iteration, reducing it further until only one element is left.

This problem requires iterating through the array multiple times, each time performing a sum and applying modulo 10, until the array is reduced to a single element.

### Code Breakdown (Step by Step)

#### Step 1: Initialization
```cpp
int n = nums.size();
vector<int> arr(n, 0);        
```
- We first initialize `n`, which holds the size of the `nums` array.
- An auxiliary array `arr` of the same size is created, initialized to zero. This array will be used to store the intermediate results during each reduction step.

#### Step 2: Outer Loop – Repeated Reduction
```cpp
for(int i = n; i > 1; i--) {
    int k = i - 1;
    for(int j = k - 1; j >= 0; j--)
        arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
    
    nums = arr;
}
```
- The outer loop runs as long as the size of the array is greater than 1. The loop starts at `n` and reduces down to 2.
- Within each iteration, we initialize `k` as `i - 1`, which represents the last index of the current array under consideration.
- The inner loop iterates from index `k - 1` down to 0, summing each pair of adjacent elements in the `nums` array, taking the sum modulo 10:
  - `nums[j] % 10` and `nums[j + 1] % 10` ensure each number is reduced to a single digit before adding them.
  - The sum is then taken modulo 10 to ensure the result stays within the range of a single digit.
- After the inner loop completes, the `arr` array contains the updated values for the next iteration, and `nums` is updated to `arr` for the subsequent step.

#### Step 3: Final Return
```cpp
return nums[0];
```
- Once the array has been reduced to a single element, the first element `nums[0]` is returned as the final result.

### Complexity

#### Time Complexity:
- The time complexity of this algorithm is O(n²), where `n` is the size of the `nums` array. This is because for each iteration (starting with `n` elements), we perform a pass through the array (decreasing the size of the array each time).
- The outer loop runs `n - 1` times, and for each iteration of the outer loop, the inner loop iterates through the current array size, resulting in a total of approximately `n(n - 1) / 2` operations.

#### Space Complexity:
- The space complexity is O(n) because we use an auxiliary array `arr` to store intermediate results, which has the same size as the input array `nums`.

### Conclusion

This code efficiently computes the triangular sum of a list of integers by iteratively reducing the array with modulo-based sums. The reduction process involves multiple passes over the array, where adjacent elements are summed, reduced modulo 10, and used in the next iteration. The time complexity is quadratic (O(n²)), making this solution suitable for moderately sized arrays, but potentially inefficient for very large arrays. The algorithm’s space complexity is O(n), as it requires storing the intermediate results in a new array. The approach demonstrates an elegant and structured method for solving problems involving reductions and modulo operations in sequences.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

---
{{< youtube K-IoQp07D8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
