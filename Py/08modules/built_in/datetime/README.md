# DateTime

- [DateTime](#datetime)
  - [Creating Python datetime Instances](#creating-python-datetime-instances)
  - [Using Strings to Create Python datetime Instances](#using-strings-to-create-python-datetime-instances)
  - [DEADLINE](#deadline)

```python
"""
cd .\Py\08modules\built_in\datetime\
jupyter nbconvert --to markdown datetime.ipynb --output README.md

 """
from datetime import datetime,date

```


```python
datetime.now()
```




    datetime.datetime(2022, 6, 19, 23, 13, 26, 727317)




```python
date_object = date.today()
print(date_object)
```

    2022-06-19


## Creating Python datetime Instances


```python
from datetime import date, time, datetime
date(year=2020, month=1, day=31)
```




    datetime.date(2020, 1, 31)




```python
time(hour=13, minute=14, second=31)
```




    datetime.time(13, 14, 31)




```python
datetime(year=2020, month=1, day=31, hour=13, minute=14, second=31)
```




    datetime.datetime(2020, 1, 31, 13, 14, 31)



## Using Strings to Create Python datetime Instances


```python
from datetime import date
date.fromisoformat("2020-01-31")
```




    datetime.date(2020, 1, 31)




```python
print(datetime.now())
print(datetime.now().strftime('%H:%M:%S'))
print(datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
print(datetime.strptime(
    "2022-06-08 16:02:13.885533+06:00".split(".")[0], '%Y-%m-%d %H:%M:%S'))
print(datetime.fromisoformat(
    "2022-06-08 16:02:13.885533+06:00").strftime('%Y-%m-%d %H:%M:%S'))

```

    2022-06-19 23:14:20.711485
    23:14:20
    2022-06-19 23:14:20
    2022-06-08 16:02:13
    2022-06-08 16:02:13


## DEADLINE


```python
from datetime import datetime
print(datetime.now())
DEADLINE = datetime(year=2022, month=12, day=12, hour=8)
print(DEADLINE)
countdown = DEADLINE - datetime.now()
print(f"Countdown to DEADLINE: {countdown}")

```

    2022-06-19 23:15:19.630033
    2022-12-12 08:00:00
    Countdown to DEADLINE: 175 days, 8:44:40.368963

