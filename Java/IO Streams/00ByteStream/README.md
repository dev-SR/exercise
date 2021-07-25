# ByteStream

## FileInputStream

`FileInputStream` is useful to read data from a file in the form of **sequence of bytes**. `FileInputStream` is meant for reading streams of raw bytes such as **image** data. **For reading streams of characters**, consider using `FileReader`.

## FileOutputStream

`FileOutputStream` is an OutputStream for writing data/streams of **raw bytes** to file or storing data to file. To write primitive values into a file, we use FileOutputStream class. For writing**byte-oriented and character-oriented** data, we can use FileOutputStream but **for writing character-oriented data**, `FileWriter` is more preferred.