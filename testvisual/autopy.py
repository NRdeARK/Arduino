mounten=[]
print("amount of Mt. :")
amount=int(input())
print("height of each Mt. :")

for i in range(amount):
    INPUT=int(input())
    mounten+=[INPUT]
    
line=""

highest=max(mounten)
lowest=min(mounten)
print("highest is",highest)
print("lowest is",lowest)
if (lowest>=0):
    negLevel=0
else:
    negLevel=lowest
    

if ((highest>=0)and(lowest>=0)):
    totallevel=highest
    
elif((highest>0)and(lowest<0)):
    totallevel=highest-lowest
    
else:
    totallevel=abs(lowest)
    highest=1
    
for level in range(totallevel):
    
    #print("Level:",highest-level)
    
    for num in range(amount):
        hight=mounten[num]
        order=highest-level-hight
        if (order>0):
            order=0
        else:
            order=abs(order)


        
        if(hight>=0):#เขาขึ้น
            #print(hight)
            if( (hight>=highest-level)and(level<highest)):#กรณีเขานั้นสูงพอ
                line+=" "*(hight-order-1)
                line+="*"
                for c in range(hight-highest+level):#จำนวนดอกหลังจากดอกแรก
                    line+=" *"
                    
                line+=" "*(hight-order-1)
                
            else:#กรณีเขานั้นสูงไม่พอ
                line+=" "*(2*hight-1)

        else:#เขาลง
            deep=abs(hight)
            deepest=abs(lowest)
            #print(highest-level-2,">=",hight)
            if((highest-level<=1)and(highest-level-2>=hight)):#กรณีเขานั้นลึกพอ
                line+=" "*abs(highest-level-1)
                line+="*"
                for c in range(deep+highest-level-2):#จำนวนดอกหลังจากดอกแรก
                    line+=" *"
                    
                line+=" "*abs(highest-level-1)
                
            else:
                line+=" "*(2*deep-1)
            
    print(line)
    line=""
  

