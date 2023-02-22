# Pathlib

- [Pathlib](#pathlib)
  - [Home Dir](#home-dir)
  - [Current Dir](#current-dir)
  - [Get the first parent folder path](#get-the-first-parent-folder-path)
  - [Get the Nth parent folder path](#get-the-nth-parent-folder-path)
  - [Join paths](#join-paths)
  - [Create a directory if it does not exist](#create-a-directory-if-it-does-not-exist)
  - [Check if the path is a folder](#check-if-the-path-is-a-folder)
  - [Check if the path is a file](#check-if-the-path-is-a-file)
  - [Get the file name](#get-the-file-name)
  - [Get the file name without extension](#get-the-file-name-without-extension)
  - [Get the file extension](#get-the-file-extension)
  - [Iterate over files in a directory](#iterate-over-files-in-a-directory)
  - [Iterate over files in a directory incl. sub folder(s)](#iterate-over-files-in-a-directory-incl-sub-folders)

```python
"""
cd .\Py\10_io\pathlib
jupyter nbconvert --to markdown pathlib.ipynb --output README.md
"""
from pathlib import Path
```

`pathlib` is a module in Python's standard library that provides an object-oriented interface to manipulate the file system paths in a platform-independent way.

Why you should consider using pathlib ?
- `pathlib` makes it super easy to work with files and interact with the file system
- `pathlib` works accross all operating systems (Windows uses while Mac and Linux use / as a separator)
- `pathlib` is treating file paths as objects

## Home Dir


```python
Path.home()
```




    WindowsPath('C:/Users/soiko')



## Current Dir


```python
Path.cwd()
```




    WindowsPath('d:/CSE/Programs/Learn/exercise/Py/10_io/pathlib')



## Get the first parent folder path



```python
one_above = Path.cwd().parent
one_above
```




    WindowsPath('d:/CSE/Programs/Learn/exercise/Py/10_io')



## Get the Nth parent folder path


```python
Path.cwd().parents[2]
```




    WindowsPath('d:/CSE/Programs/Learn/exercise')



## Join paths


```python
cwd = Path.cwd()
joined_path = cwd / 'Output'
joined_path

```




    WindowsPath('d:/CSE/Programs/Learn/exercise/Py/10_io/pathlib/Output')




```python
Path("files") / "subfiles"
```




    WindowsPath('files/subfiles')



## Create a directory if it does not exist



```python
joined_path.mkdir(exist_ok=True)
```

## Check if the path is a folder


```python
joined_path.is_dir()
```




    True



## Check if the path is a file



```python
example_file = cwd / "files"/ "file1.txt"
example_file.is_file()
```




    True



## Get the file name


```python
file_name = example_file.name
file_name
```




    'file1.txt'



## Get the file name without extension


```python
file_name = example_file.stem
file_name
```




    'file1'



## Get the file extension



```python
file_extension = example_file.suffix
file_extension
```




    '.txt'



## Iterate over files in a directory



```python
target_dir = cwd / "files"
for file in target_dir.iterdir():
	print(file)
```

    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\file1 copy 2.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\file1 copy.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\subfiles


## Iterate over files in a directory incl. sub folder(s)



```python
for file in target_dir.rglob("*"):
	print(file)
```

    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\file1 copy 2.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\file1 copy.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\subfiles
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\subfiles\subf copy 2.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\subfiles\subf copy.txt
    d:\CSE\Programs\Learn\exercise\Py\10_io\pathlib\files\subfiles\subf.txt

