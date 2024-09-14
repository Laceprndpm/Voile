# def fuction (age,name='john',sex='male',*more):
#     print(name.title())
#     print(sex)
#     print(age)
#     for i in more:
#         print(i)
# fuction (12,'name''a','b',sex = 'female')
# class dog():
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age

#     def act(self):
#         print(self.name+" and "+str(self.age))
# white=dog('white',3)
# white.act()
class fuction():
    def __init__(self,data):
        self.data = data
    def __repr__(self):
        return str(self.data)