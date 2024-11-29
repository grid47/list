
+++
authors = ["grid47"]
title = "Leetcode 283: Move Zeroes"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 283: Move Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/283.webp"
youtube = "39VJV4KVyi8"
youtube_upload_date="2020-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/39VJV4KVyi8/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/283.webp" 
    alt="A sequence where zeroes gently move to the end, and the remaining elements shift into place."
    caption="Solution to LeetCode 283: Move Zeroes Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer array `nums`, move all the zeros to the end while maintaining the relative order of the non-zero elements. Perform the operation in-place without making a copy of the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array `nums` of integers.
- **Example:** `For example, `nums = [0, 5, 0, 2, 8]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -2^31 <= nums[i] <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the array with all zeros moved to the end while keeping the relative order of non-zero elements intact.
- **Example:** `For `nums = [0, 5, 0, 2, 8]`, the output should be `[5, 2, 8, 0, 0]`.`
- **Constraints:**
	- The operation must be performed in-place.

{{< dots >}}
### Core Logic 🔍
**Goal:** Move all zeros in the `nums` array to the end while maintaining the relative order of non-zero elements.

- Use a variable `j` to track the position of the next non-zero element.
- Iterate through the array, and for each non-zero element, swap it with the element at position `j`, then increment `j`.
- After the iteration, all elements from `j` to the end of the array should be zeros.
{{< dots >}}
### Problem Assumptions ✅
- The array may contain any number of zeros, including zero zeros.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [0, 5, 0, 2, 8]``  \
  **Explanation:** All zeros are moved to the end while keeping the relative order of the non-zero elements intact. The output is `[5, 2, 8, 0, 0]`.

- **Input:** `For `nums = [4, 0, 1, 3]``  \
  **Explanation:** The zeros are moved to the end while maintaining the relative order of the non-zero elements. The output is `[4, 1, 3, 0]`.

{{< dots >}}
## Approach 🚀
We will iterate over the array and swap each non-zero element with the element at the position tracked by `j`. This will push all zeros to the end of the array.

### Initial Thoughts 💭
- The problem requires an in-place solution, meaning no extra array should be created.
- The approach involves shifting non-zero elements to the left while moving zeros to the right in a single pass.
{{< dots >}}
### Edge Cases 🌐
- An empty array should not result in any errors, but it should return an empty array.
- Ensure that the solution works efficiently for arrays of the maximum allowed length (10^4).
- If the array contains no zeros, the array should remain unchanged.
- The solution must work within the given time and space constraints.
{{< dots >}}
## Code 💻
```cpp
void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0)
            swap(nums[i], nums[j]), j++;
    }
    while(j < nums.size())
        nums[j++] = 0;
}
```

This function moves all zeroes in the input array to the end, maintaining the order of the non-zero elements using a two-pointer approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void moveZeroes(vector<int>& nums) {
	```
	Defines the function `moveZeroes`, which takes a reference to a vector of integers `nums` and moves all zeroes in the array to the end while maintaining the order of the non-zero elements.

2. **Initialize Pointer**
	```cpp
	    int j = 0;
	```
	Initializes the pointer `j` to keep track of the position where the next non-zero element should be placed.

3. **Loop Through Array**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Starts a loop to iterate through each element of the array `nums` using index `i`.

4. **Check Non-Zero Element**
	```cpp
	        if(nums[i] != 0)
	```
	Checks if the current element is non-zero.

5. **Swap Elements**
	```cpp
	            swap(nums[i], nums[j]), j++;
	```
	Swaps the current non-zero element `nums[i]` with the element at position `j` and increments `j` to the next position for the next non-zero element.

6. **Place Remaining Zeros**
	```cpp
	    while(j < nums.size())
	```
	Starts a while loop to fill the remaining positions in the array with zeroes, starting from index `j`.

7. **Assign Zeroes**
	```cpp
	        nums[j++] = 0;
	```
	Assigns zero to the current position `j` and increments `j` until all remaining positions are filled with zeroes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we are iterating over the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as the solution only uses a constant amount of extra space for the variable `j`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/move-zeroes/description/)

---
{{< youtube 39VJV4KVyi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
