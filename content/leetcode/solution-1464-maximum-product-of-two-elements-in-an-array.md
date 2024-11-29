
+++
authors = ["grid47"]
title = "Leetcode 1464: Maximum Product of Two Elements in an Array"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1464: Maximum Product of Two Elements in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "XJ1pYgzimYo"
youtube_upload_date="2020-05-31"
youtube_thumbnail="https://i.ytimg.com/vi/XJ1pYgzimYo/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, you need to find two distinct elements and calculate the product of their decremented values. Specifically, you are tasked with returning the maximum value of (nums[i] - 1) * (nums[j] - 1) for two different indices i and j in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of integers. The length of the array will be at least 2. Each element of the array is a positive integer.
- **Example:** `Input: nums = [6, 3, 8, 2]`
- **Constraints:**
	- 2 <= nums.length <= 500
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, representing the maximum value obtained by multiplying the decremented values of two distinct elements in the array.
- **Example:** `Output: 56`
- **Constraints:**
	- The result should be the maximum possible value of (nums[i] - 1) * (nums[j] - 1), where i and j are distinct indices.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the two largest numbers in the array, subtract 1 from each, and multiply them to get the maximum product.

- Identify the two largest numbers in the array.
- Decrement each of these numbers by 1.
- Multiply the decremented values and return the result as the output.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least two elements.
- The input values are valid and within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [6, 3, 8, 2]`  \
  **Explanation:** Output: 56. The two largest numbers are 8 and 6. After subtracting 1 from each, we get 7 and 5. Their product is 7 * 5 = 56.

- **Input:** `Input: nums = [1, 5, 3, 9]`  \
  **Explanation:** Output: 32. The two largest numbers are 9 and 5. After subtracting 1 from each, we get 8 and 4. Their product is 8 * 4 = 32.

{{< dots >}}
## Approach 🚀
To solve this problem, we can simply identify the two largest numbers in the array and compute their product after subtracting 1 from each of them.

### Initial Thoughts 💭
- We only need to find the two largest values in the array to maximize the result.
- Sorting the array could be an option, but a more efficient approach is to track the two largest numbers directly while iterating.
- We will iterate through the array once, keeping track of the two largest values, then compute their product after decrementing.
{{< dots >}}
### Edge Cases 🌐
- The array will always contain at least two elements, so no need to handle empty inputs.
- For arrays with 500 elements, the algorithm should still run efficiently in O(n) time.
- If the array contains duplicate values, the two largest values might be the same. Ensure distinct indices are chosen.
- The solution needs to be efficient enough to handle the largest input sizes within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int maxProduct(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int num : nums) {
        if (num >= max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }

    return (max1 - 1) * (max2 - 1);
}
```

This function finds the maximum product of two numbers from the input array, after subtracting 1 from each of them. It uses two variables, max1 and max2, to keep track of the two largest numbers in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxProduct(vector<int>& nums) {
	```
	Defines the function maxProduct, which takes a reference to a vector of integers as input and returns an integer.

2. **Variable Initialization**
	```cpp
	    int max1 = INT_MIN;
	```
	Initializes max1 to the smallest possible integer value, ensuring that it will be replaced by any larger number in the array.

3. **Variable Initialization**
	```cpp
	    int max2 = INT_MIN;
	```
	Initializes max2 to the smallest possible integer value, similar to max1, and will store the second largest number in the array.

4. **Loop Start**
	```cpp
	    for (int num : nums) {
	```
	Starts a loop to iterate through each number in the input vector nums.

5. **Condition Check**
	```cpp
	        if (num >= max1) {
	```
	Checks if the current number is greater than or equal to max1, the largest number found so far.

6. **Update Variables**
	```cpp
	            max2 = max1;
	```
	Updates max2 to hold the value of max1 because max1 will be replaced by the current number.

7. **Update Variables**
	```cpp
	            max1 = num;
	```
	Updates max1 to the current number because it is now the largest number found.

8. **Condition Check**
	```cpp
	        } else if (num > max2) {
	```
	Checks if the current number is greater than max2, the second largest number found so far.

9. **Update Variables**
	```cpp
	            max2 = num;
	```
	Updates max2 to the current number because it is the new second largest number.

10. **Return Statement**
	```cpp
	    return (max1 - 1) * (max2 - 1);
	```
	Returns the product of (max1 - 1) and (max2 - 1), which is the maximum product of two distinct elements in the array, after subtracting 1 from both.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, because we iterate through the array once to find the two largest numbers.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space to store the two largest numbers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/)

---
{{< youtube XJ1pYgzimYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
