# Queues and Priority Queues

`d_queue.h` (miniqueue) -> use list
`prg8_1.cpp`

Ford & opp Ch. 8

## Queue
Model for a queue: grocery store checkout, airport boarding, etc.

A queue is a first in first out (FIFO) data structure.

Elements are inserted in the back of the queue and are removed at the front of the queue.

Only the item at the front of the queue can be modified.

| out <- | A | B | C | ... | <- in |
| --- | --- | --- | --- | --- | --- |

```
queue();
```
create an empty queue

```
bool empty() const;
```
check whether the queue is empty, return true if it is empty and false if it is not

```
pop();
```
precondition: the queue is not empty
postcondition: the element at the front of the queue is the element that was added immediately after the element just popped or the queue is empty

```
push(const T& item);
```
Insert the argument item at the back of the queue

## Queue Object

```
#include <queue>
...
queue<int> q;
int i;
for (i=1; i<=5; i++)
    q.push(i); 
cout << "Queue size = " << q.size << endl;
cout << "Popping the queue << endl;

while (!q.empty())
{
    cout << q.front() << " ";
    q.pop();
}
cout << endl;
```

## Application: Scheduling Queue
A queue of system tasks or jobs
* Scheduling discipline: FIFO, SJF (short job first), EDF (easiest deadline first)
* arrive event -> push into the queue
* depart event -> pop from the queue

Example: job interview schedule
prg8-1.cpp

## Priority Queue

A special form of queue from which items are removed according to priority and not the order in which they entered.

Ranking is determined by some external criterion, e.g. a waiting list of system tasks based on task size or task urgency (deadline)

Rule 1: allowed to access/remove the item with the highest priority

Constructor 
```
priority_queue();
```
* Create an empty priority queue
* Rule 2: Type T must implement the operator <

Underlying data structure: `max_heap` -> binary tree structure

## Operations

```
bool empty() const;
```
check whether the priority queue is empty

```
void pop();
```
remove the item with highest priority, the queue must not be empty

```
void push(const T& item);
```
insert the item at position depending on priority

```
int size() const;
```
return the number of items in the priority queue

```
const T& top(); 
```
return the item with the highest priority, only allows reading the value so that the user cannot change the priority of the item.

## Priority Queue Object

```
#include <queue>

priority_queue<int> pq;

pq.push(20)
pq.push(10)
pq.push(15)

while (!pq.empty())
{
    cout << pq.size() << " " << pq.top() << endl;
    pq.pop();
}
```

## Sorting w/ a Priority Queue

```
template<typename T>
void psort(vector<T & v)
{
    priority_queue<t> pq;
    int i, n = v.size();

    for(i=0;i<n;i++)
        pq.push(v.at(i))
    
    for(i=n-1;i>=0;i--)
        v.at(i) = pq.top();
        cout << pq.top() << " ";
        pq.pop();
    cout << endl;
}
```