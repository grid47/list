
+++
authors = ["grid47"]
title = "Leetcode 2860: Happy Students"
date = "2024-01-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2860: Happy Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "dDse65NWFt8"
youtube_upload_date="2023-09-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dDse65NWFt8/maxresdefault.webp"
comments = true
+++



---
You are given a list of integers where each integer represents a student's happiness threshold. The task is to determine the number of ways to select a group of students so that all students in the group remain happy.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer list representing the happiness thresholds of each student.
- **Example:** `nums = [2, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] < nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of valid ways to select students such that all students are happy.
- **Example:** `Output: 3`
- **Constraints:**
	- The output is an integer representing the number of valid student selection ways.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of ways to select a group of students such that all students in the group are happy.

- Sort the input list to facilitate easier comparison of thresholds.
- Iterate through the list while tracking the number of students selected.
- Check if the current number of selected students satisfies the happiness condition for the student at each index.
- Count the valid groupings based on these conditions.
{{< dots >}}
### Problem Assumptions ✅
- The input list will not be empty.
- Each student's happiness threshold is valid according to the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 2]`  \
  **Explanation:** The valid ways to select students are: select no student, select the first student, select the second student, or select both students.

- **Input:** `nums = [1, 0, 3, 2, 1, 4]`  \
  **Explanation:** The valid ways to select students are: select no students, select the second student only, select students with indices 1 and 2, or select all students.

{{< dots >}}
## Approach 🚀
The solution involves iterating through the list of students, sorting the thresholds, and using a simple check to count the valid ways to form groups where all students are happy.

### Initial Thoughts 💭
- We need to find all subsets of students where the selected students' count meets the happiness conditions for each student.
- Sorting the list helps in efficiently finding the valid groups by comparing thresholds with the current count of selected students.
{{< dots >}}
### Edge Cases 🌐
- The list will not be empty based on the given constraints.
- The solution should efficiently handle lists with up to 100,000 students.
- When all students have a threshold of 0, there are many possible ways to select groups.
- The input list must contain between 1 and 100,000 students.
{{< dots >}}
## Code 💻
```cpp

int countWays(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ans = 0, n = nums.size();
    int selected = 0;
    if(nums[0]!=0) ans = 1; // Not Selecting AnyOne
    for(int i=0;i<n;i++) {
        selected++;
        if(selected>nums[i]) {  // No. of Selected Students is strictly greater than nums[i].
            if(i+1<n && selected<nums[i+1]) // Considering from (i+1) to n Students is not Selected.
                ans++; 
            else if(i+1==n) ans++;  // Last Student
        }
    }
    return ans;
}

```

This function counts the number of ways to select students such that the number of selected students is strictly greater than their respective values in the array `nums`, which represents a threshold for each student.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countWays(vector<int>& nums) {
	```
	Defines the function `countWays`, which accepts a vector `nums` and returns the number of valid selections of students.

2. **Sorting**
	```cpp
	    sort(nums.begin(),nums.end());
	```
	Sorts the array `nums` in ascending order to facilitate the selection process based on increasing thresholds.

3. **Variable Initialization**
	```cpp
	    int ans = 0, n = nums.size();
	```
	Initializes `ans` to 0 for counting valid selections and `n` to store the size of the `nums` array.

4. **Selection Counter**
	```cpp
	    int selected = 0;
	```
	Initializes the variable `selected` to keep track of the number of selected students.

5. **Initial Condition**
	```cpp
	    if(nums[0]!=0) ans = 1; // Not Selecting AnyOne
	```
	Checks if the first element in the sorted `nums` is not zero, and if so, it sets `ans` to 1, indicating a valid selection (not selecting anyone).

6. **Main Loop**
	```cpp
	    for(int i=0;i<n;i++) {
	```
	Starts a loop that iterates through each student represented by the array `nums`.

7. **Increment Selection**
	```cpp
	        selected++;
	```
	Increments the `selected` counter for each iteration to represent selecting a student.

8. **Condition Check**
	```cpp
	        if(selected>nums[i]) {  // No. of Selected Students is strictly greater than nums[i].
	```
	Checks if the number of selected students is strictly greater than the threshold value `nums[i]`.

9. **Next Student Check**
	```cpp
	            if(i+1<n && selected<nums[i+1]) // Considering from (i+1) to n Students is not Selected.
	```
	Checks if the next student in the array is not selected and the selected count is still valid.

10. **Valid Selection**
	```cpp
	                ans++; 
	```
	Increments the answer `ans` if the selection condition is satisfied.

11. **Last Student Check**
	```cpp
	            else if(i+1==n) ans++;  // Last Student
	```
	Increments the answer `ans` if the current student is the last one in the array, meaning the selection is valid.

12. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the final count of valid ways to select students.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the number of students.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the sorted list of students.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/happy-students/description/)

---
{{< youtube dDse65NWFt8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
