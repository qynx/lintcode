#
import copy

raws=[]
sorts=[]

result={}  #存储结果

def compare(s1,s2):
	#比较两个字符串

	l1=len(s1)
	l2=len(s2)
	i1=0
	i2=0
	while (i1<l1) and (i2<l2):
		if s1[i1]!=s2[i2]:
			return i1
		i1+=1
		i2+=1

	return i1

if __name__=='__main__':

	count=int(input(''))	

	for i in range(count):
		temp=input('')
		sorts.append(temp)

	#if(len(raws))
	raws=sorts.copy()
	sorts.sort()


	for i,s in enumerate(sorts):

		if i==0:
			r=compare(s,sorts[i+1])
			result[s]=s[0:r+1]

		elif i==len(sorts)-1:

			r=compare(s,sorts[i-1])
			result[s]=s[0:r+1]

		else:

			r1=compare(s,sorts[i-1])
			r2=compare(s,sorts[i+1])

			r=max(r1,r2)

			result[s]=s[0:r+1]

	for r in raws:
		print(result[r])



