
+++
authors = ["grid47"]
title = "Leetcode 930: Binary Subarrays With Sum"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 930: Binary Subarrays With Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "j4JDr4-jvo4"
youtube_upload_date="2024-03-14"
youtube_thumbnail="https://i.ytimg.com/vi/j4JDr4-jvo4/maxresdefault.jpg"
comments = true
+++



---
You are given a binary array nums and an integer goal. Your task is to return the number of non-empty contiguous subarrays that have a sum equal to the given goal. A subarray is defined as any contiguous part of the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary array nums, consisting of 0's and 1's, and an integer goal. You need to find the number of subarrays that sum up to the goal.
- **Example:** `Input: nums = [1,1,0,1,0,1], goal = 2`
- **Constraints:**
	- 1 <= nums.length <= 3 * 10^4
	- nums[i] is either 0 or 1.
	- 0 <= goal <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of non-empty subarrays whose sum equals the given goal.
- **Example:** `Output: 4`
- **Constraints:**
	- The array will not be empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** The objective is to find how many subarrays have a sum equal to the given goal.

- 1. Use the sliding window technique to count the number of subarrays whose sum is less than or equal to the goal.
- 2. Calculate the number of subarrays whose sum is at most 'goal' and subtract the result for 'goal-1' from it to get the exact number of subarrays with sum equal to 'goal'.
- 3. Implement the helper function 'atmost' to count subarrays with sum at most a given value, and use it to compute the result.
{{< dots >}}
### Problem Assumptions ✅
- The input array is always non-empty, and its elements are either 0 or 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1,1,0,1,0,1], goal = 2`  \
  **Explanation:** In this case, the following subarrays have a sum of 2: [1,1], [1,1], [0,1,0], and [1,1]. Thus, the output is 4.

- **Input:** `Input: nums = [0,0,0,0], goal = 0`  \
  **Explanation:** Here, every subarray has a sum of 0. Therefore, there are 15 such subarrays (which includes all possible non-empty subarrays of the input array).

{{< dots >}}
## Approach 🚀
We use a sliding window approach to efficiently count the number of subarrays with the given sum. By counting the number of subarrays whose sum is at most 'goal' and subtracting the number of subarrays with sum at most 'goal-1', we can find the result.

### Initial Thoughts 💭
- The sliding window approach helps track the sum of subarrays in linear time.
- By considering subarrays with a sum at most 'goal' and then subtracting those with sum at most 'goal-1', we can isolate those with exactly 'goal'.
- This approach efficiently counts subarrays with the desired sum by maintaining a running total of elements and adjusting the window dynamically.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty in any test case.
- The algorithm needs to handle input arrays up to 30,000 elements efficiently.
- If the goal is 0, count the number of subarrays with a sum of 0.
- The array will contain only 0's and 1's, which simplifies the sum calculation.
{{< dots >}}
## Code 💻
```cpp
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atmost(nums, goal) - atmost(nums, goal -1);
}

int atmost(vector<int> &nums, int s) {
    if(s < 0) return 0;
    int res = 0, j = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        s -= nums[i];
        while(s < 0) s += nums[j++];
        res += (i - j + 1);
    }
    return res;
}
```

The function 'numSubarraysWithSum' returns the number of subarrays that sum up to a given 'goal'. It uses the helper function 'atmost', which computes the number of subarrays with a sum at most 's'. The result is the difference between the number of subarrays with sum at most 'goal' and the number of subarrays with sum at most 'goal - 1'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSubarraysWithSum(vector<int>& nums, int goal) {
	```
	Define the function 'numSubarraysWithSum' that takes a vector of integers 'nums' and an integer 'goal', and returns the number of subarrays whose sum equals the goal.

2. **Return Statement**
	```cpp
	    return atmost(nums, goal) - atmost(nums, goal -1);
	```
	Call the helper function 'atmost' with the parameters 'nums' and 'goal', and subtract the result of 'atmost(nums, goal - 1)' from it. This returns the number of subarrays whose sum equals 'goal'.

3. **Helper Function Definition**
	```cpp
	int atmost(vector<int> &nums, int s) {
	```
	Define the helper function 'atmost', which calculates the number of subarrays in 'nums' that have a sum less than or equal to 's'.

4. **Base Case**
	```cpp
	    if(s < 0) return 0;
	```
	If the sum 's' is negative, return 0 because there are no subarrays with a sum less than 0.

5. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initialize two variables: 'res' to store the result (the number of subarrays), and 'j' as a pointer to track the start of the current subarray.

6. **For Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate through each element 'i' in the vector 'nums'.

7. **Subtract Current Element**
	```cpp
	        s -= nums[i];
	```
	Subtract the current element 'nums[i]' from 's' to adjust the sum.

8. **Adjust Start of Subarray**
	```cpp
	        while(s < 0) s += nums[j++];
	```
	If 's' becomes negative, increment 'j' to shrink the subarray from the left until the sum becomes non-negative.

9. **Count Subarrays**
	```cpp
	        res += (i - j + 1);
	```
	The number of subarrays ending at 'i' and having a sum less than or equal to 's' is equal to (i - j + 1). Add this to 'res'.

10. **Return Result**
	```cpp
	    return res;
	```
	Return the total count of subarrays whose sum is less than or equal to 's'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, as we only traverse the array once while maintaining a sliding window.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only use a few variables to track the sliding window and running sum.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

---
{{< youtube j4JDr4-jvo4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
