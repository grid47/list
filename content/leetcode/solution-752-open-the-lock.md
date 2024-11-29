
+++
authors = ["grid47"]
title = "Leetcode 752: Open the Lock"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 752: Open the Lock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp"
youtube = "Pzg3bCDY87w"
youtube_upload_date="2022-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/Pzg3bCDY87w/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/752.webp" 
    alt="A lock with combination digits, where each correct digit softly glows as it’s guessed correctly."
    caption="Solution to LeetCode 752: Open the Lock Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a lock with 4 rotating wheels, each containing 10 slots labeled '0' to '9'. The wheels can rotate freely and wrap around. You must determine the minimum number of moves required to reach a target lock configuration, avoiding certain deadends.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of deadends and a target string, representing the lock's target configuration.
- **Example:** `deadends = ['0201', '0101', '0102', '1212', '2002'], target = '0202'`
- **Constraints:**
	- 1 <= deadends.length <= 500
	- deadends[i].length == 4
	- target.length == 4
	- target will not be in the list of deadends
	- target and deadends[i] consist of digits only

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of turns required to reach the target configuration, or -1 if it is impossible.
- **Example:** `For deadends = ['0201', '0101', '0102', '1212', '2002'] and target = '0202', the output is 6.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the shortest path from '0000' to the target configuration, avoiding deadends.

- Use a breadth-first search (BFS) starting from '0000'.
- At each step, generate all possible valid configurations by rotating one of the wheels.
- If the generated configuration is a deadend, skip it.
- If the configuration matches the target, return the number of moves taken to reach it.
{{< dots >}}
### Problem Assumptions ✅
- The input deadends and target strings consist only of digits between '0' and '9'.
- The target configuration is not present in the list of deadends.
{{< dots >}}
## Examples 🧩
- **Input:** `deadends = ['0201', '0101', '0102', '1212', '2002'], target = '0202'`  \
  **Explanation:** Starting from '0000', the sequence '0000' -> '1000' -> '1100' -> '1200' -> '1201' -> '1202' -> '0202' leads to the target, taking 6 moves.

- **Input:** `deadends = ['8888'], target = '0009'`  \
  **Explanation:** Starting from '0000', the sequence '0000' -> '0009' requires just 1 move.

- **Input:** `deadends = ['8887', '8889', '8878', '8898', '8788', '8988', '7888', '9888'], target = '8888'`  \
  **Explanation:** It is impossible to reach the target without hitting a deadend.

{{< dots >}}
## Approach 🚀
Use BFS to explore all possible configurations starting from '0000', avoiding deadends, and tracking the number of moves to reach the target.

### Initial Thoughts 💭
- BFS is an ideal approach for finding the shortest path in an unweighted graph of configurations.
- Each valid configuration can be viewed as a node, and each move as an edge connecting nodes. The BFS ensures the shortest path to the target.
{{< dots >}}
### Edge Cases 🌐
- The constraints guarantee at least one deadend and one target configuration, so empty inputs are not possible.
- The BFS approach handles up to 500 deadends efficiently.
- The initial configuration '0000' cannot be a deadend.
- The algorithm should efficiently handle up to 500 deadends and a target of length 4.
{{< dots >}}
## Code 💻
```cpp
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) return -1;
    queue<string> q({"0000"});
    
    for(int turn = 0;!q.empty(); turn++) {
        for(int i = q.size(); i > 0; i--) {
            auto curr = q.front(); q.pop();
            cout << curr << ' ' << target << endl;
            if (curr == target) return turn;
            for(auto it : neighbours(curr)) {
                if(dead.count(it)) continue;
                dead.insert(it);
                q.push(it);
            }
        }
    }
    return -1;
}

vector<string> neighbours(const string &code) {
    vector<string> res;
    for(int i = 0; i < 4; i++) {
        for(int diff = -1; diff <= 1; diff++) {
            string nei = code;
            nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
            res.push_back(nei);
        }
    }
    return res;
}

```

This function solves the problem of opening a lock with a set of deadends, using a breadth-first search (BFS) approach to explore all possible states. It returns the minimum number of turns required to reach the target lock combination, or -1 if it's impossible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int openLock(vector<string>& deadends, string target) {
	```
	Defines the main function 'openLock' which takes a list of deadends and the target string. It attempts to open the lock by exploring all valid moves.

2. **Initialization**
	```cpp
	    unordered_set<string> dead(deadends.begin(), deadends.end());
	```
	Initializes the 'dead' set with the deadends, preventing any movement into these states during the BFS traversal.

3. **Edge Case**
	```cpp
	    if (dead.count("0000")) return -1;
	```
	Checks if the starting point ('0000') is in the deadends. If it is, the lock cannot be opened, and the function returns -1.

4. **Initialization**
	```cpp
	    queue<string> q({"0000"});
	```
	Initializes the queue with the starting point ('0000'), which is the initial state of the lock.

5. **BFS Loop**
	```cpp
	    for(int turn = 0;!q.empty(); turn++) {
	```
	A loop that continues as long as the queue is not empty, incrementing the 'turn' at each level of BFS.

6. **BFS Iteration**
	```cpp
	        for(int i = q.size(); i > 0; i--) {
	```
	Iterates over all elements in the queue at the current level (turn), processing each one by one.

7. **Queue Operation**
	```cpp
	            auto curr = q.front(); q.pop();
	```
	Pops the front element from the queue and assigns it to 'curr', representing the current lock state.

8. **Goal Check**
	```cpp
	            if (curr == target) return turn;
	```
	Checks if the current state matches the target. If so, returns the number of turns taken to reach it.

9. **Exploration**
	```cpp
	            for(auto it : neighbours(curr)) {
	```
	Loops through all the possible neighbouring states of the current state by calling the 'neighbours' function.

10. **Deadend Check**
	```cpp
	                if(dead.count(it)) continue;
	```
	Checks if a neighbouring state is a deadend. If it is, it is skipped.

11. **State Exploration**
	```cpp
	                dead.insert(it);
	```
	Marks the neighbouring state as visited by inserting it into the 'dead' set.

12. **State Exploration**
	```cpp
	                q.push(it);
	```
	Pushes the valid neighbouring state into the queue to be processed in subsequent turns.

13. **Failure**
	```cpp
	    return -1;
	```
	If the queue is empty and the target hasn't been reached, the function returns -1, indicating the lock cannot be opened.

14. **Neighbouring Function**
	```cpp
	vector<string> neighbours(const string &code) {
	```
	Defines the 'neighbours' function that takes a lock code and returns all the possible states that are one turn away.

15. **Neighbouring Function**
	```cpp
	    vector<string> res;
	```
	Initializes a vector to store the neighbouring states.

16. **Loop Over Digits**
	```cpp
	    for(int i = 0; i < 4; i++) {
	```
	Iterates over each digit in the 4-digit lock code.

17. **Loop Over Digits**
	```cpp
	        for(int diff = -1; diff <= 1; diff++) {
	```
	For each digit, it iterates over the possible changes (-1, 0, 1), representing turning the dial.

18. **State Change**
	```cpp
	            string nei = code;
	```
	Creates a copy of the current lock code to modify.

19. **State Change**
	```cpp
	            nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
	```
	Modifies the i-th digit of the lock code by applying the change, ensuring the new digit is valid.

20. **Neighbouring Function**
	```cpp
	            res.push_back(nei);
	```
	Adds the newly generated neighbour state to the results vector.

21. **Neighbouring Function**
	```cpp
	    return res;
	```
	Returns the vector of all valid neighbouring states.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), when the target is '0000'.
- **Average Case:** O(n), where n is the number of configurations explored (bounded by 10^4).
- **Worst Case:** O(10^4), when the BFS explores all possible configurations.

The time complexity is O(n) where n is the number of explored configurations, and there are at most 10^4 configurations.

### Space Complexity 💾
- **Best Case:** O(1), for trivial cases.
- **Worst Case:** O(10^4), for the queue and visited configurations.

The space complexity is O(n) where n is the number of configurations being tracked in BFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/open-the-lock/description/)

---
{{< youtube Pzg3bCDY87w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
