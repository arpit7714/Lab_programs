import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.util.*;



public class bcdcounter extends JComponent{
  static int q1,q2,q4,q8;
 static int q8_ ,q4_,q2_,q1_;
 static JFrame testFrame;
 static JPanel buttonsPanel;
 static JButton clock1,clock0; 
 static JLabel j1,j2,j3,j4;
private static class Line{
    final int x1; 
    final int y1;
    final int x2;
    final int y2;   
    final Color color;

    public Line(int x1, int y1, int x2, int y2, Color color) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
    }               
}

//for the q8
private static final LinkedList<Line> lines = new LinkedList<Line>();

public void addLine(int x1, int x2, int x3, int x4) {
    addLine(x1, x2, x3, x4, Color.black);
}
// for the q4
private static final LinkedList<Line> lines1 = new LinkedList<Line>();

public void addLine1(int x1, int x2, int x3, int x4) {
    addLine1(x1, x2, x3, x4, Color.black);
}
//for the q2
private static final LinkedList<Line> lines2 = new LinkedList<Line>();

public void addLine2(int x1, int x2, int x3, int x4) {
    addLine2(x1, x2, x3, x4, Color.black);
}

//for the q1
private static final LinkedList<Line> lines3 = new LinkedList<Line>();

public void addLine3(int x1, int x2, int x3, int x4) {
    addLine3(x1, x2, x3, x4, Color.black);
}


public void addLine(int x1, int x2, int x3, int x4, Color color) {
    lines.add(new Line(x1,x2,x3,x4, color));      
    repaint();
}
public void addLine1(int x1, int x2, int x3, int x4, Color color) {
    lines1.add(new Line(x1,x2,x3,x4, color));        
    repaint();
}

public void addLine2(int x1, int x2, int x3, int x4, Color color) {
    lines2.add(new Line(x1,x2,x3,x4, color));        
    repaint();
}

public void addLine3(int x1, int x2, int x3, int x4, Color color) {
    lines3.add(new Line(x1,x2,x3,x4, color));        
    repaint();
}


@Override
protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    for (Line line : lines) {
        g.setColor(line.color);
        g.drawLine(line.x1, line.y1, line.x2, line.y2);
    }
    for (Line line : lines1) {
        g.setColor(line.color);
        g.drawLine(line.x1, line.y1, line.x2, line.y2);
    }
   for (Line line : lines2) {
        g.setColor(line.color);
        g.drawLine(line.x1, line.y1, line.x2, line.y2);
    }
   for (Line line : lines3) {
        g.setColor(line.color);
        g.drawLine(line.x1, line.y1, line.x2, line.y2);
    }
}

public static void main(String[] args) {
    bcdcounter comp = new bcdcounter();
 
    testFrame = new JFrame();
    testFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    comp.setPreferredSize(new Dimension(1000, 300));
    testFrame.getContentPane().add(comp, BorderLayout.CENTER);
    buttonsPanel = new JPanel();
     clock1 = new JButton("clock 1");
     clock0 = new JButton("clock 0");
     
      /*j1=new JLabel("Q8");
      j2=new JLabel("Q4");
      j3=new JLabel("Q2");
      j4=new JLabel("Q1"); 
       
      testFrame.add(j1);
      testFrame.add(j2);
      testFrame.add(j3);
      testFrame.add(j4);*/
   
    buttonsPanel.add(clock1);
    buttonsPanel.add(clock0);
    Scanner sc=new Scanner(System.in);
     System.out.println("enter the initial state of the counter");
     String input=sc.nextLine();
     q8=Integer.parseInt(Character.toString(input.charAt(0)));
     q4=Integer.parseInt(Character.toString(input.charAt(1)));
     q2=Integer.parseInt(Character.toString(input.charAt(2)));
     q1=Integer.parseInt(Character.toString(input.charAt(3)));
     
      
    lines.add(new Line(100,100,100,100,new Color((float)Math.random(), (float)Math.random(), (float)Math.random())));  
      
    lines1.add(new Line(100,200,100,200,new Color((float)Math.random(), (float)Math.random(), (float)Math.random()))); 
     
    lines2.add(new Line(100,300,100,300,new Color((float)Math.random(), (float)Math.random(), (float)Math.random()))); 
     
    lines3.add(new Line(100,400,100,400,new Color((float)Math.random(), (float)Math.random(), (float)Math.random()))); 

    testFrame.getContentPane().add(buttonsPanel, BorderLayout.SOUTH);
    clock1.addActionListener(new mylistener());
    clock0.addActionListener(new mylistener());
    testFrame.pack();
    testFrame.setVisible(true); 
     

  }
  
 public static class mylistener implements ActionListener{
        bcdcounter comp = new bcdcounter();
     public void actionPerformed(ActionEvent ae){
         int x1,x2,y1,y2;
         if(ae.getSource()==clock1){
             q8_=q4*q2*q1+(1-((1-q2)*q1*q8))*q8;
             q4_=(1-q4)*q1*q2+(1-(q4*q2*q1))*q4;
             System.out.print(q4_+" ");
            q2_=(1-q8)*(1-q2)*q1+(1-q1*q2)*q2;
            System.out.print(q2_+" ");
            q1_=(1-q1)+(1-q1)*q1;
            System.out.print(q1_+" "+"\n");
            q1=q1_;
            q2=q2_;
            q4=q4_;
            q8=q8_;
            if (q1==1){
               Line line=lines3.getLast();
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine3(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine3(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine3(x1, y1, x2, y2, randomColor);
        }
           if (q2==1){
               Line line=lines2.getLast();
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine2(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine2(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine2(x1, y1, x2, y2, randomColor);
        }
         if (q4==1){
               Line line=lines1.getLast();
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine1(x1, y1, x2, y2, randomColor);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine1(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine1(x1, y1, x2, y2, randomColor);
        }
         if (q8==1){
               Line line=lines.getLast();
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine(x1, y1, x2, y2, randomColor);
        }
          if(q1==0){
              Line line3=lines3.getLast();
               x1 =  line3.x2;
               x2  = line3.x2+50;
               y1  = line3.y2;
               y2  = line3.y2;
              comp.addLine3(x1,y1,x2,y2,Color.black);  
         }
          if(q2==0){
            Line line2=lines2.getLast();
               x1 =  line2.x2;
               x2  = line2.x2+50;
               y1  = line2.y2;
               y2  = line2.y2;
             comp.addLine2(x1,y1,x2,y2,Color.black);
           }
          if(q4==0){
             Line line1=lines1.getLast();
               x1 =  line1.x2;
               x2  = line1.x2+50;
               y1  = line1.y2;
               y2  = line1.y2;
            comp.addLine1(x1,y1,x2,y2,Color.black); 
         }
         if (q8==0){
              Line line=lines.getLast();
               x1 =  line.x2;
               x2  = line.x2+50;
               y1  = line.y2;
               y2  = line.y2;
           comp.addLine(x1,y1,x2,y2,Color.black); 
         }         
          }

   //next
        else{
           Line line=lines.getLast();
             if(line.y1==line.y2){ 
              x1 =  line.x2;
              x2  = line.x2+50;
              y1  = line.y2;
              y2  = line.y2;
           comp.addLine(x1,y1,x2,y2,Color.black);
              }
            else{
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine(x1, y1, x2, y2, randomColor);
          }
          line=lines1.getLast();
            if(line.y1==line.y2){
               x1 =  line.x2;
               x2  = line.x2+50;
               y1  = line.y2;
               y2  = line.y2;
            comp.addLine1(x1,y1,x2,y2,Color.black); }
            else{
     
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine1(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine1(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine1(x1, y1, x2, y2, randomColor);
           }
           line=lines2.getLast();
              if (line.y1==line.y2){
               x1 =  line.x2;
               x2  = line.x2+50;
               y1  = line.y2;
               y2  = line.y2;
             comp.addLine2(x1,y1,x2,y2,Color.black); }
             else{
             x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine2(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine2(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine2(x1, y1, x2, y2, randomColor);
           }
          line=lines3.getLast();
             if(line.y1==line.y2){
                x1 =  line.x2;
               x2  = line.x2+50;
               y1  = line.y2;
               y2  = line.y2;
              comp.addLine3(x1,y1,x2,y2,Color.black); }
            else{
            x1 = line.x2;
             x2 = line.x2;
             y1 = line.y2;
             y2 = line.y2-50;
            Color randomColor = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
            comp.addLine3(x1, y1, x2, y2, randomColor);
            System.out.println(x1);
            x1  = x2; 
            x2  = x2+50;
            y1  = y2;
              comp.addLine3(x1, y1, x2, y2, randomColor);
            x1 =  x2;
            y1  = y2;
            y2  = y2+50;
            comp.addLine3(x1, y1, x2, y2, randomColor);
        
           }
       
        }
   }
  }
}//end of the class


