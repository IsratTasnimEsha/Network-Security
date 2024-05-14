// Bismillahir Rahmanir Rahim
// ElGamal Digital Signature

import java.math.BigInteger;

public class ElGamal_Digital_Signature {
    public static void main(String[] args) {
        BigInteger p = new BigInteger("23");
        BigInteger alp = new BigInteger("5");
        BigInteger a = new BigInteger("6");
        BigInteger b = new BigInteger("6");
        BigInteger msg = new BigInteger("9");

        BigInteger[] sign = signMsg(msg, p, alp, a);
        BigInteger y1 = sign[0];
        BigInteger y2 = sign[1];
        System.out.println("y1 = " + y1 + "\ny2 = " + y2);

        boolean isValid = verifySign(msg, p, alp, a, b, y1, y2);
        if(isValid) {
            System.err.println("Valid Sign");
        }
        else {
            System.err.println("Invalid Sign");
        }
    }

    public static BigInteger[] signMsg(BigInteger msg, BigInteger p, BigInteger alp, BigInteger a) {
        BigInteger[] sign = new BigInteger[2];
        BigInteger k = new BigInteger("9");       
    
        BigInteger y1 = alp.modPow(k, p);
        BigInteger kInv = k.modInverse(p.subtract(BigInteger.ONE));
        BigInteger y2 = kInv.multiply(msg.subtract(a.multiply(y1))).mod(p.subtract(BigInteger.ONE));
        sign[0] = y1;
        sign[1] = y2;
        return sign;
    }

    public static boolean verifySign(BigInteger msg, BigInteger p, BigInteger alp, BigInteger a, BigInteger b, BigInteger y1, BigInteger y2) {
        BigInteger v1 = b.modPow(y1, p);
        BigInteger v2 = y1.modPow(y2, p);
        BigInteger v = v1.multiply(v2).mod(p);
        BigInteger h = alp.modPow(msg, p);

        return v.equals(h);
    }
}
