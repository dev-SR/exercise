# Array in Java

- [Array in Java](#array-in-java)
	- [Array vs ArrayList](#array-vs-arraylist)
	- [Creating Array in Java](#creating-array-in-java)
	- [Iterating Array in Java](#iterating-array-in-java)
	- [Input Array in Java](#input-array-in-java)
		- [Removing Array Element](#removing-array-element)
		- [Inserting Array Element](#inserting-array-element)

## Array vs ArrayList

<div align="center">
<img src="img/ArrVsArrList.png" alt="ArrVsArrList.png" width="800px">
</div>

## Creating Array in Java

```java
int arr[] = new int[5];
int arr[] = new int[5] {1,2,3,4,5};
int arr[] = {1,2,3,4,5};
String arr[] = {"Hello", "World"};
String arr[] = {"Hello", "World", null};
```

## Iterating Array in Java

```java
public static void display(int[] arr) {
        // Enhanced for Loop
        for (int el : arr) {
            System.out.print(el);
            // el = 0; // ERROR: this assignment does not modify array elements
        }
		// for (int i = 0; i < arr.length; i++) {
		// 	System.out.println(arr[i]);
		// }
		System.out.println();
		System.out.println(Arrays.toString(arr));
    }
```

## Input Array in Java

```java
	//..
	int[] arr = takeInput();
	//..

    public static int[] takeInput() {
        System.out.println("Size? ");
        int n = scn.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            System.out.println("Enter the value for " + i + " index?");
            arr[i] = scn.nextInt();
            cs++;
        }
        return arr;
    }
```

### Removing Array Element

<div align="center">
<img src="img/removeEl.jpg" alt="removeEl.jpg" width="800px">
</div>

If the elements in the array are not in any particular order, simply overwrite
the element to be removed with the last element of the array, then decrement the
current- Size variable.

```java
values[pos] = values[currentSize - 1];
currentSize--;
```

The situation is more complex if the order of the elements matters. Then you
must move all elements following the element to be removed to a lower index, and
then decrement the variable holding the size of the array.

```java
for (int i = pos + 1; i < currentSize; i++)
{
 arr[i - 1] = ar[i];
}
currentSize--;
```

### Inserting Array Element

<div align="center">
<img src="img/insertArray.jpg" alt="insertArray.jpg" width="800px">
</div>

If the order of the elements does not matter, you can simply insert new elements
at the end, incrementing the variable tracking the size.

```java
if (currentSize < values.length)
{
 currentSize++;
 arr[currentSize - 1] = newElement;
}
```

Note the order of the movement: When you remove an element, you first move the
next element to a lower index, then the one after that, until you finally get to
the end of the array. When you insert an element, you start at the end of the
array, move that element to a higher index, then move the one before that, and
so on until you finally get to the insertion location.

```java
if (currentSize < values.length){
 currentSize++;
 for (int i = currentSize - 1; i > pos; i--){
  arr[i] = arr[i - 1];
 }
 arr[pos] = newElement;
}
```
