
from tkinter import *
from math import *

root=Tk()
root.title('график')
root.geometry('700x600+100+100')

cx=400
cy=400
minx=-1
maxx=1
miny=-1
maxy=1
mxx=10
mx=1
my=1
a=1
b=1
n=1
k=1

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=50,y=50)

rbt=IntVar()
rbt.set(0)
rbt1=Radiobutton(root,width=25,variable=rbt,value=1,text='Круг',indicatoron=0,anchor=W)
rbt2=Radiobutton(root,width=25,variable=rbt,value=2,text='Кардиоида',indicatoron=0,anchor=W)
rbt3=Radiobutton(root,width=25,variable=rbt,value=3,text='Логарифмическая спираль',indicatoron=0,anchor=W)
rbt4=Radiobutton(root,width=25,variable=rbt,value=4,text='Декартов лист',indicatoron=0,anchor=W)
rbt5=Radiobutton(root,width=25,variable=rbt,value=5,text='Фигура Лиссажу',indicatoron=0,anchor=W)
rbt6=Radiobutton(root,width=25,variable=rbt,value=6,text='k-лепестковая роза',indicatoron=0,anchor=W)
rbt7=Radiobutton(root,width=25,variable=rbt,value=7,text='Эпициклоида',indicatoron=0,anchor=W)

rbt1.place(x=460,y=300)
rbt2.place(x=460,y=325)
rbt3.place(x=460,y=350)
rbt4.place(x=460,y=375)
rbt5.place(x=460,y=400)
rbt6.place(x=460,y=425)
rbt7.place(x=460,y=450)

ent_minx=Entry(root,width=4)
ent_minx.insert(0,-mxx)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.insert(0,mxx)
ent_maxx.place(x=460,y=250)

ent_miny=Entry(root,width=4)
ent_miny.insert(0,-mxx)
ent_miny.place(x=250,y=460)

ent_maxy=Entry(root,width=4)
ent_maxy.insert(0,mxx)
ent_maxy.place(x=250,y=25)

ent_d=Entry(root,width=5)
ent_d.insert(0,1000)
ent_d.place(x=475,y=75)
lbl_d=Label(root,text='d')
lbl_d.place(x=460,y=75)

ent_a=Entry(root,width=5)
ent_a.insert(0,a)
ent_a.place(x=475,y=100)
lbl_a=Label(root,text='a')
lbl_a.place(x=460,y=100)

ent_b=Entry(root,width=5)
ent_b.insert(0,b)
ent_b.place(x=475,y=125)
lbl_b=Label(root,text='b')
lbl_b.place(x=460,y=125)

ent_n=Entry(root,width=5)
ent_n.insert(0,n)
ent_n.place(x=475,y=150)
lbl_n=Label(root,text='n')
lbl_n.place(x=460,y=150)

ent_k=Entry(root,width=5)
ent_k.insert(0,k)
ent_k.place(x=475,y=175)
lbl_k=Label(root,text='k')
lbl_k.place(x=460,y=175)

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
    global minx,miny,maxx,maxy,mx,my,d,a,b,n,k
    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    d=float(ent_d.get() if ent_d.get()!='' else 100)
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    n=float(ent_n.get() if ent_n.get()!='' else 1)
    k=float(ent_k.get() if ent_k.get()!='' else 5)
    df=1/d
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    canv.delete(ALL)
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST)
    f=0
    if rbt.get()==1:
        while not f>=2*pi:
            r=2
            x=r*cos(f)
            y=r*sin(f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
    if rbt.get()==2:
        a=4
        while not f>=2*pi:
            r=a*(1+cos(f))
            x=r*cos(f)
            y=r*sin(f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
        ent_a.delete(0,END)
        ent_a.insert(0,a)
    if rbt.get()==3:
        a=0.2
        n=5
        b=0.15
        while not f>=2*pi*n:
            r=a*exp(b*f)
            x=r*cos(f)
            y=r*sin(f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
        ent_a.delete(0,END)
        ent_a.insert(0,a)
        ent_n.delete(0,END)
        ent_n.insert(0,n)
        ent_b.delete(0,END)
        ent_b.insert(0,b)
    if rbt.get()==4:
        a=4
        while not f>=2*pi:
            r=3*a*cos(f)*sin(f)/(cos(f)**3+sin(f)**3)
            x=r*cos(f)
            y=r*sin(f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
        ent_a.delete(0,END)
        ent_a.insert(0,a)
    if rbt.get()==5:
        f=-pi
        while not f>=pi:
            r=10
            x=r*cos(5*f)
            y=r*sin(3*f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
    if rbt.get()==6:
        if k//2==0:
            k*=2
        f=-pi
        while not f>=pi:
            r=sin(k*f)
            x=10*r*cos(f)
            y=10*r*sin(f)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
    if rbt.get()==7:
        while not f>=2*pi:
            x=(a+b)*cos(f)-a*cos((a+b)*f/a)
            y=(a+b)*sin(f)-a*sin((a+b)*f/a)
            canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
            f+=df
        

but=Button(root,text='график',command=but_clk)
but.place(x=460,y=20)

root.mainloop()
