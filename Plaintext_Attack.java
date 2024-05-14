// Bismillahir Rahmanir Rahim
// Plain-text Attack on RSA

import java.math.BigInteger;

public class Plaintext_Attack {
    static BigInteger power(BigInteger b, BigInteger p, BigInteger mod) {
        b = b.mod(mod);
        if (p.equals(BigInteger.ZERO))
            return BigInteger.ONE;
        BigInteger j = power(b, p.divide(BigInteger.valueOf(2)), mod);
        j = (j.multiply(j)).mod(mod);
        if (p.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
            j = (j.multiply(b)).mod(mod);
        return j;
    }

    public static void main(String[] args) {
        BigInteger e = new BigInteger("10000019");
        BigInteger n = new BigInteger("20000900009");
        BigInteger msg = new BigInteger("20000000000");
        System.out.println("Message: " + msg);
        BigInteger cypher = power(msg, e, n);
        System.out.println("Cypher: " + cypher);

        BigInteger d = new BigInteger("6283524500");
        while (true) {
            BigInteger new_msg = power(cypher, d, n);
            if (new_msg.equals(msg)) {
                System.out.println("New Message: " + new_msg);
                System.out.println("Private key: " + d);
                break;
            }
            d = d.add(BigInteger.ONE);
        }
    }
}
