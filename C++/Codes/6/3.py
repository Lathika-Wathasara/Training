n,p=list(map(int,input().split()))
list_1=[]
for i in range(p):
    a=list(map(int,input().split()))
    list_1.append(a)
list_2=[]
while len(list_1)>0:
    T=True
    a=list_1[0]
    list_1.remove(a)
    b=set(a)
    if len(list_1)==0:
        list_2.append(a)
    else:

        while True:
            c=[]
            d=set()
            p=True
            for el in b:
                for i in range(len(list_1)):
                    if el in list_1[i]:
                        p=False
                        c.append(list_1[i])
                        d.update(list_1[i])
                for l in c:
                    list_1.remove(l)
                c=[]
            b.update(d)
            if p == True:
                list_2.append(list(b))
                break
                        

set_len=0
for set_ in list_2:
    set_len+=len(set_)

if set_len!=n:
    for i in range(n-set_len):
        list_2.append([0])

pairs=0
for x in range(len(list_2)):
    for y in range(x+1,len(list_2)):
        pairs+=(len(list_2[x])*len(list_2[y]))
print(pairs)