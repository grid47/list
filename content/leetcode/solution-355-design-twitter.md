
+++
authors = ["grid47"]
title = "Leetcode 355: Design Twitter"
date = "2024-10-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 355: Design Twitter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/355.webp"
youtube = "pNichitDD2E"
youtube_upload_date="2022-01-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pNichitDD2E/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/355.webp" 
    alt="A sequence of tweets appearing on a glowing timeline, with interactions and retweets softly illuminating."
    caption="Solution to LeetCode 355: Design Twitter Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Design a simplified version of Twitter where users can post tweets, follow/unfollow other users, and view the most recent tweets in their news feed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of method calls to the Twitter object. Each method is represented as a list where the first element is the method name and the subsequent elements are the parameters passed to the method.
- **Example:** `["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[ ], [1, 10], [1], [1, 3], [3, 20], [1], [1, 3], [1]]`
- **Constraints:**
	- 1 <= userId, followerId, followeeId <= 500
	- 0 <= tweetId <= 104
	- All tweets have unique IDs.
	- At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

{{< dots >}}
### Output Specifications 📤
- **Output:** Each method call may return different outputs, for example, the postTweet function does not return anything, while getNewsFeed will return the 10 most recent tweet IDs.
- **Example:** `[null, null, [10], null, null, [20, 10], null, [10]]`
- **Constraints:**
	- The output of getNewsFeed should contain the tweet IDs in order of the most recent to least recent.

{{< dots >}}
### Core Logic 🔍
**Goal:** Design a Twitter system with basic functionality such as posting tweets, following/unfollowing users, and retrieving the latest tweets in a user's feed.

- Create a User class that stores tweets and followed users.
- Create a Twitter class that handles posting tweets, following/unfollowing users, and retrieving the news feed with the 10 most recent tweets.
{{< dots >}}
### Problem Assumptions ✅
- Users may follow and unfollow other users multiple times.
- Tweets are posted by the user or the users they follow.
{{< dots >}}
## Examples 🧩
- **Input:** `["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[ ], [1, 10], [1], [1, 3], [3, 20], [1], [1, 3], [1]]`  \
  **Explanation:** In this example, User 1 posts a tweet with ID 10, follows User 3, and receives tweets from User 3 in their feed. After unfollowing User 3, User 1 only sees their own tweets.

{{< dots >}}
## Approach 🚀
We will simulate the Twitter functionality using classes for Users and the main Twitter system, handling tweets, following, unfollowing, and retrieving news feeds.

### Initial Thoughts 💭
- The primary challenge is efficiently managing the tweets and followed users for each user.
- A priority queue or similar structure will help in retrieving the most recent tweets.
- We need a way to store the user's tweets and the users they follow, and we should retrieve the most recent tweets from both the user and the followed users efficiently.
{{< dots >}}
### Edge Cases 🌐
- When no tweets are posted yet, the news feed should return an empty list.
- Handle cases where many users are following each other and there are numerous tweets to retrieve.
- If a user unfollows themselves, it should not affect their own tweets in their news feed.
- Ensure that the solution handles up to 30,000 operations efficiently.
{{< dots >}}
## Code 💻
```cpp
int id;
int time;
Tweet* next;
Tweet(int id, int time) {
    this->id = id;
    this->time = time;
    next = NULL;
}
};

class User {
public:
int id;
set<int> followed;
Tweet* tweet_head;

User(int id) {
    id = id;
    follow(id); // follow self;
    tweet_head = NULL;
}

void follow(int id) {
    followed.insert(id);
}

void unfollow(int id) {
    followed.erase(id);
}

void post(int id, int times) {
    Tweet* t = new Tweet(id, times);
    t->next = tweet_head;
    tweet_head = t;
}
};


class Twitter {
public:
int timeStamp = 0;
map<int, User*> userMap;

public:
Twitter() {
    // user map init
}

void postTweet(int userId, int tweetId) {
    if(!userMap.count(userId)) {
        User* u = new User(userId);
        userMap[userId] = u;
    }
    userMap[userId]->post(tweetId, timeStamp++);
}

struct compare {
    bool operator()(const Tweet* l, const Tweet* r) {
        return l->time < r->time;
    }
};

vector<int> getNewsFeed(int userId) {
    vector<int> res;
    if(!userMap.count(userId)) {
        return res;
    };
    set<int> users = userMap[userId]->followed;
    
    priority_queue<Tweet*, vector<Tweet*>, compare> pq;

    for(int user: users) {
        Tweet* t = userMap[user]->tweet_head;
        if(t != NULL)
            pq.push(t);
    }
    int n = 0;
    while(!pq.empty() && n < 10) {
        Tweet* t = pq.top();
        pq.pop();
        res.push_back(t->id);
        n++;
        if(t->next != NULL)
            pq.push(t->next);
    }
    cout << n << "-";
    return res;
}

void follow(int followerId, int followeeId) {
    if(!userMap.count(followerId)) {
        User* u = new User(followerId);
        userMap[followerId] = u;
    }
    if(!userMap.count(followeeId)) {
        User* u = new User(followeeId);
        userMap[followeeId] = u;
    }        
    userMap[followerId]->follow(followeeId);
}

void unfollow(int followerId, int followeeId) {
    if(userMap.count(followerId) && followerId == followeeId)
        return;
        userMap[followerId]->unfollow(followeeId);
}

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
```

This section contains the complete code of the 'Twitter' class, including methods for posting tweets, following/unfollowing users, and getting the news feed. It defines a 'Tweet' class and handles a map of users, with each user having their own list of followers and tweets.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int id;
	```
	This is the declaration of the 'id' variable, which stores the unique identifier for the tweet.

2. **Variable Initialization**
	```cpp
	int time;
	```
	This variable tracks the time when the tweet is posted, used for ordering tweets.

3. **Pointer Initialization**
	```cpp
	Tweet* next;
	```
	This pointer links to the next tweet in the list, forming a chain of tweets for each user.

4. **Constructor**
	```cpp
	Tweet(int id, int time) {
	```
	This constructor initializes a new tweet with a unique id and timestamp.

5. **Variable Assignment**
	```cpp
	    this->id = id;
	```
	Assigns the passed tweet ID to the instance variable 'id'.

6. **Variable Assignment**
	```cpp
	    this->time = time;
	```
	Assigns the passed timestamp to the instance variable 'time'.

7. **Pointer Initialization**
	```cpp
	    next = NULL;
	```
	Initializes the 'next' pointer to NULL, as it points to the next tweet in the list.

8. **Class Declaration**
	```cpp
	class User {
	```
	Declares the 'User' class, which represents a user of Twitter, with the ability to post tweets and follow/unfollow other users.

9. **Variable Declaration**
	```cpp
	int id;
	```
	Holds the unique identifier for the user.

10. **Data Structure**
	```cpp
	set<int> followed;
	```
	Stores the list of users that this user is following.

11. **Pointer Declaration**
	```cpp
	Tweet* tweet_head;
	```
	Points to the head of the linked list of tweets posted by the user.

12. **Constructor**
	```cpp
	User(int id) {
	```
	Constructor for initializing a new user with a unique ID.

13. **Variable Assignment**
	```cpp
	    id = id;
	```
	Assigns the provided user ID to the user's 'id' variable.

14. **Method Call**
	```cpp
	    follow(id); // follow self;
	```
	Makes the user follow themselves by calling the follow method.

15. **Variable Initialization**
	```cpp
	    tweet_head = NULL;
	```
	Initializes the 'tweet_head' pointer to NULL, indicating that the user has not posted any tweets initially.

16. **Method Declaration**
	```cpp
	void follow(int id) {
	```
	Defines the 'follow' method that allows a user to follow another user by adding their ID to the 'followed' set.

17. **Set Insertion**
	```cpp
	    followed.insert(id);
	```
	Inserts the provided user ID into the 'followed' set, indicating that the user is now following this user.

18. **Method Declaration**
	```cpp
	void unfollow(int id) {
	```
	Defines the 'unfollow' method that allows a user to unfollow another user.

19. **Set Removal**
	```cpp
	    followed.erase(id);
	```
	Removes the provided user ID from the 'followed' set, meaning the user no longer follows this user.

20. **Method Declaration**
	```cpp
	void post(int id, int times) {
	```
	Defines the 'post' method that allows a user to post a tweet, which is added to their list of tweets.

21. **Tweet Creation**
	```cpp
	    Tweet* t = new Tweet(id, times);
	```
	Creates a new 'Tweet' object with the provided ID and timestamp.

22. **Pointer Assignment**
	```cpp
	    t->next = tweet_head;
	```
	Sets the new tweet's 'next' pointer to the current head of the tweet list.

23. **Pointer Assignment**
	```cpp
	    tweet_head = t;
	```
	Updates the 'tweet_head' pointer to point to the new tweet, making it the first tweet in the list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for operations like follow or unfollow, when no tweets need to be retrieved.
- **Average Case:** O(log N) for posting tweets and updating news feeds.
- **Worst Case:** O(N log N) for retrieving news feeds, where N is the number of users followed and tweets available.



### Space Complexity 💾
- **Best Case:** O(1) for simple operations without large followings or tweets.
- **Worst Case:** O(N) where N is the number of users and tweets.

The space complexity depends on the number of users, their followers, and the number of tweets stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-twitter/description/)

---
{{< youtube pNichitDD2E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
