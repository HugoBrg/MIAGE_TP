/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp3_vecteursgeneralise;

/**
 *
 * @author hugob
 */
public class Vecteur {
    int x;
    int y;
    int z;
    int w;

    int dim;
    int tab[];
    
    public Vecteur(int x, int y, int z, int w) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w;
        this.dim = 4;
    }
    
    public Vecteur(int dim, int tab[]){
        if(dim==4 & tab.length<=dim){
            if(tab.length==0){
                this.x = 0;
                this.y = 0;
                this.z = 0;
                this.w = 0;
            }
            else {
                this.x = tab[0];
                this.y = tab[1];
                this.z = tab[2];
                this.w = tab[3];
            }
            this.dim=dim;
        }
        else if(dim==3 & tab.length<=dim){
            if(tab.length==0){
                this.x = 0;
                this.y = 0;
                this.z = 0;
            }
            else {
                this.x = tab[0];
                this.y = tab[1];
                this.z = tab[2];
            }
            this.dim=dim;
        }
        else{
            System.out.println("La dimension est trop petite ou le tableau n'a pas le même taille que la dimensions");
        }
    }
    
    public void afficher(){
        if(dim==4)
            System.out.println(x+" "+y+" "+z+" "+w);
        else
            System.out.println(x+" "+y+" "+z);
    }
    
}
