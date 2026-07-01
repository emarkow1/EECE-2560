# More Vectors

## Constructor

4 ways to initialize a vector, 3 from yesterday, one new one

```
vector(); // -> no parameters (3)
vector(int n, const T& value = T()); // -> size (1) or size + initial value (2)
vector(T *first, T *last);
```

last one allows you to initialize the vector using the address range \[First, last\). This allows you to initialize a vector from an array

```
int intA = {9, 2, 7, 3, 12};

vector<int> vectA(intA, intA + 5); // (4)
```

(4) initialize through memory range -> copies the values, rather than taking their place in the memory

```
int intA = {9, 2, 7, 3,  12, 4, 6};

vector<int> vectA(intA, intA + 7);
```

hardcoding the length of the array is bad practice, instead use 

```
std::size()
```

```
intA.size() // -> returns the number of elements in the array
```

*could* use

```
std::sizeof(intA) / std::sizeof(int); // -> might work, but why would you do it
```

I think that one is more used in C programs

## Operations: Add & Remove Elements
### Add a value at the rear of a vector

```
void push_back(const T& value);
```

ex:
```
//v:{9, 2, 7, 3, 12}
cout << v.back(); // -> 12
cout << v.size(); // -> 5
v.push_back(5);
cout << v.back(); // -> 5
cout << v.size(); // -> 6

v.back() = 15;  // back() can be used as an LHS operator to write to the last element of a vector
```

### Delete a value at the rear of the vector
```
void pop_back(); //removes the last element, updates the back, size -1
```
**MUST** check if the vector is empty 
ex:
```
// v:{9, 2, 7, 3, 12, 15}
v.empty(); // -> False
v.pop_back();
cout << v.back();   // -> 12
cout << v.front();  // -> 9
v.front() = 100;    // equivalent to v[0]
```

Limitation: elements cannot be added or deleted from anywhere other than the back

### Modify the Size of a Vector

```
void resize(int n, const T& fill = T());
```

Similar to a second constructor. The new vector size is `int n`. New elements are filled with the `fill` argument. If the size is smaller than the original, the remaining elements at the front are kept.

ex:
```
//v:{7, 4, 9, 3, 1}
cout << v.size();   //size: 5
v.resize(10);       // {7, 4, 9, 3, 1, 0, 0, 0, 0, 0}
v.resize(10, 1);    // {7, 4, 9, 3, 1, 1, 1, 1, 1, 1} -> imagine the last line didn't happen
v.resize(4);        // {7, 4, 9, 3}
```

### Vector API

``` 
vector();
vector(int n, const T &value = T());
vector(T *first, T *last);

T &front(); //LHS, RHS, access or modify
const T &front() const; //RHS only, read-only

T &back(); //LHS, RHS, access or modify
const T &back() const;

bool empty() const;

T &operator[] (int i)

void resize(int n, const T &fill = T());
int size() const;
void clear(); //empt vector, size = 0

bool operator == (const vector&, const vector &);
bool operator < (const vector&, const vector &);
vector &operator = (const vector&); // v1 = v2

T &at(int i);
const T &at(int i);

//v: {1, 2, 3, 4}
v[8] = 100;
v.at(8) = 100; // safer, does bound checking
```

## Example: Joining Vectors

Given two vectors vA and vB, we join them by copying the elements of vB onto the end of vA. Vector vB is not changed.

```
join(vA, vB);
    template <typename T>
    void join (vector <T> &vA, const vector<T> &vB) 
    // pass vA by reference since we want to modify that
    // pass vB by const reference since we do not want to modify it
    {
        return vA.resize(vA.size() + vB.size(), vB);
    }
```

## Template Class

Rather than defining a vector type for every type (`int`, `float`, `str`, etc.), we can define a generic template so that we can use our functions on a vector containiny any type.

```
template <typename T>
class templateClass
{
    public:
        templateClass(const T& item);

        T f();

        void g(const T& item);
        ...
    private:
        T dataValue;
        ...
}
```

Quiz on Tuesday, closed notes