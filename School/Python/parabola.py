'''Copyright Aleksey inc. 2003-2020 all rights reserved©
vk.com/khivuss'''

from tkinter import *
from math import *
from random import randint
root=Tk()
root.title('Треугольник')
root.config(bg='gray80')
root.geometry('600x600+100+100')

#Canvas

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

#windows

ent_minx=Entry(root,width=4)
ent_minx.insert(0,-5)
ent_minx.place(x=10,y=250)

ent_maxx=Entry(root,width=4)
ent_maxx.insert(0,5)
ent_maxx.place(x=465,y=250)

ent_miny=Entry(root,width=4)
ent_miny.insert(0,-5)
ent_miny.place(x=238,y=465)

ent_maxy=Entry(root,width=4)
ent_maxy.insert(0,5)
ent_maxy.place(x=238,y=15)

ent_n=Entry(root,width=6)
ent_n.insert(0,1000)
ent_n.place(x=465,y=70)
lbl_n=Label(root,text='Кол-во точек',bg='gray80')
lbl_n.place(x=465,y=50)

ent_s=Entry(root,width=10)
ent_s.place(x=465,y=150)
lbl_s=Label(root,text='Отношение точек:',bg='gray80')
lbl_s.place(x=465,y=130)

#functions
def points():
    s=0
    n=int(ent_n.get() if ent_n.get()!='' else 100)
    for i in range (n):
        x=randint(-1000,1000)/1000
        y=randint(-1000,1000)/1000
        y1 = x ** 2
        if y > 0 and y < y1 and x > 0: 
            s+=1
        canv.create_line(px(x),py(y),px(x)+1,py(y)+1,fill='purple')
        root.update()
        if s!=0:
            s_res=s/n
            ent_s.delete(0,END)
            ent_s.insert(0,s_res)

def px(x):
    mx=cx/(maxx-minx)
    px=x*mx-minx*mx
    return px

def py(y):
    my=cy/(maxy-miny)
    py=cy-(y*my-miny*my)
    return py

def clk_but():
    global minx,maxx,miny,maxy,n
    n=int(ent_n.get() if ent_n.get()!='' else 100)
    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    canv.delete(ALL)
    canv.create_line(px(minx),py(0),
                     px(maxx),py(0),
                     arrow=LAST,
                     fill='gray50')
    canv.create_line(px(0),py(miny),
                     px(0),py(maxy),
                     arrow=LAST,
                     fill='gray50')
    x=minx
    while not x>=maxx:
        y=x**2
        canv.create_line(px(x),py(y),px(x)+1,py(y)+1)
        x+=(maxx-minx)/n
    canv.create_rectangle(px(1),py(1),px(-1),py(-1))

#button

but=Button(root,
           text='график',
           command=clk_but)
but.place(x=465,y=15)

but_dot=Button(root, text='создать точки',command=points)
but_dot.place(x=465,y=100)

root.mainloop()