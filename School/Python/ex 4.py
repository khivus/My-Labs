n,m=map(int,input().split())
q=[[0]*m for i in range(n)]
for i in range(n):
    q[i]=list(map(int,input().split()))
print(q)
x=[]
y=[]
for i in range(0,m):
    if q[0][i]==1:
        y.append(0)
        x.append(i)
        q[0][i]=0      
for i in range(0,n):
    if q[i][m-1]==2:
        y.append(i)
        x.append(m-1)
        q[i][m-1]=0
for i in range(0,m):
    if q[n-1][i]==3:
        y.append(n-1)
        x.append(i)
        q[n-1][i]=0
for i in range(0,n):
    if q[i][0]==4:
        y.append(i)
        x.append(0)
        q[i][0]=0
print(y)
print(x)
j=0
l=len(x)
while not j==l:
    xt=x[j]
    yt=y[j]
    print(xt,yt)
    if yt>=1:
        if q[yt-1][xt]==3:
            q[yt-1][xt]=0
            x.append(xt)
            y.append(yt-1)
    if yt<=n-2:
        if q[yt+1][xt]==1:
            q[yt+1][xt]=0
            x.append(xt)
            y.append(yt+1)
    if xt>=1:
        if q[yt][xt-1]==2:
            q[yt][xt-1]=0
            x.append(xt-1)
            y.append(yt)
    if xt<=m-2:
        if q[yt][xt+1]==4:
            q[yt][xt+1]=0
            x.append(xt+1)
            y.append(yt)
    j+=1
    l=len(x)
print()
print(y)
print(x)
print(len(x))






    
