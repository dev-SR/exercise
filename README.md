# Quick Navigation

- [Quick Navigation](#quick-navigation)
  - [Vs Code Setting](#vs-code-setting)
    - [font](#font)
    - [snippets](#snippets)
    - [Terminal](#terminal)
      - [For Windows Terminal](#for-windows-terminal)
  - [Markdown Guide](#markdown-guide)
    - [Cheatsheets](#cheatsheets)
    - [Links](#links)
      - [**Anchor to a heading in github flavored markdown**](#anchor-to-a-heading-in-github-flavored-markdown)
        - [Chapter 1](#chapter-1)
        - [Chapter 2](#chapter-2)
    - [Images](#images)
      - [Aligning images](#aligning-images)
        - [`left` alignment](#left-alignment)
        - [`right` alignment](#right-alignment)
        - [`center` alignment example](#center-alignment-example)
    - [Mathematical Formula in markdown](#mathematical-formula-in-markdown)
    - [Code and Syntax Highlighting](#code-and-syntax-highlighting)
  - [GIT and GITHUB](#git-and-github)
    - [Gist](#gist)
    - [Clear Git Cache](#clear-git-cache)
      - [Clear Entire Git Cache](#clear-entire-git-cache)
    - [Git Alias](#git-alias)
    - [Commands for Github Repo](#commands-for-github-repo)
    - [Change the URI (URL) for a remote Git repository](#change-the-uri-url-for-a-remote-git-repository)
  - [Vim](#vim)
    - [Linux(ubuntu)](#linuxubuntu)
  - [Unicodes](#unicodes)
      - [LINKS](#links-1)
      - [Examples](#examples)

## Vs Code Setting

### font

**For Editor:** _`FiraCode-Regular.ttf`_ and _`FiraCode-Bold.ttf`_ from:
[tonsky/FiraCode](https://github.com/tonsky/FiraCode)

**For Terminal:** _`FiraMono NF`_ from
[Nerd Font](https://github.com/tonsky/FiraCode)

### snippets

You can easily define your own snippets without any extension. To create or edit your own snippets,
- select `User Snippets` under `File > Preferences > User Snippets` or `Setting > User Snippets`
- then **select the language**(by typing language identifier) for which the snippets should appear,
  - or type `New Global Snippets` file option if they should appear for all languages.

[https://code.visualstudio.com/docs/editor/userdefinedsnippets](https://code.visualstudio.com/docs/editor/userdefinedsnippets)

- Each snippet is defined under a `snippet name` and has a `scope`, `prefix`, `body` and `description`.
- Add comma separated ids of the languages where the snippet is applicable in the scope field.
  - `"scope": "javascript,typescript"`
- If scope is left empty or omitted, the snippet gets applied to all languages.
- The `prefix` is what is used to **trigger the snippet** and the body will be expanded and inserted.
  - Possible variables are:
    - `$1`, `$2` for tab stops,
    - `$0` for the final cursor position, and
    - `${1:label}`, `${2:another}` for placeholders.
      - Placeholders with the same ids are connected.

```json
{

 "Print to console": {
   "scope": "javascript,typescript",
   "prefix": "log",
   "body": ["for(int i = $1,i<=$2;i++){",
     "    console.log(\"${3:string}\");",
     "    console.log(\"${3:string}\");",
     "}",
     "$0"],
   "description": "Log output to console"
  }

}
```

[https://snippet-generator.app](https://snippet-generator.app/): !!!To declare a placeholder (ctrl + i): ${1:example}

### Terminal

#### For Windows Terminal

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

## Markdown Guide

<div id="cheatsheet"/>

### Cheatsheets

> [Cheatsheet-1](https://www.markdownguide.org/basic-syntax/)

> [Cheatsheet-1](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

<div id="links"/>

### Links

```
[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

```

[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

#### **Anchor to a heading in github flavored markdown**

Github automatically parses anchor tags out of your headers. So you can do the
following:

```
[Go to foo](#foo)
```

[Go to foo](#foo)

```
### Foo
```

> #### Foo

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

> #### HACK: Referencing Empty Div

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

##### Chapter 1

Some text here.
Some text here. Some text here.

<span id="Chapter2"/>

##### Chapter 2

Some text here.
Some text here. Some text here.

<div id="images"/>

### Images

```git
![Tux, the Linux mascot](/assets/images/tux.png)
![Tux, the Linux mascot](https://...)

```

![Tux, the Linux mascot](https://upload.wikimedia.org/wikipedia/commons/3/35/Tux.svg)

#### Aligning images

##### `left` alignment

<img align="left" width="100" height="100" src="http://www.fillmurray.com/100/100">

This is the code you need to align images to the left:

```
<img align="left" width="100" height="100" src="http://www.fillmurray.com/100/100">
```

---

##### `right` alignment

<img align="right" width="100" height="100" src="http://www.fillmurray.com/100/100">

This is the code you need to align images to the right:

```
<img align="right" width="100" height="100" src="http://www.fillmurray.com/100/100">
```

---

##### `center` alignment example

<p align="center">
  <img width="460" height="300" src="http://www.fillmurray.com/460/300">
</p>

```
<p align="center">
  <img width="460" height="300" src="http://www.fillmurray.com/460/300">
</p>
```

<div id="math"/>

### Mathematical Formula in markdown

[https://latex.codecogs.com/](https://latex.codecogs.com/)\
[https://www.codecogs.com](https://www.codecogs.com/latex/eqneditor.php)\
[http://www.sciweavers.org/](http://www.sciweavers.org/free-online-latex-equation-editor)

<div id="highlighting"/>

### Code and Syntax Highlighting

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

## GIT and GITHUB

### Gist

[Gist](https://gist.github.com/dev-SR)

### Clear Git Cache

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

#### Clear Entire Git Cache

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

### Git Alias

[gist](https://gist.github.com/dev-SR/bf82b701864366b77b3320b543fbef75)

<div id="githubrepo"/>

### Commands for Github Repo

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

### Change the URI (URL) for a remote Git repository

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

<div id="vi"></div>

## Vim

### Linux(ubuntu)

Install Vim (Enhanced version of vi which is preinstalled)

```bash

sudo apt install vim

```

Configure .vimrc

```bash
# search if.vimrc exits
ls -a | grep .vim
# open .vimrc
vim .vimrc
```

```vim
inoremap jj <Esc>
syntax on
set number
```

## Unicodes

#### LINKS

[Arrows](https://unicode-table.com/en/sets/arrow-symbols/)

[Box Drawing](https://unicode-table.com/en/blocks/box-drawing/)

#### Examples

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
