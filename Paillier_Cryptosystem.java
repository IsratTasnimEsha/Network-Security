// Bismillahir Rahmanir Rahim

import java.math.BigInteger;
import java.security.SecureRandom;

public class Paillier_Cryptosystem {
    private static SecureRandom random = new SecureRandom();

    public static BigInteger getRandom(BigInteger n) {
        BigInteger r;
        do {
            r = new BigInteger(n.bitLength(), random);
        } while (r.compareTo(n) >= 0 || r.compareTo(BigInteger.ONE) <= 0);
        return r;
    }

    public static BigInteger gcdExtended(BigInteger num1, BigInteger num2, BigInteger[] resultX, BigInteger[] resultY) {
        if (num1.equals(BigInteger.ZERO)) {
            resultX[0] = BigInteger.ZERO;
            resultY[0] = BigInteger.ONE;
            return num2;
        }
        BigInteger[] tempX = new BigInteger[1];
        BigInteger[] tempY = new BigInteger[1];
        BigInteger gcd = gcdExtended(num2.mod(num1), num1, tempX, tempY);
        resultX[0] = tempY[0].subtract(num2.divide(num1).multiply(tempX[0]));
        resultY[0] = tempX[0];
        return gcd;
    }

    public static BigInteger power(BigInteger base, BigInteger exponent, BigInteger mod) {
        base = base.mod(mod);
        if (exponent.equals(BigInteger.ZERO))
            return BigInteger.ONE;
        BigInteger result = power(base, exponent.divide(BigInteger.valueOf(2)), mod);
        result = result.multiply(result).mod(mod);
        if (exponent.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
            result = result.multiply(base).mod(mod);
        return result;
    }

    public static BigInteger modInverse(BigInteger num, BigInteger mod) {
        BigInteger originalMod = mod;
        BigInteger y = BigInteger.ZERO, x = BigInteger.ONE;

        if (mod.equals(BigInteger.ONE))
            return BigInteger.ZERO;

        while (num.compareTo(BigInteger.ONE) > 0) {
            BigInteger quotient = num.divide(mod);
            BigInteger temp = mod;

            mod = num.mod(mod);
            num = temp;
            temp = y;

            y = x.subtract(quotient.multiply(y));
            x = temp;
        }

        if (x.compareTo(BigInteger.ZERO) < 0)
            x = x.add(originalMod);

        return x;
    }

    public static void keyGeneration(BigInteger p, BigInteger q, BigInteger[] keys) {
        BigInteger n, g, lambda, miu;

        n = p.multiply(q);
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        lambda = phi.divide(gcdExtended(p.subtract(BigInteger.ONE), q.subtract(BigInteger.ONE), new BigInteger[1],
                new BigInteger[1]));

        g = n.add(BigInteger.ONE);

        BigInteger t1 = power(g, lambda, n.multiply(n));
        t1 = t1.subtract(BigInteger.ONE).divide(n);
        miu = modInverse(t1, n);

        System.out.println("\nPublic Key: \nn: " + n + "\ng: " + g + "\n");
        System.out.println("Private Key: \nlamda: " + lambda + "\nmiu: " + miu + "\n");

        keys[0] = n;
        keys[1] = g;
        keys[2] = lambda;
        keys[3] = miu;
    }

    public static BigInteger encryption(BigInteger plaintext, BigInteger generator, BigInteger modulus) {
        BigInteger random;
        do {
            random = getRandom(modulus);
        } while (!random.gcd(modulus).equals(BigInteger.ONE));

        BigInteger t1 = power(generator, plaintext, modulus.multiply(modulus));
        BigInteger t2 = power(random, modulus, modulus.multiply(modulus));
        BigInteger ciphertext = t1.multiply(t2).mod(modulus.multiply(modulus));
        System.out.println("Encrypted Message: \n" + ciphertext + "\n");
        return ciphertext;
    }

    public static BigInteger decryption(BigInteger ciphertext, BigInteger lambda, BigInteger mu, BigInteger modulus) {
        BigInteger t1 = power(ciphertext, lambda, modulus.multiply(modulus));
        t1 = t1.subtract(BigInteger.ONE).divide(modulus);

        BigInteger decryptedMessage = t1.multiply(mu).mod(modulus);
        System.out.println("Decrypted Message: \n" + decryptedMessage + "\n");
        return decryptedMessage;
    }

    public static void main(String[] args) {
        BigInteger p = new BigInteger(
                "900427525441313613919807524635341311067496661245279930141237869484311329599736957205284273194335447942227618046789702019408997989069382301699804159272410062200053616779196785075354414630333686425866290115829269025426164359550459162564003162830248280886247212202159179345056850469738510894589666645943");
        BigInteger q = new BigInteger(
                "150612702215987464234717836304324283668115216330513976093405143310751124968744254319206640568389813651716796856058406489596205794297933240966834165458996353942433159688549431028547873214882227802072590948279743547213765440370383771248626414356057444717630504686061474746169254592790524056494793714269");

        BigInteger[] keys = new BigInteger[4];
        keyGeneration(p, q, keys);

        BigInteger plainText = new BigInteger("7062450008942386330007732028349371071357549247950752653789682280930663925506885991789400733562195467");
        System.out.println("Plain Text: \n" + plainText + "\n");

        BigInteger encryptedMessage = encryption(plainText, keys[1], keys[0]);
        BigInteger decryptedMessage = decryption(encryptedMessage, keys[2], keys[3], keys[0]);
    }
}