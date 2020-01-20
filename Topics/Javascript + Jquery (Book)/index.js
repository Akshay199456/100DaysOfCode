console.log('connected!');

let $hotClass = $('.hot');
console.log("Hot class: ", $hotClass);


// Testing animation
$hotClass.on('click', function(){
	console.dir(`${$(this)}`);
	$(this).slideUp('slow');
});