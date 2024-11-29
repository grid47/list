
+++
authors = ["grid47"]
title = "Leetcode 137: Single Number II"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 137: Single Number II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp"
youtube = "cOFAmaMBVps"
youtube_upload_date="2020-06-22"
youtube_thumbnail="https://i.ytimg.com/vi/cOFAmaMBVps/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp" 
    alt="Two radiant numbers standing out in a sequence, one representing the unique element and the other repeating."
    caption="Solution to LeetCode 137: Single Number II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array where every element appears exactly three times, except for one element which appears only once. Find the element that appears only once and return it. The solution must run in linear time complexity and use constant extra space.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers where each element except for one appears three times. The array will contain at least one element.
- **Example:** `nums = [1, 1, 2, 1, 2, 2, 4]`
- **Constraints:**
	- 1 <= nums.length <= 30,000
	- -2^31 <= nums[i] <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the element that appears only once in the array.
- **Example:** `Output: 4`
- **Constraints:**
	- The array contains exactly one element that appears once.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the unique element that appears only once by using bitwise operations.

- 1. Use two variables (`ones` and `twos`) to track the bits that appear once and twice, respectively.
- 2. Iterate through the array, updating the `ones` and `twos` variables using XOR and bitwise AND operations.
- 3. After completing the iteration, `ones` will contain the unique element that appears only once.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains exactly one element that appears only once, while all other elements appear exactly three times.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 1, 2, 1, 2, 2, 4]`  \
  **Explanation:** In this case, the numbers `1` and `2` appear three times, and `4` appears only once. The result is 4.

- **Input:** `nums = [8, 8, 8, 5]`  \
  **Explanation:** Here, `8` appears three times, while `5` appears only once, so the result is 5.

{{< dots >}}
## Approach 🚀
We can use bitwise operations to solve this problem in linear time with constant space. The key idea is to maintain two variables to track the bits that appear once and twice.

### Initial Thoughts 💭
- Using bitwise XOR and AND operations can efficiently track occurrences of numbers.
- We need to process each element once and use only a constant amount of space.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return an error or handle it as a constraint violation.
- The solution must handle arrays up to 30,000 elements efficiently.
- Ensure the solution works for both large and small integer values in the array.
- The algorithm must maintain linear time complexity and constant space complexity even for large inputs.
{{< dots >}}
## Code 💻
```cpp
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    
    int ones = 0, twos = 0;
    for(int i = 0; i < n; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;            
    }
    return ones;
}
```

The `singleNumber` function uses bit manipulation to find the number that appears only once in an array where every other number appears exactly twice. It uses two variables `ones` and `twos` to track the bits that appear once and twice, respectively.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int singleNumber(vector<int>& nums) {
	```
	The function `singleNumber` is defined to take a vector of integers `nums` as input and returns the integer that appears only once.

2. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	The size of the input vector `nums` is stored in the variable `n` to control the iteration.

3. **Variable Initialization**
	```cpp
	    int ones = 0, twos = 0;
	```
	Initialize two variables, `ones` and `twos`, to zero. These variables will keep track of the bits that appear once and twice in the input array.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate through the `nums` array. This loop will process each element to update the `ones` and `twos` variables.

5. **Bitwise Operation (ones)**
	```cpp
	        ones = (ones ^ nums[i]) & ~twos;
	```
	The bitwise XOR operation between `ones` and `nums[i]` flips the bits in `ones`. The result is then ANDed with the negation of `twos` to ensure that a bit that appears twice doesn't get set in `ones`.

6. **Bitwise Operation (twos)**
	```cpp
	        twos = (twos ^ nums[i]) & ~ones;            
	```
	The bitwise XOR operation between `twos` and `nums[i]` flips the bits in `twos`. The result is ANDed with the negation of `ones` to ensure that a bit that appears once doesn't get set in `twos`.

7. **Return Statement**
	```cpp
	    return ones;
	```
	Return the value of `ones`, which contains the number that appears only once after all iterations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we use only two variables to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/single-number-ii/description/)

---
{{< youtube cOFAmaMBVps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
