Overview:

-  [Add/Remove](#addremove)

# Array List Methods

<div id="addremove" class=""></div>
## Add/Remove

#### `public boolean add(Object element)`

-  **Add element to ArrayList**

```java
_.add("John");
```

#### `public void add(int index, Object element)`

-  **Add element at particular index of ArrayList**

```java
_.add(1,"John");
```

#### `public boolean addAll(Collection c)`

-  **Append Collection elements to ArrayList**

```java
ArrayList l1 = new ArrayList(Arrays.asList(1,2,3));
ArrayList l2 = new ArrayList(Arrays.asList(4,5));
l1.addAll(l2);//[1, 2, 3, 4, 5]
```

#### `public boolean addAll(int index, Collection c)`

-  **Insert all the collection elements to the specified position in ArrayList**

```java
ArrayList l1 = new ArrayList(Arrays.asList(1,2,3));
ArrayList l2 = new ArrayList(Arrays.asList(4,5));
l1.addAll(1,l2);//[1, 4, 5, 2, 3]
```

#### `public Object remove(int index)`

-  **Remove element from the specified index in ArrayList**
-  It removes an element and **returns the same**.
-  It throws `IndexOutOfBoundsException` if the specified index is less than
   zero or greater than the size of the list (index size of ArrayList).

```java
//Removing 1st element
 al.remove(0);
//Removing 3rd element from the remaining list
Integer e = list.remove(2);
```

#### `public boolean remove(Object obj)`

-  **Remove specified element from ArrayList**
-  It returns `false` if the specified element doesn’t exist in the list.
-  If there are duplicate elements present in the list it removes the first
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
