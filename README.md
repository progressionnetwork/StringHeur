# StringHeur
Strings Heuristic Analyzer - tool to detect and classify (suspected) strings via regexp matching and heuristic rules. 

It uses common testcases to test regexp rules.
Also it analyse parsed strings from MalwareAnalyser.io's output of (Windows) cmd.exe PE file as an example and save detected (classified) strings to a new text file.

This code is a part of MalwareAnalyser.io's string parser (analyser) module.
Regexp  rules for now is not so perfect and will be increased in future.

Feel free to commit it.

_Example:_
![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur3.png)

![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur2.png)

![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur1.png)

*TODO:*
* Add more regexp rules;
* Fix current regexp rules;
* Add heuristic rules to detect suspected strings;
* Add more testcases;
* Rewrite to python;
