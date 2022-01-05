import unittest
from survey import AnonymousSurvey

class TestAnonymousSurvey(unittest.TestCase):
	""" Testing class for the AnonymousSurvey class """

	def setUp(self):
		""" Sets up the test class before the methods are called """
		question = "What language did you first learn to speak?"
		self.my_survey = AnonymousSurvey(question)
		self.responses = ['Python', 'JS', 'C++']

	def test_store_single_response(self):
		""" Test that a single response is stored correctly """
		self.my_survey.store_response(self.responses[0])
		self.assertIn('Python', self.my_survey.responses)

	def test_store_three_responses(self):
		""" Test that 3 responses are stored correctly """
		for response in self.responses:
			self.my_survey.store_response(response)

		for response in self.responses:
			self.assertIn(response, self.my_survey.responses)


unittest.main()

