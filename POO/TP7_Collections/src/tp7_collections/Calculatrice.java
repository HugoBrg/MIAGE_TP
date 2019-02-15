/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp7_collections;

import java.util.Stack;

/**
 *
 * @author hugob
 */
public class Calculatrice {

    public Calculatrice() {
    }
    
    private boolean estUnEntier(String chaine) {
	try {
            Integer.parseInt(chaine);
	} catch (NumberFormatException e){
            return false;
	} 
        return true;
    }
    
    private void afficherPile(Stack stack){
        System.out.println("Affichage");
        for(int i=0;i<stack.size();i++){
            System.out.println(stack.elementAt(i));
        }
    }
    
    public double calculer(String[] args){
        Stack stack = new Stack();
        stack.push("j");
        for(int i=0;i<args.length;i++){
            System.out.println(args[i]);
            if(estUnEntier(args[i])){
                stack.push(Double.valueOf(args[i]));
            }
            else if(args[i].equals("²")){
                System.out.println("Opérateur unaire");
                stack.push(Math.pow(Double.valueOf(stack.pop().toString()),2));
            }
            else if(args[i].equals("+")|args[i].equals("-")|args[i].equals("*")|args[i].equals("/")){
                switch(args[i]){
                    case "+" :
                        stack.push(Double.valueOf(stack.pop().toString()) + Double.valueOf(stack.pop().toString()));
                    case "-" :
                        stack.push(Double.valueOf(stack.pop().toString()) - Double.valueOf(stack.pop().toString()));
                    case "*" :
                        stack.push(Double.valueOf(stack.pop().toString()) * Double.valueOf(stack.pop().toString()));
                    case "/" :
                        stack.push(Double.valueOf(stack.pop().toString()) / Double.valueOf(stack.pop().toString()));
                    default :
                        System.out.println("Cette operande n'existe pas");                      
                }
            }
            else{
                System.out.println("Caractère inconnu");
            }
        }
        
        afficherPile(stack);
        return 1;
    }
}
