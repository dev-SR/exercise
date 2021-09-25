# Python

- [Python](#python)
	- [Pipenv vs virtualenv vs conda environment](#pipenv-vs-virtualenv-vs-conda-environment)
		- [Virtualenv](#virtualenv)
			- [with vscode](#with-vscode)
			- [using cmd](#using-cmd)
		- [PipEnv](#pipenv)
		- [Create Anaconda Environment](#create-anaconda-environment)
	- [Using Pip to install packages to Anaconda Environment](#using-pip-to-install-packages-to-anaconda-environment)
	- [Convert `ipynb` files into html, markdown, pdf and other format files](#convert-ipynb-files-into-html-markdown-pdf-and-other-format-files)

## Pipenv vs virtualenv vs conda environment

### Virtualenv

Virtualenv was the default way of creating virtual environment for many years. It is still used by many although people are moving to improved `pipenv` or `conda` (explained below).

#### with vscode

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

#### using cmd

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

### PipEnv

Pipenv was created due to many shortcomings of virtualenv such as it not making a distinction if project dependency and the dependies of the project dependency, not having mechanism to distinguish dev and production needs etc.

To install pipenv, you need to install pip first. Then do

```bash
pip install pipenv
```

Next, you create a new environment by using

```bash
pipenv install
```

This will look for a `pipenv` file, if it doesn’t exist, it will create a new environment and activate it. As you can already see, the workflow is simplified by not seperating the process of creating a new environment from scratch vs creating with a existing file. To activate you can run

```bash
pipenv shell
```

To install new packages do pip install package , and pipenv will automatically add the package to the pipenv file that’s called Pipfile. You can also install package for just the dev environement by calling

```bash
pip install <package> --dev
```

### Create Anaconda Environment

[https://towardsdatascience.com/manage-your-python-virtual-environment-with-conda-a0d2934d5195](https://towardsdatascience.com/manage-your-python-virtual-environment-with-conda-a0d2934d5195)

```bash
# List all existing environments
conda env list
# Create a new environment
conda create --name env_name
conda create --name env_name python=3.7
# Activate your new environment
conda activate env_name
# Deactivate/Change your active environment
conda activate base # can be change using VScode also
conda deactivate
#  Remove your environment
conda env remove --name env_name
```

The environments created by Conda is always located in `/Users/.../anaconda3/envs/`. You may change the default location by using the following command but it is not encouraged. Conda can no longer find your environment by your environment name, you will have to specify the environment’s full path to activate it every time.

```
conda create --prefix /path/project-env
```

`conda list` also supports revision history. It is an incredibly useful feature to have to manage your package in the environment.

```sh
(project-env) username ~ % conda list --revision
# 2020-02-03 00:01:32  (rev 0)       # new environment
#     +ca-certificates-2020.1.1
#     +pip-20.0.2
#     +python-3.7.6...
# ...
# 2020-02-03 00:24:55  (rev 1)       # installed numpy
#     +blas-1.0
#     +intel-openmp-2019.4
#     +..
#     +six-1.14.0
# 2020-02-03 22:14:24  (rev 2)      # installed configparser
#     +configparser-3.5.0
```

Imagine you accidentally screw up your dependencies just because you update/install a new package. Revision history allows you to rollback your environment to the previous version just like that.

```bash
conda install --revision 1
## Package Plan ##
# environment location: /Users/username/opt/anaconda3/envs/project-env
# added / updated specs:
#     - configparser
#     - numpy
#     - python=3.7
# The following packages will be REMOVED:
# configparser-3.5.0-py37_0
```

## Using Pip to install packages to Anaconda Environment

```sh
# activate base env
conda activate

# now install your package
python -m pip uninstall pipenv
python -m pip install <package>
# -m mod : run library module as a script..
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
