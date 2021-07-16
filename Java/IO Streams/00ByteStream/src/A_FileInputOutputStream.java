import java.io.*;

public class A_FileInputOutputStream {
    public static void main(String[] args) {
        InputStream fis = null;
        OutputStream fos = null;
        try {
            // Streams
            fis = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\input.txt");
            fos = new FileOutputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\output.txt");
            int b;
            //read and write byte by byte
            while ((b = fis.read()) != -1) {//read and store in `b`
                fos.write(b);//write from `b`
            }
            System.out.println("IO operation done!!");
            fis.close();
            fos.close();
        }catch (Exception e){
            return;
        }
    }
}
