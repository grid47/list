
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
+++



---
**Code:**

{{< highlight cpp >}}
class DiningPhilosophers {
public:
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
};
{{< /highlight >}}
---


### Problem Statement
The Dining Philosophers problem is a classic synchronization problem in computer science that illustrates the challenges of resource sharing among concurrent processes. It involves five philosophers sitting at a dining table, where they alternate between thinking and eating. Each philosopher needs two forks (one to their left and one to their right) to eat. The challenge is to design a protocol that ensures:

1. No two philosophers can use the same fork simultaneously, which could lead to a deadlock.
2. The system avoids starvation, where a philosopher could be perpetually denied the opportunity to eat.
3. Philosophers can pick up and put down forks in a manner that allows all of them to eat without conflicts.

In this implementation, we utilize mutexes to represent the forks and ensure that the philosophers can acquire the forks in a safe manner, avoiding both deadlock and starvation.

### Approach
To solve the Dining Philosophers problem, the following approach is employed:

1. **Fork Representation**: Each fork is represented by a mutex. There are five mutexes corresponding to the five forks.
2. **Mutex Locking**: Philosophers attempt to pick up the left and right forks using mutexes, ensuring that no two philosophers can access the same fork simultaneously.
3. **Lock Ordering**: To prevent deadlock, we introduce an ordering in which the forks are acquired. Philosophers with an odd index pick up the left fork first, while those with an even index pick up the right fork first. This staggered approach prevents all philosophers from waiting for one another indefinitely.
4. **Function Callbacks**: The function accepts callbacks that simulate picking up and putting down the forks, as well as the eating action.

### Code Breakdown (Step by Step)

```cpp
class DiningPhilosophers {
public:
    mutex mtx[5];
```
- **Lines 1-2**: We define the `DiningPhilosophers` class and create an array of mutexes (`mtx[5]`) to represent the five forks.

```cpp
    DiningPhilosophers() {
        
    }
```
- **Lines 3-5**: The constructor of the `DiningPhilosophers` class is defined, but it doesn’t perform any operations. It's here to facilitate object creation.

```cpp
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
```
- **Lines 6-11**: We define the `wantsToEat` method, which takes the philosopher's index and several function callbacks that represent the actions of picking up and putting down forks, as well as eating.

```cpp
        int left = philosopher;
        int right = (philosopher + 1) % 5;
```
- **Lines 12-13**: We determine the indices for the left and right forks. The left fork corresponds to the philosopher's index, while the right fork is calculated using modulo arithmetic to wrap around the array.

```cpp
        unique_lock<mutex> lck1(mtx[left], defer_lock);
        unique_lock<mutex> lck2(mtx[right], defer_lock);
```
- **Lines 14-15**: We create two unique locks (`lck1` and `lck2`) for the left and right forks, initializing them with `defer_lock` to allow us to lock them later.

```cpp
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
```
- **Lines 16-24**: We use an if-else statement to control the order in which the locks are acquired based on whether the philosopher index is odd or even:
  - If the philosopher's index is odd, they first lock the left fork and then the right fork.
  - If the index is even, they first lock the right fork and then the left fork.
- This alternating strategy prevents deadlock by ensuring that at least one philosopher can always pick up their forks without being blocked.

```cpp
        eat();
        putLeftFork();
        putRightFork();
    }
};
```
- **Lines 25-28**: After acquiring both forks, the philosopher can perform the eating action. After eating, they put down the left and right forks by invoking the respective callbacks.

### Complexity
1. **Time Complexity**: The time complexity of the `wantsToEat` function primarily depends on the number of philosophers and the time taken for eating. However, since the locking mechanism is efficient, the operations of picking and putting down forks can be considered \(O(1)\) in average scenarios.
   
2. **Space Complexity**: The space complexity is \(O(1)\) since the number of mutexes is constant (five) and does not change with input size.

### Conclusion
The `DiningPhilosophers` class provides a robust solution to the classic synchronization problem using mutexes for managing access to shared resources. By employing an alternating strategy for locking forks based on philosopher indices, this implementation effectively avoids deadlocks and ensures that all philosophers can eventually eat without starvation. The approach illustrates the importance of careful resource management in concurrent programming and highlights the effectiveness of mutexes in synchronizing access to shared resources. This solution is well-suited for applications where resource contention is a concern and demonstrates good practices in concurrency control.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-dining-philosophers/description/)

---
{{< youtube cb6-GZiSaMY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
