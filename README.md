# StringHeur
Strings Heuristic Analyzer - tool to detect and classify (suspected) strings via regexp matching and heuristic rules. 

## _Examples:_
![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur3.png)

![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur2.png)

![alt text](https://github.com/progressionnetwork/StringHeur/blob/master/StringsHeur1.png)

## StringHeur: Strings Heuristic Analyzer
StringHeur is a powerful tool designed to detect and classify potential strings in various file formats using regexp matching and heuristic rules. The primary goal of this tool is to improve malware analysis by effectively identifying suspicious strings and providing valuable insights into the behavior of potentially malicious files.

## Overview
StringHeur is capable of analyzing parsed strings from various sources, such as MalwareAnalyser.io's output of Windows cmd.exe PE files. It uses a combination of regexp rules and heuristic analysis to detect and classify suspicious strings, making it an invaluable tool for malware analysts and security researchers.

## Key Features
Regexp matching: Utilizes regular expressions to identify known patterns in strings.
Heuristic rules: Employs heuristics to classify detected strings based on their characteristics.
Test cases: Includes a set of common test cases to verify the accuracy of regexp rules.
Integration with MalwareAnalyser.io: Seamlessly analyzes parsed strings from the MalwareAnalyser.io's output of Windows cmd.exe PE files.
Export functionality: Saves detected and classified strings to a new text file for further analysis.
Getting Started
Clone the repository or download the source code as a ZIP file.
Extract the contents of the ZIP file (if applicable).
Install the required dependencies.
Run the stringheur.py script with your desired arguments.

## Dependencies
Python 3.x
regex
MalwareAnalyser.io's API (if you plan to use the integration feature)

## Usage
Run the stringheur.py script followed by the path to the input file and the desired output file:
```python stringheur.py input_file.txt output_file.txt```
Note: If you want to use the MalwareAnalyser.io integration, provide the path to the parsed MalwareAnalyser.io output file and the API key:

```python stringheur.py malware_analyser_output.txt output_file.txt --api_key your_api_key```

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contact
If you have any questions, feel free to contact us on telegram @uberwow.

## Acknowledgements
Special thanks to the MalwareAnalyser.io team for providing a powerful malware analysis platform.
This project was inspired by the need for more advanced string analysis in malware research.

## *TODO:*
* Add more regexp rules;
* Fix current regexp rules;
* Add heuristic rules to detect suspected strings;
* Add more testcases;
* Rewrite to python;
