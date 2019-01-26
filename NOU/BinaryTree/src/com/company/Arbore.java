package com.company;

public class Arbore {
    private Nod radacina; // primul nod al arborelui

    public Arbore(){
        radacina = null;
    }

    public Nod cauta( int n){
        Nod current = radacina;
        if(current == null) return null;

        while (current.valoare != n){
            if(n < current.valoare){
                current = current.st;
            } else {
                current = current.dr;
            }
            if(current == null){
                return null;
            }
        }
        return current;
    }

    // inserare nod nou
    public void insereaza(int n){
        Nod nou = new Nod();
        nou.valoare = n;

        if(radacina == null){
            radacina = nou;
        } else {
            Nod current = radacina;
            Nod parinte;
            while (true){
                parinte = current;
                if(n < current.valoare ){
                    current = current.st;
                    if(current == null){
                        parinte.st = nou;
                        return;
                    }
                } else {
                    current = current.dr;
                    if(current == null ){
                        parinte.dr = nou;
                        return;
                    }
                }

            }
        }
    }

    public boolean stergere(int n){
        Nod current = radacina;
        Nod parinte = radacina;
        boolean t = true;
        while (current.valoare != n){
            parinte = current;
            if(n < current.valoare){
                t = true;
                current = current.st;
            } else {
                t = false;
                current = current.dr;
            }
            if(current == null ) return false;
        }

        if( current.st == null  && current.dr == null){
            if(current == radacina) {
                radacina = null;
            } else {
                if(t) parinte.st = null;
                else
                    parinte.dr = null;
            }
        } else {
            if(current.dr == null){
                if( current == radacina) {
                    radacina= current.st;
                } else {
                 if(t) parinte.st = current.st;
                    else parinte.dr = current.dr;
                }
            } else {
                if(current.st == null){
                    if(current == radacina){
                        radacina = current.dr
                    } else {
                        if(t) parinte.st = current.dr;
                        else parinte.dr = current.dr;
                    }
                } else  {
                    Nod succesor = cautaSuccesor(current);
                    if(current == radacina){
                        radacina = succesor;
                    } else {
                        if( t) parinte.st = succesor;
                        else parinte.dr = succesor;
                    }
                    succesor.st = current.st;
                }
                return true;
            }
        }
    }
}
