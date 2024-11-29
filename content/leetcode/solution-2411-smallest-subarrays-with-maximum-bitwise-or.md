
+++
authors = ["grid47"]
title = "Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0xR5bFyo2QA"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0xR5bFyo2QA/maxresdefault.webp"
comments = true
+++



---
Given a 0-indexed array of non-negative integers, 'nums', you need to find the length of the smallest subarray starting at each index that has the maximum possible bitwise OR. For each index 'i', find the minimum length subarray nums[i...j] such that the bitwise OR of this subarray equals the maximum OR value possible starting from index 'i'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array, 'nums', of non-negative integers.
- **Example:** `nums = [3,1,2,5]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element at index 'i' represents the size of the minimum sized subarray starting from index 'i' with the maximum bitwise OR.
- **Example:** `Output: [3,2,2,1]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum length subarray starting at index 'i' whose OR is maximized among all subarrays starting at indices greater than or equal to 'i'.

- 1. Initialize a result array with size 'n' where each element is initially set to 1.
- 2. Track the last occurrence of each bit in the binary representation of the elements.
- 3. Starting from the last element, calculate the bitwise OR for each subarray starting at the current index and update the answer accordingly.
- 4. Use bitwise OR operation and last position tracking to efficiently compute the result for each index.
{{< dots >}}
### Problem Assumptions ✅
- The input array is non-empty, and all numbers are non-negative integers.
- Subarrays must contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3,1,2,5]`  \
  **Explanation:** For index 0, the maximum OR is 7. The shortest subarray starting at index 0 is [3, 1, 2], which has an OR of 7. For index 1, the OR is maximized by [1, 2], and for index 2, it is maximized by [2, 5]. Thus, the result is [3, 2, 2, 1].

{{< dots >}}
## Approach 🚀
The solution uses a greedy approach with bitwise OR operations and last position tracking to minimize the subarray size.

### Initial Thoughts 💭
- Bitwise OR operations combine all set bits, and the maximum OR for a subarray will involve including all contributing bits.
- The approach needs to track the last occurrence of set bits to determine the shortest subarray that gives the maximum OR.
- Efficient handling of bitwise operations and subarray size computation will be key to solving the problem within the given constraints.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty as per the problem constraints.
- The solution must efficiently handle large inputs (up to 100,000 elements) by using a linear time complexity approach.
- If all elements in the array are the same, the result will be the same length for each index.
- Handling large numbers efficiently, as bitwise operations should be performed on integers within the range 0 to 10^9.
{{< dots >}}
## Code 💻
```cpp
vector<int> smallestSubarrays(vector<int>& nums) {
    
    int n = nums.size();
    
    vector<int> ans(n, 1), last(30, 0);
    
    
    for(int i = n - 1; i >= 0; i--) {
        
        
        for(int j = 0; j < 30; j++) {
            
            if(nums[i] & (1 << j)) {
                last[j] = i;
            }
            
            ans[i] = max(ans[i], last[j] - i + 1);
        }
    }
    
    return ans;
}
```

This function calculates the smallest subarrays that contain all set bits (1s) for each element in the given array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> smallestSubarrays(vector<int>& nums) {
	```
	Function declaration to find the smallest subarray for each element of the input array 'nums'.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializing 'n' as the size of the input array 'nums'.

3. **Variable Initialization**
	```cpp
	    vector<int> ans(n, 1), last(30, 0);
	```
	Declaring and initializing 'ans' to store the answer for each element and 'last' to keep track of the last index of a set bit.

4. **Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Starting the loop from the last element of the array and iterating backwards.

5. **Inner Loop**
	```cpp
	        for(int j = 0; j < 30; j++) {
	```
	Inner loop iterating over the possible bit positions (0-29).

6. **Condition Check**
	```cpp
	            if(nums[i] & (1 << j)) {
	```
	Checking if the j-th bit is set (1) in the current number 'nums[i]'.

7. **Update**
	```cpp
	                last[j] = i;
	```
	Updating the 'last' array to store the current index for the j-th set bit.

8. **Update**
	```cpp
	            ans[i] = max(ans[i], last[j] - i + 1);
	```
	Updating the 'ans' array to hold the size of the smallest subarray that includes the current set bit.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returning the final array 'ans' which contains the size of the smallest subarray for each element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the size of the input array.
- **Average Case:** O(n), since each element is processed once.
- **Worst Case:** O(n), the worst case is still linear due to the single pass through the array and constant time bitwise operations.

The approach runs in linear time, processing each element once and performing constant-time bitwise operations.

### Space Complexity 💾
- **Best Case:** O(n), the space complexity remains linear in all cases.
- **Worst Case:** O(n), for the result array and last occurrence tracking arrays.

The space complexity is linear, requiring space for the result array and bitwise tracking arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

---
{{< youtube 0xR5bFyo2QA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
