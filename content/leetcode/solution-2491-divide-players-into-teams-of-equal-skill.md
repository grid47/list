
+++
authors = ["grid47"]
title = "Leetcode 2491: Divide Players Into Teams of Equal Skill"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2491: Divide Players Into Teams of Equal Skill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cueOpK5QMEA"
youtube_upload_date="2024-10-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cueOpK5QMEA/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers representing the skill levels of players. You need to divide the players into pairs such that the sum of the skill levels of each pair is the same across all pairs. If it's possible to form such pairs, return the sum of their chemistry, which is the product of the skill levels in each pair. If no such division is possible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of integers where each integer represents the skill level of a player.
- **Example:** `skill = [1, 5, 2, 4, 3, 3]`
- **Constraints:**
	- 2 <= skill.length <= 100000
	- skill.length is always even.
	- 1 <= skill[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the chemistry for all valid pairs, or -1 if it's impossible to form the pairs.
- **Example:** `Output: 22`
- **Constraints:**
	- The sum of chemistry values will be computed only for valid teams.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the players can be divided into pairs with equal total skill level, and calculate the sum of their chemistry.

- 1. Sort the skill levels of players.
- 2. Check if the sum of the first and last skill levels in the sorted array is the same for all adjacent pairs.
- 3. If the total skill sum is the same for all pairs, calculate the chemistry for each pair and return the sum. Otherwise, return -1.
{{< dots >}}
### Problem Assumptions ✅
- Players' skill levels are always valid positive integers.
- There will always be an even number of players in the input.
{{< dots >}}
## Examples 🧩
- **Input:** `skill = [1, 5, 2, 4, 3, 3]`  \
  **Explanation:** Here, after sorting the array, the players form pairs (1, 5), (2, 4), and (3, 3) which have equal total skill (6). The chemistry is calculated as 1*5 + 2*4 + 3*3 = 5 + 8 + 9 = 22.

- **Input:** `skill = [1, 2, 3, 4]`  \
  **Explanation:** This input cannot form valid pairs because the total skill sum of any pair does not match, so the output is -1.

- **Input:** `skill = [3, 4]`  \
  **Explanation:** With only two players, they form a valid pair with a sum of 7, and the chemistry is 3*4 = 12.

{{< dots >}}
## Approach 🚀
To solve this problem, we first sort the array to make pairing easier and check if all pairs have the same total skill level.

### Initial Thoughts 💭
- The problem requires ensuring the total skill for each pair is consistent.
- Sorting the array allows easier pairing of players with compatible skill levels.
- Sorting the array helps in pairing the smallest and largest available players to achieve a balanced sum.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain an even number of players and won't be empty.
- For large inputs, ensure the sorting operation and pair checking runs efficiently.
- The skill levels are between 1 and 1000, so there will be no zero or negative skill levels.
- Ensure efficient handling of the upper limit of skill array length (up to 100,000 players).
{{< dots >}}
## Code 💻
```cpp
long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());
    int n = skill.size();
    int l = 0, r = n - 1;
    
    int sum = skill[l] + skill[r];
    long long prod = skill[l] * skill[r];
    
    l++, r--;
    while(l < r) {
        if(sum != (skill[l] + skill[r])) return -1;
        prod += skill[l] * skill[r];
        l++;
        r--;
    }
    return prod;
}
```

This function divides players into pairs based on their skill levels and computes the total product of their skills if the sum of each pair is equal. If not, it returns -1 indicating an invalid division.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	long long dividePlayers(vector<int>& skill) {
	```
	This line declares the function `dividePlayers`, which takes a vector `skill` representing the skill levels of players and returns a `long long` value representing the total product of paired skills.

2. **Sorting**
	```cpp
	    sort(skill.begin(), skill.end());
	```
	This line sorts the `skill` vector in ascending order to facilitate pairing the weakest and strongest players.

3. **Variable Initialization**
	```cpp
	    int n = skill.size();
	```
	This line initializes the variable `n` to the size of the `skill` vector, representing the total number of players.

4. **Pointers Initialization**
	```cpp
	    int l = 0, r = n - 1;
	```
	Here, two pointers, `l` (left) and `r` (right), are initialized to point to the first and last elements of the sorted `skill` vector, respectively.

5. **Sum Calculation**
	```cpp
	    int sum = skill[l] + skill[r];
	```
	This line calculates the sum of the skills of the leftmost (`l`) and rightmost (`r`) players.

6. **Product Calculation**
	```cpp
	    long long prod = skill[l] * skill[r];
	```
	Here, the product of the skills of the leftmost and rightmost players is calculated and stored in `prod`.

7. **Pointer Adjustment**
	```cpp
	    l++, r--;
	```
	The pointers `l` and `r` are moved inward, `l` is incremented, and `r` is decremented.

8. **Loop Start**
	```cpp
	    while(l < r) {
	```
	This while loop runs as long as the left pointer is less than the right pointer, processing each pair of players.

9. **Sum Validation**
	```cpp
	        if(sum != (skill[l] + skill[r])) return -1;
	```
	Inside the loop, the sum of the current pair of players' skills is checked. If it does not match the sum of the first pair, `-1` is returned indicating an invalid division.

10. **Product Update**
	```cpp
	        prod += skill[l] * skill[r];
	```
	If the sum is valid, the product of the current pair of skills is added to `prod`.

11. **Pointer Update**
	```cpp
	        l++;
	```
	The left pointer `l` is incremented to move to the next player.

12. **Pointer Update**
	```cpp
	        r--;
	```
	The right pointer `r` is decremented to move to the next player.

13. **Return Statement**
	```cpp
	    return prod;
	```
	Once all pairs have been processed, the function returns the total product of the pairs' skills.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting operation, which is O(n log n), where n is the length of the skill array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for the sorted array, but it could be reduced to O(1) if sorting is done in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/)

---
{{< youtube cueOpK5QMEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
