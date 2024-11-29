
+++
authors = ["grid47"]
title = "Leetcode 1226: The Dining Philosophers"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1226: The Dining Philosophers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "cb6-GZiSaMY"
youtube_upload_date="2021-04-15"
youtube_thumbnail="https://i.ytimg.com/vi/cb6-GZiSaMY/maxresdefault.jpg"
comments = true
+++



---
Five philosophers sit at a round table with bowls of spaghetti. Each philosopher alternates between thinking and eating. A philosopher can only eat when both their left and right forks are available. Design a system where no philosopher will starve and they can continue alternating between eating and thinking.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of times each philosopher will call the function wantsToEat. The philosophers are numbered from 0 to 4 in a clockwise direction, and they request the forks one by one.
- **Example:** `n = 1`
- **Constraints:**
	- 1 <= n <= 60

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of an array of operations in the form [a, b, c] where: a is the philosopher id, b indicates the fork (1 for left, 2 for right), and c indicates the operation (1 for pick, 2 for put, 3 for eat).
- **Example:** `[[4, 2, 1], [4, 1, 1], [0, 1, 1], [2, 2, 1], [2, 1, 1], [2, 0, 3], [2, 1, 2], [2, 2, 2], [4, 0, 3], [4, 1, 2], [0, 2, 1], [4, 2, 2], [3, 2, 1], [3, 1, 1], [0, 0, 3], [0, 1, 2], [0, 2, 2], [1, 2, 1], [1, 1, 1], [3, 0, 3], [3, 1, 2], [3, 2, 2], [1, 0, 3], [1, 1, 2], [1, 2, 2]]`
- **Constraints:**
	- Each philosopher calls the function at least once.

{{< dots >}}
### Core Logic 🔍
**Goal:** To ensure no philosopher ever starves while alternating between eating and thinking. The philosopher must acquire both forks before eating and release them afterward.

- Each philosopher alternates between thinking and attempting to eat.
- The philosopher first picks the left fork, then the right fork (or vice versa depending on the philosopher's id).
- Once both forks are acquired, the philosopher starts eating.
- After eating, the philosopher puts down both forks, making them available for others.
{{< dots >}}
### Problem Assumptions ✅
- Each philosopher alternates between thinking and eating.
- A philosopher cannot eat without holding both forks.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 1`  \
  **Explanation:** In this example, each philosopher calls the function once. The result is a series of operations where each philosopher picks up their forks, eats, and then puts down the forks in turn.

{{< dots >}}
## Approach 🚀
To simulate the alternating process of eating and thinking while preventing starvation, we use mutex locks to ensure that philosophers only acquire forks when available and release them when done.

### Initial Thoughts 💭
- Philosophers should not block each other from eating by acquiring forks in an arbitrary order.
- We can implement a mutual exclusion mechanism using mutex locks to ensure forks are picked and released in a safe manner.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs are allowed.
- For larger values of n, the number of philosopher actions will increase, but the system must remain efficient.
- Ensure that all philosophers can eat indefinitely and never starve.
- Each philosopher must alternate between thinking and eating without blocking others.
{{< dots >}}
## Code 💻
```cpp
mutex mtx[5];
DiningPhilosophers() {
    
}

void wantsToEat(int philosopher,
                function<void()> pickLeftFork,
                function<void()> pickRightFork,
                function<void()> eat,
                function<void()> putLeftFork,
                function<void()> putRightFork) {
		
    int left = philosopher;
    int right = (philosopher + 1) % 5;
    
    unique_lock<mutex> lck1(mtx[left], defer_lock);
    unique_lock<mutex> lck2(mtx[right], defer_lock);
    
    if(philosopher % 2) {
        lck1.lock();
        lck2.lock();
        pickLeftFork();
        pickRightFork();
    } else {
        lck2.lock();
        lck1.lock();
        pickLeftFork();
        pickRightFork();            
    }
    eat();
    putLeftFork();
    putRightFork();
}
```

This code defines the solution for the Dining Philosophers problem, where philosophers need to acquire two forks to eat, while avoiding deadlocks and ensuring that they can eat in turns.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	mutex mtx[5];
	```
	A mutex array `mtx[5]` is declared to manage access to the forks (shared resources) for each philosopher.

2. **Constructor**
	```cpp
	DiningPhilosophers() {
	```
	This is the constructor for the `DiningPhilosophers` class, where the mutex array is initialized.

3. **Function Definition**
	```cpp
	void wantsToEat(int philosopher,
	```
	This is the function definition for `wantsToEat`, which simulates a philosopher's request to eat. It accepts the philosopher's ID and functions for picking up and putting down forks, as well as eating.

4. **Function Parameter**
	```cpp
	                function<void()> pickLeftFork,
	```
	A function parameter `pickLeftFork` that simulates picking up the left fork.

5. **Function Parameter**
	```cpp
	                function<void()> pickRightFork,
	```
	A function parameter `pickRightFork` that simulates picking up the right fork.

6. **Function Parameter**
	```cpp
	                function<void()> eat,
	```
	A function parameter `eat` that simulates the action of eating.

7. **Function Parameter**
	```cpp
	                function<void()> putLeftFork,
	```
	A function parameter `putLeftFork` that simulates putting down the left fork.

8. **Function Parameter**
	```cpp
	                function<void()> putRightFork) {
	```
	A function parameter `putRightFork` that simulates putting down the right fork.

9. **Fork Index Calculation**
	```cpp
	    int left = philosopher;
	```
	The `left` fork is assigned to the philosopher's position (index), corresponding to the philosopher's ID.

10. **Fork Index Calculation**
	```cpp
	    int right = (philosopher + 1) % 5;
	```
	The `right` fork is the next fork, calculated using modulo 5 to handle the circular arrangement of philosophers.

11. **Mutex Lock Setup**
	```cpp
	    unique_lock<mutex> lck1(mtx[left], defer_lock);
	```
	A `unique_lock` is created for the left fork (`lck1`), with the `defer_lock` option to avoid locking immediately.

12. **Mutex Lock Setup**
	```cpp
	    unique_lock<mutex> lck2(mtx[right], defer_lock);
	```
	A `unique_lock` is created for the right fork (`lck2`), again with the `defer_lock` option.

13. **Philosopher Eating Logic**
	```cpp
	    if(philosopher % 2) {
	```
	An if condition is used to alternate the order in which philosophers acquire the forks to avoid deadlocks.

14. **Locking Forks**
	```cpp
	        lck1.lock();
	```
	The left fork is locked.

15. **Locking Forks**
	```cpp
	        lck2.lock();
	```
	The right fork is locked.

16. **Fork Pickup**
	```cpp
	        pickLeftFork();
	```
	The function to pick up the left fork is called.

17. **Fork Pickup**
	```cpp
	        pickRightFork();
	```
	The function to pick up the right fork is called.

18. **Philosopher Eating Logic**
	```cpp
	    } else {
	```
	If the philosopher's ID is even, the order of locking the forks is reversed to avoid deadlocks.

19. **Locking Forks**
	```cpp
	        lck2.lock();
	```
	The right fork is locked first.

20. **Locking Forks**
	```cpp
	        lck1.lock();
	```
	The left fork is locked second.

21. **Fork Pickup**
	```cpp
	        pickLeftFork();
	```
	The function to pick up the left fork is called.

22. **Fork Pickup**
	```cpp
	        pickRightFork();            
	```
	The function to pick up the right fork is called.

23. **Eat Action**
	```cpp
	    eat();
	```
	The philosopher eats.

24. **Put Fork Down**
	```cpp
	    putLeftFork();
	```
	The philosopher puts down the left fork.

25. **Put Fork Down**
	```cpp
	    putRightFork();
	```
	The philosopher puts down the right fork.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of times each philosopher calls the function.
- **Average Case:** O(n), as each philosopher performs the same number of actions.
- **Worst Case:** O(n), since the system is designed to avoid starvation and deadlock.

The time complexity is linear with respect to the number of iterations each philosopher makes.

### Space Complexity 💾
- **Best Case:** O(1), since no additional space is required beyond the basic setup.
- **Worst Case:** O(1), as we only need a fixed number of mutexes and variables regardless of input size.

The space complexity is constant as the number of philosophers is fixed and the operations are performed in constant space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-dining-philosophers/description/)

---
{{< youtube cb6-GZiSaMY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
