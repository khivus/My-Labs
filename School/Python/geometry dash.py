from tkinter import *
from math import *
from random import *

root=Tk()
root.title('Geometry Dash')
root.geometry('610x610+100+100')

cx=600
cy=600
minx=0
maxx=600
miny=-100
maxy=500
mx=1
my=1
hy=20
xwall=20
ywall=20
xs=600
death=0

img=PhotoImage(file='drip.png')

canv=Canvas(root,width=cx,height=cy,bg='white')
canv.place(x=5,y=5)

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

def restart():
    global death, hy, xs
    death=0
    hy=20
    xs=600
    main()
    but_restart.place_forget()

canv.create_image(px(330),py(hy),image=img,tag='hero')
canv.create_line(px(0),py(3),px(600),py(3))
canv.create_rectangle(px(xs),py(4),px(xs+xwall),py(4+ywall),tag='wall')

def main():
    global xs, death
    xs-=2
    canv.delete('wall')
    canv.create_rectangle(px(xs),py(4),px(xs+xwall),py(4+ywall),tag='wall')
    if xs<=-20:
        xs=600+randint(0,50)
    if xs<=306 and xs>=284 and hy-20<=4+ywall:
        death=1
    if death==0:
        root.after(9,main)
    elif death==1:
        but_restart.place(x=280,y=10)

but_restart=Button(root,command=restart,text='Restart')

def jump(event):
    global hy
    a=0
    while not a>=pi:
        canv.delete('hero')
        a+=0.01
        hy=sin(a)*40+20
        canv.create_image(px(330),py(hy),image=img,tag='hero')
        for i in range(50000):
            pass
        root.update()  

main()
root.bind('<space>',jump)

root.mainloop()
