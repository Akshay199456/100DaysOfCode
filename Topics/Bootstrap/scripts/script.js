console.log("connected");

let closeListener = document.getElementById("close");
closeListener.addEventListener("click", function(){
	$('.alert').alert('close');
});