#copyright by khivuss
from tkinter import *
from math import *
root=Tk()
root.title('NVIDIA')
root.geometry('600x600+100+100')
#Canvas
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
canv=Canvas(root,
            width=cx,
            height=cy,
            bg='white')
canv.place(x=50,y=50)


#размеры
ent_minx=Entry(root,
               width=4)
ent_minx.insert(0,-m)
ent_minx.place(x=10,y=250)
#
ent_maxx=Entry(root,
               width=4)
ent_maxx.insert(0,m)
ent_maxx.place(x=460,y=250)
#
ent_miny=Entry(root,
               width=4)
ent_miny.insert(0,-m)
ent_miny.place(x=250,y=460)
#
ent_maxy=Entry(root,
               width=4)
ent_maxy.insert(0,m)
ent_maxy.place(x=250,y=25)
#
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

def move_l(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x
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
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST,fill='gray50')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    line3d(0,0,miny,0,0,maxy,None,'gray50',LAST)
    line3d(10+x,0,0,5+x,0,10)
    line3d(5+x,0,10,-5+x,0,10)
    line3d(-5+x,0,10,-10+x,0,0)
    line3d(-10+x,0,0,-5+x,0,-10)
    line3d(-5+x,0,-10,5+x,0,-10)
    line3d(5+x,0,-10,10+x,0,0)
    line3d(10+x,10,0,5+x,10,10)
    line3d(5+x,10,10,-5+x,10,10)
    line3d(-5+x,10,10,-10+x,10,0)
    line3d(-10+x,10,0,-5+x,10,-10)
    line3d(-5+x,10,-10,5+x,10,-10)
    line3d(5+x,10,-10,10+x,10,0)
    line3d(10+x,0,0,10+x,10,0)
    line3d(5+x,0,10,5+x,10,10)
    line3d(-5+x,0,10,-5+x,10,10)
    line3d(-10+x,0,0,-10+x,10,0,)
    line3d(-5+x,0,-10,-5+x,10,-10)
    line3d(5+x,0,-10,5+x,10,-10)
    root.update()
    x-=vx
    if x<=-80:x=80

def move_r(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x
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
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST,fill='gray50')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    line3d(0,0,miny,0,0,maxy,None,'gray50',LAST)
    line3d(10+x,0,0,5+x,0,10)
    line3d(5+x,0,10,-5+x,0,10)
    line3d(-5+x,0,10,-10+x,0,0)
    line3d(-10+x,0,0,-5+x,0,-10)
    line3d(-5+x,0,-10,5+x,0,-10)
    line3d(5+x,0,-10,10+x,0,0)
    line3d(10+x,10,0,5+x,10,10)
    line3d(5+x,10,10,-5+x,10,10)
    line3d(-5+x,10,10,-10+x,10,0)
    line3d(-10+x,10,0,-5+x,10,-10)
    line3d(-5+x,10,-10,5+x,10,-10)
    line3d(5+x,10,-10,10+x,10,0)
    line3d(10+x,0,0,10+x,10,0)
    line3d(5+x,0,10,5+x,10,10)
    line3d(-5+x,0,10,-5+x,10,10)
    line3d(-10+x,0,0,-10+x,10,0,)
    line3d(-5+x,0,-10,-5+x,10,-10)
    line3d(5+x,0,-10,5+x,10,-10)
    root.update()
    x+=vx
    if x>=80:x=-80
    
def move_u(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x
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
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST,fill='gray50')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    line3d(0,0,miny,0,0,maxy,None,'gray50',LAST)
    line3d(10+x,0,0,5+x,0,10)
    line3d(5+x,0,10,-5+x,0,10)
    line3d(-5+x,0,10,-10+x,0,0)
    line3d(-10+x,0,0,-5+x,0,-10)
    line3d(-5+x,0,-10,5+x,0,-10)
    line3d(5+x,0,-10,10+x,0,0)
    line3d(10+x,10,0,5+x,10,10)
    line3d(5+x,10,10,-5+x,10,10)
    line3d(-5+x,10,10,-10+x,10,0)
    line3d(-10+x,10,0,-5+x,10,-10)
    line3d(-5+x,10,-10,5+x,10,-10)
    line3d(5+x,10,-10,10+x,10,0)
    line3d(10+x,0,0,10+x,10,0)
    line3d(5+x,0,10,5+x,10,10)
    line3d(-5+x,0,10,-5+x,10,10)
    line3d(-10+x,0,0,-10+x,10,0,)
    line3d(-5+x,0,-10,-5+x,10,-10)
    line3d(5+x,0,-10,5+x,10,-10)
    root.update()
    c-=0.1
    ent_c.delete(0,END)
    ent_c.insert(0,c)

def move_d(event):
    global minx,miny,maxx,maxy,mx,my,a,b,c,alpha,x
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
    alpha=60+(80-x)/160*60
    canv.delete(ALL)
    canv.create_line(p(0,maxy),p(0,miny),arrow=FIRST,fill='gray50')
    canv.create_line(px(minx),py(0),px(maxx),py(0),arrow=LAST,fill='gray50')
    line3d(0,0,miny,0,0,maxy,None,'gray50',LAST)
    line3d(10+x,0,0,5+x,0,10)
    line3d(5+x,0,10,-5+x,0,10)
    line3d(-5+x,0,10,-10+x,0,0)
    line3d(-10+x,0,0,-5+x,0,-10)
    line3d(-5+x,0,-10,5+x,0,-10)
    line3d(5+x,0,-10,10+x,0,0)
    line3d(10+x,10,0,5+x,10,10)
    line3d(5+x,10,10,-5+x,10,10)
    line3d(-5+x,10,10,-10+x,10,0)
    line3d(-10+x,10,0,-5+x,10,-10)
    line3d(-5+x,10,-10,5+x,10,-10)
    line3d(5+x,10,-10,10+x,10,0)
    line3d(10+x,0,0,10+x,10,0)
    line3d(5+x,0,10,5+x,10,10)
    line3d(-5+x,0,10,-5+x,10,10)
    line3d(-10+x,0,0,-10+x,10,0,)
    line3d(-5+x,0,-10,-5+x,10,-10)
    line3d(5+x,0,-10,5+x,10,-10)
    root.update()
    c+=0.1
    ent_c.delete(0,END)
    ent_c.insert(0,c)

def move_dr():
    move_d()
    move_r()

def move_dl():
    move_d()
    move_l()

def move_ur():
    move_u()
    move_r()

def move_ul():
    move_u()
    move_l()

#кнопкi
but=Button(root,text='график',command=move_l)
but.place(x=460,y=20)

root.bind('<Left>',move_l)
root.bind('<Right>',move_r)
root.bind('<Up>',move_u)
root.bind('<Down>',move_d)

root.bind('<Down>-<Right>',move_dr)
root.bind('<Down>-<Leftt>',move_dl)
root.bind('<Up>-<Right>',move_ur)
root.bind('<Up>-<Left>',move_ul)

root.mainloop()
