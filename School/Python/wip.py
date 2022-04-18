#copyright by khivuss

from tkinter import *
from math import *

root=Tk()
root.title('Хоррор на юнити')
root.geometry('600x600+100+100')

vx=1
m=80
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
x=80

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

image_r1=PhotoImage(file='r3.png')
image_r2=PhotoImage(file='r1.png')
image_r3=PhotoImage(file='r2.png')

image_l1=PhotoImage(file='l3.png')
image_l2=PhotoImage(file='l1.png')
image_l3=PhotoImage(file='l2.png')

img_s=PhotoImage(file='stay.png')

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=50,y=50)
canv.create_image(px(0),py(0),image=img_s)

ent_a=Entry(root,width=5)
ent_a.insert(0,1)
ent_a.place(x=460,y=50)
lbl_a=Label(root,text='a')
lbl_a.place(x=460,y=70)

ent_b=Entry(root,width=5)
ent_b.insert(0,1)
ent_b.place(x=460,y=100)
lbl_b=Label(root,text='b')
lbl_b.place(x=460,y=120)

ent_c=Entry(root,width=5)
ent_c.insert(0,1)
ent_c.place(x=460,y=150)
lbl_c=Label(root,text='c')
lbl_c.place(x=460,y=170)

ent_alpha=Entry(root,width=5)
ent_alpha.insert(0,60)
ent_alpha.place(x=460,y=200)
lbl_alpha=Label(root,text='Alpha')
lbl_alpha.place(x=460,y=220)

ent_xxx=Entry(root,width=10)
ent_xxx.place(x=460,y=250)

def line3d(x1,y1,z1,x2,y2,z2,dash=None,fill='red',arrow=None):
    x3_1=x1*a+z1*c*cos(radians(alpha+180))
    y3_1=y1*b+z1*c*sin(radians(alpha+180))
    x3_2=x2*a+z2*c*cos(radians(alpha+180))
    y3_2=y2*b+z2*c*sin(radians(alpha+180))
    canv.create_line(px(x3_1),py(y3_1),px(x3_2),py(y3_2),dash=dash,fill=fill,arrow=arrow)

def move_r(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x,m
    minx,miny=-m,-m
    maxx,maxy=m,m
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    c=float(ent_c.get() if ent_c.get()!='' else 1)
    alpha=float(ent_alpha.get() if ent_alpha.get()!='' else 60)
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    alpha=60+(80-x)/160*60
    if x!=9:
        canv.delete(ALL)
        line3d(0+x,0,0,10+x,0,0)
        line3d(0+x,0,0,0+x,0,20)
        line3d(0+x,0,0,0+x,30,0)
        line3d(10+x,0,0,10+x,0,20)
        line3d(10+x,0,20,0+x,0,20)
        line3d(10+x,0,20,10+x,30,20)
        line3d(10+x,0,0,10+x,30,0)
        line3d(0+x,0,20,0+x,30,20)
        line3d(0+x,30,0,10+x,30,0)
        line3d(0+x,30,0,0+x,30,20)
        line3d(10+x,30,0,10+x,30,20)
        line3d(10+x,30,20,0+x,30,20)
        if 0<=x%12<=3: 
            canv.create_image(px(0),py(0),image=image_r1)
        if 4<=x%12<=7:
            canv.create_image(px(0),py(0),image=image_r2)
        if 8<=x%12<=11:
            canv.create_image(px(0),py(0),image=image_r3)
        root.update()
        x-=vx
        if x<=-80:x=80
    ent_xxx.delete(0,END)
    ent_xxx.insert(0,x)

def move_l(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x,m
    minx,miny=-m,-m
    maxx,maxy=m,m
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    c=float(ent_c.get() if ent_c.get()!='' else 1)
    alpha=float(ent_alpha.get() if ent_alpha.get()!='' else 60)
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    alpha=60+(80-x)/160*60
    if x!=-22:
        canv.delete(ALL)
        line3d(0+x,0,0,10+x,0,0)
        line3d(0+x,0,0,0+x,0,20)
        line3d(0+x,0,0,0+x,30,0)
        line3d(10+x,0,0,10+x,0,20)
        line3d(10+x,0,20,0+x,0,20)
        line3d(10+x,0,20,10+x,30,20)
        line3d(10+x,0,0,10+x,30,0)
        line3d(0+x,0,20,0+x,30,20)
        line3d(0+x,30,0,10+x,30,0)
        line3d(0+x,30,0,0+x,30,20)
        line3d(10+x,30,0,10+x,30,20)
        line3d(10+x,30,20,0+x,30,20)
        if 0<=x%12<=3: 
            canv.create_image(px(0),py(0),image=image_l1)
        if 4<=x%12<=7:
            canv.create_image(px(0),py(0),image=image_l2)
        if 8<=x%12<=11:
            canv.create_image(px(0),py(0),image=image_l3)
        root.update()
        x+=vx
        if x>=80:x=-80
    ent_xxx.delete(0,END)
    ent_xxx.insert(0,x)
    
def move_u(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x,m
    minx,miny=-m,-m
    maxx,maxy=m,m
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    c=float(ent_c.get() if ent_c.get()!='' else 1)
    alpha=float(ent_alpha.get() if ent_alpha.get()!='' else 60)
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    line3d(0+x,0,0,10+x,0,0)
    line3d(0+x,0,0,0+x,0,20)
    line3d(0+x,0,0,0+x,30,0)
    line3d(10+x,0,0,10+x,0,20)
    line3d(10+x,0,20,0+x,0,20)
    line3d(10+x,0,20,10+x,30,20)
    line3d(10+x,0,0,10+x,30,0)
    line3d(0+x,0,20,0+x,30,20)
    line3d(0+x,30,0,10+x,30,0)
    line3d(0+x,30,0,0+x,30,20)
    line3d(10+x,30,0,10+x,30,20)
    line3d(10+x,30,20,0+x,30,20)
    root.update()
    c-=0.1
    ent_c.delete(0,END)
    ent_c.insert(0,c)

def move_d(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x,m
    minx,miny=-m,-m
    maxx,maxy=m,m
    a=float(ent_a.get() if ent_a.get()!='' else 1)
    b=float(ent_b.get() if ent_b.get()!='' else 1)
    c=float(ent_c.get() if ent_c.get()!='' else 1)
    alpha=float(ent_alpha.get() if ent_alpha.get()!='' else 60)
    mx=cx/(maxx-minx)
    my=cy/(maxy-miny)
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    line3d(0+x,0,0,10+x,0,0)
    line3d(0+x,0,0,0+x,0,20)
    line3d(0+x,0,0,0+x,30,0)
    line3d(10+x,0,0,10+x,0,20)
    line3d(10+x,0,20,0+x,0,20)
    line3d(10+x,0,20,10+x,30,20)
    line3d(10+x,0,0,10+x,30,0)
    line3d(0+x,0,20,0+x,30,20)
    line3d(0+x,30,0,10+x,30,0)
    line3d(0+x,30,0,0+x,30,20)
    line3d(10+x,30,0,10+x,30,20)
    line3d(10+x,30,20,0+x,30,20)
    root.update()
    c+=0.1
    ent_c.delete(0,END)
    ent_c.insert(0,c)

root.bind('<Left>',move_l)
root.bind('<Right>',move_r)
root.bind('<Up>',move_u)
root.bind('<Down>',move_d)

root.mainloop()
