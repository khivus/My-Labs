'''Copyright Aleksey inc. 2003-2020 all rights reserved©
vk.com/khivuss'''
from tkinter import *
#root
root=Tk()
root.title('h')
root.config(bg='gray75')
w=root.winfo_screenwidth()
h=root.winfo_screenheight()
w=(w//2)-100
h=(h//2)-100
root.geometry('200x75+{}+{}'.format(w, h))
#functions
def end():
    pass
def da1():
    ent_q.delete(0,END)
    ent_q.insert(0,'another question')
    but_y['command']=da2
    but_n['command']=no2
def no1():
    ent_q.delete(0,END)
    ent_q.insert(0,'another different question')
    but_y['command']=da3
    but_n['command']=no3
def da2():
    ent_q.delete(0,END)
    ent_q.insert(0,'otvet 1')
    but_y['command']=end
    but_n['command']=end
def no2():
    ent_q.delete(0,END)
    ent_q.insert(0,'otvet 2')
    but_y['command']=end
    but_n['command']=end
def da3():
    pass
def no3():
    pass
#windows
ent_q=Entry(root,width=30)
ent_q.place(x=10,y=10)
ent_q.insert(0,'lmao question, pls give ur answer')
#buttons
but_y=Button(root,text='Da',command=da1)
but_y.place(x=10,y=35)
but_n=Button(root,text='Net',command=no1)
but_n.place(x=40,y=35)
#happy end
root.mainloop()