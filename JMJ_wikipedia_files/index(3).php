/* <syntaxhighlight lang="css"> */

/* Don't display some stuff on the main page */
body.page-Main_Page #deleteconfirm,
body.page-Main_Page #t-cite,
body.page-Main_Page #footer-info-lastmod,
body.page-Main_Page #siteSub,
body.page-Main_Page #contentSub,
body.page-Main_Page h1.firstHeading {
  display: none !important;
}

body.page-Main_Page #mp-topbanner {
  margin-top: 0 !important;
}

#coordinates {
  position: absolute;
  top: 0em;
  right: 0em;
  float: right;
  margin: 0.0em;
  padding: 0.0em;
  line-height: 1.5em;
  text-align: right;
  text-indent: 0;
  font-size: 85%;
  text-transform: none;
  white-space: nowrap;
}

/* For positioning icons at top-right, used in Templates
   "Spoken Article" and "Featured Article" */
div.topicon {
  position: absolute;
  top: -2em;
  margin-right: -10px;
  display: block !important;
}

/* FR topicon position */
div.flaggedrevs_short {
  position: absolute;
  top: -3em;
  right: 80px;
  z-index: 1;
  margin-left: 0;
  /* Because this is not yet a topicon, we emulate it's behavior, this ensure compatibility with edit lead section gadget */
  margin-right: -10px;
}

/* Menu over FR box */
div.vectorMenu div {
  z-index: 2;
}

/* Display "From Wikipedia, the free encyclopedia" */
#siteSub {
  display: inline;
  font-size: 92%;
  font-weight: normal;
}

/* {{tl|Link GA}} */
#mw-panel div.portal div.body ul li.GA {
  background: url("http://upload.wikimedia.org/wikipedia/commons/4/42/Monobook-bullet-ga.png") no-repeat 0% 0%;
  margin-left: -1.25em;
  padding-left: 1.25em;
}

/* {{tl|Link FA}} */
#mw-panel div.portal div.body ul li.FA {
  background: url("http://upload.wikimedia.org/wikipedia/commons/d/d4/Monobook-bullet-star.png") no-repeat 0% 0%;
  margin-left: -1.25em;
  padding-left: 1.25em;
}

/* Increase fontsize of diffs */
td.diff-context, td.diff-addedline, td.diff-deletedline {
  font-size: 85%;
  vertical-align: top;
}

/* Adjust font-size for inline HTML generated TeX formulae */
.texhtml {
  font-family: 'Times New Roman', serif;
  font-size: 120%;
  line-height: 1em;
}

/* Blue instead of yellow padlock for secure links. */
#bodyContent a.external[href ^="https://"],
.link-https {
  background: url("http://upload.wikimedia.org/wikipedia/en/0/00/Lock_icon_blue.gif") center right no-repeat;
  padding-right: 16px;
}

/* Soft redirect (bug:26544) */
.redirectText {
  font-size: 150%;
  margin: 5px;
}

/* Fix for empty diff-context lines. Remove when r75658 is live. */
td.diff-marker {
  height: 1.5em;
}

/* </syntaxhighlight> */