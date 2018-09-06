package com.example.cike.curl_jni_demo;

/**
 * Created by cike on 9/6/18.
 */

public class NativeClass {
    static {
        System.loadLibrary("curl");
        System.loadLibrary("mylib");
    }

    public static native int curlGet(String urlString);
}

