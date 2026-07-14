# Quiz 2 Practice Question Answers
## Part 1 - Operator Overloading
### Q1
A function signature is a unique identifier based on a function's name and the input types. e.g. the function `int makeBread(int n, str s){...};`
would have the function signature makeBread-int-int

### Q2
operators can be overloaded as a member function of a class
```
class Bread
{
    public:
    Bread operator+ (const Bread &rhs){...};
}
```
as a friend function
```
friend Bread operator+ (const Bread& lhs, const Bread&rhs){...};
```
or as a free function

```
Bread operator+ (Bread lhs, const Bread& rhs)(...);
```

### Q3
`10 + timeA;` cannot be implemented as a member function of time24 since `timeA` is on the rhs of the operation

### Q4
A friend function is a nonmember function that is allowed to access the private members and functions of a class

### Q5
These must be overloaded as free functions since they operate on the iostream of the computer (something mostly innaccessible to the programmer)

### Q6
1. Overloading cannot change the name of an operator
2. Overloading cannot change the precedence
3. Overloading cannot change how operators behave on primitive types

### Q7
```
bool operator== (const time24& lhs, const time24& rhs)
{
    if ((lhs.hour == rhs.hour) && (lhs.minute == rhs.minute))
    {
        return True;
    }
    return False;
}
```

### Q8
```
ostream& operator<< (ostream& ostr, const time24& t)
{
    ostr << t.hour << ':' << t.minute;
    return ostr;
}
```

### Q9
All classes are provided with the `=` operator

### Q10
This works because operator<< returns an `ostr` object, which the next `<<` in series can operate on

## Part 2 - Stacks
### Q11
LIFO stands for last in first out, indicating that items are added to and removed from the end of the stack

### Q12
* `push()` adds it's argument to the top of the stack.
* `pop()` removes the element at the end of the stack
* `top()` returns the element at the top of the stack and allows it to be modified
* `empty()` returns whether or not the stack is empty
* `size()` returns the number of elements in the stack

### Q13
To call these, the stack must not be empty

### Q14

```
stack<int> s;
int i;
for (i = 1; i <= 5; i++)
    s.push(i);              // blank A
cout << "Stack size = " << s.size() << endl;
cout << "Popping the stack" << endl;
while (!s.empty())
{
    cout << s.top() << " ";
    s.pop();              // blank B
}
cout << endl;
```

### Q15
The activation records contain the function argument values, local variable values, and the return address

### Q16

The function will return `true` and s will contain `E, D, B, A`

### Q17
If the target is not found, the function returns `false` and the stack contents will be replaced in order

## Part 3 - Queues and Priority Queues

### Q18
A first in first out structure is one in which elements are removed in the order in which they were inserted in. Items are inserted at the top of the queue and removed from the bottom

### Q19
Queues do not have `top()` becuase you are only meant to interact with the item at the front of the queue

### Q20
```
queue<int> q;
int i;
for (i = 1; i <= 5; i++)
    q.push(i);              // blank A
cout << "Queue size = " << q.size() << endl;
cout << "Popping the queue" << endl;
while (!q.empty())
{
    cout << q.front() << " "; // blank B
    q.pop();                // blank C
}
cout << endl;
```

output:
```
Queue size 5
Popping the queue
1 2 3 4 5
```

### Q21
A scheduling queue must allow for events to arrive and be pushed into the queue and depart and be popped from it

### Q22
Items are removed based on their priority, which is determined by the user. 

### Q23
`T` must implement the `<` operator.

### Q24
```
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
output:
```
3 20
2 15
1 10
```

### Q25
```
template<typename T>
void psort(vector<T>& v)
{
    priority_queue<T> pq;
    int i, n = v.size();
    for (i = 0; i < n; i++)
        pq.push(v.at(i));          // blank A
    for (i = n - 1; i >= 0; i--)
    {
        v.at(i) = pq.top();          // blank B
        pq.pop();          // blank C
    }
}
```
`v` will end up sorted with the lowest element at `v[0]` due to the second for loop iterating from n to 0 and drawing from the top of pq

## Part 4 - Cross-cutting/concept check
### Q26
vectors are sequence containers, map is an associative container, while stack, queue, and priority queue are adapter containers

### Q27
Adapter containers wrap around underlying sequence containers to restrict how they can be accessed.

### Q28

A stack is like a stack of plates in your cabinets, you have to take and place at the top, you can't take a plate from the bottom. A queue is like a line at a coffee shop, you join at the back and have your order taken at the front. A priority queue is like taking a ticket at the deli, whoever has the highest ticket number comes first.