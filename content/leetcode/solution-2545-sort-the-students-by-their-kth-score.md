
+++
authors = ["grid47"]
title = "Leetcode 2545: Sort the Students by Their Kth Score"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2545: Sort the Students by Their Kth Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YwAAwSzIavU"
youtube_upload_date="2023-01-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YwAAwSzIavU/maxresdefault.webp"
comments = true
+++



---
You are given a matrix of scores, where each row represents a student and each column represents an exam. You need to sort the students based on their scores in the k-th exam, from the highest to the lowest. Return the sorted matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an m x n matrix `score` representing the scores of m students in n exams. You are also given an integer k, the index of the exam to use for sorting.
- **Example:** `score = [[20, 5, 11], [10, 9, 14], [15, 18, 7]], k = 1`
- **Constraints:**
	- 1 <= m, n <= 250
	- 1 <= score[i][j] <= 10^5
	- score contains distinct integers
	- 0 <= k < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the matrix of students sorted by their scores in the k-th exam from highest to lowest.
- **Example:** `[[15, 18, 7], [10, 9, 14], [20, 5, 11]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the students based on the score in the k-th exam.

- 1. Extract the score for the k-th exam for each student.
- 2. Sort the students based on their k-th exam score in descending order.
- 3. Return the sorted matrix.
{{< dots >}}
### Problem Assumptions ✅
- All exam scores are distinct across students.
- The number of students and exams are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `score = [[20, 5, 11], [10, 9, 14], [15, 18, 7]], k = 1`  \
  **Explanation:** In this example, the students are sorted by their score in the second exam (k = 1). The sorted order is based on the scores: 18, 9, and 5.

- **Input:** `score = [[30, 40], [20, 50], [10, 30]], k = 0`  \
  **Explanation:** Here, the sorting is done by the scores in the first exam (k = 0), resulting in the order: 30, 20, and 10.

{{< dots >}}
## Approach 🚀
We need to sort the students based on the score in the k-th exam using sorting algorithms.

### Initial Thoughts 💭
- We need a way to extract and compare scores based on the k-th exam for each student.
- This can be done efficiently by using sorting techniques.
- We can use a sorting function that sorts by the k-th exam score in descending order.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the matrix is empty, though it is unlikely in this problem due to constraints.
- Handle cases with maximum values of m and n (e.g., m = 250, n = 250).
- Handle cases where the scores in the k-th exam are close in value.
- Ensure that the solution works efficiently with the maximum constraints.
{{< dots >}}
## Code 💻
```cpp
int k;
int partition(vector<vector<int>>& score, int low, int high) {

  // select the rightmost element as pivot
  vector<int> pivot = score[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (score[j][k] > pivot[k]) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(score[i], score[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(score[i + 1], score[high]);

  // return the partition point
  return (i + 1);
}
void quickSort(vector<vector<int>>& score, int low, int high) {
    if (low < high) {
        int pi = partition(score, low, high);
        quickSort(score, low, pi - 1);
        quickSort(score, pi + 1, high);
    }
}
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    this->k = k;
    quickSort(score, 0, score.size() - 1);
    return score;
}
```

This code implements the QuickSort algorithm to sort students' scores based on a specific column 'k'. The main function 'sortTheStudents' sorts the students by the score at column 'k', using the 'quickSort' helper function, which internally uses a partition method to organize the elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int k;
	```
	A variable 'k' is declared to hold the column index used to sort the students' scores.

2. **Function Definition**
	```cpp
	int partition(vector<vector<int>>& score, int low, int high) {
	```
	The 'partition' function is defined to perform the partitioning step of the QuickSort algorithm, which divides the dataset based on a pivot element.

3. **Pivot Initialization**
	```cpp
	  vector<int> pivot = score[high];
	```
	The pivot is initialized as the last element in the current sub-array of 'score'.

4. **Pointer Setup**
	```cpp
	  int i = (low - 1);
	```
	The pointer 'i' is initialized to 'low - 1'. It is used to track where to place elements greater than the pivot.

5. **For Loop**
	```cpp
	  for (int j = low; j < high; j++) {
	```
	A for loop is used to iterate over each element of the array from index 'low' to 'high' (excluding the pivot).

6. **Condition Check**
	```cpp
	    if (score[j][k] > pivot[k]) {
	```
	If the element at index 'j' is greater than the pivot, we need to swap it with the element at position 'i'.

7. **Increment Pointer**
	```cpp
	      i++;
	```
	The pointer 'i' is incremented, indicating that a new element has been placed in the 'greater than pivot' section.

8. **Swap Operation**
	```cpp
	      swap(score[i], score[j]);
	```
	The elements at indices 'i' and 'j' are swapped if the condition is met.

9. **Pivot Final Swap**
	```cpp
	  swap(score[i + 1], score[high]);
	```
	The pivot is swapped with the element at position 'i + 1', which is the correct position for the pivot in the sorted array.

10. **Partition End**
	```cpp
	  return (i + 1);
	```
	The partition function returns the index of the pivot after placing it in its correct position.

11. **Function Definition**
	```cpp
	void quickSort(vector<vector<int>>& score, int low, int high) {
	```
	The 'quickSort' function is defined, which recursively sorts the elements by dividing them into smaller partitions.

12. **Base Case**
	```cpp
	    if (low < high) {
	```
	Checks if the low index is less than the high index, which is a condition to continue sorting.

13. **Recursive Call**
	```cpp
	        int pi = partition(score, low, high);
	```
	Calls the partition function to return the index of the pivot element, which divides the array into two sub-arrays.

14. **Left Subarray Sort**
	```cpp
	        quickSort(score, low, pi - 1);
	```
	Recursively calls 'quickSort' to sort the left sub-array.

15. **Right Subarray Sort**
	```cpp
	        quickSort(score, pi + 1, high);
	```
	Recursively calls 'quickSort' to sort the right sub-array.

16. **Function Definition**
	```cpp
	vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
	```
	Defines the 'sortTheStudents' function that initializes 'k' and calls the 'quickSort' function to sort the student scores.

17. **Sorting Call**
	```cpp
	    this->k = k;
	```
	The value of 'k' is assigned to the instance variable to be used during sorting.

18. **Sorting Operation**
	```cpp
	    quickSort(score, 0, score.size() - 1);
	```
	Calls 'quickSort' to start sorting the entire array of student scores.

19. **Return Sorted Scores**
	```cpp
	    return score;
	```
	Returns the sorted array of student scores.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m log m), where m is the number of students.
- **Average Case:** O(m log m), since sorting will dominate the time complexity.
- **Worst Case:** O(m log m), since the sorting algorithm will take O(m log m) in the worst case.

The time complexity is determined by the sorting step, which is O(m log m), where m is the number of students.

### Space Complexity 💾
- **Best Case:** O(1), if the sorting is done in-place.
- **Worst Case:** O(m), where m is the number of students, due to the space required for sorting.

The space complexity is O(m), where m is the number of students, if we use additional space for sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/)

---
{{< youtube YwAAwSzIavU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
