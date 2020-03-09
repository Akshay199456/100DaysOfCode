class PalindromeChecker{
	public static boolean isPallindrome(String element){
		int currIndex = 0;
		int elementLength = element.length();
		while( currIndex < elementLength/2 ){
			if(element.charAt(currIndex) != element.charAt(elementLength - 1 - currIndex))
				return false;
			currIndex++;
		}
		return true;
	}


	public static void main(String [] args){
		String testString = "hannahs";
		boolean result = isPallindrome(testString);
		if(result)
			System.out.println(testString + " is a pallindrome");
		else
			System.out.println(testString + " is sadly not a pallindrome");
	}
}