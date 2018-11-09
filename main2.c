
    /********* main2.c : 字句解析のテスト *********/

#include <stdio.h>
#include "getSource.h"

void printToken(Token token)
{
	printf("%d", token.kind);    /*　tokenの種類（KeyId）を整数で出力　*/
	if (token.kind == Id)
		printf("\t%s", token.u.id);  /* Identifierならば，名前も出力 */
	if (token.kind == Num)
		printf("\t%d", token.u.value);	/* Numならば，値を出力 */
	printf("\n");
}

main()
{
	char fileName[30];		/*　ソースプログラムファイルの名前　*/
	Token token;

	printf("enter source file name\n");
	scanf("%s", fileName);
	if (!openSource(fileName))	/*　ソースプログラムファイルのopen　*/
		return;			/*　openに失敗すれば終わり　*/

	initSource();			/*　getSourceの初期設定　*/
	while (1) {
		token = nextToken();	/*　次のトークンを読む　*/
		printToken(token);	/*　読んだトークンを印字　*/
		if (token.kind == Period)
			break;
	}
	finalSource();
	closeSource();			/*　ソースプログラムファイルのclose　*/
}
