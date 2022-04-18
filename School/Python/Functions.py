from tkinter import *
from math import *
# функции
def NOD(x,y):
    m=min(x,y)
    i=m
    while not (x%i==0 and y%i==0):
        i-=1
    return i

def split(x,y):
    nod=NOD(x,y)
    x1=x/nod
    y1=y/nod
    m=max(x1,y1)
    m1=min(x1,y1)
    m=str(m)
    m1=str(m1)
    r=m+'/'+m1
    return r

def perfect_number(x):
    s=0
    for i in range(1,x):
        if x%i==0:
            s+=i
    if x==s:
        return True

#процедуры
def clk_but_NOD():
    a=int(ent_a.get() if ent_a.get()!='' else '0')
    b=int(ent_b.get() if ent_b.get()!='' else '0')
    res=NOD(a,b)
    ent_res.delete(0,END)
    ent_res.insert(0,res)

def clk_but_split():
    a=int(ent_a.get() if ent_a.get()!='' else '0')
    b=int(ent_b.get() if ent_b.get()!='' else '0')
    res=split(a,b)
    ent_res.delete(0,END)
    ent_res.insert(0,res)

def clk_but_perf():
    a=int(ent_a.get() if ent_a.get()!='' else '0')
    b=int(ent_b.get() if ent_b.get()!='' else '0')
    ent_res.delete(0,END)
    for i in range(a,b+1):
        if perfect_number(i):
            ent_res.insert(END,i)
            ent_res.insert(END,', ')

#интерфейс
root=Tk()
root.title('функции')
root.geometry('600x400')

#окна
ent_a=Entry(root,width=20)
ent_a.place(x=10,y=10)
lbl_a=Label(root,text='a')
lbl_a.place(x=10,y=30)

ent_b=Entry(root,width=20)
ent_b.place(x=150,y=10)
lbl_b=Label(root,text='b')
lbl_b.place(x=150,y=30)

ent_res=Entry(root,width=40)
ent_res.place(x=290,y=10)
lbl_res=Label(root,text='результат')
lbl_res.place(x=290,y=30)

#конпки
but_NOD=Button(root,
                text='НОД',
                width=5,
                command=clk_but_NOD)
but_NOD.place(x=10,y=50)

but_split=Button(root,
                text='a/b',
                width=5,
                command=clk_but_split)
but_split.place(x=60,y=50)


but_perf=Button(root,
                text='Совершенное',
                width=12,
                command=clk_but_perf)
but_perf.place(x=10,y=80)

root.mainloop()