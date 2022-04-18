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
ent_minx.insert(0,-5)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.insert(0,5)
ent_maxx.place(x=460,y=250)

ent_miny=Entry(root,width=4)
ent_miny.insert(0,-5)
ent_miny.place(x=250,y=460)

ent_maxy=Entry(root,width=4)
ent_maxy.insert(0,5)
ent_maxy.place(x=250,y=25)

ent_d=Entry(root,width=5)
ent_d.insert(0,1000)
ent_d.place(x=460,y=51)

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
    d=float(ent_d.get() if ent_d.get()!='' else 100)
    dx=1/d
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    canv.delete(ALL)
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST)
    x=minx
    while not x>=maxx:
        y=x**3-cos(x)
        canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='red')
        x+=dx

but=Button(root,text='график',command=but_clk)
but.place(x=460,y=20)

root.mainloop()
