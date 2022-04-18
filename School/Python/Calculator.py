from tkinter import *
from tkinter import messagebox
from tkinter import ttk
from math import sqrt
import math

root = Tk()
root.title('Каркулятор')
root.config(bg='black')
# логика калькулятора
def calc(key):
    global memory
    if key == '=':
# исключаем написание букв
        str1 = '+0123456789.*/'
        if calc_entry.get()[0] not in str1:
            calc_entry.insert(END, 'Первый символ не число')
            messagebox.showerror('Ошибка!', 'Вы ввели не число.')
# счёт
        try:
            result = eval(calc_entry.get())
            calc_entry.insert(END, '=' + str(result))
        except:
            calc_entry.insert(END, 'Ошибка!')
            messagebox.showerror('Ошибка!', 'Проверь правильность данных!')
# очистить поле
    elif key == 'C':
        calc_entry.delete(0, END)
#возведение в квадрат
    elif key == 'x²':
        calc_entry.insert(END, '**2')
#квадратный корень
    elif key == '√x':
        calc_entry.insert(END, '**0.5')
#+/-
    elif key == "+/-":
        if '=' in calc_entry.get():

            calc_entry.delete(0, END)
        try:
            if calc_entry.get()[0] == '-':
                calc_entry.delete(0)
            else:
                calc_entry.insert(0, '-')
        except IndexError:
            pass
#Mod
    elif key == "Mod":
        calc_entry.insert(END, "%")
#n!
    elif key == "n!":
        a = int(calc_entry.get())
        calc_entry.delete(0,END)
        for i in range (1,a+1):
            calc_entry.insert(END, i)
            calc_entry.insert(END, "*")
            if i == a:
                calc_entry.delete(a*2-1, END)
#x**3
    elif key == "x³":
        calc_entry.insert(END, "**3")
#x**y
    elif key == "x**y":
        calc_entry.insert(END, "**")
#log
    elif key == "Lg":
        x = int(calc_entry.get())
        y = int(math.log10(x))
        calc_entry.delete(0, END)
        calc_entry.insert(END, y)
#sin, cos, tg
    elif key == "sin":
        x = int(calc_entry.get())
        x = x / 57.2958
        y = math.sin(x)
        calc_entry.delete(0, END)
        calc_entry.insert(END, y)
    elif key == "cos":
        x = int(calc_entry.get())
        x = x / 57.2958
        y = math.cos(x)
        calc_entry.delete(0, END)
        calc_entry.insert(END, y)
    elif key == "tan":
        x = int(calc_entry.get())
        x = x / 57.2958
        y = math.tan(x)
        calc_entry.delete(0, END)
        calc_entry.insert(END, y)
#y√x
    elif key == "y√x":
        calc_entry.insert(END, "**(1/")
#∛x
    elif key == "∛x":
        calc_entry.insert(END, "**0.3")
#счёт опять
    else:
        if '=' in calc_entry.get():
            calc_entry.delete(0, END)
        calc_entry.insert(END, key)
# создаём все кнопки
bttn_list = [
    "(", ")", "", "", "", "",
    "sin"+', , "C", "+/-", "Mod", "/", "x²", 
    "cos", '7', '8', '9', '*', "x³", 
    "tan", '4', '5', '6', '-', "x**y",
    "y√x", '1', '2', '3', '"Lg", 
    "∛x", '√x', '0', '.', '=', "n!"
    ]
r = 1
c = 0

for i in bttn_list:
    rel = ''
    cmd=lambda x=i: calc(x)
    Button(root, text=i, bg='black', fg='white', activebackground='darkred', activeforeground='white', width=10, command=cmd).grid(row=r, column=c)
    c += 1
    if c>5:
        c=0
        r += 1

calc_entry = Entry(root, width=79, bg='black', fg='white')
calc_entry.grid(row=0, column=0, columnspan=6)

root.mainloop()