// Bismillahir Rahmanir Rahim

import java.math.BigInteger;
import java.security.SecureRandom;

public class Vernam_Cipher {

    public static void main(String[] args) {
        String plaintext = "Hello, World!";
        String key = generateRandomKey(plaintext.length());
        
        System.out.println("Original: " + plaintext);
        
        byte[] encrypted = encrypt(plaintext.getBytes(), key.getBytes());
        System.out.println("Encrypted: " + new String(encrypted));
        
        byte[] decrypted = decrypt(encrypted, key.getBytes());
        System.out.println("Decrypted: " + new String(decrypted));
    }
    
    public static byte[] encrypt(byte[] plaintext, byte[] key) {
        byte[] encrypted = new byte[plaintext.length];
        for (int i = 0; i < plaintext.length; i++) {
            encrypted[i] = (byte) (plaintext[i] ^ key[i % key.length]);
        }
        return encrypted;
    }
    
    public static byte[] decrypt(byte[] encrypted, byte[] key) {
        byte[] decrypted = new byte[encrypted.length];
        for (int i = 0; i < encrypted.length; i++) {
            decrypted[i] = (byte) (encrypted[i] ^ key[i % key.length]);
        }
        return decrypted;
    }
    
    public static String generateRandomKey(int length) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            char randomChar = (char) (Math.random() * 256);
            sb.append(randomChar);
        }
        return sb.toString();
    }
}
