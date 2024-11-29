
+++
authors = ["grid47"]
title = "Leetcode 1051: Height Checker"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1051: Height Checker in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mQAoeYaE3Xk"
youtube_upload_date="2024-06-10"
youtube_thumbnail="https://i.ytimg.com/vi/mQAoeYaE3Xk/maxresdefault.jpg"
comments = true
+++



---
A school is arranging students in a line for an annual photograph. The students are required to stand in a non-decreasing order of height. The expected order is represented by an array, where each element corresponds to the expected height of the student at that position. Given the current arrangement of the students' heights, determine the number of positions where the height of the student does not match the expected height.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array 'heights' which represents the current arrangement of students, and another array 'expected' which represents the expected arrangement of students in non-decreasing order.
- **Example:** `Input: heights = [4, 2, 3, 5, 1], expected = [1, 2, 3, 4, 5]`
- **Constraints:**
	- 1 <= heights.length <= 100
	- 1 <= heights[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of positions where the height in the 'heights' array does not match the corresponding value in the 'expected' array.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify and count the indices where the current heights do not match the expected sorted order.

- 1. Sort the 'heights' array to create the 'expected' array.
- 2. Compare the 'heights' array with the 'expected' array.
- 3. Count the number of indices where the two arrays differ.
{{< dots >}}
### Problem Assumptions ✅
- The heights array contains positive integers that represent valid heights.
- The input array will not be empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: heights = [4, 2, 3, 5, 1], expected = [1, 2, 3, 4, 5]`  \
  **Explanation:** In this example, after sorting, the heights array becomes [1, 2, 3, 4, 5]. The differences are at indices 0, 3, and 4, so the output is 3.

- **Input:** `Input: heights = [1, 2, 3, 4, 5], expected = [1, 2, 3, 4, 5]`  \
  **Explanation:** In this case, the 'heights' array is already in the expected order, so there are no differences. The output is 0.

{{< dots >}}
## Approach 🚀
The task is to find how many students are standing out of the expected order. This can be achieved by sorting the 'heights' array and comparing it with the 'expected' array.

### Initial Thoughts 💭
- The problem can be solved by comparing the current arrangement with the sorted arrangement.
- A direct approach would involve sorting the heights and then comparing the sorted list with the original list to count the mismatches.
{{< dots >}}
### Edge Cases 🌐
- There will be no empty input arrays as per the constraints.
- The solution should handle up to 100 students efficiently, as the maximum number of students is 100.
- If all students are already in the expected order, the output will be 0.
- The problem will always have at least one student, as the constraints guarantee the length of 'heights' is >= 1.
{{< dots >}}
## Code 💻
```cpp
int heightChecker(vector<int>& h) {

    auto m = max_element(h.begin(), h.end());

    vector<int> exp(*m + 1);

    for (int height : h) exp[height]++;

    int res = 0;

    for (int j = 1, i = 0; j < exp.size(); j++)
        while (exp[j]--) res += (h[i++] != j);

    return res;

}
```

This function checks how many students are standing in the wrong order based on their heights. It uses an efficient approach with frequency counting to track and compare expected versus actual positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int heightChecker(vector<int>& h) {
	```
	Define the function 'heightChecker' which takes a vector of integers 'h' representing the heights of students and returns the number of students who are standing in the wrong order.

2. **Find Maximum Element**
	```cpp
	    auto m = max_element(h.begin(), h.end());
	```
	Find the maximum height in the 'h' vector using the 'max_element' function, which returns an iterator to the maximum element.

3. **Frequency Array Initialization**
	```cpp
	    vector<int> exp(*m + 1);
	```
	Initialize a frequency array 'exp' where the index represents a possible height, and the value at each index represents the count of students with that height.

4. **Populate Frequency Array**
	```cpp
	    for (int height : h) exp[height]++;
	```
	Populate the 'exp' array by iterating through the 'h' vector, incrementing the count for each height.

5. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable 'res' to 0, which will keep track of how many students are standing in the wrong order.

6. **Outer Loop Setup**
	```cpp
	    for (int j = 1, i = 0; j < exp.size(); j++)
	```
	Start an outer loop that iterates through all possible heights, from 1 to the maximum height in the 'exp' array.

7. **Count Wrong Positions**
	```cpp
	        while (exp[j]--) res += (h[i++] != j);
	```
	For each height, check if the student at position 'i' in the 'h' vector is in the wrong position. If they are, increment the result counter 'res'.

8. **Return Result**
	```cpp
	    return res;
	```
	Return the final result, which is the total number of students standing in the wrong order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting of the heights array, where n is the number of students.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) to store the heights and expected arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/height-checker/description/)

---
{{< youtube mQAoeYaE3Xk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
