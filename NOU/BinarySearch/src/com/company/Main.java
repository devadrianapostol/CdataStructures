package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        int[] v = new int[100];
        int n, i, caut;
        System.out.println("Dati nr. de elem ale vectorului");
        n = getInt();
        System.out.println("v[0]=");
        v[0] = getInt();

        for(i=1;i < n; i++){
            do{
                System.out.println("v[" + i + "]=");
                v[i] = getInt();
            } while (v[i] < v[i-1]);
        }
        System.out.println("Dati nr. cautat ");
        caut = getInt();

        boolean gasit;
        //cautare binara iterativa
        System.out.println(" ");
        System.out.println("Cautare binara iterativa");
        gasit = caut_bin(caut, v, n);
        if(gasit){
            System.out.println("Am gasit " + caut);
        } else {
            System.out.println("Nu am gasit " + caut);
        }
        //cautare binara recursiva
        System.out.println(" ");
        System.out.println("Cautare binara recursiva");
        gasit = caut_bin_r(caut, v, 0, n-1);
        if(gasit){
            System.out.println("Am gasit " + caut);
        } else {
            System.out.println("Nu am gasit " + caut);
        }
        
    }

    private static boolean caut_bin_r(int caut, int[] v, int st, int dr) {
        int mijloc;
        if(st <= dr){
            mijloc= (st+dr) /2;
            if(v[mijloc] == caut){
                return true;
            } else {
                if(v[mijloc] < caut){
                    return caut_bin_r(caut, v, mijloc+1, dr);
                    //este in jum superioara
                } else {
                    return caut_bin_r(caut, v, 0, mijloc-1);
                    // este in jum inferioara
                }
            }
        } else {
            return false;
        }
    }

    private static boolean caut_bin(int caut, int[] v, int n) {
        boolean rezultat = false;
        int mijloc, st=0, dr=n-1;

        do {
            mijloc = (st + dr ) / 2;
            if(v[mijloc] == caut){
                rezultat = true;
            } else {
                if(v[mijloc] < caut){
                    st = mijloc + 1;
                } else {
                    dr = mijloc - 1;
                }
            }
        } while (st <= dr && rezultat == false);
        return rezultat;
    }

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


}
