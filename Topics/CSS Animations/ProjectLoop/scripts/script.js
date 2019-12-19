let currentValue = 2;
let currentSelectionMap = new Map();

// Setting map values to coordinate with the different colors of product
currentSelectionMap.set(0, "black");
currentSelectionMap.set(1, "gold");
currentSelectionMap.set(2, "roseGold");
currentSelectionMap.set(3, "silver");
currentSelectionMap.set(4, "red");


const imageUrls = {
	red : "loop-product-s1-red.jpg",
	black: "loop-product-s1-black.jpg",
	gold: "loop-product-s1-gold.jpg",
	roseGold: "loop-product-s1-rosegold.jpg",
	silver: "loop-product-s1-silver.jpg"
};

const backgroundUrls = {
	red:"loop-slide-red.jpg",
	black:"loop-slide-black2.jpg" ,
	gold:"loop-slide-gold2.jpg",
	roseGold:"loop-slide-rosegold.jpg",
	silver: "loop-slide-silver.jpg"
};


function setCurrentValue(index){
	currentValue+=index;
}

function checkCurrentValueOverFlow(){
	if(currentValue < 0)
		currentValue = 4;
	else if(currentValue > 4)
		currentValue = 0;
}

function setBackgroundAndImage(){
	/* 

	This is used to get the relative path of the file. The value is then used to append to the relative URLS
	to get the images from the local folder instead of having to host them on a website
	*/
	var scripts= document.getElementsByTagName('script');
	var path= scripts[scripts.length-1].src.split('?')[0];      // remove any ?query
	var mydir= path.split('/').slice(0, -1).join('/')+'/';  // remove last filename part of path



	const currentObject = currentSelectionMap.get(currentValue);
	const body = document.body;
	const image = document.getElementById("imageNavigator").children[1];
	// console.log(image.getAttribute("src"));

	const bodyUrl = mydir+"../images/"+backgroundUrls[currentObject];
	const imageUrl = mydir+"../images/"+imageUrls[currentObject];
	// console.log(image);

	// console.log("url('"+bodyUrl+"')");
	body.style.backgroundImage = "url('"+bodyUrl+"')";
	image.setAttribute("src", imageUrl);
}

function findIdFromColor(color){
	for(let [key,value] of currentSelectionMap.entries()){
		if(color === value)
			return key;
	}
}


// Event Listeners on different elements

const leftIcon = document.getElementById("moveLeft");
leftIcon.addEventListener("click", () => {
	console.log("Left button clicked");
	setCurrentValue(-1);
	checkCurrentValueOverFlow();
	// console.log("Current value: " + currentValue);
	setBackgroundAndImage();
});

const rightIcon = document.getElementById("moveRight");
rightIcon.addEventListener("click", () => {
	console.log("Right button clicked");
	setCurrentValue(1);
	checkCurrentValueOverFlow();
	// console.log("Current value: " + currentValue);
	setBackgroundAndImage();
});

const buttonNavigator = document.getElementById("buttonNavigator");
buttonNavigator.addEventListener("click", e => {
	console.log("Event Target: " + e.target.id);
	console.log("Event Current Target: " + e.currentTarget.id);
	if(e.target.id !== e.currentTarget.id){
		currentValue = findIdFromColor(e.target.id);
		console.log(currentValue);
		setBackgroundAndImage();
	}
});