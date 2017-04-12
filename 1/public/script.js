var slideIndex = 0;
showSlide(slideIndex);

function switchSlide(n) {
    showSlide(slideIndex += n);
}

function showSlide(n) {
    var i;
    var slidesArray = document.getElementsByClassName("slides");

    if (n > slidesArray.length-1) {
        slideIndex = 0
    }

    if (n < 0) {
        slideIndex = slidesArray.length
    };

    for (i = 0; i < slidesArray.length; i++) {
        slidesArray[i].className = slidesArray[i].className.replace(" fadeImage", "");
    }

    slidesArray[slideIndex].className += " fadeImage";

}

window.setInterval(function(){
    switchSlide(1)
}, 20000);

//-----------------------------------------------------------------Screen touch

window.addEventListener('load', function(){
    console.log("load");
    var startx= 0;
    var dist= 0;
    var endx= 0;

    document.getElementsByClassName("slides")[0].addEventListener('touchstart', function(e){
        var touchobj = e.changedTouches[0];
        startx = parseInt(touchobj.clientX);
        console.log("startx");
        e.preventDefault();
    }, false)

    document.getElementsByClassName("slides")[0].addEventListener('touchmove', function(e){
        var touchobj= e.changedTouches[0];
        dist= parseInt(touchobj.clientX)- startx;
        console.log(dist);
        e.preventDefault();
    }, false)


    document.getElementsByClassName("slides")[0].addEventListener('touchend', function(e){
        var touchobj = e.changedTouches[0] // reference first touch point for this event
        statusdiv.innerHTML = 'Status: touchend<br> Resting x coordinate: ' + touchobj.clientX + 'px'
        e.preventDefault()
    }, false)

   

    if(dist>= 10){
        switchSlide(1);
    }else if(dist<= -10){
        switchSlide(-1);
    }

}, false)





