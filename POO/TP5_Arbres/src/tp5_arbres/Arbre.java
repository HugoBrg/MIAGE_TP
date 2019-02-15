package tp5_arbres;

import java.util.Random;

/**
 *
 * @author hugob
 */
public class Arbre {
    Noeud root;
    Noeud curr;
    Noeud[] noeudArray;

    Arbre(Noeud racine) {
        this.root = racine;
        this.curr = this.root;
    }
    
    public void ajouterNoeud(Noeud n){
        if(n.getValeur()<this.curr.getValeur()&&this.curr.getFilsG()==null){
            System.out.println("Le noeud ("+curr.getValeur()+") n'a pas de fils gauche, on lui ajoute ("+n.getValeur()+")");
            this.curr.setFilsG(n);
            this.curr=this.root;
        }
        else if(n.getValeur()>this.curr.getValeur()&&this.curr.getFilsD()==null){
            System.out.println("Le noeud ("+curr.getValeur()+") n'a pas de fils droit, on lui ajoute ("+n.getValeur()+")");
            this.curr.setFilsD(n);
            this.curr=this.root;
        }    
        else if(n.getValeur()<this.curr.getValeur()){
            this.curr=curr.getFilsG();
            ajouterNoeud(n);
        }
        else if(n.getValeur()>this.curr.getValeur()){
            this.curr=curr.getFilsD();
            ajouterNoeud(n);
        }
        else if(n.getValeur()==this.curr.getValeur()){
            System.out.println("Cette valeur existe déja");
        }
        else{
            System.out.println("Erreur inconnue");
        }
    }
    
    public void ajouterNoeuds(){
        for(int i=0;i<this.noeudArray.length;i++){
            ajouterNoeud(noeudArray[i]);
        }
    }
    
    public Noeud[] genererNoeud(int n){
        noeudArray = new Noeud[n];
        for(int i=0;i<n;i++){
            Random rand = new Random();
            Noeud noeud = new Noeud(rand.nextInt(50) + 1);
            noeudArray[i]=noeud;                 
        }
        return noeudArray;
    }
    
    public void existe(Noeud n){
        if(n.getValeur()==this.curr.getValeur()){
            System.out.println("Ce noeud existe");
        }else if(n.getValeur()<this.curr.getValeur() && this.curr.getFilsG()!=null){
            this.curr=this.curr.getFilsG();
            existe(n);
        }else if(n.getValeur()>this.curr.getValeur() && this.curr.getFilsD()!=null){
            this.curr=this.curr.getFilsD();
            existe(n);
        }
        else{
            System.out.println("Ce noeud n'existe pas");
        }
    }
    
    public void parcourirPrefixe(){
	System.out.println(this.root.getValeur());
	if (this.root.getFilsG() != null){
            Arbre a1 = new Arbre(this.root.getFilsG());
            a1.parcourirPrefixe();
        }
	if (this.root.getFilsD() != null){
	    Arbre a2 = new Arbre(this.root.getFilsD());
            a2.parcourirPrefixe();
        }
    }
    
    public void parcourirInfixe(){
        if (this.root.getFilsG() != null){
            Arbre a1 = new Arbre(this.root.getFilsG());
            a1.parcourirInfixe();
        }
        System.out.println(this.root.getValeur());
	if (this.root.getFilsD() != null){
	    Arbre a2 = new Arbre(this.root.getFilsD());
            a2.parcourirInfixe();
        }
    }
    
    public void parcourirPostfixe(){
        if (this.root.getFilsG() != null){
            Arbre a1 = new Arbre(this.root.getFilsG());
            a1.parcourirPostfixe();
        }
	if (this.root.getFilsD() != null){
	    Arbre a2 = new Arbre(this.root.getFilsD());
            a2.parcourirPostfixe();
        }
        System.out.println(this.root.getValeur());
    }
  
}
