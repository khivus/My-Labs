from tkinter import *

d=0

def clk_but():
    
    a = int(ent_a.get())
    b = int(ent_b.get())
    c = int(ent_c.get())
    d = b**2-a*a*c
    if (d>0):
        x1 = (-b+d**0.5)/(2*a)
        x2 = (-b-d**0.5)/(2*a)
        ent_x1.delete(0,END)
        ent_x2.delete(0,END)
        ent_x1.insert(0,x1)
        ent_x2.insert(0,x2)
    elif(d==0):
        x1 = -b/(2*a)
        ent_x1.delete(0,END)
        ent_x2.delete(0,END)
        ent_x1.insert(0,x1)
        ent_x2.insert(0,x1)
    else:
        ent_x1.delete(0,END)

        ent_x1.insert(0,'Нет корней')

root=Tk()
root.title('Квадратное уравнение')
root.geometry('350x400')
lbl_text=Label(root,
               text='Решение ax**2+bx+c=0',
               width=20,
               height=3,
               bg='mediumpurple4',
               fg='spring green3')
lbl_text.pack()


ent_a=Entry(root,width=20)
ent_a.pack()
ent_a.insert(0,'')
lbl_a=Label(root,text='a')
lbl_a.pack()


ent_b=Entry(root,width=20)
ent_b.pack()
ent_b.insert(0,'')
lbl_b=Label(root,text='b')
lbl_b.pack()


ent_c=Entry(root,width=20)
ent_c.pack()
ent_c.insert(0,'')
lbl_c=Label(root,text='c')
lbl_c.pack()


but=Button(root,text='Решить',activebackground='darkred',activeforeground='white',command=clk_but)
but.pack()


ent_x1=Entry(root,width=20)
ent_x1.pack()
ent_x1.insert(0,'')
lbl_x1=Label(root,text='x1')
lbl_x1.pack()


ent_x2=Entry(root,width=20)
ent_x2.pack()
ent_x2.insert(0,'')
lbl_x2=Label(root,text='x2')
lbl_x2.pack()



root.mainloop()
