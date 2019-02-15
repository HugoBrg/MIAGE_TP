package tp5_arbres;

import java.util.Random;

/**
 *
 * @author hugob
 */
public class Noeud {
    private int valeur;
    private Noeud filsG;
    private Noeud filsD;

    public Noeud(int valeur) {
        this.valeur = valeur;
    }

    /*public Noeud(int valeur, Noeud filsG, Noeud filsD) {
        this.valeur = valeur;
        if(filsG.getValeur()>filsD.getValeur()){
            System.out.println("Le fils de gauche ne peut-être supérieur au fils de droite");
        }else{
            this.filsG = filsG;
            this.filsD = filsD;    
        }
    }*/

    public int getValeur() {
        return valeur;
    }

    public Noeud getFilsG() {
        return filsG;
    }

    public Noeud getFilsD() {
        return filsD;
    }

    /*public void setFilsG(Noeud filsG) {
        if(filsG.getValeur()>this.filsD.getValeur()){
            System.out.println("Le fils de gauche ne peut-être supérieur au fils de droite");
        }else{
            this.filsG = filsG;
        }
    }

    public void setFilsD(Noeud filsD) {
        if(filsD.getValeur()<this.filsG.getValeur()){
            System.out.println("Le fils de droite ne peut être inferieur au fils de gauche");
        }else{
            this.filsD = filsD;
        }
    }*/

    public void setFilsG(Noeud filsG) {
        this.filsG = filsG;
    }

    public void setFilsD(Noeud filsD) {
        this.filsD = filsD;
    }
    
    public String toString() {
        String str = "Valeur du noeud : "+this.valeur;
        if(this.filsG!=null){
             str +=" | Fils gauche : "+this.filsG.getValeur();
        }
        if(this.filsD!=null){
             str +=" | Fils droit : "+this.filsD.getValeur();
        } 
        return str;
    }
}
