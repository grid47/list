
+++
authors = ["grid47"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2154: Keep Multiplying Found Values by Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-6Wf-ZShQQ"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-6Wf-ZShQQ/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers 'nums' and an integer 'original'. Start with the number 'original' and search for it in the array. If found, multiply it by two. Repeat this process until 'original' is no longer found in 'nums'. Return the final value of 'original'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers 'nums' and an integer 'original'.
- **Example:** `nums = [4, 2, 8, 1, 16], original = 4`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i], original <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the final value of 'original' after performing the described operations.
- **Example:** `Output: 64`
- **Constraints:**
	- The final value of 'original' should be returned after the process stops.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if 'original' is in the array, and if so, multiply it by two. Repeat this process until 'original' is no longer found in the array.

- Create a frequency map to count occurrences of each number in 'nums'.
- Check if 'original' is present in 'nums' and multiply it by two if found.
- Repeat the process until 'original' is not found.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains integers within the specified range, and the number 'original' is also within the valid bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [4, 2, 8, 1, 16], original = 4`  \
  **Explanation:** The number 4 is found and doubled to 8, then 8 is found and doubled to 16, and so on until 64 is obtained, which is not found in the array.

- **Input:** `Example 2: nums = [1, 3, 5], original = 2`  \
  **Explanation:** The number 2 is not found in the array, so the process stops immediately, and the final value remains 2.

{{< dots >}}
## Approach 🚀
The approach involves checking if the number 'original' is in the array, and multiplying it by 2 whenever it is found, repeating the process until it is no longer found.

### Initial Thoughts 💭
- The algorithm needs to check for the presence of a number and keep multiplying it until it is no longer found.
- A frequency map can be useful to quickly check if a number exists in the array.
{{< dots >}}
### Edge Cases 🌐
- Empty input arrays are not allowed by the problem constraints.
- The solution should efficiently handle large arrays with a length of up to 1000.
- If 'original' is not found initially, the algorithm should return the unchanged value of 'original'.
- The array 'nums' and the value 'original' are within specified bounds.
{{< dots >}}
## Code 💻
```cpp
  int findFinalValue(vector<int>& nums, int o) {
    int h[1001]={};
    for(auto i:nums) h[i]++;
		
    while(o<=1000 && h[o])
        o*=2;
    
    return o;
}
```

This function finds the final value of 'o' after repeatedly doubling it until it no longer exists in the 'nums' array, using a frequency array for efficient lookup.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	  int findFinalValue(vector<int>& nums, int o) {
	```
	The function 'findFinalValue' takes an array 'nums' and an integer 'o'. It calculates a final value by repeatedly doubling 'o' if the value exists in 'nums'.

2. **Array Initialization**
	```cpp
	    int h[1001]={};
	```
	Initialize a frequency array 'h' of size 1001 to store the frequency of each integer in 'nums'. The array is initially set to zero.

3. **Frequency Counting**
	```cpp
	    for(auto i:nums) h[i]++;
	```
	Iterate over each element in the 'nums' array and update the frequency of that element in the array 'h'.

4. **Loop Control**
	```cpp
	    while(o<=1000 && h[o])
	```
	While 'o' is less than or equal to 1000 and the value 'o' exists in the frequency array 'h', keep doubling 'o'.

5. **Doubling**
	```cpp
	        o*=2;
	```
	Double the value of 'o'. This continues until 'o' is not present in the frequency array or exceeds 1000.

6. **Return Statement**
	```cpp
	    return o;
	```
	Return the final value of 'o' after the loop terminates.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the need to iterate through the array once to build the frequency map.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the frequency map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/)

---
{{< youtube b-6Wf-ZShQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
