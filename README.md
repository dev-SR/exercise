# 1. Quick Navigation

- Vs Code Setting
  - [Font](#font)
  - [Terminal](#terminal)
- Markdown Guides
  - [Cheatsheets](#cheatsheet)
  - [Links](#links)
  - [Images](#images)
  - [Mathematical Formula in markdown](#math)
  - [Code and Syntax Highlighting](#highlighting)
- Git and Github
  - [Gist](#gist)
  - [.gitignore commited files](#clear-git-cache).
  - [Alias](#alias)
  - [Commands for Github Repo](#githubrepo)
  - [Change the URI (URL) for a remote Git repository](#changeremote)
- Unicode For Better Comments
  - [Unicodes](#unicodes)

# 2. Vs Code Setting

## 2.1. font

**For Editor:** _`FiraCode-Regular.ttf`_ and _`FiraCode-Bold.ttf`_ from:
[tonsky/FiraCode](https://github.com/tonsky/FiraCode)

**For Terminal:** _`FiraMono NF`_ from
[Nerd Font](https://github.com/tonsky/FiraCode)

## 2.2. Terminal

### 2.2.1. For Windows Terminal

---

![img1](img/posh.png)

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

# 3. Markdown Guide

<div id="cheatsheet"/>

## 3.1. Cheatsheets

> [Cheatsheet-1](https://www.markdownguide.org/basic-syntax/)

> [Cheatsheet-1](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

<div id="links"/>

## 3.2. Links

```
[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

```

[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

### 3.2.1. **Anchor to a heading in github flavored markdown**

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

- just **_one #_** for all **heading** sizes
- **no space** between # and anchor name
- anchor tag names must be **_lowercase_**, and **_delimited by dashes_** if
   multi-word.

```
[click on this link](#my-multi-word-header)

### My Multi Word Header
```

> ### HACK: Referencing Empty Div

- [Chapter 1](#Chapter1)
- [Chapter 2](#Chapter2)

```md
-  [Chapter 1](#Chapter1)
-  [Chapter 2](#Chapter2)

<div id="Chapter1"/>
### Chapter 1

Some text here.  
Some text here. Some text here.

<span id="Chapter2"/>
### Chapter 2

Some text here.  
Some text here. Some text here.
```

<div id="Chapter1"/>

#### 3.2.1.1. Chapter 1

Some text here.  
Some text here. Some text here.

<span id="Chapter2"/>

#### 3.2.1.2. Chapter 2

Some text here.  
Some text here. Some text here.

<div id="images"/>

## 3.3. Images

```git
![Tux, the Linux mascot](/assets/images/tux.png)
![Tux, the Linux mascot](https://...)

```

![Tux, the Linux mascot](https://upload.wikimedia.org/wikipedia/commons/3/35/Tux.svg)


###  Aligning images

####  `left` alignment

<img align="left" width="100" height="100" src="http://www.fillmurray.com/100/100">

This is the code you need to align images to the left:
```
<img align="left" width="100" height="100" src="http://www.fillmurray.com/100/100">
```

---

####  `right` alignment

<img align="right" width="100" height="100" src="http://www.fillmurray.com/100/100">

This is the code you need to align images to the right:
```
<img align="right" width="100" height="100" src="http://www.fillmurray.com/100/100">
```

---

####  `center` alignment example

<p align="center">
  <img width="460" height="300" src="http://www.fillmurray.com/460/300">
</p>

```
<p align="center">
  <img width="460" height="300" src="http://www.fillmurray.com/460/300">
</p>
```

<div id="math"/>

## 3.4. Mathematical Formula in markdown

[https://latex.codecogs.com/](https://latex.codecogs.com/)\
[https://www.codecogs.com](https://www.codecogs.com/latex/eqneditor.php)\
[http://www.sciweavers.org/](http://www.sciweavers.org/free-online-latex-equation-editor)

<div id="highlighting"/>

## 3.5. Code and Syntax Highlighting

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

# 4. GIT and GITHUB

## 4.1. Gist

[Gist](https://gist.github.com/dev-SR)

## 4.2. Clear Git Cache

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

### 4.2.1. Clear Entire Git Cache

In some cases, you may want to clear the cache of your entire Git staging area.

This is particularly useful when you added multiple files that you want now to
be ignored via your `.gitignore` file.

**To clear your entire Git cache, use the `"git rm"` command with the `"-r"`
option for recursive.**

1. apply below cmd to un-stage all files:

```properties
 git rm -r --cached .
```

2. add intended file to `.gitignore`
3. then, get all files back simply by :

```properties
 git add .
```

<div id="alias"/>

## 4.3. Git Alias

[gist](https://gist.github.com/dev-SR/bf82b701864366b77b3320b543fbef75)

<div id="githubrepo"/>

## 4.4. Commands for Github Repo

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

<div id="changeremote"/>

## 4.5. Change the URI (URL) for a remote Git repository

```bash
git remote -v
# View existing remotes
# origin  https://github.com/user/repo.git (fetch)
# origin  https://github.com/user/repo.git (push)

git remote set-url origin https://github.com/user/repo2.git
# Change the 'origin' remote's URL

git remote -v
# Verify new remote URL
# origin  https://github.com/user/repo2.git (fetch)
# origin  https://github.com/user/repo2.git (push)

```

# 5. Unicodes

### 5.0.1. LINKS

[Arrows](https://unicode-table.com/en/sets/arrow-symbols/)

[Box Drawing](https://unicode-table.com/en/blocks/box-drawing/)

### 5.0.2. Examples

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
