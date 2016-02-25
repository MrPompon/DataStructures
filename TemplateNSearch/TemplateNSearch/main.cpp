#include "stdafx.h"
#include "main.h"
#include "TemplateCity.h"
int main(int argc, _TCHAR* argv[])
{
	TemplateCity* templateCity=new TemplateCity;
	if (templateCity->Initialize()){
		templateCity->Update();
	}
	delete templateCity;
	templateCity = nullptr;
	return 0;
}

