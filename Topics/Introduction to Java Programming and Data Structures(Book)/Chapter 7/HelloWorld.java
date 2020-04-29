class HelloWorld{
	// Testing out variable argument lists and Java's foreach equivalent
	public static void printMax(int... list){
		if(list.length == 0)
			System.out.println("The length of the list is zero");
		else{
			int max = list[0];
			for(int element: list){
				if(element > max)
					max = element;
			}
			System.out.println("The max element is : " + max);
		}
	}


	// Selection Sort
	public static void selectionSort(int [] list){
		for(int i = 0; i < list.length; i++){
			int minElement = list[i], minIndex = i;
			for(int j = i+1; j < list.length; j++){
				if(minElement > list[j]){
					minElement = list[j];
					minIndex = j;
				}
			}

			int temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}

	public static void displayArray(int [] list){
		for(int element: list)
			System.out.println(element + " ");
	}


	public static void main(String [] args){
		int [] list = new int[]{22,45,11,56,8,9,1,67,69};
		//System.out.println("Hello World!");
		// printMax(new int[] {2,44,3,11,77,33});
		System.out.println("Before sorting: ");
		displayArray(list);
		selectionSort(list);
		System.out.println("After sorting: ");
		displayArray(list);
	}
}