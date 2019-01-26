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
        // write your code here
        int[] v;
        v = new int[100];
        int n, i, caut;
        System.out.println("Dati nr de elem ale vectorului");
        n = getInt();
        System.out.println("Dati elem vectorului");
        for(i=0; i < n;i++){
            System.out.println("v[" + i + "]=");
            v[i] = getInt();
        }

        sortare(v,n);
        System.out.println(" ");
        System.out.println("Vectorul sortat este:");
        for(i=0; i < n;i++){
            System.out.println(v[i]+ " ");
        }
        System.out.println(" ");

    }

    private static void sortare(int[] v, int n) {
        int i,j, min, k;
        for(i=0;i <= n; i++){
            min = v[i];
            k = i;
            for(j=i+1;j < n; j++){
                if(v[j] < min){
                    min = v[j];
                    k = j;
                }
            }
            v[k] = v[i];
            v[i] = min;
        }
    }
}
