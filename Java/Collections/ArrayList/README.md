# 1. Overview

- [Basic Array List Methods](#m)
  - [Initialize ArrayList](#i)
  - [Loop ArrayList](#itr)
  - [Find length of ArrayList](#len)
  - [Add/Remove](#addremove)
  - [Get/Search](#gs)
  - [Sort](#sort)
- [Working with ArrayList](#w)

<div id="m"/>

# 2. Basic ArrayList Methods

<div id="i" class=""></div>

## 2.1. Initialize ArrayList

### 2.1.1. Arrays.asList() – Initialize ArrayList from array

To initialize an arraylist in single line statement, get all elements in form of
array using `Arrays.asList` method and pass the `array` argument to `ArrayList`
constructor.

```java
ArrayList<String> names = new ArrayList<String>( Arrays.asList("alex", "brian", "charles") );
```

### 2.1.2. List.of() – Immutable list – Java 9

We can use `List.of()` static factory methods to create **`immutable`** lists.
Only drawback is that `add` operation is **not supported** in these lists.

```java
List<String> names = List.of("alex", "brian");
```

### 2.1.3. Use Collections.ncopies(count, element)

```java
ArrayList<Integer> intlist = new ArrayList<Integer>(Collections.nCopies(10, 5));
//ArrayList items: [5, 5, 5, 5, 5, 5, 5, 5, 5, 5]
```

### 2.1.4. Anonymous inner class method to initialize ArrayList

syntax:

```java
ArrayList<T> obj = new ArrayList<T>(){{
     add(Object o1);
     add(Object o2);
     add(Object o3);
                   ...
                   ...
     }};
```

ex:

```java
  ArrayList<String> cities = new ArrayList<String>(){{
     add("Apple");
     add("Mango");
     add("Banana");
     }};
```

### 2.1.5. Create ArrayList and add objects – ArrayList constructor

```java
ArrayList<String> l = new ArrayList<>();
//1. Add elements one by one
l.add("alex");
l.add("brian");
l.add("charles");

HashMap<String, Integer> ll = new HashMap<>();
//[alex, brian, charles]
ll.put("keanu", 23);
ll.put("max", 24);
ll.put("john", 53);

//2. Add elements from other collection
l.addAll(ll.keySet());
//[alex, brian, charles, max, john, keanu]
```

### 2.1.6. Initialize ArrayList of lists

```java
List<List<Integer>> l = new ArrayList<>();

l.add( Arrays.asList(10, 20, 30) );
l.add( Arrays.asList(40, 50, 60) );
l.add( Arrays.asList(70, 80, 90) );

for (List<Integer> i : l) {
   System.out.println(i);
}
// [10, 20, 30]
// [40, 50, 60]
// [70, 80, 90]
```

Please note that `Arrays.asList()` does not return `java.util.ArrayList`
instance. It returns `java.util.Arrays$ArrayList` instance instead. So if you
must have an ArrayList only, then create `ArrayList` for `Arrays.asList()`
instance in below manner.

```java
l.add(new ArrayList<Integer>( Arrays.asList(10, 20, 30) ));
```

<div id="len" class=""></div>

## 2.2. Find length of ArrayList

```java
l.size()
```

<div id="itr" class=""></div>

## 2.3. Iterate through ArrayList of objects

There are five ways to loop ArrayList.

- For Loop
- Advanced for loop
- List Iterator
- While Loop
- Java 8 Stream

```java
/* For Loop for iterating ArrayList */
for(int i = 0; i < l.size(); i++)
{
    System.out.println(l.get(i));
}

/* Advanced For Loop*/
for(String name : l)
{
    System.out.println(name);
}
      /* While Loop for iterating ArrayList*/
int index = 0;
while (l.size() > index)
{
   System.out.println(l.get(index++));
}

/*Looping Array List using Iterator*/
ListIterator<String> listItr = l.listIterator();
while(listItr.hasNext())
{
    System.out.println(listItr.next());
}
/**
 * Iterate arraylist with stream api
*/
ArrayList<String> l = new ArrayList<String>(Arrays.asList( "alex", "brian", "charles") );

l.forEach(name -> System.out.println(name));


```

<div id="addremove" class=""></div>

## 2.4. Add/Remove

- [Add element to ArrayList](#1)
- [Add element at particular index of ArrayList](#2)
- [Add only selected items to arraylist](#ad1)
- [Append Collection elements to ArrayList](#3)
- [Insert all the collection elements to the specified position in ArrayList](#4)
- [Replace element at specified index](#r1)
- [Replace element in ArrayList while iterating](#r2)
- [Remove element from the specified index in ArrayList](#5)
- [Remove specified element from ArrayList](#6)
- [Remove all element from arraylist by value](#7)

<div id="1"/>

### 2.4.1. Add element to ArrayList

`public boolean add(Object element)`

```java
l.add("John");
```

<div id="2"/>

### 2.4.2. Add element at particular index of ArrayList

`public void add(int index, Object element)`

```java
l.add(1,"John");
```

<div id="ad1"/>

### 2.4.3. Add only selected items to arraylist

This method uses `Java 8 stream` API. We create a stream of elements from first
list, add filter to get the desired elements only, and then collect filtered
elements to another list.

```java
//List 1
List<String> namesList = Arrays.asList( "alex", "brian", "charles");

//List 2
ArrayList<String> otherList = new ArrayList<>();

//skip element with value "alex"
namesList.stream()
    .filter(name -> !name.equals("alex"))
    .forEachOrdered(otherList::add);
```

<div id="3"/>

### 2.4.4. Append Collection elements to ArrayList

`public boolean addAll(Collection c)`

```java
ArrayList l1 = new ArrayList(Arrays.asList(1,2,3));
ArrayList l2 = new ArrayList(Arrays.asList(4,5));
l1.addAll(l2);//[1, 2, 3, 4, 5]
```

<div id="4"/>

### 2.4.5. Insert all the collection elements to the specified position in ArrayList

`public boolean addAll(int index, Collection c)`

```java
ArrayList l1 = new ArrayList(Arrays.asList(1,2,3));
ArrayList l2 = new ArrayList(Arrays.asList(4,5));
l1.addAll(1,l2);//[1, 4, 5, 2, 3]
```

<div id="r1"/>

### 2.4.6. Replace element at specified index

`ArrayList.set(int index, E element)`

```java
ArrayList<String> l = new ArrayList<String>(Arrays.asList( "alex", "brian", "charles") );
l.set(0, "Lokesh");
// [alex, brian, charles]
// [Lokesh, brian, charles]
```

<div id="r2"/>

### 2.4.7. Replace element in ArrayList while iterating

```java
ArrayList<String> l = new ArrayList<String>(Arrays.asList( "alex", "brian", "charles") );

//Replace item while iterating
for(int i=0; i < l.size(); i++)
{
    if(l.get(i).equalsIgnoreCase("brian")) {
        l.set(i, "Lokesh");
    }
}
```

<div id="5"/>

### 2.4.8. Remove element from the specified index in ArrayList

`public Object remove(int index)`

- It removes an element and **returns the same**.
- It throws `IndexOutOfBoundsException` if the specified index is less than
   zero or greater than the size of the list (index size of ArrayList).

```java
//Removing 1st element
 al.remove(0);
//Removing 3rd element from the remaining list
Integer e = list.remove(2);
```

<div id="6"/>

### 2.4.9. Remove specified element from ArrayList

`public boolean remove(Object obj)`

- It returns `false` if the specified element doesn’t exist in the list.
- If there are duplicate elements present in the list it removes the first
   occurrence of the specified element from the list.

```java
//Removing element Apple from the arraylist
l.remove("Apple");
//Removing element FF from the arraylist
l.remove("FF");
//Removing element CC from the arraylist
l.remove("CC");
/*This element is not present in the list so
 * it should return false
 */
boolean b = l.remove("GG");
```

<div id="7"/>

####

```java
ArrayList<String> l = new ArrayList<String>(Arrays.asList( "alex", "brian", "charles", "alex") );
l.removeIf( name -> name.equals("alex"));
// [alex, brian, charles, alex]
// [brian, charles]
```

<div id="gs" class=""></div>

## 2.5. Get/Search

- [Get element from ArrayList](#g1)
- [Get the index of first occurrence of the element in the ArrayList](#g2)
- [Get the index of last occurrence of the element in the ArrayList](#g3)
- [Check whether element exists in ArrayList](#g4)
- [Get Sub List of ArrayList](#g5)
  - [Remove Sub list of ArrayList](#g6)

<div id="g1"></div>

### 2.5.1. Get element from ArrayList

`public Element get(int index)`

- returns the value present at the specified index.
- This method throws `IndexOutOfBoundsException` if the index is _less_ than
   `zero` or _greater_ than the `size` of the list (index<0 OR index>= size of
   the list).

```java
_.get(0)
```

<div id="g2"></div>

### 2.5.2. Get the index of first occurrence of the element in the ArrayList

`public int indexOf(Object o)`

- This method returns `-1` if the specified element is not present in the list.

```java
l.indexOf("AB")//5
l.indexOf("AA")//-1
```

<div id="g3"></div>

### 2.5.3. Get the index of last occurrence of the element in the ArrayList

`public int lastIndexOf(Object obj)`

- It returns `-1` if the specified element does not exist in the list.

```java
l.lastIndexOf("AB")//5
l.lastIndexOf("AA")//-1
```

<div id="g4"></div>

### 2.5.4. Check whether element exists in ArrayList

`public boolean contains(Object element)`

-
- It returns `true` if the specified element is found in the list else it gives
   `false`.

```java
l.contains("ink pen"));
l.contains("pen"));
l.contains(1)
```

<div id="g5"></div>

### 2.5.5. Get Sub List of ArrayList

`List subList(int fromIndex, int toIndex)`

- Here `fromIndex` is **inclusive** and `toIndex` is **exclusive**.
- The subList method throws `IndexOutOfBoundsException` – if the specified
   indexes are out of the range of ArrayList **(fromIndex < 0 || toIndex >
   size)**. `IllegalArgumentException` – if the starting index is greater than
   the end point index **(fromIndex > toIndex)**.

```java
List l = new ArrayList(Arrays.asList(0,1,2,3,4,5,6,7,8,9));
List sublist = new ArrayList(l.subList(2, 6) );//[2, 3, 4, 5]
```

<div id="g6"></div>

#### 2.5.5.1. Remove Sub list of ArrayList

```java
List l = new ArrayList(Arrays.asList(0,1,2,3,4,5,6,7,8,9));
l.subList(2, 6).clear();//[0, 1, 6, 7, 8, 9]
```

<div id="sort"/>

## 2.6. Sort ArrayList

- [Sort arraylist of Strings](#s1)
  - [List.sort() method](#s2)
  - [Collections.sort() method](#s3)
  - [with Java 8 stream](#s4)
- [Sort arraylist of Integer](#s5)
- [Sort ArrayList of Objects using Comparable and Comparator](#s6)
- [Sort ArrayList of objects by multiple fields](#s7)
- [Sort ArrayList of objects using Collections.sort() method](#s8)

<div id="s1"></div>

### 2.6.1. Sort arraylist of strings

<div id="s2"></div>

#### 2.6.1.1. List.sort() method

Java program to sort any arraylist of strings alphabetically and _descending_
order.

```java
//Unsorted list
List<String> l = Arrays.asList("Alex", "Charles", "Brian", "David");

//1. Natural order
l.sort( Comparator.comparing( String::toString ) );
//[Alex, Brian, Charles, David]


//2. Reverse order
l.sort( Comparator.comparing( String::toString ).reversed() );

//[David, Charles, Brian, Alex]
```

<div id="s3"></div>

#### 2.6.1.2. Collections.sort() method

```java
//Unsorted list
List<String> l = Arrays.asList("Alex", "Charles", "Brian", "David");

//1. Natural order
Collections.sort(l);
 //[Alex, Brian, Charles, David]


//2. Reverse order
Collections.sort(l, Collections.reverseOrder());

//[David, Charles, Brian, Alex]
```

<div id="s4"></div>

#### 2.6.1.3. Sort arraylist of strings with Java 8 stream

```java
//Unsorted list
List<String> l = Arrays.asList("Alex", "Charles", "Brian", "David");
//1. Natural order
List<String> sorted =
                     l.stream()
                     .sorted(Comparator.comparing(String::toString))
                     .collect(Collectors.toList());

//2. Reverse order
List<String> reverseSorted =
                           l.stream()
                           .sorted(Comparator.comparing(String::toString).reversed())
                           .collect(Collectors.toList());
```

<div id="s5"></div>

### 2.6.2. Sort arraylist of integers

```java
/Unsorted list
List<Integer> l = Arrays.asList(1, 3, 5, 4, 2);

//1. Natural order
l.sort(Comparator.comparing(Integer::valueOf));   //[1, 2, 3, 4, 5]

//2. Reverse order
l.sort( Comparator.comparing( Integer::valueOf ).reversed() );

//3. Natural order
Collections.sort(l);      //[1, 2, 3, 4, 5]

//4. Reverse order
Collections.sort(l, Collections.reverseOrder());  //[5, 4, 3, 2, 1]
```

<div id="s6"></div>

### 2.6.3. Java sort arraylist of objects – Comparable and Comparator

1. [Employee - Model Class](#com1")
2. [Comparable Interface](#com2)
3. [Comparator Interface](#com3)
4. [Comparator in Java 8](#com4)
5. [hashCode() and equals()](#com6)

<div id="com2"></div>

#### 2.6.3.1. Comparable Example

##### 2.6.3.1.1. Implementing `compareTo(T o)` method of `Comparable` interface

`Comparable` interface provides one method `compareTo(T o)` to implement in any
class so that two instances of that class can be compared.

_Here, out of two instances to compare, one is instance itself on which method
will be invoked, and other is passed as parameter o._

> `Employee.java`

```java
public class Employee implements Comparable<Employee> {
    private int id = -1;
    private String firstName = null;
    private String lastName = null;
    private int age = -1;

    public Employee(int id, String fName, String lName, int age) {
        this.id = id;
        this.firstName = fName;
        this.lastName = lName;
        this.age = age;
    }

    @Override
    public int compareTo(Employee o) {
        return this.id - o.id;
    }
}
```

> Sorting by `Collections.sort()`

```java
public class TestSorting {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<Employee>();
        employees.add(new Employee(1, "aTestName", "dLastName", 34));
        employees.add(new Employee(2, "nTestName", "pLastName", 30));
        employees.add(new Employee(3, "kTestName", "sLastName", 31));
        employees.add(new Employee(4, "dTestName", "zLastName", 25));

        Collections.sort(employees);
    }
}
```

<div id="com3"></div>

#### 2.6.3.2. Comparator Example

So, now we can sort a list of employees by their `id`. Now let’s consider a case
where we want to sort employees list based on some user input which is
essentially sorting field i.e. sometimes he wants to `sort` by first `name`,
sometimes sort by `age` also.

A `Comparator` can be used to sort a collection of instances on some particular
basis. **To sort of different fields, we need multiple Comparator
implementations.**

> First name sorter

```java
import java.util.Comparator;
public class FirstNameSorter implements Comparator<Employee>{

   @Override
   public int compare(Employee o1, Employee o2) {
      return o1.getFirstName().compareTo(o2.getFirstName());
   }
}
```

> Last name sorter

```java
public class LastNameSorter implements Comparator<Employee> {

    @Override
    public int compare(Employee o1, Employee o2) {
        return o1.getLastName().compareTo(o2.getLastName());
    }
}
```

> Age sorter

```java
public class AgeSorter implements Comparator<Employee> {
    @Override
    public int compare(Employee o1, Employee o2) {
        return o1.getAge() - o2.getAge();
    }
}
```

> **Now, compare with Comparator:**

```java
public class TestSorting
{
    public static void main(String[] args){
        List<Employee> employees = new ArrayList<Employee>();
        employees.add(new Employee(1, "aTestName", "dLastName", 34));
        employees.add(new Employee(2, "nTestName", "pLastName", 30));
        employees.add(new Employee(3, "kTestName", "sLastName", 31));
        employees.add(new Employee(4, "dTestName", "zLastName", 25));

        // Default Sorting by employee id
        Collections.sort(employees);
        // Sorted by firstName
        Collections.sort(employees, new FirstNameSorter());
        // Sorted by lastName
        Collections.sort(employees, new LastNameSorter());
        // Sorted by age
         Collections.sort(employees, new AgeSorter());
    }
}

```

<div id="com4"></div>

#### 2.6.3.3. Comparator in Java 8

Latest Lambda changes have made using `Comparator` a lot easier than ever
before.

```java

List<Employee> employees  = getEmployeesFromDB();

//Sort all employees by first name
employees.sort(Comparator.comparing(e -> e.getFirstName()));

//OR you can use below
employees.sort(Comparator.comparing(Employee::getFirstName));

//Sort all employees by first name in reverse order
Comparator<Employee> comparator = Comparator.comparing(e -> e.getFirstName());
employees.sort(comparator.reversed());

//Sorting on multiple fields; Group by.
Comparator<Employee> groupByComparator = Comparator.comparing(Employee::getFirstName).thenComparing(Employee::getLastName);
employees.sort(groupByComparator);

```

> Note: create getFirstName() method in class

```java
// where create method
class Employee {
    private Integer id;
    private String firstName;
    //....
    public String getFirstName() {
        return firstName;
    }
}
```

<div id="com5"></div>

#### 2.6.3.4. hashCode() and equals()

<div id="s7"></div>

### 2.6.4. Sort ArrayList of objects by multiple fields

[https://howtodoinjava.com/java/sort/groupby-sort-multiple-comparators/](https://howtodoinjava.com/java/sort/groupby-sort-multiple-comparators/)

<div id="s8"></div>

### 2.6.5. Java Collections sort() Method

[https://howtodoinjava.com/java/sort/collections-sort/](https://howtodoinjava.com/java/sort/collections-sort/)

<div id="w"/>

# 3. Working with ArrayList

- [Compare two ArrayLists](#o1)
- [Synchronize ArrayList](#o2)
- [Swap two elements in ArrayList](#o3)
- [Serialize ArrayList](#o4)
- [Join two ArrayList](#o5)
- [Make ArrayList Empty](#o61)
- [Check whether ArrayList is empty or not](#o7)
- [Replace the value of existing element in ArrayList](#o8)
- [Remove duplicate elements in ArrayList](#o9)

<div id="o1"></div>

## 3.1. Compare two ArrayLists

1. [Compare for equality](#cc1)
2. [Compare and find additional elements](#cc2)
3. [Compare and find missing elements](#cc3)
4. [Compare and find common elements](#cc4)

<div id="cc1"></div>

### 3.1.1. Compare for equality

<div id="cc2"></div>

### 3.1.2. Compare and find additional element

<div id="cc3"></div>

### 3.1.3. Compare and find missing elements

<div id="cc4"></div>

### 3.1.4. Compare and find common elements

<div id="o2"></div>
<div id="o3"></div>
<div id="o4"></div>
<div id="o5"></div>
<div id="o6"></div>
<div id="o7"></div>
<div id="o8"></div>
<div id="o9"></div>
