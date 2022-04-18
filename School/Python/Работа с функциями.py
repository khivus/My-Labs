from tkinter import *
from math import *
#функции

def fact (x):
    x=int(x)
    p=1
    for i  in range (1,x+1):
        p*=i
    return p
#функция которая проверят, является ли число простым.
def prostoe (x):
    x=int(x)
    k=0
    for i in range (2,x):
        if x%i==0:
            k+=1
    if k!=0:
        return False
    else:
        return True

def NOK (x,y):
    m=max(x,y)
    i=m
    while not (i%x==0 and i%y==0):
        i+=1
    return i

#процедуры
def clk_fact():
    a=int(ent_a.get() if ent_a.get() !='' else '0')
    result=fact(a)
    ent_result.delete(0,END)
    ent_result.insert(0,result)

def clk_prostoe():
    a=int(ent_a.get() if ent_a.get() !='' else '0')
    b=int(ent_a.get() if ent_a.get() !='' else '0')
    for i in range (a, b+1):
        if prostoe(i):
            ent_result.insert(END,i)
            ent_result.insert(END, " ")

def clk_nok():
    a=int(ent_a.get() if ent_a.get() !='' else '0')
    b=int(ent_a.get() if ent_a.get() !='' else '0')
    res=NOK(a,b)
    ent_result.delete(0,END)
    ent_result.insert(END, res)



root=Tk()
root.title('Калькулятор')
root.geometry('450x400')

#a
ent_a=Entry(root,width=10)
ent_a.grid(row=0,column=0, padx=5, pady=5)
lbl_a=Label(root,text='a')
lbl_a.grid(row=1,column=0, padx=5, pady=5)

#b
ent_b=Entry(root,width=10)
ent_b.grid(row=0,column=1, padx=5, pady=5)
lbl_b=Label(root,text='b')
lbl_b.grid(row=1,column=1, padx=5, pady=5)

#result
ent_result=Entry(root,width=45)
ent_result.grid(row=0,column=2, padx=5, pady=5)
lbl_result=Label(root,text='Результат')
lbl_result.grid(row=1,column=2, padx=5, pady=5)

#plus
plus=Button(root,text='fact(a)',
           command=clk_fact)
plus.grid(row=3,column=0, pady=5)

#minus
minus=Button(root,text='Prime',
           command=clk_prostoe)
minus.grid(row=3,column=1, pady=5)

#NOK
nok=Button(root,text='nok',
           command=clk_nok)
nok.grid(row=4,column=0, pady=5)

root.mainloop() 