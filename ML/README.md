# Python

- [Python](#python)
	- [Virtualenv](#virtualenv)
		- [with vscode](#with-vscode)
		- [using cmd](#using-cmd)
	- [Convert `ipynb` files into html, markdown, pdf and other format files](#convert-ipynb-files-into-html-markdown-pdf-and-other-format-files)

## Virtualenv

### with vscode

> Create a virtual environment:

```powershell
virtualenv env
```

<div align="center" ><img src="../img/venv-1.jpg" alt="venv 1" width="700px"></div>

> Select and activate an environment in vscode:

<div align="center" ><img src="../img/venv-2.jpg" alt="venv 1" width="700px" ></div>

<div align="center" ><img src="../img/venv-3.jpg" alt="venv 1" width="700px" ></div>

_select `python.exe` from current\env\Script dir:_

<div align="center" ><img src="../img/venv-4.jpg" alt="venv 1" width="700px" ></div>

> Now vs code terminal will use `env` virtual environment

<div align="center" ><img src="../img/venv-5.jpg" alt="venv 1" width="700px" ></div>

### using cmd

```bash
# pre-install with anaconda..
pip install virtualenv 
pip list
```

Start `virtualenv`:

```cmd
virtualenv env
```

To `activate` or `deactivate` virtualenv:

```cmd
env\Scripts\activate
deactivate
```

## Convert `ipynb` files into html, markdown, pdf and other format files

```bash
# ipython nbconvert --to FORMAT notebook.ipynb

jupyter nbconvert --to html test.ipynb 
jupyter nbconvert --to markdown test.ipynb --output README.md
jupyter nbconvert --to pdf test.ipynb 

# Note: VsCode jupyter notebooks has built in converter 
```
[https://ipython.org/ipython-doc/3/notebook/nbconvert.html](https://ipython.org/ipython-doc/3/notebook/nbconvert.html)

[https://www.programmersought.com/article/95748768264/](https://www.programmersought.com/article/95748768264/)