#imports
from tkinter import *
#процедуры
def clk_7 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'7')
def clk_8 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'8')
def clk_9 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'9')
def clk_change ():
    x=ent_res.get()
    if x[0]=='-':
        ent_res.delete(0,1)
    else:
        ent_res.insert(0,'-')
def clk_4 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'4')
def clk_5 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'5')
def clk_6 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'6')
def clk_C ():
    ent_res.delete(0,END)
    ent_res.insert(END,'0')
    global res
    res=0
def clk_1 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'1')
def clk_2 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'2')
def clk_3 ():
    if ent_res.get()=='0':
        ent_res.delete(0,END)
    ent_res.insert(END,'3')
def clk_res ():
    global res
    if res == 1:
        x = str(ent_res.get())
        while x[-1]=='0':
            x=x[0:-1]
        ent_res.delete(0,END)
        ent_res.insert(END,x)
        if ent_res.get()=='0.':
            ent_res.delete(0,END)
            ent_res.insert(END,'0')
            res=0
def clk_0 ():
    global res
    if res==1:
        ent_res.insert(END,'0')
def clk_point ():
    global res
    if res==0:
        res+=1
        ent_res.insert(END,'.')
#interface
root=Tk()
root.title('Каркулятор V2.0')
root.geometry('230x290')
#result
ent_res=Entry(root,width=40)
ent_res.grid(row=0,column=0,columnspan=4)
ent_res.insert(END,'0')
res=0
#buttons
#7
bt_7=Button(root,text='7',width=4,command=clk_7)
bt_7.grid(row=1,column=0,padx=1,pady=1)
#8
bt_7=Button(root,text='8',width=4,command=clk_8)
bt_7.grid(row=1,column=1,padx=1,pady=1)
#9
bt_9=Button(root,text='9',width=4,command=clk_9)
bt_9.grid(row=1,column=2,padx=1,pady=1)
#C
bt_C=Button(root,text='C',width=4,command=clk_C)
bt_C.grid(row=1,column=3,padx=1,pady=1)
#4
bt_4=Button(root,text='4',width=4,command=clk_4)
bt_4.grid(row=2,column=0,padx=1,pady=1)
#5
bt_5=Button(root,text='5',width=4,command=clk_5)
bt_5.grid(row=2,column=1,padx=1,pady=1)
#6
bt_6=Button(root,text='6',width=4,command=clk_6)
bt_6.grid(row=2,column=2,padx=1,pady=1)
#+/-
bt_change=Button(root,text='+/-',width=4,command=clk_change)
bt_change.grid(row=2,column=3,padx=1,pady=1)
#1
bt_1=Button(root,text='1',width=4,command=clk_1)
bt_1.grid(row=3,column=0,padx=1,pady=1)
#2
bt_2=Button(root,text='2',width=4,command=clk_2)
bt_2.grid(row=3,column=1,padx=1,pady=1)
#3
bt_3=Button(root,text='3',width=4,command=clk_3)
bt_3.grid(row=3,column=2,padx=1,pady=1)
#=
bt_res=Button(root,text='=',width=4,command=clk_res)
bt_res.grid(row=3,column=3,padx=1,pady=1,rowspan=2)
#0
bt_0=Button(root,text='0',width=4,command=clk_0)
bt_0.grid(row=4,column=0,columnspan=2,padx=1,pady=1)
#.
bt_point=Button(root,text='.',width=4,command=clk_point)
bt_point.grid(row=4,column=2,padx=1,pady=1)
#END
root.mainloop()