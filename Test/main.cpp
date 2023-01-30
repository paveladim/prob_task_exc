#include <Windows.h>
#include <cstdlib>

int main() {
	HINSTANCE load;
	load = LoadLibrary(L"Curves.dll");
	typedef void (*task) ();
	task Task;
	Task = (task)GetProcAddress(load, "task");
	Task();
	system("pause");
	return 0;
}