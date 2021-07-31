package B_webserver_using_socket;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class WebServer {
    public static final int DEFAULT_WEB_SERVER_PORT = 6666;
    private int webServerPort = DEFAULT_WEB_SERVER_PORT;
    private int webServerRequestCount = 0;
    private ServerSocket webServerSocket;

    public WebServer(int webServerPort) {
        this.webServerPort = webServerPort;
        this.webServerRequestCount = 0;
    }

    /**
     * Start the web server
     */
    protected void start() {

        log("Starting web server........\nVisit: http://localhost:" + webServerPort);

        try {
            //Web server socket creation
            webServerSocket = new ServerSocket(webServerPort);
            log("Started web server on port : " + webServerPort);

            /**
             * Wait for clients
             */
            listen();

        } catch (Exception e) {
            hault("Error: " + e);
        }
    }

    /**
     * Listening on webServerPort for the clients to connect.
     */
    protected void listen() {
        log("Waiting for connection");
        while (true) {
            try {
                // Got a connection request from client
                Socket client = webServerSocket.accept();
                webServerRequestCount ++;

                //Handle client request
                //This processing can be in a separate Thread
                //if we would like to handle multiple requests
                //in parallel.
                serveClient(client);

            } catch (Exception e) {
                log("Error: " + e);
            }
        }
    }

    protected void serveClient(Socket client) throws IOException {

        /**
         * Read the client request (parse the data if required)
         */
        readClientRequest(client);

        /**
         * Send the response back to the client.
         */
        writeClientResponse(client);
    }

    protected void readClientRequest(Socket client) throws IOException {

        log("\n--- Request from : " + client + " ---");

        /**
         * Read the data sent by client.
         */
        BufferedReader in = new BufferedReader(
                new InputStreamReader(client.getInputStream()));

        // read the data sent. We basically ignore it,
        // stop reading once a blank line is hit. This
        // blank line signals the end of the client HTTP
        // headers.
        String str = ".";
        while (!str.equals("")) {
            str = in.readLine();
            log(str);
        }
    }

    protected void writeClientResponse(Socket client) throws IOException {
        // Send the response
        PrintWriter out = new PrintWriter(client.getOutputStream());
        // Send the headers
        out.println("HTTP/1.0 200 OK");
        out.println("Content-Type: text/html");
        out.println("Server: SimpleWebServer");
        // this blank line signals the end of the headers
        out.println("");
        // HTML page
//        out.println("<CENTER>");
//        out.println("<H1 style='color:red'>Welcome to SimpleWebServer<H1>");
//        out.println("<H2>This page has been visited <span style='color:blue'>" +
//                webServerRequestCount + " time(s)</span></H2>");
//        out.println("</CENTER>");
        String html = ReadHtmlFile();
        out.println(html);
        out.flush();
        client.close();

        /**
        * ✖✖✖ Doesn't works with  DataOutputStream)
        * DataOutputStream out = new DataOutputStream(client.getOutputStream());
        * .... because of byte level stream???
        * */

/** With BufferedWriter */

//        BufferedWriter out = new BufferedWriter(new PrintWriter(client.getOutputStream()));
//        out.write("HTTP/1.0 200 OK");
//        out.newLine();
//        out.write("Content-Type: text/html");
//        out.newLine();
//        out.write("Server: SimpleWebServer");
//        out.newLine();
//        out.write("");
//        out.newLine();
//        out.write("<CENTER>");
//        out.write("<H1 style='color:red'>Welcome to SimpleWebServer<H1>");
//        out.write("<H2>This page has been visited <span style='color:blue'>" +
//                webServerRequestCount + " time(s)</span></H2>");
//        out.write("</CENTER>");
//        out.flush();
//        client.close();
    }

    private static void log(String msg) {
        System.out.println(msg);
    }

    private static void hault(String msg) {
        System.out.println(msg);
        System.exit(0);
    }

    public static String ReadHtmlFile(){
        BufferedReader br = null;
        StringBuilder stringBuilder = new StringBuilder();
        try {
            String strLine;
            br = new BufferedReader(new FileReader("D:\\CSE\\Others\\Codes\\Java\\Web\\01Socket\\src\\B_webserver_using_socket\\index.html"));
            while ((strLine = br.readLine()) != null) {
                stringBuilder.append(strLine);
            }
        } catch (IOException ioExp) {
            System.out.println("Error while reading file " + ioExp.getMessage());
        }
        return stringBuilder.toString();
    }

    public static void main(String args[]) {
        /**
         * Start web server on port '8888'
         */
        WebServer ws = new WebServer(8888);
        ws.start();
    }
}
