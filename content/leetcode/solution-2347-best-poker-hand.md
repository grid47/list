
+++
authors = ["grid47"]
title = "Leetcode 2347: Best Poker Hand"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2347: Best Poker Hand in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6BijC5dBUOA"
youtube_upload_date="2022-07-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6BijC5dBUOA/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `ranks` and a character array `suits`. These represent a set of 5 playing cards, where each card has a rank (from 1 to 13) and a suit (one of 'a', 'b', 'c', or 'd'). Determine the best possible poker hand you can make from the cards.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays, `ranks` and `suits`, both of length 5. `ranks[i]` is the rank of the ith card and `suits[i]` is the suit of the ith card.
- **Example:** `ranks = [8, 3, 5, 12, 8], suits = ["a", "b", "a", "a", "a"]`
- **Constraints:**
	- ranks.length == 5
	- suits.length == 5
	- 1 <= ranks[i] <= 13
	- 'a' <= suits[i] <= 'd'

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string representing the best type of poker hand that can be made from the given cards.
- **Example:** `"Flush"`
- **Constraints:**
	- The output must be one of the following: 'Flush', 'Three of a Kind', 'Pair', or 'High Card'.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the best hand from the set of 5 cards.

- Check if all cards have the same suit for a flush.
- Check if there are three cards with the same rank for a 'Three of a Kind'.
- Check if there are two cards with the same rank for a 'Pair'.
- If none of the above, return 'High Card'.
{{< dots >}}
### Problem Assumptions ✅
- The input always contains exactly 5 cards.
- Ranks and suits are valid according to the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `ranks = [8, 3, 5, 12, 8], suits = ["a", "b", "a", "a", "a"]`  \
  **Explanation:** All cards have the same suit 'a', so we have a Flush.

- **Input:** `ranks = [11, 11, 9, 11, 5], suits = ["b", "b", "c", "d", "a"]`  \
  **Explanation:** Three cards have the same rank (11), so we have a 'Three of a Kind'.

- **Input:** `ranks = [7, 2, 7, 9, 6], suits = ["d", "d", "b", "a", "b"]`  \
  **Explanation:** Two cards have the same rank (7), so we have a 'Pair'.

{{< dots >}}
## Approach 🚀
The goal is to check for each type of hand in order of priority (flush, three of a kind, pair), and return the first matching hand.

### Initial Thoughts 💭
- We can use a hashmap to count the frequency of ranks and suits.
- First, check if all cards are of the same suit for a Flush. Then check for Three of a Kind and Pair, and default to High Card.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the number of cards is always 5.
- There are no large inputs, as the input size is fixed at 5.
- Ensure that all cards are valid and adhere to the rank and suit constraints.
- The input will always contain 5 cards with valid ranks and suits.
{{< dots >}}
## Code 💻
```cpp
string bestHand(vector<int>& ranks, vector<char>& suits) {
    unordered_map<int,int> m1;
    unordered_map<char,int> m2;
    for(auto i:ranks) m1[i]++;
    for(auto i:suits) m2[i]++;
    string ans="";
    for(auto i:m2){
        if(i.second==5){
            return "Flush";
        }
    }
    for(auto i:m1){
        if(i.second>=3)
        return "Three of a Kind";
        else if(i.second==2)
        ans="Pair";
    }

    return ans==""?"High Card":ans;
}
```

This function evaluates a hand of cards, determining if it is a 'Flush', 'Three of a Kind', 'Pair', or 'High Card' based on the input card ranks and suits.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string bestHand(vector<int>& ranks, vector<char>& suits) {
	```
	This line defines the function 'bestHand', which takes two parameters: 'ranks' (card ranks) and 'suits' (card suits). It returns a string indicating the type of the hand.

2. **Map Initialization**
	```cpp
	    unordered_map<int,int> m1;
	```
	An unordered map 'm1' is created to store the frequency of each card rank.

3. **Map Initialization**
	```cpp
	    unordered_map<char,int> m2;
	```
	Another unordered map 'm2' is created to store the frequency of each card suit.

4. **For Loop - Ranks**
	```cpp
	    for(auto i:ranks) m1[i]++;
	```
	This loop iterates through the 'ranks' vector and updates the frequency of each rank in the 'm1' map.

5. **For Loop - Suits**
	```cpp
	    for(auto i:suits) m2[i]++;
	```
	This loop iterates through the 'suits' vector and updates the frequency of each suit in the 'm2' map.

6. **Variable Initialization**
	```cpp
	    string ans="";
	```
	Initialize an empty string 'ans', which will store the result of the hand type.

7. **For Loop - Suits Check**
	```cpp
	    for(auto i:m2){
	```
	Loop through each suit and its frequency in the 'm2' map.

8. **Flush Check**
	```cpp
	        if(i.second==5){
	```
	If a suit appears 5 times, the hand is a 'Flush'.

9. **Flush Return**
	```cpp
	            return "Flush";
	```
	Return 'Flush' if all five cards have the same suit.

10. **For Loop - Ranks Check**
	```cpp
	    for(auto i:m1){
	```
	Loop through each rank and its frequency in the 'm1' map.

11. **Three of a Kind Check**
	```cpp
	        if(i.second>=3)
	```
	If any rank appears 3 or more times, the hand is 'Three of a Kind'.

12. **Three of a Kind Return**
	```cpp
	        return "Three of a Kind";
	```
	Return 'Three of a Kind' if a rank appears 3 or more times.

13. **Pair Check**
	```cpp
	        else if(i.second==2)
	```
	If a rank appears exactly 2 times, it is considered a 'Pair'.

14. **Pair Assignment**
	```cpp
	        ans="Pair";
	```
	Set 'ans' to 'Pair' if a rank appears exactly 2 times.

15. **Return Statement**
	```cpp
	    return ans==""?"High Card":ans;
	```
	If 'ans' is still empty (no pair or three of a kind), return 'High Card'. Otherwise, return the value of 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution runs in constant time since the input size is always fixed at 5.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only use a small number of auxiliary variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-poker-hand/description/)

---
{{< youtube 6BijC5dBUOA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
