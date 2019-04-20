Lexer
=====

Token
-----

##### Controller operator


* Redirection
	* `|`
	* `<` `>`
	* `<<` `>>`
	* `[n]>& [n]&>` `[n]<& [n]<<&`
* Logical separator
	* `&&` `||`
* Command separator
	* `;`
* Descriptor closure
	* `-` with `[n]&<- [n]&>- [n]<&- [n]>&-`

##### Expansion

* `$` `~`
* `"double"` `'simple'` `` `back` ``

##### Word

* `[A-Za-z0-9!@#%^*()-_=+[]{}?/.,]`

##### White space
* `space` `tabs` `new line`

##### OPTIONAL SCRIPT (Reserved keyword)

* `if` `elif` `else`
* `while` `for`
* `+` `-` `*` `/` `%`
* `identifier`

```
'<'                                =>  TOK_REDIR
'>'                                =>  TOK_REDIR
'<<'                               =>  TOK_REDIR
'>>'                               =>  TOK_REDIR
'|'                                =>  TOK_PIPE
';'                                =>  TOK_SEP
'&&'                               =>  TOK_AND
'||'                               =>  TOK_OR
'[\n\t]'                           =>  TOK_WSPACE
'[A-Za-z0-9!@#%^*()-_=+[]{}?/.,]'  =>  TOK_WORD
```

Precedences
-----------

```
%left '>' '>>' '<' '<<' '>&' '<&' '&>' '&<'
%left '||' '&&'
%left ';'
```
