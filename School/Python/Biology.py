#imports

from tkinter import *
from math import *

#root

root=Tk()
root.title('Численность популяций')
root.config(bg='gray75')
root.geometry('600x600')

#Canvas

minx=-1
maxx=1
miny=-1
maxy=1
cx=300
cy=300

canv=Canvas(root,width=300,height=300,bg='white')
canv.place(x=160,y=230)

#Functions

def px(x):
    mx=cx/(maxx-minx)
    px=x*mx-minx*mx
    return px

def py(y):
    my=cy/(maxy-miny)
    py=cy-(y*my-miny*my)
    return py

def clk_all():
    clk_but_a()
    clk_but_b()
    clk_but_c()
    clk_but_dfg()
    graph()

def clk_but_a():
    x1=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    for i in range(n):
        x1=a*x1
    ent_x1.delete(0,END)
    ent_x1.insert(0,int(x1))

def clk_but_b():
    x2=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    for i in range(n):
        x2=(a-b*x2)*x2
    ent_x2.delete(0,END)
    ent_x2.insert(0,int(x2))
    
def clk_but_c():
    x3=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    c=float(ent_c.get() if ent_c.get()!='' else 0.5)
    for i in range(n):
        x3=(a-b*x3)*x3-c
    ent_x3.delete(0,END)
    ent_x3.insert(0,int(x3))
    
def clk_but_dfg():
    x4=int(ent_x.get() if ent_x.get()!='' else 10)
    y=int(ent_y.get() if ent_y.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    c=float(ent_c.get() if ent_c.get()!='' else 0.5)
    d=float(ent_d.get() if ent_d.get()!='' else 0.94)
    f=float(ent_f.get() if ent_f.get()!='' else 0.001)
    g=float(ent_g.get() if ent_g.get()!='' else 0.0015)
    for i in range(n):
        x4=(a-b*x4)*x4-c-f*x4*y
        y=d*y+g*x4*y
    ent_x4.delete(0,END)
    ent_x4.insert(0,int(x4))
    ent_y1.delete(0,END)
    ent_y1.insert(0,int(y))

def graph():
    x1,x2,x3,x4=int(ent_x.get() if ent_x.get()!='' else 10)
    y=int(ent_y.get() if ent_y.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    c=float(ent_c.get() if ent_c.get()!='' else 0.5)
    d=float(ent_d.get() if ent_d.get()!='' else 0.94)
    f=float(ent_f.get() if ent_f.get()!='' else 0.001)
    g=float(ent_g.get() if ent_g.get()!='' else 0.0015)
    canv.delete(ALL)
    canv.create_line(0,280,300,280,arrow=LAST)
    canv.create_line(20,300,20,0,arrow=LAST)
    x=70
    x1=50
    y1=40
    y=240
    for i in range(6):
	canv.create_line(x,278,x,282)
	canv.create_text(x,297,text=x1)
	x+=50
        x1+=50
        canv.create_line(18,y,22,y)
        canv.create_text(10,y,text=y1)
        y-=40
        y1+=40
    for i in range(n):
        x1=a*x1
        canv.create_line(px(i),py(x1),px(i)+1,py(x1)+1,fill='green')
    for i in range(n):
        x2=(a-b*x2)*x2
        canv.create_line(px(i),py(x2),px(i)+1,py(x2)+1,fill='red')
    for i in range(n):
        x3=(a-b*x3)*x3-c
        canv.create_line(px(i),py(x3),px(i)+1,py(x3)+1,fill='purple')
    for i in range(n):
        x4=(a-b*x4)*x4-c-f*x4*y
        y=d*y+g*x4*y
        canv.create_line(px(i),py(x4),px(i)+1,py(x4)+1,fill='orange')
        
#windows

ent_a=Entry(root,width=6)
ent_a.place(x=175,y=10)
ent_a.insert(0,1.18)
lbl_a=Label(root,text='a',bg='gray75')
lbl_a.place(x=160,y=10)

ent_b=Entry(root,width=6)
ent_b.place(x=175,y=60)
ent_b.insert(0,0.001)
lbl_b=Label(root,text='b',bg='gray75')
lbl_b.place(x=160,y=60)

ent_c=Entry(root,width=6)
ent_c.place(x=175,y=110)
ent_c.insert(0,0.5)
lbl_c=Label(root,text='c',bg='gray75')
lbl_c.place(x=160,y=110)

ent_d=Entry(root,width=6)
ent_d.place(x=175,y=160)
ent_d.insert(0,0.94)
lbl_d=Label(root,text='d',bg='gray75')
lbl_d.place(x=160,y=160)

ent_f=Entry(root,width=6)
ent_f.place(x=235,y=160)
ent_f.insert(0,0.001)
lbl_f=Label(root,text='f',bg='gray75')
lbl_f.place(x=220,y=160)

ent_g=Entry(root,width=6)
ent_g.place(x=295,y=160)
ent_g.insert(0,0.0015)
lbl_g=Label(root,text='g',bg='gray75')
lbl_g.place(x=280,y=160)

ent_x=Entry(root,width=6)
ent_x.place(x=75,y=260)
ent_x.insert(0,10)
lbl_x=Label(root,text='Жертвы',bg='gray75')
lbl_x.place(x=10,y=260)

ent_y=Entry(root,width=6)
ent_y.place(x=75,y=305)
ent_y.insert(0,10)
lbl_y=Label(root,text='Хищники',bg='gray75')
lbl_y.place(x=10,y=305)

ent_n=Entry(root,width=6)
ent_n.place(x=75,y=350)
ent_n.insert(0,250)
lbl_n=Label(root,text='Циклы',bg='gray75')
lbl_n.place(x=10,y=350)

ent_x1=Entry(root,width=18)
ent_x1.place(x=350,y=10)
ent_x1.insert(0,0)

ent_x2=Entry(root,width=18)
ent_x2.place(x=350,y=60)
ent_x2.insert(0,0)


ent_x3=Entry(root,width=18)
ent_x3.place(x=350,y=110)
ent_x3.insert(0,0)


ent_x4=Entry(root,width=18)
ent_x4.place(x=420,y=160)
ent_x4.insert(0,0)
lbl_x4=Label(root,text='Жертвы',bg='gray75')
lbl_x4.place(x=350,y=160)

ent_y1=Entry(root,width=18)
ent_y1.place(x=420,y=190)
ent_y1.insert(0,0)
lbl_y1=Label(root,text='Хищники',bg='gray75')
lbl_y1.place(x=350,y=190)

#Buttons

but_a=Button(root,text='Неограниченный рост',command=clk_but_a)
but_a.place(x=10,y=10)

but_b=Button(root,text='Ограниченный рост',command=clk_but_b)
but_b.place(x=10,y=60)

but_c=Button(root,text='Огр. рост с отловом',command=clk_but_c)
but_c.place(x=10,y=110)

but_dfg=Button(root,text='Жертва - Хищник',command=clk_but_dfg)
but_dfg.place(x=10,y=160)

but_graph=Button(root,text='График',width=10,command=graph)
but_graph.place(x=40,y=210)

but_all=Button(root,text='Вычислить всё',command=clk_all)
but_all.place(x=240,y=10)

#End

root.mainloop()
