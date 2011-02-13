function consolelog(text) {
    document.getElementById("dbg").innerHTML = text
    console.log(text)
}
function elementFromScreenPoint(x, y) {
	x -= window.screenX;
	y -= window.screenY;
	//y += document.body.scrollTop;
	//y -= 96;
	y -= 22;
	el = document.elementFromPoint(x, y);
	y += document.body.scrollTop;
	if(!el)
		consolelog("did not Found el!")
	consolelog("doc location supposedly " + x + ", " + y)
	document.getElementById("gazemarker").style.top = y+"px";
	document.getElementById("gazemarker").style.left = x+"px";
	return el;
}
document.addEventListener("mousemove", function(e) {
	el = document.elementFromPoint(e.pageX, e.pageY);
	if(!el) {
		consolelog("No E");
	} else {
		consolelog("Found E!");
	}
});

var oldElement = undefined;
document.gaze = function(x,y) {
	var el = elementFromScreenPoint(x, y);

	if(oldElement) oldElement.style.backgroundColor =  "white";
    while(el != undefined && el != document) {
        if(el.getAttribute("gazemusic") != "") {
            plugin().playTrack(el.getAttribute("gazemusic"))
			el.style.backgroundColor = "red";
			oldElement = el;
            break;
        }
		el = el.parentNode;
		consolelog("Iterating to parent")
    }
}