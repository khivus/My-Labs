#made by khivus

from tkinter import *
from math import *

#root

root=Tk()
root.title('график')
root.config(bg='gray80')
root.geometry('700x500+100+100')

#lol

cx=400
cy=400
mx=1
my=1

#canvas

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=50,y=50)

#windows

ent_minx=Entry(root,width=4)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.place(x=465,y=250)

ent_miny=Entry(root,width=4)
ent_miny.place(x=238,y=465)

ent_maxy=Entry(root,width=4)
ent_maxy.place(x=238,y=15)

lbl_x1=Label(root,text='x1=',background='gray80')
ent_x1=Entry(root,width=10)
lbl_x1.place(x=500,y=50)
ent_x1.place(x=525,y=50)
ent_x1.insert(0,-3)

lbl_y1=Label(root,text='y1=',background='gray80')
ent_y1=Entry(root,width=10)
lbl_y1.place(x=600,y=50)
ent_y1.place(x=625,y=50)
ent_y1.insert(0,5)

lbl_x2=Label(root,text='x2=',background='gray80')
ent_x2=Entry(root,width=10)
lbl_x2.place(x=500,y=75)
ent_x2.place(x=525,y=75)
ent_x2.insert(0,7)

lbl_y2=Label(root,text='y2=',background='gray80')
ent_y2=Entry(root,width=10)
lbl_y2.place(x=600,y=75)
ent_y2.place(x=625,y=75)
ent_y2.insert(0,2)

lbl_x3=Label(root,text='x3=',background='gray80')
ent_x3=Entry(root,width=10)
lbl_x3.place(x=500,y=100)
ent_x3.place(x=525,y=100)
ent_x3.insert(0,5)

lbl_y3=Label(root,text='y3=',background='gray80')
ent_y3=Entry(root,width=10)
lbl_y3.place(x=600,y=100)
ent_y3.place(x=625,y=100)
ent_y3.insert(0,-4)

lbl_x4=Label(root,text='x4=',background='gray80')
ent_x4=Entry(root,width=10)
lbl_x4.place(x=500,y=125)
ent_x4.place(x=525,y=125)
ent_x4.insert(0,-5)

lbl_y4=Label(root,text='y4=',background='gray80')
ent_y4=Entry(root,width=10)
lbl_y4.place(x=600,y=125)
ent_y4.place(x=625,y=125)
ent_y4.insert(0,-4)

lbl_p=Label(root,text='P =',background='gray80')
ent_p=Entry(root,width=10)
lbl_p.place(x=500,y=150)
ent_p.place(x=525,y=150)

lbl_s=Label(root,text='S =',background='gray80')
ent_s=Entry(root,width=10)
lbl_s.place(x=600,y=150)
ent_s.place(x=625,y=150)

#functions

def px(x):
    mx=cx/(maxx-minx)
    px=x*mx-minx*mx
    return px

def py(y):
    my=cy/(maxy-miny)
    py=cy-(y*my-miny*my)
    return py

def clk_but():
    global minx,maxx,miny,maxy
    x1=float(ent_x1.get() if ent_x1.get()!='' else -3)
    x2=float(ent_x2.get() if ent_x2.get()!='' else 7)
    x3=float(ent_x3.get() if ent_x3.get()!='' else 5)
    x4=float(ent_x4.get() if ent_x4.get()!='' else -5)
    y1=float(ent_y1.get() if ent_y1.get()!='' else 5)
    y2=float(ent_y2.get() if ent_y2.get()!='' else 2)
    y3=float(ent_y3.get() if ent_y3.get()!='' else -4)
    y4=float(ent_y4.get() if ent_y4.get()!='' else -4)
    maxx=max(x1,x2,x3,x4)+1
    maxy=max(y1,y2,y3,y4)+1
    minx=min(x1,x2,x3,x4)-1
    miny=min(y1,y1,y3,y4)-1
    x=[x1,x2,x3,x4]
    k1=(y2-y1)/(x2-x1+0.000000000001)
    k2=(y3-y2)/(x3-x2+0.000000000001)
    k3=(y4-y3)/(x4-x3+0.000000000001)
    k4=(y1-y4)/(x1-x4+0.000000000001)
    dk1=(y3-y1)/(x3-x1+0.000000000001)
    dk2=(y4-y2)/(x4-x2+0.000000000001)
    b1=y1-k1*x1
    b2=y2-k2*x2
    b3=y3-k3*x3
    b4=y4-k4*x4
    db1=y1-dk1*x1
    db2=y2-dk2*x2
    if min(x)<(b3-b1)/(k1-k3)<max(x) and not min(x)<(db2-db1)/(dk1-dk2)<max(x):
        x2,y2,x3,y3=x3,y3,x2,y2
    elif min(x)<(b4-b2)/(k2-k4)<max(x) and not min(x)<(db2-db1)/(dk1-dk2)<max(x):
        x1,x2,y1,y2=x2,x1,y2,y1
    a=sqrt((x2-x1)**2+(y2-y1)**2)
    b=sqrt((x3-x2)**2+(y3-y2)**2)
    c=sqrt((x4-x3)**2+(y4-y3)**2)
    d=sqrt((x1-x4)**2+(y1-y4)**2)
    p=a+b+c+d
    s=0.5*abs(x1*y2+x2*y3+x3*y4+x4*y1-x2*y1-x3*y2-x4*y3-x1*y4)

#поля вывода
    
    ent_maxx.delete(0,END)
    ent_maxx.insert(0,maxx)
    ent_maxy.delete(0,END)
    ent_maxy.insert(0,maxy)
    ent_minx.delete(0,END)
    ent_minx.insert(0,minx)
    ent_miny.delete(0,END)
    ent_miny.insert(0,miny)
    ent_p.delete(0,END)
    ent_p.insert(0,p)
    ent_s.delete(0,END)
    ent_s.insert(0,s)
    

    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)

#давайте рисовать!
    
    canv.delete(ALL)
    canv.create_polygon(px(x1),py(y1),px(x2),py(y2),px(x3),py(y3),px(x4),py(y4),outline='red',fill='white')
    canv.create_line(px(x1),py(y1),px(x3),py(y3),fill='green')
    canv.create_line(px(x2),py(y2),px(x4),py(y4),fill='blue')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    canv.create_line(px(0),py(miny),px(0),py(maxy),arrow=LAST,fill='gray50')
    
#button

but=Button(root,text='график',command=clk_but,width=26,heigh=2,activebackground='red',activeforeground='white')
but.place(x=500,y=175)

#end

root.mainloop()
