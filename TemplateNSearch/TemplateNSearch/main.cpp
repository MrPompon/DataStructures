#include "stdafx.h"
#include "main.h"
#include "TemplateCity.h"
int main(int argc, _TCHAR* argv[])
{
	TemplateCity templateCity;
	if (templateCity.Initialize()){
		templateCity.Update();
	}
	return 0;
}

