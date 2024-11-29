
+++
authors = ["grid47"]
title = "Leetcode 1979: Find Greatest Common Divisor of Array"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1979: Find Greatest Common Divisor of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "sJ5pTyUWOZ0"
youtube_upload_date="2021-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/sJ5pTyUWOZ0/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, your task is to compute the greatest common divisor (GCD) of the smallest and largest elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` where each element is a positive integer.
- **Example:** `nums = [12, 30, 50, 60, 80]`
- **Constraints:**
	- 2 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the greatest common divisor of the smallest and largest number in the array.
- **Example:** `Output: 10`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the GCD of the smallest and largest number in the array.

- Step 1: Find the smallest and largest numbers in the array.
- Step 2: Compute the greatest common divisor (GCD) of these two numbers using the Euclidean algorithm.
- Step 3: Return the GCD as the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains at least two integers.
- The GCD of the smallest and largest integers will be calculated.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [12, 30, 50, 60, 80]`  \
  **Explanation:** In this example, the smallest number is 12, and the largest number is 80. The greatest common divisor of 12 and 80 is 4.

- **Input:** `Input: nums = [7, 5, 6, 8, 3]`  \
  **Explanation:** The smallest number is 3, and the largest number is 8. The GCD of 3 and 8 is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to compute the greatest common divisor of the smallest and largest numbers in the given array. The approach involves first finding the smallest and largest numbers and then calculating their GCD using the Euclidean algorithm.

### Initial Thoughts 💭
- Finding the smallest and largest numbers in the array can be done in a single pass.
- Calculating the GCD is an efficient operation, and the Euclidean algorithm ensures we can find it quickly.
- The Euclidean algorithm is ideal for computing the GCD in logarithmic time, which is efficient even for large input arrays.
{{< dots >}}
### Edge Cases 🌐
- The input array will always contain at least two elements, so this case is not applicable.
- For large arrays, ensure the solution efficiently computes the GCD by using the Euclidean algorithm.
- If all elements in the array are the same, the GCD will be that value.
- Ensure that the GCD is calculated correctly and that the solution handles arrays with the maximum size and values.
{{< dots >}}
## Code 💻
```cpp
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int> &nums) {
        int min = 1001;
        int max = 0;
        // Find the min and max from array
        for (int e : nums) {
            if (e < min) min = e;
            if (e > max) max = e;
        }
        return gcd(min, max);
    }
```

This code defines two functions: `gcd` to calculate the greatest common divisor (GCD) of two numbers, and `findGCD` to calculate the GCD of the smallest and largest elements in an array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **GCD Function Definition**
	```cpp
	    int gcd(int a, int b) {
	```
	Define the `gcd` function which takes two integers as input and computes their greatest common divisor.

2. **Base Case**
	```cpp
	        if (b == 0) return a;
	```
	If the second number is zero, return the first number as the GCD.

3. **Recursive Case**
	```cpp
	        return gcd(b, a % b);
	```
	Otherwise, recursively call `gcd` with the second number and the remainder of the division of the first number by the second number.

4. **FindGCD Function Definition**
	```cpp
	    int findGCD(vector<int> &nums) {
	```
	Define the `findGCD` function which takes a vector of integers and finds the GCD of the smallest and largest numbers in the array.

5. **Initialize Min and Max**
	```cpp
	        int min = 1001;
	```
	Initialize a variable `min` to a value greater than any element in the input array (assumed max value).

6. **Initialize Max**
	```cpp
	        int max = 0;
	```
	Initialize a variable `max` to a value smaller than any element in the input array (assumed min value).

7. **Loop Through Array**
	```cpp
	        for (int e : nums) {
	```
	Loop through each element `e` in the array `nums`.

8. **Update Min**
	```cpp
	            if (e < min) min = e;
	```
	If the current element `e` is smaller than the current `min`, update `min`.

9. **Update Max**
	```cpp
	            if (e > max) max = e;
	```
	If the current element `e` is larger than the current `max`, update `max`.

10. **Return GCD of Min and Max**
	```cpp
	        return gcd(min, max);
	```
	Return the GCD of the smallest and largest elements in the array using the previously defined `gcd` function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array, for finding the smallest and largest numbers.
- **Average Case:** O(n), assuming GCD calculation is efficient.
- **Worst Case:** O(n + log(max_value)), where n is the length of the array and max_value is the largest number in the array.

The time complexity is linear for finding the smallest and largest values, and logarithmic for the GCD calculation.

### Space Complexity 💾
- **Best Case:** O(1), no additional space is required.
- **Worst Case:** O(1), as we only use a few variables.

The space complexity is constant as we only use a few variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/)

---
{{< youtube sJ5pTyUWOZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
