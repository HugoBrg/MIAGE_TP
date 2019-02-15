/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp2;

/**
 *
 * @author hugob
 */
public class Polynome {
    private int a,b,c;
    private double x,d,r1,r2;

    Polynome(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    public double calculer(double x){
        double r;
        r=a*Math.pow(x,2)+b*x+c;
        return r;
    }
    
    public void discriminant(Polynome p){
        d=(Math.pow(b,2))-4*(p.a)*(p.c);
        System.out.println("Discriminant : "+d);
    }
    
    public void racines (Polynome p){
        double r;
        if(d<0)
            System.out.println("Racine complexe 1 : "+racineComplexe1(p)+"\nRacine complexe 2 : "+racineComplexe2(p));
        else if(d>0)
            System.out.println("Racine réelle 1 : "+racineReelle1(p)+"\nRacine réelle 2 : "+racineReelle2(p));
        else if(d==0)
            System.out.println("Racines : "+(-(p.b)/2*(p.a)));
        else
            System.out.println("Erreur");
            
    }
    public double racineReelle1 (Polynome p){
        double r;
        r=-((p.b)-Math.sqrt(p.d))/2*(p.a);
        return r;
    }
    
    public double racineReelle2 (Polynome p){
        double r;
        r=-((p.b)+Math.sqrt(p.d))/2*(p.a);
        return r;
    }
    
    public String racineComplexe1 (Polynome p){
        String r;
        Complexe c1 = new Complexe((p.b),(p.d));
        r=-c1.reelle+"-i√"+c1.imaginaire+"/"+2*(p.a);
        return r;
    }
    
    public String racineComplexe2 (Polynome p){
        String r;
        Complexe c2 = new Complexe((p.b),(p.d));
        r=-c2.reelle+"+i√"+c2.imaginaire+"/"+2*(p.a);
        return r;
    }
}
