class Notes:
	def __init__(self, N=100, Nt='CBSE'):
		self.Nno=N
		self.NName=Nt
	def Allocate(self, N, Nt):
		self.Nno = self.Nno+N
		self.NName = Nt + self.NName
	def Show(self):
		print(self.Nno, "#", self.NName)

s=Notes()
t=Notes(200)
u=Notes(300, "Made Easy")
s.Show()
t.Show()
u.Show()
s.Allocate(4, "Made")
t.Allocate(10, "Easy")
u.Allocate(25, "Made Easy")
s.Show()
t.Show()
u.Show()