
+++
authors = ["grid47"]
title = "Leetcode 1947: Maximum Compatibility Score Sum"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1947: Maximum Compatibility Score Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HinLw7adoH8"
youtube_upload_date="2021-07-25"
youtube_thumbnail="https://i.ytimg.com/vi/HinLw7adoH8/maxresdefault.jpg"
comments = true
+++



---
You are given a survey with n questions where each question's answer is either 0 (no) or 1 (yes). The survey is completed by m students and m mentors. Each student's answers are represented by a 2D array of size m x n, and similarly, each mentor's answers are represented by another 2D array. The compatibility score of a student-mentor pair is calculated as the number of answers that are the same for both the student and the mentor. Your task is to find the optimal pairing of students to mentors that maximizes the sum of the compatibility scores.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two 2D arrays: one representing the students' answers and another representing the mentors' answers. Both arrays have m rows (one for each student and mentor) and n columns (one for each question's answer). Each entry in the arrays is either 0 or 1.
- **Example:** `students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]`
- **Constraints:**
	- m == students.length == mentors.length
	- n == students[i].length == mentors[j].length
	- 1 <= m, n <= 8
	- students[i][k] is either 0 or 1
	- mentors[j][k] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of compatibility scores that can be achieved by optimally pairing students to mentors.
- **Example:** `Output: 8`
- **Constraints:**
	- The output should be a single integer representing the maximum compatibility score sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the optimal pairings between students and mentors that maximize the sum of compatibility scores.

- Step 1: For each student-mentor pairing, calculate the compatibility score by counting the number of matching answers.
- Step 2: Find the optimal pairing by checking all possible permutations of student-mentor assignments.
- Step 3: Sum the compatibility scores of the optimal pairings and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The input sizes are small enough (maximum 8 students/mentors and 8 questions) that checking all permutations is computationally feasible.
- Each student will be assigned to exactly one mentor, and vice versa.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]`  \
  **Explanation:** The possible pairings are evaluated to find the one with the highest sum of compatibility scores. The optimal pairings in this case are student 0 with mentor 2 (compatibility score 3), student 1 with mentor 0 (score 2), and student 2 with mentor 1 (score 3). The total score is 8.

- **Input:** `Input: students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]`  \
  **Explanation:** In this case, all compatibility scores are 0 because no student-answer matches any mentor-answer, so the total score is 0.

{{< dots >}}
## Approach 🚀
The approach is to explore all possible pairings between students and mentors, calculate the compatibility score for each pairing, and select the optimal combination that maximizes the total score.

### Initial Thoughts 💭
- Since m and n are relatively small (maximum of 8), brute-forcing through all possible permutations of student-mentor pairings is computationally feasible.
- The problem is essentially about finding the maximum matching between two sets (students and mentors) based on a compatibility function.
{{< dots >}}
### Edge Cases 🌐
- Empty student or mentor arrays are not valid inputs as per the problem constraints.
- Since m and n are capped at 8, the input size is small and does not require special handling for large inputs.
- When all answers are 0 or 1, ensure the compatibility scores are calculated correctly.
- Ensure that the input arrays are of size m x n and contain only 0 or 1 values.
{{< dots >}}
## Code 💻
```cpp
int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    vector<int> pos;
    int ans = 0;
    for(int i = 0; i < students.size(); i++)
        pos.push_back(i);
    do {

        int curr = 0;
        for(int i = 0; i < students.size(); i++)
        for(int j = 0; j < students[pos[i]].size(); j++)
            curr += (students[pos[i]][j] == mentors[i][j]);
        ans = max(ans, curr);

    } while(next_permutation(pos.begin(), pos.end()));
    return ans;
}
```

This function computes the maximum compatibility sum between students and mentors, by evaluating different permutations of student-mentor assignments.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
	```
	The function begins by accepting two parameters: 'students' and 'mentors', both of which are 2D vectors representing their respective compatibility values.

2. **Variable Initialization**
	```cpp
	    vector<int> pos;
	```
	A vector 'pos' is initialized to store the indices of the students for permutation. This will help in exploring different student-mentor assignments.

3. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	The variable 'ans' is initialized to 0. It will hold the maximum compatibility sum found through all permutations of student-mentor pairings.

4. **Loop over Students**
	```cpp
	    for(int i = 0; i < students.size(); i++)
	```
	A loop is initiated to iterate over the students, used to generate the initial list of indices in 'pos'.

5. **Filling pos**
	```cpp
	        pos.push_back(i);
	```
	Each student's index 'i' is added to the vector 'pos'. This will be used to explore different permutations of student-mentor assignments.

6. **Do-While Loop**
	```cpp
	    do {
	```
	A do-while loop is used to iterate through all permutations of the student assignments (in 'pos') using the 'next_permutation' function.

7. **Permutation Evaluation**
	```cpp
	        int curr = 0;
	```
	A temporary variable 'curr' is initialized to 0, which will store the current compatibility sum for this specific permutation of student-mentor pairings.

8. **Loop over Students**
	```cpp
	        for(int i = 0; i < students.size(); i++)
	```
	The second loop iterates over the students, evaluating the compatibility of each student-mentor pair for the current permutation.

9. **Inner Loop over Attributes**
	```cpp
	        for(int j = 0; j < students[pos[i]].size(); j++)
	```
	This nested loop iterates over the compatibility attributes of each student-mentor pair.

10. **Compatibility Check**
	```cpp
	            curr += (students[pos[i]][j] == mentors[i][j]);
	```
	For each attribute, the compatibility of the student and mentor pair is checked. If they match, 'curr' is incremented by 1.

11. **Update Maximum Compatibility**
	```cpp
	        ans = max(ans, curr);
	```
	After evaluating a permutation, 'ans' is updated to the maximum value between the current maximum compatibility sum and the compatibility sum of the current permutation.

12. **End of Permutation Evaluation**
	```cpp
	    } while(next_permutation(pos.begin(), pos.end()));
	```
	The do-while loop continues until all permutations of the 'pos' vector have been evaluated.

13. **Return Statement**
	```cpp
	    return ans;
	```
	Once all permutations have been evaluated, the maximum compatibility sum 'ans' is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m!)
- **Average Case:** O(m!)
- **Worst Case:** O(m!)

Since we need to check all permutations of student-mentor pairings, the time complexity is factorial in m, i.e., O(m!).

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is linear in m, as we need space to store the current permutation of students and mentors.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-compatibility-score-sum/description/)

---
{{< youtube HinLw7adoH8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
