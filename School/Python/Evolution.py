'''
Copyright Aleksey inc. 2003-2020 all rights reserved©
vk.com/khivuss
'''
#imports

from tkinter import *
from math import *

#root

root=Tk()
root.title('Численность популяций')
root.config(bg='gray75')
w=root.winfo_screenwidth()
h=root.winfo_screenheight()
w=(w//2)-300
h=(h//2)-300
root.geometry('600x600+{}+{}'.format(w, h))

#Canvas

minx=0
maxx=300
miny=0
maxy=300
cx=300
cy=300

canv=Canvas(root,width=300,height=300,bg='white')
canv.place(x=160,y=230)

#Функции перевода координат

def px(x):
    mx=cx/(maxx-minx)
    px=x*mx-minx*mx
    return px

def py(y):
    my=cy/(maxy-miny)
    py=cy-(y*my-miny*my)
    return py

#Functions

def graph():
    clear()
    graph1()
    graph2()
    graph3()
    graph4()

def clear():
    canv.delete(ALL)
    canv.create_line(0,300,300,300,arrow=LAST)
    canv.create_line(2,300,2,0,arrow=LAST)

def clk_but_a():
    clear()
    graph1()

def clk_but_b():
    clear()
    graph2()
    
def clk_but_c():
    clear()
    graph3()
    
def clk_but_dfg():
    clear()
    graph4()

#Функции графика

def graph1():
    x=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    for i in range(n):
        x=a*x
        canv.create_line(px(i),py(x),px(i)+1,py(x)+1,fill='blue')
        root.update()
    ent_x1.delete(0,END)
    ent_x1.insert(0,int(x))

def graph2():
    x=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    for i in range(n):
        x=(a-b*x)*x
        canv.create_line(px(i),py(x),px(i)+1,py(x)+1,fill='purple')
        root.update()
    ent_x2.delete(0,END)
    ent_x2.insert(0,int(x))

def graph3():
    x=int(ent_x.get() if ent_x.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    c=float(ent_c.get() if ent_c.get()!='' else 0.5)
    for i in range(n):
        x=(a-b*x)*x-c
        canv.create_line(px(i),py(x),px(i)+1,py(x)+1,fill='orange')
        root.update()
    ent_x3.delete(0,END)
    ent_x3.insert(0,int(x))

def graph4():
    x=int(ent_x.get() if ent_x.get()!='' else 10)
    y=int(ent_y.get() if ent_y.get()!='' else 10)
    n=int(ent_n.get() if ent_n.get()!='' else 250)
    a=float(ent_a.get() if ent_a.get()!='' else 1.18)
    b=float(ent_b.get() if ent_b.get()!='' else 0.001)
    c=float(ent_c.get() if ent_c.get()!='' else 0.5)
    d=float(ent_d.get() if ent_d.get()!='' else 0.94)
    f=float(ent_f.get() if ent_f.get()!='' else 0.001)
    g=float(ent_g.get() if ent_g.get()!='' else 0.0015)
    for i in range(n):
        x=(a-b*x)*x-c-f*x*y
        y=d*y+g*x*y
        canv.create_line(px(i),py(x),px(i)+1,py(x)+1,fill='green')
        canv.create_line(px(i),py(y),px(i)+1,py(y)+1,fill='crimson')
        root.update()
    ent_x4.delete(0,END)
    ent_x4.insert(0,int(x))
    ent_y1.delete(0,END)
    ent_y1.insert(0,int(y))

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

but_a=Button(root,text='Неограниченный рост',command=clk_but_a,activebackground='blue',activeforeground='white')
but_a.place(x=10,y=10)

but_b=Button(root,text='Ограниченный рост',command=clk_but_b,activebackground='purple',activeforeground='white')
but_b.place(x=10,y=60)

but_c=Button(root,text='Огр. рост с отловом',command=clk_but_c,activebackground='orange',activeforeground='white')
but_c.place(x=10,y=110)

but_dfg=Button(root,text='Жертва - Хищник',command=clk_but_dfg,activebackground='green',activeforeground='crimson')
but_dfg.place(x=10,y=160)

but_graph=Button(root,text='График',width=10,command=graph,activebackground='cyan',activeforeground='crimson')
but_graph.place(x=40,y=210)

#End

root.mainloop()