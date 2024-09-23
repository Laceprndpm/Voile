def code(key,m):
    times = len(m)//len(key)
    temp=[]
    for i in range(times):
        j=de_one(key,m[i*len(key):(i+1)*len(key)])
        temp.append(j)
    return temp

def de_one(key,n):
    num=len(key)
    temp=0
    for i in range(num):
        temp+=key[i]*n[i]
    if temp >0:
        return 1
    else:
        return 0