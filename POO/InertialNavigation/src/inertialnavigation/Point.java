/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inertialnavigation;

/**
 *
 * @author hugob
 */
public class Point {
    private double x;
    private double y;

    public Point(double x, double y){
        this.x=x;
        this.y=y;
    }
    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }
}
