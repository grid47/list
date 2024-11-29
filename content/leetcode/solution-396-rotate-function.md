
+++
authors = ["grid47"]
title = "Leetcode 396: Rotate Function"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 396: Rotate Function in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp"
youtube = "GzBK8dxblaw"
youtube_upload_date="2024-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/GzBK8dxblaw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/396.webp" 
    alt="A glowing array where elements rotate, with each rotation step softly highlighted."
    caption="Solution to LeetCode 396: Rotate Function Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array `nums` of length `n`. For each rotation `k`, we define a function `F(k)` which is calculated as: F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n-1) * arrk[n-1]. The goal is to return the maximum value of `F(k)` for all possible `k` in the range from `0` to `n-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers `nums` and an integer `n` representing the length of the array.
- **Example:** `Input: nums = [1, 2, 3, 4]`
- **Constraints:**
	- 1 <= n <= 10^5
	- -100 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum value of F(k) for all possible values of `k`.
- **Example:** `Output: 20`
- **Constraints:**
	- The solution must return the maximum value of F(k) among all rotations of the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute F(k) for all `k` and return the maximum value.

- Compute the sum of the array and the initial value of F(0).
- Use a rolling approach to compute subsequent F(k) values by adjusting the previous F(k-1).
- Return the maximum value of F(k).
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` is a valid integer array of length `n`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 2, 3, 4]`  \
  **Explanation:** We calculate F(k) for all rotations: F(0), F(1), F(2), and F(3). The maximum value is 20.

- **Input:** `Input: nums = [100]`  \
  **Explanation:** With a single element, there is only one possible rotation, and the value of F(k) is 0.

{{< dots >}}
## Approach 🚀
The approach uses an efficient way to compute F(k) using a rolling sum, so that we do not need to recompute the entire sum for each rotation.

### Initial Thoughts 💭
- The problem involves rotating the array and computing a function based on the rotated array.
- We need an optimized solution to avoid recalculating the entire function for every rotation.
{{< dots >}}
### Edge Cases 🌐
- The input array `nums` will not be empty as it has a minimum length of 1.
- Ensure the solution handles input arrays with lengths up to 10^5 efficiently.
- Handle cases where the array has only one element or all elements are the same.
- Handle edge cases such as small or large values in the array and rotations for arrays of size 1.
{{< dots >}}
## Code 💻
```cpp
int maxRotateFunction(vector<int>& nums) {
    long sum = 0, fn = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        fn += i * nums[i];
    }

    long l = 1, r;
    long newfn = fn;

    while(l < n) {
        r = l + n - 1;
        long removed = (l - 1) *nums[l -1];
        long added = r * nums[r % n];

        newfn = newfn - removed + added - sum;

        fn = max(fn, newfn);
        l++;
    }
    return fn;
}
```

The function `maxRotateFunction` calculates the maximum value of the rotate function for a given array `nums`. The approach calculates the initial sum and the first value of the function, then iteratively adjusts the value using an optimized method instead of recalculating the function for each rotation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxRotateFunction(vector<int>& nums) {
	```
	The function `maxRotateFunction` takes a vector of integers `nums` and returns the maximum possible value of the rotate function.

2. **Variable Initialization**
	```cpp
	    long sum = 0, fn = 0;
	```
	Two variables are initialized: `sum` will store the sum of all elements in the array, and `fn` will store the initial value of the rotate function.

3. **Array Length**
	```cpp
	    int n = nums.size();
	```
	The variable `n` stores the size of the `nums` array.

4. **Initial Calculation**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop iterates over each element of the array to compute the initial `sum` and `fn`.

5. **Sum Calculation**
	```cpp
	        sum += nums[i];
	```
	The sum of all elements in the array is computed.

6. **Initial Function Calculation**
	```cpp
	        fn += i * nums[i];
	```
	The initial value of the rotate function is calculated by multiplying each element by its index and adding it to `fn`.

7. **Variable Initialization**
	```cpp
	    long l = 1, r;
	```
	Two variables, `l` and `r`, are initialized. `l` will track the left index for the next rotation, and `r` will be used for the right index.

8. **Function Update**
	```cpp
	    long newfn = fn;
	```
	A new variable `newfn` is initialized to store the updated value of the rotate function during each iteration.

9. **Rotation Loop**
	```cpp
	    while(l < n) {
	```
	The loop continues as long as `l` is less than the size of the array, ensuring each rotation is processed.

10. **Right Index Calculation**
	```cpp
	        r = l + n - 1;
	```
	The right index `r` is calculated based on `l` and the size of the array.

11. **Element Removal**
	```cpp
	        long removed = (l - 1) *nums[l -1];
	```
	The value of the element at `l - 1` is removed from the calculation, as it is no longer part of the rotated array.

12. **Element Addition**
	```cpp
	        long added = r * nums[r % n];
	```
	The value of the element at index `r % n` is added to the calculation.

13. **Function Update**
	```cpp
	        newfn = newfn - removed + added - sum;
	```
	The value of `newfn` is updated by removing the contribution of the previous element and adding the contribution of the new element.

14. **Max Function Update**
	```cpp
	        fn = max(fn, newfn);
	```
	The value of `fn` is updated to be the maximum of its current value and the updated `newfn`.

15. **Index Update**
	```cpp
	        l++;
	```
	The left index `l` is incremented to move to the next rotation.

16. **Final Result**
	```cpp
	    return fn;
	```
	The function returns the maximum value of the rotate function after all rotations are processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution runs in linear time O(n) because we only need to compute the sum and adjust the function in each step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a few variables to keep track of the sum and function values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotate-function/description/)

---
{{< youtube GzBK8dxblaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
