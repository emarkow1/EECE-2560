# Pointers

Ford & Topp Ch. 5

## Data Addresses in Memory

integer 50 stored at memory position 5000

etc.

## Assigning Values to Pointers

A pointer is a special variable that stores the address of memory

```
&x
```
Is the address of the integer in memory
```
int x = 50;
```

Set `p1` to point at an actual data item.
```
int *p1;
p1 = &x;
cin >> *p1;
y = 2 + *p1;
*p1 = *p1 + 1;
cout << *p1;
```

`*p1` and `x` refer to the same memory location. 
* `*` the dereference operator
* `&` the "address of" operator

Another Example

```
int *p1, *p2;
int x, y;
x = y = 5;
p1 = &x;
p2 = &y;

cin >> *p1; // 15
cin >> *p2; // 10
*p1 = *p1 + *p2; // 15 + 10 -> p1
cout << x; // 25
cout << y; // 10

float *p3;
string *p4;
time24 *p5;
```

```
int *p1;
int x;
p1 = &x

p1 = 76; // should be *p1 = 76; compiler will give invalid conversion from int to int pointer

cout << p1;
cout << *p1;
```

the `*` and `&` operators are inverse of each other

```
&(*p1) -> &x
*(&x) -> *p1 -> x
```

Pass by value
```
void clear(int x)
{
    x = 0;
}
int main()
{
    int n = 10;
    clear(n);
    cout << n; // 10
    return 0;
}
```

Pass by reference
```
void clear (int &x)
...
```

Pass by pointer
```
void clear(int *p1)
{
    *p1 = 0;
}
int main()
{
    int n = 10;
    clear(&n);
    cout << n; // 0
    return 0;
}
```
Both pass by pointer and pass by reference can be used to change the variable outside the function.

What is wrong with this?
```
int x;   // Fix
int *p1; // error: p1 is not initialized. Points to nothing
p1 = &x; // Fix: now p1 has something to point to
*p1 = 9;
cout << "The value at address:" << p1 << "is" << *p1;

int y = 5;
cout << "y's value is" << y;
int *yptr = &y;
yptr = 9; // invalid conversion from int to int*
*yptr = 9; // fix
cout << "y's value is now" << *yptr;
```

## Dynamic Memory Allocation

Goal: point p1 to some new part of memory
operator: `new`

```
int *p1; float *p2;
p1 = new int;
p2 = new float;
*p1 = 9;
```

1. find a free space that is large enough for the type
    * e.g. `int` typically uses 32 bits
2. constructor of type called automatically

### new

need explicit casts
```
float *p1; p1 = new int;
```
destroy the old address stored in `p1`
```
int *p1; p1 = new int;
*p1 = 25; p1 = new int;
*p1 = 9;
```

`NULL` point

```
int *p1;
 p1 = NULL; // address of 0, points to nothing
 int *p2;
```

point to pointers

```
int x = 9;
int *p1 = &x;
int **p2 = &p1;
*p1 == 9;
**p2 == 9;
*(*p2) = 9;
```

## Deallocating Memory

Operator `delete` tells the OS the location is free to be used

```
int *ptr = new int;
*ptr = 17;
cout << *ptr << endl;
delete ptr; // OS frees space
ptr = NULL; //makes sure that you cannot use this pointer anymore


int *ptr2 = new int;
*ptr = 25;
cout << *ptr2 << endl;
*ptr = 6; // might work, depending on how memory has been allocated doesn't work after NULL addition
cout << *ptr2 << endl;
```

### For Quiz 2

next Tuesday
* Operator overloading
* Stack
* Queue and Priority Queue

### Deallocating memory examples
ex:

```
int *ptr1 = new int;
int *ptr2 = ptr1;

*ptr1 = 17;
cout << *ptr1 << *ptr2; // 17 17
delete ptr1;
cout << *ptr1 << *ptr2; // 17 17
// FIX
ptr1 = ptr2 = NULL
```
Causes unpredictable result because you are accessing a location that you shouldn't be able to

```
int *ptr;
ptr = new int;
*ptr = 17;
... (no delete ptr)
ptr = new int; // This will cause a memory leak since the space containing 17 was never deallocated
*ptr = 6;
```

## Arrays: Pointer Arithmetic
Array name: a const pointer to the first element in the array

```
int arr[7];
*arr == arr[0];
*(arr + 1) = arr[1];
```

the `1` here is one of the contained type's spaces (e.g. int8 has different size than int32)

Could also write
```
int *p; p = arr;

*p = arr[0]; *(p+1) = arr[1]
```

## Access Arrays and Allocate Arrays
Using a pointer to scan an array

```
double arr[] = {1.2, 4.5, 6.7, 9.0};
double *p = arr;
int arrSize = sizeof(arr)/sizeof(double);

while (p! = arr + arrSize)
{
    cout << *p << endl;
    p++;
}
```

Dynamic memory allocation to allocate arrays
```
int *ptr;
ptr = new int[100];
cout << ptr[0];
cout << ptr[1];
...
```

```
ptr[99] == *(ptr + 99) // equivalent representation
```

## Non-primitive Type Arrays
Dynamic Memory allocation

```
time24 *timeList;
timeList = new time24[10];
for (int i = 0; i < 10; i++)
    timeList[i].setHour(7);
```

Deallocate a dynamically allocated array
```
delete []timeList;
```

What is the difference?
```
int *p = new int(100);
int *p = new int[100];
```

```
delete p1; //frees 1 integer space

delete []p2;
```

## Pointers + Classes
How to access class members through a pointer?

```
rectangle box(2,5);

rectangle *rectPte;

rectPtr = &box;

cout << *rectPtr.area(); object .

cout << *rectPtr->area(); pointer ->
```

```
rectangle *rectPtr2;

rectPtr2 = new rectangle(2,5);

rectPtr2->setSize(7,10);

delete rectPtr2;
```

## Classes Using Dynamic Memory Allocation
Store data using dynamic memory
Constructor (allocate) + destructor (deallocate)

```
template <typename T>
class dynamicClass
{
    public:
    void print();
    ...
    private:
    T member1;
    T *member2Ptr; //Dyamically allocated
}
```

## Dynamic Class Constructor
dynamicClass Constructor

```
template <typename T>
dyamicClass<T> :: dynamicClass(const T &ml, const T &m2) : member(m1)
{
    member1 = m1;
    member2Ptr = new T(m2);
}

dynamicClass<int> obj(1, 10)
// 1. allocate space for obj
// 2. call constructor automatically
obj.print()
```

```
dynamicClass<int> *dPtr;
dPtr = new dynamicClass<int> (2, 20);
dPtr->print();
```