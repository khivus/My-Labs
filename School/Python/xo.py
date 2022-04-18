from tkinter import *
from math import *

root=Tk()
root.title('Крестики - Нолики')
root.geometry('400x400+100+100')

count=0

def restart():
    global count
    count=0
    but_restart.place_forget()
    lbl['text']=''
    but_a1['state']='normal'
    but_a2['state']='normal'
    but_a3['state']='normal'
    but_b1['state']='normal'
    but_b2['state']='normal'
    but_b3['state']='normal'
    but_c1['state']='normal'
    but_c2['state']='normal'
    but_c3['state']='normal'
    but_a1['text']=''
    but_a2['text']=''
    but_a3['text']=''
    but_b1['text']=''
    but_b2['text']=''
    but_b3['text']=''
    but_c1['text']=''
    but_c2['text']=''
    but_c3['text']=''

def winner(x):
    if (but_a1['text'] == but_a2['text'] == but_a3['text'] == x) or (but_b1['text'] == but_b2['text'] == but_b3['text'] == x) or (but_c1['text'] == but_c2['text'] == but_c3['text'] == x) or (but_a1['text'] == but_b1['text'] == but_c1['text'] == x) or (but_a2['text'] == but_b2['text'] == but_c2['text'] == x) or (but_a3['text'] == but_b3['text'] == but_c3['text'] == x) or (but_a1['text'] == but_b2['text'] == but_c3['text'] == x) or (but_a3['text'] == but_b2['text'] == but_c1['text'] == x):
        lbl['text']=x,'Выиграли \nИгра окончена'
        but_restart.place(x=100,y=320)
        disable_buttons()

def res():
    global count
    winner('X')
    winner('O')
    if count==9:
        disable_buttons()
        lbl['text']='Игра окнчена \nНикто не выиграл'
        but_restart.place(x=100,y=320)

def disable_buttons():
    but_a1['state']='disabled'
    but_a2['state']='disabled'
    but_a3['state']='disabled'
    but_b1['state']='disabled'
    but_b2['state']='disabled'
    but_b3['state']='disabled'
    but_c1['state']='disabled'
    but_c2['state']='disabled'
    but_c3['state']='disabled'

def clk_a1():
    if but_a1['text']=='':
        global count
        count+=1
        if count%2==1:  but_a1['text']='X'
        else:   but_a1['text']='O'
        res()

def clk_a2():
    if but_a2['text']=='':
        global count
        count+=1
        if count%2==1:  but_a2['text']='X'
        else:   but_a2['text']='O'
        res()

def clk_a3():
    if but_a3['text']=='':
        global count
        count+=1
        if count%2==1:  but_a3['text']='X'
        else:   but_a3['text']='O'
        res()

def clk_b1():
    if but_b1['text']=='':
        global count
        count+=1
        if count%2==1:  but_b1['text']='X'
        else:   but_b1['text']='O'
        res()

def clk_b2():
    if but_b2['text']=='':
        global count
        count+=1
        if count%2==1:  but_b2['text']='X'
        else:   but_b2['text']='O'
        res()

def clk_b3():
    if but_b3['text']=='':
        global count
        count+=1
        if count%2==1:  but_b3['text']='X'
        else:   but_b3['text']='O'
        res()

def clk_c1():
    if but_c1['text']=='':
        global count
        count+=1
        if count%2==1:  but_c1['text']='X'
        else:   but_c1['text']='O'
        res()

def clk_c2():
    if but_c2['text']=='':
        global count
        count+=1
        if count%2==1:  but_c2['text']='X'
        else:   but_c2['text']='O'
        res()

def clk_c3():
    if but_c3['text']=='':
        global count
        count+=1
        if count%2==1:  but_c3['text']='X'
        else:   but_c3['text']='O'
        res()

but_a1=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_a1)
but_a1.place(x=10,y=10)

but_a2=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_a2)
but_a2.place(x=100,y=10)

but_a3=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_a3)
but_a3.place(x=190,y=10)

but_b1=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_b1)
but_b1.place(x=10,y=100)

but_b2=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_b2)
but_b2.place(x=100,y=100)

but_b3=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_b3)
but_b3.place(x=190,y=100)

but_c1=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_c1)
but_c1.place(x=10,y=190)

but_c2=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_c2)
but_c2.place(x=100,y=190)

but_c3=Button(root,text='',font='Arial 30',width=3,height=1,command=clk_c3)
but_c3.place(x=190,y=190)

lbl=Label(root)
lbl.place(x=100,y=280)

but_restart=Button(root,text='Начать заново',command=restart)

root.mainloop()