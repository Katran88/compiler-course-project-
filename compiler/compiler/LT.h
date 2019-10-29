#pragma once

#define	LT_MAXSIZE			1024		// ������������ ���������� ����� � ������� ������	
#define	LT_TI_NULLXDX		-1			// ��� �������� ������� ���������������				
#define	LEX_TYPE			't'			// ������� ��� ��� ������
#define	LEX_ID				'i'			// ������� ��� ��������������
#define	LEX_MAIN			'm'			// ������� ��� ������� �������
#define LEX_IF				'c'			// ������� ��� ����� if
#define	LEX_GLOBAL			'g'			// ������� ��� ����������� ���������� ����������
#define	LEX_LITERAL			'l'			// ������� ��� ��������
#define	LEX_FUNCTION		'f'			// ������� ��� function
#define	LEX_RETURN			'r'			// ������� ��� return
#define	LEX_PRINT			'p'			// ������� ��� print
#define	LEX_SEMICOLON		';'			// ������� ��� ;
#define	LEX_COMMA			','			// ������� ��� ,
#define	LEX_LEFTBRACE		'{'			// ������� ��� {
#define	LEX_RIGHTBRACE		'}'			// ������� ��� }
#define	LEX_LEFTHESIS		'('			// ������� ��� (
#define	LEX_RIGHTHESIS		')'			// ������� ��� )
#define	LEX_PLUS			'+'			// ������� ��� +
#define	LEX_MINUS			'-'			// ������� ��� -
#define	LEX_STAR			'*'			// ������� ��� *
#define	LEX_DIRSLASH		'/'			// ������� ��� /
#define	LEX_EQUAL_SIGN		'='			// ������� ��� =
#define	LEX_LESS_SIGN		'<'			// ������� ��� <
#define	LEX_MORE_SIGN		'>'			// ������� ��� >
#define	LEX_SAME_SIGN		's'			// ������� ��� ==
#define	LEX_DIFFERENT_SIGN	'e'			// ������� ��� !=


#define PARM_LEX_DEFAULT_EXT L".lex.txt" //��� ����� � ������ ������������ ������a
// ������� ������
namespace LT
{
	struct Entry						// ������ ������� ������
	{
		char lexema;					// ������
		int sn;							// ����� ������ � �������� ������
		int idxTI;						// ������ � ������� ��������������� ��� LT_TI_NULLIDX
		Entry();
		Entry(const char lex, int str_n, int idxTI);
	};

	struct LexTable						// ��������� ������� ������
	{
		int maxsize;					// ������� ������� ������ < LT_MAXSIZE
		int current_size;				// ������� ������ ������� ������ < maxsize
		Entry* table;					// ������ ����� ������� ������

		LexTable();

		void Add(Entry entry);					// ���������� ������
		Entry GetEntry(int n);					// �������� ������ ������� ������
		void PrintLexTable(const wchar_t* in);		// ����� ������ � ����
		void Delete();							// ������� ������� ������ (���������� ������)
	};
}