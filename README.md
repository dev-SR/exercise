# Quick Navigation

-  Vs Code Setting
   -  [Font](#font)
   -  [Terminal](#terminal)
-  Markdown Guides
   -  [Cheatsheets](#Cheatsheet)
   -  [Links](#links)
   -  [Images](#images)
   -  [Code and Syntax Highlighting](#code-and-syntax-highlighting)
-  Git and Github
   -  [Gist](#gist)
   -  [.gitignore commited files](#clear-git-cache).
   -  [Alias](#alias)
   -  [Commands for Github Repo](#githubrepo)
-  Unicode For Better Comments
   -  [Unicodes](#unicodes)

# Vs Code Setting:

## font

**For Editor:** _`FiraCode-Regular.ttf`_ and _`FiraCode-Bold.ttf`_ from:
[tonsky/FiraCode](https://github.com/tonsky/FiraCode)

**For Terminal:** _`FiraMono NF`_ from
[Nerd Font](https://github.com/tonsky/FiraCode)

## Terminal

### For Windows Terminal:

---

[mohyposh](https://github.com/jandedobbeleer/oh-my-posh)\
PowerShell Installation:

```
Install-Module oh-my-posh -Scope CurrentUser
```

Winget Installation:

```
winget install JanDeDobbeleer.OhMyPosh
```

List all themes:

```
Get-PoshThemes
```

Set Theme:

Path: `C:\Users\u\Documents\WindowsPowerShell`\
fileName: `Microsoft.PowerShell_profile.ps1`

```
Set-PoshPrompt -Theme pure
```

# Markdown Guide

---

## Cheatsheets

> [Cheatsheet-1](https://www.markdownguide.org/basic-syntax/)

> [Cheatsheet-1](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

## Links

```
[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

```

[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

### **Anchor to a heading in github flavored markdown**

---

Github automatically parses anchor tags out of your headers. So you can do the
following:

```
[Go to foo](#foo)
```

[Go to foo](#foo)

```
### Foo
```

> ### Foo

In the above case, the Foo header has generated an anchor tag with the name foo.

> **Note:**

-  just **_one #_** for all **heading** sizes
-  **no space** between # and anchor name
-  anchor tag names must be **_lowercase_**, and **_delimited by dashes_** if
   multi-word.

```
[click on this link](#my-multi-word-header)

### My Multi Word Header
```

> ### HACK: Referencing Empty Div

---

```md
## Content

-  [Chapter 1](#Chapter1)
-  [Chapter 2](#Chapter2)

<div id="Chapter1"></div>
## Chapter 1

Some text here.  
Some text here. Some text here.

## Chapter 2 <span id="Chapter2"><span>

Some text here.  
Some text here. Some text here.
```

## Images

```git
![Tux, the Linux mascot](/assets/images/tux.png)
![Tux, the Linux mascot](https://...)
```

![Tux, the Linux mascot](https://upload.wikimedia.org/wikipedia/commons/3/35/Tux.svg)

## Code and Syntax Highlighting

---

```
Inline `code` has `back-ticks around` it.
```

Inline `code` has `back-ticks around` it.

Blocks of code are either fenced by lines with three back-ticks ```\` , or are
indented with four spaces. I recommend only using the fenced code blocks --
they're easier and only they support syntax highlighting.

Basic Example:

````
```javascript
var s = "JavaScript syntax highlighting";
alert(s);


```python
s = "Python syntax highlighting"
print s


```No language indicated, so no syntax highlighting.
But let's throw in a <b>tag</b>.

````

```javascript
var s = 'JavaScript syntax highlighting';
alert(s);
```

```python
s = "Python syntax highlighting"
print s
```

```
No language indicated, so no syntax highlighting.
But let's throw in a <b>tag</b>.
```

Highlight Bash/shell code :

```properties
Shell:      console, shell
Bash:       bash, sh, zsh
PowerShell: powershell, ps
DOS:        dos, bat, cmd
```

or,

````
```properties
 npm run build
````

```properties
 npm run build
```

# GIT and GITHUB

## Gist

---

[Gist](https://gist.github.com/dev-SR)

## Clear Git Cache

---

[Ref](https://devconnected.com/how-to-clear-git-cache/)

When working with Git, you may want to add some new lines to your gitignore
files.

However, when listing the files to be committed in your staging area, you
realize that some of the ignored files are still showing up.

In this case, you may need to clear your Git cache.

**The easiest way to clear your Git cache is to use the “git rm” command with
the `–cached` option.**

```properties
 git rm --cached filename
```

> **Note** o not forget the `--cached` option or your file will be deleted from
> the filesystem.

### Clear Entire Git Cache

In some cases, you may want to clear the cache of your entire Git staging area.

This is particularly useful when you added multiple files that you want now to
be ignored via your `.gitignore` file.

**To clear your entire Git cache, use the `"git rm"` command with the `"-r"`
option for recursive.**

```properties
 git rm -r --cached .
```

<div id="alias"></div>

## Git Alias

```properties
[alias]
	a = add --all
	#############
	b = branch
	ba = branch -a
	bd = branch -d
	bdd = branch -D
	#############
	c = commit
	ca = commit -a
	cm = commit -m
	cam = commit -am
	cd = commit --amend
	cad = commit -a --amend
	######
	conf = config --global -e
	#############
	cl = clone
	#############
	f = fetch
	fo = fetch origin
	fu = fetch upstream
	#############
	l = log --oneline
	lg = log --oneline --graph --decorate
	#############
	m = merge
	ma = merge --abort
	mc = merge --continue
	ms = merge --skip
	#############
	o = checkout
	om = checkout main
	ob = checkout -b
	#############
	ps = push
	psf = push -f
	psu = push -u
	pst = push --tags
	#############
	pso = push origin
	psao = push --all origin
	psfo = push -f origin
	psuo = push -u origin
	#############
	psom = push origin main
	psaom = push --all origin main
	psfom = push -f origin main
	psuom = push -u origin main
	#############
	pl = pull
	pb = pull --rebase
	#############
	plo = pull origin
	pbo = pull --rebase origin
	plom = pull origin main
	ploc = !git pull origin $(git bc)
	pbom = pull --rebase origin main
	pboc = !git pull --rebase origin $(git bc)
	#############
	plu = pull upstream
	plum = pull upstream main
	pluc = !git pull upstream $(git bc)
	pbum = pull --rebase upstream main
	pbuc = !git pull --rebase upstream $(git bc)
	#############
	rb = rebase
	rba = rebase --abort
	rbc = rebase --continue
	rbi = rebase --interactive
	rbs = rebase --skip
	#############
	re = reset
	rh = reset HEAD
	reh = reset --hard
	rem = reset --mixed
	res = reset --soft
	rehh = reset --hard HEAD
	remh = reset --mixed HEAD
	resh = reset --soft HEAD
	rehom = reset --hard origin/main
	#############
	r = remote
	ra = remote add
	rr = remote rm
	rv = remote -v
	rn = remote rename
	rp = remote prune
	rs = remote show
	rao = remote add origin
	rau = remote add upstream
	rro = remote remove origin
	rru = remote remove upstream
	rso = remote show origin
	rsu = remote show upstream
	rpo = remote prune origin
	rpu = remote prune upstream
	#############
	rmf = rm -f
	rmrf = rm -r -f
	#############
	s = status
	sb = status -s -b
	#############
	sa = stash apply
	sc = stash clear
	sd = stash drop
	sl = stash list
	sp = stash pop
	ss = stash save
	ssk = stash save -k
	sw = stash show
	#############
	t = tag
	td = tag -d
	#############
	w = show
	wp = show -p
	wr = show -p --no-color
    ........
```

<div id="githubrepo"></div>

## Commands for Github Repo

…or create a new repository on the command line

```
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin <url>
git push -u origin main
```

…or push an existing repository from the command line

```
git remote add origin <url>
git branch -M main
git push -u origin main
```

# Unicodes

### LINKS

[Arrows](https://unicode-table.com/en/sets/arrow-symbols/)

[Box Drawing](https://unicode-table.com/en/blocks/box-drawing/)

### Examples:

```
    /**
       int **p = new int*[2]; <- array of Integer Pointers
             ┃
             ▼
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[0] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛
       ┏━━━━━━┓      ┏━━━━━━━━━━━━━━━┓
       ┃ p[1] ┃----> ┃ new int[n];   ┃
       ┗━━━━━━┛      ┗━━━━━━━━━━━━━━━┛

     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │   │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │   │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │   │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │   │
     └───┘───┘───┘───┘───┘
     ┌───┐───┐───┐───┐───┐
     │   │   │   │   │   │
     └───┘───┘───┘───┘───┘

           */
```
