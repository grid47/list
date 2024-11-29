
+++
authors = ["grid47"]
title = "Leetcode 2555: Maximize Win From Two Segments"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2555: Maximize Win From Two Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "trj4pn5uzZ0"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/trj4pn5uzZ0/maxresdefault.webp"
comments = true
+++



---
You are given a sorted array `prizePositions` containing positions of prizes along a line and an integer `k`. Your task is to select two segments of length `k` such that you can maximize the number of prizes collected. The two segments may overlap, and you can collect all prizes within either of the segments.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `prizePositions` sorted in non-decreasing order, and an integer `k` representing the length of the two segments.
- **Example:** `prizePositions = [1, 1, 2, 2, 3, 3, 5], k = 2`
- **Constraints:**
	- 1 <= prizePositions.length <= 10^5
	- 1 <= prizePositions[i] <= 10^9
	- 0 <= k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of prizes you can collect by selecting two segments of length `k` optimally.
- **Example:** `7`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number of prizes collected by optimally selecting two segments.

- 1. Iterate through the array `prizePositions` while maintaining a dynamic programming array `dp` to track the maximum number of prizes collectable with one segment.
- 2. For each position, calculate the maximum number of prizes you can win by selecting a segment ending at that position.
- 3. Update the result by considering the combination of the second segment after the first segment, ensuring the total number of prizes is maximized.
{{< dots >}}
### Problem Assumptions ✅
- The array `prizePositions` is sorted in non-decreasing order.
{{< dots >}}
## Examples 🧩
- **Input:** `prizePositions = [1, 1, 2, 2, 3, 3, 5], k = 2`  \
  **Explanation:** By selecting two segments: [1, 3] and [3, 5], all 7 prizes are covered.

- **Input:** `prizePositions = [1, 2, 3, 4], k = 0`  \
  **Explanation:** With `k = 0`, the segments can only cover a single prize, so the maximum is 2 prizes with segments [3, 3] and [4, 4].

{{< dots >}}
## Approach 🚀
We aim to maximize the number of prizes collected by optimally choosing two segments. We use dynamic programming to track the best selection of prizes for each segment.

### Initial Thoughts 💭
- We need to select the maximum possible number of prizes within two non-overlapping segments.
- We can use dynamic programming to track the maximum number of prizes we can win by selecting one segment and combining it with the next segment.
{{< dots >}}
### Edge Cases 🌐
- The array `prizePositions` will always contain at least one element, according to the constraints.
- Ensure that the solution works efficiently with large inputs where `prizePositions.length` can go up to 100,000.
- Handle cases where `k = 0`, which means the segments can only cover a single prize.
- The solution should handle large numbers up to the maximum constraint of `10^9`.
{{< dots >}}
## Code 💻
```cpp
int maximizeWin(vector<int>& pos, int k) {
    
    int n = pos.size(), res = 0;
    
    vector<int> dp(n + 1, 0);
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(pos[j] < pos[i] - k) j++;
        dp[i + 1] = max(dp[i], i - j + 1);
        res = max(res, i - j + 1 + dp[j]);
    }
    
    return res;
}
```

The function 'maximizeWin' aims to find the maximum number of wins a player can achieve given the list of positions in the game and a constraint 'k'. The code uses dynamic programming with a sliding window approach to calculate the result efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximizeWin(vector<int>& pos, int k) {
	```
	This is the function definition for 'maximizeWin'. It takes a vector 'pos' representing the positions and an integer 'k' representing the constraint.

2. **Variable Initialization**
	```cpp
	    int n = pos.size(), res = 0;
	```
	Here, the integer 'n' is initialized to the size of the 'pos' vector, and 'res' is initialized to 0 to store the result (maximum number of wins).

3. **Dynamic Programming Array Initialization**
	```cpp
	    vector<int> dp(n + 1, 0);
	```
	A dynamic programming (DP) array 'dp' is initialized with size 'n + 1' and all elements set to 0. This array will store the maximum number of wins up to each position.

4. **Variable Initialization**
	```cpp
	    int j = 0;
	```
	The variable 'j' is initialized to 0 and will be used as the sliding window pointer to track the range of valid positions for counting wins.

5. **Loop Through Positions**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This for loop iterates over the positions in the 'pos' vector, processing each position one by one.

6. **Sliding Window Movement**
	```cpp
	        while(pos[j] < pos[i] - k) j++;
	```
	The while loop shifts the window pointer 'j' to the right until the condition 'pos[j] < pos[i] - k' is no longer true, maintaining the valid range of positions.

7. **Update DP Array**
	```cpp
	        dp[i + 1] = max(dp[i], i - j + 1);
	```
	This line updates the DP array at index 'i + 1', calculating the maximum wins between the current value 'dp[i]' and the number of wins in the valid window (i - j + 1).

8. **Update Result**
	```cpp
	        res = max(res, i - j + 1 + dp[j]);
	```
	This line updates the result 'res' to the maximum value between the current 'res' and the sum of the number of wins in the current window (i - j + 1) plus the previously computed wins up to position 'j'.

9. **Return Result**
	```cpp
	    return res;
	```
	The function returns the value of 'res', which is the maximum number of wins a player can achieve given the positions and constraint 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the `prizePositions` array.
- **Average Case:** O(n), since we iterate through the array once and use dynamic programming to compute the result.
- **Worst Case:** O(n), as we need to iterate over the entire array to calculate the best result.



### Space Complexity 💾
- **Best Case:** O(1), if no additional space is used.
- **Worst Case:** O(n), since we need to store the dynamic programming array `dp` of size n.

Space complexity is dominated by the `dp` array used for dynamic programming.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximize-win-from-two-segments/description/)

---
{{< youtube trj4pn5uzZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
