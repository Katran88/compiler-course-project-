#include "Error.h"

namespace Error
{
	// ����� ������: 0-99 - ��������� ������
	//				 100-109 - ������ � ������� �����/������
	//				 110-119 - ������ �������� � ������ ������
	//				 120-129 - ����������� ������
	//				 130-139 - �������������� ������
	//				 400-415 - ������������� ������
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"),

		ERROR_ENTRY_NODEF(2),		ERROR_ENTRY_NODEF(3),		ERROR_ENTRY_NODEF(4),
		ERROR_ENTRY_NODEF(5),		ERROR_ENTRY_NODEF(6),		ERROR_ENTRY_NODEF(7),
		ERROR_ENTRY_NODEF(8),		ERROR_ENTRY_NODEF(9),		ERROR_ENTRY_NODEF10(10),
		ERROR_ENTRY_NODEF10(20),	ERROR_ENTRY_NODEF10(30),	ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50),	ERROR_ENTRY_NODEF10(60),	ERROR_ENTRY_NODEF10(70),
		ERROR_ENTRY_NODEF10(80),	ERROR_ENTRY_NODEF10(90),

		ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "�� ������� ������� ���� ��� ��������� ����"),
		ERROR_ENTRY_NODEF(102),		ERROR_ENTRY_NODEF(103),

		ERROR_ENTRY(104, "��������� ����� �������� ���������"),

		ERROR_ENTRY_NODEF(105),		ERROR_ENTRY_NODEF(106),		ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),		ERROR_ENTRY_NODEF(109),

		ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "������������ ������ � �������� ���� (-in)"),
		ERROR_ENTRY(112, "������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113, "����, ���������� ��� -in:, ����"),
		ERROR_ENTRY_NODEF(114),		ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116),		ERROR_ENTRY_NODEF(117),
		ERROR_ENTRY_NODEF(118),		ERROR_ENTRY_NODEF(119),

		ERROR_ENTRY(120, "������� ������ �����������."),
		ERROR_ENTRY(121, "��������������� �������"),
		ERROR_ENTRY(122, "������� ��������������� �����������."),
		ERROR_ENTRY(123, "���������� ��������������"),
		ERROR_ENTRY(124, "����������� ������"),
		ERROR_ENTRY(125, "�� ������� ������� ���� � ���������(��� ����������������)"),
		ERROR_ENTRY(126, "������� ������� �������"),
		ERROR_ENTRY(127, "�������� ������ ���������� ��������"),
		ERROR_ENTRY(128, "������� ������� ��� ����������"),
		ERROR_ENTRY(129, "����������� ����������"),
		ERROR_ENTRY(130, "�������� ��������� ���������"),
		ERROR_ENTRY(131, "��������� ������� � ���������"),
		ERROR_ENTRY(132, "������ � ���������"),
		ERROR_ENTRY(133, "������ � ���������� �������"),
		ERROR_ENTRY(134, "������ � ���������� ���������� �������"),
		ERROR_ENTRY(135, "��������� �������� � ���������"),
		ERROR_ENTRY(136, "������ � ������� ����� � ����"),
		ERROR_ENTRY(137, "��������� �������� � ������� ����� � ����"),
		ERROR_ENTRY(138, "�������� ���������� ��������"),
		ERROR_ENTRY(139, "������������ ����������������� ������������������ ��������"),
		ERROR_ENTRY_NODEF10(140),	ERROR_ENTRY_NODEF10(150),	
		ERROR_ENTRY_NODEF10(160),	ERROR_ENTRY_NODEF10(170),	
		ERROR_ENTRY_NODEF10(180),	ERROR_ENTRY_NODEF10(190),	
		ERROR_ENTRY_NODEF100(200),
		ERROR_ENTRY_NODEF100(300),
		ERROR_ENTRY(400, "���������� ������������� ��� ��������������� �������� � ���� ��������������"),
		ERROR_ENTRY(401, "����������� ����� ����� � ���������(main)"),
		ERROR_ENTRY(402, "�������� ��� ������������� ��������"),
		ERROR_ENTRY(403, "��������� ������������ ���������� ���������� �������"),
		ERROR_ENTRY(404, "��������������� ����� ���������� � ����������� ���������� ��� ������ �������"),
		ERROR_ENTRY(405, "���������� �������� ��������� ����� ����� �������"),
		ERROR_ENTRY(406, "������ � ��������� ���������"),
		ERROR_ENTRY(407, "����� ����������� �������"),
		ERROR_ENTRY(408, "���������� ����������� �������� � ������� ����������"),
		ERROR_ENTRY(409, "����� �� �������� ���������� ������������� ��������"),
		ERROR_ENTRY(410, "����� �� �������� ����������� ������� ��� STR"),
		ERROR_ENTRY(411, "����������� �����-���� �������� ����� ������ ����������"),
		ERROR_ENTRY(412, "�� ���� ������������ ����� ����������� ������������ �������� 4� �����"),
		ERROR_ENTRY(413, "cprint ��������� ������ ��� ������ str"),
		ERROR_ENTRY(414, "������� ������ ������� ��� ����� � ���� if"),
		ERROR_ENTRY(415, "� ��������� ����� ���� ������ ���� ����� �����(main)"),
		ERROR_ENTRY(416, "����������� ������� ��������� ����� ��� main"),
		ERROR_ENTRY_NODEF(417),		ERROR_ENTRY_NODEF(418),
		ERROR_ENTRY_NODEF(419),
		ERROR_ENTRY_NODEF10(420),	ERROR_ENTRY_NODEF10(430),
		ERROR_ENTRY_NODEF10(440),	ERROR_ENTRY_NODEF10(450),
		ERROR_ENTRY_NODEF10(460),	ERROR_ENTRY_NODEF10(470),
		ERROR_ENTRY_NODEF10(480),	ERROR_ENTRY_NODEF10(490),
		ERROR_ENTRY_NODEF100(500),	ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700),	ERROR_ENTRY_NODEF100(800),
		ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
			return errors[id];
		else
			return errors[0];
	}

	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			errors[id].errorPosition.col = col;
			errors[id].errorPosition.line = line;
			return errors[id];
		}
		else
			return errors[0];
	}
}