def checa(base,exp,meta):
    s = 1
    if(base == 1 and meta == 1):
        return True
    for i in range(exp):
        s*=base
        if(s>meta):
            return True
    return s>meta

while True:
    try:
        n=int(input())
        p= int(input())

        l = 1
        r = int(1e102)

        while(l<r):
            med = (l+r)//2+1
            if(checa(med,n,p)):
                r = med-1
            else:
                l = med
        print(l)

    except EOFError:
        break