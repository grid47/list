
+++
authors = ["grid47"]
title = "Leetcode 948: Bag of Tokens"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 948: Bag of Tokens in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "prI82maTivg"
youtube_upload_date="2024-03-04"
youtube_thumbnail="https://i.ytimg.com/vi/prI82maTivg/maxresdefault.jpg"
comments = true
+++



---
You are given an array of tokens and an initial amount of power. The goal is to maximize the score by playing the tokens strategically. In each turn, you can either play a token face-up or face-down. Playing a token face-up costs you power but increases your score, while playing a token face-down gains you power but decreases your score. Your task is to determine the maximum score you can achieve after playing the tokens.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'tokens' representing the values of tokens, and an integer 'power' representing the initial power.
- **Example:** `Input: tokens = [50, 100, 200], power = 150`
- **Constraints:**
	- 0 <= tokens.length <= 1000
	- 0 <= tokens[i], power < 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum score that can be achieved by strategically playing the tokens.
- **Example:** `Output: 2`
- **Constraints:**
	- The result will always be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the score by playing tokens in a way that maximizes the score, considering the constraints of power and score.

- 1. Sort the tokens in ascending order.
- 2. Use two pointers: one pointing to the smallest token and the other to the largest token.
- 3. If your current power is sufficient to play the smallest token face-up, play it and increase the score.
- 4. If your score is at least 1, consider playing the largest token face-down to regain power.
- 5. Continue playing tokens in this manner until no more valid moves can be made.
{{< dots >}}
### Problem Assumptions ✅
- The tokens are played in a way that maximizes the score.
- The player can only play tokens when the conditions (either power or score) are met.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tokens = [50, 100], power = 150`  \
  **Explanation:** In this case, you can play token0 (50) face-up, reducing power to 100 and increasing the score to 1. The maximum score achievable is 1 because playing token1 (100) would require more power than you currently have.

- **Input:** `Input: tokens = [100, 200, 300], power = 250`  \
  **Explanation:** Play token0 (100) face-up, reducing power to 150 and increasing score to 1. Then, play token1 (200) face-up, reducing power to 0 and increasing score to 2. The maximum score achievable is 2.

{{< dots >}}
## Approach 🚀
The approach focuses on sorting the tokens and using a two-pointer technique to maximize the score while managing power and score constraints efficiently.

### Initial Thoughts 💭
- The problem can be viewed as optimizing a process where tokens are played based on the current state of power and score.
- Sorting the tokens helps in efficiently choosing the smallest and largest tokens to play.
- By using a greedy strategy with two pointers, we can maximize the score while managing power efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the result should be 0.
- Ensure the solution efficiently handles large input sizes, especially with the maximum number of tokens.
- If all tokens are larger than the initial power, no tokens can be played face-up.
- The solution should run within the time limits for up to 1000 tokens.
{{< dots >}}
## Code 💻
```cpp
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int res = 0, pts = 0, i = 0, j = tokens.size() - 1;
    while(i <= j) {
        if(power >= tokens[i]) {
            power -= tokens[i++];
            res = max(res, ++pts);
        } else if(pts > 0) {
            power += tokens[j--];
            pts--;
        } else break;
    }
    
    return res;
}
```

This function calculates the maximum score in the 'Bag of Tokens' problem. It sorts the tokens and uses a greedy approach with two pointers, maximizing score by spending tokens when possible and gaining points when necessary, while maintaining a balance of power.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int bagOfTokensScore(vector<int>& tokens, int power) {
	```
	The function `bagOfTokensScore` takes in a vector of tokens and a power value, returning the maximum score that can be achieved based on the given rules.

2. **Sorting Tokens**
	```cpp
	    sort(tokens.begin(), tokens.end());
	```
	Sort the tokens in ascending order to facilitate a greedy approach. This ensures that the smallest tokens are considered first to maximize the score.

3. **Variable Initialization**
	```cpp
	    int res = 0, pts = 0, i = 0, j = tokens.size() - 1;
	```
	Initialize variables: `res` to track the maximum score, `pts` to track the current points, `i` as the left pointer, and `j` as the right pointer for the token array.

4. **Main Loop Start**
	```cpp
	    while(i <= j) {
	```
	Start a while loop that continues as long as the left pointer `i` does not surpass the right pointer `j`.

5. **If Enough Power to Spend Token**
	```cpp
	        if(power >= tokens[i]) {
	```
	If there is enough power to spend the token at position `i` (the smallest available token), proceed with the action to gain points.

6. **Spend Token**
	```cpp
	            power -= tokens[i++];
	```
	Spend the token at position `i` (decrease power) and increment the left pointer `i`.

7. **Update Maximum Score**
	```cpp
	            res = max(res, ++pts);
	```
	Increase the points (`pts`) and update the maximum score (`res`) if the new score exceeds the previous maximum.

8. **Else If Points Available to Re-gain Power**
	```cpp
	        } else if(pts > 0) {
	```
	If points are available (i.e., `pts > 0`), you can trade points to gain power by taking a token from the right side of the array.

9. **Re-gain Power by Trading Points**
	```cpp
	            power += tokens[j--];
	```
	Gain power by taking the token at position `j` (the largest available token) and decrementing the right pointer `j`.

10. **Reduce Points**
	```cpp
	            pts--;
	```
	Reduce the points (`pts`) as one point is used to gain power.

11. **End Loop Condition**
	```cpp
	        } else break;
	```
	If neither condition is satisfied (i.e., there is not enough power and no points to trade), break out of the loop.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the maximum score (`res`) achieved.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n), where n is the number of tokens.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the sorted list of tokens.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/bag-of-tokens/description/)

---
{{< youtube prI82maTivg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
