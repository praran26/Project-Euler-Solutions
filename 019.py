import datetime
Y1,M1,D1=1901,1,1
Y2,M2,D2=2000,12,31
date1=datetime.date(Y1,M1,D1)
date2=datetime.date(Y2,M2,D2)
ans=0
for i in range(Y1,Y2+1):
    for j in range(1,13):
        curdate=datetime.date(i,j,1)
        if curdate.weekday()==6 and date1<=curdate<=date2:
            ans+=1
print(ans)
