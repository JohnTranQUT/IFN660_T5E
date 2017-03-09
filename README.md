#Regular Expression Literals Scanner (Alfred)

##Todos
- [ ] **Week 2**
	- [ ] **Add Syntax Error Detection**
		- [ ] **Illegal REGEX_FIRST_CHAR**
		- [ ] REGEX Not Closing

##Completed
- [ ] **Week 2**
	- [x] Initialization
	- [x] Add REGEX_START
	- [x] Add REGEX_END
	- [x] Add REGEX_FLAGS
	- [x] Add REGEX_BODY

##Test Logs
Literal Type | Test Result | Test Scripts
--- | --- | ---
REGEX_START | Pass | `/`
REGEX_END | Pass | `//`
REGEX_FLAGS | Pass | `//`
REGEX_FLAGS | Pass | `//g`
REGEX_FLAGS | Pass | `//gmi`
REGEX_BODY | Pass | `/HelloWorld/gmi`
REGEX_BODY | Pass | `/Hello\/World/gmi`
REGEX_BODY | Pass | `/[Hello]{1,5}\/[World]+/`