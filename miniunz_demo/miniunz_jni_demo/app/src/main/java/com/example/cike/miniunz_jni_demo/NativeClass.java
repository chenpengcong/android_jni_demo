package com.example.cike.miniunz_jni_demo;

/**
 * Created by cike on 9/6/18.
 */

public class NativeClass {
    static {
        System.loadLibrary("mylib");
    }

    public static native void unzip(String zipFileName, String unzipDstDir);
}
