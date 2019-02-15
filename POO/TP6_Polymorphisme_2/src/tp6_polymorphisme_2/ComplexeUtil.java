package tp6_polymorphisme_2;

/**
 *
 * @author hugob
 */
public class ComplexeUtil {
    
    /****************************************************égalité****************************************************/
    private static boolean egale(IComplexe c_1, IComplexe c_2){
        return (c_1.imaginaire()==c_2.imaginaire()&&c_1.reelle()==c_2.reelle());
    }
    
    /****************************************************addition****************************************************/
    private static IComplexe addition(IComplexe c_1, IComplexe c_2) {
        return new ComplexeCartesien(c_1.reelle() + c_2.reelle(), c_1.imaginaire() + c_2.imaginaire());
    }
    
    /****************************************************égalité****************************************************/
    private static IComplexe soustraction(IComplexe c_1,IComplexe c_2) {
        return new ComplexeCartesien(c_1.reelle() - c_2.reelle(), c_1.imaginaire() - c_2.imaginaire());
    }
    
    /****************************************************multiplication****************************************************/
    private static IComplexe multiplication(IComplexe c_1, IComplexe c_2) {
	return new ComplexeCartesien((c_1.reelle()*c_2.reelle()) - (c_1.imaginaire()*c_2.imaginaire()), (c_1.reelle()*c_2.imaginaire()) + (c_1.imaginaire()*c_2.reelle()));
    }
    
    /****************************************************division****************************************************/
    private static IComplexe division(IComplexe c_1, IComplexe c_2){
	return new ComplexeCartesien(
                (c_1.reelle()*c_2.reelle() - c_1.imaginaire()*c_2.imaginaire())/(c_2.reelle()*c_2.reelle() + c_2.imaginaire()*c_2.imaginaire()), 
                (c_1.reelle()*c_2.reelle() + c_2.imaginaire()*c_1.imaginaire())/(c_2.reelle()*c_2.reelle() + c_2.imaginaire()*c_2.imaginaire()));
    }
    
    /****************************************************toPolaire****************************************************/
    private static ComplexePolaire toPolaire(IComplexe c_1){
        return new ComplexePolaire(c_1.imaginaire(),c_1.reelle());
    }
    
    /****************************************************toCartesien****************************************************/
    private static ComplexeCartesien toCartesien(IComplexe c_1){
        return new ComplexeCartesien(c_1.imaginaire(),c_1.reelle());
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        IComplexe cc_1 = new ComplexeCartesien(1, -1);
        IComplexe cc_2 = new ComplexeCartesien(2, -1);
        IComplexe cp_1 = new ComplexePolaire(1, -2);
        IComplexe cp_2 = new ComplexePolaire(2, -2);
 
        System.out.println(egale(cc_1,cc_1));
        System.out.println(egale(cc_1,cc_2));
        
        IComplexe c_1 = addition(cc_1,cc_2);
        System.out.println(c_1);
        
        IComplexe c_2 = soustraction(cc_1,cc_2);
        System.out.println(c_2);
        
        IComplexe c_3 = multiplication(cc_1,cc_2);
        System.out.println(c_3);
        
        IComplexe c_4 = division(cc_1,cc_2);
        System.out.println(c_4);
        
        ComplexeCartesien cc_3 = toCartesien(c_1);
        ComplexePolaire cp_3 = toPolaire(cc_3);
    }
}