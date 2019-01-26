package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static int getInt() throws IOException {
        String s = getString();
        return Integer.parseInt(s);
    }

    private static String getString() throws IOException {
        InputStreamReader sir = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(sir);
        String s = br.readLine();
        return s;
    }


    public static void main(String[] args) throws IOException {


    }
}
