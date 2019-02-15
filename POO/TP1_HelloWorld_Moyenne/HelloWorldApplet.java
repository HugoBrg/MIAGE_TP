import java.awt.Graphics;  
import java.applet.Applet;  
  
public class HelloWorldApplet extends Applet {  
  public void paint(Graphics g) {  
    g.drawString("Hello world!", 50, 25);  
  }  
}