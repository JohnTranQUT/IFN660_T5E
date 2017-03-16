<<<<<<< HEAD
# IFN660-T5E GitHub Repository

## Message
Merging Branches, Please do not modify your scanner code. 
Merged branches will be deleted. 
If you want to modify your scanner files, please pull the master repository, create branch based on master repository, modify your code, merge to your master, and push to GitHub.
**For one-token-every-member scanner repository, it has been moved to one-token-scanner branch.**

## Status
Merging
- [ ] Alfred
- [ ] Ray
- [ ] Michael
- [ ] Gem
- [x] Jason
- [ ] John
- [x] Jin
=======
# Regular Expression Literals Scanner (Alfred)
Notice: Syntax Error Detection has been removed. 

## Todos

## Completed
- [x] Initialization
- [x] Add REGEX_START
- [x] Add REGEX_END
- [x] Add REGEX_FLAGS
- [x] Add REGEX_BODY
- [x] ~~Add Syntax Error Detection~~
	- [x] ~~Illegal REGEX_FIRST_CHAR~~
	- [x] ~~REGEX Not Closing~~

## Test Logs
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
>>>>>>> 0f6687b226cc5e9dc3b7a2afcec7040b9c813118
