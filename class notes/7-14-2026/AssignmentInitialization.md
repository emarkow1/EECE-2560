# Assignment and Initialization
## Object Assignment
With dynamically allocated data
```
dynamicClass<int> objA(1,2), objB(3,4);
objA = objB;
```

| 100 | 102 | 103 | 104 | ... | 106 | 108 |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | 106 | 3 | 108 | ... | 2 | 4 |
| objA | | | objB | ... | | |

becomes

| 100 | 102 | 103 | 104 | ... | 106 | 108 |
| --- | --- | --- | --- | --- | --- | --- |
| 2 | 108 | 3 | 108 | ... | 2 | 4 |
| objA | | | objB | ... | | |

Now, nothing points to location 106, this causes a memory leak and unpredictable behavior. Now objA and objB can both modify location 108.

## Assignment Operator Overloading
Overload = as a mamber function
```
template<typename T>
```
>finish this
## Object initialization
copy constructor: takes one object as a const reference parameter
```
template <typename T>
dynamicClass<T> :: dynamicClass(const dynamicClass<t> &obj) : member1(obj.member)
{
    member2Ptr = new T;
    * member2Ptr = *(obj.member2Ptr);
}
```
## Initialization vs Assignment
```
dynamicClass<int> objA(3,5);

dynamicClass<int> objB(objA); // (1)

dynamicClass<int> objB = objA; // (1)

objB = func(objA);

dynamicClass<int> objA(3,5), objB(2,4);
objB = objA;
```

3 ways to call copy constructor
1. When an object is declared and initialized by an existing object
2. When an object is passed by value
3. 

Q1: C(m1, m2)? CC(obj)? D? A?

Constructor calls
1. C1: `objA(3,5)`
2. CC1: `objB = objA`
3. C2: `objC(0,0)`
4. CC2: `demo(objA,objB,5) -> dynamicClass<T> demo(**dynamicClass<T> one**, ...)`
5. C3: `dynamicClass<T> obj(m,m)`
6. CC3: `return obj`

Destructor calls
1. CC2: `one` oos demo
2. C3: `obj` oos demo
3. CC3: `return obj` oos main
4. C2: `objC` oos main
5. CC1: `objB` oos main
6. C1: `objA` oos main