import java.io.*;
class ByteFile implements Serializable {
    private int byte_in_int[] = new int[100000];
    private int amount = 0;
    public ByteFile (String filename) {
        try {
            BufferedInputStream in = new BufferedInputStream(new FileInputStream(filename));
            while ((byte_in_int[amount] = in.read()) != -1){
                amount++;
            }
            in.close();
        } catch (IOException ie) { System.out.print("Error: " + ie); }
    }
    public void write(String filename) {
        try {
            BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream(filename));
            int temp_amount = 0;
            while (temp_amount <= amount){
                out.write(byte_in_int[temp_amount]);
                temp_amount++;
            }
            out.close();
        } catch (IOException ex) { ex.printStackTrace();  }
    }
}
class TextFile implements Serializable {
    private String line[] = new String[100];
    private int amount = 0;
    public TextFile (String filename, int number) {
        try {
            BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter pw = new PrintWriter(new FileOutputStream(filename));
            System.out.println("Bat dau nhap file: ");
            System.out.println("Ket thuc voi THEEND.");
            while (true) {
                line[amount] = kb.readLine();
                if(line[amount].equals("THEEND.")) {
                    line[amount] = null;
                    break;
                }
                else {
                    if (amount != 0) {
                        pw.print("\n");
                        pw.print(line[amount]);
                        pw.flush();
                        amount++;
                    }
                    else {
                        pw.print(line[amount]);
                        pw.flush();
                        amount++;
                    }
                }
            }
            pw.close();
        } catch (IOException ex) { ex.printStackTrace(); }
    }
    public TextFile (String filename) {
        try {
            BufferedReader in = new BufferedReader(new FileReader(filename));
            while ((line[amount] = in.readLine()) != null) {
            //    System.out.println(line[amount]);
                amount++;
            }
            in.close();
        } catch (IOException ex) { ex.printStackTrace(); }
    }
    public void write(String filename) {
        try {
            BufferedWriter out = new BufferedWriter(new FileWriter(filename));
            int temp_amount = 0;
            while (line[temp_amount] != null) {
                if (temp_amount != 0) {
                    out.write("\n");
            	    out.write(line[temp_amount]);
                    temp_amount++;
                }
                else{
                    out.write(line[temp_amount]);
                    temp_amount++;
                }
            }
            out.close();
        } catch (IOException ex) { ex.printStackTrace(); }
    }
}
class Main {
    public static void byteFile() {
        try {
            BufferedInputStream in = new BufferedInputStream(new FileInputStream("test-read.jpg"));
            BufferedOutputStream out = new BufferedOutputStream(new FileOutputStream("test-write.jpg"));
            int ch;
            while ((ch = in.read()) != -1){
                out.write(ch);
            }
            in.close();
            out.close();
        } catch (IOException ex) { ex.printStackTrace(); }
    }
    public static void textFile() {
        try {
            BufferedReader in = new BufferedReader(new FileReader("test-read.txt"));
            BufferedWriter out = new BufferedWriter(new FileWriter("test-write.txt"));
            String line[] = new String[100];
            int index = 0;
            while((line[index] = in.readLine()) != null) {  
                index++;
            }
            index = 0;
            while (line[index] != null) {
                if (index != 0) {
                    out.write("\n");
            	    out.write(line[index]);
                    index++;
                }
                else{
                    out.write(line[index]);
                    index++;
                }
            }
            in.close();
            out.close();
            System.out.println("Ghi file thanh cong");
        } catch (IOException ex) { ex.printStackTrace(); }
    }
    public static void main(String[] args) {
        //byteFile();
        //textFile();
        ByteFile test_byte = new ByteFile("test-read.jpg");
        test_byte.write("test-write.jpg");
        TextFile test_text = new TextFile("test-read.txt");
        test_text.write("test-write.txt");
        //write_Object
        try {
            ObjectOutputStream f = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream("test-read.ser")));
            f.writeObject(test_byte);
            f.flush();
            f.close();
        } catch (IOException e) { e.printStackTrace(); }
        //read_Object
        try {
            ObjectInputStream f = new ObjectInputStream(new BufferedInputStream(new FileInputStream("test-read.ser")));
            ByteFile test_byte2;
            test_byte2 = (ByteFile)f.readObject();
            test_byte2.write("test-write2.jpg");
            f.close();
        } catch (ClassNotFoundException | IOException e) { e.printStackTrace(); }
        //create_text_file
        TextFile test_text_crt = new TextFile("test-crt.txt",1);
    }
}