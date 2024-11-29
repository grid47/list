
+++
authors = ["grid47"]
title = "Leetcode 2771: Longest Non-decreasing Subarray From Two Arrays"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2771: Longest Non-decreasing Subarray From Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2aJYkQsBRbI"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/2aJYkQsBRbI/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays, nums1 and nums2, both of the same length n. Your task is to construct a new array nums3 such that each element in nums3 is either taken from nums1 or nums2 at the same index. The goal is to maximize the length of the longest contiguous non-decreasing subarray in nums3.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two 0-indexed integer arrays nums1 and nums2 of length n.
- **Example:** `nums1 = [1,4,2,3], nums2 = [2,1,3,4]`
- **Constraints:**
	- 1 <= nums1.length == nums2.length == n <= 100,000
	- 1 <= nums1[i], nums2[i] <= 1,000,000,000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the length of the longest non-decreasing subarray that can be formed in nums3.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the maximum length of a non-decreasing subarray that can be achieved by selecting elements optimally from nums1 and nums2.

- Initialize two arrays dp1 and dp2 to store the lengths of non-decreasing subarrays ending at each index when nums3 is constructed using nums1 or nums2 respectively.
- Iterate through the arrays and update dp1 and dp2 based on the conditions for non-decreasing subarrays.
- At each step, maintain the maximum length encountered so far.
- Return the maximum length at the end of the loop.
{{< dots >}}
### Problem Assumptions ✅
- The length of nums1 and nums2 will not exceed 100,000.
- The values in nums1 and nums2 will not exceed 1,000,000,000.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [3,5,2,8], nums2 = [4,2,6,9]`  \
  **Explanation:** One possible nums3 could be [3,5,6,9], forming a non-decreasing subarray of length 4.

- **Input:** `nums1 = [1,3,2], nums2 = [2,2,2]`  \
  **Explanation:** Optimal nums3 = [1,2,2], with the longest non-decreasing subarray length of 3.

{{< dots >}}
## Approach 🚀
Use a dynamic programming approach to track the lengths of non-decreasing subarrays constructed from nums1 and nums2.

### Initial Thoughts 💭
- At each index, nums3[i] can be chosen from either nums1[i] or nums2[i].
- The decision at index i depends on the value chosen at index i-1 to maintain the non-decreasing condition.
- We can optimize the solution by using two arrays to track the lengths of valid subarrays ending at each index.
{{< dots >}}
### Edge Cases 🌐
- Input arrays nums1 and nums2 cannot be empty.
- Handle arrays of size 100,000 efficiently.
- Arrays with all elements being the same.
- Ensure input arrays are of the same length.
{{< dots >}}
## Code 💻
```cpp

int Boom(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int ans = 1;
    vector<int> dp1(n, 1), dp2(n, 1);
            
    for(int i = 1; i < n; i++) {         
        for(int j = 0; j < i; j++) {
            if(nums1[i] >= nums1[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
            if(nums1[i] >= nums2[j]) {
               dp1[i] = max(dp1[i], dp2[j] + 1);                    
            }
            if(nums2[i] >= nums1[j]) {
                dp2[i] = max(dp2[i], dp1[j] + 1);                    
            }                 
            if(nums2[i] >= nums2[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);                                        
            }
        }
        ans = max(ans, max(dp1[i], dp2[i]));          
    }
    
    return ans;
}


int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int ans = 1;
    vector<int> dp1(n, 1), dp2(n, 1);
            
    for(int i = 1; i < n; i++) {         
        if(nums1[i] >= nums1[i - 1]) {
            dp1[i] = max(dp1[i], dp1[i - 1] + 1);
        }
        if(nums1[i] >= nums2[i - 1]) {
           dp1[i] = max(dp1[i], dp2[i - 1] + 1);                    
        }
        if(nums2[i] >= nums1[i - 1]) {
            dp2[i] = max(dp2[i], dp1[i - 1] + 1);                    
        }                 
        if(nums2[i] >= nums2[i - 1]) {
            dp2[i] = max(dp2[i], dp2[i - 1] + 1);                                        
        }
        ans = max(ans, max(dp1[i], dp2[i]));          
    }
    
    return ans;
}
```

This code defines a function to calculate the maximum length of a non-decreasing subsequence from two arrays `nums1` and `nums2`. It uses dynamic programming with two arrays `dp1` and `dp2` to track the lengths of subsequences. The `Boom` function is used for a more complex comparison between the two arrays, while the `maxNonDecreasingLength` function calculates the length of the longest non-decreasing subsequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	int Boom(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the main function `Boom` that will calculate the maximum subsequence length by comparing two arrays.

2. **Variable Initialization**
	```cpp
	    int n = nums1.size();
	```
	Initialize `n` to the size of `nums1` as both arrays are expected to be of equal size.

3. **Variable Initialization**
	```cpp
	    int ans = 1;
	```
	Initialize `ans` to 1 to represent the minimum length of any subsequence.

4. **Array Initialization**
	```cpp
	    vector<int> dp1(n, 1), dp2(n, 1);
	```
	Initialize two vectors `dp1` and `dp2` with size `n`, and set each value to 1, representing the length of a subsequence at each index.

5. **Looping**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Begin a loop from `i = 1` to iterate through the elements of the arrays.

6. **Nested Loop**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	For each element `i`, compare it with all previous elements `j`.

7. **Condition Checking**
	```cpp
	            if(nums1[i] >= nums1[j]) {
	```
	Check if the element at `nums1[i]` is greater than or equal to `nums1[j]`.

8. **Dynamic Programming**
	```cpp
	                dp1[i] = max(dp1[i], dp1[j] + 1);
	```
	Update the value of `dp1[i]` by taking the maximum value between its current value and `dp1[j] + 1`, indicating an increase in the subsequence length.

9. **Condition Checking**
	```cpp
	            if(nums1[i] >= nums2[j]) {
	```
	Check if the element at `nums1[i]` is greater than or equal to `nums2[j]`.

10. **Dynamic Programming**
	```cpp
	               dp1[i] = max(dp1[i], dp2[j] + 1);                    
	```
	Update `dp1[i]` by comparing it to `dp2[j] + 1`.

11. **Condition Checking**
	```cpp
	            if(nums2[i] >= nums1[j]) {
	```
	Check if the element at `nums2[i]` is greater than or equal to `nums1[j]`.

12. **Dynamic Programming**
	```cpp
	                dp2[i] = max(dp2[i], dp1[j] + 1);                    
	```
	Update `dp2[i]` by comparing it to `dp1[j] + 1`.

13. **Condition Checking**
	```cpp
	            if(nums2[i] >= nums2[j]) {
	```
	Check if the element at `nums2[i]` is greater than or equal to `nums2[j]`.

14. **Dynamic Programming**
	```cpp
	                dp2[i] = max(dp2[i], dp2[j] + 1);                                        
	```
	Update `dp2[i]` by comparing it to `dp2[j] + 1`.

15. **Result Calculation**
	```cpp
	        ans = max(ans, max(dp1[i], dp2[i]));          
	```
	Update `ans` to the maximum of the current `ans`, `dp1[i]`, and `dp2[i]`.

16. **Return**
	```cpp
	    return ans;
	```
	Return the value of `ans`, which holds the length of the longest non-decreasing subsequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves a single pass through the arrays, updating values based on conditions.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The solution uses two additional arrays of size n to store DP values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/)

---
{{< youtube 2aJYkQsBRbI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
