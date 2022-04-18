from tkinter import *
def clk_but():
    lbl_text['bg']='sea green'
    ent_text.delete(0,END)
    ent_text.insert(0,'СМЭРТ')
    
root=Tk()
root.title('графический интерфейс')
root.geometry('350x400')
lbl_text=Label(root,
               text='Мой грандиозный проект!',
               width=22,
               height=3,
               bg='hot pink',
               fg='spring green2')
lbl_text.pack()

ent_text=Entry(root,
               width=20)
ent_text.pack()
ent_text.insert(0,'Мой последний проект!')


but=Button(root,text='move',command=clk_but)
but.pack()



root.mainloop()
