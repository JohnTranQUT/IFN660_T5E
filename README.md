#Numeric Literals Scanner (John)

##Important Links
- [Flex Reference](http://www.delorie.com/gnu/docs/flex/flex.html)
- [Google Doc Link](https://drive.google.com/open?id=0B9oGgiMd13T8TlFodFZ1dkstZ0k)
- [ECMA Standard](http://www.ecma-international.org/ecma-262/7.0/index.html)
- [FaceBook Group](https://www.facebook.com/groups/1294849777217759/)
- [Readme.md cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

##Completed/Todos
- [x] Initialization
- [x] Identify Decimal with . only
- [x] Identify Decimal with 0.
- [x] Identify Decimal with 0 only
- [x] Identify Decimal with Exponent
- [x] Binary
	- [x] Use start conditions
	- [x] Stores and shows value
- [x] Octal
	- [x] Use start conditions
	- [x] Stores and shows value
- [x] Hexidecimal
	- [x] Use start conditions (Not Req)
	- [x] Stores and shows value
- [x] Line Terminators
- [x] Comments
	- [x] Use start conditions (Not Req)
- [x] Whitespace
- [ ] Get test.js file working

##Test Logs
Literal Type | Test Result | Test Scripts | Remark
--- | --- | --- | ---
NUMERIC_Decimal_Integers | Passed | 0 <br/>423 | 
NUMERIC_Decimals | Passed | .12089<br/>0.12089| 
NUMERIC_Exponent | Passed | 0e1239<br/>129e9232<br/>.2e34<br/>0.2e43<br/>0.2E-43 | 
NUMERIC_Binary| Passed | 0b1001<br/>0B1001 | Has Binary Start
NUMERIC_Octal | Passed | 0o72314<br/>0O72314 | Has Octal Start
NUMERIC_Hexidecimal | Passed | 0xAdF123148<br/>0XAdF123148 | Hexidecimal Start Not Required
COMMENTS_SingleLine | Passed | // one line comment | No start conditions required because content ignored
COMMENTS_MultiLine | Passed | /\* one line comment \*/ | No start conditions required because content ignored
LINE_TERMINALS | Passed | U+000A LINE FEED (LF)	<LF> <br/>U+000D CARRIAGE RETURN (CR) <CR> | 
LINE_TERMINALS | **Failed** | U+2028 LINE SEPARATOR <LS> <br/>U+2029 PARAGRAPH SEPARATOR <PS>| Problem with identifying way to convert hexidecimal
WHITE_SPACE | Passed | U+0009 TABS <TAB> <br/>U+000B LIKE TAB <VT> <br/>U+000C FORM FEED <FF> <br/>U+0020 SPACE <SP> | 
WHITE_SPACE | **Failed** | U+00A0 NO-BREAK SPACE <NBSP> <br/>U+FEFF ZERO WIDTH NO-BREAK SPACE <ZWNBSP> | Problem with identifying way to convert hexidecimal
