
+++
authors = ["grid47"]
title = "Leetcode 846: Hand of Straights"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 846: Hand of Straights in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "amnrMCVd2YI"
youtube_upload_date="2021-05-21"
youtube_thumbnail="https://i.ytimg.com/vi/amnrMCVd2YI/maxresdefault.jpg"
comments = true
+++



---
Alice has a set of cards, each with a value written on it. She wants to rearrange these cards into groups, where each group consists of `groupSize` consecutive cards. Given an integer array `hand` where `hand[i]` represents the value on the ith card, and an integer `groupSize`, return `true` if she can rearrange the cards into groups of consecutive numbers, or `false` otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array `hand` representing the values on the cards and an integer `groupSize` that denotes the required group size.
- **Example:** `Input: hand = [10, 12, 13, 11, 14, 15, 16], groupSize = 3`
- **Constraints:**
	- 1 <= hand.length <= 10^4
	- 0 <= hand[i] <= 10^9
	- 1 <= groupSize <= hand.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if it is possible to rearrange the cards into consecutive groups of size `groupSize`. Otherwise, return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- If the length of `hand` is not divisible by `groupSize`, return `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if we can group the cards into valid groups of consecutive numbers of size `groupSize`.

- Step 1: Count the frequency of each card in the hand using a map.
- Step 2: For each unique card, attempt to form a group by selecting consecutive cards. Decrease their frequencies as you form groups.
- Step 3: If at any point, forming a group is not possible (e.g., not enough consecutive cards), return false.
- Step 4: If all cards are grouped successfully, return true.
{{< dots >}}
### Problem Assumptions ✅
- The hand contains at least one card.
- The values on the cards are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: hand = [10, 12, 13, 11, 14, 15, 16], groupSize = 3`  \
  **Explanation:** The hand can be rearranged into three groups: [10, 11, 12], [13, 14, 15], and [16]. Therefore, the answer is `true`.

- **Input:** `Input: hand = [1, 2, 3, 4, 5], groupSize = 4`  \
  **Explanation:** The length of the hand is 5, which is not divisible by 4, so it's impossible to divide the cards into groups of 4. Therefore, the answer is `false`.

- **Input:** `Input: hand = [1, 2, 3, 4, 6, 7], groupSize = 3`  \
  **Explanation:** It's not possible to form the required groups because the card with value 5 is missing, which breaks the sequence. Therefore, the answer is `false`.

{{< dots >}}
## Approach 🚀
To solve the problem, we first count the frequency of each card and attempt to group consecutive cards by checking if each value can form a valid group with its consecutive numbers.

### Initial Thoughts 💭
- If the length of the hand is not divisible by `groupSize`, it's impossible to form valid groups.
- We need to efficiently manage card frequencies and check for possible consecutive sequences.
- This problem can be tackled using a greedy approach by starting from the smallest card value and trying to form groups of consecutive numbers.
{{< dots >}}
### Edge Cases 🌐
- The input cannot be empty as there must be at least one card.
- Ensure that the solution can handle large input sizes (up to 10^4 cards).
- If the length of the hand is not divisible by `groupSize`, return `false`.
- The solution must handle arrays where `groupSize` is larger than the number of unique cards efficiently.
{{< dots >}}
## Code 💻
```cpp
bool isNStraightHand(vector<int>& hand, int groupSize) {
    map<int, int> mp;
    for(int x: hand) mp[x]++;
    
    for(auto it: mp) {
        if(mp[it.first] > 0)
        for(int i = 1; i < groupSize; i++){
            mp[it.first + i] -= mp[it.first];
            if(mp[it.first + i] < 0)
                return false;
        }
        mp[it.first] = 0;
    }
    return true;
}
```

This function checks if a given hand of cards can be rearranged into groups of consecutive cards.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isNStraightHand(vector<int>& hand, int groupSize) {
	```
	The function `isNStraightHand` takes a hand of cards and checks whether the cards can be grouped into valid straight sequences of the specified size.

2. **Variable Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is initialized to store the count of each card in the hand.

3. **Counting Elements**
	```cpp
	    for(int x: hand) mp[x]++;
	```
	For each card in the hand, increment its count in the map `mp`.

4. **Loop Through Map**
	```cpp
	    for(auto it: mp) {
	```
	Iterate over each card in the map `mp`.

5. **Condition Check**
	```cpp
	        if(mp[it.first] > 0)
	```
	Check if the current card has not been used already.

6. **Inner Loop**
	```cpp
	        for(int i = 1; i < groupSize; i++){
	```
	Loop through the group size and check if the following cards can form a valid group.

7. **Card Deduction**
	```cpp
	            mp[it.first + i] -= mp[it.first];
	```
	Decrease the count of the card in the map for each card that should be part of the current group.

8. **Negative Count Check**
	```cpp
	            if(mp[it.first + i] < 0)
	```
	If any card required for the group has a negative count, it means the group cannot be formed, so return false.

9. **Return False**
	```cpp
	                return false;
	```
	Return false if the cards cannot form a valid straight hand.

10. **Reset Card Count**
	```cpp
	        mp[it.first] = 0;
	```
	Set the current card count to 0 after processing it.

11. **Return True**
	```cpp
	    return true;
	```
	Return true if all cards can be grouped into valid straight hands.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting of cards, which is O(n log n), followed by the greedy approach to form groups in O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the frequency map storing the count of each unique card.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/hand-of-straights/description/)

---
{{< youtube amnrMCVd2YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
