'''Copyright Aleksey inc. 2003-2021 all rights reserved©
@khivus'''

from math import *
from tkinter import *

root=Tk()
root.title('Nice cock!')
root.geometry('400x300+200+100')
root.config(background='gray20')

canv=Canvas(root,width=200,heigh=200,bg='black')
canv.place(x=10,y=10)

a=5
b=3
c=4
cx=200
cy=200
mx=1
my=1
minx=0
maxx=1
miny=0
maxy=1

ent_a=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_a=Label(root,text='Сторона a',background='gray20',foreground='lightblue')
ent_a.place(x=10,y=245)
lbl_a.place(x=10,y=220)

ent_b=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_b=Label(root,text='Сторона b',background='gray20',foreground='lightblue')
ent_b.place(x=80,y=245)
lbl_b.place(x=80,y=220)

ent_c=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_c=Label(root,text='Сторона c',background='gray20',foreground='lightblue')
ent_c.place(x=150,y=245)
lbl_c.place(x=150,y=220)

ent_s=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_s=Label(root,text='S =',background='gray20',foreground='lightblue')
ent_s.place(x=245,y=50)
lbl_s.place(x=220,y=50)

ent_p=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_p=Label(root,text='P =',background='gray20',foreground='lightblue')
ent_p.place(x=245,y=80)
lbl_p.place(x=220,y=80)

ent_alpha=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_alpha=Label(root,text='sin(alpha) =',background='gray20',foreground='lightblue')
ent_alpha.place(x=290,y=110)
lbl_alpha.place(x=220,y=110)

ent_beta=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_beta=Label(root,text='sin(beta) =',background='gray20',foreground='lightblue')
ent_beta.place(x=290,y=140)
lbl_beta.place(x=220,y=140)

ent_gamma=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_gamma=Label(root,text='sin(gamma) =',background='gray20',foreground='lightblue')
ent_gamma.place(x=300,y=170)
lbl_gamma.place(x=220,y=170)

ent_r=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_r=Label(root,text='r =',background='gray20',foreground='lightblue')
ent_r.place(x=245,y=200)
lbl_r.place(x=220,y=200)

ent_R=Entry(root,width=10,background='gray20',foreground='lightblue')
lbl_R=Label(root,text='R =',background='gray20',foreground='lightblue')
ent_R.place(x=245,y=230)
lbl_R.place(x=220,y=230)

ent_a.insert(0,5)
ent_b.insert(0,3)
ent_c.insert(0,4)

def px(x):
    mx=cx/(maxx-minx)
    px=x*mx-minx*mx
    return px+6

def py(y):
    my=cy/(maxy-miny)
    py=cy-(y*my-miny*my)
    return py-101

def сbt():
    global a,b,c,maxx,maxy
    canv.delete(ALL)
    a1=float(ent_a.get() if ent_a.get()!='' else 5)
    b1=float(ent_b.get() if ent_b.get()!='' else 3)
    c1=float(ent_c.get() if ent_c.get()!='' else 4)
    a=max(a1,b1,c1)
    c=min(a1,b1,c1)
    if c<a1<a:
        b=a1
    elif c<b1<a:
        b=b1
    elif c<c1<a:
        b=c1
    elif a1==b1==c1:
        b=a
    canv.create_line(5,200,5,0,arrow=LAST,fill='white')
    canv.create_line(0,100,200,100,arrow=LAST,fill='white')
    p=(a+b+c)/2
    P=p*2
    S=sqrt(p*(p-a)*(p-b)*(p-c))
    h=(2*S)/a
    alpha=(2*S)/(a*b)
    beta=(2*S)/(a*c)
    gamma=(2*S)/(b*c)
    r=S*2/P
    ah=sqrt(c**2-h**2)
    R=(a*b*c)/(4*S)
    maxx=a+5
    maxy=a+5
    betas=asin(beta)/2
    ao=r/sin(betas)
    x=sqrt(ao**2-r**2)
    y0=sqrt(R**2-(a/2)**2)
    if (asin(alpha)*57.2958)+(asin(beta)*57.2958)<90: canv.create_oval(px(a/2-R),py(-y0-R),px(a/2+R),py(-y0+R),outline='pink')
    else: canv.create_oval(px(a/2-R),py(y0-R),px(a/2+R),py(y0+R),outline='pink')
    canv.create_line(px(0),py(0),px(a),py(0),fill='green')
    canv.create_line(px(0),py(0),px(ah),py(h),fill='green')
    canv.create_line(px(a),py(0),px(ah),py(h),fill='green')
    canv.create_oval(px(x-r),py(0),px(x+r),py(2*r),outline='red')
    ent_s.delete(0,END)
    ent_s.insert(0,S)
    ent_alpha.delete(0,END)
    ent_alpha.insert(0,alpha)
    ent_beta.delete(0,END)
    ent_beta.insert(0,beta)
    ent_gamma.delete(0,END)
    ent_gamma.insert(0,gamma)
    ent_p.delete(0,END)
    ent_p.insert(0,p*2)
    ent_r.delete(0,END)
    ent_r.insert(0,r)
    ent_R.delete(0,END)
    ent_R.insert(0,R)

but_main=Button(root,text='Button',command=сbt,activebackground='pink',bg='black',fg='white',activeforeground='black')
but_main.place(x=220,y=10)

root.mainloop()
