from tkinter import *
from why import questions

root=Tk()
root.title('Тест')
#root.geometry('900x300+250+100')

c=0 #счётчик
n=15 #кол-во вопросов
p=0 #правильные ответы
q=questions

#windows

lbl=Label(root,text='Тест по мотематеке',width=140,heigh=5,font='areal 10')
lbl.pack()

rbt=IntVar()
rbt.set(0)
rbt1=Radiobutton(root,width=150,heigh=2,variable=rbt,value=1,anchor=W)
rbt2=Radiobutton(root,width=150,heigh=2,variable=rbt,value=2,anchor=W)
rbt3=Radiobutton(root,width=150,heigh=2,variable=rbt,value=3,anchor=W)
rbt4=Radiobutton(root,width=150,heigh=2,variable=rbt,value=4,anchor=W)

def jk():
    global c,p
    if rbt.get()>0 or c==0:
        if c==0:
            rbt1.pack()
            rbt2.pack()
            rbt3.pack()
            rbt4.pack()
            but['text']='Следующий вопрос'
            lbl['text']=q[c][0]
            rbt1['text']=q[c][1]
            rbt2['text']=q[c][2]
            rbt3['text']=q[c][3]
            rbt4['text']=q[c][4]
        if n>c>0:
            if rbt.get()==q[c-1][5]: p+=1
            lbl['text']=q[c][0]
            rbt1['text']=q[c][1]
            rbt2['text']=q[c][2]
            rbt3['text']=q[c][3]
            rbt4['text']=q[c][4]
            if c==n-1:
                but['text']='Проверить ответы'            
        if c==n:
            if rbt.get()==q[c-1][5]: p+=1
            if p/n<0.5: mark='2'
            elif 0.5<=p/n<0.75: mark='3'
            elif 0.75<=p/n<0.9: mark='4'
            elif p/n>=0.9: mark='5'
            else: 
                lbl['text']='Something went wrong \nPlease restart programm'
                but['state']='disabled'
                rbt1.pack_forget()
                rbt2.pack_forget()
                rbt3.pack_forget()
                rbt4.pack_forget()
                return
            lbl['text']='Вы ответили на '+str(p)+' вопросов из '+str(n)+'\nВаша оценка: '+str(mark)
            but['state']='disabled' #выключение кнопки
            rbt1.pack_forget()
            rbt2.pack_forget()
            rbt3.pack_forget()
            rbt4.pack_forget()
        rbt.set(0)
        c+=1

but=Button(root,text='Решить!',command=jk,width=20,heigh=3)
but.pack()

root.mainloop()
