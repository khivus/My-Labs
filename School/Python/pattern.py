from tkinter import *
from math import *

def sx(coord):
  mcoord = cx / (xmax-xmin)
  pcoord = coord*mcoord - xmin*mcoord
  return int(pcoord)

def sy(coord):
  mcoord = cy / (ymax-ymin)
  pcoord = cy - (coord*mcoord - ymin*mcoord)
  return int(pcoord)

left_pos = 0
right_pos = 0
mid_pos = 0

def define(left_pos, right_pos):
  global lbl_res
  grapf = ent_grapf.get().replace("x", "mid_pos")
  mid_pos = (left_pos + right_pos) / 2
  if eval(ent_grapf.get().replace("x", "left_pos")) * eval(ent_grapf.get().replace("x", "mid_pos")) < 0: right_pos = mid_pos
  else: left_pos = mid_pos
  if not (right_pos - left_pos) / 2 < 10**-6: define(left_pos, right_pos)
  else:
    lbl_res['text'] = str((right_pos + left_pos) / 2) + " ± погрешность"
    ent_xmax.delete(0, END)
    ent_xmin.delete(0, END)
    ent_xmax.insert(0, str(right_pos))
    ent_xmin.insert(0, str(left_pos))
    ent_ymax.delete(0, END)
    ent_ymin.delete(0, END)
    ent_ymax.insert(0, str(round(eval(ent_grapf.get().replace("x", "right_pos")), 7)))
    ent_ymin.insert(0, str(round(eval(ent_grapf.get().replace("x", "left_pos")), 7)))

def result():
  global xmax, xmin, ymax, ymin
  xmax = float(ent_xmax.get() if ent_xmax.get() != "" else -1)
  ymax = float(ent_ymax.get() if ent_ymax.get() != "" else -1)
  xmin = float(ent_xmin.get() if ent_xmin.get() != "" else 1)
  ymin = float(ent_ymin.get() if ent_ymin.get() != "" else 1)
  n = float(ent_n.get() if ent_n.get() != "" else 1)
  grapf = ent_grapf.get()
  draw(grapf, [int(xmax), int(xmin), int(ymax), int(ymin), int(n)])

def draw(grapf, arr):
  canv.delete(ALL)
  canv.create_line(sx(arr[1]),sy(0),sx(arr[0]),sy(0),arrow=LAST,fill="gray50")
  canv.create_line(sx(0),sy(arr[3]),sx(0),sy(arr[2]),arrow=LAST,fill="gray50")
## Что в комментарии - для проекта, где нет масштабирования
##  for x in range(arr[1], arr[0]):
##    canv.create_line(sx(x), sy(0.1), sx(x), sy(-0.1))
##    canv.create_text(sx(x), sy(-0.25), text=str(x), font="ComicSans 8")
##  for y in range(arr[3], arr[2]):
##    canv.create_line(sx(0.1), sy(y), sx(-0.1), sy(y))
##    if y != 0: canv.create_text(sx(0.25), sy(y), text=str(y), font="ComicSans 8")
  x = arr[1]
  while not x >= arr[0]:
    y = eval(grapf)
    canv.create_line(sx(x),sy(y),sx(x)+1,sy(y)+1,fill="red")
    x += (arr[0] - arr[1]) / arr[4]
  root.update()

root = Tk()
root.title("Бросок Мяча")
root.geometry("650x650+0+0")
###
cx, cy = 400, 400
xmax, xmin = 1, -1
ymax, ymin = 1, -1
mx, my = 1, 1
###
canv = Canvas(root, bg='white', width=cx, height=cy)
canv.place(x=50, y=50)
###
ent_ymax = Entry(width=5)
ent_ymax.place(y=0, x= 50+cx//2)
ent_ymax.insert(0, "5")

ent_xmin = Entry(width=5)
ent_xmin.place(y=50+cy//2, x=0)
ent_xmin.insert(0, "-5")

ent_ymin = Entry(width=5)
ent_ymin.place(y=cy+50, x=50+cx//2)
ent_ymin.insert(0, "-5")


ent_xmax = Entry(width=5)
ent_xmax.place(y=50+cy//2, x=50+cx)
ent_xmax.insert(0, "5")

ent_n = Entry(width=10)
ent_n.place(y=cy//2, x=180+cx)
ent_n.insert(0, "1000")
lbl_n = Label(text="Плотность: ")
lbl_n.place(y=cy//2, x=100+cx)

ent_grapf = Entry(width=10)
ent_grapf.place(y=50+cy//2, x=180+cx)
ent_grapf.insert(0, "x**3-cos(x)")
lbl_grapf = Label(text="График: ")
lbl_grapf.place(y=50+cy//2, x=100+cx)

ent_right = Entry(width=10)
ent_right.place(y=150+cy//2, x=180+cx)
ent_right.insert(0, "1")
lbl_right = Label(text="Точка 2(b): ")
lbl_right.place(y=150+cy//2, x=100+cx)

ent_left = Entry(width=10)
ent_left.place(y=100+cy//2, x=180+cx)
ent_left.insert(0, "0")
lbl_right = Label(text="Точка 1(a): ")
lbl_right.place(y=100+cy//2, x=100+cx)

btn_res = Button(text="Построить", command=result)
btn_res.place(x=0, y=0)

lbl_res = Label()
lbl_res.place(x=cx-100, y=0)

com = lambda: define(float(ent_left.get() if ent_left.get() != "" else 1), float(ent_right.get() if ent_right.get() != "" else 1.5))

btn_def = Button(text="Определить", command=com)
btn_def.place(x=75, y=0)

root.mainloop()
