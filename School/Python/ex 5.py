n,m=map(int,input().split())
k=[] #массив с камерами
for i in range (n):
    k.append(list(map(float,input().split()))) #list превращает в массив, append добавляет в массив
r=[]
for i in range (m):
    r.append(list(map(float,input().split())))
def f(x,y,x1,y1,x2,y2,x3,y3):
    if x1==x2:
        if x3>x1:
            if x>=x1:
                return True
            else:
                return False
        else:
            if x<=x1:
                return True
            else:
                return False
    else:
        k=(y1-y2)/(x1-x2)
        b=y1-k*x1
        if y3>k*x3+b:
            if y>=k*x+b:
                return True
            else:
                return False
        else:
            if y<=k*x+b:
                return True
            else:
                return False
i=0
while not (i>=n) or (len(r)==0):
    x,y=r[i]
    x1,y1,x2,y2,x3,y3=k[i]
    j=0
    while not j>=len(r) or len(r)==0:
        x,y=r[j]
        if f(x,y,x1,y1,x2,y2,x3,y3) and f(x,y,x3,y3,x1,y1,x2,y2) and f(x,y,x2,y2,x3,y3,x1,y1):
            del r[j]
        j+=1
    i+=1
print(len(r))