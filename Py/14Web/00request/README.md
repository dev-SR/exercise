# Get data from Api


```python
# !pip install requests [not required if anaconda is used]
import requests
```


```python
url = 'https://jsonplaceholder.typicode.com/todos/1'
res = requests.get(url)
res
```




    <Response [200]>




```python
res.status_code
```




    200




```python
type(res.text)
```




    str




```python
res.text
```




    '{\n  "userId": 1,\n  "id": 1,\n  "title": "delectus aut autem",\n  "completed": false\n}'




```python
import json
```


```python
data = json.loads(res.text)
print(data)
print()
print(data['title'])
```

    {'userId': 1, 'id': 1, 'title': 'delectus aut autem', 'completed': False}
    
    delectus aut autem
    

# Scrape an Image


```python
url ='https://store.storeimages.cdn-apple.com/4982/as-images.apple.com/is/iphone-12-pro-family-hero?wid=470&hei=556&fmt=jpeg&qlt=95&.v=1604021663000'

res = requests.get(url)
res
```




    <Response [200]>




```python
binary_data = res.content
```


```python
with open("iphone.jpg","wb") as f: 
    f.write(binary_data) # wb-> write binary mode
```


```python

```
