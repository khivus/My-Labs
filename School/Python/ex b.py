n,h=map(int,input().split())
ss=h%2
s=1
for i in range (n):
    d,l=input().split()
    l=int(l)
    if d=='u':
        ss+=l
    elif d=='d':
        ss-=l
    if 0<=ss<=h:
        if d=='u':
            s+=l
        elif d=='d':
            s-=l
if s<=0 or s>h:
    print(0)
else: print(s)