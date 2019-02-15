/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_vecteurs;

/**
 *
 * @author hugob
 */
public class Vecteur {
    private int x;
    private int y;

    public Vecteur(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public void Scalaire(int k){
        this.x=this.x*k;
        this.y=this.y*k;
    }
    public void Scalaire(Vecteur v2){
        this.x=this.x*v2.x;
        this.y=this.y*v2.y;
    }
    public void Transposer(){
        int z = this.x;
        this.x=this.y;
        this.y=z;
    }
    public void Ajouter(Vecteur v2){
        this.x=this.x+v2.x;
        this.y=this.y+v2.y;
    }
    @Override
    public String toString(){
        String r = "x = "+this.x+" | y = "+this.y;
        return r;
    }
}
