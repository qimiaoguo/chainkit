package com;

public class SignatureJNI {
    static {
        System.loadLibrary("signaturejni"); // Load native library at runtime
        // hello.dll (Windows) or libhello.so (Unixes)
    }

    // Declare a native method sayHello() that receives nothing and returns void
    public native String sign(String hash, String privateKey);
    public native boolean verify(String hash, String sig, String publicKey);

    public static void main(String[] args) {
        SignatureJNI signatureJNI = new SignatureJNI();
        String x = signatureJNI.sign("1111111111111111111111111111111111111111111111111111111111111111", "5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3");
        System.out.println(x);
        System.out.println(System.currentTimeMillis());

        for (int i =0; i < 10000; i++) {

//            boolean m = signatureJNI.verify("1111111111111111111111111111111111111111111111111111111111111111", "SIG_K1_JySxLBnL5YbZCXDYXFUvqfsG58ckZ1TqTARzxVTTH6ELC1kfYM6Fvu5ii7ujeHCxVsGQjq8NbFReF5jK9XaftyN8NyJviu", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV");
//            boolean y = signatureJNI.verify("17cc523c8f5550ea172a5254221d99576249d91b61dedecdf49b4827c7896fbf", "SIG_K1_K8NfvdLS27vS8ZkZXd2EdxHJx4quEiRRpXWHmZM9MTvUGDhdTYDzVsAcgdzY1XAyuBahRNaDd9qiMyoFTa3RxJ8fkQzFNH", "EOS7u75TG5tYGreQctWVtvVLuHvMkPXr9i8qDY3xgVB8GzWqoGLHK");
            boolean z = signatureJNI.verify("7af85099ef7ed2ceb9a70f50db54f426f227203797bc95844aff6c1112733434", "SIG_K1_KcF1Nx3krkpsvEgHjfPxeTuxZvijoxBqdQjQ2r9Lo2NqWsyA3NM8aQZLQWX5HukZxsGUPC2pdAXmmMbnfa1rtGZZ6sQXQD", "EOS7ofXJ6D1H1QYDYKyGR576tJ21t42TxkWrKwZTBUBKwbiF3HUGz");
//            System.out.println(m);
//            System.out.println(y);
//            System.out.println(z);
        }
        System.out.println(System.currentTimeMillis());
    }

}