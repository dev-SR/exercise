# Quick Navigation

-  Markdown Guides
   -  [Cheatsheets](#Cheatsheet)
   -  [Links](#links)
-  Git and Github
   -  [.gitignore commited files](#Clear-Git-Cache:).

## Markdown Guide

---

### Cheatsheets

> [Cheatsheet-1](https://www.markdownguide.org/basic-syntax/)

> [Cheatsheet-1](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

### Links

```
[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](../blob/master/LICENSE)

```

[I'm an inline-style link](https://www.google.com)

[I'm a relative reference to a repository file](C++/0string)

#### **Anchor to a heading in github flavored markdown**

---

Github automatically parses anchor tags out of your headers. So you can do the
following:

```
[Go to foo](#foo)
```

[Go to foo](#foo)

```
# Foo
```

# Foo

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

## Clear Git Cache:

[Ref](https://devconnected.com/how-to-clear-git-cache/)

---

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
