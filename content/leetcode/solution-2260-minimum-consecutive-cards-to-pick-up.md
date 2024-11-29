
+++
authors = ["grid47"]
title = "Leetcode 2260: Minimum Consecutive Cards to Pick Up"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2260: Minimum Consecutive Cards to Pick Up in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BIHnh-MH6CQ"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BIHnh-MH6CQ/maxresdefault.webp"
comments = true
+++



---
You are given an array `cards` where each element represents a card's value. A matching pair of cards occurs when two cards have the same value. Your task is to find the minimum number of consecutive cards you need to pick to guarantee that you have a pair of matching cards. If it's impossible to find a matching pair, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list `cards` containing integers where each integer represents the value of a card.
- **Example:** `cards = [7, 2, 3, 7, 5, 6]`
- **Constraints:**
	- 1 <= cards.length <= 105
	- 0 <= cards[i] <= 106

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of consecutive cards you need to pick up to have at least one matching pair of cards. If no pair exists, return -1.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest subarray of consecutive cards that contains at least one pair of matching cards.

- Use a hashmap to keep track of the last seen index of each card.
- As you iterate over the cards, check if the current card has been seen before.
- If a match is found, calculate the number of consecutive cards between the current and previous occurrence of the card.
- Keep track of the smallest such subarray length.
{{< dots >}}
### Problem Assumptions ✅
- The array will contain at least one pair of matching cards, or none at all.
{{< dots >}}
## Examples 🧩
- **Input:** `cards = [7, 2, 3, 7, 5, 6]`  \
  **Explanation:** We can pick the cards [7, 2, 3, 7], which contains a matching pair of 7's. Therefore, the minimum number of consecutive cards is 4.

- **Input:** `cards = [1, 2, 3, 4]`  \
  **Explanation:** There are no matching cards, so it is impossible to have a pair of matching cards. The output is -1.

{{< dots >}}
## Approach 🚀
We will use a hashmap to store the last index of each card and check for matching pairs while iterating through the list.

### Initial Thoughts 💭
- We need to find matching cards and track the smallest number of consecutive cards that contain such a pair.
- Using a hashmap will allow us to check for duplicates efficiently as we iterate through the array.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as the length of `cards` is guaranteed to be at least 1.
- The solution should handle arrays with lengths up to 100,000 efficiently.
- Ensure that if no matching pairs are found, the function correctly returns -1.
- The card values are within the range 0 to 1,000,000, so the solution should handle large numbers effectively.
{{< dots >}}
## Code 💻
```cpp
int minimumCardPickup(vector<int>& cards) {
    map<int, int> mp;
    int n = cards.size();
    int ans = n + 1;
    
    for(int i = 0; i < n; i++){
        if(mp.count(cards[i])) {
            ans = min(ans, i - mp[cards[i]] + 1);
        }
        mp[cards[i]] = i;            
    }
    
    return ans == n + 1? -1: ans;
}
```

This function finds the minimum number of cards to pick up so that a duplicate card is picked, by using a hashmap to track the last occurrence of each card. If no duplicate is found, it returns -1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumCardPickup(vector<int>& cards) {
	```
	The function `minimumCardPickup` takes a vector of integers, `cards`, and returns an integer representing the minimum number of cards to pick up to find a duplicate. If no duplicate is found, it returns -1.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	A map `mp` is initialized to store the last index at which each card appears in the vector `cards`.

3. **Size Calculation**
	```cpp
	    int n = cards.size();
	```
	The variable `n` is set to the size of the `cards` vector, representing the total number of cards.

4. **Answer Initialization**
	```cpp
	    int ans = n + 1;
	```
	The variable `ans` is initialized to `n + 1`, which is used to store the minimum number of cards between duplicates. This is initially set to a number larger than any possible valid result.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++){
	```
	A loop is started to iterate over each card in the `cards` vector by index `i`.

6. **Check for Duplicates**
	```cpp
	        if(mp.count(cards[i])) {
	```
	This checks if the current card has appeared before by checking if it exists in the map `mp`.

7. **Update Answer**
	```cpp
	            ans = min(ans, i - mp[cards[i]] + 1);
	```
	If the card has appeared before, the minimum number of cards between this and the previous occurrence is updated. The `min` function ensures that the smallest value is stored.

8. **Update Map**
	```cpp
	        mp[cards[i]] = i;            
	```
	The current card and its index are added to the map `mp`, updating the last occurrence of that card.

9. **Return Result**
	```cpp
	    return ans == n + 1? -1: ans;
	```
	After the loop finishes, the function checks if `ans` was updated. If no duplicate was found, `ans` will still be `n + 1`, and the function returns -1. Otherwise, it returns the minimum number of cards between duplicates.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear since we only make one pass over the input array, and hashmap operations (insert and lookup) are O(1) on average.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a hashmap to store the indices of the cards.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/)

---
{{< youtube BIHnh-MH6CQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
