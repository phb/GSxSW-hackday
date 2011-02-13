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

	return document.elementFromPoint(x, y);
}

document.addEventListener("click", function(e) {
	console.log(e.screenY);

	document.gaze(e.clientX, e.clientY);
}, true);

var oldElement = null;

document.gaze = function(x, y) {
	var marker = document.getElementById('gazemarker');
	var e      = document.elementFromPoint(x, y);
	var uri    = null;

	marker.style.top  = y + 'px';
	marker.style.left = x + 'px';

	if(oldElement)
		oldElement.style.backgroundColor =  'white';

    while(e != undefined && e != document && (uri = e.getAttribute('gazemusic')) == null){
		e = e.parentNode;
    }

	if(uri != null){
		console.log(uri);
		plugin().playTrack(uri);

		e.style.backgroundColor = 'red';

		oldElement = e;
	}
}
