/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp1_helloworld;

/**
 *
 * @author hugob
 */
import java.awt.Graphics;  
import java.applet.Applet;  
  
public class HelloWorldApplet extends Applet {  
  public void paint(Graphics g) {  
    g.drawString("Hello world!", 50, 25);  
  }  
}