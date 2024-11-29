
+++
authors = ["grid47"]
title = "Leetcode 1115: Print FooBar Alternately"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1115: Print FooBar Alternately in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
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
You are given a class `FooBar` with two methods: `foo()` and `bar()`. These methods are called concurrently by two threads. One thread calls `foo()` while the other calls `bar()`. You need to modify the program to ensure that the output alternates between 'foo' and 'bar', and 'foobar' is printed exactly `n` times. The threads should alternate their execution such that `foo()` is printed first, followed by `bar()`, and this pattern should continue for `n` times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` representing the number of times the pattern 'foobar' should be printed.
- **Example:** `Input: n = 3`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the string 'foobar' repeated `n` times, with each 'foo' and 'bar' printed by different threads in alternating order.
- **Example:** `Output: 'foobarfoobarfoobar'`
- **Constraints:**
	- The two threads should print 'foo' and 'bar' in alternating order, starting with 'foo'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Ensure that the two threads alternate between printing 'foo' and 'bar', starting with 'foo', for `n` times.

- Use two mutexes to control the execution order of the threads.
- Thread A prints 'foo', and thread B prints 'bar'. Thread A should print first, then thread B, and the alternation continues for `n` times.
{{< dots >}}
### Problem Assumptions ✅
- Threads are scheduled asynchronously, so thread A and thread B may not execute in any specific order without synchronization.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 1`  \
  **Explanation:** In this case, thread A calls `foo()` and thread B calls `bar()`. The expected output is 'foobar' because thread A prints 'foo' first, followed by thread B printing 'bar'.

- **Input:** `Input: n = 2`  \
  **Explanation:** Here, the expected output is 'foobarfoobar' because the pattern 'foo' followed by 'bar' should repeat twice.

{{< dots >}}
## Approach 🚀
The approach uses two mutexes to synchronize the threads. The first mutex ensures that 'foo' is printed first by thread A, and the second mutex controls the execution of thread B, ensuring 'bar' is printed after 'foo'.

### Initial Thoughts 💭
- We need to manage the execution order of two threads to ensure they print in the correct sequence.
- Using two mutexes allows us to control which thread prints at any given time, ensuring they alternate in the desired order.
{{< dots >}}
### Edge Cases 🌐
- Since n is guaranteed to be at least 1, there will always be at least one 'foobar' printed.
- For large values of `n`, the solution should handle multiple thread executions efficiently.
- When `n` is 1, the output is simply 'foobar'.
- The solution must handle both small and large values of `n` efficiently.
{{< dots >}}
## Code 💻
```cpp
int n;
mutex mtx1, mtx2;
public:
FooBar(int n) {
    mtx2.lock();
    this->n = n;
}

void foo(function<void()> printFoo) {
    
    for (int i = 0; i < n; i++) {
        mtx1.lock();
    	// printFoo() outputs "foo". Do not change or remove this line.
    	printFoo();
        mtx2.unlock();
    }
}

void bar(function<void()> printBar) {
    
    for (int i = 0; i < n; i++) {
        mtx2.lock();
    	// printBar() outputs "bar". Do not change or remove this line.
    	printBar();
        mtx1.unlock();
    }
}
```

This code defines a class `FooBar` where two tasks, `foo` and `bar`, alternate printing the strings 'foo' and 'bar' respectively. The synchronization between the tasks is achieved using two mutexes, `mtx1` and `mtx2`, to control the execution order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int n;
	```
	The variable `n` is declared to store the number of iterations for the tasks.

2. **Mutex Declaration**
	```cpp
	mutex mtx1, mtx2;
	```
	Two mutexes, `mtx1` and `mtx2`, are declared to synchronize the `foo` and `bar` functions and control the task execution order.

3. **Access Modifier**
	```cpp
	public:
	```
	Access modifier to define that the following functions can be accessed from outside the class.

4. **Constructor**
	```cpp
	FooBar(int n) {
	```
	The constructor `FooBar(int n)` is defined to initialize the variable `n` and lock `mtx2`.

5. **Locking Mutex**
	```cpp
	    mtx2.lock();
	```
	The mutex `mtx2` is locked in the constructor to prevent `bar` from starting before `foo`.

6. **Assigning Value**
	```cpp
	    this->n = n;
	```
	The constructor assigns the value of `n` to the class's `n` variable.

7. **Function Definition**
	```cpp
	void foo(function<void()> printFoo) {
	```
	The `foo` method is defined, where it will print 'foo' repeatedly for `n` times.

8. **For Loop**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	A `for` loop is used to execute the task `n` times.

9. **Locking Mutex**
	```cpp
	        mtx1.lock();
	```
	The mutex `mtx1` is locked to ensure that `foo` can execute before `bar`.

10. **Function Call**
	```cpp
	    	printFoo();
	```
	The function `printFoo()` is called to output 'foo'.

11. **Unlocking Mutex**
	```cpp
	        mtx2.unlock();
	```
	The mutex `mtx2` is unlocked, allowing `bar` to execute.

12. **Function Definition**
	```cpp
	void bar(function<void()> printBar) {
	```
	The `bar` method is defined, where it will print 'bar' repeatedly for `n` times.

13. **For Loop**
	```cpp
	    for (int i = 0; i < n; i++) {
	```
	A `for` loop is used to execute the task `n` times.

14. **Locking Mutex**
	```cpp
	        mtx2.lock();
	```
	The mutex `mtx2` is locked to ensure that `bar` can execute after `foo`.

15. **Print Bar**
	```cpp
	    	// printBar() outputs "bar". Do not change or remove this line.
	```
	A comment indicating that `printBar()` will output 'bar'. It should not be changed.

16. **Function Call**
	```cpp
	    	printBar();
	```
	The function `printBar()` is called to output 'bar'.

17. **Unlocking Mutex**
	```cpp
	        mtx1.unlock();
	```
	The mutex `mtx1` is unlocked, allowing `foo` to execute again.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since each thread executes `n` times, and there are no nested iterations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because only a fixed number of variables are used to control the thread synchronization.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/print-foobar-alternately/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
