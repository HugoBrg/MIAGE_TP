package tp5_arbres;
/**
 *
 * @author hugob
 */
public class TP5_Arbres {
    public static void main(String[] args) {
        //TestNoeud t1 = new TestNoeud(2,4,6);
        
        Noeud n1 = new Noeud(8);
        Arbre a1 = new Arbre(n1);
        
        Noeud n2 = new Noeud(5);
        a1.ajouterNoeud(n2);
        
        Noeud n3 = new Noeud(12);
        a1.ajouterNoeud(n3);
        
        Noeud n4 = new Noeud(16);
        a1.ajouterNoeud(n4);
        
        Noeud n5 = new Noeud(10);
        a1.ajouterNoeud(n5);
        
        Noeud n6 = new Noeud(3);
        a1.ajouterNoeud(n6);
        
        Noeud n7 = new Noeud(13);
        a1.ajouterNoeud(n7);
        
        Noeud n8 = new Noeud(11);
        a1.ajouterNoeud(n8);
        
        Noeud ntest = new Noeud(4);
        
        
        a1.existe(n8);
        a1.existe(ntest);
        
        System.out.println("***Parcours prefixe***");
        a1.parcourirPrefixe();
        System.out.println("***Parcours infixe***");
        a1.parcourirInfixe();
        System.out.println("***Parcours postfixe***");
        a1.parcourirPostfixe();
        
        Noeud n9 = new Noeud(15);
        Arbre a2 = new Arbre(n9);
        
        a2.genererNoeud(10);
        a2.ajouterNoeuds();
        
        System.out.println("***Parcours prefixe***");
        a2.parcourirPrefixe();
        System.out.println("***Parcours infixe***");
        a2.parcourirInfixe();
        System.out.println("***Parcours postfixe***");
        a2.parcourirPostfixe();
    }
}
