# Bison Template
**Scanner** rules require manual edit:
- [ ] TemplateLiteral - Jason
- [x] BinaryIntegerLiteral - John
- [x] OctalIntegerLiteral - John
- [x] HexIntegerLiteral - John

## **Parser** Grammer Rules
**BOLD** are required
Non-bold are not required and have points for expansion. Please mark completed and add where required.
Please add when branching
- [x] **Script**
- [x] **ScriptBody_opt**
- [x] **ScriptBody**
- [x] **StatementList**
- [x] **StatementListItem**
- [x] **Statement**
- [x] Declaration
	- [ ] *HoistableDeclaration*
	- [ ] *ClassDeclaration*
	- [ ] *LexicalDeclaration*
- [x] BlockStatement
	- [x] *Block*
		- [x] *StatementList_opt*
- [x] VariableStatement
	- [x] *VariableDeclarationList*
		- [x] *VariableDeclaration*
			- [x] *BindingIdentifier*
				- [x] *Initializer_opt*
				- [x] *Initializer*
			- [x] *BindingPattern*
				- [x] *ObjectBindingPattern*
					- [x] *BindingPropertyList*
					- [x] *BindingProperty*
						- [x] *SingleNameBinding*
							- [x] *Initializer_opt* ALREADY MADE
							- [x] *BindingIdentifier*
						- [x] *PropertyName*
							- [x] *LiteralPropertyName*
							- [x] *ComputedPropertyName*
						
						- [ ] *BindingElement*
				- [ ] *ArrayBindingPattern*
- [x] **EmptyStatement**
- [x] **ExpressionStatement**
- [x] IfStatement
- [ ] BreakableStatement
- [ ] ContinueStatement
- [ ] BreakStatement
- [ ] ReturnStatement
- [ ] WithStatement
- [ ] LabelledStatement
- [ ] ThrowStatement
- [ ] TryStatement
- [ ] DebuggerStatement
- [x] **Expression**
- [x] **AssignmentExpression**
- [x] **ConditionalExpression**
- [ ] YieldExpression
- [ ] ArrowFunction
- [x] **LeftHandSideExpression**
- [x] **NewExpression**
- [ ] CallExpression
- [x] **LogicalORExpression**
- [x] **MemberExpression**
- [x] **LogicalANDExpression**
- [x] **PrimaryExpression**
- [ ] MemberExpression
- [ ] SuperProperty
- [ ] MetaProperty
- [ ] Arguments
- [x] **BitwiseORExpression**
- [x] **IdentifierReference**
- [x] **Literal**
- [ ] ArrayLiteral
- [ ] ObjectLiteral
- [ ] FunctionExpression
- [ ] ClassExpression
- [ ] GeneratorExpression
- [ ] CoverParenthesizedExpressionAndArrowParameterList
- [x] **BitwiseXORExpression**
- [x] **Identifier**
- [x] **BitwiseANDExpression**
- [x] **NumericLiteral**
- [x] **EqualityExpression**
- [x] **RelationalExpression**
- [x] **ShiftExpression**
- [x] **AdditiveExpression**
- [x] **MultiplicativeExpression**
- [x] **ExponentiationExpression**
- [x] **UnaryExpression**
- [x] **UpdateExpression**
- [x] **IdentifierName**
- [x] **TemplateLiteral**
- [x] **RegularExpressionLiteral**
- [x] **NullLiteral**
- [x] **StringLiteral**
- [x] **AssignmentOperator**
- [x] **MultiplicativeOperator**
- [x] **empty**


Rules removed from scanner.l are stored in `dump.txt` file. Refer if needed.