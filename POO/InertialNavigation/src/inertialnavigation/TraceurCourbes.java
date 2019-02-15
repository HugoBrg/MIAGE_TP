/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inertialnavigation;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

/**
 *
 * @author hugob
 */
 
public class TraceurCourbes extends JFrame{
 
	private Courbe x;
        private Courbe y;
        private Courbe z;
 
	public TraceurCourbes(DataStruct[] dataCSV){
		super("Courbe");
		this.setSize(1920, 1080);
 
		this.x=new Courbe();
                this.y=new Courbe();
                this.z=new Courbe();
                
 
                for(int j=0;j<dataCSV.length;j++){
                    //System.out.println("x : "+dataCSV[j].id+" | y : "+dataCSV[j].x);
                    this.x.ajouterPoint(new Point(dataCSV[j].id,dataCSV[j].x));
                    this.y.ajouterPoint(new Point(dataCSV[j].id,dataCSV[j].y));
                    this.z.ajouterPoint(new Point(dataCSV[j].id,dataCSV[j].z));
                }

		this.getContentPane().add(this.x);
                //this.getContentPane().add(this.y);
                //this.getContentPane().add(this.z);
 
		this.setVisible(true);
 
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we){
				System.exit(0);
			}
		});
	}
 
}