package M10.D05.socket;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String serverAddress = "127.0.0.1"; // 服务器地址
        int port = 12345; // 服务器端口

        try (Socket socket = new Socket(serverAddress, port);
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {

            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            String userMessage;

            // 从用户输入发送消息
            while ((userMessage = userInput.readLine()) != null) {
                out.println(userMessage); // 发送消息
                System.out.println("Server response: " + in.readLine()); // 接收响应
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
