# DateTime

[https://realpython.com/python-datetime/](https://realpython.com/python-datetime/)


```python
import datetime
```


```python
datetime.datetime.now()
```




    datetime.datetime(2021, 10, 16, 23, 58, 39, 133743)




```python
date_object = datetime.date.today()
print(date_object)
```

    2021-10-16
    

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
from datetime import datetime

DEADLINE = datetime(year=2021, month=12, day=12, hour=8)
countdown = DEADLINE - datetime.now()
print(f"Countdown to DEADLINE: {countdown}")

```

    Countdown to DEADLINE: 56 days, 7:56:10.039381
    
