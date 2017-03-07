%%
/* enter the scanner here */
null        {return null;}
true                          { return true; }
false                        { return false; }
%%
int yywrap()
{
    return 1;
}