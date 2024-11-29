
+++
authors = ["grid47"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2024-06-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1561: Maximum Number of Coins You Can Get in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hPe9Z3TiUrA"
youtube_upload_date="2020-08-24"
youtube_thumbnail="https://i.ytimg.com/vi/hPe9Z3TiUrA/maxresdefault.jpg"
comments = true
+++



---
You and two friends are given 3n piles of coins, and in each step, three piles are chosen. Alice always picks the pile with the most coins, you pick the second largest pile, and your friend Bob picks the remaining pile. Repeat this process until all piles are picked. Your goal is to maximize the total number of coins you can collect.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers, where each integer represents the number of coins in a pile. The length of the array is 3n, where n is a positive integer.
- **Example:** `Input: piles = [1, 3, 2, 7, 5, 4, 6, 8, 9]`
- **Constraints:**
	- 3 <= piles.length <= 10^5
	- piles.length % 3 == 0
	- 1 <= piles[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of coins you can collect.
- **Example:** `Output: 18`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the coins you collect by strategically selecting piles in each round, ensuring you pick the second largest pile in each triplet.

- Sort the piles in descending order to prioritize larger piles for Alice.
- Pick the second largest pile for yourself in each triplet.
- Repeat the process until all piles are picked, keeping track of your total.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have a size that is a multiple of 3.
- The number of coins in each pile is a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: piles = [1, 3, 2, 7, 5, 4, 6, 8, 9]`  \
  **Explanation:** In this case, the optimal choices would be: (9, 8, 7), (6, 5, 4), and (3, 2, 1). You would get 8 + 6 = 14 coins.

- **Input:** `Example 2: piles = [1, 2, 3, 4, 5, 6]`  \
  **Explanation:** In this case, the optimal choices would be: (6, 5, 4), (3, 2, 1). You would get 5 + 2 = 7 coins.

{{< dots >}}
## Approach 🚀
The solution involves sorting the piles in descending order and picking the second largest pile in each triplet.

### Initial Thoughts 💭
- Since Alice picks the largest pile in each triplet, the second largest pile will always be the optimal choice for you.
- Sorting the array will help us easily select the largest, second largest, and smallest piles in each step.
- Sorting the array is the key to ensuring we can maximize the coins we collect.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least three piles in the input, so no need to handle empty inputs.
- For large inputs, ensure that the sorting operation does not cause time-limit issues. The time complexity of sorting is O(n log n), which should be efficient enough given the constraints.
- If all piles have the same number of coins, the result will be the sum of every second pile in each triplet.
- Ensure that the input size is divisible by 3, as per the problem constraints.
{{< dots >}}
## Code 💻
```cpp
int maxCoins(vector<int>& piles) {
    int max = 0;

    int n = piles.size();

    for (int i : piles) {

        if (max < i) max = i;

    }

    vector<int> freq(max + 1, 0);

    for (int i : piles) {

        freq[i]++;

    }

    int coins = 0;

    int chance = n / 3;

    int turn = 1;

    int i = max;

    while (chance != 0) {

        if (freq[i] > 0) {

            if (turn == 1) turn = 0;

            else {

                chance--;

                turn = 1;

                coins += i;

            }

            freq[i]--;

        } else {

            i--;

        }

    }

    return coins;
}
```

This is the complete function `maxCoins`, which calculates the maximum number of coins that can be collected from the piles, adhering to the rules defined in the problem.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxCoins(vector<int>& piles) {
	```
	This is the function declaration for `maxCoins`, which takes a vector of integers `piles` as input, representing the piles of coins.

2. **Variable Initialization**
	```cpp
	    int max = 0;
	```
	Here, we initialize the `max` variable to zero. This will be used to track the maximum value in the piles.

3. **Variable Initialization**
	```cpp
	    int n = piles.size();
	```
	We initialize `n` to the size of the `piles` vector, which represents the total number of piles.

4. **Loop Iteration**
	```cpp
	    for (int i : piles) {
	```
	This is the start of a for loop that iterates over each element `i` in the `piles` vector.

5. **Condition Check**
	```cpp
	        if (max < i) max = i;
	```
	In this condition, we check if the current pile value `i` is greater than `max`, and if so, update `max`.

6. **Variable Initialization**
	```cpp
	    vector<int> freq(max + 1, 0);
	```
	We initialize a frequency vector `freq` of size `max + 1` with all elements set to zero. This will help us count the occurrences of each pile size.

7. **Loop Iteration**
	```cpp
	    for (int i : piles) {
	```
	This for loop iterates over each pile value `i` again to update the frequency count.

8. **Variable Update**
	```cpp
	        freq[i]++;
	```
	Here, we increment the corresponding index in the `freq` vector to track the frequency of each pile size.

9. **Variable Initialization**
	```cpp
	    int coins = 0;
	```
	We initialize `coins` to zero, which will store the total coins collected.

10. **Variable Initialization**
	```cpp
	    int chance = n / 3;
	```
	The `chance` variable is initialized to `n / 3`, which represents the number of chances the player has to pick coins.

11. **Variable Initialization**
	```cpp
	    int turn = 1;
	```
	We initialize `turn` to 1, which keeps track of whose turn it is. Player 1's turn is represented by 1.

12. **Variable Initialization**
	```cpp
	    int i = max;
	```
	The variable `i` is initialized to the value of `max`, which will be used to traverse the piles starting from the largest pile.

13. **Loop Iteration**
	```cpp
	    while (chance != 0) {
	```
	This while loop continues until the number of chances (`chance`) is zero.

14. **Condition Check**
	```cpp
	        if (freq[i] > 0) {
	```
	If there are piles of size `i` remaining, we proceed with the selection process.

15. **Condition Check**
	```cpp
	            if (turn == 1) turn = 0;
	```
	If it's Player 1's turn, we switch to Player 2's turn by setting `turn` to 0.

16. **Condition Check**
	```cpp
	            else {
	```
	If it's Player 2's turn, we process the turn and reduce the `chance` by one.

17. **Variable Update**
	```cpp
	                chance--;
	```
	Decrement the `chance` by 1, indicating that one chance has been used.

18. **Variable Update**
	```cpp
	                turn = 1;
	```
	Switch back to Player 1's turn by setting `turn` to 1.

19. **Variable Update**
	```cpp
	                coins += i;
	```
	Add the current pile size `i` to the total `coins` collected.

20. **Variable Update**
	```cpp
	            freq[i]--;
	```
	Decrement the frequency of the pile size `i`, as it has been used.

21. **Else Block**
	```cpp
	        } else {
	```
	If no piles of size `i` are remaining, we decrement `i` to try the next smaller pile.

22. **Variable Update**
	```cpp
	            i--;
	```
	Decrement `i` to try the next smaller pile.

23. **Return Statement**
	```cpp
	    return coins;
	```
	Finally, we return the total number of `coins` collected by the players.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting operation dominates the time complexity, making it O(n log n) in all cases.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/)

---
{{< youtube hPe9Z3TiUrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
