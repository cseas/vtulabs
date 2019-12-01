/* 11. Write a program for simple RSA algorithm to encrypt and decrypt the data.
   Created by Abhijeet Singh
 */
import java.io.DataInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.BitSet;
import java.util.Random;
public class Rsa {
    private BigInteger p;
    private BigInteger q;

    private BigInteger n;
    private BigInteger phi;

    private BigInteger e;
    private BigInteger d;

    private int bit_length = 1024;
    private Random r;

    public Rsa() {
        r = new Random();

        p = BigInteger.probablePrime(bit_length, r);
        q = BigInteger.probablePrime(bit_length, r);

//        n is not used anywhere in this constructor
        n = p.multiply(q);
        phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));

        e = BigInteger.probablePrime(bit_length/2, r);

        while(e.gcd(phi).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0) {
            e.add(BigInteger.ONE);
        }

        d = e.modInverse(phi);
    }

    public Rsa(BigInteger e, BigInteger d, BigInteger n) {
        this.e = e;
        this.d = d;
        this.n = n;
    }

    private static String bytesToString(byte[] encrypted) {
        String test = "";
        for(byte b:encrypted)
            test += Byte.toString(b);
        return test;
    }

    public byte[] encrypt(byte[] message) {
        return (new BigInteger(message)).modPow(e, n).toByteArray();
    }

    public byte[] decrypt(byte[] message) {
        return (new BigInteger(message)).modPow(d, n).toByteArray();
    }

    public static void main(String[] args) throws IOException {
        Rsa rsa = new Rsa();

        DataInputStream in = new DataInputStream(System.in);
        String teststring;

        System.out.println("Enter plain text:");
        teststring = in.readLine();

        System.out.println("Encrypting string: " + teststring);
        System.out.println("String in bytes: " + bytesToString(teststring.getBytes()));

        byte[] encrypted = rsa.encrypt(teststring.getBytes());
        byte[] decrypted = rsa.decrypt(encrypted);

        System.out.println("Encrypted value: " + encrypted);
        System.out.println("Decrypted bytes: " + bytesToString(decrypted));
        System.out.println("Decrypted string: " + new String(decrypted));
    }
}
