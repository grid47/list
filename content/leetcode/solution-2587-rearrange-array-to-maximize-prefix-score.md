
+++
authors = ["grid47"]
title = "Leetcode 2587: Rearrange Array to Maximize Prefix Score"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2587: Rearrange Array to Maximize Prefix Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N3qkc7zT_a0"
youtube_upload_date="2023-03-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/N3qkc7zT_a0/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. In one operation, you can choose two indices and subtract a power of two from both elements at those indices. A subarray is considered beautiful if you can make all of its elements equal to zero by applying the operation any number of times. Your task is to return the number of beautiful subarrays in `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums`.
- **Example:** `For example, `nums = [5, 6, 1, 3, 5]`.`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer that represents the number of beautiful subarrays in the array `nums`.
- **Example:** `For `nums = [5, 6, 1, 3, 5]`, the output is `3`.`
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
- **Input:** `For `nums = [5, 6, 1, 3, 5]``  \
  **Explanation:** The beautiful subarrays are `[5, 6, 1]`, `[5, 6, 1, 3, 5]`, and `[6, 1, 3]` as each can become all zeros after applying the operations.

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
int maxScore(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = nums.size();
    
    if(n == 1) return nums[0] > 0;
    int cnt = 0;
    
    long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(sum > 0) cnt++;
    }
    
    return cnt;
}
```

The function 'maxScore' sorts the input array in descending order and calculates how many elements contribute positively to the score. It returns the count of elements that result in a positive cumulative sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxScore(vector<int>& nums) {
	```
	Defines the 'maxScore' function that accepts a vector of integers.

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end(), greater<int>());
	```
	Sorts the input vector in descending order using the 'greater<int>' comparison function.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the sorted vector 'nums' in variable 'n'.

4. **Condition**
	```cpp
	    if(n == 1) return nums[0] > 0;
	```
	Checks if the vector has only one element and returns true if that element is positive.

5. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes the 'cnt' variable to count how many elements contribute positively to the sum.

6. **Variable Initialization**
	```cpp
	    long sum = 0;
	```
	Initializes a long variable 'sum' to keep track of the cumulative sum.

7. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates through each element in the sorted vector 'nums'.

8. **Summing Elements**
	```cpp
	        sum += nums[i];
	```
	Adds the current element of 'nums' to the cumulative 'sum'.

9. **Condition**
	```cpp
	        if(sum > 0) cnt++;
	```
	If the cumulative sum is positive, increments the 'cnt' variable.

10. **Return**
	```cpp
	    return cnt;
	```
	Returns the count of elements that resulted in a positive cumulative sum.

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


[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/)

---
{{< youtube N3qkc7zT_a0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
