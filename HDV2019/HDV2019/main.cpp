#include "stdafx.h"

void wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "Russian");
	Log::LOG log;

	try
	{
		Parm::PARM param = Parm::getparm(argc, argv);
		log = Log::getlog(param.log);
		Log::WriteLine(log, "����: ", "��� ������\n", "");
		Log::WriteLog(log);
		Log::WriteParm(log, param);
		In::IN in = In::getin(param.in);
		Log::WriteIn(log, in);
		LT::LexTable lexTable;
		IT::IdTable	idTable;

#pragma region lexAnaliz

		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		lexAnaliz(in, lexTable, idTable);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << ">>>>>>>>>>>Lex analiz: " << time_span.count() << " seconds." << std::endl << std::endl;

		lexTable.PrintLexTable(param.in);
		idTable.PrintIdTable(param.in);

#pragma endregion

#pragma region sintaxAnaliz

		#ifdef DEBUG
		MFST_TRACE_START
		#endif // DEBUG

		MFST::MFST* sintaxAnaliz = new MFST::MFST(lexTable, GRB::getGreibach());

		t1 = std::chrono::high_resolution_clock::now();
		sintaxAnaliz->start();
		t2 = std::chrono::high_resolution_clock::now();

		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "\n>>>>>>>>>>>Sintax analiz: " << time_span.count() << " seconds." << std::endl << std::endl;

		sintaxAnaliz->saveoutputTree();
		sintaxAnaliz->printRules();

		
#pragma endregion

#pragma region semantikAnaliz

		t1 = std::chrono::high_resolution_clock::now();
		SemantikAnaliz(sintaxAnaliz->storestate, sintaxAnaliz->grebach, lexTable, idTable);
		t2 = std::chrono::high_resolution_clock::now();

		lexTable.PrintLexTable(param.in);

		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "\n>>>>>>>>>>>Semantik analiz: " << time_span.count() << " seconds." << std::endl << std::endl;

#pragma endregion

#pragma region code_generation
		t1 = std::chrono::high_resolution_clock::now();
		generation(lexTable, idTable, sintaxAnaliz->storestate);
		t2 = std::chrono::high_resolution_clock::now();

		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "\n>>>>>>>>>>>Code generation: " << time_span.count() << " seconds." << std::endl << std::endl;
#pragma endregion

		delete sintaxAnaliz;
		lexTable.Delete();
		idTable.Delete(); 
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
		Log::Close(log);
	}
}