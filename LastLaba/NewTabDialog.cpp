#include "NewTabDialog.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void RunDialog() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LastLaba::NewTabDialog form;
	Application::Run(%form);
}