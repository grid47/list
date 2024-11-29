
+++
authors = ["grid47"]
title = "Leetcode 1116: Print Zero Even Odd"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1116: Print Zero Even Odd in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
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
You are given an instance of the class `ZeroEvenOdd`, which contains three functions: `zero`, `even`, and `odd`. The same instance of `ZeroEvenOdd` is passed to three different threads. Thread A calls `zero()` to print zeros, thread B calls `even()` to print even numbers, and thread C calls `odd()` to print odd numbers. The goal is to output a sequence of numbers in the order: 0, 1, 2, 3, ..., 2n, where n is the given number, and the length of the sequence is `2n`. The threads should execute asynchronously, ensuring that the sequence is printed correctly.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, which represents the length of the series to be printed. The total number of elements in the output series will be `2n`.
- **Example:** `Input: n = 3`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string that represents the sequence starting with '0', followed by odd and even numbers alternating, up to `2n`.
- **Example:** `Output: '010203'`
- **Constraints:**
	- The output must contain the numbers in the correct order, alternating between 0, odd, and even numbers, starting with 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to ensure that the threads execute in the correct order, printing the sequence: '0', odd, even, and so on until `2n`.

- Use mutexes to control the execution order of the threads. Each thread should print its number in the sequence.
- Thread A prints 0, then thread C prints the first odd number, and thread B prints the first even number, alternating until the sequence is completed.
{{< dots >}}
### Problem Assumptions ✅
- Threads will be executed asynchronously, and we need to control the execution order using synchronization mechanisms.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 1`  \
  **Explanation:** In this case, the output sequence is '010', where thread A prints 0, thread C prints the first odd number 1, and thread B prints the first even number 2.

- **Input:** `Input: n = 2`  \
  **Explanation:** The output should be '0102', as thread A prints 0, thread C prints the first odd number 1, and thread B prints the second even number 2.

{{< dots >}}
## Approach 🚀
The approach uses three threads and mutexes to ensure that the numbers are printed in the correct order. Thread A prints 0, thread C prints odd numbers, and thread B prints even numbers, following the specified order.

### Initial Thoughts 💭
- The problem requires synchronization to control the order of execution for the threads.
- By using mutexes, we can ensure that each thread waits for the appropriate signal to print its number in the correct sequence.
{{< dots >}}
### Edge Cases 🌐
- The minimum value for `n` is 1, so there will always be at least one number in the output sequence.
- For large values of `n`, the program should efficiently handle multiple threads without causing delays or errors.
- When `n` is 1, the output should be '010'.
- The solution should be able to handle values of `n` up to 1000 without performance issues.
{{< dots >}}
## Code 💻
```cpp
int n;
mutex mtx1, mtx2, mtx;
public:
ZeroEvenOdd(int n) {
    mtx1.lock();
    mtx2.lock();
    this->n = n;
}

// printNumber(x) outputs "x", where x is an integer.
void zero(function<void(int)> printNumber) {
    int t = 0;
    for(int j = 0; j < n; j++) {
        // cout << j << " ";
        mtx.lock();
        printNumber(0);
        if(t == 0) {
            t = 1;
            mtx1.unlock();         
        }
        else {
            t = 0;
            mtx2.unlock();            
        }            
    }
}

void even(function<void(int)> printNumber) {
    int i = 2;
    while(i <= n) {
        mtx2.lock();
        printNumber(i);
        mtx.unlock();
        i += 2;
    }
}

void odd(function<void(int)> printNumber) {
    int i = 1;
    while(i <= n) {
        mtx1.lock();
        printNumber(i);        
        mtx.unlock();
        i += 2;
    }
}
```

This code defines the ZeroEvenOdd class, which synchronizes the printing of numbers 0, odd, and even in sequence using mutex locks. The `zero` method ensures that 0 is printed first, followed by either an odd or even number. The `even` and `odd` methods print even and odd numbers in a sequence, with proper synchronization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	Declares an integer variable `n` which holds the value for the range of numbers to be printed.

2. **Mutex Declaration**
	```cpp
	mutex mtx1, mtx2, mtx;
	```
	Declares three mutex objects: `mtx1`, `mtx2`, and `mtx`, used for controlling access to shared resources between the threads.

3. **Access Control**
	```cpp
	public:
	```
	Defines the access specifier for the methods and constructor, allowing them to be accessed publicly.

4. **Constructor**
	```cpp
	ZeroEvenOdd(int n) {
	```
	Constructor that initializes the value of `n` and locks `mtx1` and `mtx2` to ensure proper synchronization.

5. **Locking**
	```cpp
	    mtx1.lock();
	```
	Locks the mutex `mtx1` to prevent other threads from accessing the shared resource until the lock is released.

6. **Locking**
	```cpp
	    mtx2.lock();
	```
	Locks the mutex `mtx2`, ensuring synchronization between the threads for printing even and odd numbers.

7. **Variable Assignment**
	```cpp
	    this->n = n;
	```
	Assigns the parameter value `n` to the class's `n` variable, defining the range of numbers to be printed.

8. **Constructor End**
	```cpp
	}
	```
	Marks the end of the constructor method.

9. **Function Declaration**
	```cpp
	void zero(function<void(int)> printNumber) {
	```
	Defines the `zero` function, which prints zero followed by odd and even numbers in alternating sequence.

10. **Variable Initialization**
	```cpp
	    int t = 0;
	```
	Initializes a flag variable `t` that helps control whether `mtx1` or `mtx2` is unlocked.

11. **Loop Control**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Loops through the range from 0 to `n`, controlling the printing sequence.

12. **Mutex Lock**
	```cpp
	        mtx.lock();
	```
	Locks the main mutex `mtx` to ensure exclusive access to the shared resource (printing).

13. **Print Function**
	```cpp
	        printNumber(0);
	```
	Prints the number 0 using the provided `printNumber` function.

14. **Condition Check**
	```cpp
	        if(t == 0) {
	```
	Checks if the flag `t` is 0, which determines whether to unlock `mtx1` or `mtx2`.

15. **Flag Change**
	```cpp
	            t = 1;
	```
	Changes the flag `t` to 1 to indicate that the next step will unlock `mtx1`.

16. **Mutex Unlock**
	```cpp
	            mtx1.unlock();
	```
	Unlocks `mtx1` to allow the next thread (even or odd) to proceed.

17. **Else Condition**
	```cpp
	        }
	```
	Ends the first condition block for controlling the unlocking of `mtx1`.

18. **Condition Check**
	```cpp
	        else {
	```
	If `t` was 1, this else block executes to unlock `mtx2`.

19. **Flag Reset**
	```cpp
	            t = 0;
	```
	Resets the flag `t` to 0 to switch back to unlocking `mtx1`.

20. **Mutex Unlock**
	```cpp
	            mtx2.unlock();
	```
	Unlocks `mtx2` to allow the next thread to print its number.

21. **Loop End**
	```cpp
	        }
	```
	Ends the `if-else` block for controlling which mutex to unlock.

22. **Function End**
	```cpp
	    }
	```
	Marks the end of the `for` loop in the `zero` method.

23. **Function End**
	```cpp
	}
	```
	Marks the end of the `zero` method.

24. **Function Declaration**
	```cpp
	void even(function<void(int)> printNumber) {
	```
	Defines the `even` function, which prints the even numbers in the sequence.

25. **Variable Initialization**
	```cpp
	    int i = 2;
	```
	Initializes the variable `i` to 2, representing the first even number to be printed.

26. **Loop Control**
	```cpp
	    while(i <= n) {
	```
	Continues the loop until `i` exceeds `n`, printing all even numbers.

27. **Mutex Lock**
	```cpp
	        mtx2.lock();
	```
	Locks the `mtx2` mutex to synchronize access to the shared resource while printing even numbers.

28. **Print Function**
	```cpp
	        printNumber(i);
	```
	Prints the even number `i` using the provided `printNumber` function.

29. **Mutex Unlock**
	```cpp
	        mtx.unlock();
	```
	Unlocks the main mutex `mtx`, allowing the next thread (odd) to proceed.

30. **Increment**
	```cpp
	        i += 2;
	```
	Increments `i` by 2 to move to the next even number.

31. **Loop End**
	```cpp
	    }
	```
	Ends the `while` loop in the `even` method.

32. **Function End**
	```cpp
	}
	```
	Marks the end of the `even` method.

33. **Function Declaration**
	```cpp
	void odd(function<void(int)> printNumber) {
	```
	Defines the `odd` function, which prints the odd numbers in the sequence.

34. **Variable Initialization**
	```cpp
	    int i = 1;
	```
	Initializes the variable `i` to 1, representing the first odd number to be printed.

35. **Loop Control**
	```cpp
	    while(i <= n) {
	```
	Continues the loop until `i` exceeds `n`, printing all odd numbers.

36. **Mutex Lock**
	```cpp
	        mtx1.lock();
	```
	Locks the `mtx1` mutex to synchronize access to the shared resource while printing odd numbers.

37. **Print Function**
	```cpp
	        printNumber(i);
	```
	Prints the odd number `i` using the provided `printNumber` function.

38. **Mutex Unlock**
	```cpp
	        mtx.unlock();
	```
	Unlocks the main mutex `mtx`, allowing the next thread (even) to proceed.

39. **Increment**
	```cpp
	        i += 2;
	```
	Increments `i` by 2 to move to the next odd number.

40. **Loop End**
	```cpp
	    }
	```
	Ends the `while` loop in the `odd` method.

41. **Function End**
	```cpp
	}
	```
	Marks the end of the `odd` method.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since each thread executes a fixed number of times based on `n`, and there are no nested iterations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because only a few variables are needed for synchronization, and no additional space is required.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/print-zero-even-odd/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
