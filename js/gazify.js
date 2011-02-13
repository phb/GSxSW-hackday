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
	consolelog("doc location supposedly " + x + ", " + y)
	document.getElementById("gazemarker").style.top = y+"px";
	document.getElementById("gazemarker").style.left = x+"px";
	return el;
}
var oldElement = undefined;
document.gaze = function(x,y) {
	var el = elementFromScreenPoint(x, y);
	if(oldElement) oldElement.style.backgroundColor =  "white";
    while(el != undefined && el != document) {
        if(el.getAttribute("gazemusic") != "") {
            plugin().playTrack(el.getAttribute("gazemusic"))
            break;
        }
    }
    
	el.style.backgroundColor = "red";
	oldElement = el;
}