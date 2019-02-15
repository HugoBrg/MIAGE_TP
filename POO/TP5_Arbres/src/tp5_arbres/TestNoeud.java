package tp5_arbres;
/**
 *
 * @author hugob
 */
public class TestNoeud {
    TestNoeud(int value,int filsG,int filsD){
        Noeud filsGauche = new Noeud(filsG);
        Noeud filsDroit = new Noeud(filsD);
        Noeud n1 = new Noeud(value);
        Noeud n2 = new Noeud(value);
        n2.setFilsG(filsGauche);
        n2.setFilsD(filsDroit);

        System.out.println("Fils gauche getter : "+n2.getFilsG()+" Fils droit getter : "+n2.getFilsD());
        
        
        System.out.println(n1.toString());
        System.out.println(n2.toString());
    }
}
