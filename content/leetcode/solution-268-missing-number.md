
+++
authors = ["grid47"]
title = "Leetcode 268: Missing Number"
date = "2024-10-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 268: Missing Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Binary Search","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp"
youtube = "WnPLSRLSANE"
youtube_upload_date="2021-07-26"
youtube_thumbnail="https://i.ytimg.com/vi/WnPLSRLSANE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp" 
    alt="A series of numbers, with one missing number softly highlighted as the gap is revealed."
    caption="Solution to LeetCode 268: Missing Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array nums containing n distinct numbers, each in the range [0, n], return the only number in the range that is missing from the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums containing distinct integers in the range [0, n].
- **Example:** `For example, nums = [1, 0, 3].`
- **Constraints:**
	- 1 <= n <= 10^4
	- 0 <= nums[i] <= n
	- All the numbers of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the only missing number in the range [0, n].
- **Example:** `For nums = [1, 0, 3], the output is 2.`
- **Constraints:**
	- The missing number is guaranteed to be between 0 and n.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the missing number in the array, we can leverage a mathematical approach using XOR or summation properties.

- 1. Calculate the XOR of all elements in the array.
- 2. XOR the result with all the numbers from 0 to n.
- 3. The result will be the missing number.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain n distinct elements in the range [0, n].
- There will always be one missing number.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [1, 0, 3], the missing number is 2.`  \
  **Explanation:** The array should have contained the numbers 0, 1, 2, and 3. The missing number is 2.

{{< dots >}}
## Approach 🚀
The approach to solve this problem involves leveraging the properties of XOR or the summation formula to find the missing number in the range [0, n].

### Initial Thoughts 💭
- The XOR of two identical numbers cancels out, which makes XOR an efficient way to find the missing number.
- We can use the XOR approach to achieve the solution in O(n) time and O(1) space.
{{< dots >}}
### Edge Cases 🌐
- The array will always contain at least one element, so there are no empty inputs.
- For large inputs, the XOR approach ensures an O(n) time complexity and O(1) space complexity.
- If the array is missing 0, it will be correctly identified as the missing number.
- The solution should work for arrays of size up to 10^4.
{{< dots >}}
## Code 💻
```cpp
int missingNumber(vector<int>& nums) {
    int sum = nums[0];
    for(int i = 1; i < nums.size(); i++)
        sum ^= nums[i];
    for(int i = 0; i <= nums.size(); i++)
        sum ^= i;
    return sum;
}
```

This function finds the missing number in an array of integers from 0 to n. It uses the XOR operation to find the number that does not appear in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int missingNumber(vector<int>& nums) {
	```
	Defines the `missingNumber` function that takes a vector of integers `nums` and returns the missing number from the range 0 to n.

2. **Initial XOR Setup**
	```cpp
	    int sum = nums[0];
	```
	Initializes the variable `sum` with the first element of `nums` to start the XOR operation.

3. **Iterate Over Input Array**
	```cpp
	    for(int i = 1; i < nums.size(); i++)
	```
	Iterates over the remaining elements in the `nums` array, starting from the second element.

4. **XOR Each Array Element**
	```cpp
	        sum ^= nums[i];
	```
	Applies the XOR operation between the current `sum` and each element of the `nums` array.

5. **Iterate Over Full Range**
	```cpp
	    for(int i = 0; i <= nums.size(); i++)
	```
	Iterates over the full range from 0 to `n`, where `n` is the size of the array.

6. **XOR with Range Elements**
	```cpp
	        sum ^= i;
	```
	Applies the XOR operation between `sum` and each value in the range 0 to `n`.

7. **Return Missing Number**
	```cpp
	    return sum;
	```
	Returns the result of the XOR operation, which is the missing number in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate over the array once and perform constant time operations for each element.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/missing-number/description/)

---
{{< youtube WnPLSRLSANE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
