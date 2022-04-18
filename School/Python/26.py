s,n=map(int,input().split())
sl=s
f=[]
for i in range(n):
    f.append(i)
f.sort()
i=0
while not (sl-f[i]<0):
    sl-=f[i]
    i+=1
print(i)
if sl+f[i-1]>f[i]:
    print(f[i])
else:
    print(f[i-1])
'''100
100 4
80
30
50
40 
'''