
+++
authors = ["grid47"]
title = "Leetcode 2778: Sum of Squares of Special Elements "
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2778: Sum of Squares of Special Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "7eI3tsBVCi4"
youtube_upload_date="2023-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/7eI3tsBVCi4/maxresdefault.webp"
comments = true
+++



---
Given a 1-indexed integer array nums of length n, an element nums[i] is considered special if the index i divides the length n (i.e., n % i == 0). Your task is to find the sum of the squares of all special elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 1-indexed integer array nums of length n.
- **Example:** `nums = [5, 3, 2, 7]`
- **Constraints:**
	- 1 <= nums.length == n <= 50
	- 1 <= nums[i] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the squares of all special elements in nums.
- **Example:** `Output: 58`
- **Constraints:**
	- Output is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify all special elements in the array and calculate the sum of their squares.

- Iterate through all elements of nums with their respective 1-based indices.
- Check if the index i divides the length n.
- If i divides n, calculate the square of nums[i] and add it to the result.
- Return the sum after processing all indices.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums is always 1-indexed.
- The length of nums is a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 5, 6]`  \
  **Explanation:** n = 3. Special elements are nums[1] (4) and nums[3] (6). Sum of squares = 4^2 + 6^2 = 16 + 36 = 52.

- **Input:** `nums = [1, 3, 7, 2]`  \
  **Explanation:** n = 4. Special elements are nums[1] (1), nums[2] (3), and nums[4] (2). Sum of squares = 1^2 + 3^2 + 2^2 = 1 + 9 + 4 = 14.

{{< dots >}}
## Approach 🚀
Iterate through the array using a loop and check divisibility conditions for each 1-based index. Accumulate the sum of the squares for all qualifying elements.

### Initial Thoughts 💭
- The index i should divide the length n of the array.
- 1-based indexing needs careful handling to align with array operations.
- A direct loop from 1 to n with modulus checks will suffice for this problem due to small constraints.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as per constraints (n >= 1).
- Test cases with nums having maximum length and maximum values.
- Test cases where all elements in nums are the same.
- Test cases where nums contains minimal values (all 1s).
- Ensure the code properly handles 1-based indexing.
{{< dots >}}
## Code 💻
```cpp
int sumOfSquares(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++)
        if(n % (i + 1) == 0) ans += nums[i] * nums[i];
    return ans;
}
```

The function `sumOfSquares` calculates the sum of squares of elements in the array `nums` whose indices are divisors of the array's size `n`. It uses a loop to check for divisors and adds the square of the corresponding element to the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int sumOfSquares(vector<int>& nums) {
	```
	This line declares the function `sumOfSquares`, which accepts a reference to an integer vector `nums` and returns an integer result.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable `ans` is initialized to 0 and will store the sum of the squares of the appropriate elements in the `nums` array.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The variable `n` is initialized to store the size of the array `nums`, which will be used to find divisors of the array's size.

4. **Looping**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A for-loop starts that iterates from 0 to `n-1`, covering all the indices of the `nums` array.

5. **Conditional Function Call**
	```cpp
	        if(n % (i + 1) == 0) ans += nums[i] * nums[i];
	```
	Inside the loop, a condition checks if the index `i + 1` is a divisor of `n` (i.e., if `n % (i + 1) == 0`). If true, the square of `nums[i]` is added to `ans`.

6. **Return Statement**
	```cpp
	    return ans;
	```
	After completing the loop, the function returns the value of `ans`, which contains the sum of the squares of the elements whose indices are divisors of `n`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves a single pass through the array, checking divisibility and accumulating results.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant additional space for computation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-squares-of-special-elements/description/)

---
{{< youtube 7eI3tsBVCi4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
