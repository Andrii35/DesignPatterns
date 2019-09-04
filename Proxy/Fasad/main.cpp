#include"Proxy.h"

int main() {
	Door*door = new Door();
	SecureProxy*proxy = new SecureProxy(door);
	proxy->Close();
	proxy->Open("admin", "123");
	proxy->Open("Alex", "890");
	proxy->Close();
	proxy->Open("admin", "123");

	system("pause");
}