class AnonymousSurvey():
	""" Collects anonymous answers for survey questions """
	def __init__(self, question):
		""" Store a question and prepare to store responses """
		self.question = question
		self.responses = []

	def show_question(self):
		""" Shows question to the user """
		print(self.question)

	def store_response(self, new_response):
		""" Stores a single response to a survey"""
		self.responses.append(new_response)

	def show_results(self):
		""" Shows all the responses that have been given """
		print("Survey Results: ")
		for response in self.responses:
			print(response)