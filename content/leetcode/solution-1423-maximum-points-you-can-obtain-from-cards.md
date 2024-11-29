
+++
authors = ["grid47"]
title = "Leetcode 1423: Maximum Points You Can Obtain from Cards"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1423: Maximum Points You Can Obtain from Cards in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TsA4vbtfCvo"
youtube_upload_date="2021-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/TsA4vbtfCvo/maxresdefault.jpg"
comments = true
+++



---
You are given an array `cardPoints` representing the points of cards arranged in a row. In each step, you can pick the first or the last card from the row. Your goal is to pick exactly `k` cards and maximize the sum of the points of the cards you select.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `cardPoints` and an integer `k`, representing the cards and the number of cards to be selected respectively.
- **Example:** `[1, 2, 3, 4, 5, 6, 1], k = 3`
- **Constraints:**
	- 1 <= cardPoints.length <= 10^5
	- 1 <= cardPoints[i] <= 10^4
	- 1 <= k <= cardPoints.length

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum score obtained by selecting exactly `k` cards.
- **Example:** `12`
- **Constraints:**
	- The output is the maximum sum of the points of `k` cards selected from the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum score by selecting exactly `k` cards from either end of the row.

- Step 1: Use dynamic programming to track the total sum of cards taken from the left and right ends of the row.
- Step 2: Evaluate each possible way of taking cards and find the maximum sum.
- Step 3: Return the maximum score found.
{{< dots >}}
### Problem Assumptions ✅
- The array `cardPoints` contains at least one element.
- You can only pick `k` cards from the beginning or the end of the row.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 2, 3, 4, 5, 6, 1], k = 3`  \
  **Explanation:** In this case, picking the last three cards results in the maximum sum: 1 + 6 + 5 = 12.

- **Input:** `[9, 7, 7, 9, 7, 7, 9], k = 7`  \
  **Explanation:** Here, you need to take all the cards, so the maximum sum is the sum of all the cards, which is 55.

{{< dots >}}
## Approach 🚀
The approach involves calculating the maximum score by considering all ways of picking `k` cards from the two ends of the row.

### Initial Thoughts 💭
- This problem involves selecting elements from the start or the end of an array.
- Dynamic programming or sliding window techniques can be applied to track the maximum score.
- We need to efficiently calculate the score for various ways of selecting `k` cards.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the length of the array is at least 1.
- For large inputs, ensure that the solution runs in linear time to handle up to 100,000 elements.
- Handle the case where all cards have the same point value, or where `k` is equal to the length of the array.
- The array size can be large, but the time complexity of the solution should allow for efficient computation.
{{< dots >}}
## Code 💻
```cpp
int maxScore(vector<int>& card, int k) {
    int n = card.size();
    vector<int> frt, bck;
    frt.push_back(0);
    bck.push_back(0);
    for(int i = 0; i < n; i++) {

    frt.push_back(frt.back() + card[i]);
 bck.push_back(bck.back() + card[n - 1 - i]);

    }

    int ans = bck[k];
    for(int i = 1; i <= k; i++) {
        
        ans = max(ans, frt[i] + bck[k - i]);
        }
    return ans;
}
```

The `maxScore` function calculates the maximum score possible by choosing up to `k` cards from the beginning and the end of the vector `card`. It uses dynamic programming to compute the maximum possible score by splitting the cards between the front and the back.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxScore(vector<int>& card, int k) {
	```
	Defines the function `maxScore` that takes a vector of integers `card` and an integer `k` as input and returns the maximum score possible.

2. **Variable Initialization**
	```cpp
	    int n = card.size();
	```
	Initializes the variable `n` to the size of the `card` vector, which represents the total number of cards available.

3. **Variable Initialization**
	```cpp
	    vector<int> frt, bck;
	```
	Declares two vectors `frt` and `bck`, which will store cumulative sums for the front and back sections of the `card` vector.

4. **Vector Operations**
	```cpp
	    frt.push_back(0);
	```
	Pushes a `0` into the `frt` vector to represent the cumulative sum of cards from the front (starting with zero).

5. **Vector Operations**
	```cpp
	    bck.push_back(0);
	```
	Pushes a `0` into the `bck` vector to represent the cumulative sum of cards from the back (starting with zero).

6. **Loop Constructs**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Begins a loop that iterates over all the cards in the `card` vector.

7. **Vector Operations**
	```cpp
	    frt.push_back(frt.back() + card[i]);
	```
	For each card `i`, adds the current card's value to the cumulative sum in the `frt` vector, which tracks the sum of cards taken from the front.

8. **Vector Operations**
	```cpp
	    bck.push_back(bck.back() + card[n - 1 - i]);
	```
	For each card `i`, adds the current card's value to the cumulative sum in the `bck` vector, which tracks the sum of cards taken from the back.

9. **Score Initialization**
	```cpp
	    int ans = bck[k];
	```
	Initializes the variable `ans` with the sum of the first `k` cards from the back, which represents the score starting with cards from the back.

10. **Loop Constructs**
	```cpp
	    for(int i = 1; i <= k; i++) {
	```
	Begins a loop that iterates through possible splits of the `k` cards between the front and the back.

11. **Score Calculation**
	```cpp
	        ans = max(ans, frt[i] + bck[k - i]);
	```
	Updates the value of `ans` to be the maximum score found by splitting the `k` cards between the front and back sections.

12. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the maximum score found from the different possible splits of the cards.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), since we process each element of the array exactly once.
- **Worst Case:** O(n), as we need to compute the score for each possible selection of `k` cards.

The time complexity is linear, making it efficient for large input sizes.

### Space Complexity 💾
- **Best Case:** O(n), as the space usage depends on the length of the input array.
- **Worst Case:** O(n), since we store the cumulative sums of cards from both ends.

The space complexity is linear, as we need extra space for the cumulative sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

---
{{< youtube TsA4vbtfCvo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
