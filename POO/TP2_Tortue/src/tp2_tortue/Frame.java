/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp2_tortue;

/**
 *
 * @author hugob
 */
import java.awt.Dimension;
import java.awt.Image;
import javax.swing.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class Frame extends JFrame {

   public Frame() throws IOException {

      super("Tortue");

      WindowListener l = new WindowAdapter() {
         public void windowClosing(WindowEvent e){
            System.exit(0);
         }
      };
      addWindowListener(l);
      setSize(800,800); 
      setVisible(true);
   }
}