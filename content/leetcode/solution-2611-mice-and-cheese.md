
+++
authors = ["grid47"]
title = "Leetcode 2611: Mice and Cheese"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2611: Mice and Cheese in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "S_pCzVdQX9U"
youtube_upload_date="2023-04-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/S_pCzVdQX9U/maxresdefault.webp"
comments = true
+++



---
You have two mice and a set of n different types of cheese. Each type of cheese has a different point value when eaten by either mouse. The first mouse must eat exactly k types of cheese, while the second mouse eats the remaining cheese types. Your task is to maximize the total points the two mice can achieve by distributing the cheese types between the mice.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays, reward1 and reward2, each of length n, where reward1[i] represents the points the first mouse gets from eating the ith cheese type, and reward2[i] represents the points the second mouse gets from eating the ith cheese type. Additionally, you are given a non-negative integer k, which represents the number of cheese types the first mouse should eat.
- **Example:** `reward1 = [2, 5, 3, 4], reward2 = [1, 2, 6, 4], k = 3`
- **Constraints:**
	- 1 <= n == reward1.length == reward2.length <= 10^5
	- 1 <= reward1[i], reward2[i] <= 1000
	- 0 <= k <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum points that the two mice can achieve, considering that the first mouse eats exactly k types of cheese.
- **Example:** `Output: 18`
- **Constraints:**
	- The output will be a single integer representing the maximum points the mice can achieve.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the total points by distributing the cheeses between the two mice, ensuring that the first mouse eats exactly k types of cheese.

- Step 1: Calculate the difference in reward between reward1[i] and reward2[i] for each cheese.
- Step 2: Sort the cheeses based on the difference in rewards, from largest to smallest.
- Step 3: Assign the first mouse the k cheeses that provide the highest rewards for it, and assign the remaining cheeses to the second mouse.
- Step 4: Calculate the total points and return it.
{{< dots >}}
### Problem Assumptions ✅
- The rewards are non-negative integers.
- The first mouse is guaranteed to eat exactly k cheeses.
{{< dots >}}
## Examples 🧩
- **Input:** `reward1 = [2, 5, 3, 4], reward2 = [1, 2, 6, 4], k = 3`  \
  **Explanation:** The first mouse eats the 2nd, 3rd, and 4th cheeses, giving points 5, 3, and 4. The second mouse eats the 1st cheese, giving 2 points. The total points are 5 + 3 + 4 + 2 = 18.

- **Input:** `reward1 = [1, 1], reward2 = [1, 1], k = 1`  \
  **Explanation:** In this case, the first mouse eats one cheese, and the second mouse eats the other. The total points will be 1 + 1 = 2.

{{< dots >}}
## Approach 🚀
The approach focuses on maximizing the reward for the first mouse by sorting the cheese types based on the difference between the rewards of the two mice and assigning the cheeses accordingly.

### Initial Thoughts 💭
- We need to maximize the reward for the first mouse by selecting k types of cheese that yield the highest reward for it.
- It is important to prioritize the cheeses that give the first mouse the most points while considering the second mouse's reward for the remaining cheeses.
{{< dots >}}
### Edge Cases 🌐
- If reward1 or reward2 is empty, return 0 as no points can be earned.
- Ensure that the algorithm efficiently handles the maximum constraint of 10^5 cheese types.
- If k is 0, the first mouse does not eat any cheese, and the second mouse eats all the cheeses.
- Handle cases where all rewards are equal, where the two mice have identical reward values for each cheese.
{{< dots >}}
## Code 💻
```cpp

int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
    
    int n = r1.size();

    vector<vector<int>> ans;
    
    for(int i = 0; i < n; i++) {
        ans.push_back({r1[i] - r2[i], r1[i], r2[i]});
    }
    sort(ans.begin(), ans.end(), greater<vector<int>>());
    
    int res = 0, i = 0;
    while(k--) {
        res += ans[i++][1];
    }
    while(i < n) res += ans[i++][2];
    return res;
}
```

This function calculates the total maximum cheese mice can get by selecting `k` mice from `r1` and the rest from `r2`, sorting based on the difference between `r1[i]` and `r2[i]`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
	```
	Defines the function `miceAndCheese`, which takes two vectors `r1` and `r2` representing the number of cheeses for mice in two locations, and an integer `k` representing the number of mice to select from `r1`.

2. **Variable Declaration**
	```cpp
	    int n = r1.size();
	```
	Initializes variable `n` to the size of the input vector `r1`, representing the number of mice.

3. **Vector Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Declares a 2D vector `ans` to store the difference between `r1[i]` and `r2[i]`, along with the values from `r1[i]` and `r2[i]`.

4. **Loop - Calculation**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through each mouse and calculate the difference between the cheese values in `r1[i]` and `r2[i]`.

5. **Push to Vector**
	```cpp
	        ans.push_back({r1[i] - r2[i], r1[i], r2[i]});
	```
	Adds a new element to the `ans` vector containing the difference `r1[i] - r2[i]`, followed by `r1[i]` and `r2[i]`.

6. **Sorting**
	```cpp
	    sort(ans.begin(), ans.end(), greater<vector<int>>());
	```
	Sorts the vector `ans` in descending order based on the first element of each sub-array (the difference `r1[i] - r2[i]`).

7. **Variable Initialization**
	```cpp
	    int res = 0, i = 0;
	```
	Initializes two variables: `res` to accumulate the total cheese and `i` to keep track of the index.

8. **While Loop - Select `k` Mice**
	```cpp
	    while(k--) {
	```
	Starts a loop that runs `k` times to add the best `k` mice from `r1` to the result.

9. **Add Cheese from `r1`**
	```cpp
	        res += ans[i++][1];
	```
	Adds the cheese value from `r1[i]` to `res` for the current best selection, then increments `i`.

10. **While Loop - Add Remaining Mice**
	```cpp
	    while(i < n) res += ans[i++][2];
	```
	Adds the remaining cheese values from `r2[i]` to `res` for the remaining mice.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total amount of cheese accumulated after selecting `k` mice from `r1` and the rest from `r2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the number of cheese types.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the differences in rewards for each cheese type.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/mice-and-cheese/description/)

---
{{< youtube S_pCzVdQX9U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
