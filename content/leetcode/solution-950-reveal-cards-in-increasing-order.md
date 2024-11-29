
+++
authors = ["grid47"]
title = "Leetcode 950: Reveal Cards In Increasing Order"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 950: Reveal Cards In Increasing Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sorting","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "i2QrUdwWlak"
youtube_upload_date="2024-04-10"
youtube_thumbnail="https://i.ytimg.com/vi/i2QrUdwWlak/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers, where each integer represents a unique card in a deck. The deck can be shuffled into any order, and the goal is to reorder it such that the cards are revealed in increasing order. To do this, you repeatedly reveal the top card and move the next card to the bottom of the deck until all cards are revealed. The problem is to return the order of cards that would reveal them in increasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing the deck of cards.
- **Example:** `Input: deck = [20, 15, 10, 5, 25]`
- **Constraints:**
	- The deck contains between 1 and 1000 cards.
	- Each card value is a unique integer between 1 and 10^6.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array representing the deck of cards after revealing them in increasing order.
- **Example:** `Output: [5, 15, 10, 20, 25]`
- **Constraints:**
	- The output must be an array of integers representing the cards in the required order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the order of cards such that revealing them one by one follows the increasing order of their values.

- 1. Sort the deck in increasing order.
- 2. Use a queue to simulate the process of revealing the cards and moving the next one to the bottom.
- 3. Place each card in the result based on the queue’s order.
{{< dots >}}
### Problem Assumptions ✅
- The deck is shuffled initially, but the goal is to determine the order in which cards should be revealed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: deck = [5, 10, 20, 15]`  \
  **Explanation:** After sorting, the deck becomes [5, 10, 15, 20]. We simulate revealing the cards as follows: 5 is revealed, 10 moves to the bottom, 15 is revealed, 20 moves to the bottom, 10 is revealed, and finally 20 is revealed.

- **Input:** `Input: deck = [1, 2, 3, 4]`  \
  **Explanation:** After sorting, the deck becomes [1, 2, 3, 4]. We simulate revealing them in order: 1, 2, 3, and 4.

{{< dots >}}
## Approach 🚀
The approach involves sorting the deck and using a queue to simulate the process of revealing and moving cards in the deck.

### Initial Thoughts 💭
- Sorting the deck is the key to ensuring that the cards are revealed in increasing order.
- The main challenge is to implement the correct simulation of the card reveal and move-to-bottom steps.
{{< dots >}}
### Edge Cases 🌐
- If the input deck is empty, the output should be an empty array.
- If the deck contains a large number of cards (e.g., 1000), the solution must efficiently handle the size.
- If the deck contains only one card, the output is simply that card.
- The algorithm must be efficient enough to handle up to 1000 cards.
{{< dots >}}
## Code 💻
```cpp
vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int n = deck.size();
    queue<int> q;
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++)
        q.push(i);
    
    for(int i = 0; i < n; i++) {
        res[q.front()] = deck[i];
        q.pop();
        if(!q.empty()) {
            q.push(q.front());
            q.pop();                
        }
    }
    
    return res;
}
```

This function takes a deck of cards (represented as an array) and returns the deck after performing a series of operations to rearrange the cards in increasing order, following a specific pattern. The pattern involves repeatedly placing the front card in the result and moving the next card to the back of the deck.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
	```
	The function `deckRevealedIncreasing` takes a vector of integers (representing a deck of cards) and returns a vector representing the deck after rearrangement.

2. **Sorting Deck**
	```cpp
	    sort(deck.begin(), deck.end());
	```
	Sort the deck in increasing order to prepare for the rearrangement process, ensuring that the smallest cards are placed at the front.

3. **Get Deck Size**
	```cpp
	    int n = deck.size();
	```
	Store the size of the deck (number of cards) in the variable `n`.

4. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	Initialize a queue `q` that will be used to manage the positions of cards in the deck during the rearrangement process.

5. **Result Vector Initialization**
	```cpp
	    vector<int> res(n, 0);
	```
	Initialize a result vector `res` of size `n` with all elements set to 0. This vector will hold the final rearranged deck.

6. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through the deck to populate the queue with the indices of the cards.

7. **Push Indices to Queue**
	```cpp
	        q.push(i);
	```
	Push the index `i` of each card into the queue, so the queue holds the indices of all cards in the deck.

8. **Start Rearranging**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start another loop to rearrange the deck based on the queue and the sorted cards.

9. **Place Card in Result**
	```cpp
	        res[q.front()] = deck[i];
	```
	Place the current card from the sorted deck at the position specified by the front of the queue in the result vector.

10. **Remove Card from Queue**
	```cpp
	        q.pop();
	```
	Pop the front element from the queue, which represents the index of the card that has just been placed in the result vector.

11. **Rearrange Cards in Queue**
	```cpp
	        if(!q.empty()) {
	```
	If there are still cards in the queue, proceed to rearrange them.

12. **Move Front to Back**
	```cpp
	            q.push(q.front());
	```
	Push the front element of the queue to the back, effectively moving the next card to the back of the deck.

13. **Pop Card from Queue**
	```cpp
	            q.pop();
	```
	Pop the front element again after moving it to the back.

14. **Return Result**
	```cpp
	    return res;
	```
	Return the rearranged deck stored in the result vector `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting step dominates the time complexity, which is O(n log n) where n is the size of the deck.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of a queue and the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reveal-cards-in-increasing-order/description/)

---
{{< youtube i2QrUdwWlak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
