
if __name__=='__main__':

	s=input('')
	s=s[::-1]
	#print(s)
	sp=s.split(' ')
	#print(sp)
	sp.reverse()
	#print(sp)
	s=' '.join(sp)
	print(s)

