def fact(x):
    u = 1
    for i in range(x+1):
        if(i==0):
            continue
        u*=i
    return u
def combina(n,m):
    nfa = fact(n)
    mfa = fact(m)
    nmfa = fact(n-m)

    return nfa//(mfa*nmfa)

while True:
    line = input()
    num1, num2 = map(int, line.split())
    if(num1 == 0 and num2 == 0):
        break
    
    print(num1,end='')
    print(" things taken ",end = '')
    print(num2,end = '')
    print(" at a time is ",end = '')
    print(combina(num1,num2),end = '')
    print(" exactly.")