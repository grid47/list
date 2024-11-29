
+++
authors = ["grid47"]
title = "Leetcode 1823: Find the Winner of the Circular Game"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1823: Find the Winner of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Recursion","Queue","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PBBQgW_75e0"
youtube_upload_date="2024-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/PBBQgW_75e0/maxresdefault.jpg"
comments = true
+++



---
In this problem, there are `n` friends sitting in a circle. The game proceeds by counting `k` friends clockwise starting from the 1st friend. The last friend counted leaves the circle. This continues until only one friend remains, who is the winner. Your task is to find the winner of the game given `n` and `k`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers `n` and `k`, where `n` is the number of friends and `k` is the number of friends to be counted in each round.
- **Example:** `n = 5, k = 2`
- **Constraints:**
	- 1 <= k <= n <= 500

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of the last remaining friend who wins the game.
- **Example:** `Output: 3`
- **Constraints:**
	- The result is a single integer representing the winner's number.

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve this problem, simulate the counting process and eliminate the friends until only one is left.

- Initialize a list to represent the circle of friends.
- Repeat the elimination process: for each turn, count `k` friends clockwise, and remove the last counted friend.
- Continue until there is only one friend left in the circle, and return that friend as the winner.
{{< dots >}}
### Problem Assumptions ✅
- The number of friends `n` is at least 1.
- The number of friends `n` is at most 500.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, k = 2`  \
  **Explanation:** In this example, we start with friend 1 and eliminate friends in the order 2, 4, 1, and 5. Friend 3 is the last remaining and wins the game.

- **Input:** `n = 6, k = 5`  \
  **Explanation:** Here, we eliminate friends in the order 5, 4, 3, 2, and finally friend 1 wins as the last one remaining.

{{< dots >}}
## Approach 🚀
The approach is to simulate the process of counting and eliminating friends until only one remains. A circular data structure can be used to handle the counting and wrapping around the circle.

### Initial Thoughts 💭
- We need to simulate the elimination process efficiently.
- We can use a queue or list to represent the circle and eliminate friends.
- A queue will allow us to simulate the circular nature of the problem by rotating the elements and eliminating one each time.
{{< dots >}}
### Edge Cases 🌐
- The number of friends `n` is always at least 1 based on the problem's constraints.
- For large values of `n` and `k`, the algorithm must efficiently simulate the elimination process in linear time.
- If `k = 1`, the elimination process will be straightforward as each friend is eliminated one by one.
- Ensure that the simulation handles the circular nature correctly.
{{< dots >}}
## Code 💻
```cpp
int findTheWinner(int n, int k) {
    queue<int> q;
    for(int i = 1; i <= n; i++)
        q.push(i);
    
    while(q.size() != 1) {
        int x= k;
        while(x > 1) {
            int r = q.front();
            q.pop();
            q.push(r);
            x--;
        }
        q.pop();
    }
    
    return q.front();
}
```

The function `findTheWinner` simulates a game where `n` people stand in a circle and every `k`th person is eliminated until one remains. The function returns the winner's position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findTheWinner(int n, int k) {
	```
	This defines the function `findTheWinner`, which takes two integers, `n` (number of people) and `k` (elimination step), and returns the winner's position.

2. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue `q` is initialized to simulate the circular arrangement of players.

3. **Queue Population**
	```cpp
	    for(int i = 1; i <= n; i++)
	```
	This `for` loop iterates from 1 to `n`, adding each person to the queue.

4. **Push Elements to Queue**
	```cpp
	        q.push(i);
	```
	Each person's number from 1 to `n` is pushed into the queue, representing the players in the circle.

5. **Elimination Loop**
	```cpp
	    while(q.size() != 1) {
	```
	This `while` loop continues until only one player remains in the queue.

6. **Elimination Step Initialization**
	```cpp
	        int x= k;
	```
	The variable `x` is initialized to `k`, representing the step at which players are eliminated.

7. **Inner Elimination Loop**
	```cpp
	        while(x > 1) {
	```
	This inner loop runs until `x` reaches 1, simulating the elimination process.

8. **Front Element of Queue**
	```cpp
	            int r = q.front();
	```
	The front player (the first player in the queue) is stored in variable `r`.

9. **Pop from Queue**
	```cpp
	            q.pop();
	```
	The front player is removed from the queue.

10. **Push to Rear of Queue**
	```cpp
	            q.push(r);
	```
	The removed player is pushed back to the rear of the queue.

11. **Decrement Elimination Step**
	```cpp
	            x--;
	```
	The elimination step counter `x` is decremented, moving toward eliminating the `k`th player.

12. **Eliminate Player**
	```cpp
	        q.pop();
	```
	Once the `k`th player is reached, they are removed (eliminated) from the queue.

13. **Return Winner**
	```cpp
	    return q.front();
	```
	The function returns the front player of the queue, who is the winner of the game.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires iterating over the list of friends and performing rotations, leading to a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the list or queue representing the circle of friends.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

---
{{< youtube PBBQgW_75e0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
