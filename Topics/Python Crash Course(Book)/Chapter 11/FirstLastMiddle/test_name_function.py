import unittest
from name_function import get_formatted_name

class NamesTestCase(unittest.TestCase):
	""" Tests for name_funnction.py """

	def test_first_last_name(self):
		""" Test the results when first and last name is passed """
		formatted_name = get_formatted_name('janis', 'joplin')
		self.assertEqual(formatted_name, 'Janis Joplin')

	def test_first_middle_last_name(self):
		""" Tests the results when first, middle and last name passed '"""
		formatted_name = get_formatted_name('akshay', 'sridhara', 'mysore')
		self.assertEqual(formatted_name, 'Akshay Mysore Sridhara')

unittest.main()