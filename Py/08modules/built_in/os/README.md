```python
import os
print(dir(os))
```

    ['DirEntry', 'F_OK', 'MutableMapping', 'O_APPEND', 'O_BINARY', 'O_CREAT', 'O_EXCL', 'O_NOINHERIT', 'O_RANDOM', 'O_RDONLY', 'O_RDWR', 'O_SEQUENTIAL', 'O_SHORT_LIVED', 'O_TEMPORARY', 'O_TEXT', 'O_TRUNC', 'O_WRONLY', 'P_DETACH', 'P_NOWAIT', 'P_NOWAITO', 'P_OVERLAY', 'P_WAIT', 'PathLike', 'R_OK', 'SEEK_CUR', 'SEEK_END', 'SEEK_SET', 'TMP_MAX', 'W_OK', 'X_OK', '_AddedDllDirectory', '_Environ', '__all__', '__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', '_check_methods', '_execvpe', '_exists', '_exit', '_fspath', '_get_exports_list', '_putenv', '_unsetenv', '_wrap_close', 'abc', 'abort', 'access', 'add_dll_directory', 'altsep', 'chdir', 'chmod', 'close', 'closerange', 'cpu_count', 'curdir', 'defpath', 'device_encoding', 'devnull', 'dup', 'dup2', 'environ', 'error', 'execl', 'execle', 'execlp', 'execlpe', 'execv', 'execve', 'execvp', 'execvpe', 'extsep', 'fdopen', 'fsdecode', 'fsencode', 'fspath', 'fstat', 'fsync', 'ftruncate', 'get_exec_path', 'get_handle_inheritable', 'get_inheritable', 'get_terminal_size', 'getcwd', 'getcwdb', 'getenv', 'getlogin', 'getpid', 'getppid', 'isatty', 'kill', 'linesep', 'link', 'listdir', 'lseek', 'lstat', 'makedirs', 'mkdir', 'name', 'open', 'pardir', 'path', 'pathsep', 'pipe', 'popen', 'putenv', 'read', 'readlink', 'remove', 'removedirs', 'rename', 'renames', 'replace', 'rmdir', 'scandir', 'sep', 'set_handle_inheritable', 'set_inheritable', 'spawnl', 'spawnle', 'spawnv', 'spawnve', 'st', 'startfile', 'stat', 'stat_result', 'statvfs_result', 'strerror', 'supports_bytes_environ', 'supports_dir_fd', 'supports_effective_ids', 'supports_fd', 'supports_follow_symlinks', 'symlink', 'sys', 'system', 'terminal_size', 'times', 'times_result', 'truncate', 'umask', 'uname_result', 'unlink', 'urandom', 'utime', 'waitpid', 'walk', 'write']
    


```python
os.getcwd() # current woring dir
```




    'd:\\CSE\\Others\\Codes\\Py\\08modules\\built_in\\os'




```python
os.mkdir("newly_created")
```


```python
os.listdir()
```




    ['newly_created', 'py_os.ipynb']




```python
# os.remove()
# os.removedirs()
# os.rename()
```


```python
import sys
```


```python
sys.version
```




    '3.8.10 (default, May 19 2021, 13:12:57) [MSC v.1916 64 bit (AMD64)]'




```python
sys.path
```




    ['d:\\CSE\\Others\\Codes\\Py\\08modules\\built_in\\os',
     'c:\\Users\\soiko\\.vscode\\extensions\\ms-toolsai.jupyter-2021.9.1101343141\\pythonFiles',
     'c:\\Users\\soiko\\.vscode\\extensions\\ms-toolsai.jupyter-2021.9.1101343141\\pythonFiles\\lib\\python',
     'C:\\ProgramData\\Anaconda3\\python38.zip',
     'C:\\ProgramData\\Anaconda3\\DLLs',
     'C:\\ProgramData\\Anaconda3\\lib',
     'C:\\ProgramData\\Anaconda3',
     '',
     'C:\\Users\\soiko\\AppData\\Roaming\\Python\\Python38\\site-packages',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages\\locket-0.2.1-py3.8.egg',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages\\win32',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages\\win32\\lib',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages\\Pythonwin',
     'C:\\ProgramData\\Anaconda3\\lib\\site-packages\\IPython\\extensions',
     'C:\\Users\\soiko\\.ipython']


