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

        quicksort(v, 0 , n);
        
        System.out.println(" ");
        System.out.println("Vectorul sortat este:");
        for(i=0; i < n;i++){
            System.out.println(v[i]+ " ");
        }
        System.out.println(" ");

    }

    private static void quicksort(int[] v, int st, int dr) {
        int index = partitionare(v, st, dr);
        if(st < index -1){
            quicksort(v, st, index-1);
        } else {
            quicksort(v, index, dr);
        }
    }

    private static int partitionare(int[] v, int st, int dr) {
        int i=st, j=dr;
        int tmp;
        int pivot = v[(st + dr ) / 2];

        while( i <= j){
            while(v[i] < pivot){
                i++;
            }
            while(v[j] > pivot){
                j--;
            }
            if(i<=j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++;
                j--;
            }
        }

        return i;
    }
}
