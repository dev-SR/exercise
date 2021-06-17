## Install Virtualenv:

```bash
pip install virtualenv
```

Start `virtualenv`:

```
virtualenv env
```

To `activate` or `deactivate` virtualenv:

```
env\Scripts\activate
deactivate
```

## Convert `ipynb` files into html, markdown, pdf and other format files

```bash
# ipython nbconvert --to FORMAT notebook.ipynb

jupyter nbconvert --to html test.ipynb
jupyter nbconvert --to markdown test.ipynb
jupyter nbconvert --to pdf test.ipynb


```
[https://ipython.org/ipython-doc/3/notebook/nbconvert.html](https://ipython.org/ipython-doc/3/notebook/nbconvert.html)

[https://www.programmersought.com/article/95748768264/](https://www.programmersought.com/article/95748768264/)