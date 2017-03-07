%%
/* enter the scanner here */
null        {return null;}
%%
int yywrap()
{
    return 1;
}