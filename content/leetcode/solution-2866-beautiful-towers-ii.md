
+++
authors = ["grid47"]
title = "Leetcode 2866: Beautiful Towers II"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2866: Beautiful Towers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HZVMmKR0jZw"
youtube_upload_date="2023-09-24"
youtube_thumbnail="https://i.ytimg.com/vi/HZVMmKR0jZw/maxresdefault.jpg"
comments = true
+++



---
You are given an array maxHeights of n integers. Your task is to build n towers in the coordinate line where the height of the i-th tower is between 1 and maxHeights[i]. The configuration is beautiful if the heights form a mountain array, where heights increase to a peak and then decrease afterward. Return the maximum possible sum of the heights of a beautiful tower configuration.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing the maximum heights of the towers. You need to find a configuration of towers where the heights form a mountain shape.
- **Example:** `maxHeights = [3, 5, 4, 1, 6]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= maxHeights[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of the heights of the towers in a valid mountain configuration.
- **Example:** `For input maxHeights = [3, 5, 4, 1, 6], the output is 14.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum sum of tower heights such that the arrangement forms a valid mountain shape.

- For each possible peak, calculate the sum of the heights of the non-decreasing and non-increasing parts of the mountain array.
- Iterate through the array to compute the possible configurations and find the one with the maximum sum.
{{< dots >}}
### Problem Assumptions ✅
- The array will not be empty and will contain at least one tower.
{{< dots >}}
## Examples 🧩
- **Input:** `For input maxHeights = [3, 5, 4, 1, 6], the output is 14.`  \
  **Explanation:** The configuration heights = [3, 4, 4, 1, 2] is a valid mountain where the sum of heights is maximized.

{{< dots >}}
## Approach 🚀
We will compute the maximum sum of the heights by iterating through all possible peaks and adjusting the tower heights accordingly.

### Initial Thoughts 💭
- To form a mountain array, we need to consider the non-decreasing and non-increasing subsequences.
- The sum of the tower heights must be maximized while respecting the maximum height constraints.
- The challenge is finding an efficient way to calculate the sum for each possible peak.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty as per the constraints.
- Ensure the solution handles large arrays efficiently (n up to 100,000).
- If all towers have the same maximum height, any configuration with a peak in the middle will form a valid mountain.
- The solution must respect the maximum height constraints while maximizing the sum.
{{< dots >}}
## Code 💻
```cpp
long long maximumSumOfHeights(vector<int>& A) {
    int n = A.size();
    vector<long long> left(n), stack = {-1};
    long long res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        while (stack.size() > 1 && A[stack.back()] > A[i]) {
            int j = stack.back();
            stack.pop_back();
            cur -= 1L * (j - stack.back()) * A[j];
        }
        cur += 1L * (i - stack.back()) * A[i];
        stack.push_back(i);
        left[i] = cur;
    }

    stack = {n};
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (stack.size() > 1 && A[stack.back()] > A[i]) {
            int j = stack.back();
            stack.pop_back();
            cur -= 1L * -(j - stack.back()) * A[j];
        }
        cur += 1L * -(i - stack.back()) * A[i];
        stack.push_back(i);
        res = max(res, left[i] + cur - A[i]);
    }

    return res;
}
```

This function calculates the maximum sum of heights in an array using dynamic programming and a stack-based approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	long long maximumSumOfHeights(vector<int>& A) {
	```
	Defines the function signature, initializing the parameters and starting the function.

2. **Initialization**
	```cpp
	    int n = A.size();
	```
	Calculates the size of the array A and stores it in variable n.

3. **Initialization**
	```cpp
	    vector<long long> left(n), stack = {-1};
	```
	Initializes a vector `left` to store partial results and a stack with a single element -1.

4. **Variables**
	```cpp
	    long long res = 0, cur = 0;
	```
	Declares two variables: `res` to store the final result and `cur` to store intermediate values.

5. **Loop**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	Starts a loop over the array from index 0 to n-1.

6. **Stack Operation**
	```cpp
	        while (stack.size() > 1 && A[stack.back()] > A[i]) {
	```
	Checks if the stack contains more than one element and if the current element is smaller than the top element of the stack.

7. **Stack Operation**
	```cpp
	            int j = stack.back();
	```
	Stores the index of the top element of the stack in variable `j`.

8. **Stack Operation**
	```cpp
	            stack.pop_back();
	```
	Removes the top element from the stack.

9. **Calculation**
	```cpp
	            cur -= 1L * (j - stack.back()) * A[j];
	```
	Updates the `cur` variable by subtracting the contribution of the removed element.

10. **Calculation**
	```cpp
	        cur += 1L * (i - stack.back()) * A[i];
	```
	Updates the `cur` variable by adding the contribution of the current element.

11. **Stack Operation**
	```cpp
	        stack.push_back(i);
	```
	Adds the current index to the stack.

12. **Calculation**
	```cpp
	        left[i] = cur;
	```
	Stores the current value of `cur` in the `left` vector at index `i`.

13. **Initialization**
	```cpp
	    stack = {n};
	```
	Reinitializes the stack with a single element `n`.

14. **Initialization**
	```cpp
	    cur = 0;
	```
	Resets the `cur` variable to 0.

15. **Loop**
	```cpp
	    for (int i = n - 1; i >= 0; i--) {
	```
	Starts a second loop over the array from index n-1 to 0.

16. **Stack Operation**
	```cpp
	        while (stack.size() > 1 && A[stack.back()] > A[i]) {
	```
	Checks if the stack contains more than one element and if the current element is smaller than the top element of the stack.

17. **Stack Operation**
	```cpp
	            int j = stack.back();
	```
	Stores the index of the top element of the stack in variable `j`.

18. **Stack Operation**
	```cpp
	            stack.pop_back();
	```
	Removes the top element from the stack.

19. **Calculation**
	```cpp
	            cur -= 1L * -(j - stack.back()) * A[j];
	```
	Updates the `cur` variable by subtracting the contribution of the removed element.

20. **Calculation**
	```cpp
	        cur += 1L * -(i - stack.back()) * A[i];
	```
	Updates the `cur` variable by adding the contribution of the current element.

21. **Stack Operation**
	```cpp
	        stack.push_back(i);
	```
	Adds the current index to the stack.

22. **Calculation**
	```cpp
	        res = max(res, left[i] + cur - A[i]);
	```
	Updates the `res` variable with the maximum value between the current `res` and the sum of `left[i]`, `cur`, and `A[i]`.

23. **Return**
	```cpp
	    return res;
	```
	Returns the final result stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), as we process each tower at most twice.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need for storing intermediate results in arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/beautiful-towers-ii/description/)

---
{{< youtube HZVMmKR0jZw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
