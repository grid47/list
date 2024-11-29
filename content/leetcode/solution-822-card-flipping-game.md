
+++
authors = ["grid47"]
title = "Leetcode 822: Card Flipping Game"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 822: Card Flipping Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp"
youtube = "K-g8sOWW4F0"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/K-g8sOWW4F0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp" 
    alt="A set of cards being flipped, with the correct card glowing softly as it's flipped over."
    caption="Solution to LeetCode 822: Card Flipping Game Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two arrays, fronts and backs, representing the numbers on the front and back of each card. Each card is initially placed with the front number facing up. You may flip any number of cards. An integer is considered 'good' if it appears on the back of some card and is not visible on the front of any card after flipping. Your task is to return the minimum possible 'good' integer after flipping the cards. If there is no such 'good' integer, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: 'fronts' and 'backs', each containing n integers. The ith integer in 'fronts' corresponds to the number on the front of the ith card, and the ith integer in 'backs' corresponds to the number on the back of the ith card.
- **Example:** `Input: fronts = [3, 5, 8, 10], backs = [5, 4, 8, 6]`
- **Constraints:**
	- n == fronts.length == backs.length
	- 1 <= n <= 1000
	- 1 <= fronts[i], backs[i] <= 2000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the minimum good integer that can be obtained after flipping some cards. If no such integer exists, return 0.
- **Example:** `Output: 4`
- **Constraints:**
	- The output must be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest integer that is on the back of at least one card but not on the front of any card after any number of flips. The approach involves identifying which integers are on both the front and back of cards and eliminating those from potential candidates.

- Step 1: Identify all integers that appear on both the front and back of the same card. These integers should not be considered.
- Step 2: Check the remaining integers on the front and back of the cards. The smallest integer that appears on the back but not on the front will be the result.
- Step 3: If no such integer exists, return 0.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays contain integers between 1 and 2000.
- The arrays are of equal length.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: fronts = [3, 5, 8, 10], backs = [5, 4, 8, 6]`  \
  **Explanation:** In this case, the number '5' appears on both the front and back of the first card, so it cannot be considered as a 'good' integer. The remaining possible candidates are 4 and 6. The minimum of these is 4, which is the result.

- **Input:** `Input: fronts = [1], backs = [1]`  \
  **Explanation:** Here, the number '1' is present on both the front and back of the same card, so no 'good' integer exists. Therefore, the result is 0.

{{< dots >}}
## Approach 🚀
The key to solving this problem is identifying numbers that appear both on the front and back of the same card. These numbers should be excluded from the set of potential 'good' integers. After that, we simply find the smallest remaining integer on the back of the cards.

### Initial Thoughts 💭
- The key to solving this problem is focusing on the numbers that appear both on the front and back of cards, as they cannot be 'good'.
- The challenge is to find the smallest integer that is visible only on the back of a card and not on the front of any card.
{{< dots >}}
### Edge Cases 🌐
- There are no empty input cases, as n is always at least 1.
- For large inputs, the solution must efficiently handle arrays of size up to 1000 without excessive computation.
- Ensure that cases where no 'good' integer exists (i.e., all numbers are the same on both sides of the cards) are handled correctly.
- The algorithm must process the cards efficiently, considering that n can be as large as 1000.
{{< dots >}}
## Code 💻
```cpp
int flipgame(vector<int>& fronts, vector<int>& backs) {
    unordered_set<int> same;
    for(int i = 0; i < fronts.size(); i++) if(fronts[i] == backs[i]) same.insert(fronts[i]);
    int res = 3000;
    for(auto &num: fronts) if(!same.count(num)) res = min(res, num);
    for(auto &num: backs)  if(!same.count(num)) res = min(res, num);        
    return res % 3000;
}
```

This function finds the minimum number on the cards that can be flipped, excluding those that have the same number on both the front and back.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int flipgame(vector<int>& fronts, vector<int>& backs) {
	```
	The function `flipgame` is defined to take two vectors of integers, `fronts` and `backs`, representing the numbers on the front and back of the cards, respectively.

2. **Set Initialization**
	```cpp
	    unordered_set<int> same;
	```
	An unordered set `same` is initialized to store the numbers that appear on both the front and the back of a card.

3. **Check for Matching Cards**
	```cpp
	    for(int i = 0; i < fronts.size(); i++) if(fronts[i] == backs[i]) same.insert(fronts[i]);
	```
	The loop iterates through all the cards, and for each card where the number on the front matches the number on the back, the number is inserted into the `same` set.

4. **Result Initialization**
	```cpp
	    int res = 3000;
	```
	The variable `res` is initialized to 3000, which serves as a placeholder for the minimum number. This is an arbitrarily large value for comparison purposes.

5. **Process Front Cards**
	```cpp
	    for(auto &num: fronts) if(!same.count(num)) res = min(res, num);
	```
	The loop iterates through the `fronts` vector, and for each number that is not in the `same` set, it updates `res` to be the minimum of `res` and the current number.

6. **Process Back Cards**
	```cpp
	    for(auto &num: backs)  if(!same.count(num)) res = min(res, num);        
	```
	The loop iterates through the `backs` vector, and for each number that is not in the `same` set, it updates `res` to be the minimum of `res` and the current number.

7. **Return Result**
	```cpp
	    return res % 3000;
	```
	The function returns the minimum number found modulo 3000, which ensures that the result is within a valid range. If no valid number is found, the function returns 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of cards.
- **Average Case:** O(n), where n is the number of cards.
- **Worst Case:** O(n), where n is the number of cards.

The time complexity is linear with respect to the number of cards, as we process each card only once.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of cards, for storing the set of excluded integers.
- **Worst Case:** O(n), where n is the number of cards, for storing the set of excluded integers.

The space complexity is proportional to the number of cards, as we store the numbers that appear on both the front and back.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/card-flipping-game/description/)

---
{{< youtube K-g8sOWW4F0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
