from math import*
from tkinter import*

def brosok():
    g=9.81
    v0=float(ent_v0.get())
    a=float(ent_a.get())
    l=float(ent_l.get())
    h=float(ent_h.get())
    y=l*tan(radians(a))-g*l**2/(2*v0**2*cos(radians(a))**2)
    ent_y.delete(0,END)
    ent_y.insert(0,y)
    ent_res.delete(0,END)
    if y>h:
        ent_res.insert(0,'перелёт')
    elif y<0:
        ent_res.insert(0,'недолёт')
    else:
        ent_res.insert(0,'попадание')
    canv.delete(ALL)
    canv.create_line(0,390,
                     400,390,
                     arrow=LAST)
    canv.create_line(10,400,
                     10,0,
                     arrow=LAST)
    for x in range(390,10,-10):
            canv.create_line(x,388,
                         x,392)
    for y in range(10,390,10):
        canv.create_line([8,y],[12,y])
    t=0
    while not t>=4:
        x=v0*cos(radians(a))*t
        y=v0*sin(radians(a))*t-(g*t**2)/2
        xp=x*10+10
        yp=400-(y*10+10)
        canv.create_line(xp,yp,xp+1,yp+1,fill='purple')
        t+=0.001
    lp=l*10+10
    hp=390-(h*10)
    canv.create_line(lp,390,lp,hp,lp+5,hp,lp+5,390)
root=Tk()
root.geometry('600x600')
root.title('Бросок мяча')

ent_v0=Entry(root,width=5)
ent_v0.place(x=10,y=10)
ent_v0.insert(0,'18')
lbl_v0=Label(root,text='Vo')
lbl_v0.place(x=10,y=30)

ent_a=Entry(root,width=5)
ent_a.place(x=55,y=10)
ent_a.insert(0,'30')
lbl_a=Label(root,text='α')
lbl_a.place(x=55,y=30)

ent_l=Entry(root,width=5)
ent_l.place(x=100,y=10)
ent_l.insert(0,'30')
lbl_l=Label(root,text='l')
lbl_l.place(x=100,y=30)

ent_h=Entry(root,width=5)
ent_h.place(x=145,y=10)
ent_h.insert(0,'1')
lbl_h=Label(root,text='h')
lbl_h.place(x=145,y=30)

ent_y=Entry(root,width=5)
ent_y.place(x=10,y=55)
lbl_y=Label(root,text='y')
lbl_y.place(x=10,y=75)

ent_res=Entry(root,width=20)
ent_res.place(x=55,y=55)
lbl_res=Label(root,text='Результат')
lbl_res.place(x=55,y=75)

but_1=Button(text='Выполнить',
             command=brosok)
but_1.place(x=10,y=100)

canv=Canvas(root,
            width=400,
            height=400,
            bg='white')
canv.place(x=185,y=8)

root.mainloop()
