import threading

cv=threading.Condition()

class Scheduler():
	def __init__(self):
		self.turn=0

s=Scheduler()


class A:

	def __init__(self,cv):
		self.cv=cv
		self.a=[1,2,3,4]

	def run(self):

		while True:
			with self.cv:

				while s.turn==1:
					self.cv.wait()

				#self.cv.wait()
				if len(self.a)==0:
					s.turn=1
					self.cv.notify()
					break
				else:
					print(self.a.pop())
				s.turn=1

				self.cv.notify()


class B:

	def __init__(self,cv):
		self.cv=cv
		self.a=['a','b','c','d']

	def run(self):

		while True:
			with self.cv:

				while s.turn==0:
					self.cv.wait()
				#self.cv.wait()
				if len(self.a)==0:
					s.turn=0
					self.cv.notify()
					#print(len(self.a))
					break
				else:
					print(self.a.pop())
				#
				s.turn=0
				self.cv.notify()

if __name__=='__main__':

	a=A(cv)
	b=B(cv)

	t1=threading.Thread(target=a.run)
	t2=threading.Thread(target=b.run)

	t1.start()
	t2.start()

	t1.join()
	t2.join()


