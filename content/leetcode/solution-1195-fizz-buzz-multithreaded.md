
+++
authors = ["grid47"]
title = "Leetcode 1195: Fizz Buzz Multithreaded"
date = "2024-07-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1195: Fizz Buzz Multithreaded in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a class `FizzBuzz` that has four methods: `fizz()`, `buzz()`, `fizzbuzz()`, and `number()`. These methods are executed by four different threads. The goal is to output a sequence of numbers from 1 to `n` with special rules: if the number is divisible by 3 and 5, print 'fizzbuzz'; if divisible by 3 but not 5, print 'fizz'; if divisible by 5 but not 3, print 'buzz'; otherwise, print the number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, representing the length of the sequence.
- **Example:** `Input: n = 10`
- **Constraints:**
	- 1 <= n <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of values where each value corresponds to the number or one of the words 'fizz', 'buzz', or 'fizzbuzz'.
- **Example:** `Output: [1, 2, 'fizz', 4, 'buzz', 'fizz', 7, 8, 'fizz', 'buzz']`
- **Constraints:**
	- The sequence should follow the correct order and the rules for 'fizz', 'buzz', and 'fizzbuzz'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to implement the `FizzBuzz` class such that each method is responsible for printing the appropriate output based on the current number.

- Create the `FizzBuzz` class with an initializer for the number `n`.
- Use synchronization (mutexes) to coordinate the threads for each method.
- Ensure the correct method is called based on whether the number is divisible by 3, 5, or both.
{{< dots >}}
### Problem Assumptions ✅
- Each method (`fizz`, `buzz`, `fizzbuzz`, `number`) will be executed by a separate thread.
- The order of printing is important and must follow the rules for 'fizz', 'buzz', and 'fizzbuzz'.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 7`  \
  **Explanation:** The sequence from 1 to 7 will output: [1, 2, 'fizz', 4, 'buzz', 'fizz', 7]. 'fizz' is printed for multiples of 3, 'buzz' for multiples of 5, and the rest are the numbers themselves.

{{< dots >}}
## Approach 🚀
We will solve this by using multithreading and synchronization. Each thread will be responsible for printing a particular output based on the current number in the sequence.

### Initial Thoughts 💭
- We need to ensure the threads run in the correct order without race conditions.
- Mutexes will help synchronize the output, ensuring that the numbers are printed in the correct order and with the correct labels.
{{< dots >}}
### Edge Cases 🌐
- If `n` is 1, the output should just be [1].
- For larger values of `n` (up to 50), ensure that the solution works within the time limits.
- If `n` is a multiple of both 3 and 5, 'fizzbuzz' should be printed.
- Handle synchronization properly to avoid race conditions between threads.
{{< dots >}}
## Code 💻
```cpp
int n, i;
mutex f, b, fz, num;
public:
FizzBuzz(int n) {
    f.lock();
    b.lock();
    fz.lock();
    i = 1;
    this->n = n;
}

// printFizz() outputs "fizz".
void fizz(function<void()> printFizz) {
    while(i <= n) {
        f.lock();
        if(i <= n)            
        printFizz();
        i++;            
        if(i % 3== 0  && i % 5== 0 ) {
            fz.unlock();
        } else if(i % 3 == 0) {
            f.unlock();
        } else if(i % 5 == 0) {
            b.unlock();
        } else if(i <= n) {
            num.unlock();
        } else {
            fz.unlock();
            f.unlock();
            b.unlock();
            num.unlock();
        }

    }
}

// printBuzz() outputs "buzz".
void buzz(function<void()> printBuzz) {
    while(i <= n) {
        b.lock();
        if(i <= n)            
        printBuzz();
        i++;
        if(i % 3== 0  && i % 5== 0 ) {
            fz.unlock();
        } else if(i % 3 == 0) {
            f.unlock();
        } else if(i % 5 == 0) {
            b.unlock();
        } else if(i <= n) {
            num.unlock();
        } else {
            fz.unlock();
            f.unlock();
            b.unlock();
            num.unlock();
        }
    }
}

// printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
    while(i <= n) {
        fz.lock();
        if(i <= n)
        printFizzBuzz();
        i++;
        if(i % 3 == 0 && i % 5== 0 ) {
            fz.unlock();
        } else if(i % 3 == 0) {
            f.unlock();
        } else if(i % 5 == 0) {
            b.unlock();
        } else if(i <= n) {
            num.unlock();
        } else {
            fz.unlock();
            f.unlock();
            b.unlock();
            num.unlock();
        }
    }
}

// printNumber(x) outputs "x", where x is an integer.
void number(function<void(int)> printNumber) {
    while(i <= n) {
        num.lock();
        if(i <= n)
        printNumber(i);
        i++;
        if(i % 3 == 0 && i % 5== 0 ) {
            fz.unlock();
        } else if(i % 3 == 0) {
            f.unlock();
        } else if(i % 5 == 0) {
            b.unlock();
        } else if(i <= n) {
            num.unlock();
        } else {
            fz.unlock();
            f.unlock();
            b.unlock();
            num.unlock();
        }
    }
}
```

The implementation demonstrates a multithreaded solution for the FizzBuzz problem using mutex locks to synchronize threads.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **variable declaration**
	```cpp
	int n, i;
	```
	Defines variables `n` (the range limit) and `i` (the current number being processed).

2. **synchronization primitives**
	```cpp
	mutex f, b, fz, num;
	```
	Declares mutex objects to control thread synchronization for fizz, buzz, fizzbuzz, and number printing.

3. **access specifier**
	```cpp
	public:
	```
	Marks the following members of the class as publicly accessible.

4. **constructor**
	```cpp
	FizzBuzz(int n) {
	```
	Defines the constructor, initializing the range limit `n` and locking the mutexes.

5. **mutex lock**
	```cpp
	    f.lock();
	```
	Locks the mutex for the `fizz` thread to ensure controlled execution.

6. **mutex lock**
	```cpp
	    b.lock();
	```
	Locks the mutex for the `buzz` thread to prevent premature execution.

7. **mutex lock**
	```cpp
	    fz.lock();
	```
	Locks the mutex for the `fizzbuzz` thread to maintain synchronization.

8. **variable initialization**
	```cpp
	    i = 1;
	```
	Initializes the iterator variable `i` to start processing from 1.

9. **variable assignment**
	```cpp
	    this->n = n;
	```
	Assigns the range limit `n` to the instance variable of the class.

10. **function definition**
	```cpp
	void fizz(function<void()> printFizz) {
	```
	Defines the `fizz` function, which uses a lambda to print 'fizz' when appropriate.

11. **loop**
	```cpp
	    while(i <= n) {
	```
	Begins a loop that iterates through numbers from 1 to `n`.

12. **mutex lock**
	```cpp
	        f.lock();
	```
	Locks the mutex for the `fizz` thread before executing its logic.

13. **conditional check**
	```cpp
	        if(i <= n)            
	```
	Checks if the current number is within the range limit before printing.

14. **function call**
	```cpp
	        printFizz();
	```
	Executes the function to print 'fizz'.

15. **iterator increment**
	```cpp
	        i++;            
	```
	Increments the iterator to move to the next number.

16. **conditional check**
	```cpp
	        if(i % 3== 0  && i % 5== 0 ) {
	```
	Checks if the current number is divisible by both 3 and 5.

17. **mutex unlock**
	```cpp
	            fz.unlock();
	```
	Unlocks the `fizzbuzz` mutex if the number is divisible by both 3 and 5.

18. **conditional check**
	```cpp
	        } else if(i % 3 == 0) {
	```
	Checks if the number is divisible only by 3.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as each number from 1 to `n` is processed once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since only a constant amount of space is used for synchronization and variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/fizz-buzz-multithreaded/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
