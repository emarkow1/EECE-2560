# Dynamic Memory Allocation

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

## new

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

The whole object space of dPtr is dynamically allocated, while the dPtr itself is statically allocated.

## Destructors
What happens when obj goes out of scope?
```
void func()
{
    dynamicClass<int> obj(1,10);
} <- here
```
1. destructor called
2. free/deallocate space of obj

A special member function, the destructor, is called.
```
dyanmicClass<T> :: ~dynamicClass()
{
    delete member2Ptr;
}
```

OS handles statically allocated memory, we handle dynamically allocated memory. A destructor is necessary for dynamic allocation.

1. Destructor must always be named `~className`. 
2. Most of the time this is automatically called.
3. There cannot be any parameters
4. There are no return types or values
5. Constructor and destructor must be in the public session
6. Destructor cannot be overloaded

## Summary
* Statically declared objects
    * Automatically call constructors
    * Automatically call destructors
    * ex: `int x; time24 timeA; int* ptr; dynamicClass<int> obj;`
* Dynamically declared objects
    * new: allocate space and call constructor
    * delete: call destructor + deallocate space
    * ex: `int* p = new int(10); dynamicClass *dptr = new dynamicClass(2,20);`
* Constructor and Destructor
    * allocate/deallocate dynamic data members
    * new/delete

## Example:

Constructor called at:
* `dynamicClass<int> obj1(1,100)` - statically allocate obj1
* `ptrObj2 = new dynamicClass<int> (2,200)` - dynamically allocate ptrObj2
* `destroyDemo(3,300);` -> `dynamicClass<int> obj(m1, m2)` - statically allocate obj in scope of destroyDemo function

Destructor called at:
* `destroyDemo(3,300);` - statically deallocate as function scope closes
* `delete ptrObj2;` - dynamically deallocate ptrObj2
* at end of main function obj1 automatically goes out of scope.