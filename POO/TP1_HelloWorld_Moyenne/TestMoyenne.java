	public class TestMoyenne {
		public static void main (String[] args){
        	Moyenne m1 = new Moyenne(); 
        	m1.ajouteNote(18,2);
        	m1.ajouteNote(16,1);
        	m1.ajouteNote(19,3);
        	m1.ajouteNote(8,3);
        	System.out.println(m1.calculMoyenne());
        	System.out.println(m1.meilleurNote());
      	}
    }  