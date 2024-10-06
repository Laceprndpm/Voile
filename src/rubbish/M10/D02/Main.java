package M10.D02;

// import javax.swing.JFrame;
// import javax.swing.ImageIcon;

// import java.io.File;
// import java.io.IOException;
// import java.util.Scanner;
// import javax.sound.sampled.*;

public class Main {
    public static void main(String[] args) {

    }
}
// // int m = Math.abs(-2147483648);
// // System.err.println(m);
// double[] a = new double[10];
// String string = new String();
// System.err.println(a[0]);
// System.err.println(string);
// JFrame frame = new JFrame();
// frame.setTitle("JFrame title is HERE!");
// frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
// frame.setSize(420, 420);
// frame.setResizable(false);
// frame.setVisible(true);

// ImageIcon image = new ImageIcon("src\\M10\\D02\\patchouli.jpg");
// frame.setIconImage(image.getImage());
// Scanner scanner = new Scanner(System.in);

// File file = new File("src\\M10\\D02\\marisa.wav");
// AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);
// Clip clip = AudioSystem.getClip();
// clip.open(audioStream);

// String response = "";

// while (!response.equals("Q")) {
// System.out.println("P = play, S = Stop, R = Reset, Q = Quit");
// System.out.print("Enter your choice: ");

// response = scanner.next();
// response = response.toUpperCase();

// switch (response) {
// case ("P"):
// clip.start();
// break;
// case ("S"):
// clip.stop();
// break;
// case ("R"):
// clip.setMicrosecondPosition(0);
// break;
// case ("Q"):
// clip.close();
// break;
// default:
// System.out.println("Not a valid response");
// }

// }
// System.out.println("Byeeee!");
// }

// import java.io.File;
// import java.io.IOException;
// import java.util.Scanner;

// import javax.sound.sampled.AudioInputStream;
// import javax.sound.sampled.AudioSystem;
// import javax.sound.sampled.Clip;
// import javax.sound.sampled.LineUnavailableException;
// import javax.sound.sampled.UnsupportedAudioFileException;
// import javax.sound.sampled.spi.AudioFileReader;

// public class Main {
// public static void main(String[] args) throws UnsupportedAudioFileException,
// IOException, LineUnavailableException {

// Scanner scanner = new Scanner(System.in);
// File file = new File("src\\M10\\D02\\marisa.wav");
// AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);
// Clip clip = AudioSystem.getClip();
// clip.open(audioStream);

// clip.start();

// String response = scanner.next();
// }
// }
// import java.io.File;
// import java.io.FileNotFoundException;
// import java.io.FileReader;
// import java.io.IOException;

// public class Main {
// public static void main(String[] args) {

// // A.n_print();
// // Asub asub = new Asub();
// // asub.print();

// // Animal animal;
// // Scanner scanner = new Scanner(System.in);

// // try{
// // int a = 2/0;
// // System.err.println(a);
// // }
// // catch(Exception e){

// // }

// // while (true) {
// // System.err.println("h");
// // }

// try {
// FileReader file = new FileReader("src\\M10\\D02\\new.txt");
// int data;
// while ((data = file.read()) != (-1)) {
// System.out.print((char) data);
// }
// file.close();
// }
// catch(FileNotFoundException e){
// System.out.println("null");
// }
// catch (IOException e) {
// file.close();
// e.printStackTrace();
// }
// finally {
// }

// }
// }

// import java.io.FileReader;
// import java.io.FileNotFoundException;
// import java.io.IOException;

// public class Main {
// public static void main(String[] args) {
// FileReader file = null;
// try {
// file = new FileReader("src\\M10\\D02\\new.txt");
// int data;
// while ((data = file.read()) != -1) {
// System.out.print((char) data);
// }
// }
// catch (FileNotFoundException e) {
// System.out.println("文件未找到: " + e.getMessage());
// }
// catch (IOException e) {
// System.out.println("读取文件时发生错误: " + e.getMessage());
// }
// finally {
// if (file != null) {
// try {
// file.close();
// } catch (IOException e) {
// System.out.println("关闭文件时发生错误: " + e.getMessage());
// }
// }
// }
// }
// }
