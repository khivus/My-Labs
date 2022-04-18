from tkinter import *
from math import *
root=Tk()
root.title('график')
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
ent_n.insert(0,10000)
ent_n.place(x=465,y=70)
lbl_n=Label(root,text='Кол-во точек',bg='gray80')
lbl_n.place(x=465,y=50)

ent_fx=Entry(root,width=15)
ent_fx.place(x=465, y=150)
'''
ent_maxy=Entry(root,width=6)
ent_maxy.place(x=465,y=250)
lbl_maxy=Label(root,text='max y',bg='gray80')
lbl_maxy.place(x=465,y=230)
ent_miny=Entry(root,width=6)
ent_miny.place(x=465,y=300)
lbl_miny=Label(root,text='min y',bg='gray80')
lbl_miny.place(x=465,y=280)
'''
#functions
'''
работает криво
def my():
    global miny,maxy
    a=float(ent_miny.get() if ent_miny.get()!='' else -1)
    b=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    a=(a+b)/2
    for i in range(100):
        j=(a+b)/2
        fa=(a**3/2)-4*a**2+5
        fb=(b**3/2)-4*b**2+5
        fj=(j**3/2)-4*j**2+5
        if fb*fj<0:
            a=j
        else:
            b=j
    ent_maxy.delete(0,END)
    ent_maxy.insert(END,j)
    a=float(ent_miny.get() if ent_miny.get()!='' else -1)
    b=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    b=(a+b)/2
    for i in range(100):
        j=(a+b)/2
        fa=(a**3/2)-4*a**2+5
        fb=(b**3/2)-4*b**2+5
        fj=(j**3/2)-4*j**2+5
        if fa*fj<0:
            b=j
        else:
            a=j
    ent_miny.delete(0,END)
    ent_miny.insert(END,j)
'''

def fx():
    global minx,maxx
    a=float(ent_minx.get() if ent_minx.get()!='' else -1)
    b=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    for i in range(100):
        j=(a+b)/2
        fa=-2*tan(a)+4*a
        fb=-2*tan(b)+4*b
        fj=-2*tan(j)+4*j
        if fa*fj<0:
            b=j
        else:
            a=j
    ent_fx.delete(0,END)
    ent_fx.insert(END,(a+b)/2)

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
    minx=float(ent_minx.get() if ent_minx.get()!='' else -1)
    maxx=float(ent_maxx.get() if ent_maxx.get()!='' else 1)
    miny=float(ent_miny.get() if ent_miny.get()!='' else -1)
    maxy=float(ent_maxy.get() if ent_maxy.get()!='' else 1)
    n=float(ent_n.get() if ent_n.get()!='' else 100)
    
#рисуем обычными координатами

    canv.delete(ALL)
    canv.create_line(px(minx),py(0),
                     px(maxx),py(0),
                     arrow=LAST,
                     fill='gray50')
    canv.create_line(px(0),py(miny),
                     px(0),py(maxy),
                     arrow=LAST,
                     fill='gray50')

###
#график
#y=ent_y.get() #if ent_y.get()!='' else ent_y.insert(END,'Нет функции!') жаль это так не работает ибо считает, что функция это строка
#if y>max(y): ymax=y
#y=x**3-cos(x)             -1
#y=((x**3)/2)-4*x**2+5       -2
#y=6**x+8**x-10**x         -3
#y=-2*tan(x)+4*x           -4
###

    x=minx
    while not x>=maxx:
        y=-2*tan(x)+4*x
        canv.create_line(px(x),py(y),
                         px(x)+1,py(y)+1,
                         fill='green')
        x+=(maxx-minx)/n
        

#button

but=Button(root,
           text='график',
           command=clk_but)
but.place(x=465,y=15)

but_fx=Button(root, text='Ноль Функции', command=fx)
but_fx.place(x=465,y=120)
'''
but_my=Button(root,text='maxy',command=my)
but_my.place(x=465,y=200)
'''
root.mainloop()