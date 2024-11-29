
+++
authors = ["grid47"]
title = "Leetcode 1700: Number of Students Unable to Eat Lunch"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1700: Number of Students Unable to Eat Lunch in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Queue","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "d_cvtFwnOZg"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/d_cvtFwnOZg/maxresdefault.jpg"
comments = true
+++



---
In a school cafeteria, sandwiches are placed in a stack and students queue up to get one. Each student has a preference for the type of sandwich, and they either take the sandwich from the stack or move to the back of the queue if the sandwich is not to their liking. The goal is to determine how many students are unable to get a sandwich.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: 'students' representing the preference of each student (0 for circular, 1 for square), and 'sandwiches' representing the stack of sandwiches (with 0 for circular, 1 for square).
- **Example:** `[0, 1, 0, 1], [1, 0, 1, 0]`
- **Constraints:**
	- 1 <= students.length, sandwiches.length <= 100
	- students.length == sandwiches.length
	- students[i] and sandwiches[i] are either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the number of students who are unable to get a sandwich.
- **Example:** `2`
- **Constraints:**
	- The returned integer should be between 0 and the total number of students.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine how many students are unable to eat based on their preferences and the order of the sandwiches.

- Initialize a count for each type of sandwich in the stack and for each student preference.
- Iterate over the queue of students and check if the sandwich at the top of the stack matches the student's preference.
- If the student prefers the sandwich, remove it from the stack and move the student out of the queue.
- If the student does not want the sandwich, move them to the end of the queue.
- Continue the process until no student at the front of the queue can take the sandwich at the top of the stack.
{{< dots >}}
### Problem Assumptions ✅
- There will always be enough sandwiches for each student at the start, but some may not get one by the end of the process.
{{< dots >}}
## Examples 🧩
- **Input:** `[0, 1, 0, 1], [1, 0, 1, 0]`  \
  **Explanation:** All students are able to take a sandwich after a few moves, resulting in no students left without food.

- **Input:** `[1, 0, 1, 0, 1, 1], [0, 1, 1, 1, 0, 0]`  \
  **Explanation:** Two students are unable to get a sandwich by the end of the process due to mismatched preferences.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves simulating the sandwich distribution process, keeping track of which students are still waiting for a sandwich.

### Initial Thoughts 💭
- The process involves moving students around the queue and keeping track of their preferences relative to the sandwiches on top of the stack.
- We can optimize by using a simple queue to manage the students and a counter for the sandwich types to ensure we don't perform unnecessary operations.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as there is always at least one student and one sandwich.
- The solution should efficiently handle arrays up to 100 elements in length.
- If all students prefer the same type of sandwich, the outcome depends on the sandwiches available in the stack.
- The solution must be able to handle up to 100 students and sandwiches efficiently.
{{< dots >}}
## Code 💻
```cpp
int countStudents(vector<int>& A, vector<int>& B) {
    int count[] = {0, 0}, n = A.size(), k;
    for (int a : A)
        count[a]++;
    for (k = 0; k < n && count[B[k]] > 0; ++k)
        count[B[k]]--;
    return n - k;
}
```

This function simulates a process where each student in array B is matched with a student from array A. It counts how many students in array B do not find a match in A, and returns the number of unmatched students.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countStudents(vector<int>& A, vector<int>& B) {
	```
	Defines the function `countStudents` that takes two integer vectors, `A` and `B`, representing students and their preferences, and returns the number of students in `B` who cannot find a matching student in `A`.

2. **Variable Initialization**
	```cpp
	    int count[] = {0, 0}, n = A.size(), k;
	```
	Initializes an array `count` to count the occurrences of each student in array `A`, a variable `n` to store the size of array `A`, and a variable `k` for iteration.

3. **Counting Students in A**
	```cpp
	    for (int a : A)
	```
	Iterates through each student in array `A` to count the occurrences of each student using the `count` array.

4. **Counting Students in A**
	```cpp
	        count[a]++;
	```
	For each student `a` in array `A`, increments the corresponding count in the `count` array.

5. **Matching Students**
	```cpp
	    for (k = 0; k < n && count[B[k]] > 0; ++k)
	```
	Iterates through each student in array `B` and checks if the student can be matched with a student in `A` based on the `count` array. Decreases the count if a match is found.

6. **Decreasing Count for Matches**
	```cpp
	        count[B[k]]--;
	```
	If a match is found, decreases the count for student `B[k]` in the `count` array.

7. **Return Unmatched Students**
	```cpp
	    return n - k;
	```
	Returns the number of unmatched students, which is the total number of students (`n`) minus the number of students that were matched (`k`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each student and sandwich once, so the time complexity is O(n), where n is the number of students.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the queue of students, and O(1) if the queue is not explicitly stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

---
{{< youtube d_cvtFwnOZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
