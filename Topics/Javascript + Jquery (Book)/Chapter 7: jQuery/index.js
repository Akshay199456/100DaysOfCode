console.log('connected!');

let $hotClass = $('.hot');
console.log("Hot class: ", $hotClass);


// Testing animation
$hotClass.on('click', function(){
	console.dir(`${$(this)}`);
	$(this).slideUp('slow');
});


// Create element and add
const $lastLi = $('li:last');
const $newElement = $("<li id='five'>REEEEEEEE</li>");

$lastLi.after($newElement);


// Traversing the DOM using jQuery
const $element = $('#two');

console.log('All siblings: ', $element.siblings());

console.log('nextAll Siblings: ', $element.nextAll());