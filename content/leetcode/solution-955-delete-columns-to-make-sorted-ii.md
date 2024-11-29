
+++
authors = ["grid47"]
title = "Leetcode 955: Delete Columns to Make Sorted II"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 955: Delete Columns to Make Sorted II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an array of strings, where each string is of the same length. You are allowed to delete any number of columns, and after deleting the selected columns, the remaining strings should be in lexicographically non-decreasing order. Your task is to determine the minimum number of columns that must be deleted to achieve this order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of n strings, each string having the same length.
- **Example:** `Input: strs = ["ab","ac","bb"]`
- **Constraints:**
	- 1 <= strs.length <= 100
	- 1 <= strs[i].length <= 100
	- strs[i] consists of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the minimum number of columns that need to be deleted to make the array of strings lexicographically ordered.
- **Example:** `Output: 1`
- **Constraints:**
	- The output is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of columns that need to be deleted while ensuring the remaining strings are in lexicographically non-decreasing order.

- 1. Initialize a counter to track the number of deletions.
- 2. Traverse through each column and check if the current column violates the lexicographical order between adjacent strings.
- 3. If a violation is found, increment the deletion counter and skip further checks for that column.
- 4. After checking each column, return the counter as the minimum number of deletions required.
{{< dots >}}
### Problem Assumptions ✅
- All input strings are valid and consist only of lowercase English letters.
- The length of all strings is the same.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: strs = ["ab","ac","bb"]`  \
  **Explanation:** In this case, deleting the second column (index 1) results in the array ["a", "c", "b"], which is lexicographically ordered.

- **Input:** `Input: strs = ["dc","ba","za"]`  \
  **Explanation:** In this case, no deletions are required since the array is already in lexicographic order.

- **Input:** `Input: strs = ["zyx","wvu","tsr"]`  \
  **Explanation:** Here, all columns violate the lexicographic order, so all columns must be deleted, resulting in an answer of 3.

{{< dots >}}
## Approach 🚀
We approach this problem by checking each column for lexicographical violations between adjacent rows. If a column violates the order, we count it as a column to delete.

### Initial Thoughts 💭
- The problem is primarily about identifying columns that cause lexicographical violations.
- We need to check each column for lexicographical order violations and count how many columns need to be deleted.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one string, so no need to handle empty inputs.
- For large inputs with 100 strings and each string having 100 characters, the algorithm should efficiently process the array within the time limits.
- The strings may contain identical characters, but the logic still applies for detecting lexicographical violations.
- Ensure the solution handles arrays with up to 100 strings and strings of length up to 100 characters efficiently.
{{< dots >}}
## Code 💻
```cpp
int minDeletionSize(vector<string>& strs) {
    int res = 0, m = strs.size(), n = strs[0].size();
    int i , j;
    vector<bool> sorted(m - 1, false);
    for(j = 0; j < n; j++) {
        for(i = 0; i < m - 1; i++) {
            if(!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                res++;
                break;
            }
        }
        if(i < m - 1) continue;
        for(i = 0; i < m - 1; i++) {
            sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
        }
    }
    return res;
}
```

This function calculates the minimum number of columns to delete in order to make the rows of a list of strings sorted lexicographically. It iterates column by column, maintaining a state of sorted rows using a boolean vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minDeletionSize(vector<string>& strs) {
	```
	Function declaration for `minDeletionSize` which takes a vector of strings as input and returns an integer result.

2. **Variable Initialization**
	```cpp
	    int res = 0, m = strs.size(), n = strs[0].size();
	```
	Initialize variables: `res` to track the number of deletions, `m` for the number of rows, and `n` for the number of columns.

3. **Loop Variables**
	```cpp
	    int i , j;
	```
	Declare loop variables `i` and `j` to iterate over rows and columns respectively.

4. **Sorted Vector**
	```cpp
	    vector<bool> sorted(m - 1, false);
	```
	Initialize a boolean vector `sorted` of size `m-1` to track which adjacent rows are already sorted.

5. **Outer Loop**
	```cpp
	    for(j = 0; j < n; j++) {
	```
	Iterate through each column in the strings using the outer loop variable `j`.

6. **Inner Loop**
	```cpp
	        for(i = 0; i < m - 1; i++) {
	```
	Inner loop to check adjacent rows for sorting in the current column.

7. **Check Condition**
	```cpp
	            if(!sorted[i] && strs[i][j] > strs[i + 1][j]) {
	```
	Check if the current column violates the sorting order for adjacent rows that are not already sorted.

8. **Increment Result**
	```cpp
	                res++;
	```
	If the current column violates sorting, increment the deletion count `res`.

9. **Break**
	```cpp
	                break;
	```
	Exit the inner loop early if a deletion is determined for the current column.

10. **Skip Current Column**
	```cpp
	        if(i < m - 1) continue;
	```
	If the column is marked for deletion, skip further processing for it.

11. **Update Sorted**
	```cpp
	        for(i = 0; i < m - 1; i++) {
	```
	Update the `sorted` state for adjacent rows based on the current column.

12. **Update Condition**
	```cpp
	            sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
	```
	Mark adjacent rows as sorted if the current column satisfies the sorting condition.

13. **Return Result**
	```cpp
	    return res;
	```
	Return the total number of columns that need to be deleted to make rows sorted.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

The time complexity is O(n * m), where n is the number of strings and m is the length of each string, as we need to check each column for each string.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a constant amount of extra space for tracking deletions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
