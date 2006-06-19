/* manual_Manual.c
 *
 * Copyright (C) 1992-2003 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * pb 2003/05/28
 */

#include "ManPagesM.h"

void manual_Manual_init (ManPages me);
void manual_Manual_init (ManPages me) {

MAN_BEGIN ("Manual", "ppgb", 20040209)
INTRO ("The documentation system for the P\\s{RAAT} program.")
NORMAL ("You will get a manual window every time you choose anything from a #Help menu or press a #Help button.")
ENTRY ("How to find what you are looking for")
NORMAL ("You can navigate the manual in several ways:")
LIST_ITEM ("\\bu To go to the Intro, use the #H button.")
LIST_ITEM ("\\bu To go to the information behind a %link (a piece of blue text), #click on it.")
LIST_ITEM ("\\bu To go forward and backward through a tutorial with numbered pages, use \"1 >\" and \"< 1\".")
LIST_ITEM ("\\bu To %revisit previous pages, use the #< and #> buttons.")
LIST_ITEM ("\\bu To browse %alphabetically, use the horizontal scroll bar and the buttons "
	"named \"< 1\" and \"1 >\", or the ##Search for page (list)...# command in the ##Go to# menu.")
LIST_ITEM ("\\bu To find a page with a %%known title%, use the ##Search for page...# command.")
NORMAL ("The fastest way to find what you want is often the #Search button.")
ENTRY ("Search")
NORMAL ("In the text field after the Search button, you can type strings, separated by spaces. "
	"When you press the #Return (or #Enter) key, or click the #Search button, "
	"all manual pages are searched for the combination of strings that you typed. "
	"The titles of the 20 best matching pages are displayed as links.")
NORMAL ("##Example:# to know how to create a pitch contour from a sound, type")
CODE ("sou pit")
NORMAL ("and press #Return. The best matches should appear on top. These should include "
	"##Sound: To Pitch (ac)...# and ##Sound: To Pitch (cc)...#.")
NORMAL ("The search is case-insensitive. For instance, the search string \"$script\" will give you all "
	"the pages that contain the words %script, %Script, %description, %PostScript, or %SCRIPT, and so on.")
NORMAL ("#Background. The search algorithm uses the following heuristics:")
LIST_ITEM ("\\bu A match in the page title is better than one in the rest of the text.")
LIST_ITEM ("\\bu Pages with many matches are better than those with few.")
ENTRY ("Your own man pages")
NORMAL ("To create your own man pages, create @ManPages text files.")
MAN_END

MAN_BEGIN ("ManPages", "ppgb", 20040208)
INTRO ("You can create a documentation or education system with files that you and others "
	"can read into P\\s{RAAT} (with the @@Read from file...@ command). "
	"Your files will become a hypertext system very similar to the usual @Manual.")
ENTRY ("Example 1: a single document")
NORMAL ("If you create a single ManPages file, it will look like a manual with a single page. "
	"Here is an example:")
CODE ("ManPagesTextFile")
CODE ("\"Welkom\" \"miep\" 19970820 0")
CODE ("<intro> \"Hallo allemaal!\"")
CODE ("<entry> \"Belangrijk...\"")
CODE ("<normal> \"Hoogge\\bse\\\" \\\" erd publiek!\"")
CODE ("<normal> \"Einde.\"")
NORMAL ("A ManPages file should start with the following information:")
LIST_ITEM ("1. The word \"ManPagesTextFile\" on the first line.")
LIST_ITEM ("2. The title of the man page, between double quotes. "
	"This will be drawn at the top of the page. "
	"The name of the ManPages file should be derived from the title (see below).")
LIST_ITEM ("3. The author of the man page, between double quotes. "
	"This will be drawn at the bottom of the page.")
LIST_ITEM ("4. The date you created or modified the page, "
	"in the format year \\-- month (two digits) \\-- day (two digits), without spaces.")
LIST_ITEM ("5. The recording time. If this is not zero, "
	"three sound buttons (see below) will appear at the top of the page.")
LIST_ITEM ("6. A sequence of paragraph types and texts. "
	"You put the types between < and >, and the texts between double quotes "
	"(if your text contains a double quote, you should write two double quotes).")
NORMAL ("The format of a ManPages text file is rather free, as long as the first line is correct, "
	"the four required pieces of information are there in the correct order, "
	"and there is a correct alternation between paragraph texts and types. "
	"If you put multiple elements on a line, there should be at least one space between them. "
	"You may distribute texts across multiple lines, as long as you do not add any spaces:")
CODE ("<normal> \"Hoogge\\bse\\\" \\\" erd")
CODE ("publiek!\"")
NORMAL ("This will have exactly the same effect as above.")
ENTRY ("Example 2: multiple documents")
NORMAL ("The above example with a single document is not very useful. "
	"You will usually want to refer to other documents:")
CODE ("ManPagesTextFile")
CODE ("\"Welcome\" \"ppgb\" 19970820 1.0")
CODE ("<intro> \"Welcome to our transcription course.\"")
CODE ("<entry> \"Groups of speech sounds\"")
CODE ("<normal> \"You can listen to the following sounds")
CODE ("from the languages of the world,")
CODE ("pronounced by a single speaker (me):\\\"r")
CODE ("<list_item> \"\\@ Vowels, quite problematic for Dutch students!\"")
CODE ("<list_item> \"\\@ \\@ Dorsal fricatives\\@ , equally problematic!\"")
NORMAL ("With the symbol `\\@ ', you create a %link to another ManPages file. "
	"A link will be drawn in blue on your screen. "
	"In this example, you have created links to the files ##Vowels.man# "
	"and ##Dorsal_fricatives.man# in the same directory as the current file "
	"(all ##.man# files have to be in the same directory; this makes it likely "
	"that their names are unique). "
	"If the link contains spaces or other non-alphanumeric symbols, "
	"you have to use three `\\@ ' symbols, as shown; "
	"with a single word, you may use a single `\\@ '.")
NORMAL ("In resolving the file name, the ManPages system replaces spaces "
	"and other special symbols with underscores, "
	"and converts any initial lower-case character by its upper-case variant. "
	"For instance, if your link is \"\\@ \\@ back vowels\\@ \", "
	"the file name will be ##Back_vowels.man#.")
NORMAL ("The %title attribute of ##Back_vowels.man# must be equal to the link name, "
	"though capitalization of the first letter is allowed. "
	"Thus, the title of ##Back_vowels.man# will probably be \"Back vowels\". "
	"Likewise, the starting file with the title \"Welcome\" should have the name ##Welcome.man# "
	"if any other files refer to it.")
ENTRY ("Paragraph types")
NORMAL ("A normal paragraph will have type <normal>. The hypertext system will "
	"leave a blank space between paragraphs with this type. "
	"The first paragraph of a man page will normally have the type <intro>. "
	"Though this may look the same as <normal>, the search system of the @Manual "
	"may take account of the distinction.")
NORMAL ("Headings (like the title \"Paragraph types\" of this subsection) "
	"have type <entry>. This will be drawn in a larger character size.")
NORMAL ("For lists, you use the type <list_item>. You will often combine this with %button symbols, "
	"like in the following:")
CODE ("<normal> \"Choose a colour:\"")
CODE ("<list_item> \"\\bsbu \\@ Red.\"")
CODE ("<list_item> \"\\bsbu \\@ Green.\"")
CODE ("<list_item> \"\\bsbu \\@ Blue.\"")
NORMAL ("For text that should appear with a fixed character width, you use the type <code>.")
NORMAL ("For a paragraph that should be connected with the following paragraph "
	"without leaving a blank space "
	"(probably a list item or a definition), you use the type <tag>.")
NORMAL ("For a paragraph with a blank left margin, you use the type <definition>.")
ENTRY ("Special symbols and styles")
NORMAL ("You can use all of P\\s{RAAT}'s @@special symbols@ and @@text styles@, "
	"except that some %single text-style symbols have different meanings:")
LIST_ITEM ("\\bu A single percent sign introduces a word in italic: $$\\% pot$ gives %pot.")
LIST_ITEM ("\\bu A single number sign introduces a word in bold: $$\\# pot$ gives #pot.")
LIST_ITEM ("\\bu A single dollar sign introduces a word in monospace: $$\\$ pot$ gives $pot.")
LIST_ITEM ("\\bu A single underscore is rendered as an underscore: $$a_b$ gives a_b.")
NORMAL ("To create a single italic, bold, or subscripted letter, "
	"you revert to the usual technique for stretches of italic, bold, or subscripted text. "
	"So, to get %F__1_, you type $$\\% F_\\_ 1_.")
ENTRY ("Sound links")
NORMAL ("Your text may contain links to sound files. They are drawn in blue. "
	"The format is:")
CODE ("<normal> \"You should know that \\@ \\@ \\bsFIct.aifc|\\bsct\\@  is more open than "
	"\\@ \\@ \\bsFIo.aifc|o\\@ .\"")
NORMAL ("On your screen, you will see an #\\ct and an #o symbol, both drawn in blue. "
	"If you click on one of these sound links, one of the sound files ##ct.aifc# "
	"or ##o.aifc# will be played.")
NORMAL ("The format of the sound link \"$$\\@ \\@ \\bsFIo.aifc|o\\@ $\" is to be understood "
	"as follows. The pipe symbol separates the link information (\\bsFIo.aifc) from the viewable "
	"link text (o). The link information is introduced with a symbol (\\bsFI) that "
	"tells the manual system that a sound file name follows. The manual system reads "
	"this file, sees that it contains a sound, and plays that sound. "
	"You can use relative path names, e.g., \\bsFIsounds/o.aifc refers to the file "
	"##o.aifc# in the subdirectory #sounds, which must be contained in the same directory as the ##.man# files; "
	"use the forward slash (/) if you want your man pages to run on all platforms (Windows, Macintosh, Unix).")
ENTRY ("Script links")
NORMAL ("Your text may contain links to Praat scripts. They are drawn in blue. "
	"The format is:")
CODE ("<normal> \"Here is a script that \\@ \\@ \\bsSCdraw.praat|draws\\@  what you have selected.\"")
NORMAL ("On your screen, you will see the word #draws, drawn in blue. "
	"If you click on it, the script ##draw.praat# will be executed. The string \"$$\\bsSC$\" indicates "
	"that a script file name follows. As with sounds, you can use relative file paths. The script can take "
	"arguments:")
CODE ("<normal> \"This script \\@ \\@ \\bsSCload2files.praat hello.wav hello.TextGrid|loads\\@  some files.\"")
NORMAL ("If the script file name or any arguments except the last contain spaces, they have to be enclosed "
	"within double quotes, which have to be doubled again in the ManPage code:")
CODE ("<normal> \"Here is a script that \\@ \\@ \\bsSC\\\" \\\" my scripts/draw.praat\\\" \\\" |draws\\@  what you have selected.\"")
CODE ("<normal> \"This script \\@ \\@ \\bsSC\\\" \\\" my scripts/load2files.praat\\\" \\\"  \\\" \\\" my sounds/hello.wav\\\" \\\"  my textgrids/hello.TextGrid|loads\\@  some files.\"")
ENTRY ("How to separate link information and link text")
NORMAL ("The separation between link information and viewable link text, as seen "
	"in the above description of sound and script links, is actually a general mechanism "
	"in the hypertext system. For instance, if you want to see the text \"x\" "
	"in blue on your screen, and create a link from it to the page \"Dorsal fricatives\", "
	"you specify the link as $$\\@ \\@ Dorsal fricatives|x\\@ $.")
ENTRY ("Sound buttons")
NORMAL ("If the %%Recording time% attribute is not 0, "
	"three buttons will appear at the top of the page:")
NORMAL ("1. The #%Rec button allows you to record a sound from the microphone.")
NORMAL ("2. The #%Play button allows you to play this recorded sound. "
	"In this way, you can compare your own utterances with the sounds "
	"behind the sound links, for example.")
NORMAL ("3. The #%Pub button copies the latest sound to the list of objects, "
	"allowing you to perform analyses on it, save it to disk, et cetera. "
	"The latest sound may be a sound that you recorded with the #%Rec button, "
	"a sound that you played with the #%Play button, "
	"or a sound that you played by clicking on a sound link, "
	"whichever occurred most recently.")
MAN_END

}

/* End of file manual_Manual.c */