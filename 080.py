def root(n,prec):
    s=str(n)
    if len(s)%2:
        s="0"+s
    ans=""
    dividend=0
    last=0
    for j in range(0,len(s),2):
        dividend=dividend*100+int(s[j])*10+int(s[j+1])
        for i in range(9,-1,-1):
            if (last*10+i)*i<=dividend:
                ans+=(str(i))
                dividend-=(last*10+i)*i
                last=last*10+2*i
                break
    if prec:        
        ans+=('.')
        for _ in range(prec):
            dividend=dividend*100
            for i in range(9,-1,-1):
                if (last*10+i)*i<=dividend:
                    ans+=(str(i))
                    dividend-=(last*10+i)*i
                    last=last*10+2*i
                    break
        return ans
def f(i):
    return sum(map(int,list("".join(root(i,100).split('.'))[:100])))
cur=1
cur_root=1
ans=0
while cur<=100:
    if cur_root*cur_root==cur:
        cur+=1
        cur_root+=1
    else:
        ans+=f(cur)
        cur+=1
print ans