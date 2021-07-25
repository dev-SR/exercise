# String IO Conversions

## Convert InputStream into a String

Needless to say, an `InputStream` can store any data and in some cases, they store String contents as a `byte` stream. An to read from that byte Stream we need `OutputStream` classes

<div align="center">
<img src="../../img/Java_Stream_Readers_BufferedReaders.jpg" alt="stream" width="700px">
</div

```java

    /*

   * OP 1: convert InputStream directly into byte array, then convert to string using
        new String(byte b[])
        
       ┏━━━━━━━━━━━━━━┓      ┏━━━━━━━━━━━━━━┓      ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃ InputStream  ┃----> ┃ new byte[]   ┃----> ┃ String(byte b[])   ┃
       ┗━━━━━━━━━━━━━━┛      ┗━━━━━━━━━━━━━━┛      ┗━━━━━━━━━━━━━━━━━━━━┛
      But straight-forward way print garbage byte stream 
    
    * OP 2: read from InputStream using OutputStream , then convert to string using
        
       ┏━━━━━━━━━━━━━━┓      ┏━━━━━━━━━━━━━━┓      ┏━━━━━━━━━┓
       ┃ InputStream  ┃----> ┃ OutputStream ┃----> ┃ String  ┃
       ┗━━━━━━━━━━━━━━┛      ┗━━━━━━━━━━━━━━┛      ┗━━━━━━━━━┛

    * OP 2: read from InputStream using Reader , then convert to string using
        
       ┏━━━━━━━━━━━━━━┓      ┏━━━━━━━━━┓      ┏━━━━━━━━┓
       ┃ InputStream  ┃----> ┃ Reader  ┃----> ┃ String ┃
       ┗━━━━━━━━━━━━━━┛      ┗━━━━━━━━━┛      ┗━━━━━━━━┛



    */
```
