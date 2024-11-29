
+++
authors = ["grid47"]
title = "Leetcode 2037: Minimum Number of Moves to Seat Everyone"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2037: Minimum Number of Moves to Seat Everyone in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wS7Ag33hf8E"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/wS7Ag33hf8E/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays: one representing the available seats in a row and the other representing the students who need to be seated. Each element in the arrays corresponds to a student's desired seat or the position of an available seat. The task is to determine the minimum number of moves required to seat all students. A move consists of moving a student from one seat to another.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: 'seats' representing the available seat positions and 'students' representing the students' desired seat positions.
- **Example:** `[[3, 1, 5, 2], [2, 5, 1, 3]]`
- **Constraints:**
	- 1 <= seats.length, students.length <= 100
	- 1 <= seats[i], students[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to seat all students in the correct seats.
- **Example:** `6`
- **Constraints:**
	- The solution must be efficient, ideally O(n log n), due to the sorting step.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum number of moves required to seat all students by sorting both arrays and matching each student's desired position with the available seats.

- 1. Sort the 'seats' and 'students' arrays.
- 2. For each student, calculate the absolute difference between the student's desired seat and the actual seat.
- 3. Sum up the differences to get the total number of moves.
{{< dots >}}
### Problem Assumptions ✅
- Each student must sit in one seat, and each seat can only be occupied by one student.
- The seating order does not matter, only the minimum number of moves to achieve the seating arrangement.
{{< dots >}}
## Examples 🧩
- **Input:** `[[3, 1, 5, 2], [2, 5, 1, 3]]`  \
  **Explanation:** In this case, we sort the seats and students arrays: [1, 2, 3, 5] for seats and [1, 2, 3, 5] for students. The absolute differences are: |1-1| + |2-2| + |3-3| + |5-5| = 0 + 0 + 0 + 0 = 6 moves.

{{< dots >}}
## Approach 🚀
The key idea is to minimize the number of moves by matching the closest available seat to each student, which can be achieved by sorting both the 'seats' and 'students' arrays.

### Initial Thoughts 💭
- Sorting both arrays allows us to match the closest seat to each student, minimizing the movement required.
- The solution is straightforward and efficient, requiring only sorting followed by a simple sum of differences.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the solution handles cases where the input arrays are empty (though it is not expected in this problem).
- Handle the case where the number of students and seats is large, up to 100 elements.
- Consider cases where all students are already seated in their correct seats, resulting in 0 moves.
- The solution should work efficiently for inputs with up to 100 elements.
{{< dots >}}
## Code 💻
```cpp
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    
    int res = 0;
    for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
    
    return res;
}
```

This function calculates the minimum number of moves required to seat students in specific seats, where the seats and students are represented by two integer arrays. The function first sorts both arrays and then computes the sum of absolute differences between corresponding elements in the sorted arrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minMovesToSeat(vector<int>& seats, vector<int>& students) {
	```
	This line defines the function `minMovesToSeat`, which takes two vectors of integers: `seats` (the positions of seats) and `students` (the positions of students).

2. **Sorting**
	```cpp
	    sort(seats.begin(), seats.end());
	```
	Here, we sort the `seats` vector in ascending order to align them with the students' positions.

3. **Sorting**
	```cpp
	    sort(students.begin(), students.end());
	```
	Similarly, we sort the `students` vector in ascending order to facilitate optimal seating arrangement.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This line initializes a variable `res` to zero, which will hold the cumulative sum of the absolute differences between seat and student positions.

5. **Loop**
	```cpp
	    for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
	```
	This `for` loop iterates over each pair of seats and students, calculating the absolute difference between their positions and adding it to `res`.

6. **Return**
	```cpp
	    return res;
	```
	The function returns the value of `res`, which represents the minimum number of moves required to arrange the students in the seats.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting the arrays.
- **Average Case:** O(n log n) for sorting the arrays and summing the differences.
- **Worst Case:** O(n log n) for sorting, where n is the number of students or seats.

The time complexity is dominated by the sorting step, which takes O(n log n) time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n) for storing the seat and student arrays.

The space complexity is O(n) due to the storage of the input arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/)

---
{{< youtube wS7Ag33hf8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
