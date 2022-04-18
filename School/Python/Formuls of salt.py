from tkinter import *

root=Tk()
root.title('Formuls of salt')
root.geometry('600x600+200+200')

kos=['хлорид','бромид','иодид','нитрат','нитрит','перхлорат',
     'сульфид','сульфит','сульфат','карбонат','силикат','хромат','фосфат']
mes=['лития','натрия','калия','серебра',
     'Берилия','магния','кальция','меди (II)','цинка','железа (II)','хрома (II)',
     'алюминия','железа (III)','хрома (III)']

def valme(val):
    if val<=5:
        val=1
        return val
    elif 5<val<12:
        val=2
        return val
    elif val>11:
        val=3
        return val

def valko(val):
    if val<=3:
        val=1
        return val
    elif 3<val<11:
        val=2
        return val
    elif val>10:
        val=3
        return val

def salt():
    vm=1
    vo=1
    if lst_me.curselection()!=() and lst_ko.curselection()!=():
        me=lst_me.get(lst_me.curselection())
        ko=lst_ko.get(lst_ko.curselection())
        mev=int(lst_me.curselection()[0])
        kov=int(lst_ko.curselection()[0])
    val_me=valme(mev)
    val_ko=valko(kov)
    if val_me==2: val_me='₂'
    elif val_me==3: val_me='₃'
    if val_ko==2: val_ko='₂'
    elif val_ko==3: val_ko='₃'
    if val_me!=1 and val_ko!=1: lbl_f['text']=me , val_ko , '(' , ko , ')' , val_me
    elif val_me==val_ko: lbl_f['text']=me , ko
    elif val_ko==1: lbl_f['text']=me , '(' , ko , ')' , val_me
    else: lbl_f['text']=me , val_ko , ko
    lbl_f1['text']='Соль: '+kos[kov]+' '+mes[mev]

lst_me=Listbox(root,width=10,height=14,selectmode=SINGLE,exportselection=0)
lst_me.insert(END,'Li','Na','K',
              'Ag','Be','Mg',
              'Ca','Cu','Zn',
              'Fe(II)','Cr(II)',
              'Al','Fe(III)','Cr(III)')
lst_me.place(x=10,y=10)
lbl_me=Label(root,text='Металлы')
lbl_me.place(x=10,y=240)

lst_ko=Listbox(root,width=10,height=14,selectmode=SINGLE,exportselection=0)
lst_ko.insert(END,'Cl','Br','I',
              'NO₃','NO₂','ClO₄',
              'S','SO₃','SO₄',
              'CO₃','SiO₃','CrO₄',
              'PO₄')
lst_ko.place(x=100,y=10)
lbl_ko=Label(root,text='Кислотные \nостатки')
lbl_ko.place(x=97,y=240)

lbl_f=Label(root,font='areal 30')
lbl_f.place(x=200,y=10)

lbl_f1=Label(root,font='areal 10')
lbl_f1.place(x=200,y=75)

but_res=Button(root,text='Salty',command=salt,width=21)
but_res.place(x=10,y=280)

root.mainloop()
