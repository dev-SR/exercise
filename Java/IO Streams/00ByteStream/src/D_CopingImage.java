import dev.Color;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class D_CopingImage {
    public static void main(String[] args) {
        InputStream fis = null;
        OutputStream fos = null;
        try {
            // Streams
            fis = new FileInputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\img.jpg");
            fos = new FileOutputStream("D:\\CSE\\Others\\Codes\\Java\\IO Streams\\00ByteStream\\src\\img_copied.jpg");
//            int b;
//            //read and write byte by byte
//            while ((b = fis.read()) != -1) {//read and store in `b`
//                fos.write(b);//write from `b`
//            }
            byte b[] = new byte[fis.available()];
            fis.read(b);
            fos.write(b);
            Color.printMsg(Color.GREEN_BRIGHT, "Image Copied");

            fis.close();
            fos.close();
        } catch (Exception e) {
            Color.printMsg(Color.RED_BRIGHT, "failed to copy!!!");
        }
    }
}
