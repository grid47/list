
+++
authors = ["grid47"]
title = "Leetcode 2140: Solving Questions With Brainpower"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2140: Solving Questions With Brainpower in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yPaLLSEDlX4"
youtube_upload_date="2023-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/yPaLLSEDlX4/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D list of questions. Each question is represented by a pair of values: the points earned by solving it and the number of subsequent questions you can't solve after completing it. You need to maximize the total points earned by choosing which questions to solve.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `questions`, where each element is a list `[points, brainpower]` representing a question.
- **Example:** `Input: questions = [[3,2],[4,3],[4,4],[2,5]]`
- **Constraints:**
	- 1 <= questions.length <= 10^5
	- questions[i].length == 2
	- 1 <= points_i, brainpower_i <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the maximum number of points you can earn by selecting which questions to solve.
- **Example:** `Output: 5`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the total points earned by deciding whether to solve or skip each question, taking into account the brainpower required for future questions.

- Start by deciding whether to solve or skip the first question.
- If the current question is solved, skip the next `brainpower` questions.
- Use dynamic programming to store and compute the maximum points for each state.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid as per the problem constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `questions = [[3,2],[4,3],[4,4],[2,5]]`  \
  **Explanation:** In this example, the best strategy is to solve question 0, which earns 3 points, and then solve question 3, which earns 2 points. The total is 5 points.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming. We will recursively decide whether to solve a question or skip it, and store the results for each state to avoid redundant calculations.

### Initial Thoughts 💭
- If we solve a question, we cannot solve the subsequent `brainpower` questions.
- We can use dynamic programming to store results for each question index and number of points we can earn.
- A greedy approach will not work due to the constraints of skipping questions, so dynamic programming is the best choice.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one question, so the input will never be empty.
- The algorithm must efficiently handle large inputs, with up to 10^5 questions.
- If all `brainpower` values are high, you will need to be careful in selecting which questions to solve.
- The algorithm should be able to compute the result efficiently within the input constraints.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> qns;
vector<long long> mem;

long long dp(int idx) {
    if(idx >= qns.size()) return 0;
    
    if(mem[idx] != -1) return mem[idx];
    
    long long ans = dp(idx + 1);
    
    ans = max(ans, (long long) qns[idx][0] + dp(idx + 1+ qns[idx][1]));
    
    return mem[idx] = ans;
}

long long mostPoints(vector<vector<int>>& questions) {
    qns = questions;
    
    mem.resize(qns.size(), -1);
    return dp(0);
    
}
```

This is the implementation of a dynamic programming solution that calculates the maximum points achievable from a set of questions. Each question has a certain number of points and a time cost associated with it.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> qns;
	```
	This initializes a 2D vector `qns` to hold the question data, where each element represents a question with points and time.

2. **Variable Initialization**
	```cpp
	vector<long long> mem;
	```
	This initializes a vector `mem` to store the results of subproblems in dynamic programming, helping to avoid redundant calculations.

3. **Base Case**
	```cpp
	if(idx >= qns.size()) return 0;
	```
	This is the base case of the recursive `dp` function. If the index `idx` exceeds the size of the question list, it returns 0 (no more points to accumulate).

4. **Memoization Check**
	```cpp
	if(mem[idx] != -1) return mem[idx];
	```
	This checks if the result for the current index `idx` has already been computed and stored in `mem`. If so, it returns the cached value.

5. **Recursive Call**
	```cpp
	long long ans = dp(idx + 1);
	```
	This makes a recursive call to `dp` for the next index, representing the decision to skip the current question.

6. **Recursive Decision**
	```cpp
	ans = max(ans, (long long) qns[idx][0] + dp(idx + 1 + qns[idx][1]));
	```
	This calculates the result by considering the possibility of solving the current question. It adds the points for the current question and makes a recursive call, skipping the time cost associated with it.

7. **Memoization Store**
	```cpp
	return mem[idx] = ans;
	```
	This stores the computed result for the current index `idx` in `mem` to avoid redundant calculations and returns the value.

8. **Main Function**
	```cpp
	long long mostPoints(vector<vector<int>>& questions) {
	```
	This defines the main function `mostPoints`, which serves as the entry point to solve the problem, accepting a list of questions.

9. **Initialize Variables**
	```cpp
	qns = questions;
	```
	This initializes the `qns` vector with the input `questions` vector, which contains the problem data.

10. **Memoization Initialization**
	```cpp
	mem.resize(qns.size(), -1);
	```
	This initializes the `mem` vector with a size equal to the number of questions, filling it with `-1` to indicate that no subproblem has been solved yet.

11. **Return Statement**
	```cpp
	return dp(0);
	```
	This calls the `dp` function starting from index `0` and returns the result, which is the maximum points achievable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the best, average, and worst cases, the time complexity is O(n), where n is the number of questions. This is because each question is processed once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the memoization table used to store results for each question.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/solving-questions-with-brainpower/description/)

---
{{< youtube yPaLLSEDlX4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
