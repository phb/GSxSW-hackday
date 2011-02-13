/* <syntaxhighlight lang="css"> */
 
/* Main page fixes */
#interwiki-completelist {
    font-weight: bold;
}
body.page-Main_Page #ca-delete {
    display: none !important;
}

body.page-Main_Page #mp-topbanner {
   clear: both;
}

/* Edit window toolbar */
#toolbar {
    height: 22px;
    margin-bottom: 6px;
}

/* Margins for <ol> and <ul> */
#content ol, #content ul,
#mw_content ol, #mw_content ul {
    margin-bottom: 0.5em;
}

/* Make the list of references smaller */
div.references {
    font-size: 90%;
}

/* Highlight clicked reference in blue to help navigation */
div.references li:target,
sup.reference:target,
span.citation:target { 
    background-color: #DEF;
}

/* Ensure refs in table headers and the like aren't bold or italic */
sup.reference {
    font-weight: normal;
    font-style: normal;
}

/* Styling for citations */
span.citation, cite {
    font-style: normal;
    word-wrap: break-word;
}

/* For linked citation numbers and document IDs, where
   the number need not be shown on a screen or a handheld,
   but should be included in the printed version
*/
@media screen, handheld {
    span.citation *.printonly {
        display: none;
    }
}

/* Default skin for navigation boxes */
table.navbox {            /* Navbox container style */
    border: 1px solid #aaa;
    width: 100%; 
    margin: auto;
    clear: both;
    font-size: 88%;
    text-align: center;
    padding: 1px;
}
table.navbox + table.navbox {  /* Single pixel border between adjacent navboxes */
    margin-top: -1px;          /* (doesn't work for IE6, but that's okay)       */
}
.navbox-title,
.navbox-abovebelow,
table.navbox th {
    text-align: center;      /* Title and above/below styles */
    padding-left: 1em;
    padding-right: 1em;
}
.navbox-group {              /* Group style */
    white-space: nowrap;
    text-align: right;
    font-weight: bold;
    padding-left: 1em;
    padding-right: 1em;
}
.navbox, .navbox-subgroup {
    background: #fdfdfd;     /* Background color */
}
.navbox-list {
    border-color: #fdfdfd;   /* Must match background color */
}
.navbox-title,
table.navbox th {
    background: #ccccff;     /* Level 1 color */
}
.navbox-abovebelow,
.navbox-group,
.navbox-subgroup .navbox-title {
    background: #ddddff;     /* Level 2 color */
}
.navbox-subgroup .navbox-group, .navbox-subgroup .navbox-abovebelow {
    background: #e6e6ff;     /* Level 3 color */
}
.navbox-even {
    background: #f7f7f7;     /* Even row striping */
}
.navbox-odd {
    background: transparent; /* Odd row striping */
}

.collapseButton {          /* 'show'/'hide' buttons created dynamically */
    float: right;          /* by the CollapsibleTables javascript in    */
    font-weight: normal;   /* [[MediaWiki:Common.js]] are styled here   */
    text-align: right;     /* so they can be customised.                */
    width: auto;
}
.navbox .collapseButton {  /* In navboxes, the show/hide button balances */
    width: 6em;            /* the vde links from [[Template:Navbar]],    */
}                          /* so they need to be the same width.         */

.navbar {                  /* Navbox template links */
    font-size: 88%;        /* Default font-size */
    font-weight: normal;
}
.navbox .navbar {
    font-size: 100%;       /* Font-size when nested within navbox */
}

/* Infobox template style */
.infobox {
    border: 1px solid #aaa;
    background-color: #f9f9f9;
    color: black;
    margin: 0.5em 0 0.5em 1em;
    padding: 0.2em;
    float: right;
    clear: right;
}
.infobox td,
.infobox th {
    vertical-align: top;
}
.infobox caption {
    font-size: larger;
}
.infobox.bordered {
    border-collapse: collapse;
}
.infobox.bordered td,
.infobox.bordered th {
    border: 1px solid #aaa;
}
.infobox.bordered .borderless td,
.infobox.bordered .borderless th {
    border: 0;
}

.infobox.sisterproject {
    width: 20em;
    font-size: 90%;
}

.infobox.standard-talk {
    border: 1px solid #c0c090;
    background-color: #f8eaba;
}
.infobox.standard-talk.bordered td,
.infobox.standard-talk.bordered th {
    border: 1px solid #c0c090;
}

/* styles for bordered infobox with merged rows */
.infobox.bordered .mergedtoprow td,
.infobox.bordered .mergedtoprow th {
    border: 0;
    border-top: 1px solid #aaa;
    border-right: 1px solid #aaa;
}

.infobox.bordered .mergedrow td,
.infobox.bordered .mergedrow th {
    border: 0;
    border-right: 1px solid #aaa;
}

/* Styles for geography infoboxes, eg countries,
   country subdivisions, cities, etc.            */
.infobox.geography {
    text-align: left;
    border-collapse: collapse;
    line-height: 1.2em; 
    font-size: 90%;
}

.infobox.geography  td,
.infobox.geography  th {
    border-top: 1px solid #aaa;
    padding: 0.4em 0.6em 0.4em 0.6em;
}
.infobox.geography .mergedtoprow td,
.infobox.geography .mergedtoprow th {
    border-top: 1px solid #aaa;
    padding: 0.4em 0.6em 0.2em 0.6em;
}

.infobox.geography .mergedrow td,
.infobox.geography .mergedrow th {
    border: 0;
    padding: 0 0.6em 0.2em 0.6em;
}

.infobox.geography .mergedbottomrow td,
.infobox.geography .mergedbottomrow th {
    border-top: 0;
    border-bottom: 1px solid #aaa;
    padding: 0 0.6em 0.4em 0.6em;
}

.infobox.geography .maptable td,
.infobox.geography .maptable th {
    border: 0;
    padding: 0;
}

/* Normal font styling for table row headers with scope="row" tag */
.wikitable.plainrowheaders th[scope=row] {
    font-weight: normal;
    text-align: left;
}

/* lists in data cells are always left-aligned */
.wikitable td ul,
.wikitable td ol,
.wikitable td dl {
    text-align: left;
}

/* Makes redirects appear in italics in categories and on [[Special:Allpages]] */
.redirect-in-category, .allpagesredirect {
    font-style: italic;
}

/* Icons for medialist templates [[Template:Listen]],
   [[Template:Multi-listen_start]], [[Template:Video]],
   [[Template:Multi-video_start]]
*/
div.listenlist {
    background: url("http://upload.wikimedia.org/wikipedia/commons/3/3f/Gnome_speakernotes_30px.png");
    padding-left: 40px;
}

/* Style rules for media list templates */
div.medialist {
    min-height: 50px;
    margin: 1em;
    background-position: top left;
    background-repeat: no-repeat;
}
div.medialist ul {
    list-style-type: none; 
    list-style-image: none;
    margin: 0;
}
div.medialist ul li {
    padding-bottom: 0.5em;
}
div.medialist ul li li {
    font-size: 91%;
    padding-bottom: 0;
}

/* Change the external link icon to an Adobe icon for all PDF files
   in browsers that support these CSS selectors, like Mozilla and Opera */
#content a[href$=".pdf"].external, 
#content a[href*=".pdf?"].external, 
#content a[href*=".pdf#"].external,
#content a[href$=".PDF"].external, 
#content a[href*=".PDF?"].external, 
#content a[href*=".PDF#"].external,
#mw_content a[href$=".pdf"].external, 
#mw_content a[href*=".pdf?"].external, 
#mw_content a[href*=".pdf#"].external,
#mw_content a[href$=".PDF"].external, 
#mw_content a[href*=".PDF?"].external, 
#mw_content a[href*=".PDF#"].external {
    background: url("http://upload.wikimedia.org/wikipedia/commons/2/23/Icons-mini-file_acrobat.gif") center right no-repeat;
    padding-right: 18px;
}

/* Change the external link icon to an Adobe icon anywhere the PDFlink class
   is used (notably Template:PDFlink). This works in IE, unlike the above. */
#content span.PDFlink a,
#mw_content span.PDFlink a {
    background: url("http://upload.wikimedia.org/wikipedia/commons/2/23/Icons-mini-file_acrobat.gif") center right no-repeat;
    padding-right: 18px;
}

/* Content in columns with CSS instead of tables [[Template:Columns]] */
div.columns-2 div.column {
    float: left;
    width: 50%;
    min-width: 300px;
}
div.columns-3 div.column {
    float: left;
    width: 33.3%;
    min-width: 200px;
}
div.columns-4 div.column {
    float: left;
    width: 25%;
    min-width: 150px;
}
div.columns-5 div.column {
    float: left;
    width: 20%;
    min-width: 120px;
}

/* Messagebox templates */
.messagebox {
    border: 1px solid #aaa;
    background-color: #f9f9f9;
    width: 80%;
    margin: 0 auto 1em auto;
    padding: .2em;
}
.messagebox.merge {
    border: 1px solid #c0b8cc;
    background-color: #f0e5ff;
    text-align: center;
}
.messagebox.cleanup {
    border: 1px solid #9f9fff;
    background-color: #efefff;
    text-align: center;
}
.messagebox.standard-talk {
    border: 1px solid #c0c090;
    background-color: #f8eaba;
    margin: 4px auto;
}
/* For old WikiProject banners inside banner shells. */
.mbox-inside .standard-talk,
.messagebox.nested-talk {
    border: 1px solid #c0c090;
    background-color: #f8eaba;
    width: 100%;
    margin: 2px 0;
    padding: 2px;
}
.messagebox.small {
    width: 238px;
    font-size: 85%;
    float: right;
    clear: both;
    margin: 0 0 1em 1em;
    line-height: 1.25em; 
}
.messagebox.small-talk {
    width: 238px;
    font-size: 85%;
    float: right;
    clear: both;
    margin: 0 0 1em 1em;
    line-height: 1.25em; 
    background: #F8EABA;
}

/* Cell sizes for ambox/tmbox/imbox/cmbox/ombox/fmbox/dmbox message boxes */
th.mbox-text, td.mbox-text {   /* The message body cell(s) */
    border: none; 
    padding: 0.25em 0.9em;     /* 0.9em left/right */
    width: 100%;               /* Make all mboxes the same width regardless of text length */
}
td.mbox-image {                /* The left image cell */
    border: none; 
    padding: 2px 0 2px 0.9em;  /* 0.9em left, 0px right */
    text-align: center; 
}
td.mbox-imageright {           /* The right image cell */
    border: none;
    padding: 2px 0.9em 2px 0;  /* 0px left, 0.9em right */
    text-align: center; 
}
td.mbox-empty-cell {           /* An empty narrow cell */
    border: none;
    padding: 0px;
    width: 1px;
}

/* Article message box styles */
table.ambox {
    margin: 0px 10%;                  /* 10% = Will not overlap with other elements */
    border: 1px solid #aaa; 
    border-left: 10px solid #1e90ff;  /* Default "notice" blue */
    background: #fbfbfb; 
}
table.ambox + table.ambox {      /* Single border between stacked boxes. */
    margin-top: -1px;
}
.ambox th.mbox-text, 
.ambox td.mbox-text {            /* The message body cell(s) */
    padding: 0.25em 0.5em;       /* 0.5em left/right */
}
.ambox td.mbox-image {           /* The left image cell */
    padding: 2px 0 2px 0.5em;    /* 0.5em left, 0px right */
}
.ambox td.mbox-imageright {      /* The right image cell */
    padding: 2px 0.5em 2px 0;    /* 0px left, 0.5em right */
}

table.ambox-notice {
    border-left: 10px solid #1e90ff;    /* Blue */
}
table.ambox-speedy {
    border-left: 10px solid #b22222;    /* Red */
    background: #fee;                   /* Pink */
}
table.ambox-delete {
    border-left: 10px solid #b22222;    /* Red */
}
table.ambox-content {
    border-left: 10px solid #f28500;    /* Orange */
}
table.ambox-style {
    border-left: 10px solid #f4c430;    /* Yellow */
}
table.ambox-move {
    border-left: 10px solid #9932cc;    /* Purple */
}
table.ambox-protection {
    border-left: 10px solid #bba;       /* Gray-gold */
}

/* Image message box styles */
table.imbox {
    margin: 4px 10%; 
    border-collapse: collapse; 
    border: 3px solid #1e90ff;    /* Default "notice" blue */
    background: #fbfbfb;
}
.imbox .mbox-text .imbox {  /* For imboxes inside imbox-text cells. */
    margin: 0 -0.5em;       /* 0.9 - 0.5 = 0.4em left/right.        */
    display: block;         /* Fix for webkit to force 100% width.  */
}
.mbox-inside .imbox {       /* For imboxes inside other templates.  */
    margin: 4px;
}

table.imbox-notice {
    border: 3px solid #1e90ff;    /* Blue */
}
table.imbox-speedy {
    border: 3px solid #b22222;    /* Red */
    background: #fee;             /* Pink */
}
table.imbox-delete {
    border: 3px solid #b22222;    /* Red */
}
table.imbox-content {
    border: 3px solid #f28500;    /* Orange */
}
table.imbox-style {
    border: 3px solid #f4c430;    /* Yellow */
}
table.imbox-move {
    border: 3px solid #9932cc;    /* Purple */
}
table.imbox-protection {
    border: 3px solid #bba;       /* Gray-gold */
}
table.imbox-license {
    border: 3px solid #88a;       /* Dark gray */
    background: #f7f8ff;          /* Light gray */
}
table.imbox-featured {
    border: 3px solid #cba135;    /* Brown-gold */
}

/* Category message box styles */
table.cmbox {
    margin: 3px 10%;
    border-collapse: collapse;
    border: 1px solid #aaa; 
    background: #DFE8FF;    /* Default "notice" blue */
}

table.cmbox-notice {
    background: #D8E8FF;    /* Blue */
}
table.cmbox-speedy {
    margin-top: 4px;
    margin-bottom: 4px;
    border: 4px solid #b22222;    /* Red */
    background: #FFDBDB;          /* Pink */
}
table.cmbox-delete {
    background: #FFDBDB;    /* Red */
}
table.cmbox-content {
    background: #FFE7CE;    /* Orange */
}
table.cmbox-style {
    background: #FFF9DB;    /* Yellow */
}
table.cmbox-move {
    background: #E4D8FF;    /* Purple */
}
table.cmbox-protection {
    background: #EFEFE1;    /* Gray-gold */
}

/* Other pages message box styles */
table.ombox {
    margin: 4px 10%; 
    border-collapse: collapse; 
    border: 1px solid #aaa;       /* Default "notice" gray */
    background: #f9f9f9;
}

table.ombox-notice {
    border: 1px solid #aaa;       /* Gray */
}
table.ombox-speedy {
    border: 2px solid #b22222;    /* Red */
    background: #fee;             /* Pink */
}
table.ombox-delete {
    border: 2px solid #b22222;    /* Red */
}
table.ombox-content {
    border: 1px solid #f28500;    /* Orange */
}
table.ombox-style {
    border: 1px solid #f4c430;    /* Yellow */
}
table.ombox-move {
    border: 1px solid #9932cc;    /* Purple */
}
table.ombox-protection {
    border: 2px solid #bba;       /* Gray-gold */
}
 
/* Talk page message box styles */
table.tmbox {
    margin: 4px 10%;
    border-collapse: collapse;
    border: 1px solid #c0c090;    /* Default "notice" gray-brown */
    background: #f8eaba;
}
.mediawiki .mbox-inside .tmbox { /* For tmboxes inside other templates. The "mediawiki" class ensures that */
    margin: 2px 0;               /* this declaration overrides other styles (including mbox-small above)   */
    width: 100%;                 /* For Safari and Opera */
}
.mbox-inside .tmbox.mbox-small { /* "small" tmboxes should not be small when  */
    line-height: 1.5em;          /* also "nested", so reset styles that are   */   
    font-size: 100%;             /* set in "mbox-small" above.                */
}

table.tmbox-speedy {
    border: 2px solid #b22222;    /* Red */
    background: #fee;             /* Pink */
}
table.tmbox-delete {
    border: 2px solid #b22222;    /* Red */
}
table.tmbox-content {
    border: 2px solid #f28500;    /* Orange */
}
table.tmbox-style {
    border: 2px solid #f4c430;    /* Yellow */
}
table.tmbox-move {
    border: 2px solid #9932cc;    /* Purple */
}
table.tmbox-protection,
table.tmbox-notice {
    border: 1px solid #c0c090;    /* Gray-brown */
}

/* Disambig and set index box styles */
table.dmbox {
    clear: both; 
    margin: 0.9em 1em; 
    border-top: 1px solid #ccc; 
    border-bottom: 1px solid #ccc; 
    background: transparent;
}
 
/* Footer and header message box styles */
table.fmbox {
    clear: both;
    margin: 0.2em 0;
    width: 100%;
    border: 1px solid #aaa;
    background: #f9f9f9;     /* Default "system" gray */
}
table.fmbox-system {
    background: #f9f9f9;
}
table.fmbox-warning {
    border: 1px solid #bb7070;  /* Dark pink */
    background: #ffdbdb;        /* Pink */
}
table.fmbox-editnotice {
    background: transparent;
}
/* Div based "warning" style fmbox messages. */
div.mw-warning-with-logexcerpt,
div.mw-lag-warn-high,
div.mw-cascadeprotectedwarning,
div#mw-protect-cascadeon {
    clear: both;
    margin: 0.2em 0;
    border: 1px solid #bb7070;
    background: #ffdbdb;
    padding: 0.25em 0.9em;
}
/* Div based "system" style fmbox messages. 
   Used in [[MediaWiki:Readonly lag]]. */
div.mw-lag-warn-normal,
div.fmbox-system {
    clear: both;
    margin: 0.2em 0;
    border: 1px solid #aaa;
    background: #f9f9f9;
    padding: 0.25em 0.9em;
}

/* These mbox-small classes must be placed after all other 
   ambox/tmbox/ombox etc classes. "body.mediawiki" is so 
   they override "table.ambox + table.ambox" above. */
body.mediawiki table.mbox-small {   /* For the "small=yes" option. */
    clear: right;
    float: right;
    margin: 4px 0 4px 1em;
    width: 238px;
    font-size: 88%;
    line-height: 1.25em;
}
body.mediawiki table.mbox-small-left {   /* For the "small=left" option. */
    margin: 4px 1em 4px 0;
    width: 238px;
    border-collapse: collapse;
    font-size: 88%;
    line-height: 1.25em;
}


/* Remove default styles for [[MediaWiki:Noarticletext]]. */
div.noarticletext {
    border: none;
    background: transparent;
    padding: 0;
}

#wpSave {
    font-weight: bold;
}

/* class hiddenStructure is defunct. See [[Wikipedia:hiddenStructure]] */
.hiddenStructure {
    display: inline ! important;
    color: #f00; 
    background-color: #0f0;
}

/* suppress missing interwiki image links where #ifexist cannot
   be used due to high number of requests see .hidden-redlink on 
   http://meta.wikimedia.org/wiki/MediaWiki:Common.css
*/
.check-icon a.new {
    display: none; 
    speak: none;
}

/* Removes underlines from certain links */
.nounderlines a,
.IPA a:link, .IPA a:visited { 
    text-decoration: none;
}

/* Standard Navigationsleisten, aka box hiding thingy
   from .de.  Documentation at [[Wikipedia:NavFrame]]. */
div.NavFrame {
    margin: 0;
    padding: 4px;
    border: 1px solid #aaa;
    text-align: center;
    border-collapse: collapse;
    font-size: 95%;
}
div.NavFrame + div.NavFrame {
    border-top-style: none;
    border-top-style: hidden;
}
div.NavPic {
    background-color: #fff;
    margin: 0;
    padding: 2px;
    float: left;
}
div.NavFrame div.NavHead {
    height: 1.6em;
    font-weight: bold;
    background-color: #ccf;
    position: relative;
}
div.NavFrame p,
div.NavFrame div.NavContent,
div.NavFrame div.NavContent p {
    font-size: 100%;
}
div.NavEnd {
    margin: 0;
    padding: 0;
    line-height: 1px;
    clear: both;
}
a.NavToggle {
    position: absolute;
    top: 0;
    right: 3px;
    font-weight: normal;
    font-size: 90%;
}

/* Hatnotes and disambiguation notices */
.rellink,
.dablink {
    font-style: italic;
    padding-left: 2em;
    margin-bottom: 0.5em;
}
.rellink i,
.dablink i {
    font-style: normal;
}

/* Style for horizontal UL lists */
.horizontal ul {
    padding: 0;
    margin: 0;
}
.horizontal li { 
    padding: 0 0.6em 0 0.4em;
    display: inline;
    border-right: 1px solid;
}
.horizontal li:last-child {
    border-right: none;
    padding-right: 0;
}

/* Allow transcluded pages to display in lists rather than a table.
   Compatible in Firefox; incompatible in IE6. */
.listify td    { display: list-item; }
.listify tr    { display: block; }
.listify table { display: block; }

/* Geographical coordinates defaults. See [[Template:Coord/link]]
   for how these are used. The classes "geo", "longitude", and
   "latitude" are used by the [[Geo microformat]].
 */
.geo-default, .geo-dms, .geo-dec  { display: inline; }
.geo-nondefault, .geo-multi-punct { display: none; }
.longitude, .latitude             { white-space: nowrap; }

/* When <div class="nonumtoc"> is used on the table of contents,
   the ToC will display without numbers */
.nonumtoc .tocnumber { display: none; }
.nonumtoc #toc ul,
.nonumtoc .toc ul {
    line-height: 1.5em;
    list-style: none;
    margin: .3em 0 0;
    padding: 0;
}
.nonumtoc #toc ul ul, 
.nonumtoc .toc ul ul { 
    margin: 0 0 0 2em; 
}

/* Allow limiting of which header levels are shown in a TOC;
   <div class="toclimit-3">, for instance, will limit to
   showing ==headings== and ===headings=== but no further
   (as long as there are no =headings= on the page, which
   there shouldn't be according to the MoS).
 */
.toclimit-2 .toclevel-1 ul,
.toclimit-3 .toclevel-2 ul,
.toclimit-4 .toclevel-3 ul,
.toclimit-5 .toclevel-4 ul,
.toclimit-6 .toclevel-5 ul,
.toclimit-7 .toclevel-6 ul {
    display: none;
}

/* Styling for Template:Quote */
blockquote.templatequote { 
     margin-top: 0; 
}
blockquote.templatequote div.templatequotecite { 
    line-height: 1em;
    text-align: left;
    padding-left: 2em;
    margin-top: 0;
}
blockquote.templatequote div.templatequotecite cite {
    font-size: 85%;
}

/* User block messages */
div.user-block {
    padding: 5px;
    margin-bottom: 0.5em;
    border: 1px solid #A9A9A9;
    background-color: #FFEFD5;
}

/* Prevent line breaks in silly places: 
   1) Links when we don't want them to
   2) Bold "links" to the page itself
   2) HTML formulae
   3) Ref tags with group names <ref group="Note"> --> "[Note 1]"
*/
.nowraplinks a,
.nowraplinks .selflink,
span.texhtml,
sup.reference a { 
    white-space: nowrap;
}

/* For template documentation */
.template-documentation {
    clear: both;
    margin: 1em 0 0 0;
    border: 1px solid #aaa; 
    background-color: #ecfcf4; 
    padding: 1em;
}

/* Inline divs in ImageMaps (code borrowed from de.wiki) */
.imagemap-inline div {
    display: inline;
}

/* Increase the height of the image upload box */
#wpUploadDescription {
    height: 13em;
}

/* Reduce line-height for <sup> and <sub> */
sup, sub {
    line-height: 1em;
}

/* Minimum thumb width */
.thumbinner {
    min-width: 100px;
}

/* Remove white border from thumbnails */
div.thumb {
    border: none;
}
div.tright {
    border: none;
    margin: 0.5em 0 0.8em 1.4em;
}
div.tleft {
    border: none;
    margin: 0.5em 1.4em 0.8em 0;
}

/* Makes the background of a framed image white instead of gray. */
/* Only visible with transparent images. */
div.thumb img.thumbimage {
    background-color: #fff;
}
 
/* The backgrounds for galleries. */
#content .gallerybox div.thumb {
    background-color: #F9F9F9;   /* Light gray padding */
}
/* Put a chequered background behind images, only visible if they have transparency */
.gallerybox .thumb img,
.filehistory a img,
#file img {
    background: white url("http://upload.wikimedia.org/wikipedia/commons/5/5d/Checker-16x16.png") repeat;
}
/* But not on articles, user pages, portals or with opt-out. */
.ns-0 .gallerybox .thumb img,
.ns-2 .gallerybox .thumb img,
.ns-100 .gallerybox .thumb img, 
.nochecker .gallerybox .thumb img {
    background: white;
}

/* Prevent floating boxes from overlapping any category listings,
   file histories, edit previews, and edit [Show changes] views */
#mw-subcategories, #mw-pages, #mw-category-media, 
#filehistory, #wikiPreview, #wikiDiff {
    clear: both;
}

/* Selectively hide headers in WikiProject banners */
.wpb .wpb-header             { display: none; }
.wpbs-inner .wpb .wpb-header { display: block; }     /* for IE */
.wpbs-inner .wpb .wpb-header { display: table-row; } /* for real browsers */
.wpbs-inner .wpb-outside     { display: none; }      /* hide things that should only display outside shells */

/* Styling for Abuse Filter tags */
.mw-tag-markers {
    font-family:sans-serif;
    font-style:italic;
    font-size:90%;
}

/* Fix so <tt>, <code>, <pre>, <kbd>, and <samp> tags get normal text size 
   also in some versions of Firefox, Safari, Konqueror, Chrome etc. 
   Remove "tt, code, pre, " once r69336 is live;
   remove the rest once r76322 is live. */
tt, code, pre, kbd, samp {
    font-family: monospace, "Courier New";
}
/* Same fix, but for inline code generated by #tag:syntaxhighlight */
span.mw-geshi {
    font-family: monospace, "Courier New" !important;
}

/* Remove bullets when there are multiple edit page warnings */
ul.permissions-errors > li {
    list-style: none;
}
ul.permissions-errors {
    margin: 0;
}

/* No linewrap on the labels of the login/signup page */
body.page-Special_UserLogin .mw-label label,
body.page-Special_UserLogin_signup .mw-label label { white-space : nowrap; }

/* Fix an alignment issue with oggplayer when rendered as center */
.center .ogg-player-options ul {
    margin: 0.3em 0px 0px 1.5em;
}

/* Disable the automatic text-size adjust of WebKit on iPhones etc.
   It scales some text, and not the other. Use none, or fixed percentage instead.
   Use media selector, because defining a value, overwrites platform defaults. */
@media only screen and (max-device-width: 480px) {
    body {
        -webkit-text-size-adjust: none;
    }
}

/* Pie chart test: Transparent borders */
.transborder {
    border: solid transparent;
}
* html .transborder {  /* IE6 */
    border: solid #000001;
    filter: chroma(color=#000001);
}

/* Avoid header sublines running into floating objects.
   Also fixes WP:BUNCH. bugzilla:26449.
   Remove when r79087 and r79091 are live. */
h1, h2, h3, h4, h5, h6 {
    overflow: hidden;
}

/* </syntaxhighlight> */