
+++
authors = ["grid47"]
title = "Leetcode 2826: Sorting Three Groups"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2826: Sorting Three Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Q3wrIhMmpfA"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Q3wrIhMmpfA/maxresdefault.webp"
comments = true
+++



---
You are given an array `nums` containing elements that are either 1, 2, or 3. In each operation, you can remove an element from the array. The task is to return the minimum number of operations required to make the array non-decreasing.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of integers, where each element is one of the values 1, 2, or 3.
- **Example:** `For example, `nums = [3, 1, 2, 3, 1]``
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 3

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to make the array `nums` non-decreasing.
- **Example:** `For `nums = [2, 1, 3, 2, 3]`, the output is `2`.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of deletions to make the array non-decreasing.

- Track how many operations are needed to make the array non-decreasing for each possible value (1, 2, 3).
- Iterate through the array and compare each element with its previous value to determine if it should be removed.
{{< dots >}}
### Problem Assumptions ✅
- The array contains only 1, 2, or 3 as its elements.
- The array length is manageable (<= 100).
{{< dots >}}
## Examples 🧩
- **Input:** `For `nums = [3, 1, 2, 3, 1]``  \
  **Explanation:** By removing the first, third, and fourth elements, we can make the array non-decreasing: `[1, 2, 3]`.

{{< dots >}}
## Approach 🚀
The solution involves calculating the minimum number of operations required to make the array non-decreasing by tracking the number of deletions for each element in `nums`.

### Initial Thoughts 💭
- The elements in `nums` are restricted to 1, 2, and 3, which simplifies the problem.
- We need to track the number of removals for each value and minimize the number of deletions.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty (which won't happen according to constraints), no deletions are needed.
- Handle inputs with the maximum length of 100 efficiently.
- If all elements are already in non-decreasing order, no deletions are required.
- Ensure the solution works within time limits for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int minimumOperations(vector<int>& A) {
    int a = 0, b = 0, c = 0;
    for (int x: A) {
        a += x != 1;
        b = min(a, b + (x != 2));
        c = min(b, c + (x != 3));
    }
    return c;
}
```

This function calculates the minimum number of operations required to transform the elements of vector 'A' into the sequence [1, 2, 3], following a specific transformation order. Each operation involves changing an element in 'A' to match the desired sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumOperations(vector<int>& A) {
	```
	The function 'minimumOperations' is defined, taking a vector of integers 'A' as input and returning the minimum number of operations needed to transform 'A' into the sequence [1, 2, 3].

2. **Variable Initialization**
	```cpp
	    int a = 0, b = 0, c = 0;
	```
	Variables 'a', 'b', and 'c' are initialized to zero. These variables keep track of the number of operations required to transform elements into 1, 2, and 3, respectively.

3. **Loop Start**
	```cpp
	    for (int x: A) {
	```
	A for loop is started, iterating through each element 'x' of the vector 'A'. This loop is used to process each element in 'A' and update the operation counts.

4. **Update a**
	```cpp
	        a += x != 1;
	```
	The variable 'a' is incremented if the current element 'x' is not equal to 1, indicating that an operation is needed to transform this element to 1.

5. **Update b**
	```cpp
	        b = min(a, b + (x != 2));
	```
	The variable 'b' is updated to the minimum of the current 'a' and 'b + 1' if the current element 'x' is not equal to 2. This step tracks the operations needed to transform elements into 2.

6. **Update c**
	```cpp
	        c = min(b, c + (x != 3));
	```
	The variable 'c' is updated to the minimum of the current 'b' and 'c + 1' if the current element 'x' is not equal to 3. This step tracks the operations needed to transform elements into 3.

7. **Return Statement**
	```cpp
	    return c;
	```
	The function returns the value of 'c', which represents the minimum number of operations needed to transform the entire sequence into [1, 2, 3].

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the `nums` array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as only a few variables are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sorting-three-groups/description/)

---
{{< youtube Q3wrIhMmpfA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
