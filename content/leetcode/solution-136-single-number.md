
+++
authors = ["grid47"]
title = "Leetcode 136: Single Number"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 136: Single Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/136.webp"
youtube = "mriHA5vEh0A"
youtube_upload_date="2024-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/mriHA5vEh0A/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/136.webp" 
    alt="A glowing, solitary number standing out in a sequence, signifying its uniqueness."
    caption="Solution to LeetCode 136: Single Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a non-empty array of integers where every element appears twice except for one element that appears once, find the single element that appears only once. The solution must have linear time complexity and use only constant space.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers where all but one element appear twice. The array is non-empty and contains at least one element.
- **Example:** `nums = [5, 5, 3]`
- **Constraints:**
	- 1 <= nums.length <= 3 * 10^4
	- -3 * 10^4 <= nums[i] <= 3 * 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the element that appears only once in the array.
- **Example:** `Output: 3`
- **Constraints:**
	- The array contains exactly one element that appears once.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the element that appears once by using XOR.

- 1. Use the XOR operation to find the element that appears once. XORing the same number twice cancels it out, leaving only the unique element.
- 2. Initialize a variable to 0 and XOR it with each element in the array.
- 3. Return the result after the final XOR operation, which will be the single number.
{{< dots >}}
### Problem Assumptions ✅
- The array is guaranteed to contain one unique element and all other elements appear exactly twice.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 5, 3]`  \
  **Explanation:** In this example, the number 3 appears once while 5 appears twice. The result is 3.

- **Input:** `nums = [7, 9, 7, 3, 9]`  \
  **Explanation:** In this case, 3 appears once, and all other numbers appear twice. The result is 3.

- **Input:** `nums = [4]`  \
  **Explanation:** Since there is only one number in the array, the result is that number itself, 4.

{{< dots >}}
## Approach 🚀
The approach to solving this problem is based on using XOR operation to find the unique element, which guarantees a linear time solution with constant space.

### Initial Thoughts 💭
- XOR can be used efficiently to identify the unique element, as XORing the same number twice cancels it out.
- We need to ensure that we process the array in linear time while using constant space.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return an error or handle it as a constraint violation.
- The solution must handle arrays with up to 30,000 elements efficiently.
- Handle cases where the only element in the array is the unique element.
- Ensure that the solution works efficiently even for large input sizes and adheres to the time and space complexity requirements.
{{< dots >}}
## Code 💻
```cpp
int singleNumber(vector<int>& nums) {
    int x = 0;
    for(int y: nums)
        x ^= y;
    return x;
}
```

The function `singleNumber` finds the number that appears only once in a list of integers where every other number appears twice. It uses XOR to isolate that single number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int singleNumber(vector<int>& nums) {
	```
	This is the function definition of `singleNumber`, which takes a vector of integers and returns the number that appears only once.

2. **Variable Initialization**
	```cpp
	    int x = 0;
	```
	Initialize a variable `x` to 0. This will hold the result of XOR operations and ultimately the number that appears only once.

3. **Loop Iteration**
	```cpp
	    for(int y: nums)
	```
	Start a loop to iterate through each element `y` in the `nums` array.

4. **Bitwise Operation**
	```cpp
	        x ^= y;
	```
	Apply the XOR operation between `x` and the current element `y`. This operation ensures that pairs of the same number cancel each other out.

5. **Return Statement**
	```cpp
	    return x;
	```
	Return the value of `x`, which holds the number that appeared only once after all XOR operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we traverse the array once to find the unique element.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use only a constant amount of space for calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/single-number/description/)

---
{{< youtube mriHA5vEh0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
