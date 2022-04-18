#copyright by khivuss

from tkinter import *
from math import *
root=Tk()
root.title('NVIDIA')
root.geometry('600x600+100+100')

m=50
cx=400
cy=400
minx=-1
maxx=1
miny=-1
maxy=1
mx=1
my=1
a=1
b=1
c=1
alpha=60

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=50,y=50)

rbt=IntVar()
rbt.set(0)
rbt1=Radiobutton(root,width=15,variable=rbt,value=1,text='Куб',indicatoron=0,anchor=W)
rbt2=Radiobutton(root,width=15,variable=rbt,value=2,text='Шестиугльник',indicatoron=0,anchor=W)
rbt3=Radiobutton(root,width=15,variable=rbt,value=3,text='Домик',indicatoron=0,anchor=W)
rbt4=Radiobutton(root,width=15,variable=rbt,value=4,text='Пирамидка',indicatoron=0,anchor=W)
rbt5=Radiobutton(root,width=15,variable=rbt,value=5,text='Covid19',indicatoron=0,anchor=W)

rbt1.place(x=460,y=300)
rbt2.place(x=460,y=325)
rbt3.place(x=460,y=350)
rbt4.place(x=460,y=375)
rbt5.place(x=460,y=400)

ent_minx=Entry(root,width=4)
ent_minx.insert(0,-m)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.insert(0,m)
ent_maxx.place(x=460,y=250)

ent_miny=Entry(root,width=4)
ent_miny.insert(0,-m)
ent_miny.place(x=250,y=460)

ent_maxy=Entry(root,width=4)
ent_maxy.insert(0,m)
ent_maxy.place(x=250,y=25)

ent_a=Entry(root,width=5)
ent_a.insert(0,1)
ent_a.place(x=500,y=75)
lbl_a=Label(root,text='a')
lbl_a.place(x=475,y=75)

ent_b=Entry(root,width=5)
ent_b.insert(0,1)
ent_b.place(x=500,y=100)
lbl_b=Label(root,text='b')
lbl_b.place(x=475,y=100)

ent_c=Entry(root,width=5)
ent_c.insert(0,1)
ent_c.place(x=500,y=125)
lbl_c=Label(root,text='c')
lbl_c.place(x=475,y=125)

ent_alpha=Entry(root,width=5)
ent_alpha.insert(0,60)
ent_alpha.place(x=500,y=150)
lbl_alpha=Label(root,text='Alpha')
lbl_alpha.place(x=456,y=150)

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

def line3d(x1,y1,z1,x2,y2,z2,dash=None,fill='red',arrow=None):
    x3_1=x1*a+z1*c*cos(radians(alpha+180))
    y3_1=y1*b+z1*c*sin(radians(alpha+180))
    x3_2=x2*a+z2*c*cos(radians(alpha+180))
    y3_2=y2*b+z2*c*sin(radians(alpha+180))
    canv.create_line(px(x3_1),py(y3_1),px(x3_2),py(y3_2),dash=dash,fill=fill,arrow=arrow)

def but_clk():
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha
    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    c=float(ent_c.get() if ent_c.get()!='' else 1)
    alpha=float(ent_alpha.get() if ent_alpha.get()!='' else 60)
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    canv.delete(ALL)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST,fill='gray50')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    line3d(0,0,miny,0,0,maxy,None,'gray50',LAST)  
    if rbt.get()==1: #куб
        line3d(0,0,0,0,0,10)
        line3d(0,0,0,0,10,0)
        line3d(0,0,0,10,0,0)
        line3d(10,0,0,10,10,0)
        line3d(10,0,0,10,0,10)
        line3d(0,10,0,10,10,0)
        line3d(0,10,0,0,10,10)
        line3d(10,10,10,10,10,0)
        line3d(10,10,10,0,10,10)
        line3d(10,10,10,10,0,10)
        line3d(0,0,10,10,0,10)
        line3d(0,0,10,0,10,10)
    if rbt.get()==2: #шестиугольник
        line3d(10,0,0,5,0,10)
        line3d(5,0,10,-5,0,10)
        line3d(-5,0,10,-10,0,0)
        line3d(-10,0,0,-5,0,-10)
        line3d(-5,0,-10,5,0,-10)
        line3d(5,0,-10,10,0,0)
        line3d(10,10,0,5,10,10)
        line3d(5,10,10,-5,10,10)
        line3d(-5,10,10,-10,10,0)
        line3d(-10,10,0,-5,10,-10)
        line3d(-5,10,-10,5,10,-10)
        line3d(5,10,-10,10,10,0)
        line3d(10,0,0,10,10,0)
        line3d(5,0,10,5,10,10)
        line3d(-5,0,10,-5,10,10)
        line3d(-10,0,0,-10,10,0,)
        line3d(-5,0,-10,-5,10,-10)
        line3d(5,0,-10,5,10,-10)
    if rbt.get()==3: #домик
        line3d(10,0,0,10,10,0)
        line3d(10,0,0,10,0,10)
        line3d(0,10,0,10,10,0)
        line3d(0,10,0,0,10,10)
        line3d(10,10,10,10,10,0)
        line3d(10,10,10,0,10,10)
        line3d(10,10,10,10,0,10)
        line3d(0,0,10,10,0,10)
        line3d(0,0,10,0,10,10)
        line3d(0,10,0,0,15,5)
        line3d(0,15,5,0,10,10)
        line3d(10,10,0,10,15,5)
        line3d(10,15,5,10,10,10)
        line3d(0,15,5,10,15,5)
        line3d(3,3,10,7,3,10)
        line3d(3,7,10,7,7,10)
        line3d(3,3,10,3,7,10)
        line3d(7,3,10,7,7,10)
        line3d(10,7,0,10,7,3)
        line3d(10,7,3,10,0,3)
        line3d(0,0,0,0,0,10)
        line3d(0,0,0,0,10,0)
        line3d(0,0,0,10,0,0)
    if rbt.get()==4: #Пирамидка
        line3d(10,0,10,10,0,-10)
        line3d(10,0,10,-10,0,10)
        line3d(-10,0,10,-10,0,-10)
        line3d(-10,0,-10,10,0,-10,(1,1))
        line3d(7,7,7,7,7,-7)
        line3d(7,7,7,-7,7,7)
        line3d(-7,7,7,-7,7,-7)
        line3d(7,7,-7,-7,7,-7)
        line3d(10,0,10,7,7,7)
        line3d(-10,0,10,-7,7,7)
        line3d(10,0,-10,7,7,-7)
        line3d(-10,0,-10,-7,7,-7)
    if rbt.get()==5: #Covid19
        line3d(10,0,10,10,0,-10)
        line3d(10,0,10,-10,0,10)
        line3d(-10,0,10,-10,0,-10,(1,1))
        line3d(-10,0,-10,10,0,-10,(1,1))
        line3d(10,0,0,10,25,10)
        line3d(10,25,10,0,0,10)
        line3d(10,25,10,10,0,10)
        line3d(-10,0,10,-10,25,10)
        line3d(0,0,10,-10,25,10)
        line3d(-10,0,0,-10,25,10)
        line3d(10,0,-10,10,25,-10)
        line3d(0,0,-10,10,25,-10)
        line3d(10,0,0,10,25,-10)
        line3d(-10,0,-10,-10,25,-10)
        line3d(0,0,-10,-10,25,-10)
        line3d(-10,0,0,-10,25,-10)

#кнопкi
but=Button(root,text='график',command=but_clk,width=10,heigh=3)
but.place(x=460,y=180)

root.mainloop()
