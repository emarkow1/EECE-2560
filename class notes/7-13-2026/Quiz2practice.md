# EECE 2560 — Quiz 2 Practice Questions

Work through the questions first, then check yourself against the **Answer Key** at the bottom. Question types are mixed on purpose: conceptual recall, code tracing, and short implementation.

---

## Part 1 — Operator Overloading

**Q1.** What is a *function signature*? Does changing the return type create a new signature? Give an example.

**Q2.** Name the three ways to overload an operator in C++ (the three "styles" shown in the slides), and state the key difference between them.

**Q3.** For the `time24` class you want all three of these expressions to compile:
```cpp
timeA + timeB;
timeA + 10;
10 + timeA;
```
Which one of these *cannot* be written as a member function of `time24`, and why?

**Q4.** What is a `friend` function, and why is it useful when overloading operators?

**Q5.** Why must `operator<<` and `operator>>` be overloaded as **global/free** functions rather than member functions? (Think about what the left-hand operand is.)

**Q6.** State three restrictions on operator overloading (things you are *not* allowed to change or do).

**Q7. (Implementation)** Fill in the body of the equality operator for `time24`, given that the class has `int hour;` and `int minute;`:
```cpp
bool operator== (const time24& lhs, const time24& rhs)
{
    // your code
}
```

**Q8. (Implementation)** Complete the stream insertion operator so that a `time24` prints as `hour:minute`:
```cpp
ostream& operator<< (ostream& ostr, const time24& t)
{
    // your code
    return ostr;
}
```

**Q9.** Which operator is automatically provided (by default) for *all* classes even if you never overload it?

**Q10.** Explain in one sentence why `(cout << t1) << t2;` works — what must `operator<<` return to allow this chaining?

---

## Part 2 — Stacks

**Q11.** A stack is a **LIFO** structure. Spell out what LIFO stands for, and state at which end(s) items are inserted and removed.

**Q12.** Match each `stack` operation to what it does: `push`, `pop`, `top`, `empty`, `size`.

**Q13.** What is the **precondition** for calling `top()` and `pop()` on a stack?

**Q14. (Code trace)** Fill in the two blanks, then state the exact printed output:
```cpp
stack<int> s;
int i;
for (i = 1; i <= 5; i++)
    _____________;              // blank A
cout << "Stack size = " << s.size() << endl;
cout << "Popping the stack" << endl;
while (!s.empty())
{
    cout << s.top() << " ";
    _____________;              // blank B
}
cout << endl;
```

**Q15.** When a program calls a function, the system pushes an **activation record** onto the system stack. List what an activation record specifies, and state what the system does with that record (a) when the function is *called* and (b) when it *returns*.

**Q16. (Harder trace)** Consider the `uncouple` function below. A stack `s` currently holds (top → bottom): `E, D, C, B, A`. You call `uncouple(s, C)`. What does `s` contain afterward (top → bottom), and what does the function return?
```cpp
template <typename T>
bool uncouple(stack<T>& s, const T& target) {
    stack<T> tmpStk;
    bool foundTarget = true;
    while (!s.empty() && s.top() != target) {
        tmpStk.push(s.top());
        s.pop();
    }
    if (!s.empty())  s.pop();
    else             foundTarget = false;
    while (!tmpStk.empty()) {
        s.push(tmpStk.top());
        tmpStk.pop();
    }
    return foundTarget;
}
```

**Q17.** In Q16, what does `uncouple` return if the target is *not* found in the stack, and what happens to the stack contents in that case?

---

## Part 3 — Queues and Priority Queues

**Q18.** A queue is a **FIFO** structure. Spell out FIFO, and state at which end items are inserted and at which end they are removed.

**Q19.** Contrast the accessor operations: a `stack` gives you `top()`, but a `queue` gives you `front()`. In your own words, why does a queue not have a `top()`?

**Q20. (Code trace)** Fill in the blanks, then give the exact printed output:
```cpp
queue<int> q;
int i;
for (i = 1; i <= 5; i++)
    _____________;              // blank A
cout << "Queue size = " << q.size() << endl;
cout << "Popping the queue" << endl;
while (!q.empty())
{
    cout << _____________ << " "; // blank B
    _____________;                // blank C
}
cout << endl;
```

**Q21.** In a scheduling queue, what are the two operations called, and which one pushes into the queue vs. pops from it?

**Q22.** A **priority queue** removes items differently from an ordinary queue. On what basis are items removed, and what determines an item's ranking?

**Q23.** For the STL `priority_queue<T>` to work, what must type `T` implement?

**Q24. (Code trace)** Give the exact output:
```cpp
priority_queue<int> pq;
pq.push(20);
pq.push(10);
pq.push(15);
while (!pq.empty())
{
    cout << pq.size() << " " << pq.top() << endl;
    pq.pop();
}
```
*(Hint: the default STL `priority_queue` is a max-heap.)*

**Q25. (Implementation + reasoning)** Here is the priority-queue sort. Fill in the three blanks, then state the order (ascending or descending) in which `v` ends up sorted, and explain why.
```cpp
template<typename T>
void psort(vector<T>& v)
{
    priority_queue<T> pq;
    int i, n = v.size();
    for (i = 0; i < n; i++)
        _____________;          // blank A
    for (i = n - 1; i >= 0; i--)
    {
        _____________;          // blank B
        _____________;          // blank C
    }
}
```

---

## Part 4 — Cross-cutting / concept check

**Q26.** Classify each of the following STL containers as **sequence**, **adapter**, or **associative**: `vector`, `stack`, `queue`, `map`, `priority_queue`.

**Q27.** Both `stack` and `queue` are called *adapter* containers. What does that mean — what do they use for underlying storage?

**Q28.** One-line each: give a real-world analogy for a stack, a queue, and a priority queue.

---
---

# Answer Key

### Part 1 — Operator Overloading

**A1.** A signature is the function's name plus its parameter types (e.g., `setSize-int-int`, `setSize-float`). The **return type is NOT part of the signature**, so `void f(int)` and `bool f(int)` conflict — you cannot overload on return type alone.

**A2.** (1) **Free (global) functions**, (2) **Friend functions**, (3) **Member functions**. Free functions take all operands as parameters and use public getters; friend functions are like free functions but are granted access to private members; member functions belong to the left operand's class and receive the left operand implicitly (via `this`), taking only the right operand as a parameter.

**A3.** `10 + timeA` cannot be a member function. A member `operator+` is called on the left operand, which must be an object of the class — but here the left operand is `int`. When the first operand might not be a class object, the operator must be a free or friend function.

**A4.** A friend function is a non-member function that the class explicitly grants access to its private/protected members (declared with `friend` inside the class). It's useful for operator overloading because it can access private data (like `hour`/`minute`) directly while still being a non-member — which is required when the left operand isn't the class object.

**A5.** The left-hand operand of `<<`/`>>` is a stream (`ostream`/`istream`), not your class. A member function's left operand must be an object of *its own* class, so you'd have to add the operator to `ostream`, which you can't modify. Making it a global (friend) function lets the stream be the left operand and your object the right operand.

**A6.** Any three of: you cannot change an operator's **arity** (number of operands); you cannot change its **precedence** or associativity; you cannot invent new operators; you cannot change how operators behave on **built-in types**; and you cannot overload the same operator as *both* a global and a member function. (Also: a few operators can't be overloaded at all.)

**A7.**
```cpp
bool operator== (const time24& lhs, const time24& rhs)
{
    return lhs.hour == rhs.hour && lhs.minute == rhs.minute;
}
```

**A8.**
```cpp
ostream& operator<< (ostream& ostr, const time24& t)
{
    ostr << t.hour << ':' << t.minute;
    return ostr;
}
```

**A9.** The **assignment operator `=`** (a default member-wise assignment) is provided automatically for all classes.

**A10.** `operator<<` returns the stream by reference (`ostream&`). So `(cout << t1)` evaluates to `cout` itself, which can then be used as the left operand of the next `<< t2`. Returning the stream is what enables chaining.

### Part 2 — Stacks

**A11.** **Last In, First Out.** Both insertion (`push`) and removal (`pop`) happen at the **same end**, called the **top**. The most recently pushed item is the first one popped.

**A12.** `push(item)` = insert at the top; `pop()` = remove the top item; `top()` = return a reference to the top item (without removing); `empty()` = true if the stack has no items; `size()` = number of items.

**A13.** The stack must **not be empty**. Calling `top()` or `pop()` on an empty stack violates the precondition.

**A14.** Blank A: `s.push(i)`  Blank B: `s.pop()`. Output:
```
Stack size = 5
Popping the stack
5 4 3 2 1 
```
(Pushed 1,2,3,4,5; LIFO pops in reverse order.)

**A15.** An activation record specifies (per the slides) the function's **arguments/parameters**, its **local variables**, and the **return location** (address to return to). The system **pushes** an activation record when a function is *called* and **pops** it when the function *returns*.

**A16.** The loop moves `E, D` onto `tmpStk` (they aren't the target), then finds `C` on top and pops it (the `if (!s.empty()) s.pop();` removes the target). Then `tmpStk` is emptied back onto `s`. Result — `s` contains, top → bottom: **`E, D, B, A`** (C removed, relative order preserved). Return value: **`true`**.

**A17.** If the target is never found, the first loop empties all of `s` into `tmpStk`, `s` becomes empty so `foundTarget` is set to **`false`**, and then everything is pushed back. The stack is **restored to its original contents**, and the function returns **`false`**.

### Part 3 — Queues and Priority Queues

**A18.** **First In, First Out.** Items are inserted at the **back** (`push`) and removed at the **front** (`pop`). The earliest item added is the first removed.

**A19.** A queue only allows access at the front (the next item to leave), since removals happen there — there's no meaningful "top." `front()` returns the oldest element; a stack's `top()` returns the newest. The naming reflects *where* access is allowed in each structure.

**A20.** Blank A: `q.push(i)`  Blank B: `q.front()`  Blank C: `q.pop()`. Output:
```
Queue size = 5
Popping the queue
1 2 3 4 5 
```
(FIFO — pops in the same order they were pushed.)

**A21.** **Enqueue** (push into the queue) and **dequeue** (pop from the queue).

**A22.** Items are removed according to **priority/ranking**, *not* the order in which they entered. Ranking is set by some **external criterion** (e.g., task importance, deadline).

**A23.** Type `T` must implement the comparison operator **`<`** (the `operator<`), since the priority queue orders elements by comparing them.

**A24.** Default `priority_queue` is a max-heap, so `top()` is always the current largest:
```
3 20
2 15
1 10
```

**A25.** Blank A: `pq.push(v[i])`  Blank B: `v[i] = pq.top()`  Blank C: `pq.pop()`. The vector ends up sorted in **ascending order**. Reason: the max-heap yields the largest element first; the second loop writes from the *end* of the vector backward (`i = n-1 → 0`), so the largest goes to the last slot, next-largest to the second-last, etc., producing smallest → largest.

### Part 4 — Cross-cutting

**A26.** `vector` = sequence; `stack` = adapter; `queue` = adapter; `map` = associative; `priority_queue` = adapter.

**A27.** An adapter container doesn't store data itself — it *wraps* another container as its underlying storage and exposes a restricted interface on top of it (e.g., `stack` typically over a `deque`/`vector`, exposing only push/pop/top).

**A28.** Stack — a stack of cafeteria trays (take/add from the top). Queue — a grocery checkout line (first in line served first). Priority queue — a hospital ER triage (most critical patient seen first, regardless of arrival order).