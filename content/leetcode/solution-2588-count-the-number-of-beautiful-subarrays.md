
+++
authors = ["grid47"]
title = "Leetcode 2588: Count the Number of Beautiful Subarrays"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2588: Count the Number of Beautiful Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JokGqRfyMPU"
youtube_upload_date="2023-03-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/JokGqRfyMPU/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. In one operation, you can choose two indices and subtract a power of two from both elements at those indices. A subarray is considered beautiful if you can make all of its elements equal to zero by applying the operation any number of times. Your task is to return the number of beautiful subarrays in `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums`.
- **Example:** `For example, `nums = [6, 4, 5, 3, 4]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer that represents the number of beautiful subarrays in the array `nums`.
- **Example:** `For `nums = [6, 4, 5, 3, 4]`, the output is `3`.`
- **Constraints:**
	- The result will always be a valid integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the number of subarrays that can be made equal to 0 by applying the specified operations.

- 1. Loop through all possible subarrays in `nums`.
- 2. For each subarray, check if it can be transformed into an array of zeros by applying the operations.
- 3. Count the number of such subarrays and return the count.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains valid integers within the given range.
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [6, 4, 5, 3, 4]``  \
  **Explanation:** The beautiful subarrays are `[6, 4]`, `[6, 4, 5, 3, 4]`, and `[4, 5, 3]` as each can become all zeros after applying the operations.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the subarrays where it is possible to make all elements equal to zero by applying the operation any number of times. A strategy would be to check each subarray and verify if it satisfies the condition for becoming a beautiful subarray.

### Initial Thoughts 💭
- For each subarray, check if it can be made to have all elements equal to zero using the given operations.
- This problem seems to involve checking the binary representation of the numbers and ensuring we can make them equal.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the array will not be empty.
- The solution should be optimized to handle large inputs up to 10^5 elements.
- If all numbers are already zero, all subarrays are beautiful.
- The length of the array is guaranteed to be within the specified limits.
{{< dots >}}
## Code 💻
```cpp
long long beautifulSubarrays(vector<int>& nums) {
    int n= nums.size();
    long long cnt = 0;
    map<int, int> mp;
    mp[0] = 1;
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp ^= nums[i];
        if(mp.count(tmp)) cnt+= mp[tmp];
        mp[tmp]++;
    }
    return cnt;
}
```

The function 'beautifulSubarrays' calculates the number of beautiful subarrays in the input array 'nums'. A beautiful subarray is defined as a subarray where the XOR of all elements is zero at some point in the subarray. It uses a map to track XOR values and their frequencies to count the valid subarrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long beautifulSubarrays(vector<int>& nums) {
	```
	Defines the 'beautifulSubarrays' function, which takes a vector of integers as input and returns the count of beautiful subarrays.

2. **Variable Initialization**
	```cpp
	    int n= nums.size();
	```
	Initializes 'n' to the size of the 'nums' array.

3. **Variable Initialization**
	```cpp
	    long long cnt = 0;
	```
	Initializes the 'cnt' variable to store the count of beautiful subarrays.

4. **Data Structure Initialization**
	```cpp
	    map<int, int> mp;
	```
	Declares a map 'mp' to store the frequency of each XOR value encountered during the iteration.

5. **Data Structure Initialization**
	```cpp
	    mp[0] = 1;
	```
	Initializes the map with the value 0 mapped to 1, representing the XOR value of an empty subarray.

6. **Variable Initialization**
	```cpp
	    int tmp = 0;
	```
	Initializes 'tmp' to 0, which will be used to accumulate the XOR of the elements in the array.

7. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop that iterates over the array 'nums'.

8. **XOR Operation**
	```cpp
	        tmp ^= nums[i];
	```
	Applies the XOR operation on the current element of 'nums' with 'tmp', updating 'tmp' at each step.

9. **Condition Check**
	```cpp
	        if(mp.count(tmp)) cnt+= mp[tmp];
	```
	Checks if the current XOR value 'tmp' has been encountered before. If so, adds the frequency of 'tmp' from the map to 'cnt'.

10. **Data Structure Update**
	```cpp
	        mp[tmp]++;
	```
	Increments the frequency of the current XOR value 'tmp' in the map.

11. **Return**
	```cpp
	    return cnt;
	```
	Returns the total count of beautiful subarrays found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^3)

In the worst case, we may need to check each subarray, which can lead to a time complexity of O(n^3). Optimizing this solution is essential.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity depends on the storage of subarrays being checked.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/)

---
{{< youtube JokGqRfyMPU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
