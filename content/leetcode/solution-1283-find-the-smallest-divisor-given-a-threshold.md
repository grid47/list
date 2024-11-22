
+++
authors = ["grid47"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1283: Find the Smallest Divisor Given a Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KGlnb3yT8iY"
youtube_upload_date="2020-11-06"
youtube_thumbnail="https://i.ytimg.com/vi/KGlnb3yT8iY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, m , sum;
        while(left < right) {
            m = (left + right) / 2;
            sum = 0;
            for(int i: nums) sum += (i + m - 1)/m;
            if(sum > threshold) 
            left = m + 1;
            else right = m;
        }
        return left;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem at hand is to find the smallest divisor for an array of integers such that when each element of the array is divided by this divisor and rounded up to the nearest integer, the sum of the results does not exceed a given threshold. 

For example, if we have an array `nums = [1, 2, 5, 9]` and a threshold of `6`, the smallest divisor that would allow the sum of the results of `ceil(nums[i] / divisor)` to be `<= 6` needs to be determined. In this case, the smallest divisor that achieves this would be `5`, as it yields `1 + 1 + 1 + 2 = 5`, which is within the threshold.

### Approach
To efficiently find the smallest divisor, we can use a binary search strategy. The search space for the divisor ranges from `1` to the maximum possible value (in this case, `1e6`). We will iteratively narrow down this range based on whether the current divisor meets the condition of keeping the sum below or equal to the threshold.

1. Initialize the search range with `left` set to `1` and `right` set to `1e6`.
2. Perform a binary search:
   - Calculate the midpoint `m` of the current range.
   - Compute the sum of the quotients for the current divisor `m`.
   - If the sum exceeds the threshold, it means `m` is too small; adjust the search range to search for a larger divisor.
   - Otherwise, search for a smaller divisor.
3. The process continues until the left pointer equals the right pointer, which will indicate the smallest divisor found.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
```
- **Line 1-2**: We define the class `Solution` and the method `smallestDivisor` that takes a reference to a vector of integers `nums` and an integer `threshold` as input. The method returns the smallest divisor as an integer.

```cpp
        int left = 1, right = 1e6, m, sum;
```
- **Line 3**: We initialize:
  - `left` to `1` (the smallest possible divisor).
  - `right` to `1e6` (an arbitrary upper bound on the divisor).
  - `m` and `sum` for later use.

```cpp
        while(left < right) {
```
- **Line 4**: We start a loop that will continue until the `left` pointer is no longer less than the `right` pointer.

```cpp
            m = (left + right) / 2;
```
- **Line 5**: We compute the midpoint `m` of the current search range. This value represents the current candidate for the smallest divisor.

```cpp
            sum = 0;
```
- **Line 6**: We initialize `sum` to accumulate the results of the division.

```cpp
            for(int i: nums) sum += (i + m - 1)/m;
```
- **Line 7**: We iterate through each element `i` in `nums` and compute the ceiling of `i/m` using the expression `(i + m - 1) / m`. This works because adding `m - 1` ensures that any remainder will round up to the next integer. We accumulate this in `sum`.

```cpp
            if(sum > threshold) 
                left = m + 1;
```
- **Line 8-9**: After calculating the sum, we check if it exceeds the threshold. If it does, it means `m` is too small, so we adjust the left pointer to `m + 1` to search for a larger divisor.

```cpp
            else 
                right = m;
```
- **Line 10-11**: If the sum does not exceed the threshold, we know that `m` might be a valid answer, so we adjust the right pointer to `m` to continue searching for a potentially smaller valid divisor.

```cpp
        }
        return left;
    }
};
```
- **Line 12-14**: The loop continues until `left` equals `right`, at which point `left` will be the smallest divisor that meets the conditions. We return `left` as the final result.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this algorithm is \(O(n \log m)\), where \(n\) is the number of elements in the array `nums`, and \(m\) is the maximum value of the divisor. The logarithmic factor arises from the binary search across the divisor range, while the linear factor comes from summing the elements in the array for each midpoint evaluation.

2. **Space Complexity**:
   - The space complexity is \(O(1)\) because we are using a constant amount of extra space regardless of the input size. The storage used for variables such as `left`, `right`, `m`, and `sum` does not depend on the size of the input.

### Conclusion
The `smallestDivisor` function efficiently computes the smallest divisor for an array of integers, ensuring that the sum of the divided results remains below a specified threshold. By employing a binary search strategy, the solution narrows down the search space systematically, yielding a time-efficient algorithm suitable for larger inputs. This explanation serves to clarify the implementation details, functionality, and performance of the code, providing insights into effective algorithm design and optimization techniques.

This structured breakdown enhances understanding of both the algorithm's logic and the broader context of problem-solving in programming, encouraging deeper exploration of binary search applications in various scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/)

---
{{< youtube KGlnb3yT8iY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
