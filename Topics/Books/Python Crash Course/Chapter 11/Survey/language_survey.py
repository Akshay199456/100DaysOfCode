from survey import AnonymousSurvey

if __name__ == '__main__':
	""" Defines a function and makes a survey """
	question = 'What language did you first learn to speak?'
	my_survey = AnonymousSurvey(question)

	""" Show a question and store responses to the question """
	my_survey.show_question()
	print("Enter q at any time to quit\n")
	
	valid = True
	while(valid):
		response = input('Language: ')
		if response == 'q':
			valid = False
		if(valid):
				my_survey.store_response(response)

	""" Show the survey results """
	my_survey.show_results()
