%{
#include <iostream>
#include <y.tab.h>
#include <string>
#include <list>
#include <vector>


using namespace std;
string templateLiteral;
%}

d [0-9]
w [a-zA-Z_]

sourceChar [a-zA-Z0-9_ \n]
%x template_head
%x template_start
%x template_component
%%
`					            {
									BEGIN(template_start);								
									templateLiteral="";
									printf("\n");
								}

<template_start>{sourceChar}*\$\{        {
									//Template head
									BEGIN(template_component);
									templateLiteral+=yytext;
								}

<template_component>{sourceChar}+/\}     {
									printf("\t*)Literal component: ${%s} \n",yytext);									
									BEGIN(template_start);									
									templateLiteral+=yytext;
								}

<template_start>\}{sourceChar}*\$\{		{
									//Template middle
									BEGIN(template_component);
									templateLiteral+=yytext;
								}
<template_start>\}{sourceChar}*\`		{
									//Literal tail								
									templateLiteral+=yytext;								
									yylval.templateLiteral=_strdup( templateLiteral.c_str());
									BEGIN(0);
									return TEMPLATE_LITERAL; 								
								}
<template_start>{sourceChar}*\`          {
									//No substitution							
									BEGIN(0);
									templateLiteral+=yytext;
									yylval.templateLiteral=_strdup( templateLiteral.c_str());
									return TEMPLATE_LITERAL;
								}


%%

int yywrap()
{
    return 1;
}
