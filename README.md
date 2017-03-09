#Regular Expression Literals Scanner (Alfred)

##Todos

##Completed
- [x] Initialization
- [x] Add REGEX_START
- [x] Add REGEX_END
- [x] Add REGEX_FLAGS
- [x] Add REGEX_BODY
- [x] Add Syntax Error Detection
	- [x] Illegal REGEX_FIRST_CHAR
	- [x] REGEX Not Closing

##Test Logs
Literal Type | Test Result | Test Scripts | Remark
--- | --- | --- | ---
REGEX_START | Passed | `/` | 
REGEX_END | Passed | `//` | 
REGEX_FLAGS | Passed | `//` | 
REGEX_FLAGS | Passed | `//g` | 
REGEX_FLAGS | Passed | `//gmi` | 
REGEX_BODY | Passed | `/HelloWorld/gmi` | 
REGEX_BODY | Passed | `/Hello\/World/gmi` | 
REGEX_BODY | Passed | `/[Hello]{1,5}\/[World]+/` | 
ILL_FIRST_CHAR | Passed | `//` | 
ILL_FIRST_CHAR | Passed | `/*` | 
REGEX_NOT_CLO | Passed | `/HelloWorld\/gmi`<br>` ` | 
**REGEX_NOT_CLO** | **Failed** | `/HelloWorld\/gmi` | Failed only when <br>it is followed by `<<EOF>>`