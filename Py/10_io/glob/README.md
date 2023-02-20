# Glob


```python
"""
cd ./Py/10_io/glob
jupyter nbconvert --to markdown glob_module.ipynb --output README.md
"""

```

The `glob` module in Python is used to **search for files and directories** whose *names match a specified patter*n. Here's an example use case:




```python
from glob import glob
files = glob("files/*")
files

```




    ['files\\aasdjl copy 2.txt',
     'files\\aasdjl copy 3.txt',
     'files\\aasdjl copy.txt',
     'files\\aasdjl.txt',
     'files\\ex copy 2.csv',
     'files\\ex copy.csv',
     'files\\ex.csv',
     'files\\input1.txt',
     'files\\input2.txt']



- Finding files with a particular extension:


```python
csv_files = glob('files/*.csv')
csv_files
```




    ['files\\ex copy 2.csv', 'files\\ex copy.csv', 'files\\ex.csv']



- Suppose you have a directory that contains many `text` files, and you want to search for all the files that contain the word `"input"` in their names. You can use the glob module to achieve this:


```python
files = glob("files/*input*.txt")
files

```




    ['files\\input1.txt', 'files\\input2.txt']



- Sorting files:


```python
import os
files =glob('files/*')
files = sorted(files, key=os.path.getmtime, reverse=True)
print(files)

```

    ['files\\ex copy 2.csv', 'files\\ex copy.csv', 'files\\ex.csv', 'files\\input1.txt', 'files\\input2.txt', 'files\\aasdjl copy 2.txt', 'files\\aasdjl copy 3.txt', 'files\\aasdjl copy.txt', 'files\\aasdjl.txt']

