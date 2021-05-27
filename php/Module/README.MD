#### PHP provides two constructs to load code and HTML from another module:
* ### require and include.

```
The main difference is that attempting to 'require' a nonexistent file is a fatal error, while attempting to
'include' such a file produces a warning but does not stop script
execution.
```
* A common use of include is to separate page-specific content from
general site design. Common elements such as headers and footers go
in separate HTML files, and each page then looks like:
  
```
<?php include "header.html"; ?>
content
<?php include "footer.html"; ?>
```
* We use include because it allows PHP to continue to process the
page even if there’s an error in the site design file(s). The require
construct is less forgiving and is more suited to loading code libraries,
where the page cannot be displayed if the libraries do not load. For
example:

```
require "codelib.php";
mysub(); // defined in codelib.php
```

### Documenting Classes with PHPDoc 
PHPDoc has a special inline documentation style. By formatting your comments in a particular way, the PHPDoc script can parse your code to not only generate which parameters a function take and what type of variable it returns, but also associate comments and other useful information with objects, functions, and variables. PHPDoc comments are based on the same formatting and naming conventions as Javadoc. So, to flag a comment block to grab PHPDoc's attention, use a traditional C-style comment but use two asterisks after the opening slash: 
```
/** 
* This is a PHPDoc comment block 
*/
```
| KeyWord       | Meaning        | 
| ------------- |:-------------:| 
| @access    | Method access: public or private | 
| @param    | Function parameter |  
| @return    | Function return value |  
| @var | Object variable | 
 