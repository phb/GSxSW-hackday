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
	var gazemarker = document.getElementById("gazemarker");
	document.body.removeChild(gazemarker)
	el = document.elementFromPoint(x, y);
	document.body.appendChild(gazemarker)
	y += document.body.scrollTop;
/*	if(!el)
		consolelog("did not Found el!")*/
	//consolelog("doc location supposedly " + x + ", " + y)
	gazemarker.style.top = y+"px";
	gazemarker.style.left = x+"px";
	return el;
}
document.addEventListener("mousemove", function(e) {
	document.gaze(e.pageX, e.pageY);
});

var currentElement = null;
var currentTrack = null;
var contestantElement = null;
var contestantUnderGazeSince = 0;
function setCurrentElement(el) {
    if(el == currentElement) return;
    consolelog("current element is now " + el);
    if(currentElement) currentElement.style.backgroundColor = "white"
    currentElement = el;
    currentTrack = el ? el.getAttribute("gazemusic") : null;
    if(el) {
        el.style.backgroundColor = "green";
        plugin().playTrack(currentTrack);
    } // else pause
}
function setContestantElement(el) {
    if(el == currentElement) return;
    
    var now = (new Date).getTime();
    if(el == contestantElement) {
        if(now - contestantUnderGazeSince > 2000) {
            setCurrentElement(contestantElement);
            contestantElement = null;
            contestantUnderGazeSince = 0;
        }
        return;
    } else {
        if(contestantElement) contestantElement.style.backgroundColor = "white";
        contestantElement = el;
        contestantUnderGazeSince = now;
        if(contestantElement) contestantElement.style.backgroundColor = "yellow";
    }
}

document.gaze = function(x,y) {
	var el = elementFromScreenPoint(x, y);
    while(el != null && el != document) {
        var track = el.getAttribute("gazemusic");
        if(track && track.length > 0) {
            break;
        }
		el = el.parentNode;
    }
    if(el == document) el = null;
    setContestantElement(el);
}