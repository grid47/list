
+++
authors = ["grid47"]
title = "Leetcode 1014: Best Sightseeing Pair"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1014: Best Sightseeing Pair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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
You are given an array where each element represents the value of a sightseeing spot. The distance between two sightseeing spots is the difference in their indices. The score of a pair of sightseeing spots i and j (where i < j) is calculated as values[i] + values[j] + (i - j), which includes the values of both spots and subtracts the distance between them. Your task is to find the maximum score of any pair of sightseeing spots.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers, where each integer represents the value of a sightseeing spot.
- **Example:** `values = [5, 3, 6, 2, 4]`
- **Constraints:**
	- 2 <= values.length <= 5 * 10^4
	- 1 <= values[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the maximum score of any pair of sightseeing spots.
- **Example:** `Output: 8`
- **Constraints:**
	- The result should be an integer representing the maximum score.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the pair of sightseeing spots that maximizes the score, which involves considering both the values and the distance between the spots.

- Iterate through the array and for each spot, compute the score with all previous spots while keeping track of the maximum score.
- Maintain a running value for the maximum score by subtracting the distance between the spots.
{{< dots >}}
### Problem Assumptions ✅
- The input will always have at least two sightseeing spots.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: values = [5, 3, 6, 2, 4]`  \
  **Explanation:** In this case, the maximum score occurs between the first and third spots: 5 + 6 + (0 - 2) = 8.

- **Input:** `Input: values = [1, 2]`  \
  **Explanation:** For this example, the score is 1 + 2 + (0 - 1) = 2, which is the maximum score.

{{< dots >}}
## Approach 🚀
The optimal approach is to iterate through the array, maintaining a running maximum score based on the current spot and the previous ones. This can be done efficiently using a greedy approach.

### Initial Thoughts 💭
- We need to maximize the score, which involves both the values of the sightseeing spots and the distance between them.
- By iterating through the array while keeping track of the maximum score at each step, we can find the solution in linear time.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the input will always have at least two values.
- The solution should be efficient enough to handle up to 50,000 spots in linear time.
- If all values are the same, the solution should still correctly calculate the maximum score based on the distances.
- The number of spots is at least 2, ensuring there is always a valid pair.
{{< dots >}}
## Code 💻
```cpp
int maxScoreSightseeingPair(vector<int>& val) {

    int res = 0, cur = 0;

    for(int x : val) {
        res = max(res, cur + x);
        cur = max(cur, x) - 1;
    }

    return res;
}
```

This function calculates the maximum score of a sightseeing pair, where the score is calculated based on the sum of values from two points with a particular condition that the second point must be after the first. It uses a greedy approach to find the maximum score by iterating through the values in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxScoreSightseeingPair(vector<int>& val) {
	```
	Declares the function `maxScoreSightseeingPair` which takes a vector of integers `val` representing the values of sightseeing spots, and returns an integer representing the maximum score of a sightseeing pair.

2. **Initialization**
	```cpp
	    int res = 0, cur = 0;
	```
	Sets `res` to 0, as initially no score has been calculated, and `cur` to 0, which will hold the current potential score during the iteration.

3. **Loop Through Values**
	```cpp
	    for(int x : val) {
	```
	Iterates over each value `x` in the `val` vector representing the value of a sightseeing spot.

4. **Update Result**
	```cpp
	        res = max(res, cur + x);
	```
	Updates the maximum score `res` by comparing the current score `cur + x` (the sum of the current potential score and the current value) with the previous maximum score.

5. **Update Current Score**
	```cpp
	        cur = max(cur, x) - 1;
	```
	Updates the current potential score `cur` by comparing it with the value `x`. The current score is reduced by 1 as part of the problem's condition (since the second point must be after the first).

6. **Return Statement**
	```cpp
	    return res;
	```
	Returns the maximum score of a sightseeing pair, which is the result of evaluating all possible pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the array once, leading to a time complexity of O(n), where n is the number of sightseeing spots.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since the solution only uses a few variables to track the maximum score and the current best score.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-sightseeing-pair/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
