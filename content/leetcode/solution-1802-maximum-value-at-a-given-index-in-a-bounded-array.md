
+++
authors = ["grid47"]
title = "Leetcode 1802: Maximum Value at a Given Index in a Bounded Array"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1802: Maximum Value at a Given Index in a Bounded Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "o3H1ccp2ckc"
youtube_upload_date="2021-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/o3H1ccp2ckc/maxresdefault.jpg"
comments = true
+++



---
You are tasked with constructing an array `nums` of length `n` such that: all elements are positive integers, the difference between adjacent elements is at most 1, the sum of elements does not exceed `maxSum`, and the value at index `index` is maximized. Return the value at `index` in the array `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: `n`, `index`, and `maxSum`. These are the length of the array, the index whose value is to be maximized, and the maximum allowable sum of all elements in the array, respectively.
- **Example:** `n = 5, index = 2, maxSum = 10`
- **Constraints:**
	- 1 <= n <= maxSum <= 10^9
	- 0 <= index < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the value at the index `index` in the array `nums` after constructing it under the given conditions.
- **Example:** `Output: 3`
- **Constraints:**
	- The value at `index` must be maximized while ensuring that the sum of the elements in the array does not exceed `maxSum`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Construct the array such that the value at `index` is maximized, while adhering to the constraints of adjacent element differences and sum limits.

- Use binary search to determine the maximum possible value for `nums[index]`.
- For each candidate value, calculate if the sum of the array can remain within `maxSum` while keeping the difference between adjacent elements at most 1.
{{< dots >}}
### Problem Assumptions ✅
- We assume the values are large enough to require an efficient solution using binary search.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, index = 2, maxSum = 10`  \
  **Explanation:** In this case, the array `[1, 2, 3, 2, 1]` satisfies all conditions, and the value at index 2 is maximized as 3, with a total sum of 10.

{{< dots >}}
## Approach 🚀
The approach uses binary search to determine the maximum possible value for the element at `index`, checking if the sum of the array remains within `maxSum`.

### Initial Thoughts 💭
- The problem involves finding the maximum possible value at a specific index in an array, while satisfying sum and adjacent element difference constraints.
- Binary search is the most efficient method to maximize the value at the index since it allows us to narrow down the possible values for `nums[index]`.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since `n` is always at least 1.
- For large values of `n` and `maxSum`, binary search ensures the solution runs efficiently even when the input values approach their upper bounds.
- Consider the case where `index` is at either end of the array, or when `n` is equal to `maxSum`.
- Ensure the solution efficiently handles the maximum constraints.
{{< dots >}}
## Code 💻
```cpp
bool can(long long pk, long long n, long long i, long long sum) {
    sum -= n;
    long j = n - i - 1;
    
long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
    
    return sum - need >= 0;
}

int maxValue(int n, int index, int mx) {
    
    int ans = 0, l = 0, r = mx;
    
    while(l <= r) {
        long mid = l + (r - l + 1) / 2;
        // cout << mid << " ";
        if(can(mid, n, index, mx)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    
    return ans + 1;
}
```

This code defines two main functions. The `can` function checks if a certain value can be achieved based on the input parameters. The `maxValue` function utilizes a binary search algorithm to find the maximum value that can be achieved under given constraints.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool can(long long pk, long long n, long long i, long long sum) {
	```
	Define the 'can' function which takes parameters pk, n, i, and sum to check if a certain value can be achieved based on the constraints.

2. **Mathematical Operations**
	```cpp
	    sum -= n;
	```
	Adjust the sum by subtracting the total number of elements.

3. **Variable Initialization**
	```cpp
	    long j = n - i - 1;
	```
	Initialize the variable 'j' to represent the index of the second element in the range.

4. **Mathematical Operations**
	```cpp
	    
	```
	Blank line for separation.

5. **Mathematical Operations**
	```cpp
	long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
	```
	Calculate the amount needed based on the value of pk and the indices i and j.

6. **Return**
	```cpp
	    return sum - need >= 0;
	```
	Return whether the remaining sum is greater than or equal to the calculated need.

7. **Function Definition**
	```cpp
	int maxValue(int n, int index, int mx) {
	```
	Define the 'maxValue' function which implements a binary search to find the maximum value.

8. **Variable Initialization**
	```cpp
	    int ans = 0, l = 0, r = mx;
	```
	Initialize variables for binary search: ans (answer), l (lower bound), and r (upper bound).

9. **Loop and Recursion**
	```cpp
	    while(l <= r) {
	```
	Start the binary search loop.

10. **Mathematical Operations**
	```cpp
	        long mid = l + (r - l + 1) / 2;
	```
	Calculate the midpoint for the binary search.

11. **Flow Control**
	```cpp
	        if(can(mid, n, index, mx)) {
	```
	If the 'can' function returns true for the current mid value, adjust the binary search bounds.

12. **Variable Initialization**
	```cpp
	            ans = mid;
	```
	Update the answer with the current value of mid.

13. **Mathematical Operations**
	```cpp
	            l = mid + 1;
	```
	Move the lower bound up to search the higher range.

14. **Flow Control**
	```cpp
	        } else r = mid - 1;
	```
	Otherwise, move the upper bound down to search the lower range.

15. **Return**
	```cpp
	    return ans + 1;
	```
	Return the final answer, incremented by 1 to match the problem's requirements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(maxSum))
- **Average Case:** O(log(maxSum))
- **Worst Case:** O(log(maxSum))

The binary search over the possible values for `nums[index]` results in a time complexity of O(log(maxSum)).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution only requires a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/)

---
{{< youtube o3H1ccp2ckc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
