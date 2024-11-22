
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
**Code:**

{{< highlight cpp >}}
class Tweet {
public:
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
 */
{{< /highlight >}}
---

### 🚀 Problem Statement

Imagine you’re designing a simplified version of **Twitter**, where users can:

- **Post tweets**
- **Follow/unfollow other users**
- **View a personalized news feed** with tweets from themselves and the users they follow

Key operations:
- **Posting a tweet**: A user can post a tweet with a unique ID and a timestamp.
- **Getting the news feed**: A user can view their own tweets and tweets from the users they follow, sorted by timestamp (most recent first).
- **Following and unfollowing users**: A user can follow and unfollow other users, and this impacts what appears in their news feed.

Let’s dive into how we can build this Twitter-like system efficiently! 🧑‍💻

---

### 🧠 Approach

To simulate this Twitter-like system, we need to efficiently manage users, their tweets, and their relationships (follow/unfollow). Here's the plan:

1. **User and Tweet Management**: 
   - Each user has a unique ID, a set of followed users, and a linked list of their tweets.
   - Each tweet has an ID, a timestamp, and a pointer to the next tweet in the sequence.
   - Users can follow/unfollow other users, affecting what shows up in their feed.

2. **Tweet Ordering**: 
   - Tweets need to be displayed in **most recent first** order.
   - A **priority queue (heap)** is perfect for this because it always lets us access the tweet with the highest timestamp efficiently.

3. **Data Structure**:
   - **User Map**: A map (`userMap`) stores each user by their unique ID. It helps us quickly access user data.
   - **Tweet Linked List**: Each user has a linked list of tweets, with the newest tweet at the head.
   - **Priority Queue**: A heap stores tweets based on their timestamps, so we can efficiently get the most recent ones.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down the code step by step and understand how it all comes together. 💡

#### Step 1: Define the `Tweet` Class

The `Tweet` class represents a single tweet:
```cpp
class Tweet {
public:
    int id;  // Unique identifier for the tweet
    int time;  // Timestamp when the tweet was posted
    Tweet* next;  // Pointer to the next tweet in the linked list

    Tweet(int id, int time) {
        this->id = id;
        this->time = time;
        next = NULL;
    }
};
```
- Each tweet has an ID, a timestamp, and a link to the next tweet (forming a linked list).
- The linked list helps us store tweets in the order they were posted (newest at the front).

#### Step 2: Define the `User` Class

The `User` class manages information about a user:
```cpp
class User {
public:
    int id;
    set<int> followed;  // Set of users this user is following
    Tweet* tweet_head;  // Head of the linked list of tweets

    User(int id) {
        this->id = id;
        follow(id);  // Follow self by default
        tweet_head = NULL;
    }

    void follow(int id) {
        followed.insert(id);  // Add the user to the followed list
    }

    void unfollow(int id) {
        followed.erase(id);  // Remove the user from the followed list
    }

    void post(int id, int times) {
        Tweet* t = new Tweet(id, times);  // Create a new tweet
        t->next = tweet_head;  // Insert the tweet at the head of the list
        tweet_head = t;
    }
};
```
- **`follow()`**: Adds a user to the followed list.
- **`unfollow()`**: Removes a user from the followed list.
- **`post()`**: Adds a tweet to the front of the user's tweet list.

#### Step 3: Define the `Twitter` Class

The `Twitter` class manages the main operations: posting tweets, following/unfollowing, and getting the news feed:
```cpp
class Twitter {
public:
    int timeStamp = 0;  // Global timestamp for all tweets
    map<int, User*> userMap;  // Map storing users by their ID

    Twitter() {
        // Constructor to initialize the Twitter system
    }

    void postTweet(int userId, int tweetId) {
        if (!userMap.count(userId)) {
            User* u = new User(userId);  // Create a new user if not exists
            userMap[userId] = u;
        }
        userMap[userId]->post(tweetId, timeStamp++);  // Post the tweet with the current timestamp
    }
```
- **`userMap`** stores users and their data (tweets, followers).
- **`postTweet()`**: Adds a tweet to the user's tweet list, ensuring each tweet has a unique timestamp.

#### Step 4: Implement the `getNewsFeed()` Function

This function retrieves a user’s news feed, with tweets from the user and those they follow:
```cpp
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!userMap.count(userId)) {
            return res;  // Return empty result if user does not exist
        }

        set<int> users = userMap[userId]->followed;  // Get the list of users the user is following
        priority_queue<Tweet*, vector<Tweet*>, compare> pq;  // Max-heap to store tweets

        // Push the most recent tweet from each followed user into the priority queue
        for (int user : users) {
            Tweet* t = userMap[user]->tweet_head;
            if (t != NULL)
                pq.push(t);
        }

        int n = 0;
        while (!pq.empty() && n < 10) {  // Retrieve at most 10 tweets
            Tweet* t = pq.top();  // Get the tweet with the highest timestamp
            pq.pop();  // Remove it from the queue
            res.push_back(t->id);  // Add the tweet's ID to the result
            n++;
            if (t->next != NULL)
                pq.push(t->next);  // Push the next tweet from the same user
        }
        return res;  // Return the result containing tweet IDs
    }
```
- A **priority queue** is used to get the most recent tweets efficiently.
- The function retrieves up to 10 tweets, prioritizing newer ones.

#### Step 5: Implement the `follow()` and `unfollow()` Functions

These manage user relationships:
```cpp
    void follow(int followerId, int followeeId) {
        if (!userMap.count(followerId)) {
            User* u = new User(followerId);
            userMap[followerId] = u;
        }
        if (!userMap.count(followeeId)) {
            User* u = new User(followeeId);
            userMap[followeeId] = u;
        }
        userMap[followerId]->follow(followeeId);  // Make the follower follow the followee
    }

    void unfollow(int followerId, int followeeId) {
        if (userMap.count(followerId) && followerId != followeeId)
            userMap[followerId]->unfollow(followeeId);  // Make the follower unfollow the followee
    }
};
```
- **`follow()`** makes a user follow another user.
- **`unfollow()`** allows a user to stop following another user (except themselves).

---

### 📈 Complexity Analysis

#### Time Complexity:
- **postTweet**: **O(1)** — Inserting a tweet is constant time.
- **getNewsFeed**: **O(N log N)**, where `N` is the total number of tweets from followed users. This is because we use a priority queue (heap) to manage tweet retrieval.
- **follow/unfollow**: **O(1)** — Set operations are constant time.

#### Space Complexity:
- **O(N)** — Where `N` is the total number of tweets across all users. This includes the memory used by tweet objects and the `userMap`.

---

### 🏁 Conclusion

This Twitter-like simulation is both efficient and simple, handling the major operations like posting tweets, following/unfollowing users, and getting news feeds. By using data structures like **priority queues** and **sets**, we ensure fast access and optimal performance.

Key Takeaways:
- **Time Complexity**: O(N log N) for retrieving tweets, thanks to the priority queue.
- **Space Complexity**: O(N) for storing tweets and user data.
- This solution is well-suited for handling the simulation of social media interactions efficiently! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-twitter/description/)

---
{{< youtube pNichitDD2E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
