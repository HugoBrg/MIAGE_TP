/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6_polymorphisme;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author hugob
 */
public class AppletFormes extends Applet {
    public void paint(Graphics g) {   
        TestFormes tf1 = new TestFormes(g);
    }
}
