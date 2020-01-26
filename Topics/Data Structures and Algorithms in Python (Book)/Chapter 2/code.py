# Testing empty dict

dict_check = {}
if(not dict_check):
    print('Passes')


# Testing inheritance and printing protected/private members outside class

class Test():
    ''' Class for testing purposes '''
    def __init__(self):
        self._protected_data = 5
        self.__private_data = 10

object = Test()

# No enforcement on protected members. Can be accessed outside class as well
print('Protected Data is: ', object._protected_data)

'''
    Private members have enforcement. They can't be accessed using 
    object._private_date. They can only be accessed by 
    object._className_instance variable 
'''
print('Private Data is: ', object._Test__private_data)