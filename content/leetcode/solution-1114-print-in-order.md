
+++
authors = ["grid47"]
title = "Leetcode 1114: Print in Order"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1114: Print in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a class with three methods: `first()`, `second()`, and `third()`. These methods are called concurrently by three threads. The goal is to ensure that `second()` is executed only after `first()` has been executed, and `third()` is executed only after `second()` has been executed. The execution of these methods is asynchronous, and you need to design a mechanism that guarantees the correct order of execution regardless of the operating system's thread scheduling.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of integers, where the integers represent the order in which the threads call the methods: 1 for `first()`, 2 for `second()`, and 3 for `third()`.
- **Example:** `Input: nums = [1, 3, 2]`
- **Constraints:**
	- nums is a permutation of [1, 2, 3].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the concatenation of the strings printed by each method in the correct order. For example, if `first()`, `second()`, and `third()` are printed in the correct order, the output will be 'firstsecondthird'.
- **Example:** `Output: 'firstsecondthird'`
- **Constraints:**
	- The methods should be executed in the correct order, even if the threads are scheduled asynchronously.

{{< dots >}}
### Core Logic 🔍
**Goal:** Ensure that `second()` is executed after `first()`, and `third()` is executed after `second()`.

- Use a mechanism to control the order of method execution, such as using mutex locks or condition variables.
- Track the current method that should be executed and allow each thread to proceed only when it is their turn to execute the corresponding method.
{{< dots >}}
### Problem Assumptions ✅
- The methods `first()`, `second()`, and `third()` are executed by three different threads.
- Thread scheduling is unpredictable, and the order of execution is determined by the input array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 2]`  \
  **Explanation:** In this case, thread A calls `first()`, thread B calls `third()`, and thread C calls `second()`. The expected output is 'firstsecondthird', as `second()` should execute after `first()`, and `third()` should execute after `second()`.

- **Input:** `Input: nums = [2, 1, 3]`  \
  **Explanation:** In this case, thread A calls `second()`, thread B calls `first()`, and thread C calls `third()`. The expected output is 'firstsecondthird', as the order must be adjusted to maintain correct execution.

{{< dots >}}
## Approach 🚀
The solution involves controlling the execution order using synchronization primitives like mutex locks or condition variables. By tracking the current stage of execution, we can ensure the correct order of method invocations.

### Initial Thoughts 💭
- Since the threads are running concurrently, we need to control the execution order between them.
- Using locks or condition variables is a straightforward way to enforce the desired execution order.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain exactly three integers representing the methods to be executed.
- Since the input array is always a permutation of [1, 2, 3], there are no large inputs to consider.
- The solution should handle all permutations of [1, 2, 3].
- Ensure that the methods are executed in the correct order, regardless of thread scheduling.
{{< dots >}}
## Code 💻
```cpp
std::mutex mtx;
public:
Foo() {
    curVal = 1;
}

void first(function<void()> printFirst) {
    mtx.lock();
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    curVal++;
    mtx.unlock();
}

void second(function<void()> printSecond) {
    mtx.lock();
    while(curVal != 2)
    {
        mtx.unlock();
        mtx.lock();
    }
    mtx.unlock();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    curVal++ ;       
}

void third(function<void()> printThird) {
    mtx.lock();
    while(curVal != 3)
    {
        mtx.unlock();
        mtx.lock();
    }
    mtx.unlock();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    curVal++;
```

This code defines a class that manages a sequence of tasks (first, second, and third) where each task is executed in a specific order. The `mutex` is used to ensure thread safety and control the execution order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Mutex Declaration**
	```cpp
	std::mutex mtx;
	```
	A mutex `mtx` is declared to ensure that the tasks are executed in the correct order by preventing race conditions.

2. **Constructor**
	```cpp
	public:
	```
	Access modifier indicating that the following function is public.

3. **Constructor**
	```cpp
	Foo() {
	```
	The constructor of the class `Foo` is defined. It initializes the `curVal` variable to 1.

4. **Variable Initialization**
	```cpp
	    curVal = 1;
	```
	The integer variable `curVal` is initialized to 1, which will control the order of the execution of the tasks.

5. **First Task**
	```cpp
	void first(function<void()> printFirst) {
	```
	The `first` method is defined, which will execute the first task, printing 'first' when called.

6. **Lock**
	```cpp
	    mtx.lock();
	```
	The mutex `mtx` is locked to ensure that no other task is executed before this one.

7. **Function Call**
	```cpp
	    printFirst();
	```
	The `printFirst()` function is called to print 'first'.

8. **Update Variable**
	```cpp
	    curVal++;
	```
	The `curVal` variable is incremented to 2 to indicate that the first task is complete.

9. **Unlock**
	```cpp
	    mtx.unlock();
	```
	The mutex `mtx` is unlocked, allowing the next task to be executed.

10. **Second Task**
	```cpp
	void second(function<void()> printSecond) {
	```
	The `second` method is defined, which will execute the second task, printing 'second' when called.

11. **Lock**
	```cpp
	    mtx.lock();
	```
	The mutex `mtx` is locked to ensure exclusive access to the critical section.

12. **While Loop**
	```cpp
	    while(curVal != 2)
	```
	A `while` loop is used to wait until `curVal` is equal to 2, indicating that the first task has been completed.

13. **Unlock and Lock**
	```cpp
	        mtx.unlock();
	```
	Unlock the mutex to allow other threads to execute while the current task is waiting.

14. **Re-lock**
	```cpp
	        mtx.lock();
	```
	Re-lock the mutex to check the condition again and proceed once the `curVal` reaches 2.

15. **Unlock**
	```cpp
	    mtx.unlock();
	```
	Unlock the mutex to allow the next task to execute.

16. **Function Call**
	```cpp
	    printSecond();
	```
	The `printSecond()` function is called to print 'second'.

17. **Update Variable**
	```cpp
	    curVal++ ;
	```
	The `curVal` variable is incremented to 3 to indicate that the second task is complete.

18. **Third Task**
	```cpp
	void third(function<void()> printThird) {
	```
	The `third` method is defined, which will execute the third task, printing 'third' when called.

19. **Lock**
	```cpp
	    mtx.lock();
	```
	The mutex `mtx` is locked to ensure exclusive access.

20. **While Loop**
	```cpp
	    while(curVal != 3)
	```
	A `while` loop is used to wait until `curVal` is equal to 3, indicating that the second task has been completed.

21. **Unlock and Lock**
	```cpp
	        mtx.unlock();
	```
	Unlock the mutex to allow other threads to execute while the current task is waiting.

22. **Re-lock**
	```cpp
	        mtx.lock();
	```
	Re-lock the mutex to check the condition again and proceed once the `curVal` reaches 3.

23. **Unlock**
	```cpp
	    mtx.unlock();
	```
	Unlock the mutex to allow the next task to execute.

24. **Function Call**
	```cpp
	    printThird();
	```
	The `printThird()` function is called to print 'third'.

25. **Update Variable**
	```cpp
	    curVal++;
	```
	The `curVal` variable is incremented, indicating that all tasks have been completed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1) as the input size is fixed and each method is executed only once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because the solution only uses a fixed number of variables for synchronization.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/print-in-order/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
