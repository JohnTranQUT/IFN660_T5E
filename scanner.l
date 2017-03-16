%{
#include "y.tab.h"
%}
/* Start of String regex n8706638 */
LineTerminator (\x0D\x2028\x2029\x0A)
LineCont (\\{LineTerminatorSeq})
LineTerminatorSeq (\x0A\x0D|\x0D[^\x0A]|[\x0A\x2028\x2029])
EscSeq ({CharEscSeq}|0[^0-9]|{HexEscSeq}|{UnicodeEscSeq})
CharEscSeq ([{SingleEscChar}]|{NonEscChar})
SingleEscChar ('"\\bfnrtv)
NonEscChar ([^{EscChar}{LineTerminator}])
EscChar ({SingleEscChar}0-9xu)
HexEscSeq (x[0-9A-Fa-f]{2})
UnicodeEscSeq (u([0-9A-Fa-f]{4})|\{[0-9A-Fa-f][0-9A-Fa-f]*\})
DoubleStrChar ([ 0-9]|[^"\\\x0D\x2028\x2029\x0A]|\\{EscSeq}|{LineCont})
SingleStrChar ([ 0-9]|[^'\\\x0D\x2028\x2029\x0A]|\\{EscSeq}|{LineCont})
/* End of String regex */

%%

 /* n08706638 Null literal start */
null        {return NULL_L;}
 /* end of Null literal  */
 
 /* Start of String Literal */

(\"{DoubleStrChar}*\") {
    yylval.name = _strdup(yytext);
	return STRING_L;}
(\'{SingleStrChar}*\') {
    yylval.name = _strdup(yytext);
	return STRING_L;}
	
/* end of String Literal */

.* {
    yylval.name = "Syntax Error: unhandled pattern";
    return ERROR;}

%%
int yywrap()
{
    return 1;
}
