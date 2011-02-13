var isChrome = function() {
	return navigator.userAgent.indexOf('Chrome') != -1;
}

var isSafari = function() {
	return navigator.vendor.indexOf('Apple') != -1;
}
var isFirefox = function() {
	return navigator.userAgent.indexOf('Firefox') != -1;
}

document.elementFromScreenPoint = function(x, y) {
	var offX = (window.screenX < 0) ? 0 : window.screenX;
	var offY = (window.screenY < 0) ? 0 : window.screenY;

	if (isChrome()) {
		x -= offX;
		y -= offY + 60;
	}
	else if (isSafari()) {
		x -= offX;
		y -= offY + 96;
	}
	else if (isFirefox()) {
		x -= window.mozInnerScreenX;
		y -= window.mozInnerScreenY;
	}
	else {
		x -= offX;
		y -= offY;
	}
    
    var marker = document.getElementById('gazemarker');
    document.body.removeChild(marker);
	el =  document.elementFromPoint(x, y);
	document.body.appendChild(marker);
	
	return el;
}

var currentElement           = null;
var currentTrack             = null;
var contestantElement        = null;
var contestantUnderGazeSince = 0;

var setCurrentElement = function(e) {
    if(e == currentElement)
		return;

    console.log("current element is now " + e);

    if(currentElement)
		currentElement.style.backgroundColor = "white";

    currentElement = e;
    currentTrack   = e ? e.getAttribute("gazemusic") : null;

    if(e){
		e.style.backgroundColor = "green";

        plugin().playTrack(currentTrack);
    } // else pause
}

var setContestantElement = function(e) {
    if(e == currentElement)
		return;

    var now = (new Date).getTime();

    if(e == contestantElement) {
        if(now - contestantUnderGazeSince > 2000) {
            setCurrentElement(contestantElement);

            contestantElement        = null;
            contestantUnderGazeSince = 0;
        }

        return;
    }
    else {
        if(contestantElement)
			contestantElement.style.backgroundColor = "white";

        contestantElement        = e;
        contestantUnderGazeSince = now;

        if(contestantElement)
			contestantElement.style.backgroundColor = "yellow";
    }
}

document.addEventListener("click", function(e) {
	document.gaze(e.clientX, e.clientY);
}, false);

document.addEventListener("mousemove", function(e) {
	document.gaze(e.clientX, e.clientY);
}, false);

document.gaze = function(x, y) {
    var marker = document.getElementById('gazemarker');
    document.body.removeChild(marker);
	var e =  document.elementFromPoint(x, y);
	document.body.appendChild(marker);
    
	var uri = null;
	
	marker.style.left = (x + window.scrollX) + 'px';
	marker.style.top  = (y + window.scrollY) + 'px';
	
    while(e != undefined && e != document){
		var uri = e.getAttribute('gazemusic');

		if(uri && uri.length > 0)
			break;
		e = e.parentNode;
    }
    setContestantElement((e == document) ? null : e);
}

document.gazeInfo = function(artist, album, title, cover) {
	$('#gazeinfo-artist').text(artist);
	$('#gazeinfo-album').text(album);
	$('#gazeinfo-title').text(title);
	$('#gazeinfo-cover').css('background', 'url(data:image/png;base64,' + cover + ')');
	$('#gazeinfo').fadeIn();
	console.log("helloo world");
}
