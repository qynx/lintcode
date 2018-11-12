a={}  #存储从0~n位的 每个字符的情况

s=[]  #存储所有字符串
if __name__=='__main__':

	count=int(input(''))

	for i in range(count):
		ss=input('')
		s.append(ss)

		#对每一个字符串做统计
		for index,sss in enumerate(ss):
			if index in a:
				if sss in a[index]:
					a[index][sss]+=1
				else:
					a[index][sss]=1

			else:
				a[index]={}
				a[index][sss]=1

	for ss in s:#对每一个字符串

		#temp=""
		for index,sss in enumerate(ss):
			if a[index][sss]==1:
				print(ss[0:index+1])
				#如果到此步可以拆分 那么该字符串之后的值 便没有区分度
				#for j in range(index+1,len(ss)):
					#a[j][ss[j]]-=1
				break

