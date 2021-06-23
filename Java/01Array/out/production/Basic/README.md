## Array vs ArrayList

### Removing Array Element

![img.png](./imgs/removeEl.jpg)

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
	values[i - 1] = values[i];
}
currentSize--;
```
