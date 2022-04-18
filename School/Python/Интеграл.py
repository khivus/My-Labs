from tkinter import *
from math import *

root=Tk()
root.title('график')
root.geometry('600x600+100+100')

cx=400
cy=400
minx=-1
maxx=1
miny=-1
maxy=1
mx=1
my=1

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=50,y=50)

ent_minx=Entry(root,width=4)
ent_minx.insert(0,-1)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.insert(0,5)
ent_maxx.place(x=460,y=250)

ent_miny=Entry(root,width=4)
ent_miny.insert(0,-1)
ent_miny.place(x=250,y=460)

ent_maxy=Entry(root,width=4)
ent_maxy.insert(0,5)
ent_maxy.place(x=250,y=25)

ent_d=Entry(root,width=5)
ent_d.insert(0,1000)
ent_d.place(x=460,y=50)
lbl_d=Label(root,text='d')
lbl_d.place(x=460,y=70)

ent_a=Entry(root,width=5)
ent_a.insert(0,0)
ent_a.place(x=460,y=90)
lbl_a=Label(root,text='a')
lbl_a.place(x=460,y=110)

ent_b=Entry(root,width=5)
ent_b.insert(0,2)
ent_b.place(x=460,y=130)
lbl_b=Label(root,text='b')
lbl_b.place(x=460,y=150)

ent_s1=Entry(root,width=15)
ent_s1.place(x=460,y=170)
lbl_s1=Label(root,text='s1')
lbl_s1.place(x=460,y=190)

ent_s2=Entry(root,width=15)
ent_s2.place(x=460,y=210)
lbl_s2=Label(root,text='s2')
lbl_s2.place(x=460,y=230)

def f(x):
    y=x**2+1
    return y

def px(x):
    px=x*mx-minx*mx
    return px

def py(y):
    py=cy-(y*my-miny*my)
    return py

def p(x,y):
    px=x*mx-minx*mx
    py=cy-(y*my-miny*my)
    return px,py

def but_clk():
    global minx,miny,maxx,maxy,mx,my,d,dx
    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    d=float(ent_d.get() if ent_d.get()!='' else 1000)
    a=float(ent_a.get() if ent_a.get()!='' else 0)
    b=float(ent_b.get() if ent_b.get()!='' else 2)
    dx=1/d
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    canv.delete(ALL)
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST)
    #graph
    s1=0
    x=minx
    while not x>=maxx:
        y=f(x)
        canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='black')
        x+=0.001
    #integral
    x=a
    while not x>=b:
        y=f(x)
        s1+=dx*y
        
        canv.create_rectangle(px(x),py(0),px(x+dx),py(y),fill='',outline='red')
        x+=dx
    ent_s1.delete(0,END)
    ent_s1.insert(0,s1)
    s2=(b**3/3+b)-(a**3/3+a)
    ent_s2.delete(0,END)
    ent_s2.insert(0,s2)
    

but=Button(root,text='график',command=but_clk)
but.place(x=460,y=20)

root.mainloop()
